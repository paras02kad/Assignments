#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,int>mp;
mp[0] = 1;
mp[0] = 2;

cout<<mp[0]<<endl;

return 0;
}