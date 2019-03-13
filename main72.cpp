#include<cstdio>
#include<cstring>
struct Node {
    int val;
    Node* next;
    Node* prev;
};
struct List {
    Node* head;
    Node* tail;
    List() {
        head = new Node();
        tail = new Node();
        tail->next = 0;
        head->next = tail;
        tail->prev = head;
        head->prev = 0;
    }

    void insert(int v) {
        Node* newNode = new Node();
        newNode->val = v;
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;
    }

    void appendList(List& list) {
        tail->prev->next = list.head->next;
        list.head->next->prev = tail->prev;
        delete list.head;
        delete tail;
        list.head = 0;
        tail = list.tail;
    }

    ~List() {
        Node* node = head;
        while(node != 0) {
            Node* next = node->next;
            delete node;
            node = next;
        }
    }
};
using namespace std;
bool sums[100001];
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        memset(sums, 0, sizeof(sums));
        int num;
        scanf("%d", &num);
        List lst;
        lst.insert(0);
        sums[0] = true;
        int totalSum = 0;
        for(int i=0;i<num;++i) {
            int tmp;
            scanf("%d", &tmp);
            List newList;
            Node* node = lst.head->next;
            while(node != lst.tail) {
                int v = tmp + node->val;
                if(!sums[v]) {
                    newList.insert(v);
                    sums[v] = true;
                    totalSum += v;
                }
                node = node->next;
            }
            lst.appendList(newList);
        }
        printf("%d\n", totalSum);
    }
}
