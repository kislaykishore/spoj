#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
// Implement BIT
void update(int* bit, int n, int idx, int val) {
    for(;idx <= n;idx += idx & (-idx)) {
        bit[idx] += val;
    }
}

long long querySum(int* bit, int idx) {
    long long sum = 0;
    for(;idx > 0;idx -= idx & (-idx)) {
        sum += bit[idx];
    }
    return sum;
}
long long countInversions(int* array, int n) {
    int maxVal = array[0];
    for(int i=1;i<n;++i) {
        if(array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    int* bit = new int[n + 1];
    memset(bit, '\0', sizeof(int) * (n + 1));
    long long sum = 0;
    for(int i=n-1;i>=0;--i) {
        int idx = array[i] + 1;
        update(bit, n, idx, 1);
        sum += querySum(bit, idx - 1);
    }

    delete [] bit;
    return sum;
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        map<string, int> mp;
        scanf("%d\n", &n);
        string* strArray = new string[n];
        for(int i=0;i<n;++i) {
            char str[21];
            scanf("%s", str);
            string st(str);
            strArray[i] = st;
        }

        for(int i=0;i<n;++i) {
            char str[21];
            scanf("%s", str);
            string st(str);
            mp[st] = i;
       }

        int *array = new int[n];
        for(int i=0;i<n;++i) {
            array[i] = mp[strArray[i]];
        }
        delete [] strArray;

        long long inversions = countInversions(array, n);
        printf("%lld\n", inversions);
        delete [] array;
    }
}
