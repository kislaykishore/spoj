#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int computeMinCost(char *str);
int computeMinCost(char* str, int lIndex, int rIndex, int** array);
int main() {
    char str[2050];
    int test = 0;
    while(true) {
        ++test;
        scanf("%s", str);
        if(str[0] == '-') {
            break;
        }
        int len = strlen(str);
        int cost = computeMinCost(str);
        printf("%d. %d\n", test, cost);
    }
    return 0;
}

int computeMinCost(char *str) {
    stack<char> stk;
    int cost = 0;
    for(int i=0;i<strlen(str);++i) {
        char c=str[i];
        if(c == '{') {
            stk.push('{');
        } else {
            if(stk.empty()) {
                stk.push('{');
                cost++;
            } else {
                stk.pop();
            }
       }

    }
    return cost + stk.size()/2;
}
