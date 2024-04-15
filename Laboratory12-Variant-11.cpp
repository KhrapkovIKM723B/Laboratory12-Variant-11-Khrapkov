#include <iostream>
#include <stdlib.h>

using namespace std;
const int SIZE = 10;

void fillAndShowArray(int arr[][SIZE], const int size);
int findMinElement(int arr[][SIZE], const int size);
int findMaxElement(int arr[][SIZE], const int size);
void swapMinAndMax(int arr[][SIZE], const int size);
int sumMainDiagonal(int arr[][SIZE], const int size);

int main() {
    setlocale(LC_ALL, "ukr");
    int matrix[SIZE][SIZE] = {};

    fillAndShowArray(matrix, SIZE);

    cout << endl;
    cout << "Мiнiмум: " << findMinElement(matrix, SIZE) << endl;
    cout << "Максимум: " << findMaxElement(matrix, SIZE) << endl;

    swapMinAndMax(matrix, SIZE);
    fillAndShowArray(matrix, SIZE); 

    cout << sumMainDiagonal(matrix, SIZE) << endl;

    return 0;
}

void fillAndShowArray(int arr[][SIZE], const int size)
{
    for (int i = 0; i < size; i++) {
        cout << "| ";
        for (int j = 0; j < size; j++) {
            arr[i][j] = 1 + rand() % 100; 
            cout << arr[i][j] << " ";
        }
        cout << " |" << endl;
    }
}

int findMinElement(int arr[][SIZE], const int size) {
    int min = arr[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] < min)
                min = arr[i][j];
        }
    }
    return min;
}

int findMaxElement(int arr[][SIZE], const int size) {
    int max = arr[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}

void swapMinAndMax(int arr[][SIZE], const int size) {
    int min = arr[0][0], max = arr[0][0];
    int minI = 0, minJ = 0, maxI = 0, maxJ = 0;

   
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
                minI = i;
                minJ = j;
            }
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

  
    arr[minI][minJ] = max;
    arr[maxI][maxJ] = min;
}

int sumMainDiagonal(int arr[][SIZE], const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i][i];
    }
    return sum;
}