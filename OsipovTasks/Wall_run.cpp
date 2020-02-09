#include <iostream>

using namespace std;

// Последовательностью событий - тело долетело до позиции в которой была плоскость в момент его броска, а плоскость - убежала.
// Подумать, как получить точный результат в этом случае. Подумать, какие последовательности убывающие, возрастающие возникнут при таком моделировании.

int main() {
	// Будет бесконечно малая последовательность, стремящаяся к нулю как по времени, так и по расстоянию
	long double handicap = 1000, ball_speed=100, wall_speed=10, wall_coord = 1000, ball_coord = 0, current_wall_position = 1000, current_ball_position=0, time_before_reach;
	long double limit = 0.000000000000000000000000000000000000000000000000000001;
	cout.precision(10);
	cout << "Time" << "\t\t" << "Wall coord" << "\t" << "Ball coord" << "\t" << "Distance" << endl;

	// Пока ячейка памяти long double не переполнится
	while (handicap > limit) {
		cout << "|" << time_before_reach << "\t\t|" << current_wall_position << "\t\t|" << current_ball_position << "\t\t|" <<  handicap << endl;  // Вывод значений

		time_before_reach = wall_coord / ball_speed;  // Время, за которое тело достигнет позиции стены
		wall_coord = wall_speed * time_before_reach;  // Пока тело достигает позиции стена, стена улетает
		ball_coord = ball_speed * time_before_reach;  // Расчет оординаты тела

		// Счетчики текущего положения тела и стены
		current_wall_position += wall_coord;
		current_ball_position += ball_coord;

		handicap = wall_coord;  // Расчет растояния между ними
	}
	cout << "<------------------------------------------------------->" << endl << "ETC." << endl << "<------------------------------------------------------->";
	return 0;
}
