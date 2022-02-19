#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "libs/data_structures/matrix/matrix.h"

int sumRowOrColumns(int *a, int sizeA) {
    int sum = 0;
    for (int i = 0; i < sizeA; i++) {
        sum += a[i];
    }
    return sum;
}

void swap(float *a, float *b) {
    float t = *a;
    *a = *b;
    *b = t;
}

void test_swapRows_usualMatrix() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    matrix m1 = createMatrixFromArray(a, 3, 3);
    swapRows(m1, 0, 1);
    int b[] = {4, 5, 6, 1, 2, 3, 7, 8, 9};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapRows_oneRow() {
    int a[] = {1, 2, 3};
    matrix m1 = createMatrixFromArray(a, 1, 3);
    swapRows(m1, 0, 0);
    int b[] = {1, 2, 3};
    matrix m2 = createMatrixFromArray(b, 1, 3);

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapColumns_usualMatrix() {
    int a[] = {1, 2, 3, 4,
               5, 6, 7, 8,
               9, 10, 11, 12};
    matrix matrix1 = createMatrixFromArray(a, 3, 4);
    swapColumns(matrix1, 0, 3);
    int b[] = {4, 2, 3, 1,
               8, 6, 7, 5,
               12, 10, 11, 9};
    matrix matrix2 = createMatrixFromArray(b, 3, 4);
    assert(twoMatricesEqual(matrix1, matrix2));
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_swapColumns_oneColumns() {
    int a[] = {1, 2, 3};
    matrix matrix1 = createMatrixFromArray(a, 3, 1);
    swapColumns(matrix1, 0, 0);
    int b[] = {1, 2, 3};
    matrix matrix2 = createMatrixFromArray(b, 3, 1);

    assert(twoMatricesEqual(matrix1, matrix2));
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_insertionSortRowsMatrixByRowCriteria_usualMatrix() {
    int a[] = {2, 2, 2, 2,
               3, 3, 3, 3,
               1, 1, 1, 1};
    matrix matrix1 = createMatrixFromArray(a, 3, 4);
    insertionSortRowsMatrixByRowCriteria(matrix1, sumRowOrColumns);
    int b[] = {1, 1, 1, 1,
               2, 2, 2, 2,
               3, 3, 3, 3};
    matrix matrix2 = createMatrixFromArray(b, 3, 4);

    assert(twoMatricesEqual(matrix1, matrix2));
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_insertionSortRowsMatrixByRowCriteria_oneRow() {
    int a[] = {1, 1, 1, 1};
    matrix matrix1 = createMatrixFromArray(a, 1, 4);
    insertionSortRowsMatrixByRowCriteria(matrix1, sumRowOrColumns);
    int b[] = {1, 1, 1, 1};
    matrix matrix2 = createMatrixFromArray(b, 1, 4);

    assert(twoMatricesEqual(matrix1, matrix2));
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_insertionSortColsMatrixByColCriteria_usualMatrix() {
    int a[] = {3, 1, 2, 1,
               3, 1, 2, 1,
               3, 1, 2, 1};
    matrix matrix1 = createMatrixFromArray(a, 3, 4);
    insertionSortColsMatrixByColCriteria(matrix1, sumRowOrColumns);
    int b[] = {1, 1, 2, 3,
               1, 1, 2, 3,
               1, 1, 2, 3};
    matrix matrix2 = createMatrixFromArray(b, 3, 4);

    assert(twoMatricesEqual(matrix1, matrix2));
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_insertionSortColsMatrixByColCriteria_oneColumn() {
    int a[] = {1,
               1,
               1};
    matrix matrix1 = createMatrixFromArray(a, 3, 1);
    insertionSortColsMatrixByColCriteria(matrix1, sumRowOrColumns);
    int b[] = {1,
               1,
               1};
    matrix matrix2 = createMatrixFromArray(b, 3, 1);

    assert(twoMatricesEqual(matrix1, matrix2));
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_isEMatrix_oneElement() {
    int a[] = {1};
    matrix matrix1 = createMatrixFromArray(a, 1, 1);

    assert(isEMatrix(matrix1));
    freeMemMatrix(matrix1);
}

void test_isEMatrix_nonSquareMatrix() {
    int a[] = {1, 0, 0, 0,
               0, 1, 0, 0,
               0, 0, 1, 0};
    matrix matrix1 = createMatrixFromArray(a, 3, 4);

    assert(!isEMatrix(matrix1));
    freeMemMatrix(matrix1);
}

void test_isEMatrix_EMatrix() {
    int a[] = {1, 0, 0,
               0, 1, 0,
               0, 0, 1};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    assert(isEMatrix(matrix1));
    freeMemMatrix(matrix1);
}

void test_isEMatrix_nonEMatrix() {
    int a[] = {0, 0, 1,
               0, 1, 0,
               1, 0, 0};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    assert(!isEMatrix(matrix1));
    freeMemMatrix(matrix1);
}

void test_isSymmetricMatrix_nonSquareMatrix() {
    int a[] = {1, 2, 3, 4,
               2, 3, 4, 5,
               3, 4, 5, 6};
    matrix matrix1 = createMatrixFromArray(a, 3, 4);
    assert(!isSymmetricMatrix(matrix1));
    freeMemMatrix(matrix1);
}

void test_isSymmetricMatrix_symmetricMatrix() {
    int a[] = {1, 2, 3,
               2, 3, 4,
               3, 4, 5};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    assert(isSymmetricMatrix(matrix1));
    freeMemMatrix(matrix1);
}

void test_isSymmetricMatrix_nonSymmetricMatrix() {
    int a[] = {1, 2, 3,
               2, 3, 4,
               6, 4, 5};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    assert(!isSymmetricMatrix(matrix1));
    freeMemMatrix(matrix1);
}

void test_transposeSquareMatrix() {
    int a[] = {1, 2, 3,
               4, 5, 6,
               7, 8, 9};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    transposeSquareMatrix(matrix1);
    int b[] = {1, 4, 7,
               2, 5, 8,
               3, 6, 9};
    matrix matrix2 = createMatrixFromArray(b, 3, 3);

    assert(twoMatricesEqual(matrix1, matrix2));
    freeMemMatrix(matrix1);
    freeMemMatrix(matrix2);
}

void test_getMinValuePos_oneElement() {
    int a[] = {1};
    matrix matrix1 = createMatrixFromArray(a, 1, 1);
    position minValuePos = getMinValuePos(matrix1);

    assert(minValuePos.rowIndex == 0);
    assert(minValuePos.colIndex == 0);
    freeMemMatrix(matrix1);
}

void test_getMinValuePos_oneMinValue() {
    int a[] = {9, 8, 7,
               6, 5, 4,
               3, 2, 1};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    position minValuePos = getMinValuePos(matrix1);

    assert(minValuePos.rowIndex == 2);
    assert(minValuePos.colIndex == 2);
    freeMemMatrix(matrix1);
}

void test_getMinValuePos_manyMinValue() {
    int a[] = {1, 0, 0,
               0, 1, 0,
               0, 0, 1};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    position minValuePos = getMinValuePos(matrix1);

    assert(minValuePos.rowIndex == 0);
    assert(minValuePos.colIndex == 1);
    freeMemMatrix(matrix1);
}

void test_getMaxValuePos_oneElement() {
    int a[] = {1};
    matrix matrix1 = createMatrixFromArray(a, 1, 1);
    position maxValuePos = getMaxValuePos(matrix1);

    assert(maxValuePos.rowIndex == 0);
    assert(maxValuePos.colIndex == 0);
    freeMemMatrix(matrix1);
}

void test_getMaxValuePos_oneMinValue() {
    int a[] = {5, 8, 7,
               6, 4, 9,
               3, 2, 1};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    position maxValuePos = getMaxValuePos(matrix1);

    assert(maxValuePos.rowIndex == 1);
    assert(maxValuePos.colIndex == 2);
    freeMemMatrix(matrix1);
}

void test_getMaxValuePos_manyMinValue() {
    int a[] = {1, 0, 0,
               0, 1, 0,
               0, 0, 1};
    matrix matrix1 = createMatrixFromArray(a, 3, 3);
    position maxValuePos = getMaxValuePos(matrix1);

    assert(maxValuePos.rowIndex == 0);
    assert(maxValuePos.colIndex == 0);
    freeMemMatrix(matrix1);
}


void test_swapRows() {
    test_swapRows_usualMatrix();
    test_swapRows_oneRow();
}

void test_swapColumns() {
    test_swapColumns_usualMatrix();
    test_swapColumns_oneColumns();
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_usualMatrix();
    test_insertionSortRowsMatrixByRowCriteria_oneRow();
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_usualMatrix();
    test_insertionSortColsMatrixByColCriteria_oneColumn();
}

void test_isEMatrix() {
    test_isEMatrix_EMatrix();
    test_isEMatrix_oneElement();
    test_isEMatrix_nonSquareMatrix();
    test_isEMatrix_nonEMatrix();
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_nonSquareMatrix();
    test_isSymmetricMatrix_symmetricMatrix();
    test_isSymmetricMatrix_nonSymmetricMatrix();
}

void test_getMinValuePos() {
    test_getMinValuePos_oneElement();
    test_getMinValuePos_oneMinValue();
    test_getMinValuePos_manyMinValue();
}

void test_getMaxValuePos() {
    test_getMaxValuePos_oneElement();
    test_getMaxValuePos_oneMinValue();
    test_getMaxValuePos_manyMinValue();
}

void test() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

void solvingProblemNumberOne() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapColumns(m, minPos.colIndex, maxPos.colIndex);

    outputMatrix(m);

    freeMemMatrix(m);
    
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void solvingProblemNumberTwo() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    sortRowsByMinElement(m);

    outputMatrix(m);

    freeMemMatrix(m);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void solvingProblemNumberThree() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    sortColsByMinElement(m);

    outputMatrix(m);

    freeMemMatrix(m);
}


matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "it is impossible to multiply matrices");
        exit(1);
    }

    matrix m = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int sum = 0;
            for (int index = 0; index < m1.nCols; index++) {
                sum += m1.values[i][index] * m2.values[index][j];
            }
            m.values[i][j] = sum;
        }
    }

    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

void solvingProblemNumberFour() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    getSquareOfMatrixIfSymmetric(&m);

    outputMatrix(m);

    freeMemMatrix(m);
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                return false;
            }
        }
    }
    return true;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long *a = (long long *)malloc(m.nRows * sizeof(long long));
    for (int i = 0; i < m.nRows; i++) {
        a[i] = getSum(m.values[i], m.nCols);
    }

    if (isUnique(a, m.nRows)) {
        transposeSquareMatrix(m);
    }

    free(a);
}

void solvingProblemNumberFive() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    transposeIfMatrixHasNotEqualSumOfRows(m);

    outputMatrix(m);

    freeMemMatrix(m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m = mulMatrices(m1, m2);
    return isEMatrix(m);
}

void solvingProblemNumberSix() {
    int row1, col1;
    scanf("%d %d", &row1, &col1);

    matrix m1 = getMemMatrix(row1, col1);
    inputMatrix(m1);

    int row2, col2;
    scanf("%d %d", &row2, &col2);

    matrix m2 = getMemMatrix(row2, col2);
    inputMatrix(m2);

    if (isMutuallyInverseMatrices(m1, m2)) {
        printf("True");
    } else {
        printf("False");
    }

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

int max(int a, int b) {
    return a > b ? a: b;
}

int min(int a, int b) {
    return a < b ? a: b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.nRows + m.nCols;
    int sizeA = 0;
    int *a = (int *)malloc((n - 1) * sizeof(int));
    for (int i = 1; i < n; i++) {
        position currentPos;
        currentPos.rowIndex = m.nRows > i ? (m.nRows - i) : 0;
        currentPos.colIndex = i >= m.nRows ? (i - m.nRows) : 0;

        int maxValue = m.values[currentPos.rowIndex][currentPos.colIndex];
        while (currentPos.rowIndex < m.nRows && currentPos.colIndex < m.nCols) {
            maxValue = max(maxValue, m.values[currentPos.rowIndex++][currentPos.colIndex++]);
        }

        bool isUniqueValue = true;
        for (int j = 0; j < sizeA; j++) {
            if (maxValue == a[j]) {
                isUniqueValue = false;
            }
        }

        if (isUniqueValue) {
            a[sizeA++] = maxValue;
        }
    }

    long long result = getSum(a, sizeA);

    free(a);

    return result;
}

void solvingProblemNumberSeven() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    printf("%lld", findSumOfMaxesOfPseudoDiagonal(m));

    freeMemMatrix(m);
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);

    int minValue = m.values[maxPos.rowIndex][maxPos.colIndex];
    for (int i = maxPos.rowIndex - 1; i >= 0; i--) {
        int difference = maxPos.rowIndex - i;

        position currentPos;
        currentPos.rowIndex = i;
        currentPos.colIndex = max(maxPos.colIndex - difference, 0);

        int distance = difference * 2 + 1;
        for (int j = 0; j < distance && currentPos.colIndex < m.nCols; j++) {
            minValue = min(minValue, m.values[currentPos.rowIndex][currentPos.colIndex++]);
        }
    }

    return minValue;
}

void solvingProblemNumberEight() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    printf("%d", getMinInArea(m));

    freeMemMatrix(m);
}

float getDistance(int *a, int n) {
    long long distance = 0;
    for (int i = 0; i < n; i++) {
        distance += a[i] * a[i];
    }
    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *b = (float *)malloc(m.nRows * sizeof(float));

    for (int i = 0; i < m.nRows; i++) {
        b[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 0; i < m.nRows - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nRows; j++) {
            if (b[j] < b[minIndex]) {
                minIndex = j;
            }
        }
        swapRows(m, minIndex, i);
        swap(&b[minIndex], &b[i]);
    }

    free(b);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void solvingProblemNumberNine() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    sortByDistances(m);

    outputMatrix(m);

    freeMemMatrix(m);
}

int main() {
    test();
    //solvingProblemNumberOne();
    //solvingProblemNumberTwo();
    //solvingProblemNumberThree();
    //solvingProblemNumberFour();
    //solvingProblemNumberFive();
    //solvingProblemNumberSix();
    //solvingProblemNumberSeven();
    //solvingProblemNumberEight();
    solvingProblemNumberNine();

    return 0;
}
