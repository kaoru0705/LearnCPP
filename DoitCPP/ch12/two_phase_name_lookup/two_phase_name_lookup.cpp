/* https://eli.thegreenplace.net/2012/02/06/dependent-name-lookup-for-c-templates */

#include <iostream>

//template <typename T> class Base {
//public:
//    void f() {
//        std::cout << "    Base<T>::f" << std::endl;
//    }
//};
//
//template <typename T> class Derived : public Base<T> {
//public:
//    void g() {
//        std::cout << "Derived<T>::g" << std::endl; 
//        f(); // error 'f': identifier not found
//    }
//};
// ���� Derived<T>::g �� �ǵ��� Base<T>::f�� ȣ���ϴ� ��������, �����Ϸ��� ��� ���� ������ �����մϴ�.
// �����Ϸ��� ȣ�� f �� ���ø� �Ű����� T �� ���ӵȴٴ� ���� �����ϵ��� ����⸸ �ϸ� �˴ϴ�.
// �̸� ���� �� ���� ����� f() �� Base<T>::f() �� �ٲ� �ų� this->f() �� �ٲٴ� ���Դϴ�(this �� T �� �Ϲ������� ���ӵǱ� �����Դϴ�).

template <typename T> class Base {
public:
    void f() {
        std::cout << "    Base<T>::f" << std::endl;
    }
};

template <typename T> class Derived : public Base<T> {
public:
    void g() {
        std::cout << "Derived<T>::g" << std::endl;
        //this->f();
        //Base<T>::f();
    }
};
// ��ó�� ������ ���� �ذ�. �ٵ� ��?
// Base class�� specialization(����� Ư��ȭ) ���Ѻ���.
template <>
class Base<int> {
public:
    void f() {
        std::cout << "    Base<int>::f" << std::endl;
    }
};
/*
Derived<T>::g
    Base<T>::f
Derived<T>::g
    Base<int>::f
*/
// ��� Derived<int>�� �䱸���� �� base template�� int�� Ư��ȭ�� �ִ� �ǰ�? �����Ϸ��� ��� ��������? Base<int>�� Derived<int> �ڿ� ���ǵ� ���ݾ�!


// �����Ϸ��� �ڵ忡�� � �̸��� Ȯ���Ϸ��� �� ��, ���� �ش� �̸��� ���������� ���θ� �Ǵ��ϸ�, Ȯ�� ������ �̷��� ���п��� ���۵˴ϴ�.
// ���������� ���� �̸��� "����������" Ȯ�ε�����, ���ø��� ���ǵ� �� �������� �̸��� ���ø��� �ν��Ͻ�ȭ ������ Ȯ�ε˴ϴ�. �̰��� �� ������ Ư��ȭ�� �ùٸ��� �νĵǵ��� �ϴ� ���Դϴ�.
// ���� ���� ������ ���ư� ���ڽ��ϴ�. �����Ϸ��� Base Ŭ�������� f�� ã�� �ʴ� ������ �����ϱ��?
// ����, ù ��° �ڵ� f() ȣ�⿡�� f�� ���ӵ��� �ʴ� �̸��Դϴ�.
// ���� ���ø� ���� �������� f�� Ȯ���ؾ� �մϴ�. �� �������� �����Ϸ��� Base<T>::f �� �������� ������ ���� ���մϴ�. ���߿� Ư��ȭ�� �� �ֱ� �����Դϴ�.
// ���� �����Ϸ��� Base Ŭ�������� �̸��� ã�� �ʰ�, ���δ� ���������� �̸��� ã���ϴ�. ���δ� ������ f�� ���� ������ �����Ϸ��� ������ �߻���ŵ�ϴ�.
// �ݸ�, this-> �� ���� f�� ȣ���Ͽ� ��������� fã��(look-up)�� dependent�� ����� ã�� ��Ģ�� ����˴ϴ�.
// ���� f�� ���ø��� �ν��Ͻ�ȭ �������� Ȯ�εǸ�, �����Ϸ��� �� �������� Base Ŭ������ ������ �����ϰ� �̸��� �ùٸ��� Ȯ���� �� �ֽ��ϴ�.

int main()
{
    Derived<float> df;
    df.g();

    Derived<int> di;
    di.g();
    return 0;
}