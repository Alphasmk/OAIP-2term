#include <iostream>
#include <cstdarg>
using namespace std;

// Объявление прототипа функции для поиска всех простых чисел в нескольких интервалах
void isPrimeNumber(int, ...);

int main()
{
  // Проверяем несколько интервалов
  isPrimeNumber(6, 1, 20, 15, 21, 39, 63);
  isPrimeNumber(4, 8, 23, 40, 82);
  isPrimeNumber(2, 30, 67);
  system("pause");
}

void isPrimeNumber(int a, ...)
{
  va_list args; // Список аргументов переменной длины
  va_start(args, a); // Инициализация списка аргументов
  bool isPrime;
  int x, y;
  // Перебираем все интервалы
  for (int k = 1; k <= a / 2; ++k)
  {
    x = va_arg(args, int); // Получаем начало интервала(a)
    y = va_arg(args, int); // Получаем конец интервала(b)
    // Перебираем числа в текущем интервале
    for (int n = x; n <= y; n++)
    {
      isPrime = true; // Предполагаем, что число является простым перед проверкой
      // Проверяем частные случаи и делаем проверку на простоту
      if (n <= 1) {
        isPrime = false;
      }
      else if (n == 2) {
        isPrime = true;
      }
      else if (n % 2 == 0) {
        isPrime = false;
      }
      else {
        // Проверяем делители до квадратного корня числа
        for (int i = 3; i <= sqrt(n); i += 2) {
          if (n % i == 0) {
            isPrime = false;
            break;
          }
        }
      }

      // Если число простое, выводим его
      if (isPrime)
      {
        cout << n << " ";
      }
    }
    cout << "   "; // Разделяем результаты для разных интервалов
  }
  va_end(args);

  printf("\n");
  printf("\n");
}
// P.S. Алгоритм поиска простого числа частично взят из интернета и доработан