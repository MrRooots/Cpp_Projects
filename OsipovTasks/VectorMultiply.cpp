#include <iostream>
#include <ctime>
using namespace std;


// Скалярное произведение для векторов любой размерности
double calculate_scalar_product(double coord_list_1[], double coord_list_2[], int length) {
	double result = 0;

	cout << "For vector a = [ ";
	for (size_t i = 0; i < length; i++) {
		cout << coord_list_1[i] << " ";
	}
	cout << "]\nDor vecot b = [ ";
	for (size_t i = 0; i < length; i++) {
		cout << coord_list_2[i] << " ";
	}
	cout << "]";
	for (size_t i = 0; i < length; i++) {
		result += coord_list_1[i]*coord_list_2[i];
	}

	return result;
}


double double_rand(double fMin, double fMax) {
    double f = (double)rand() / 10000;
    return fMin + f * (fMax - fMin);
}


int main() {
	int dim_count;
	srand(time(nullptr));

	// Считываем размерность векторов
	// cout << "Entera c count of dimensions: "; cin >> dim_count;
	dim_count = rand()%10+1;
	cout << "For dimension count: " << dim_count << endl;

	double *coord_list_1 = new double[dim_count];  // Список координат первого вектора
	double *coord_list_2 = new double[dim_count];  // Список координат второго вектора

	// Списак заполняется рандомными координатами
	for (size_t i = 0; i < dim_count; i++) {
		coord_list_1[i] = double_rand(0, 121);
		coord_list_2[i] = double_rand(0, 121);
	}

	cout << "\nResult is: " << calculate_scalar_product(coord_list_1, coord_list_2, dim_count);
	return 0;
}
