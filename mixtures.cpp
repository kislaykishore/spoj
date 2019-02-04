#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct Node {
    int color;
    int smoke;
};
Node minimizeSmoke(Node** dpArray, int startIndex, int endIndex) {
    if(dpArray[startIndex][endIndex].color != -1) {
        return dpArray[startIndex][endIndex];
    }
    int minColor = -1;
    int minSmoke = -1;
    for(int i=startIndex;i<endIndex;++i) {
        Node smoke1 = minimizeSmoke(dpArray, startIndex, i);
        Node smoke2 = minimizeSmoke(dpArray, i+1, endIndex);
        int totalSmoke = smoke1.smoke + smoke2.smoke;
        totalSmoke += smoke1.color * smoke2.color;
        if(minSmoke == -1 || totalSmoke < minSmoke) {
            minColor = (smoke1.color + smoke2.color) % 100;
            minSmoke = totalSmoke;
        }
    }
    dpArray[startIndex][endIndex].color = minColor;
    dpArray[startIndex][endIndex].smoke = minSmoke;
    return dpArray[startIndex][endIndex];
}

int main() {
    int n;
    while(cin>>n) {
        int* array = new int[n];
        for(int i=0;i<n;++i) {
            scanf("%d", array+i);
        }
        Node **dpArray = new Node*[n];
        for(int i=0;i<n;++i) {
            dpArray[i]  = new Node[n];
            memset(dpArray[i], -1, sizeof(Node) * n);
        }
        for(int i=0;i<n;++i) {
            dpArray[i][i].color = array[i];
            dpArray[i][i].smoke = 0;
        }
        delete [] array;
        Node minSmoke = minimizeSmoke(dpArray, 0, n-1);
        for(int i=0;i<n;++i) {
            delete dpArray[i];
        }
        delete [] dpArray;
        printf("%d\n", minSmoke.smoke);
    }
}
