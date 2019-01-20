#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
#include<set>
#include<stack>
#include<list>
using namespace std;
struct Prime {
    int num1;
    int num2;
};

int setIth(int num, int val, int idx) {
    stack<int> stk;
    int k = num;
    int i = 0;
    while(k) {
        if(i == idx) {
            stk.push(val);
        } else {
            int v = k % 10;
            stk.push(v);
        }
        k /= 10;
        ++i;
    }
    int ret = 0;
    while(!stk.empty()) {
        int n = stk.top();
        stk.pop();
        ret *= 10;
        ret += n;
    }
    return ret;
}

int bfs(int a, int b, map<int, set<int>*>& mp) {
    queue<pair<int, int> > q;
    pair<int, int> p;
    p.first = a;
    p.second = 0;
    q.push(p);
    set<int> visited;
    while(!q.empty()) {
        pair<int, int> num = q.front();
        q.pop();
        if(visited.find(num.first) != visited.end()) {
            continue;
        }
        visited.insert(num.first);
        if(num.first == b) {
            return num.second;
        }
        // get the list of all the primes reachable by num
        if(mp.find(num.first) == mp.end()) {
            continue;
        }
        set<int>* lst = mp[num.first];
        for(set<int>::iterator it=lst->begin();it != lst->end();++it) {
            pair<int, int> pr;
            pr.first = *it;
            pr.second = num.second + 1;
            q.push(pr); 
        }
    }
    return -1;
}

void addEdge(int a, int b, map<int, set<int>*>& mp) {
    if(mp.find(a) == mp.end()) {
        mp[a] = new set<int>();
    }
    if(mp.find(b) == mp.end()) {
        mp[b] = new set<int>();
    }
    mp[a]->insert(b);
    mp[b]->insert(a);
}

int getIth(int val, int idx) {
    while(idx--) {
        val /= 10;
    }
    return val % 10;
}

int main() {
    map<int, set<int>*>mp;
    int tests;
    //scanf("%d", &tests);
    bool *primeArray = new bool[10000];
    memset(primeArray, '\0', sizeof(bool) * 10000);
    primeArray[0] = primeArray[1] = true;
    int v = sqrt(10000);
    for(int i=2; i <= v;) {
        if(primeArray[i]) {
            i++;
            continue;
        }
        for(int j=i;;++j) {
            int prod = i * j;
            if(prod < 10000) {
                primeArray[prod] = true;
            } else {
                break;
            }
        }
        i++;
    }
    set<int> primes;
    for(int i=1000;i<10000;++i) {
        if(!primeArray[i]) {
            primes.insert(i);
        }
    }
    delete [] primeArray;
    for(set<int>::iterator itr=primes.begin(); itr != primes.end(); ++itr) {
        // try changing one character at a time
        for(int i=0;i<4;++i) {
            // change the i-th digit
            int init = getIth(*itr, i);
            int inc = i == 0?2:1;
            for(int j=init;j<10;j += inc) {
                int v = setIth(*itr, j,i);
                if(v != *itr && primes.find(v) != primes.end()) {
                    // add mappings between the two numbers
                    addEdge(v, *itr, mp);
                }
            }
        }
    }

    // Do the bfs
    scanf("%d", &tests);
    while(tests--) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        int cost = bfs(p1, p2, mp);
        if(cost == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", cost);
        }
    }
}
