#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    while(true) {
        int n;
        scanf("%d", &n);
        if(n == 0) {
            return 0;
        }
        int *c = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", c + i);
        }
        int *p = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", p + i);
        }
        sort(c, c+n);
        sort(p, p+n);
        long long sum = 0;
        for(int i=0;i<n;++i) {
            sum += c[i] * p[n-i-1];
        }
        printf("%lld\n", sum);
        delete [] c;
        delete [] p;
    }
}
