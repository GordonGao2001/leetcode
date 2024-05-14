#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::cin;

class Solution{
    public:
        vector<int> twosum(vector<int>& nums, int target){
            int i=target;
            vector<int> res;
            for(auto it=nums.begin(); it<nums.end()-1;++it)
            {
                for(auto it2 = it+1;it2!=nums.end();++it2)
                {
                    i = i-*it2;
                    cout<< i << '\n';
                    if(i==0)
                    {
                        res.push_back(it-nums.begin());
                        res.push_back(it2-nums.begin());
                        return res;
                    }
                    i=target-*it;
                }
            }
            return res;
        }
};


int main(int argc, const char * argv[])
{
    Solution s;
    vector<int> sums{3,2,3};
    vector<int> res_index = s.twosum(sums, 6);
    for(auto i:res_index)
        cout<< i << '\t';
    return 0;
}