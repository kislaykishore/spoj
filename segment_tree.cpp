#include<cstdio>
#include<cstring>
void build(int* tree, int *array, int node, int start, int end) {
    if(start == end) {
        tree[node] = array[start];
    } else {
        build(tree, array, 2 * node, start, (start + end)/2);
        build(tree, array, 2 * node + 1, (start + end)/2 + 1, end);
        tree[node] = tree[2 * node] + tree[2* node + 1];
    }
}

bool isOverlap(int a, int b, int x, int y) {
    return (a <= y && b >= y) || (a <= x && b >= x) || (a >= x && b <= y);
}

bool isCompleteOverlap(int start, int end, int targetStart, int targetEnd) {
    return (start >= targetStart && end <= targetEnd);
}

int update(int* tree, int node, int start, int end, int val, int targetStart, int targetEnd) {
    int sum = 0;
    if(start == end) {
        tree[node] += val;
        sum = val;
    } else {
        // verify if we need to update in the left subtree
        int leftStart = start;
        int leftEnd = (start + end)/2;
        if(isOverlap(leftStart, leftEnd, targetStart, targetEnd)) {
            sum += update(tree, node * 2, leftStart, leftEnd, val, targetStart, targetEnd);
        }
        int rightStart = leftEnd + 1;
        int rightEnd = end;
        if(isOverlap(rightStart, rightEnd, targetStart, targetEnd)) {
            sum += update(tree, node * 2 + 1, rightStart, rightEnd, val, targetStart, targetEnd);
        }
        tree[node] += sum;
    }
    return sum;
}
int query(int* tree, int node, int start, int end, int targetStart, int targetEnd) {
    int sum = 0;
    if(!isOverlap(start, end, targetStart, targetEnd)) {
        return 0;
    }
    else if(isCompleteOverlap(start, end, targetStart, targetEnd)) {
        return tree[node];
    }

    // Partial overlap
    int leftStart = start;
    int leftEnd = (start + end)/2;
    sum += query(tree, node * 2, leftStart, leftEnd, targetStart, targetEnd);

    int rightStart = leftEnd + 1;
    int rightEnd = end;
    sum += query(tree, node * 2 + 1, rightStart, rightEnd, targetStart, targetEnd);
    return sum;
        
}
int getTreeSize(int n) {
    int val = 1;
    while(val < n) {
        val <<= 1;
    }
    return (val << 1) - 1;
}

int main() {
    int n=6;
    int *array = new int[n + 1];
    for(int i=1;i<=n;++i) {
        scanf("%d", array + i);
    }
    int treeSize = getTreeSize(n);
    int* tree = new int[treeSize + 1];
    memset(tree, '\0', sizeof(int) * treeSize);
    build(tree, array, 1, 1, n);
    while(true) {
        for(int i=1;i<treeSize+1;++i) {
            printf("%d\n", tree[i]);
        }
        int start, end, val;
        scanf("%d %d %d", &start, &end, &val);
        update(tree, 1, 1, treeSize, val, start, end);
        scanf("%d %d", &start, &end);
        printf("Value: %d\n", query(tree, 1, 1, treeSize, start, end));
    }
}
