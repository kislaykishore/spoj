#include<cstdio>
#include<cstring>
#include<utility>
using namespace std;
pair<long long, long long> dp[102][102];
inline int toDigit(char c) {
    return c - '0';
}

pair<long long, long long> compute(char* str, int start, int end) {
    pair<long long, long long> pr;
    if(dp[start][end].first != -1) {
        return dp[start][end];
    }
    if(start == end) {
        pr.first = pr.second = toDigit(str[start]);
        dp[start][end] = pr;
        return pr;
    }

    long long maxVal = 0;
    long long minVal = -1;
    for(int i=start+1;i<end;i+=2) {
        pair<long long, long long> lhs = compute(str, start, i - 1);
        pair<long long, long long> rhs = compute(str, i + 1, end);
        long long candidateValMax, candidateValMin;
        if(str[i] == '*') {
            candidateValMax = lhs.first * rhs.first;
            candidateValMin = lhs.second * rhs.second;
        } else if(str[i] == '+') {
            candidateValMax = lhs.first + rhs.first;
            candidateValMin = lhs.second + rhs.second;
        }
        if(minVal == -1) {
            minVal = candidateValMin;
        } else {
            minVal = candidateValMin < minVal?candidateValMin:minVal;
        }
            
        maxVal = candidateValMax > maxVal?candidateValMax:maxVal;
    }
    pr.first = maxVal;
    pr.second = minVal;
    dp[start][end] = pr;
    return dp[start][end];
}
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        char str[101];
        scanf("%s", str);
        memset(dp, -1, sizeof(dp));
        pair<long long, long long> val = compute(str, 0, strlen(str) - 1);
        printf("%lld %lld\n", val.first, val.second);
    }
}
