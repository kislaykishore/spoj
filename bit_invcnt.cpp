#include<cstdio>
// Implement BIT
void updateNode(int* bitArray, int index, int len, int val) {
    if(index >= len) {
        return;
    }
    bitArray[index] += val;
    int newIndex = index + (index & (-index));
    updateNode(bitArray, newIndex, len, val);
}

long long querySum(int* bitArray, int index) {
    if(index == 0) {
        return 0;
    }
    int newIndex = index - (index & (-index));
    return bitArray[index] + querySum(bitArray, newIndex);
}

long long countInversions(int* array, int n) {
    int maxElem = array[0];
    for(int i=0;i<n;++i) {
        if(array[i] > maxElem) {
            maxElem = array[i];
        }
    }
    int len = maxElem + 1;
    int *bitArray = new int[len];
    for(int i=0;i<len;++i) {
        bitArray[i] = 0;
    }
    long long inversions = 0;
    for(int i=n-1;i>=0;--i) {
        updateNode(bitArray, array[i], len, 1);
        inversions += querySum(bitArray, array[i] - 1);
    }
    return inversions;
    
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

        long long inversions = countInversions(array, n);
        printf("%lld\n", inversions);
        delete [] array;
    }
}
