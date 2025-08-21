#include <iostream>
#include <string>


int main() {
    // 문자열 생성
    std::string text{ "The C++ programming language is one of the hardest languages." };

    // 찾을 문자열과 대체할 문자열 정의
    std::string target{ "hardest" };
    std::string replacement{ "most powerful" };

    // find 함수를 사용하여 첫 번째로 등장하는 위치 찾기
    size_t pos = text.find(target);

    // 문자열에 대상 문자열이 존재하는 경우 replace 함수를 사용하여 대체
    if (pos != std::string::npos) {
        text.replace(pos, target.length(), replacement);
        std::cout << "대체 후 문장: " << text << std::endl;
    }
    else {
        std::cout << target << " 을 찾을 수 없음" << std::endl;
    }

    return 0;
}
