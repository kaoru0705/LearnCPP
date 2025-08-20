#include <iostream>

template <typename T = int>   // �⺻ ���� ����
class data_package {
public:
    data_package(T first) : first{ first } {}
    void print_out_element() {
        std::cout << "Ŭ���� ���ø� ���� �Ű� ���� �� : " << first << std::endl;
    }
private:
    T first;
};

int main() {
    data_package<> template_inst1{ 5 };   // �⺻ ����(���⼭�� int)���� ����
    data_package<std::string> template_inst2{"Ŭ���� ���ø� �⺻��"};

    template_inst1.print_out_element();
    template_inst2.print_out_element();
}
