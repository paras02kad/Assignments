class Solution
{
public:

/*
* First approach
! TC = O(3n) + O(5)
* SC = O(2n);
*/

    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();

        int arr[n];
        int brr[n];

        arr[0] = nums[0];
        brr[n-1] = nums[n-1];

        for (int i = 1; i < n; i++)
        {
            arr[i] = arr[i - 1] + nums[i];
        }

        for (int i = (n - 2); i >= 0; i--)
        {
            brr[i] = brr[i + 1] + nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == brr[i])
                return i;
        }
        return -1;
    }

/*
! TC = O(2n) + O(2)
* SC = O(2);
*/

     int pivotIndex(vector<int>& nums)
     {
        int leftsum = 0;
        int rightsum = 0;

        for(int i = 0;i<nums.size();i++)
        {
            rightsum = rightsum + nums[i];
        }

        for(int i = 0;i<nums.size();i++)
        {
            rightsum = rightsum - nums[i];

            if(leftsum == rightsum)
            {
                return i;
            }

            leftsum = leftsum + nums[i];
        }
        return -1;

    }
};


   
