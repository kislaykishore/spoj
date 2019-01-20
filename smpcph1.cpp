#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main() {
    int len;
    scanf("%d\n", &len);
    char transMap[26];
    for(int i=0;i<26;++i) {
        transMap[i] = (int)'a' + i;
    }
    char str[26];
    //scanf("%s", str);
    cin.getline(str, 26);
    for(int i=0;i<len;++i) {
        transMap[str[i] - 'a'] = str[(i+1)%len];
    }

    int n;
    scanf("%d\n", &n);
    while(n--) {
        char pt[1001];
        //scanf("%s", pt);
        cin.getline(pt, 1001);
        for(int i=0;pt[i] != '\0';++i) {
            if(pt[i] >= 'a' && pt[i] <= 'z') {
                pt[i] = transMap[pt[i] - 'a'];
            }
        }
        printf("%s\n", pt);
    }
}
