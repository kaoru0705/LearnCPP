#include <iostream>

template <typename Type1, typename Type2>
class data_package {
public:
    template <typename Type3>            // �ٱ��� ���ø� �Ű����� ��� 
    class nested_class_data_package {    // ���� Ŭ����
    public:
        nested_class_data_package(Type3 data) : nested_class_data{ data } {}
        Type3 get_element() { return nested_class_data; }
        Type3 nested_class_data;
    };

    template <typename Type4>    // �� ���ø� �Ű����� ���
    class nested_class {         // ���� Ŭ����
    public:
        nested_class(Type4 data) : nested_class_data{ data } {}
        void print_out_element() {
            std::cout << "��ø Ŭ���� ������: " << nested_class_data << std::endl;
        }
    private:
        Type4 nested_class_data;
    };

    data_package(Type1 first, Type2 second) : first{first}, second{second},
        internal_data(second) {
    }

    void print_out_element() {
        std::cout << "ù ��° ���: " << first <<
            ", �� ��° ���: " << second << std::endl;
        std::cout << "��ø Ŭ���� ���: " << internal_data.get_element() << std::endl;
    }

private:
    Type1 first;
    Type2 second;
    nested_class_data_package<Type2> internal_data;   // ��� ������ ����

};
int main() {
    data_package<std::string, int> template_inst1{"���ڿ�", 10};
    data_package<std::string, int>::nested_class<int> template_inst2{ 500 };   // ��ü�� ����

    std::cout << "��ø Ŭ���� ù ��° ����" << std::endl;
    template_inst1.print_out_element();

    std::cout << std::endl << "��ø Ŭ���� �� ��° ����" << std::endl;
    template_inst2.print_out_element();
}