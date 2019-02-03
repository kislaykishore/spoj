#include<cstdio>
#include<algorithm>
using namespace std;
struct Activity {
    int startTime;
    int endTime;
};
bool compareActivity(Activity& a1, Activity& a2) {
    return a1.endTime < a2.endTime;
}

int main() {
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        int n;
        scanf("%d", &n);
        Activity* activities = new Activity[n];
        for(int i=0;i<n;++i) {
            int m, n;
            scanf("%d %d", &activities[i].startTime, &activities[i].endTime);
        }
        sort(activities, activities + n, compareActivity);
        int activityCount = 0;
        int lastEndTime = 0;
        for(int i=0;i<n;++i) {
            if(activities[i].startTime >= lastEndTime) {
                activityCount++;
                lastEndTime = activities[i].endTime;
            }
        }
        delete [] activities;
        printf("%d\n", activityCount);
    }
}
