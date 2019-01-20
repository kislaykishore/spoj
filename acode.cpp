#include<cstdio>
#include<cstring>
using namespace std;
long long compute(long long* dpArray, const char* array, int len);
long long compute(long long* dpArray, const char* array, int len, int index);
int main() {
    char array[5001];
    while(true) {
        scanf("%s", array);
        int len = strlen(array);
        if(strcmp(array, "0") == 0) {
            return 0;
        }
        long long* dpArray = new long long[len + 1];
        for(int i=0;i<len + 1;++i){
            dpArray[i] = -1;
        }

        dpArray[0] = 1;
        long long val = compute(dpArray, array, len);
        printf("%lld\n", val);
        
        
    }
}
long long compute(long long* dpArray, const char* array, int len) {
    return compute(dpArray, array, len, len);
}

long long compute(long long* dpArray, const char* array, int len, int index) {
    if(dpArray[index] != -1) {
        return dpArray[index];
    }
    char val = array[index - 1];
    long long count = 0;
    // single character case
    if(val > '0' && val <= '9') {
        count = compute(dpArray, array, len, index - 1);
    }
    int num = 0;
    if(index > 1 && array[index-2] != '0') {
        num += (array[index - 1] - '0');
        num += 10 * (array[index - 2] - '0');
        if(num > 0 && num <= 26) {
            count += compute(dpArray, array, len, index - 2);
        }

    }
    dpArray[index] = count;
    return dpArray[index];
}
