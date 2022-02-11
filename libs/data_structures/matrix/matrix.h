//
// Created by Григорий on 11.02.2022.
//

#ifndef MATRICES_MATRIX_H
#define MATRICES_MATRIX_H

typedef struct matrix {
    int **values;       // Элементы матрицы
    int nRows;          // Количество рядов
    int nCols;          // Количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

#endif //MATRICES_MATRIX_H
