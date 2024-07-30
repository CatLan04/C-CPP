#include <stdio.h>

int count(int d[], int num, int tong) {
    int i, j;
    int dp[tong + 1];
    for (i = 0; i <= tong; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (i = 0; i < num; i++) {
        for (j = d[i]; j <= tong; j++) {
            dp[j] += dp[j - d[i]];
        }
    }
    return dp[tong];
}

int main() {
    int num, tong;
    scanf("%d", &num);
    scanf("%d", &tong);
    int d[num];
    for (int i = 0; i < num; i++) {
        scanf("%d",&d[i]);
    }
    int result = count(d, num, tong);
    printf("%d\n", result);
    return 0;
}
