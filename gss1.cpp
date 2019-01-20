#include<cstdio>
#include<cstring>
struct Node {
    int prefixSum;
    int suffixSum;
    int maxSubArraySum;
    int totalSum;
};

int max(int a, int b) {
    return a< b?b:a;
}
int computeLevels(int n) {
    int level = 1;
    int val = 1;
    while(val < n){
        val <<= 1;
        level++;
    }
    return level;
}

int computeStartIndex(int levels) {
    return (1 <<(levels-1)) - 1;
}
void populateSegmentTree(Node* array, int index);

int main() {
    int n;
    scanf("%d", &n);
    int levels = computeLevels(n);
    printf("%d\n", levels);
    int sz = (1 << levels) - 1;
    int startIndex = computeStartIndex(levels);
    Node *array = new Node[sz];
    int *valArray = new int[n];
    for(int i=0;i<n;++i) {
        scanf("%d", valArray + i);
    }
    for(int i=0;i<startIndex;++i) {
        array[i].totalSum = -16000;
    }
    for(int i = startIndex;i<sz;++i) {
        int arrayIdx = i - startIndex;
        if(arrayIdx < n) {
            array[i].prefixSum = array[i].suffixSum = array[i].maxSubArraySum = array[i].totalSum = valArray[arrayIdx];
        } else {
            array[i].prefixSum = array[i].suffixSum = array[i].maxSubArraySum = array[i].totalSum = 0;
        }
    }
    delete [] valArray;

    // construct segment tree
    populateSegmentTree(array, 0);
    // Now the tree has been populated
    int m;
    scanf("%d", &m);
    int x, y;
    while(m--) {
        scanf("%d %d", &x, &y);
        // Now we have to find the node where they diverge
        
    }
    for(int i=0;i<sz;++i) {
        printf("%d Prefix: %d, Suffix: %d, SubArray: %d, Total: %d\n", i, array[i].prefixSum, array[i].suffixSum, array[i].maxSubArraySum, array[i].totalSum);
    }

    delete [] array;
}
void populateSegmentTree(Node* array, int index) {
    if(array[index].totalSum != -16000) {
        return;
    }
    int lIndex = 2*index + 1;
    int rIndex = lIndex + 1;
    populateSegmentTree(array, lIndex);
    populateSegmentTree(array, rIndex);
    int prefixSum = array[lIndex].totalSum + array[rIndex].prefixSum;
    array[index].prefixSum = max(prefixSum, array[lIndex].prefixSum);

    int suffixSum = array[lIndex].suffixSum + array[rIndex].totalSum;
    array[index].suffixSum = max(suffixSum, array[rIndex].suffixSum);

    array[index].totalSum = array[lIndex].totalSum + array[rIndex].totalSum;

    int maxSubArraySum = max(array[lIndex].maxSubArraySum, max(array[rIndex].maxSubArraySum, array[lIndex].suffixSum + array[rIndex].prefixSum));
    array[index].maxSubArraySum = maxSubArraySum;

}
