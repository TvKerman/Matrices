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
    bool isInverseMatrices = isEMatrix(m);
    freeMemMatrix(m);
    return isInverseMatrices;
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

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *)pa;
    long long arg2 = *(const long long *)pb;

    if (arg1 < arg2) {
        return -1;
    } else if (arg1 > arg2) {
        return 1;
    } else {
        return 0;
    }
}

int countNUnique(long long *a, int n) {
    if (n == 0) {
        return 0;
    }

    int count = 1;
    long long previousClass = a[0];
    for (int i = 1; i < n; i++) {
        if (previousClass != a[i]) {
            count += 1;
        }

        previousClass = a[i];
    }

    return count;
}

int countEqClassesByRowsSum(matrix m)  {
    long long *a = (long long *)malloc(m.nRows * sizeof(long long));
    for (int i = 0; i < m.nRows; i++) {
        a[i] = getSum(m.values[i], m.nCols);
    }

    qsort(a, m.nRows, sizeof(long long), cmp_long_long);

    int count = countNUnique(a, m.nRows);

    free(a);
    return count;
}

void solvingProblemNumberTen() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    printf("%d", countEqClassesByRowsSum(m));

    freeMemMatrix(m);
}

int getNSpecialElement(matrix m) {
    int count = 0;
    for (int j = 0; j < m.nCols; j++) {
        int max = m.values[0][j];
        int sum = 0;
        for (int i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > max) {
                sum += max;
                max = m.values[i][j];
            } else {
                sum += m.values[i][j];
            }
        }

        if (max > sum) {
            count += 1;
        }
    }

    return count;
}

void solvingProblemNumberEleven() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    printf("%d", getNSpecialElement(m));

    freeMemMatrix(m);
}

position getLeftMin(matrix m) {
    position minPos = {0, 0};

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if ((m.values[minPos.rowIndex][minPos.colIndex] > m.values[i][j]) ||
                    (m.values[minPos.rowIndex][minPos.colIndex] == m.values[i][j] && minPos.colIndex > j)) {
                minPos.rowIndex = i;
                minPos.colIndex = j;
            }
        }
    }

    return minPos;
}

void swapPenultimateRow(matrix m, int n) {
    for (int i = m.nCols - 1; i >= 0; i--) {
        m.values[m.nRows - 2][i] = m.values[i][n];
    }
}

void solvingProblemNumberTwelve() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    position pos = getLeftMin(m);
    swapPenultimateRow(m, pos.colIndex);

    outputMatrix(m);

    freeMemMatrix(m);
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }

    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols)) {
            return false;
        }
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++) {
        count += hasAllNonDescendingRows(ms[i]);
    }

    return count;
}

void solvingProblemNumberThirteen() {
    int row, col, n;
    scanf("%d %d %d", &row, &col, &n);

    matrix *ms = getMemArrayOfMatrices(n, row, col);
    inputMatrices(ms, n);

    printf("%d\n", countNonDescendingRowsMatrices(ms, n));
    //outputMatrices(ms, n);

    freeMemMatrices(ms, n);
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            count += 1;
        }
    }

    return count;
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols) {
            count += 1;
        }
    }

    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxCount = 0;
    int *a = (int *)malloc(nMatrix * sizeof(int));

    for (int i = 0; i < nMatrix; i++) {
        int currentCount = countZeroRows(ms[i]);

        a[i] = currentCount;
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
    }

    for (int i = 0; i < nMatrix; i++) {
        if (maxCount == a[i]) {
            outputMatrix(ms[i]);
            printf("\n");
        }
    }

    free(a);
}

void solvingProblemNumberFourteen() {
    int row, col, n;
    scanf("%d %d %d", &row, &col, &n);

    matrix *ms = getMemArrayOfMatrices(n, row, col);
    inputMatrices(ms, n);

    printMatrixWithMaxZeroRows(ms, n);

    freeMemMatrices(ms, n);
}

double absD(double a) {
    return a > 0 ? a: -a;
}

double getMaxAbsoluteValue(matrixD m) {
    double maxAbsoluteValue = m.values[0][0];
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (maxAbsoluteValue < absD(m.values[i][j])) {
                maxAbsoluteValue = m.values[i][j];
            }
        }
    }

    return maxAbsoluteValue;
}

void printMatrixDWithMinMaxValue(matrixD *ms, int nMatrix) {
    double eps = 0.00001;
    double minStandard = getMaxAbsoluteValue(ms[0]);
    double *a = (double *)malloc(nMatrix * sizeof(double ));

    for (int i = 1; i < nMatrix; i++) {
        double currentStandard = getMaxAbsoluteValue(ms[i]);

        a[i] = currentStandard;
        if (currentStandard < minStandard) {
            minStandard = currentStandard;
        }
    }

    for (int i = 0; i < nMatrix; i++) {
        if (absD(minStandard - a[i]) < eps) {
            outputMatrixD(ms[i]);
            printf("\n");
        }
    }

    free(a);
}

void solvingProblemNumberFifteen() {
    int row, col, n;
    scanf("%d %d %d", &row, &col, &n);

    matrixD *ms = getMemArrayOfMatricesD(n, row, col);
    inputMatricesD(ms, n);

    printMatrixDWithMinMaxValue(ms, n);

    freeMemMatricesD(ms, n);
}

int min2(int a, int b) {
    return a < b ? a : b;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

int getNSpecialElement2(matrix m) {
    matrix maxMatrix = getMemMatrix(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        maxMatrix.values[i][0] = m.values[i][0];
        for (int j = 1; j < m.nCols; j++) {
            maxMatrix.values[i][j] = max2(maxMatrix.values[i][j - 1], m.values[i][j]);
        }
    }

    matrix minMatrix = getMemMatrix(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        minMatrix.values[i][m.nCols - 1] = m.values[i][m.nCols - 1];
        for (int j = m.nCols - 2; j >= 0; j--) {
            minMatrix.values[i][j] = min2(minMatrix.values[i][j + 1], m.values[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 1; j < m.nCols - 1; j++) {
            if (maxMatrix.values[i][j - 1] < m.values[i][j] && minMatrix.values[i][j + 1] > m.values[i][j]) {
                count += 1;
            }
        }

        if (m.nCols > 1 && m.values[i][0] < minMatrix.values[i][1]) {
            count += 1;
        }
        if (m.nCols > 1 && maxMatrix.values[i][m.nCols - 2] < m.values[i][m.nCols - 1]) {
            count += 1;
        }
    }

    freeMemMatrix(minMatrix);
    freeMemMatrix(maxMatrix);

    return count;
}

void solvingProblemNumberSixteen() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    printf("%d", getNSpecialElement2(m));

    freeMemMatrix(m);
}

double getScalarProduct(int *a, int *b, int n) {
    double scalarProduct = 0;
    for (int i = 0; i < n; i++) {
        scalarProduct += a[i] * b[i];
    }

    return scalarProduct;
}

double getVectorLength(int *a, int n) {
    double vectorLength = 0;
    for (int i = 0; i < n; i++) {
        vectorLength += a[i] * a[i];
    }

    return sqrt(vectorLength);
}

double getCosine(int *a, int *b, int n) {
    return getScalarProduct(a, b, n) / getVectorLength(a, n) / getVectorLength(b, n);
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int index = 0;
    double maxAngle = absD(getCosine(m.values[0], b, m.nCols));
    for (int i = 1; i < m.nRows; i++) {
        double currentAngle = absD(getCosine(m.values[i], b, m.nCols));
        if (currentAngle < maxAngle) {
            maxAngle = currentAngle;
            index = i;
        }
    }

    return index;
}

void solvingProblemNumberSeventeen() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix b = getMemMatrix(1, col);
    inputMatrix(b);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    printf("%d", getVectorIndexWithMaxAngle(m, b.values[0]));

    freeMemMatrix(m);
    freeMemMatrix(b);
}

long long getScalarProductIntVector(const int *a, const int *b, int n) {
    long long scalarProduct = 0;
    for (int i = 0; i < n; i++) {
        scalarProduct += a[i] * b[i];
    }

    return scalarProduct;
}

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    int *a = (int *)malloc(m.nRows * sizeof(int));
    for (int k = 0; k < m.nRows; k++) {
        a[k] = m.values[k][j];
    }

    long long scalarProduct = getScalarProductIntVector(m.values[i], a, m.nRows);

    free(a);

    return scalarProduct;
}

long long getSpecialScalarProduct(matrix m) {
    position maxValuePos = getMaxValuePos(m);
    position minValuePos = getMinValuePos(m);

    return getScalarProductRowAndCol(m, maxValuePos.rowIndex, minValuePos.colIndex);
}

void solvingProblemNumberEighteen() {
    int row, col;
    scanf("%d %d", &row, &col);

    matrix m = getMemMatrix(row, col);
    inputMatrix(m);

    printf("%lld", getSpecialScalarProduct(m));

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
    //solvingProblemNumberNine();
    //solvingProblemNumberTen();
    //solvingProblemNumberEleven();
    //solvingProblemNumberTwelve();
    //solvingProblemNumberThirteen();
    //solvingProblemNumberFourteen();
    //solvingProblemNumberFifteen();
    solvingProblemNumberSixteen();
    //solvingProblemNumberSeventeen();
    //solvingProblemNumberEighteen();

    return 0;
}
