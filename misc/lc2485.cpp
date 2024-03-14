class Solution
{
public:
    int pivotInteger(int n)
    {
        //! Always remember to Declare variables with some initial value to avoid garbage value allocation to it.
        //* We made use of preFix sum array.
        
        vector<int> preFix(n + 1, 0);
        int checker = 0;
        int data = 0;
        for (int i = 1; i <= n; i++)
        {
            data += i;
            preFix[i] = data;
        }

        for (int i = n; i > 0; i--)
        {
            checker += i;
            if (preFix[i] == checker)
                return i;
        }

        return -1;
    }
};