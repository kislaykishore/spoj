#include<cstdio>
int gcd(int a, int b) {
    int rem = a % b;
    if(rem == 0) {
        return b;
    } else {
        return gcd(b, rem);
    }
}
void populateArray(long long* array, int n, int maxIndex) {
    for(int i=maxIndex+1;i<=n;++i) {
        long long val = array[i - 1];
        for(int j=1;j<i;++j) {
            val += gcd(i, j);
        }
        array[i] = val;
    }
}
int main() {
    long long array[1000001];
    array[0] = array[1] = 0;
    int maxIndex = 1;
    while(true) {
        int n;
        scanf("%d", &n);
        if(n == 0) {
            return 0;
        }
        if(n > maxIndex) {
            populateArray(array, n, maxIndex);
            maxIndex = n;
        }
        printf("%lld\n", array[n]);
        
    }
}
