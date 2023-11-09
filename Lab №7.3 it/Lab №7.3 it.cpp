#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функція для обчислення характеристики стовпця
int col(int* column, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        if (column[i] < 0 && column[i] % 2 != 0) {
            sum += abs(column[i]);
        }
    }
    return sum;
}

// Функція для перестановки стовпців матриці за зростанням характеристик
void rearrangeCol(int** matrix, int k, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (col(matrix[j], k) > col(matrix[j + 1], k)) {
                for (int l = 0; l < k; ++l) {
                    std::swap(matrix[j][l], matrix[j + 1][l]);
                }
            }
        }
    }
}

// Функція для обчислення суми елементів у стовпці з від'ємними елементами
int sumOfColNegativeElements(int** matrix, int k, int n) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
        bool hasNegative = false;
        for (int i = 0; i < k; ++i) {
            if (matrix[j][i] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative) {
            for (int i = 0; i < k; ++i) {
                sum += matrix[j][i];
            }
        }
    }
    return sum;
}

// Функція для виводу матриці
void printMatrix(int** matrix, int k, int n) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(5) << matrix[j][i] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    srand(time(0));

    int k, n;
    std::cout << "Print row size (k): ";
    std::cin >> k;
    std::cout << "Print col size (n): ";
    std::cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[k];
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[j][i] = rand() % 100 - 50;
        }
    }

    std::cout << "Original matrix:\n";
    printMatrix(matrix, k, n);

    rearrangeCol(matrix, k, n);

    std::cout << "Sorted matrix:\n";
    printMatrix(matrix, k, n);

    int sum = sumOfColNegativeElements(matrix, k, n);

    std::cout << "Sum of cols negative elements: " << sum << "\n";

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
