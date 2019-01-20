#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        int *array = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", array + i);
        }
        int base = n;
        long long* hashArray = new long long[n];
        map<long long, int>indexMap;
        for(int i=0;i<n;++i) {
            long long num = 0;
            int x = n;
            for(int j=0;j<n;++j) {
                if(i == j && j != (n-1)) {
                    j++;
                } else {
                    num = (num * base) + array[j];
                    x--;
                }
            }
            while(x--) {
                num *= base;
            }
            indexMap[num] = array[i];
            hashArray[array[i]] = num;
        }
        sort(hashArray, hashArray + n);
        for(int i=0;i<n;++i) {
            array[indexMap[hashArray[i]]] = i;
        }
        for(int i=0;i < n; ++i) {
            printf("%d", array[i]);
            if(i != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
        delete [] array;
        delete [] hashArray;
    }
}
