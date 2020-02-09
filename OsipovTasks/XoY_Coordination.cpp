// Вывести минимум положительных чисел (или нуль) и вернуть произведение неотрицательных чисел.

#include <iostream>
#include <math.h>  // Математические ф-ции
using namespace std;

// Расчет координат тела, брошенного под углом к горизонту
int main() {
  const float G = 9.81;
  const double To_Degrees = M_PI/180;  // Значение для перевода аргумента тригонометрической ф-ции в грдусы
  double angle, speed, abs_speed, speed_y, speed_x, t, coord_x, coord_y, out_count, wall_x_coord, wall_y_coord, wall_heigh, wall_width;

  // Считывание данных
  cout << "Угол: "; cin >> angle;  // Угол в градусах 70
  cout << "Скорость (м/с): "; cin >> speed;  // Скорость в м/с 100
  cout << "Время (с): "; cin >> t;  // Время в секундах
  cout << "Введите координаты нижней части препятствия (x, y), высоту и ширину (через пробел): "; cin >> wall_x_coord >> wall_y_coord >> wall_heigh >> wall_width;  // Координаты препятствия
  cout << "Кол-во выводов: "; cin >> out_count;  // Кол-во выводов координат

  //////////////////////////////////////////////////////////////////////////////// Testing case
  // angle = 70;
  // speed = 100;
  // t = 20;
  // out_count = 40;
  // wall_x_coord = -1;
  // wall_y_coord = -10;
  // wall_heigh = -1;
  // wall_width = -1;
  //////////////////////////////////////////////////////////////////////////////// Testing case

  speed_y = speed * sin(angle * To_Degrees);
	speed_x = speed * cos(angle * To_Degrees);


  // Проверка о столкновении до начала цикла с выводами
  for (float i = 0; i <= t; i += 0.01){
    coord_x = speed * cos(angle * To_Degrees) * i;  // Расчет координаты по x
    coord_y = speed * sin(angle * To_Degrees) * i - (G * i * i) / 2;  // Расчет координаты по y

    // Если тело попадает в зону препятствия (Прямоугольник)
    if (coord_y <= wall_y_coord + wall_heigh && coord_y >= wall_y_coord && coord_x <= wall_x_coord + wall_width && coord_x >= wall_x_coord) {
      cout << "Тело столкнулось с препятствием на координатах: x: " << coord_x << "y: " << coord_y << endl;
      return 0;
    }
  };

  // Ровный вывод координат за ровные доли общего времени
  for (float i = 0; i <= t; i += t / out_count) {
    coord_x = speed * cos(angle * To_Degrees) * i;  // Расчет координаты по x
    coord_y = speed * sin(angle * To_Degrees) * i - (G * i * i)/2;  // Расчет координаты по y

    abs_speed = sqrt((speed_y - G * i) * (speed_y - G * i) + speed_x * speed_x) ;

    // Если тело попадает в зону препятствия (Прямоугольник)
    if (coord_y <= wall_y_coord + wall_heigh && coord_y >= wall_y_coord && coord_x <= wall_x_coord + wall_width && coord_x >= wall_x_coord) {
      cout << "Произошло столкновение с препятствием!";
      return 0;
    } else {
      cout << "Время: " << i << " секунд: координата по x: " << coord_x << ", координата по y: " << coord_y << ". Абсолютная скорость: " << abs_speed << endl;  // Построчный вывод
    };
  };

  cout << "Столкновения не произошло!";

  return 0;
}
