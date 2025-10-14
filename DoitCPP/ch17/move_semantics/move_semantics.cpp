// https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/
// 이동 의미론
// 포인터를 복사하는 (copy semantics) assigment operator나 copy constructor를 갖는 대신, 포인터의 소유권을 소스 객체에서 대상 객체로 이전/이동 시킨다면? 이것이 move semantics의 핵심
// 이건 사실 auto_ptr이라는 c++11까지 존재하던 스마트포인터이다. 그러나 문제가 있어서 c++17에서 제거되었다.
// 1. 인수가 이동되고 삭제된 걸 모른다면 null pointer를 역참조하게 되어 런타임 에러를 발생시킬 수 있다.
// 2. 항상 배열이 아닌 delete 이므로 동적 배열에는 적합하지 않다.
// 3. 대부분의 컨테이너와 알고리즘을 포함하여 표준 라이브러리의 다른 많은 클래스와 호환되지 않았다. standard library classes는 복사할 때 이동이 아닌 복사본을 만든다고 가정하기 때문에 일어난다.
// 그래서 move-aware smart pointers 인 unique_ptr, weak_ptr, shared_ptr로 대체되었다.
#include <iostream>

template <typename T>
class Auto_ptr2
{
	T* m_ptr{};
public:
	Auto_ptr2(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr2()
	{
		delete m_ptr;
	}

	// A copy constructor that implements move semantics
	Auto_ptr2(Auto_ptr2& a) // note: not const
	{
		// We don't need to delete m_ptr here.  This constructor is only called when we're creating a new object, and m_ptr can't be set prior to this.
		m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
	}

	// An assignment operator that implements move semantics
	Auto_ptr2& operator=(Auto_ptr2& a) // note: not const
	{
		if (&a == this)
			return *this;

		delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
		m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
		a.m_ptr = nullptr; // make sure the source no longer owns the pointer
		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	Auto_ptr2<Resource> res1(new Resource());
	Auto_ptr2<Resource> res2; // Start as nullptr

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	res2 = res1; // res2 assumes ownership, res1 is set to null

	std::cout << "Ownership transferred\n";

	std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
	std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

	return 0;
}