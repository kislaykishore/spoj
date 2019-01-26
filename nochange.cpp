#include<cstdio>
#include<cstring>
int max(int a, int b) {
    return a > b?a:b;
}
int main() {
    int addDollars;
    scanf("%d", &addDollars);
    int numCoins;
    scanf("%d", &numCoins);
    int *coins = new int[numCoins];

    for(int i=0;i<numCoins;++i) {
        scanf("%d", coins + i);
    }

    int **array = new int*[numCoins];
    for(int i=0;i<numCoins;++i) {
        array[i] = new int[addDollars + 1];
        memset(array[i], -1, (addDollars + 1) * sizeof(int));
    }

    int firstCoin = coins[0];
    for(int i=0;;i++ ) {
        int prod = firstCoin * i;
        if(prod > addDollars) {
            break;
        }
        array[0][prod] = i;
    }

    for(int i=1;i<numCoins;++i) {
        for(int j=0;j<=addDollars;++j) {
            int val = array[i-1][j];
            if(val != -1) {
                // the sum exists
                for(int k=0;k<=val;++k) {
                    int index = k * coins[i] + j;
                    if(index > addDollars) {
                        break;
                    }
                    array[i][index] = max(array[i][index], k);
                }
            }
        }
    }

    if(array[numCoins-1][addDollars] != -1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    delete [] coins;
    for(int i=0;i<numCoins;++i) {
        delete [] array[i];
    }
    delete [] array;
}
