#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::vector<std::string> num_str_vector;  // Создаем вектор для хранения введенных значений

    for (int i = 0; i < 100; ++i) {   // Вводим 100 чисел и добавляем их в вектор
        std::string num_str;
        std::cout << "Введите " << i + 1 << "-е число (100 значное): ";
        std::cin >> num_str;

        bool valid_input = true;  // Проверяем, что введенная строка состоит только из цифр и имеет длину 100 символов
        if (num_str.length() != 100) {
            valid_input = false;
        } else {
            for (char c : num_str) {
                if (!isdigit(c)) {
                    valid_input = false;
                    break;
                }
            }
        }

        if (valid_input) {
            num_str_vector.push_back(num_str);
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите 100 значное число, состоящее только из цифр." << std::endl;
            --i; // Повторяем ввод
        }
    }

    // Создаем вектор для хранения целых чисел
    std::vector<int> num_int_vector;

    // Преобразуем строки в векторе в целые числа
    for (const std::string& num_str : num_str_vector) {
        int num_int = std::stoi(num_str);
        num_int_vector.push_back(num_int);
    }

    // Вычисляем сумму и разность чисел
    int total_sum = 0;
    int total_diff = num_int_vector[0];

    for (int i = 1; i < num_int_vector.size(); ++i) {
        total_sum += num_int_vector[i];
        total_diff -= num_int_vector[i];
    }

    // Выводим результаты
    std::cout << "Сумма всех чисел: " << total_sum << std::endl;
    std::cout << "Разность первого числа и суммы остальных: " << total_diff << std::endl;

    return 0;
}
