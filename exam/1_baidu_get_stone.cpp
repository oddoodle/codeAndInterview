#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int num_of_cycle;
    cin >> num_of_cycle;
    for(; num_of_cycle>=1; num_of_cycle--){
        int num;
        int key=0;
        vector<int> stones;
        cin >> num;
        for(int i=0; i<=num-1; i++){
            int a;
            cin >> a;
            if(a >= 0){
                stones.push_back(a);
            }
            else
            {
                return 0;
            }
        }
        if(num == 1)
        {
            if(stones[0]%2){
                key += 1;
            }
            /*else{
                cout << "woman" <<endl;
            }*/
        }
        else{
            sort(stones.begin(),stones.end());
            int map=0;
            for(int j=0; j<=num-2; j++)
            {
                if(stones[j] == stones[j+1])
                {
                    map += 1;
                }
            }
            if(stones[1] != 0 && map<2){

                for(int j=0; j<=num-1; j++)
                {
                    if(stones[j] != j)
                    {
                        key = key + stones[j] - j;
                    }

                }
            }
        } 
        
        if(key%2){
            cout << "man" <<endl;
        }
        else{
            cout << "woman" <<endl;
        } 
        stones.clear();
    }
    system("pause");
    return 0;
}