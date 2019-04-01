#include<cstdio>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int w, b;
        scanf("%d %d", &w, &b);
        double prob = b & 1?1:0;
        printf("%.6f\n", prob);
    }
}
