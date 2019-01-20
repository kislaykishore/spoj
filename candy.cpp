#include<cstdio>
int main() {
    while(true) {
        int packets; 
        scanf("%d", &packets);
        if(packets == -1) {
            return 0;
        }
        int *distribution = new int[packets];
        int sum = 0;
        for(int i=0;i<packets;++i) {
            scanf("%d", distribution + i);
            sum += distribution[i];
        }

        int moves = 0;
        if(sum % packets == 0) {
            // possible
            int avg = sum/packets;
            for(int i=0;i<packets;++i) {
                if(distribution[i] > avg) {
                    moves += (distribution[i] - avg);
                }
            }
            printf("%d\n", moves);
        } else {
            printf("-1\n");
        }
    }
}
