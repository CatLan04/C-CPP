#include<stdio.h>
int x[20];
int n,r0,c0;

int check(int v, int k) {
    // Kiểm tra xem giá trị v có thể gán cho x[k] không
    for (int i = 1; i <= k-1 ; i++) {
        if (x[i] == v) return 0;
        if (x[i] + i == v + k) return 0;
        if (x[i] - i == v - k) return 0;
    }
    if(x[c0] == v) return 0;
    if(x[c0] + c0 == v+k) return 0;
    if (x[c0] - c0 == v - k) return 0;
    return 1;
}
void printSolution() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
}

void TRY(int k) {
    if (k == c0)
        if (k == n) printSolution();
            else TRY(k + 1);
    for (int v = 1; v <= n ; v++) {
        if (check(v, k)) {
            x[k] = v;
            if (k == n) printSolution();
            else TRY(k + 1);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &r0, &c0);
    x[c0] = r0;
    TRY(1);
    return 0;
}
