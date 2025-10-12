/* https://eli.thegreenplace.net/2012/02/06/dependent-name-lookup-for-c-templates */
#include <iostream>

template <typename T> class Base {
public:
    typedef int MyType;
};

template <typename T> class Derived : public Base<T> {
public:
    void g() {
        // A. error: ��MyType�� was not declared in this scope
        // MyType k = 2;

        // B. error: need ��typename�� before ��Base<T>::MyType�� because
        // ��Base<T>�� is a dependent scope
        // Base<T>::MyType k = 2;

        // C. works!
        typename Base<T>::MyType k = 2;

        std::cout << "Derived<T>::g --> " << k << std::endl;
    }
};

int main()
{
    Derived<float> df;
    df.g();


    return 0;
}
//  MyType Ÿ���� ���� ���� k�� �����Ϸ��� �� ���� �õ��� ���� �ֽ��ϴ�. ó�� �� ���� ������ ������ �߻����� �ּ� ó���߽��ϴ�.
//   
//  (A)�� ���� ��Ȯ������ ���Դϴ�. MyType �� ���������� �ʱ� ������ Base Ŭ�������� ã�� �� �����ϴ�. ������ ������ �����Դϴ�.
//  
//  ������ (B)�� �� �۵����� �������?
//  Base<T>�� Ư��ȭ�� �� �ֱ� ������ �����Ϸ��� MyType�� type���� �ƴ��� Ȯ���� �� ���� �����Դϴ�.
//  Ư��ȭ�� type���� �δ� �� ��ſ� MyType�̶� �Ҹ��� �޼���� ������ �� �ֽ��ϴ�. ���� �����Ϸ��� �ν��Ͻ�ȭ �������� �� ������ �̷� �� �����ϴ�.
//  MyType�� type���� �ƴ����� ���δ� ������ ������ �κ��� ��� ���� �м��Ǵ����� ������ ��ġ�� �����Դϴ�.
//  ���� ���� ������ MyType�� Ÿ������ ���θ� �����Ϸ��� ��������� �˷���� �մϴ�.
//  default�� "not a type"�̸�, �����Ϸ����� Ÿ�� ���� �˸��� ���� �̸� �տ� typename �� �ٿ��� �մϴ�. �̴� C++ ǥ�� 14.6���� ��õǾ� �ֽ��ϴ�.