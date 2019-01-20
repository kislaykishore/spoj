#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct Coin {
    int value;
    int weight;
    
    bool operator < (const Coin& other) const {
        return value < other.value;
    }

};
int computeMinValue(int weight, vector<Coin>& coins, int* dp);
int main() {
    int test;
    scanf("%d", &test);
    int dp[10001];
    while(test--) {
        for(int i=1;i<sizeof(dp)/sizeof(int);++i) {
            dp[i] = (char)(-1);
        }
        dp[0] = 0;
        int e,f;
        scanf("%d %d", &e, &f);
        int weight = f - e;
        int n;
        vector<Coin> coins;
        scanf("%d", &n);
        coins.reserve(n);
        for(int i=0;i<n;++i) {
            int v, w;
            scanf("%d %d", &v, &w);
            Coin c;
            c.value = v;
            c.weight = w;
            coins.push_back(c);
        }
        // Once the coins are sorted, we need to construct the dp

        int val = computeMinValue(weight, coins, dp);
        if(val == -2) {
            printf("This is impossible.\n");
        } else {
            printf("The minimum amount of money in the piggy-bank is %d.\n", val);
        }
    }
}
int computeMinValue(int weight, vector<Coin>& coins, int* dp) {
    if(dp[weight] != -1) {
        return dp[weight];
    }
    for(int i=0;i<coins.size();++i) {
        Coin* c = &coins[i];
        int adjustedWeight = weight - c->weight;
        int minCost;
        if(adjustedWeight >= 0) {
            int val = computeMinValue(adjustedWeight, coins, dp);
            if(val == -2) {
                minCost = -2;
            } else {
                minCost = val + c->value;
            }
        } else {
            continue;
        }
        if(minCost != -2 && (dp[weight] == -1 || minCost < dp[weight])) {
            dp[weight] = minCost;
        }
    }
    if(dp[weight] == -1) {
        dp[weight] = -2;
    }
    return dp[weight];
}
