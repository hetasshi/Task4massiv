#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Задание 1
void task1(int matrix[][4], int rows, int cols) {
    int sum = 0, minElem = INT_MAX, maxElem = INT_MIN;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int elem = matrix[i][j];
            sum += elem;
            if (elem < minElem) minElem = elem;
            if (elem > maxElem) maxElem = elem;
        }
    }

    double average = static_cast<double>(sum) / (rows * cols);

    cout << "Сумма всех элементов: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Минимальный элемент: " << minElem << endl;
    cout << "Максимальный элемент: " << maxElem << endl;
}

// Задание 2
void task2(int matrix[][4], int rows, int cols) {
    int rowSums[rows] = {0};
    int colSums[cols] = {0};
    int totalSum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
            totalSum += matrix[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "| " << rowSums[i] << endl;
    }

    cout << string(20, '-') << endl;

    for (int j = 0; j < cols; ++j) {
        cout << colSums[j] << " ";
    }
    cout << "| " << totalSum << endl;
}


// Задание 3
void task3() {
    const int rows1 = 5, cols1 = 10, cols2 = 5;
    int array1[rows1][cols1];
    int array2[rows1][cols2];

    srand(time(0));

    
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            array1[i][j] = rand() % 51;
        }
    }

    
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            array2[i][j] = array1[i][2 * j] + array1[i][2 * j + 1];
        }
    }

    cout << "Первый массив:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Второй массив:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cout << array2[i][j] << " ";
        }
        cout << endl;
    }
}

// Задание 4
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// Задание 5
void task5() {
    int grades[10];
    cout << "Введите 10 оценок студента:" << endl;
    for (int i = 0; i < 10; ++i) cin >> grades[i];

    while (true) {
        cout << "Меню:\n1. Вывод оценок\n2. Пересдача экзамена\n3. Проверка на стипендию\n4. Выход" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < 10; ++i) cout << grades[i] << " ";
            cout << endl;
        } else if (choice == 2) {
            int index, newGrade;
            cout << "Введите номер оценки (0-9) и новую оценку:" << endl;
            cin >> index >> newGrade;
            if (index >= 0 && index < 10) grades[index] = newGrade;
        } else if (choice == 3) {
            double average = 0;
            for (int i = 0; i < 10; ++i) average += grades[i];
            average /= 10;
            cout << (average >= 4.5 ? "Стипендия выходит." : "Стипендия не выходит.") << endl;
        } else if (choice == 4) {
            break;
        }
    }
}

// Задание 6
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            ++i;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Задание 7
void task7(int array[], int size) {
    double average = 0;
    for (int i = 0; i < size; ++i) average += array[i];
    average /= size;

    int limit = (average > 0) ? (size * 2 / 3) : (size / 3);

    for (int i = 0; i < limit - 1; ++i) {
        for (int j = 0; j < limit - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = limit, j = size - 1; i < j; ++i, --j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    for (int i = 0; i < size; ++i) cout << array[i] << " ";
    cout << endl;
}

int main() {
    // Задание 1
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "Задание 1:" << endl;
    task1(matrix1, 3, 4);

    // Задание 2
    cout << "\nЗадание 2:" << endl;
    task2(matrix1, 3, 4);

    // Задание 3
    cout << "\nЗадание 3:" << endl;
    task3();

    // Задание 5
    cout << "\nЗадание 5:" << endl;
    task5();

    // Задание 7
    cout << "\nЗадание 7:" << endl;
    int array7[15] = {3, -5, 8, 1, 0, -2, 7, 4, -9, 6, 11, -1, 2, 5, -3};
    task7(array7, 15);
  
    return 0;
}
