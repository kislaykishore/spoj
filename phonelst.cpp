#include<cstdio>
#include<cstring>
struct Node {
    Node* children[11];
};
bool insert(Node* node, char* str, int idx, int len) {
    if(idx == len) {
        for(int i=0;i<10;++i) {
            if(node->children[i]) {
                return false;
            }
        }
        node->children[10] = (Node*)1;
        return true;
    }
    // if it's not last
    int c = str[idx] - '0';
    if(!node->children[c]) {
        node->children[c] = new Node();
        memset(node->children[c], 0, sizeof(Node*) * 11);
    }
    if(node->children[10]) {
        return false;
    }
    return insert(node->children[c], str, idx+1, len);
}

void deleteNode(Node* node) {
    if(node == 0) {
        return;
    }
    for(int i=0;i<10;++i) {
        deleteNode(node->children[i]);
    }
    delete node;
}

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        Node nullNode;
        memset(nullNode.children, 0, sizeof(Node*) * 11);
        int n;
        scanf("%d", &n);
        bool val = true;
        while(n--) {
            char phoneNum[11];
            scanf("%s", phoneNum);
            if(val) {
                val = insert(&nullNode, phoneNum, 0, strlen(phoneNum));
            }
        }
        printf("%s\n", val?"YES":"NO");
        // delete
        for(int i=0;i<10;++i) {
            deleteNode(nullNode.children[i]);
        }
    }
}
