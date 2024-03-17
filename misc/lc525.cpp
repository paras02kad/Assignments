//! Approach - 1 --> goes wrong at test case [0,0,1,0,0,0,1,1] gives ans as 1 instead of 6.

// class Solution
// {
// public:
//     int findMaxLength(vector<int> &nums)
//     {

//         int z = 0;
//         int o = 0;
//         int ans = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == 0)
//                 o++;
//             else
//                 z++;
//             if (z == o)
//                 ans = max(ans, i);
//         }

//         return ans;
//     }
// };

class Solution
{

public:
    int findMaxLength(vector<int> &nums)
    {

        int n nums.size();

        unordered_map<int, int> mp;

        int currSum = 0;

        mp[0] = -1;

        int result = 0;

        for (int i = 0; i < n; i++)
        {

            currSum += (nums[i] == 1) ? 1 : -1;

            if (mp.find(currSum) != mp.end())
            {

                result = max(result, imp[currSum]);
            }
            else
            {

                mp[currSum] = i;
            }
        }
        return result;
    }
};
