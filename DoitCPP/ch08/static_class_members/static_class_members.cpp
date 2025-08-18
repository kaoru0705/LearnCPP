#include <iostream>
#include <list>

class my_vector {
public:
    my_vector(int size);
private:
    int vector_size;
    std::list<int> contents;
};

my_vector::my_vector(int size) : vector_size{ size } {
    for (int i = 0; i < vector_size; ++i) {
        contents.push_back(0);
    }
}

class matrix {
public:
    matrix(int row, int col);
    ~matrix();
private:
    int row_count;
    int col_count;
    std::list<my_vector*> contents;
};

matrix::matrix(int row, int col) : row_count{ row }, col_count{ col } {
    for (int i = 0; i < row_count; ++i) {
        my_vector* new_vector = new my_vector(col_count);
        contents.push_back(new_vector);
    }
}

matrix::~matrix() {
    for (auto item : contents) {
        delete item;
    }
}

// ���� Ŭ����
class linear_algebra {
public:
    // ���� ��� �Լ� ����
    static void matrix_multiply(matrix& operand1, matrix& operand2);
    static void dot_product(my_vector& operand1, my_vector& operand2);

private:
    // ���� ��� ���� ����
    static void matrix_vector_multiply(matrix& operand1, my_vector& operand2);
};

void linear_algebra::matrix_multiply(matrix& operand1, matrix& operand2) {
    std::cout << "�ΰ��� ��İ��� ��� �մϴ�." << std::endl;
}

void linear_algebra::matrix_vector_multiply(matrix& operand1, my_vector& operand2) {
    std::cout << "��İ� ������ ���� ��� �մϴ�." << std::endl;
}

void linear_algebra::dot_product(my_vector& operand1, my_vector& operand2) {
    std::cout << "������ ������ ��� �մϴ�." << std::endl;
}

// ���� �Լ����� ���� ���� ����� ���� ����
void do_matrix_multiply(matrix& matrix_1, matrix& matrix_2) {
    linear_algebra::matrix_multiply(matrix_1, matrix_2);
}

// ���� �Լ����� ����� ���� ����� ���� �Ұ���
void do_matrix_vector_multiply(matrix& matrix_1, my_vector& vector_1) {
    //linear_algebra::matrix_vector_multiply(matrix_1, vector_1); // ���� �����ڿ� ���� ������ �� ����
}

void do_vector_innerproduct(my_vector& vector_1, my_vector& vector_2) {
    linear_algebra::dot_product(vector_1, vector_2);
}

int main() {
    matrix matrix_1{ 10, 10 }, matrix_2{ 10, 10 };
    my_vector vector_1{ 10 }, vector_2{ 10 };

    do_matrix_multiply(matrix_1, matrix_2);
    do_matrix_vector_multiply(matrix_1, vector_2);
    do_vector_innerproduct(vector_1, vector_2);

    return 0;
}