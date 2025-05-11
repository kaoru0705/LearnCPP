#include <iostream>
#include <random>
#include <stdexcept>
#include <limits>


int main() {
    // 1���� 100���� ���� ���� ����
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    int answer = dist(gen);

    // *count ������ �����ʹ� ���������, ������ ��̸� ���� �߰��Ͽ����ϴ�.
    // *�� ������ ���� �����⸦ �����ϴ��� ī��Ʈ�ϱ� ���� Ȱ��Ǵ� �����Դϴ�. :)
    int count = 0;

    // ���� ����
    bool is_correct = false;
    while (!is_correct) {
        try {
            // ����ڿ��� ���� �Է� ��û
            ++count;
            std::cout << "���ڸ� �Է��ϼ���: ";
            int guess;
            std::cin >> guess;

            // ���ڰ� �ƴ� �Է�
            if (std::cin.fail()) {
                std::cin.clear(); // �Է� ��Ʈ���� ���¸� �ʱ�ȭ
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���� ����
                throw std::invalid_argument("���ڸ� �Է����ּ���!");
            }

            // �Է��� ���ڰ� ������ ������� Ȯ��
            if (guess < 1 || guess > 100) {
                throw std::out_of_range("1���� 100 ������ ���ڸ� �Է����ּ���!");
            }

            // ���� �� �� �޽��� ���
            if (guess > answer) {
                std::cout << "�ʹ� ���ƿ�!" << std::endl << std::endl;
            }
            else if (guess < answer) {
                std::cout << "�ʹ� ���ƿ�!" << std::endl << std::endl;
            }
            else {
                std::cout << "�����մϴ�! ������ " << answer << "�Դϴ�." << std::endl;
                std::cout << count << "�� ���� ���߼̽��ϴ�. :)" << std::endl;
                is_correct = true;
            }
        }
        // reference variable e
        catch (const std::exception& e) {
            // ���� �߻� �� ���� �޽��� ���
            std::cerr << e.what() << std::endl << std::endl;
        }
    }

    return 0;
}