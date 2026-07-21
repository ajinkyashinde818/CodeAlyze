#include <stdio.h>

int main() {
    int N = 0, K = 0;
    scanf("%d%d", &N, &K);
    int i;
    int resultCountOfFriends = 0;
    for (i = 0; i < N; ++i) {
        int heightOfFriend = 0;
        scanf("%d", &heightOfFriend);
        if (heightOfFriend >= K) {
            resultCountOfFriends++;
        }
    }

    printf("%d", resultCountOfFriends);
}
