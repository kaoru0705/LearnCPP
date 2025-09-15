#include <iostream>

// ���� ����� ���� : ���̾Ƹ�� ����(Diamond Problem)
//
// ���� �� �θ� Ŭ������ ���� ���� Ŭ������ ����ϰ� ������, � ��η� ��ӵ� ����� ��� ���� ��ȣ���� �߻��մϴ�.

//class Base { public: void hello() {} };
//class A : public Base {};
//class B : public Base {};
//class C : public A, public B {}; // ���̾Ƹ�� ����


//C���� hello()�� ȣ���ϸ� A �� Base�� B �� Base �� ��ΰ� ���ܼ� ��ȣ���� ����ϴ�.
//
//�ذ�å: ���� ���(Virtual Inheritance)
class Base { public: void hello() {} };
class A : virtual public Base {};
class B : virtual public Base {};
class C : public A, public B {}; // ���� Base�� �� ���� ��ӵ�