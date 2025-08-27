// RAII는 메모리의 관리를 객체나 변수의 생명 주기와 일치시키는 방법입니다.
// 특히 객체의 범위를 벗어 날때 메모리가 해제되도록 하는 것입니다. RAII를 위해서는 객체의 소멸과 메모리의 소멸이 동시에 동작하도록 하는 것입니다.
// 이렇게 RAII 바이너리로 구현된 라이브러리가 아니라 메모리 관리 기법입니다.
// 이런 메모리 관리 기법을 적용해 만든 라이브러리가 스마트 포인터입니다.
// 반면, 가비지 컬렉터는 개발자가 스스로 메모리를 관리 하지 않더라도 언어의 동작 환경이 자동으로 메모리를 회수하는 '기능'입니다.
// Java, C#, Python 등에서 사용되는 기법으로 동작 환경이 메모리가 참조 여부를 확인하고 메모리를 해체 합니다. 그래서 가비지 컬렉터의 동작 시점이나 동작시 성능 저하가 문제가 되는 경우가 많습니다.
//
// RAII가 가비지 컬렉터 대비 장단점은 아래와 같습니다.
//* 장점: 메모리 해제 시점이 명확하고 의도에 따라서 메모리가 해제 될 수 있습니다. (범위를 벗어날 경우)
//* 단점 : 동작 환경이 자동으로 메모리를 해제해주지 않기 때문에 RAII를 직접 구현하거나 RAII가 구현된 메모리 관리 방식을 사용해야 합니다.
#include <iostream>
#include <memory>

class class_object {
public:
    class_object() {
        std::cout << "메모리가 할당 되었습니다." << std::endl;
    };
    ~class_object() {
        std::cout << "메모리가 해제 되었습니다." << std::endl;
    };
    void print_out() {
        std::cout << "객체의 함수를 호출합니다." << std::endl;
    };
};

int main() {
    // 스마트 포인터로 메모리 누수 방지
    std::unique_ptr<class_object> unique_pointer{ new class_object() };
    unique_pointer->print_out();

    auto unique_pointer2{ std::make_unique<class_object>() };
    unique_pointer2->print_out();

    return 0;
}