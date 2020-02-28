#include <iostream>
#include <ctime>

using namespace std;

// // Прототипы функции
// int **matrix_calculation(int row_1, int row_2, int column_1, int column_2, int **matrix_1, int **matrix_2, int **res_matrix);
// void test_function(int (&matrix_calculation)(int row_1, int row_2, int column_1, int column_2, int **matrix_1, int **matrix_2, int **res_matrix));

// Подсчет матрицы результата
double **matrix_calculation(int row_1, int row_2, int column_1, int column_2, double **matrix_1, double **matrix_2) {
  cout << "First matrix is:\n";
	for (int i = 0; i < row_1; i++) {
    for (int j = 0; j < column_1; j++) {
			cout << matrix_1[i][j] << "\t";
		}
    cout << endl;
  }

	cout << "Second matrix is:\n";
	for (int i = 0; i < row_2; i++) {
    for (int j = 0; j < column_2 ; j++) {
			cout << matrix_2[i][j] << "\t";
		}
    cout << endl;
  }

  // Инициализация результирующей матрицы
  double **res_matrix = new double* [row_1];

  // Расчет и заполнение
  for (int i = 0; i < row_1; i++) {
    res_matrix[i] = new double[column_2];

    for (int j = 0; j < column_2; j++) {
      res_matrix[i][j] = 0;

      for (int k = 0; k < column_1; k++) {
        res_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
      }
    }
  }
  return res_matrix;  // Возврат матрицы
}

void test_function(double** (&matrix_calculation)(int row_1, int row_2, int column_1, int column_2, double **matrix_1, double **matrix_2)) {
  srand(time(nullptr));
  for (size_t i = 0; i < 4; i++) {

  	int row_1 = rand()%10 + 1;
  	int column_1 = rand()%10 + 1;
  	int row_2 = column_1;
  	int column_2 = rand()%10 + 1;

  	// Проверка на возможность умножения
    if (column_1 != row_2) {
      cout << "Invalid sizes!!\n";
    } else {
  		// Инициализация первой матрицы
  	  double **matrix_1 = new double* [row_1];

  	  // Создание указателей на массивы в основном массиве :)
  	  for (int i = 0; i < row_1; i++) {
  	    matrix_1[i] = new double [column_1];
  	  }

  	  // Заполнение первого массива
  	  for (int i = 0; i < row_1; i++) {
  	    for (int j = 0; j < column_1; j++) {
  	      matrix_1[i][j] = rand()%20;
  	    }
  	  }

  		// Инициализация второй матрицы
  	  double **matrix_2 = new double* [row_2];

  	  // Создание указателей на массивы в основном массиве :)
  	  for (int i = 0; i < row_2; i++) {
  	    matrix_2[i] = new double [column_2];
  	  }

  	  // Заполнение второго массива
  	  for (int i = 0; i < row_2; i++) {
  	    for (int j = 0; j < column_2; j++) {
  	      matrix_2[i][j] = rand()%20;
  	    }
  	  }

      double **result = matrix_calculation(row_1, row_2, column_1, column_2, matrix_1, matrix_2);

      cout << "Result is: \n";
      for (size_t i = 0; i < row_1; i++) {
        for (size_t l = 0; l < column_2; l++) {
          cout << result[i][l] << '\t';
        }
        cout << '\n';
      }
      cout << "\n<<---------------------------------------------------------->>\n\n";
    }
  }
}

// Функция калькулятор должна возвращать матрицу!
int main() {
  test_function(matrix_calculation);
  return 0;
}
