class Solution
{
    //! did it after seeing hints could be done by two pointer also;
    
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();

        vector<int> subArr(n - k,0);

        int total = 0;
        int sub_arr=0;

        for (int i = 0; i < n; i++)
        {
            total += cardPoints[i];
            if (i < n - k)
            {
                subArr[i] = cardPoints[i];
                sub_arr += cardPoints[i];
            }
        }

        int data = total-sub_arr;

        for (int i = 0; i < k; i++)
        {
            sub_arr=sub_arr + cardPoints[n-k+i] - cardPoints[i];
            data = max(data,(total-sub_arr));
            
        }

        return data;
    }
};