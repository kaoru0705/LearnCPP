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

//���� A�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_a : public monster {
public:
    monster_a() {
        monster_type = monster_a_type;
    };
};


//���� B�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_b : public monster {
public:
    monster_b() {
        monster_type = monster_b_type;
    };
};


//���� C�� �߻� Ŭ���� Monster Ŭ�����κ��� ���
class monster_c : public monster {
public:
    monster_c() {
        monster_type = monster_c_type;
    };
};

// ���� ��ü�� ���޹޾� Ư���� Ʃ�÷� ��ȯ
std::tuple<int, std::string, int, int> get_monster_status(monster& monster_inst) {

    int monster_type{ monster_inst.get_monster_type() };
    std::string monster_name;
    int hp{ 100 }, power{ 100 };

    switch (monster_type) {
    case monster_a_type:
        monster_name = "A ����";
        hp += 10;
        break;
    case monster_b_type:
        monster_name = "B ����";
        power += 20;
        break;
    case monster_c_type:
        monster_name = "C ����";
        hp -= 10;
        power += 100;
        break;
    }
    // �� Ʃ�� ����
    return std::make_tuple(monster_type, monster_name, hp, power);
}

// Ʃ���� ���� ���
void print_out_tuple(std::tuple<int, std::string, int, int> monster_status) {
    std::cout << std::get<1>(monster_status) << "("
        << std::get<0>(monster_status) << ") : hp("
        << std::get<2>(monster_status) << "), power("
        << std::get<3>(monster_status) << ")" << std::endl;
}

// tuple size ��� ���� ����ϴ� �ҽ� �ڵ� cppreference.com ����
// https://en.cppreference.com/w/cpp/utility/tuple/tuple_cat
// template<class T> == template<typename T> (������ ����)
// ������ ���� Ÿ���� ����� ���� �ݵ�� typename�� ��� ��.
// ���� typename tuple_obj�� std::size_T N�̶�� Ư�� �����͸� �� �κ� Ư��ȭ�̴�.
// ��������� show()�� ����ϰ� �ִ�.
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

    // make_tuple�� ������ Ʃ���� ��ȯ �޾� Ʃ�� ��ü�� ����
    std::tuple<int, std::string, int, int> monster_a_status{ get_monster_status(monster_a_inst) };
    // �� ���� ������(copy constructor)�� Ʃ�� ����
    std::tuple<int, std::string, int, int> monster_a_status_copy{ monster_a_status };
    // �� ������ �ʱ�ȭ�� Ʃ�� ����
    std::tuple<int, std::string, int, int> monster_b_status_temp{ monster_b_type, "B ���� �ӽ�", 100, 100 };
    // �� auto ���
    auto monster_b_status = get_monster_status(monster_b_inst);

    print_out_tuple(monster_a_status);
    print_out_tuple(monster_a_status_copy);
    print_out_tuple(monster_b_status_temp);

    // �� Ʃ���� ���ڰ� ��ȯ
    std::swap(monster_b_status, monster_b_status_temp);
    std::cout << "Ʃ�� ���� ��ȯ ��" << std::endl;
    print_out_tuple(monster_b_status_temp);

    // Ʃ�� �� �ٲٱ�
    std::get<1>(monster_a_status) = "hello";
    std::cout << std::get<1>(monster_a_status) << std::endl;
    std::cout << std::get<1>(monster_a_status_copy) << std::endl;
    

    // �� Ʃ�� ��ġ��
    auto monster_status_all = std::tuple_cat(monster_a_status, monster_b_status);
    std::cout << "tuple_cat ȣ�� ���� : { ";
    // std::tuple_size<std::tuple>�� ��� ����� tuple�� ������ ���� ���� ���⼱ monster_status_all�� 8
    // decltype�� monster_status_all�� type�� �������� ��ȯ�ϰ� �ִ�.
    print_out_tuple_second<decltype(monster_status_all), std::tuple_size<decltype(monster_status_all)>::value>::show(monster_status_all);
    std::cout << "}" << std::endl;

    return 0;
}