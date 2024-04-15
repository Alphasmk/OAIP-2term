#include <iostream>
#include <stdexcept>
using namespace std;

// Функция деления двух чисел
double divide(double numerator, double denominator) {
    // Попытка деления
    try {
        if (denominator == 0.0) {
            // Генерация исключения при попытке деления на ноль
            throw runtime_error("Деление на ноль недопустимо.");
        }

        // Если деление возможно, возвращаем результат
        return numerator / denominator;

    }
    catch (const exception& e) {
        // Перехватываем исключение и выводим сообщение об ошибке
        cerr << "Исключение: " << e.what() << endl;

        // Возвращаем значение по умолчанию
        return 0.0;
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");

    double result;

    // Пример использования функции деления с блоком try-catch
    result = divide(10.0, 2.0);
    cout << "Результат деления: " << result << endl;

    // Попытка деления на ноль
    result = divide(5.0, 0.0);
    cout << "Результат деления: " << result << endl;  // Никогда не будет достигнут

    return 0;
}