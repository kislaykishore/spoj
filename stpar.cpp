#include<cstdio>
#include<stack>
using namespace std;
int main() {
    while(true) {
        int n;
        scanf("%d", &n);
        if(n== 0) {
            return 0;
        }
        n++;
        int maxValue = 0;
        bool possible = true;
        stack<int> stk;
        while(n--) {
            int num = 1001;
            if(n != 0) {
                scanf("%d", &num);
            }
            if(stk.empty() || stk.top() > num) {
                stk.push(num);
            } else {
                while(!stk.empty() && stk.top() < num) {
                    int tp = stk.top();
                    if(tp < maxValue) {
                        possible = false;
                    } else {
                        maxValue = tp;
                    }
                    stk.pop();
                }
                stk.push(num);
            }
        }
        printf("%s\n", possible?"yes":"no");
    }
}
