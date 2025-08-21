// since c++17 filesystem
#include <iostream>
#include <string>
#include <filesystem> // ���� �ý��� ��� ����
#include <fstream>    // ���� ����� ��� ����


int main() {
    // 1. ���͸� ����
    std::filesystem::create_directories("MyDirectory");

    // 2. ���� ���� �� ����
    std::ofstream outFile("MyDirectory/myFile.txt");
    outFile << "Hello, FileSystem Library!" << std::endl;
    outFile << "HAHAHAHAHA!" << std::endl;
    outFile.close();

    // 3. ���͸� ���� ���� Ȯ��
    std::cout << "Files in MyDirectory:\n";
    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator("MyDirectory")) {
        if (entry.is_regular_file()) {
            std::cout << entry.path().filename() << std::endl;
        }
    }

    // 4. ���� �б�
    std::ifstream inFile("MyDirectory/myFile.txt");
    std::string line;
    while (getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();

    // 5. ���� �� ���͸� ����
    std::filesystem::remove_all("MyDirectory");

    return 0;
}
