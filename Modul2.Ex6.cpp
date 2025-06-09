#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>

#define ROWS 10
#define COLS 10

// Введення елементів матриці вручну
int inputMatrix(int matrix[ROWS][COLS]) {
    printf("Введiть елементи матрицi 10x10:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("matrix[%d][%d]: ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

// Заповнення матриці випадковими числами
void fillMatrixRandom(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = -100 + rand() % 201; // від -100 до 100
        }
    }
}

// Виведення матриці
int printMatrix(int matrix[ROWS][COLS]) {
    printf("\nМатриця:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 1;
}

// Знаходження максимального значення
int findMax(int matrix[ROWS][COLS]) {
    int max = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

// Знаходження мінімального значення
int findMin(int matrix[ROWS][COLS]) {
    int min = matrix[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

// Обчислення середнього арифметичного min і max
double averageMinMax(int min, int max) {
    return (min + max) / 2.0;
}

// Головна програма
int main() {
    setlocale(LC_ALL, "Ukrainian");
    srand((unsigned int)time(NULL));
    int matrix[ROWS][COLS];
    int choice;

    printf("Оберiть спосiб заповнення матрицi:\n");
    printf("1 - Ввести вручну\n");
    printf("2 - Заповнити випадковими числами\n");
    printf("Ваш вибiр: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Невiрний вибiр.\n");
        return 1;
    }

    if (choice == 1) {
        if (!inputMatrix(matrix)) {
            printf("Помилка введення.\n");
            return 1;
        }
    }
    else if (choice == 2) {
        fillMatrixRandom(matrix);
        printf("Матриця успiшно заповнена випадковими числами.\n");
    }

    printMatrix(matrix);

    int min = findMin(matrix);
    int max = findMax(matrix);
    double avg = averageMinMax(min, max);

    printf("\nМiнiмальний елемент: %d\n", min);
    printf("Максимальний елемент: %d\n", max);
    printf("Середнє арифметичне: %.2lf\n", avg);

    return 0;
}

