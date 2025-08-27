#include <iostream>
#include <functional>
#include <string>

void function_pointer(int input) {
    std::cout << "�Լ� ������ ��� �Լ� : " << input << std::endl;
}

struct functor {
    void operator()(char functor_prefix) {
        std::cout << "���� : " << functor_prefix << std::endl;
    }
};

class class_object {
public:
    class_object(std::string init_string) : class_object_name{ init_string } {}

    void std_function_call_member(std::string contents) {
        std::cout << "Ŭ���� ��� �Լ� ��üȭ (" << class_object_name << ") : " << contents << std::endl;
    }

private:
    std::string class_object_name;
};

int main() {
    class_object class_obj{ "ȣ�� ��ü�� ������ �ִ� Ŭ����" };
    functor functor_obj;

    std::function<void(int)> func_pointer{ function_pointer };
    std::function<void(functor&, char)> functor_func{ &functor::operator() };
    std::function<void(double)> lambda_func{ [](double input) { std::cout << "���� �Լ� : " << input << std::endl; } };
    std::function<void(class_object&, std::string)> member_func{ &class_object::std_function_call_member };

    func_pointer(10);
    functor_func(functor_obj, 'A');
    lambda_func(0xa8);
    member_func(class_obj, "���");

    return 0;
}