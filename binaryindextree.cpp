#include<cstdio>
void update(int *bitArray, int index, int len, int val) {
    index++;
    while(index <= len) {
        bitArray[index] += val;
        index += index & (-index);
    }
}
void constructBIT(int *array, int len, int* bitArray) {
    for(int i=0;i<len+1;++i) {
        bitArray[i] = 0;
    }
    for(int i=0;i<len;++i) { 
        update(bitArray, i, len, array[i]);
    }
}
int main() {
    int array[] = { 2,1,1,3,2,3,4,5,6,7,8,9 };
    int len = sizeof(array)/sizeof(int);
    int *bitArray = new int[len + 1];
    constructBIT(array, len, bitArray);
    for(int i=1;i<=len;++i) {
        printf("%d ", bitArray[i]);
    }
    printf("\n");
}
