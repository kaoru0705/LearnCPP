#include <iostream>
#include <string>


void check_found(std::string::size_type n) {
    if (n == std::string::npos) {
        std::cout << "not found" << std::endl;
    }
    else {
        std::cout << "found index: " << n << std::endl;
    }
}

int main() {
    std::string::size_type n;
    std::string str{ "This is an example of a standard string." };

    // ���ڿ� ���� �������� "example" Ž��
    n = str.find("example");
    check_found(n);

    // ���ڿ� ���� �������� "is" Ž��
    n = str.find("is");
    check_found(n);

    // ���ڿ� �� index ��ġ 4���� "is" Ž��
    n = str.find("is", 4);
    check_found(n);

    // ���ڿ� ���� �������� 'h' Ž��
    n = str.find('h');
    check_found(n);

    // ���ڿ� ���� �������� 'k' Ž��
    n = str.find('k');
    check_found(n);

    return 0;
}
