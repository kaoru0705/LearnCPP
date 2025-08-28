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
    std::cout << "�迭�� ������ ���ε�" << std::endl;
    std::cout << numbers[0] << " : " << number0 << std::endl;
    std::cout << numbers[1] << " : " << number1 << std::endl;
    std::cout << numbers[2] << " : " << number2 << std::endl;

    struct data_struct struct_object { 20, "����ü", 10.5f };
    auto [number3, string0, decimal0] = struct_object;
    std::cout << std::endl << "����ü�� ������ ���ε�" << std::endl;
    std::cout << struct_object.number << " : " << number3 << std::endl;
    std::cout << struct_object.sentence << " : " << string0 << std::endl;
    std::cout << struct_object.decimal << " : " << decimal0 << std::endl;

    std::tuple<int, char, double> tuple_object{ 5, 'C', 20.1f };
    auto [number4, char1, decimal1] {tuple_object};
    std::cout << std::endl << "Ʃ���� ������ ���ε�" << std::endl;
    std::cout << std::get<0>(tuple_object) << " : " << number4 << std::endl;
    std::cout << std::get<1>(tuple_object) << " : " << char1 << std::endl;
    std::cout << std::get<2>(tuple_object) << " : " << decimal1 << std::endl;

    std::map<int, std::string> map_object;

    map_object.insert({ 0, "ù��°" });
    map_object.insert({ 1, "�ι�°" });
    map_object.insert({ 2, "����°" });
    std::cout << std::endl << "���� ������ ���ε�" << std::endl;
    for (auto [number5, string1] : map_object) {
        std::cout << "[" << number5 << "] " << map_object[number5] << " : " << string1 << std::endl;
    }

    return 0;
}