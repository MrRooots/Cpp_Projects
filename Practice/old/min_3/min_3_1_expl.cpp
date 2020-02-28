#include <iostream>
#include <cmath>
#include <cassert> // assert
using namespace std;

int const INFINITE_ROOTS = -1;  // Особое значение "бесконечное (несчётное) количество корней".
using NT = float;  // Используемый числовой тип (Number Type).

NT const // Вспомогательные числовые константы:
  HALF_PI   = 1.5707963267948966, // половина пи,
  PI        = 3.1415926535897932, // число пи,
  DOUBLE_PI = 6.2831853071795865, // два пи,
  TOLERANCE = 1e-10; // граница между "нулём" и "ненулём".

// Логарифм по произвольному основанию.
NT log(NT base, NT arg) {
  return log(arg) / log(base);
}

// Проверка значения на близость нулю.
bool is_almost_zero(NT x, NT tolerance = TOLERANCE) {
  return fabs(x) <= tolerance;
}

// Левая часть уравнения.
NT f(NT a, NT b, NT c, NT x) {
  return 1 + sin(pow(a, x) + fabs(log(b, c)));
}

// Решаем уравнение f(a, b, c, root) = 0.
// Функция возвращает "количество корней",
// один корень записывает по ссылке.
int solve_f(NT a, NT b, NT c, NT & root) {
  if (a < 0 || b <= 0 || b == 1 || c <= 0) {
    return 0; // нет корней.
  }

  // Потенциально почти все возможные x -- корни:
  if (a == 0 || a == 1) {
    return is_almost_zero(f(a, b, c, 1)) ? INFINITE_ROOTS : 0;
  }

  // Счётное число корней, получим один из них.
  NT const
    // Часть выражения:
    expr_part = fabs(log(b, c)) + HALF_PI,
    // Номер корня:
    n = 1 + ceil(expr_part / DOUBLE_PI),
    // Аргумент логарифма в формуле корня:
    log_arg = DOUBLE_PI*n - expr_part;

  assert(log_arg > 0);
  root = log(a, log_arg);
  return 1;
}

int main() {
  cout << "Solving f(a, b, c, x) = 0," << " enter a, b, c:\n";
  cout.precision(16);

  for (NT a, b, c, x; cin >> a >> b >> c;) {
    switch (solve_f(a, b, c, x)) {
    case 0:
      cout << "no roots\n";
      break;

    case INFINITE_ROOTS:
      cout << "any number is a root\n";
      break;

    case 1: // один корень, записан в x
      cout << "x == " << x
           << ", error is " << f(a, b, c, x)
           << endl;
      break;

    default:
      assert(!"impossible roots quantity");
      cout << "unknown error\n";
      return 1; // ошибка.
    }
  }

  return 0;
}
