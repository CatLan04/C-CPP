#include<stdio.h>
int a[10][10],row[10][10],col[10][10],o[4][4][10];
int cnt;
void solution()
{
    cnt++;
    printf("Cach dien thu %d : \n",cnt);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
int rec(int n)
{
    if (n <= 3) return 1;
    if (n <= 6) return 2;
    return 3;
}
void Try(int i, int j)
{
    int r = rec(i);
    int c = rec(j);
    for (int k = 1; k <= 9; k++)
        if (row[i][k]==0&&col[j][k]==0&&o[r][c][k]==0)
    {
        a[i][j] = k;
        row[i][k] = 1;
        col[j][k] = 1;
        o[r][c][k] = 1;
        if (i == 9 && j == 9) solution();
        else
        {
            if (j == 9) Try(i+1,1);
            else Try(i,j+1);
        }
        row[i][k] = 0;
        col[j][k] = 0;
        o[r][c][k] = 0;
    }
}
int main()
{
    Try(1,1);
}
