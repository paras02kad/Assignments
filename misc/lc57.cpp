//* Interval Based Question - 1;

// class Solution
// {
// public:
//! Brute Force Approach
//! TC  = O(n*n);
//! Don't know whats wrong with given code.

//     vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
//     {

//         for (int i = 0; i < intervals.size(); i++)
//         {
//             //* Case - 1;
//             if (intervals[i][1] < newInterval[0])
//                 continue;

//             //* Case - 2;
//             else if (intervals[i][0] > newInterval[1])
//             {
//                 intervals.insert(intervals.begin() + i, newInterval);
//                 return intervals;
//             }

//             //* Case - 3
//             else
//             {
//                  newInterval[0] = min(intervals[i][0], newInterval[0]);
//                  newInterval[1] = max(intervals[i][1], newInterval[1]);
//                 intervals.erase(intervals.begin()+i);
//                 return intervals;
//             }
//         }
//         intervals.push_back(newInterval);
//         return intervals;
//     }
// };

//! Brute Force Approach
//! TC  = O(n*n);
//! This code works somehow.

// class Solution
// {
// public:
//     //! Brute Force Approach
//     vector<vector<int>> insert(vector<vector<int>> &intervals,
//                                vector<int> &newInterval)
//     {

//         int i = 0;
//         while (i < intervals.size())
//         {
//             //* Case - 1;
//             if (intervals[i][1] < newInterval[0])
//                 i++;

//             //* Case - 2;
//             else if (intervals[i][0] > newInterval[1])
//             {
//                 intervals.insert(intervals.begin() + i, newInterval);
//                 return intervals;
//             }

//             //* Case - 3
//             else
//             {
//                 newInterval[0] = min(intervals[i][0], newInterval[0]);
//                 newInterval[1] = max(intervals[i][1], newInterval[1]);
//                 intervals.erase(intervals.begin() + i);
//             }
//         }
//         intervals.push_back(newInterval);
//         return intervals;
//     }
// };

//! optimized Approach.
//! TC  = O(n);
//! SC = O(n);

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();

        vector<vector<int>> result;

        while (i < n) {

            if (intervals[i][1] < newInterval[0])
                result.push_back(intervals[i]);
            else if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
            i++;
        }
        result.push_back(newInterval);
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
