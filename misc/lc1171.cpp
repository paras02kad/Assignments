/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//! Approach - 1
//! My Code --> Almost Correct
//! Inspired from hints --> By converting linked list to array
//! Problem lies near converting linked list according to the indexes accumulated in our index vector and then transforming that array to the given linked list.
//* Here we made use of unordered_sets as well as maps to do so

// class Solution
// {
// public:
//     ListNode *removeZeroSumSublists(ListNode *head)
//     {
//         vector<int> list;
//         unordered_map<int, int> mp;

//         while (head->next != NULL)
//             list.push_back(head->val);

//         mp[list[0]] = 0;

//         for (int i = 1; i < list.size(); i++)
//         {
//             list[i] += list[i - 1];
//             mp[list[i]] = i;
//         }
//         unordered_set<int> st;

//         for (int i = 0; i < list.size(); i++)
//         {
//             if (mp.find(list[i]) != mp.end())
//             {
//                 st.insert(i + 1);
//                 st.insert(mp[list[i]]);
//             }
//         }
//         int counter = 0;

//         while (head->next != NULL)
//         {
//             if (st.find(counter) != st.end())
//             {
//                 head->next = head->next->next;
//             }
//         }
//         return head;
//     }
// };

//! Approach - 2 -->(CORRECT ANSWER)
//! We didn't made use of vectors.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {

        int prefixSum = 0;
        unordered_map<int, ListNode *> mp;

        ListNode *dummy = new ListNode(0);
        mp[0] = dummy;

        dummy->next = head;

        while (head != NULL)
        {
            prefixSum += head->val;

            if (mp.find(prefixSum) != mp.end())
            {
                //* We got that value in our map than we will go for Deletion.
                ListNode *start = mp[prefixSum];
                ListNode *temp = start;
                int pSum = prefixSum;

                //* Deleting all the nodes which adds upto zero

                while (temp != head)
                {
                    temp = temp->next;
                    pSum += temp->val;
                    if (temp != head)
                        mp.erase(pSum);
                }
                start->next = head->next;
            }
            else
            {
                mp[prefixSum] = head;
            }

            head = head->next;
        }

        return dummy->next;
    }
};