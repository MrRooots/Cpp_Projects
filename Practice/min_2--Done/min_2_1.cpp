// DONE //
// https://ideone.com/noVrkb

#include <iostream>
using namespace std;

// Проверка попадание в круг
bool is_inside_circle(float x, float y, float circle_x, float circle_y, float circle_radius){
  float dx = x - circle_x, dy = y - circle_y;

  return dx * dx + dy * dy <= circle_radius * circle_radius;
};


// Проверка на попадание в первый прямоугольник
bool is_inside_up_to_down_rectangle(float x, float y, float x_max, float y_max, float x_min, float y_min) {
  return x < x_max && x > x_min && y >= y_min && y <= y_max;
};


// Проверка на попадание во второй прямоугольник
bool is_inside_left_to_right_rectangle(float x, float y, float x_max, float y_max, float x_min, float y_min) {
  return x < x_max && x > x_min && y > y_min && y < y_max;
};


// Логическое произведение всех попаданий
bool is_inside_figure(float x, float y) {
  return is_inside_circle(x, y, 0, 0, 4) && !is_inside_up_to_down_rectangle(x, y, 1, 4, -1, -4) && !is_inside_left_to_right_rectangle(x, y, 4, 1, -4, -1);
};

// Основная ф-ция
int main(){
  cout << "Enter an x, y coordinates (any char to exit): " << endl;

  // Ввод координат пользователем
  for (float x = 0, y = 0; cin >> x >> y;) {
    is_inside_figure(x, y) == 1? cout << "Попадание!" << endl: cout << "Промах!" << endl;
  };

  return 0;
}
