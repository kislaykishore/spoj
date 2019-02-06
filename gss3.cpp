#include<cstdio>
#include<cstring>
#define max(x, y) ((x) > (y)?(x):(y))
#define MIN_VAL -101235453
struct Node {
    int maxSuffixSum;
    int maxPrefixSum;
    int maxSubarraySum;
    int totalSum;
};

int computeTreeSize(int n) {
    int x = 1;
    int val = n;
    while(n) {
        n >>= 1;
        x <<= 1;
    }
    return (x << 1);
}
Node* buildTree(int* array, int startIndex, int endIndex, Node* treeArray, int idx, int n) {
    if(startIndex >= n) {
        return 0;
    }
    if(startIndex == endIndex) {
        treeArray[idx].totalSum = treeArray[idx].maxSuffixSum = treeArray[idx].maxPrefixSum = treeArray[idx].maxSubarraySum = array[startIndex];
        return treeArray + idx;
    } else {
        int mid = (startIndex + endIndex)/2;
        Node* val1 = buildTree(array, startIndex, mid, treeArray, 2 * idx, n);
        Node* val2 = buildTree(array, mid+1, endIndex, treeArray, 2*idx + 1, n);
        treeArray[idx].maxPrefixSum = max(val1->maxPrefixSum, val1->totalSum + val2->maxPrefixSum);
        treeArray[idx].maxSuffixSum = max(val1->maxSuffixSum + val2->totalSum, val2->maxSuffixSum);
        treeArray[idx].totalSum = val1->totalSum + val2->totalSum;
        treeArray[idx].maxSubarraySum = max(val1->maxSubarraySum, val2->maxSubarraySum);
        treeArray[idx].maxSubarraySum = max(treeArray[idx].maxSubarraySum, val1->maxSuffixSum + val2->maxPrefixSum);
        return treeArray + idx;
    }
}

Node* update(Node* treeArray, int idx, int updateIndex, int queryStartIdx, int queryEndIdx, int updateVal) {
    if(updateIndex < queryStartIdx || updateIndex > queryEndIdx) {
        return treeArray + idx;
    }
    if(queryStartIdx == queryEndIdx && queryStartIdx == updateIndex) {
        treeArray[idx].totalSum = treeArray[idx].maxSuffixSum = treeArray[idx].maxPrefixSum = treeArray[idx].maxSubarraySum = updateVal;
        return treeArray + idx;
    } else {
        // there is a partial match
        int mid = (queryStartIdx + queryEndIdx)/2;
        Node* val1 = update(treeArray, 2 * idx, updateIndex, queryStartIdx, mid, updateVal);
        Node* val2 = update(treeArray, 2 * idx + 1, updateIndex, mid + 1, queryEndIdx, updateVal);
        treeArray[idx].maxPrefixSum = max(val1->maxPrefixSum, val1->totalSum + val2->maxPrefixSum);
        treeArray[idx].maxSuffixSum = max(val1->maxSuffixSum + val2->totalSum, val2->maxSuffixSum);
        treeArray[idx].totalSum = val1->totalSum + val2->totalSum;
        treeArray[idx].maxSubarraySum = max(val1->maxSubarraySum, val2->maxSubarraySum);
        treeArray[idx].maxSubarraySum = max(treeArray[idx].maxSubarraySum, val1->maxSuffixSum + val2->maxPrefixSum);
        return treeArray + idx;
    }
}

Node query(Node* treeArray, int idx, int startIndex, int endIndex, int queryStartIdx, int queryEndIdx) {
    if(queryStartIdx <= startIndex && queryEndIdx >= endIndex) {
        return treeArray[idx];
    } else if(queryStartIdx > endIndex || queryEndIdx < startIndex) {
        Node ret;
        ret.maxSubarraySum = MIN_VAL;
        return ret;
    }

    // there is a partial match
    int mid = (startIndex + endIndex) / 2;
    Node node1 = query(treeArray, idx*2, startIndex, mid, queryStartIdx, queryEndIdx);
    Node node2 = query(treeArray, idx*2 + 1, mid + 1, endIndex, queryStartIdx, queryEndIdx);
    Node result;
    if(node1.maxSubarraySum == MIN_VAL) {
        return node2;
    } else if(node2.maxSubarraySum == MIN_VAL) {
        return node1;
    }
    result.maxPrefixSum = max(node1.maxPrefixSum, node1.totalSum + node2.maxPrefixSum);
    result.maxSuffixSum = max(node1.maxSuffixSum + node2.totalSum, node2.maxSuffixSum);
    result.maxSubarraySum = max(node1.maxSubarraySum, node2.maxSubarraySum);
    result.maxSubarraySum = max(result.maxSubarraySum, node1.maxSuffixSum + node2.maxPrefixSum);
    result.totalSum = node1.totalSum + node2.totalSum;
    return result;
}
int main() {
    int n;
    scanf("%d", &n);
    int *array = new int[n];
    for(int i=0;i<n;++i) {
        scanf("%d", array + i);
    }
    // construct segment tree
    int treeSize = computeTreeSize(n);
    Node* treeArray = new Node[treeSize];
    buildTree(array, 0, n-1, treeArray, 1, n);
    delete [] array;

    // query
    int m;
    scanf("%d", &m);
    for(int i=0;i<m;++i) {
        int op, startIndex, endIndex;
        scanf("%d %d %d", &op, &startIndex, &endIndex);
        if(op == 1) {
            Node node = query(treeArray, 1, 1, n, startIndex, endIndex);
            printf("%d\n", node.maxSubarraySum);
        } else {
            update(treeArray, 1, startIndex, 1, n, endIndex);
        }
    }
    delete [] treeArray;
}
