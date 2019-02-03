#include<cstdio>
struct PartyInfo {
    int fee;
    int fun;
};

PartyInfo dpCompute(PartyInfo** partyInfo, PartyInfo* parties, int n, int budget) {
    for(int i=1;i<=n;++i) {
        PartyInfo party = parties[i-1];
        for(int j=0;j<=budget;++j) {
            // case 1: i-th element is not chosen
            PartyInfo maxInfo = partyInfo[i-1][j];
            // case 1: i-th element is chosen
            // which can only happen if j >= party.fee
            if(j >= party.fee) {
                PartyInfo pInfo = partyInfo[i-1][j-party.fee];
                pInfo.fun += party.fun;
                pInfo.fee = j;
                if(pInfo.fun > maxInfo.fun) {
                    maxInfo= pInfo;
                }
            }
            partyInfo[i][j] = maxInfo;
        }
    }
    return partyInfo[n][budget];

}


int main() {
    while(true) {
        int budget, n;
        scanf("%d %d", &budget, &n);
        if(budget == 0 && n == 0) {
            return 0;
        }
        PartyInfo* parties = new PartyInfo[n];
        for(int i=0;i<n;++i) {
            scanf("%d %d", &parties[i].fee, &parties[i].fun);
        }
        PartyInfo** dp = new PartyInfo*[n+1];
        for(int i=0;i<=n;++i) {
            dp[i] = new PartyInfo[budget+1];
        }
        for(int i=0;i<=budget;++i) {
            dp[0][i].fee = 0;
            dp[0][i].fun = 0;
        }
        PartyInfo val = dpCompute(dp, parties, n, budget);
        for(int i=budget-1;i>=0;--i) {
            if(dp[n][i].fun == val.fun) {
                val = dp[n][i];
            } else {
                break;
            }
        }
        for(int i=0;i<=n;++i) {
            delete [] dp[i];
        }
        delete [] dp;
        printf("%d %d\n", val.fee, val.fun);
    }    
}
