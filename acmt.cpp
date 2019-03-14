#include<cstdio>
int max(int a, int b) {
    return a > b?a:b;
}
int min(int a, int b) {
    return a<b?a:b;
}
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int e, n;
        scanf("%d %d", &e, &n);
        int maxVal = 0;
        for(int i=0;i<=e;i += 2) {
            int val = i/2;
            int team1 = 0;
            if(val <= n) {
                team1 = val;
                int team2 = min((e - i), (n - val)/2);
                maxVal = max(team1 + team2, maxVal);
            } else {
                break;
            }
        }
        printf("%d\n", maxVal);
    }
}
