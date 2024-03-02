class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {

//* Making changes in the orignal array to get 0-indexed array

        for (int i = 0; i < bookings.size(); i++)
        {
            bookings[i][0] = bookings[i][0] - 1;
            bookings[i][1] = bookings[i][1] - 1;
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < bookings.size(); i++)
        {
            int a = bookings[i][0];
            int b = bookings[i][1];

            if (a == b)
            {
                ans[b] += bookings[i][2];
            }
            else
            {
                ans[a] += bookings[i][2];
            }

            if ((b + 1) == n) continue;
            else
                ans[b + 1] -= bookings[i][2];
        }


  //! Calculating the preFixSum array

        for (int i = 1; i < n; i++)
        {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};