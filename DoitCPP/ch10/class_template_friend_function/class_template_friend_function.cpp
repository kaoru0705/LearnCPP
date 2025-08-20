//friend 키워드를 붙였다는 건** "이 함수는 멤버 함수가 아니라 외부 함수이지만, 이 클래스의 private 멤버에 접근할 권한을 준다" * *라는 뜻이에요.
//
//즉 printout_friend_element는 클래스 안에서 정의되었지만, 사실상 클래스 밖의 전역 네임스페이스에 속하는 함수예요.
//(단, 클래스 템플릿 안에서 정의되었으므로 클래스 템플릿의 매개변수 T에 종속적인 함수 템플릿이 됩니다.)
#include <iostream>

template <typename T = int>
class data_package {
public:
    data_package(T first) : first{ first } {}

    friend void printout_friend_element(data_package<T>& data_object) {
        std::cout << "(friend 함수) 템플릿 매개변수 값 : "
            << data_object.first << std::endl;
    }

private:
    T first;
};

int main() {
    data_package<> template_inst1(5);
    data_package<std::string> template_inst2("클래스 템플릿 기본값");

    printout_friend_element(template_inst1);
    printout_friend_element(template_inst2);
}
