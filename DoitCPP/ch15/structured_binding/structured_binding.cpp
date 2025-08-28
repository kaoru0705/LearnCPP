#include <iostream>
#include <tuple>
#include <map>


struct data_struct {
    int number;
    std::string sentence;
    float decimal;
};

int main() {
    int numbers[3] { 1, 2, 3 };
    auto [number0, number1, number2] {numbers};
    std::cout << "배열의 구조적 바인딩" << std::endl;
    std::cout << numbers[0] << " : " << number0 << std::endl;
    std::cout << numbers[1] << " : " << number1 << std::endl;
    std::cout << numbers[2] << " : " << number2 << std::endl;

    struct data_struct struct_object { 20, "구조체", 10.5f };
    auto [number3, string0, decimal0] = struct_object;
    std::cout << std::endl << "구조체의 구조적 바인딩" << std::endl;
    std::cout << struct_object.number << " : " << number3 << std::endl;
    std::cout << struct_object.sentence << " : " << string0 << std::endl;
    std::cout << struct_object.decimal << " : " << decimal0 << std::endl;

    std::tuple<int, char, double> tuple_object{ 5, 'C', 20.1f };
    auto [number4, char1, decimal1] {tuple_object};
    std::cout << std::endl << "튜플의 구조적 바인딩" << std::endl;
    std::cout << std::get<0>(tuple_object) << " : " << number4 << std::endl;
    std::cout << std::get<1>(tuple_object) << " : " << char1 << std::endl;
    std::cout << std::get<2>(tuple_object) << " : " << decimal1 << std::endl;

    std::map<int, std::string> map_object;

    map_object.insert({ 0, "첫번째" });
    map_object.insert({ 1, "두번째" });
    map_object.insert({ 2, "세번째" });
    std::cout << std::endl << "맵의 구조적 바인딩" << std::endl;
    for (auto [number5, string1] : map_object) {
        std::cout << "[" << number5 << "] " << map_object[number5] << " : " << string1 << std::endl;
    }

    return 0;
}