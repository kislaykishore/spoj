#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *diffArray = new int[n + 1];
    memset(diffArray, '\0', sizeof(int) * (n+1));

    while(k--) {
        int a, b;
        scanf("%d %d", &a, &b);
        diffArray[a - 1] += 1;
        diffArray[b] -= 1;
    }

    int* array = new int[n];
    array[0] = diffArray[0];
    for(int i=1;i<n;++i) {
        array[i] = diffArray[i] + array[i-1];
    }
    delete [] diffArray;
    sort(array, array + n);
    printf("%d\n", array[n/2]);
    delete [] array;
}
