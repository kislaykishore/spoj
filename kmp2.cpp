#include<cstdio>
#include<cstring>
using namespace std;
void computeLPS(const char* pattern, int size, int *lps);
int main() {
    const char* pattern = "AAACAAAA";
    int len = strlen(pattern);
    int *lps = new int[len];
    computeLPS(pattern, len, lps);
    for(int i=0;i<len;++i) {
        printf("%d ", lps[i]);
    }
    printf("\n");
}

void computeLPS(const char* pattern, int size, int *lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < size) {
        if(pattern[i] == pattern[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                i++;
                lps[i] = 0;
            }
        }
    }
}
