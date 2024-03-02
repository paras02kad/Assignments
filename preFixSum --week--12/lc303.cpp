class NumArray
{
public:

/*
! overall TC = O(nums.size()) + O(2) + O(2*number of queries)
* overall SC = O(nums.size())
*/


    vector<int> preSum;

    NumArray(vector<int> &nums)
    {

        //! important to redeclare preSum array with size in order to avoid Runtime Error
        preSum = vector<int>(nums.size());
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            preSum[i] = preSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {

        if (left == 0)
            return preSum[right];
        else
            return (preSum[right] - preSum[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */