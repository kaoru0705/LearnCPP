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

    // 문자열 시작 지점부터 "example" 탐색
    n = str.find("example");
    check_found(n);

    // 문자열 시작 지점부터 "is" 탐색
    n = str.find("is");
    check_found(n);

    // 문자열 내 index 위치 4부터 "is" 탐색
    n = str.find("is", 4);
    check_found(n);

    // 문자열 시작 지점부터 'h' 탐색
    n = str.find('h');
    check_found(n);

    // 문자열 시작 지점부터 'k' 탐색
    n = str.find('k');
    check_found(n);

    return 0;
}
