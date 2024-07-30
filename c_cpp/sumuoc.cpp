#include<bits/stdc++.h>
#define se second
#define fi first
using namespace std;
const int N=1e6+7;
map<int,int> m;
int f[N],n;
void sang()
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i*i<=1000000;i++)
        if(f[i]==0)
        for(int j=i*i;j<=1000000;j+=i)
        if(f[j]==0) f[j]=1;
    int k=0;
    for(int i=1;i<=1000000;i++)
        if(f[i]==0)
    {
        k++;
        f[k]=i;
    }
}
void phantich(long long x)
{
    int i=1;
    while(f[i]*f[i]<=x)
    {
        while(x%f[i]==0)
        {
            m[f[i]]++;
            x/=f[i];
        }
        i++;
    }
    if(x>1) m[x]++;
}
string operator+ (string a,string b)
{
    string res="";
    int nho=0;
    while(a.size()<b.size()) a='0'+a;
    while(b.size()<a.size()) b='0'+b;
    for(int i=a.size()-1;i>=0;i--)
    {
        int x=a[i]+b[i]-96+nho;
        nho=x/10;
        x=x%10;
        res=char(x+48)+res;
    }
    if(nho>1) res="1"+res;
    return res;
}
string operator-(string a,string b)
{
    string res="";
    int nho=0,tam=0;
    while(a.size()<b.size()) a='0'+a;
    while(b.size()<a.size()) b='0'+b;
    if(a<b) {swap(a,b),tam=1;}
    for(int i=a.size()-1;i>=0;i--)
    {
        int x=a[i]-b[i]-nho;
        if(x<0)
        {
            x=x+10;
            nho=1;
        }
        res=char(x+48)+res;
    }
    while(res.size()>1&&res[0]=='0') res.erase(0,1);
    if(tam==1) res="-"+res;
    return res;
}
string operator*(string a,string b)
{
    string res="";
    int n=a.size();
    int m=b.size();
    int len=m+n-1;
    int nho=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m&&i-j>=1)
        {
            int a1=a[j]-48;
            int b1=b[i-j-1]-48;
            tmp+=a1*b1;
        }
        tmp+=nho;
        nho=tmp/10;
        res=char(tmp%10+48)+res;
    }
    while(res.size()>1&&res[0]=='0') res.erase(0,1);
    return res;
}
bool cmp(string a,string b)
{
    while(a.size()>b.size()) b="0"+b;
    while(b.size()>a.size()) a="0"+a;
    if(a>=b) return 1;
    else return 0;
}
string chia(string a,string b)
{
   string res="";
   string hold="",kb[11];
   kb[0]="0";
   for(int i=1;i<=10;i++) kb[i]=kb[i-1]+b;
   for(int i=0;i<a.size();i++)
   {
       hold=hold+a[i];
       int k=1;
       while(cmp(hold,kb[k])&&k<10) k++;
       k--;
       hold=hold-kb[k];
       res=res+char(k+48);
   }
   while(res.size()&&res[0]=='0') res.erase(0,1);
   return res;
}
string cd(long long x)
{
    string res="";
    while(x>0)
    {
        res=char(x%10+48)+res;
        x/=10;
    }
    return res;
}
string lt(int n,int k)
{
    if(k==0) return "1";
    if(k==1) return cd(n);
    if(k%2==0) return lt(n,k/2)*lt(n,k/2);
    if(k%2==1) return lt(n,k/2)*lt(n,k/2)*cd(n);
}
string k="1",res;
void solve()
{
    for(auto i:m)
    {
        k=k*cd(i.se+1);
    }
    cout<<k<<'\n';
    res="1";
    for(auto i:m)
    {
        string tu=lt(i.fi,i.se+1)-"1";
        string mau=cd(i.fi)-"1";
        cout<<tu<<" "<<mau<<" ";
        string s=tu/mau;
        cout<<s<<endl;
        res=res*s;
        //cout<<res<<" ";
    }
    cout<<res;
}
main()
{
    cin>>n;
    sang();
    for(int i=2;i<=n;i++)
        phantich(i);
    solve();
}
