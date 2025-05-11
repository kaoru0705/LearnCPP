#include <iostream>


int main() {
    try {
        int input;
        std::cout << "���� �� �ϳ��� �Է��غ����� : ";
        std::cin >> input;

        // �Է¹��� ���ڰ� ����̸�
        if (input > 0) {
            std::cout << "throw 1" << std::endl;
            throw 1;   // ���� 1 �߻�(���� ���� ����)
        }

        // �Է¹��� ���ڰ� �����̸�
        if (input < 0) {
            std::cout << "throw -1.0f" << std::endl;
            throw - 1.0f;   // ���� 1.0f �߻�(�ε��Ҽ��� ���� ����)
        }

        // �Է¹��� ���ڰ� 0�̸�
        if (input == 0) {
            std::cout << "throw Z" << std::endl;
            throw 'Z';   // ���� Z �߻� (���� ���� ����)
        }
    }
    catch (int a) {   // ���� ���� ���� �ޱ�
        std::cout << "catch " << a << std::endl;
    }
    catch (...) {   // ó������ ���� ������ ���� ��� �ޱ�
        std::cout << "catch all" << std::endl;
    }

    return 0;
}
