class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &nums)
    {
        
        int max_ele = nums[0];
        int n = nums.size();
        vector<long long>ans(n,0);

        for(int i = 0;i<n;i++)
        ans[i]=nums[i];

        for (int i = 0; i < n; i++)
        {
            max_ele = max(max_ele,nums[i]);
             ans[i] += max_ele ;
        }

        
        for (int i = 0; i < n; i++)
        {
             ans[i] += ans[i-1];
        }
        
        return ans;
    }
};