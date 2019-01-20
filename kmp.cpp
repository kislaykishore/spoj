#include<cstdio>
#include<cstring>
using namespace std;
void computeLPSArray(char* pat, int M, int* lps);
int main() {
    char* pattern = "abcdabc";
    const char* text = "abcxabcdabxabcdabcdabcyabc";

    int len = strlen(pattern);
    int* lps = new int[len];
    computeLPSArray(pattern, len, lps);
    for(int i=0;i<len;++i)
        printf("%d ", lps[i]);
    printf("\n");
}
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
