#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int main() {
    int f,s,g,u,d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    f--;
    s--;
    g--;

    bool visited[1000000];
    memset(visited, 0, sizeof(visited));
    int pushes = 0;
    queue<int> q;
    q.push(s);
    q.push(-1);
    visited[s] = true;
    bool found = false;
    while(q.size() > 1 && !found) {
        int front = q.front();
        q.pop();
//        printf("%d\n", front);
        if(front == -1) {
            pushes++;
            q.push(-1);
            continue;
        }
        visited[front] = true;
        if(front == g) {
            found = true;
            break;
        } else {
            int up = front + u;
            if(up <= f && !visited[up]) {
                q.push(up);
                visited[up] = true;
            }
            int down = front - d;
            if(down >= 0 && !visited[down]) {
                q.push(down);
                visited[down] = true;
            }
        }
    }
    if(found) {
        printf("%d\n", pushes);
    } else {
        printf("use the stairs\n");
    }
}
