class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++)
            s.insert(nums2[i]);

        for (int i = 0; i < nums1.size(); i++) {
            if (s.find(nums1[i]) != s.end()) {
                ans.push_back(nums1[i]);
                s.erase(nums1[i]);
            }
        }

        return ans;
    }
};