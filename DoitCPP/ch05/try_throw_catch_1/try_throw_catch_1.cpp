#include <iostream>


int main() {
    try {
        int input;
        std::cout << "���� �� �ϳ��� �Է��ϼ��� : ";
        std::cin >> input;

        // �Է¹��� ���ڰ� ����̸�
        if (input > 0) {
            std::cout << "throw 1" << std::endl;
            throw 1;      // ���� 1 �߻�(���� ���� ����)
            std::cout << "after throw 1" << std::endl;
        }

        // �Է¹��� ���ڰ� �����̸�
        if (input < 0) {
            std::cout << "throw -1.0f" << std::endl;
            throw - 1.0f;   // ���� 1.0f �߻�(�ε��Ҽ��� ���� ����)
            std::cout << "after throw -1.0f" << std::endl;
        }

        // �Է¹��� ���ڰ� 0�̸�
        if (input == 0) {
            std::cout << "throw Z" << std::endl;
            throw 'Z';    // ���� Z �߻�(���� ���� ����)
            std::cout << "after throw Z" << std::endl;
        }
    }
    catch (int a) {   // ���� ���� ���� �ޱ�
        std::cout << "catch " << a << std::endl;
    }
    catch (float b) {   // �ε��Ҽ��� ���� ���� �ޱ�
        std::cout << "catch " << b << std::endl;
    }
    catch (char c) {   // ���� ���� ���� �ޱ�
        std::cout << "catch " << c << std::endl;
    }

    return 0;
}
