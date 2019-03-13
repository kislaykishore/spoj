#include<cstdio>
#include<cstring>
struct Bond {
    int amount;
    int interest;
};
int dp[50000];
int computeMaxInterest(int amount, Bond* bonds, int d) {
    if(dp[amount] != -1) {
        return dp[amount];
    }
    int maxVal = 0;
    for(int i=0;i<d;++i) {
        Bond& bnd = bonds[i];
        int bndAmt = bnd.amount / 1000;
        if(amount >= bndAmt) {
            int tmpVal = computeMaxInterest(amount - bndAmt, bonds, d) + bnd.interest;
            if(tmpVal > maxVal) {
                maxVal = tmpVal;
            }
        }
    }
    dp[amount] = maxVal;
    return maxVal;
}
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int amount, years;
        scanf("%d %d", &amount, &years);
        int d;
        scanf("%d", &d);
        Bond* bonds = new Bond[d];
        for(int i=0;i<d;++i) {
            scanf("%d %d", &bonds[i].amount, &bonds[i].interest);
        }
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<years;++i) {
            int val = amount / 1000;
            amount += computeMaxInterest(val, bonds, d);
        }
        delete [] bonds;
        printf("%d\n", amount);
        
    }
}
