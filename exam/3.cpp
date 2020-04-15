#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n,m,s;
    cin >> n >> m >> s;
    int** cityMap=new int*[n];
    for(int i=0; i<=n-1; i++)
    {
        cityMap[i] = new int[n];
        for(int j=0; i<=n-1; j++)
        {
            cityMap[i][j] = 1;
        }
    }
    for(int i=0; i<=m-1; i++)
    {
        int x,y;
        cin >> x >> y;
        if(x == 0)
        {
            cityMap[y-1][y-1] = 0;
        }
        else
        {
            cityMap[x-1][y-1] = 0;
            cityMap[y-1][x-1] = 0;
        }
        if(cityMap[s-1][s-1])
        {
            int a,num = 0;
            for(a=0; a<=n-1 && num==0; a++)
            {
                num += cityMap[s-1][a];
            }
            if(num == 0)
            {
                cityMap[s-1][s-1] = 0;
                cout << i+1 << endl;
                return 0;
            }
        }
        else
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    cout << 0 << endl;
    return 0;
}