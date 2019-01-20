#include<cstdio>
int findPos(int *array, int lIndex, int rIndex, int val) {
    if(lIndex > rIndex) {
        return lIndex;
    }
    if(lIndex == rIndex) {
        if(val >= array[lIndex]) {
            return lIndex + 1;
        } else {
            return lIndex;
        }
    }

    int mid = (lIndex + rIndex)/2;
    if(val >= array[mid]) {
        return findPos(array, mid + 1, rIndex, val);
    } else {
        return findPos(array, lIndex, mid - 1, val);
    }
}
long long computeInversionsSorted(int *array, int lIndex, int mid, int rIndex) {
    long long inv = 0;
    for(int i=mid + 1;i<=rIndex;++i) {
        int pos = findPos(array, lIndex, mid, array[i]);
        inv += mid - pos + 1;
    }
    return inv;
}
void mergeArrays(int* array, int lIndex, int mid, int rIndex) {
    int p = lIndex;
    int q = mid + 1;
    int *mergeArray = new int[rIndex - lIndex + 1];
    int index = 0;
    while(p<=mid && q <= rIndex) {
        if(array[p] < array[q]) {
            mergeArray[index] = array[p];
            p++;
        } else {
            mergeArray[index] = array[q];
            q++;
        }
        index++;
    }
    while(p<=mid) {
        mergeArray[index] = array[p];
        p++;
        index++;
    }
    while(q <= rIndex) {
        mergeArray[index] = array[q];
        q++;
        index++;
    }
    for(int i=0;i<(rIndex - lIndex + 1);++i) {
        array[lIndex + i] = mergeArray[i];
    }
    delete [] mergeArray;
}

long long countInversions(int *array, int lIndex, int rIndex) {
    if(rIndex == lIndex) {
        return 0;
    }
    int mid = (lIndex + rIndex)/2;
    long long inv = countInversions(array, lIndex, mid);
    inv += countInversions(array, mid + 1, rIndex);

    // compute the inversions for the two halves
    long long val = computeInversionsSorted(array, lIndex, mid, rIndex);
    mergeArrays(array, lIndex, mid, rIndex);
    return val + inv;
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        int *array = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", array + i);
        }

        long long inversions = countInversions(array, 0, n -1);
        printf("%lld\n", inversions);
        delete [] array;
    }
}
