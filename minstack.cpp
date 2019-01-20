#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
struct Pair {
    int num;
    int indicator;
};

void push(stack<Pair>& stk, int num) {
    if(stk.empty()) {
        Pair p;
        p.num = num;
        p.indicator = 1;
        stk.push(p);
    }
    Pair minima = stk.top();
    Pair x;
    x.num = num;
    x.indicator = 0;
    if(minima.num <= num) {
        stk.pop();
        stk.push(x);
        stk.push(minima);
    } else {
        Pair z;
        z.num = num;
        z.indicator = 1;
        stk.push(x);
        stk.push(z);
    }
}

void pop(stack<Pair>& stk) {
    // First element is a minima
    if(stk.empty()) {
        printf("EMPTY\n");
        return;
    }
    Pair minima = stk.top();
    stk.pop();
    Pair elem = stk.top();
    stk.pop();
    if(!stk.empty()) {
        Pair val = stk.top();
        if(val.indicator == 0) {
            stk.push(minima);
        }
    }
//    printf("%d\n", elem.num);
}

void min(stack<Pair>& stk) {
    if(stk.empty()) {
        printf("EMPTY\n");
        return;
    }
    Pair minima= stk.top();
    printf("%d\n", minima.num);
}
int main() {
    int n;
    scanf("%d", &n);
    stack<Pair> stk;
    char op[20];
    while(n--) {
        scanf("%s", op);
        if(strcmp(op, "PUSH") == 0) {
            int num;
            scanf("%d", &num);
            push(stk, num);
        } else if(strcmp(op, "POP") == 0) {
            pop(stk);
        } else if(strcmp(op, "MIN") == 0) {
            min(stk);
        }
    }
}
