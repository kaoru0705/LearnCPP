#include <iostream>

void func_throw() {
    std::cout << std::endl;
    std::cout << "func_throw() �Լ� ����" << std::endl;
    std::cout << "throw -1" << std::endl;
    throw - 1;   // ���� ���� ���� ������
    std::cout << "after throw -1" << std::endl;
}

void func_2() {
    std::cout << std::endl;
    std::cout << "func_2() �Լ� ����" << std::endl;
    std::cout << "func_throw() ȣ��" << std::endl;
    func_throw();
    std::cout << "after func_throw()" << std::endl;
}

void func_1() {
    std::cout << std::endl;
    std::cout << "func_1() �Լ� ����" << std::endl;
    std::cout << "func_2() ȣ��" << std::endl;
    func_2();
    std::cout << "after func_2()" << std::endl;
}


int main() {
    std::cout << "main ����" << std::endl;

    try {
        std::cout << "func_1() ȣ��" << std::endl;
        func_1();
    }
    catch (int exec) {   // ���� ���� ���� �ޱ�
        std::cout << std::endl;
        std::cout << "catch " << exec << std::endl;
    }

    return 0;
}
