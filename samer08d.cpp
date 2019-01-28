#include<cstdio>
#include<cstring>
#include<map>
#include<utility>
using namespace std;
int lcs(char* str1, int idx1, char* str2, int idx2, int k, int** dpArray) {
    if(idx1 < 0 || idx2 < 0) {
        return 0;
    }
    if(dpArray[idx1][idx2] != -1) {
        return dpArray[idx1][idx2];
    }
    if(idx1 + 1 < k || idx2 + 1 < k) {
        return 0;
    }
    else {
        bool isMatch = true;
        int i;
        for(i=0;(idx1 - i) >= 0 && (idx2 - i) >=0;++i) {
            if(str1[idx1 - i] != str2[idx2 - i]) {
                break;
            }
        }
        
        isMatch = i >= k;
        if(isMatch) {
            int lMax = 0;
            for(int a=k;a<=i;++a) {
                int l = a + lcs(str1, idx1 - a, str2, idx2 - i, k, dpArray);
                lMax = l > lMax?l:lMax;
            }
            int l2 = lcs(str1, idx1 - 1, str2, idx2, k, dpArray);
            int l3 = lcs(str1, idx1, str2, idx2 - 1, k, dpArray);
            dpArray[idx1][idx2] = max(lMax, max(l2, l3));
            return dpArray[idx1][idx2];
        } else {
            int val = lcs(str1, idx1 - 1, str2, idx2, k, dpArray);
            int val2 = lcs(str1, idx1, str2, idx2 - 1, k, dpArray);
            int l = max(val, val2);
            dpArray[idx1][idx2] = l;
            return l;
        }
    }
}

int main() {
    while(true) {
        int k;
        scanf("%d", &k);
        if(k == 0) {
            break;
        }
        char str1[1001];
        char str2[1001];
        scanf("%s", str1);
        scanf("%s", str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int **dpArray = new int*[len1 + 1];
        for(int i=0;i<len1 + 1;++i) {
            dpArray[i] = new int[len2 + 1];
            memset(dpArray[i], -1, sizeof(int) * (len2 + 1));
        }
        int sLength = lcs(str1, len1 - 1, str2 - 1, len2, k, dpArray);
        for(int i=0;i<len1+1;++i) {
            delete [] dpArray[i];
        }
        delete [] dpArray;
        printf("%d\n", sLength);
    }
 
}
