#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
bool verify(int val, char* str, int len) {
    for(int i=0;str[i];i+= val) {
        for(int j=0;j<val;++j) {
            if(str[i + j] != str[j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    vector<int>* factors = new vector<int>[100001];
    int sqr = sqrt(100000);
    for(int i=1;i<=sqr;++i) {
        for(int j=i;;j++) {
            int prod = i * j;
            if(prod > 100000) {
                break;
            }
            factors[prod].push_back(i);
            factors[prod].push_back(j);
        }
    }

    while(true) {
        char str[100001];
        scanf("%s", str);
        if(str[0] == '*') {
            delete [] factors;
            return 0;
        }
        int len = strlen(str);
        // for all the factors verify
        vector<int>& factorVals = factors[len];
        sort(factorVals.begin(), factorVals.end());
        int maxLen;
        for(int i=0;i<factorVals.size();++i) {
            bool isValid = verify(factorVals[i], str, len);
            if(isValid) {
                maxLen = len / factorVals[i];
                break;
            }
        }
        printf("%d\n", maxLen);

    }
}
