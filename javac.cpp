#include<cstdio>
#include<iostream>
#include<cctype>
#include<string>
using namespace std;
bool isC(char* str) {
    if(str[0] <'a' || str[0] >'z') {
        return false;
    }
    int i;
    for(i=1;str[i];++i) {
        if(str[i] == '_' && str[i-1] == '_') {
            return false;
        } else if((str[i] <'a' || str[i] >'z') && str[i] != '_') {
            return false;
        }
    }
    return str[i-1] >= 'a' && str[i-1] <= 'z';
}

string convertToC(char* str) {
    if(str[0] < 'a' || str[0] >'z') {
        return "";
    }
    string s("");
    for(int i=0;str[i];++i) {
        if(islower(str[i])) {
            s += str[i];
        } else if(isupper(str[i])) {
            s += "_";
            s += tolower(str[i]);
        } else {
            return "";
        }
    }
    return s;
}

void convertToJava(char* str) {
    string result = "";
    bool capitalize = false;
    int idx1 = 0;
    int idx2 = 0;
    for(int i=0;str[i];++i) {
        if(str[i] == '_') {
            capitalize = true;
            idx2++;
        } else {
            if(capitalize) {
                str[idx1] = toupper(str[idx2]);
                capitalize = false;
            } else {
                str[idx1] = str[idx2];
            }
            idx1++;
            idx2++;
        }
    }
    str[idx1] = 0;
}
int main() {
    char str[101];
    while(scanf("%s", str) != EOF) {
        string result;
        if(isC(str)) {
            convertToJava(str);
            printf("%s\n", str);
            continue;
        } else {
            string s = convertToC(str);
            if(s == "") {
                printf("Error!\n");
            } else {
                cout<<s<<'\n';
            }
        }
    }
}
