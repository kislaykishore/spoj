#include<cstdio>
#include<cstring>
struct Info {
    int fee;
    int fun;
};

Info computeMaxFun(Info** dp, Info* infos, int budget, int n) {
    int maxFun = -1;
    for(int i=0;i<=budget;++i) {
        dp[0][i].fee = dp[0][i].fun = 0;
    }

    for(int i=1;i<=n;++i) {
        for(int j=0;j<=budget;++j) {
            Info* maxVal;
            // case 1: i-th party is not included
            Info dt1 = dp[i-1][j];
            maxVal = &dt1;
            // case 2: i-th party is included
            if(j >= infos[i-1].fee) {
                Info dt2 = dp[i-1][j-infos[i-1].fee];
                dt2.fee += infos[i-1].fee;
                dt2.fun += infos[i-1].fun;
                if(dt2.fun > dt1.fun || (dt2.fun == dt1.fun && dt2.fee < dt1.fee)) {
                    maxVal = &dt2;
                }
            }
            dp[i][j] = *maxVal;
        }
    }
    return dp[n][budget];
}
int main() {
    while(true) {
        int budget, n;
        scanf("%d %d", &budget, &n);
        if(budget == 0 && n == 0) {
            return 0;
        }
        Info* infos = new Info[n];
        for(int i=0;i<n;++i) {
            scanf("%d %d", &infos[i].fee, &infos[i].fun);
        }
        Info** dp = new Info*[n + 1];
        for(int i=0;i<=n;++i) {
            dp[i] = new Info[budget+1];
        }
        Info dt = computeMaxFun(dp, infos, budget, n);
        delete [] infos;
        for(int i=0;i<=n;++i) {
            delete [] dp[i];
        }
        delete [] dp;
        printf("%d %d\n", dt.fee, dt.fun);
    }
}
