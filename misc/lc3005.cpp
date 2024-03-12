class Solution
{
public:
//! first and probably worst approach; 
//! Better TC is achieved using maps and sets
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> freq(101, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int answer = 0;
        int counter = 0;

        for (int i = 0; i < freq.size(); i++)
        {
            if (answer < freq[i])
            {
                answer = max(answer, freq[i]);
            }
        }
        if (answer == 1)
            return nums.size();
        else

            for (int i = 0; i < freq.size(); i++)
            {
                if (freq[i] == answer)
                    counter += freq[i];
            }

        return counter;
    }
};