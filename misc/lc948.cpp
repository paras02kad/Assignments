class Solution
{
public:
//! actually done by greedy method
    int bagOfTokensScore(vector<int> &tokens, int power)
    {

        int n = tokens.size();

        //* Sorting the given array
        sort(tokens.begin(), tokens.end());

        int answer = 0;

        int i = 0;
        int j = n - 1;
        int data = 0;

        while (i <= j)
        {

            if (power >= tokens[i])
            {
                answer++;
                power = power - tokens[i];
                i++;
                data = max(data, answer);
            }
            else if (answer > 0)
            {
                power = power + tokens[j];
                answer--;
                j--;
            }
            else
                return data;
        }
        return data;
    }
};