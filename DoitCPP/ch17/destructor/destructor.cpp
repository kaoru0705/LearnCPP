// https://www.learncpp.com/cpp-tutorial/destructors/
// RAII(Resource Acquisition is Initialization)를 구현한 클래스의 예시
// 리소스(메모리, 파일 또는 데이터베이스 핸들 등) 사용을 자동 지속 시간을 가진 객체(동적으로 할당하지 않은 객체)의 수명에 묶는 프로그래밍 기법
// in c++에서는 생성자와 소멸자를 가진 클래스를 통해 구현된다.
// 리소스는 객체가 살아있는 동안 사용할 수 있고, 객체가 소멸될 때 소멸자에서 해제된다.
// 리소스를 보유한 모든 객체가 자동으로 정리되므로 리소스 누수를 방지하는 데 도움이 된다.


#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray
{
private:
	int* m_array{};
	int m_length{};

public:
	IntArray(int length) // constructor
	{
		assert(length > 0);

		m_array = new int[static_cast<std::size_t>(length)] {};
		m_length = length;
	}

	~IntArray() // destructor
	{
		// Dynamically delete the array we allocated earlier
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};

int main()
{
	IntArray ar(10); // allocate 10 integers
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count + 1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	return 0;
} // ar is destroyed here, so the ~IntArray() destructor function is called here