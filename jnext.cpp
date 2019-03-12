#include<cstdio>
#include<algorithm>
using namespace std;
void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int tests;
    scanf("%d", &tests);
    int array[1000001];
    while(tests--) {
        int n;
        scanf("%d", &n);
        bool nonDecreasing = false;
        for(int i=0;i<n;++i) {
            scanf("%d", array + i);
            if(!nonDecreasing && i >= 1 && array[i] > array[i-1]) {
                nonDecreasing = true;
            }
                
        }
        if(!nonDecreasing) {
            printf("-1\n");
            continue;
        }
        for(int i=n-1;i>=0;--i) {
            int minVal = array[i];
            int minIndex = i;
            if(array[i - 1] < array[i]) {
                // we need to change here
                // find the least number just greater than array[i-1]
                for(int j=i+1;j<n;++j) {
                    if(array[j] > array[i-1] && array[j] < minVal) {
                        minVal = array[j];
                        minIndex = j;
                    }
                }
                swap(array[i-1], array[minIndex]);
                sort(array + i, array + n);
                break;
            }
        }
        for(int i=0;i<n;++i) {
            printf("%d", array[i]);
        }
        printf("\n");
    }
}
