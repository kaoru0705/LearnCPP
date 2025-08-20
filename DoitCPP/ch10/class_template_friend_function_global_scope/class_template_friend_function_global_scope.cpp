#include <iostream>
// ���� �������� �Լ��� ������ ���� printout_friend_element�Լ����� ����� ���ø� �Ű������� ������ �����ؾ� �ȴ�.

template <typename T = int>
class data_package {
public:
    data_package(T first) : first{first} {}
    template <typename C>
    friend void printout_friend_element(C& data_object);    // ������ �Լ� ����
    //friend void printout_friend_element(data_package<C>& data_object); // �̷��� ������ ���ø� �Ű������� ������ �� �ִ�.
private:
    T first;
};

template <typename C>
void printout_friend_element(C& data_object){               // ������ �Լ� ����
//void printout_friend_element(data_package<C>& data_object) {    
    std::cout << "(friend �Լ� ���ø� ȣ��)  ���ø� ���� �Ű� ���� �� : "
        << data_object.first << std::endl;
}

int main() {
    data_package<> template_inst1(5);
    data_package<std::string> template_inst2("Ŭ���� ���ø� �⺻��");

    printout_friend_element(template_inst1);
    printout_friend_element(template_inst2);
}