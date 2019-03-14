#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        char str[2001];
        scanf("%s", str);
        int len = strlen(str);
        vector<int> prev;
        vector<int> post;
        int prevCount = 0;
        for(int i=0;i<len;++i) {
            if(str[i] == 'K') {
                prevCount++;
            } else if(str[i] == 'E') {
                prev.push_back(prevCount);
            }
        }
        int postCount = 0;
        for(int i=len-1;i>=0;--i) {
            if(str[i] == 'K') {
                postCount++;
            } else if(str[i] == 'E') {
                post.push_back(postCount);
            }
        }
        long long sum = 0;
        for(int i=0;i<prev.size();++i) {
            sum += prev[i] * post[prev.size() - i - 1];
        }
        printf("%lld\n", sum);
    }
}
