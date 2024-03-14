class Solution
{
    //! Exactly same as subArray  sum equal to k ie(lc560)
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }

        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == goal)
                answer++;

            int rem = nums[i] - goal;

            if (mp.find(rem) != mp.end())
                answer += mp[rem];

            mp[nums[i]]++;
        }
        return answer;
    }
};