#include<cstdio>
#include<cstring>
int main() {
    int cas = 0;
    while(true) {
        cas++;
        int n;
        scanf("%d", &n);
        if(n == 0) {
            return 0;
        }
        int * netCredit = new int[n];
        int totalSum = 0;
        memset(netCredit, 0, sizeof(int) * n);
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                int a;
                scanf("%d", &a);
                netCredit[i] += a; 
                netCredit[j] -= a;
                totalSum += a;
            }
        }
        int credit = 0;
        for(int i=0;i<n;++i) {
            if(netCredit[i] > 0) {
                credit += netCredit[i];
            }
        }
        delete [] netCredit;
        printf("%d. %d %d\n", cas, totalSum, credit);
    }
}
