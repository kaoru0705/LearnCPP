// since c++17 filesystem
#include <iostream>
#include <string>
#include <filesystem> // 파일 시스템 헤더 파일
#include <fstream>    // 파일 입출력 헤더 파일


int main() {
    // 1. 디렉터리 생성
    std::filesystem::create_directories("MyDirectory");

    // 2. 파일 생성 및 쓰기
    std::ofstream outFile("MyDirectory/myFile.txt");
    outFile << "Hello, FileSystem Library!" << std::endl;
    outFile << "HAHAHAHAHA!" << std::endl;
    outFile.close();

    // 3. 디렉터리 내의 파일 확인
    std::cout << "Files in MyDirectory:\n";
    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator("MyDirectory")) {
        if (entry.is_regular_file()) {
            std::cout << entry.path().filename() << std::endl;
        }
    }

    // 4. 파일 읽기
    std::ifstream inFile("MyDirectory/myFile.txt");
    std::string line;
    while (getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();

    // 5. 파일 및 디렉터리 삭제
    std::filesystem::remove_all("MyDirectory");

    return 0;
}
