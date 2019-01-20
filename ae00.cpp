#include<cstdio>
#include<cmath>
#include<list>

int main() {
    // We have to compute the total number
    // of factors for a given length

    int n;
    scanf("%d", &n);
    int *factorCount = new int[n + 1];
    factorCount[0] = 0;
    factorCount[1] = 1;
    for(int i=2;i<=n;++i) {
        factorCount[i] = 1;
    }
    int x = sqrt(n+1);
    for(int i=2;i<=x;++i) {
        for(int j=i;;++j) {
            int val = i * j;
            if(val > n) {
                break;
            }
            factorCount[val] += 1;
        }
    }
    int sum = 0;
    for(int i=1;i<=n;++i) {
        sum += factorCount[i];
    }
    printf("%d\n", sum);
    delete [] factorCount;
    return 0; 
}
