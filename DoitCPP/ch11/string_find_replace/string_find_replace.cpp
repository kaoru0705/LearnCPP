#include <iostream>
#include <string>


int main() {
    // ���ڿ� ����
    std::string text{ "The C++ programming language is one of the hardest languages." };

    // ã�� ���ڿ��� ��ü�� ���ڿ� ����
    std::string target{ "hardest" };
    std::string replacement{ "most powerful" };

    // find �Լ��� ����Ͽ� ù ��°�� �����ϴ� ��ġ ã��
    size_t pos = text.find(target);

    // ���ڿ��� ��� ���ڿ��� �����ϴ� ��� replace �Լ��� ����Ͽ� ��ü
    if (pos != std::string::npos) {
        text.replace(pos, target.length(), replacement);
        std::cout << "��ü �� ����: " << text << std::endl;
    }
    else {
        std::cout << target << " �� ã�� �� ����" << std::endl;
    }

    return 0;
}
