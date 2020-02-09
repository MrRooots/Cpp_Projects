#include <iostream>
using namespace std;

// Задание: Площадь в гектарах ↔ квадратных милях ↔ квадратных километрах.
// Считать, что 1 км2 равен 100 га, 1 кв. миля равна 2.588881 км2.


double ga_to_km(double ga) {
  return ga * 0.01;
}


double km_to_ga(double km) {
  return km * 100;
}


double mi_to_km(double mi) {
  return mi * 2.588881;
}


double km_to_mi(double km) {
  return km / 2.588881;
}


int main() {
  double len = 0;

  cout << "Enter length: "; cin >> len;

  cout << "Ga to km: " << ga_to_km(len) << endl;
  cout << "Km to ga: " << km_to_ga(len) << endl;
  cout << "Mi to km: " << mi_to_km(len) << endl;
  cout << "Km to mi: " << km_to_mi(len) << endl;
  cout << "Mi to ga: " << km_to_ga(mi_to_km(len)) << endl;
  cout << "Ga to mi: "<< km_to_mi(ga_to_km(len)) << endl;
  return 0;
}
