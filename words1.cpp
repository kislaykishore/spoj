#include<cstdio>
#include<map>
#include<list>
using namespace std;
int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int inputs;
        map<char, int> degreeMap;
        scanf("%d", &inputs);
        char ch;
        scanf("%c", &ch);
        map<char, list<char>* > graph;
        for(int i=0;i<inputs;++i) {
            scanf("%c", &ch);
            char ch1 = ch;
            char ch2;
            while(true) {
                scanf("%c", &ch);
                if(ch == '\n') {
                    break;
                } else {
                    ch2 = ch;
                }
            }
            if(graph[ch1] == NULL) {
                graph[ch1] = new list<char>();
            }
            if(graph.find(ch2) == graph.end()) {
                graph[ch2] = new list<char>();
            }
            graph[ch1]->push_back(ch2);
            degreeMap[ch1] = degreeMap[ch1] + 1;
            degreeMap[ch2] = degreeMap[ch2] - 1;
        }
        char startVertex = '$';
        char endVertex = '$';
        int count = 0;
        bool possible = true;
        for(map<char, int>::iterator itr = degreeMap.begin(); itr != degreeMap.end(); ++itr) {
            if(itr->second != 0) {
                if(count == 2) {
                    possible = false;
                }
                else if(itr->second == 1) {
                    startVertex = itr->first;
                    count++;
                } else if(itr->second == -1) {
                    endVertex = itr->first;
                    count++;
                } else {
                    possible = false;
                }
            }
        }

        // if possible is false, we have to check whether the graph is connected
        // we know the start and end vertices, so, we just have to travel through the graph

        possible = startVertex != '$' && endVertex != '$' && possible;
        if(possible) {
            char vertex = startVertex;
            while(!graph[vertex]->empty()) {
                list<char>* v = graph[vertex];
                char nextVertex = (*v).front();
                (*v).pop_front();
                vertex = nextVertex;
            }
            // check if any of the vertices is not visited
            for(map<char, list<char>* >::iterator it=graph.begin();possible && it != graph.end();++it) {
               if(!it->second->empty()) {
                   possible = false;
               }

            }
        }
        if(possible) {
            printf("Ordering is possible.\n");
        } else {
            printf("The door cannot be opened.\n");
        }
    }
}
