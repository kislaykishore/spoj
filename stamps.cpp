#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int countFriends(int val, int idx, int num) {
    if(val * idx <= num) {
        return val;
    } else {
        int rem = num % idx;
        int quo = num/idx;
        if(rem == 0) {
            return quo;
        } else {
            return quo + 1;
        }
    }
}
int main() {
    int tests;
    scanf("%d", &tests);
    int array[10001];
    for(int k=1;k<=tests;++k) {
        memset(array, 0, sizeof(array));
        int num, fNum;
        scanf("%d %d", &num, &fNum);
        for(int i=0;i<fNum;++i) {
            int x;
            scanf("%d", &x);
            array[x]++;
        }
        int numFriends = 0;
        for(int i=10000;i>=0 && num > 0;--i) {
            int val = array[i];
            if(val != 0) {
                int inc = countFriends(val, i, num);
                num -= inc * i;
                numFriends += inc;
            }
        }
        printf("Scenario #%d:\n", k);
        if(num <= 0) {
            printf("%d\n\n", numFriends);
        } else {
            printf("impossible\n\n");
        }

        
    }
}

