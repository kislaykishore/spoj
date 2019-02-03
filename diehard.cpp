#include<cstdio>
#include<map>
using namespace std;
struct State {
    int health;
    int armor;
    int st;
    bool operator==(const State& stt) const {
        return health==stt.health && armor == stt.armor && st == stt.st;
    }
    bool operator<(const State& stt) const {
        return health < stt.health;
    }
};
int computeTime(State& state, map<State, int>& mp) {
    if(state.health <= 0 || state.armor <= 0) {
        return -1;
    }
    if(mp.find(state) != mp.end()) {
        return mp[state];
    }
    // try all the states
    State airState = state;
    airState.health += 3;
    airState.armor += 2;
    airState.st = 1;
    int maxTime = 0;
    if(state.st != 1) {
        int s1 = computeTime(airState, mp) + 1;
        maxTime = s1>maxTime?s1:maxTime;
    }
    State waterState = state;
    waterState.health -= 5;
    waterState.armor -= 10;
    waterState.st = 2;
    if(state.st != 2) {
        int s2 = computeTime(waterState, mp) + 1;
        maxTime = s2>maxTime?s2:maxTime;
    }
    State fireState = state;
    fireState.health -= 20;
    fireState.armor += 5;
    fireState.st = 3;
    if(state.st != 3) {
        int s3 = computeTime(fireState, mp) + 1;
        maxTime = s3>maxTime?s3:maxTime;
    }
    mp[state] = maxTime;
    return maxTime;
}
int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int h, a;
        scanf("%d %d", &h, &a);
        map<State, int> mp;
        // step into air
        State init;
        init.health = h;
        init.armor = a;
        init.st = -1;
        int time = computeTime(init, mp);
        printf("%d\n", time);
    }
}
