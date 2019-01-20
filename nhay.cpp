#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
void computeLPS(const char* pat, int size, int *lps);
void findOccurrences(const char* pat, int *lps, int size);
int main() {
    int n;
    char c;
    while(cin>>n) {
        char *pat = new char[n+1];
        scanf("%s", pat);
        scanf("%c", &c);
        int len = n;
        int *lps = new int[len];
        computeLPS(pat, len, lps);
        // after lps computation, we need to match strings
        findOccurrences(pat, lps, len);
        printf("\n");
    }

}

void findOccurrences(const char* pat, int *lps, int size) {
    int pos=0;
    int j = 0;
    char c;
    bool readNext = true;
    while(true) {
        if(readNext) {
            scanf("%c", &c);
            j++;
        }
        if(c == '\n') {
            return;
        } else {
            if(c == pat[pos]) {
                pos++;
                readNext = true;
            } else {
                if(pos == 0) {
                    readNext = true;
                } else {
                    pos = lps[pos-1];
                    readNext = false;
                }
            }
            if(pos == size) {
                // Found a match
                printf("%d\n", j - size);
                pos = lps[pos -1];
            }
 
        }
    }
}
void computeLPS(const char* pat, int size, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i<size) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len == 0) {
                i++;
            } else { 
                len = lps[len - 1];
            }
        }
    }
}
