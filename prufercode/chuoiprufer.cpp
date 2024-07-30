#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int d[1001][1001];
int kq[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x,y;
        cin >> x >> y;
        b[x]++;
        b[y]++;
        d[x][y]=d[y][x]=1;
    }
    int dmin = n+1;
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 1 && i <= dmin){
        dmin = i;
        do{
                //cout << dmin << " ";
                for (int j = 0; j<= n; j++)
                    if(d[dmin][j]==1)
                    {
                        d[dmin][j]=d[j][dmin]=0;
                        b[dmin]--;
                        --b[j];
                        if (j < i && b[j]==1 && j!=0) dmin = j;
                        else dmin = n+1;
                        kq[++k]=j;
                        break;
                    }
                if(k==n-1) break;
            }while(dmin!=i&&dmin!=n+1);}
        if(k==n-1) break;
    }
    //cout << k << "\n";
    for (int i = 1; i <= k; i++)
    {
        cout<< kq[i] << " ";
    }
}
