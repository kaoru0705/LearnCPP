#include <iostream>
// 전역 범위에서 함수를 정의할 때는 printout_friend_element함수에서 사용할 템플릿 매개변수를 별도로 선언해야 된다.

template <typename T = int>
class data_package {
public:
    data_package(T first) : first{first} {}
    template <typename C>
    friend void printout_friend_element(C& data_object);    // 프렌드 함수 선언
    //friend void printout_friend_element(data_package<C>& data_object); // 이렇게 적으면 템플릿 매개변수를 고정할 수 있다.
private:
    T first;
};

template <typename C>
void printout_friend_element(C& data_object){               // 프렌드 함수 정의
//void printout_friend_element(data_package<C>& data_object) {    
    std::cout << "(friend 함수 템플릿 호출)  템플릿 형식 매개 변수 값 : "
        << data_object.first << std::endl;
}

int main() {
    data_package<> template_inst1(5);
    data_package<std::string> template_inst2("클래스 템플릿 기본값");

    printout_friend_element(template_inst1);
    printout_friend_element(template_inst2);
}