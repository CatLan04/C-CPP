#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
class ThiSinh
{
private:
    string name;
    float toan,li,hoa;
    float tong;
public:
    void set_tt()
    {
        cout << "Nhap ten thi sinh: " ;
        fflush(stdin);
        getline(cin,this->name);
        cout << "Nhap diem: ";
        cin >> this->toan >> this->li >> this->hoa;
    }
    void out()
    {
        this->tong = this->toan+this->li+this->hoa;
        if (this->tong >= 18)
            cout << this->name << '\n';
    }
};
int main()
{
    ThiSinh a[100];
    int n;
    cout << "Nhap so luong thi sinh du thi: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i].set_tt();
    cout << "Danh sach thi sinh trung tuyen: "<<'\n';
    for (int i = 1; i <= n; i++)
        a[i].out();
    return 0;
}
