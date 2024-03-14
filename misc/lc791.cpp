
//! Approach - 1 --> (CORRECT APPROACH)
//! We made use of UnorderedMap to keep record of char with their frequencies and then check according to the order string.

//! Asymptomatic Analysis
//* TC = O(m+n+k) --> k = left over chars in string
//* SC = O(m)

class Solution
{
public:
    string customSortString(string order, string s)
    {

        int n = order.length();
        int m = s.length();

        unordered_map<char, int> mp;

        //! Filing in the map according to the string s
        for (int i = 0; i < m; i++)
        {
            mp[s[i]]++;
        }

        string ans = "";

        //! checking according to the order string.
        //* Case - 1 --> Searching for map for the char that occurs in order string.
        for (int i = 0; i < n; i++)
        {
            char tata = order[i];

            if (mp.find(tata) != mp.end())
            {
                while (mp[tata] != 0)
                {
                    ans += tata;
                    mp[tata]--;
                }
                //* if frequencies are zero then we are removing those elements from map.

                if (mp[tata] == 0)
                    mp.erase(tata);
            }
        }

        //* Case - 2 --> If the map didn't have the char which belongs to the order then next remaining elements of string s.

        for (auto exe : mp)
        {
            while (exe.second != 0)
            {
                ans += exe.first;
                exe.second--;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> index(26, -1);

        // Assigning index values based on the order string
        for (int i = 0; i < order.length(); i++)
        {
            char ch = order[i];
            index[ch - 'a'] = i;
        }

        // Comparator function for sorting based on custom order
        auto myComparator = [&index](char ch1, char ch2)
        {
            return index[ch1 - 'a'] < index[ch2 - 'a'];
        };

        // Sorting the string 's' based on custom order
        sort(begin(s), end(s), myComparator);

        return s;
    }
};