#include <iostream>
#include <tuple>

const int monster_a_type {0};
const int monster_b_type {1};
const int monster_c_type {2};

class monster {
public:
    int get_monster_type() { return monster_type; };

protected:
    int monster_type;

private:
    int location_x;
    int location_y;
};

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
    monster_a() {
        monster_type = monster_a_type;
    };
};


//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
public:
    monster_b() {
        monster_type = monster_b_type;
    };
};


//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public monster {
public:
    monster_c() {
        monster_type = monster_c_type;
    };
};

// 몬스터 객체를 전달받아 특성을 튜플로 반환
std::tuple<int, std::string, int, int> get_monster_status(monster& monster_inst) {

    int monster_type{ monster_inst.get_monster_type() };
    std::string monster_name;
    int hp{ 100 }, power{ 100 };

    switch (monster_type) {
    case monster_a_type:
        monster_name = "A 몬스터";
        hp += 10;
        break;
    case monster_b_type:
        monster_name = "B 몬스터";
        power += 20;
        break;
    case monster_c_type:
        monster_name = "C 몬스터";
        hp -= 10;
        power += 100;
        break;
    }
    // ① 튜플 생성
    return std::make_tuple(monster_type, monster_name, hp, power);
}

// 튜플의 원소 출력
void print_out_tuple(std::tuple<int, std::string, int, int> monster_status) {
    std::cout << std::get<1>(monster_status) << "("
        << std::get<0>(monster_status) << ") : hp("
        << std::get<2>(monster_status) << "), power("
        << std::get<3>(monster_status) << ")" << std::endl;
}

// tuple size 상관 없이 출력하는 소스 코드 cppreference.com 참조
// https://en.cppreference.com/w/cpp/utility/tuple/tuple_cat
// template<class T> == template<typename T> (완전히 동일)
// 하지만 종속 타입을 명시할 때는 반드시 typename을 써야 함.
// 밑은 typename tuple_obj와 std::size_T N이라는 특정 데이터를 쓴 부분 특수화이다.
// 재귀적으로 show()를 출력하고 있다.
template<class tuple_obj, std::size_t N>
struct print_out_tuple_second {
    static void show(const tuple_obj& t)
    {
        print_out_tuple_second<tuple_obj, N - 1>::show(t);
        std::cout << ", " << std::get<N - 1>(t);
    }
};

template<class tuple_obj>
struct print_out_tuple_second<tuple_obj, 1> {
    static void show(const tuple_obj& t)
    {
        std::cout << std::get<0>(t);
    }
};

int main() {

    monster_a monster_a_inst;
    monster_b monster_b_inst;

    // make_tuple로 생성된 튜플을 반환 받아 튜플 객체에 대입
    std::tuple<int, std::string, int, int> monster_a_status{ get_monster_status(monster_a_inst) };
    // ② 복사 생성자(copy constructor)로 튜플 생성
    std::tuple<int, std::string, int, int> monster_a_status_copy{ monster_a_status };
    // ③ 유니폼 초기화로 튜플 생성
    std::tuple<int, std::string, int, int> monster_b_status_temp{ monster_b_type, "B 몬스터 임시", 100, 100 };
    // ④ auto 사용
    auto monster_b_status = get_monster_status(monster_b_inst);

    print_out_tuple(monster_a_status);
    print_out_tuple(monster_a_status_copy);
    print_out_tuple(monster_b_status_temp);

    // ⑤ 튜플의 원솟값 교환
    std::swap(monster_b_status, monster_b_status_temp);
    std::cout << "튜플 내용 교환 후" << std::endl;
    print_out_tuple(monster_b_status_temp);

    // 튜플 값 바꾸기
    std::get<1>(monster_a_status) = "hello";
    std::cout << std::get<1>(monster_a_status) << std::endl;
    std::cout << std::get<1>(monster_a_status_copy) << std::endl;
    

    // ⑥ 튜플 합치기
    auto monster_status_all = std::tuple_cat(monster_a_status, monster_b_status);
    std::cout << "tuple_cat 호출 이후 : { ";
    // std::tuple_size<std::tuple>의 멤버 상수는 tuple의 데이터 형식 개수 여기선 monster_status_all은 8
    // decltype은 monster_status_all의 type을 연역으로 반환하고 있다.
    print_out_tuple_second<decltype(monster_status_all), std::tuple_size<decltype(monster_status_all)>::value>::show(monster_status_all);
    std::cout << "}" << std::endl;

    return 0;
}