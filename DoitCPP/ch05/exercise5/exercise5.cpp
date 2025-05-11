#include <iostream>
#include <random>
#include <stdexcept>
#include <limits>


int main() {
    // 1부터 100까지 랜덤 숫자 생성
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    int answer = dist(gen);

    // *count 변수는 문제와는 상관없지만, 게임의 재미를 위해 추가하였습니다.
    // *몇 번만에 숫자 맞히기를 성공하는지 카운트하기 위해 활용되는 변수입니다. :)
    int count = 0;

    // 게임 시작
    bool is_correct = false;
    while (!is_correct) {
        try {
            // 사용자에게 숫자 입력 요청
            ++count;
            std::cout << "숫자를 입력하세요: ";
            int guess;
            std::cin >> guess;

            // 숫자가 아닌 입력
            if (std::cin.fail()) {
                std::cin.clear(); // 입력 스트림의 상태를 초기화
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
                throw std::invalid_argument("숫자를 입력해주세요!");
            }

            // 입력한 숫자가 범위를 벗어나는지 확인
            if (guess < 1 || guess > 100) {
                throw std::out_of_range("1부터 100 사이의 숫자를 입력해주세요!");
            }

            // 숫자 비교 후 메시지 출력
            if (guess > answer) {
                std::cout << "너무 높아요!" << std::endl << std::endl;
            }
            else if (guess < answer) {
                std::cout << "너무 낮아요!" << std::endl << std::endl;
            }
            else {
                std::cout << "축하합니다! 정답은 " << answer << "입니다." << std::endl;
                std::cout << count << "번 만에 맞추셨습니다. :)" << std::endl;
                is_correct = true;
            }
        }
        // reference variable e
        catch (const std::exception& e) {
            // 예외 발생 시 에러 메시지 출력
            std::cerr << e.what() << std::endl << std::endl;
        }
    }

    return 0;
}