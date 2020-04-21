#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    cin >> n >>m ;
    vector<int> a;
    for(int i=0; i<=n-1; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(),a.end());
    int p;
    cin >> p;
    vector<int> r;
    int money;
    int k;
    for(int i=0; i<=p-1; i++)
    {
        int num;
        cin >> num;
        k=0;
        money=0;
        for(int j=0; j<=num-1; j++)
        {
            if(j%m == 0)
            {
                k++;
            }
            money = money + a[num-j-1]*k;
            
        }
        r.push_back(money);
    }
    for(int i=0; i<=p-1; i++)
    {
        cout << r[i] <<endl;
    }
    return 0;
}