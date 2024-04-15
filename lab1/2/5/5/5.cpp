#include <iostream>
using namespace std;

// Объявление прототипов функций
double metodD(double (*)(double), double, double, double, int);
double f(double);
double s(double);

int main()
{
  setlocale(LC_CTYPE, "rus"); // Установка русской локали для консоли
  int a = 1, b = 4, choice;
  double e = 0.001, x{};

  do
  {
    cout << "Введите номер уравнения (1 или 2): ";
    cin >> choice;
  } while (choice != 1 && choice != 2); // Проверка корректности ввода номера уравнения

  if (choice == 1)
  {
    cout << "Корень уравнения: " << metodD(f, a, b, e, choice) << endl; // Вызов метода дихотомии для уравнения f(x)
  }
  if (choice == 2)
  {
    cout << "Корень уравнения: " << metodD(s, a, b, e, choice) << endl; // Вызов метода дихотомии для уравнения s(x)
  }

  system("pause");
}

// Функция метода дихотомии
double metodD(double(*func)(double), double a, double b, double e, int ch)
{
  double x;

  while (abs(a - b) > 2 * e) // Цикл вычисления корня с заданной точностью
  {
    x = (a + b) / 2; // Вычисление середины отрезка

    if (ch == 1)
    {
      if (func(x) * func(a) <= 0)
      {
        b = x;
      }
      else
      {
        a = x;
      }
    }

    if (ch == 2)
    {
      if (func(x) * func(a) <= 0)
      {
        b = x;
      }
      else
      {
        a = x;
      }
    }
  }

  return x; // Возвращение найденного корня
}

// Уравнение f(x)
double f(double x)
{
  return pow(x, 3) + 3 * x - 1;
}

// Уравнение s(x)
double s(double x)
{
  return exp(x) - 4;
}
