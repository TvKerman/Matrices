#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"

int sumArray(int *a, int sizeA) {
    int sum = 0;
    for (int i = 0; i < sizeA; i++) {
        sum += a[i];
    }
    return sum;
}


int main() {
    //matrix m = getMemMatrix(3, 4);
    //inputMatrix(m);
    //insertionSortColsMatrixByColCriteria(m, sumArray);
    //outputMatrix(m);
    //insertionSortRowsMatrixByRowCriteria(m, sumArray);
    //outputMatrix(m);
    //freeMemMatrix(m);
    return 0;
}
