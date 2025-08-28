#include <iostream>

const int loop_count{ 5 };
const int change_count{ 5 };

class vending_machine {
public:
    vending_machine() : price{ 450, 390, 11340, 900, 150 } {};
    void stack_drink() {};

    void sale_sale_using_lambda_function_object(int payments[], int changes[]) {
        auto calcu_changes = [&changes](int payment, int price)->int {
            int change = payment - price;
            changes[0] = change / 1000;
            change %= 1000;
            changes[1] = change / 500;
            change %= 500;
            changes[2] = change / 100;
            change %= 100;
            changes[3] = change / 50;
            change %= 50;
            changes[4] = change / 10;
            return payment - price;
            };

        for (int i = 0; i < loop_count; ++i) {
            std::cout << payments[i] << "���� ���� " << price[i] << "�� ¥�� ���Ḧ �����߽��ϴ�." << std::endl;
            std::cout << "�Ž��� ���� ���� " << calcu_changes(payments[i], price[i]) << "�Դϴ�." << std::endl;
            std::cout << "õ�� ¥�� " << changes[0] << "��, ����� ¥�� " << changes[1] << "��, ��� ¥�� " << changes[2] << "��, ";
            std::cout << "���ʿ� ¥�� " << changes[3] << "��, �ʿ� ¥��" << changes[4] << "���� �޽��ϴ�." << std::endl;
        }
    };

private:
    int price[loop_count];
};

int main() {
    vending_machine vending_machine_object = vending_machine();
    int payments[loop_count] { 1000, 500, 15000, 1000, 200 };
    int changes[change_count] { 0, };

    std::cout << std::endl << "���� ǥ���� �Լ� ��ü�� ����ϱ�" << std::endl;
    std::cout << "--------------------------------------------------------------------" << std::endl;
    vending_machine_object.sale_sale_using_lambda_function_object(payments, changes);
    return 0;
}
