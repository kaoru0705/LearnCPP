//friend Ű���带 �ٿ��ٴ� ��** "�� �Լ��� ��� �Լ��� �ƴ϶� �ܺ� �Լ�������, �� Ŭ������ private ����� ������ ������ �ش�" * *��� ���̿���.
//
//�� printout_friend_element�� Ŭ���� �ȿ��� ���ǵǾ�����, ��ǻ� Ŭ���� ���� ���� ���ӽ����̽��� ���ϴ� �Լ�����.
//(��, Ŭ���� ���ø� �ȿ��� ���ǵǾ����Ƿ� Ŭ���� ���ø��� �Ű����� T�� �������� �Լ� ���ø��� �˴ϴ�.)
#include <iostream>

template <typename T = int>
class data_package {
public:
    data_package(T first) : first{ first } {}

    friend void printout_friend_element(data_package<T>& data_object) {
        std::cout << "(friend �Լ�) ���ø� �Ű����� �� : "
            << data_object.first << std::endl;
    }

private:
    T first;
};

int main() {
    data_package<> template_inst1(5);
    data_package<std::string> template_inst2("Ŭ���� ���ø� �⺻��");

    printout_friend_element(template_inst1);
    printout_friend_element(template_inst2);
}
