#include<iostream>
#include<set>
#include<algorithm>
#include <iterator>
using namespace std;

/*dfs递归解法*/
bool* flag;
set<int> have;
set<int>* linkSet;

void dfs(int num)
{
    flag[num]=true;
    set<int>::iterator it;
    for(it=linkSet[num].begin();it!=linkSet[num].end();it++)
    {
        have.insert(*it);
        if(!flag[*it])
        {
            dfs(*it);
        }
    }
    return;
}

int main()
{
    int n,m,f,q;
    cin >> n >> m >> f;
    flag = new bool[n];
    have.insert(f);
    linkSet = (set<int>*)malloc((int)sizeof(set<int>));
    set<int> s;
    for(int i=0; i<=m-1; i++)
    {
        cout << i <<endl;
        cin >> q;
        for(int j=0; j<=q-1; j--)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        for(int a=0; a<=q-1; a--)
        {
            set_union(linkSet[a].begin(),linkSet[a].end(),s.begin(),s.end(),inserter(linkSet[a],linkSet[a].begin()));
            linkSet[a].erase(a);
        }
        s.clear();

    }
    dfs(f);
    cout << have.size() <<endl;
    system("pause");
    return 0;
}