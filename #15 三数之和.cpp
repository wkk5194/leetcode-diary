#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

vector< vector<int> > threeSum(vector<int>& nums) {
    // 把两个数的可能和放到hashmap里面，并且记录使用了哪两个数
    int len = nums.size();
    int sum;
    map< int, vector< pair<int,int> > > mymap;
    for(int i=0;i<len-1;i++)
        for(int j=i+1;j<len;j++)
        {
            sum = nums[i]+nums[j];
            if(mymap.count(sum) == 0)
            {
                vector< pair<int,int> > newVector;
                newVector.push_back(make_pair(i,j));
                mymap.insert(make_pair(sum,newVector));
            }else{
                mymap[sum].push_back(make_pair(i,j));
            }
        }
    vector< vector<int> > res;
    set< set<int> > myset;
    for(int i=0;i<len-2;i++)
    {
        if(mymap.count(0-nums[i])!=0)
        {
            for(int j=0;j<mymap[0-nums[i]].size();j++)
            {
                int first = mymap[0-nums[i]][j].first;
                int second = mymap[0-nums[i]][j].second;
                if(i==first || i==second) continue;
                set<int> sett;
                sett.insert(nums[i]);
                sett.insert(nums[first]);
                sett.insert(nums[second]);
                if(myset.count(sett)!=0) continue;
                myset.insert(sett);
                vector<int> tt;
                tt.push_back(nums[i]);
                tt.push_back(nums[first]);
                tt.push_back(nums[second]);
                res.push_back(tt);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> data;
    int n;
    int temp;
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> temp;
        data.push_back(temp);
    }
    vector< vector<int> > res;
    res = threeSum(data);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++) cout << res[i][j] << " ";
        cout << endl;
    }
}