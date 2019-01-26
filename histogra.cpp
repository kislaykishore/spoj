#include<cstdio>
#include<stack>

using namespace std;
int main() {
    while(true) {
        int n;
        long long maxArea = 0;
        scanf("%d", &n);
        if(n == 0) {
            break;
        }
        bool readNext = true;
        stack<long long> stk;
        stack<int> idx;
        int i;
        int height;
        for(i=0;i<n;) {
            if(readNext) {
                scanf("%d", &height);
                readNext = false;
            }
            if(stk.empty() || stk.top() <= height) {
                stk.push(height);
                idx.push(i);
                readNext = true;
                ++i;
            } else {
                long long poppedHeight = stk.top();
                int poppedIdx = idx.top();
                stk.pop();
                idx.pop();
                // right area
                long long area = poppedHeight * (i - poppedIdx);
                // left area
                int length;
                if(!idx.empty()) {
                    length = poppedIdx - idx.top() - 1;
                } else {
                    length = poppedIdx;
                }
                long long leftArea = poppedHeight * length;
                area += leftArea;
                if(area > maxArea) {
                    maxArea = area;
                }
            }
        }
        while(!stk.empty()) {
            long long popHeight = stk.top();
            int poppedIdx = idx.top();
            stk.pop();
            idx.pop();
            long long ar = popHeight * (i-poppedIdx);
            int length;
            if(!idx.empty()) {
                length = poppedIdx - idx.top() - 1;
            } else {
                length = poppedIdx;
            }
            long long lAr = popHeight * length;
            ar += lAr;
            if(ar > maxArea) {
                maxArea = ar;
            }
        }
        printf("%lld\n", maxArea);
    }
}
