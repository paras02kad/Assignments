class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while (i < j && s[i] == s[j])
        {
            if (s[i] == s[j])
            {
                if (j - i == 1)
                    return 0;

                while (s[i] == s[i + 1] && i < j)
                {
                    //! to get through the "abbbbbbbbbbbbbbbbbbba" test case because without the underlying condition i would go on increasing and will reach till j and then j will run thus resulting ain a negative value thus once i goes near j.j Shouldnt run in that case and give final output.
                    i++;
                    if (j - i == 1)
                        return 0;
                }

                while (s[j] == s[j - 1])
                    j--;
            }
            i++;
            j--;
        }
        return (j - i + 1);
    }
};