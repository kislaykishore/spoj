#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int computeMinCost(char *str);
int computeMinCost(char* str, int lIndex, int rIndex, int** array);
int main() {
    char str[2050];
    int test = 0;
    while(true) {
        ++test;
        scanf("%s", str);
        if(str[0] == '-') {
            break;
        }
        int len = strlen(str);
        int cost = computeMinCost(str);
        printf("%d. %d\n", test, cost);
    }
    return 0;
}

int computeMinCost(char *str) {
    int len = strlen(str);
    int **array = new int*[len];
    for(int i=0;i<len;++i) {
        array[i] = new int[len];
        for(int j=0;j<len;++j) {
            array[i][j] = -1;
        }
    }
    int cost = computeMinCost(str, 0, len - 1, array);
    for(int i=0;i<len;++i) {
        delete [] array[i];
    }
    delete [] array;
    return cost;
}

int computeMinCost(char* str, int lIndex, int rIndex, int **array) {
    // either it could be curly braces surrounding an inner
    // stable string
    if(array[lIndex][rIndex] != -1) {
        return array[lIndex][rIndex];
    }
    int minCost = 0;
    if(rIndex - lIndex > 1) {
        minCost = computeMinCost(str, lIndex + 1, rIndex - 1, array);
    }

    // we need to add the cost of making the outer braces in-line
    if(str[lIndex] == '}') {
        minCost++;
    }
    if(str[rIndex] == '{') {
        minCost++;
    }

    // otherwise, it could be a concatenation of two stable strings
    for(int i = lIndex + 1;i<= rIndex-2;i+=2) {
        int cost = computeMinCost(str, lIndex, i, array);
        cost += computeMinCost(str, i + 1, rIndex, array); 
        minCost = cost<minCost?cost:minCost;
    }
    array[lIndex][rIndex] = minCost;
    return minCost;

    
    
}
