class Solution
{
public:

    //! First Approach
    //! TC -- O(m+n)
    //! SC -- O(n)

    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s;

        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < n; i++)
        {
            s.insert(nums2[i]);
        }

        for (int i = 0; i < m; i++)
        {
            if (s.find(nums1[i]) != s.end())
                return nums1[i];
        }
        return -1;
    }

    //! Second Approach
    //! First Approach
    //! TC -- O(m+n)
    //! SC -- O(1)

    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {

        int m = nums1.size();
        int n = nums2.size();
        int p = 0, q = 0;

        while (p < m && q < n)
        {
            if (nums1[p] == nums2[q])
                return nums1[p];

            else if (nums1[p] < nums2[q])
                p++;
            else
                q++;
        }
        return -1;
    }
};