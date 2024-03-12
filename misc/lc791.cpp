class Solution
{
public:
    string customSortString(string order, string s)
    {
        int n = order.length();
        int m = s.length();

        unordered_map<char, int> st;

        for (int i = 0; i < m; i++)
        {
            st[s[i]]++;
        }

        string ans = "";

        for (int i = 0; i < m; i++)
        {
            char tata = order[i];
            if (st.find(tata) != st.end())
            {
                ans += tata;
                st[tata]--;
            }

            else
                ans += s[i];
        }
        return ans;
    }
};





class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> index(26, -1);

        // Assigning index values based on the order string
        for (int i = 0; i < order.length(); i++) {
            char ch = order[i];
            index[ch - 'a'] = i;
        }

        // Comparator function for sorting based on custom order
        auto myComparator = [&index](char ch1, char ch2) {
            return index[ch1 - 'a'] < index[ch2 - 'a'];
        };

        // Sorting the string 's' based on custom order
        sort(begin(s), end(s), myComparator);

        return s;
    }
};