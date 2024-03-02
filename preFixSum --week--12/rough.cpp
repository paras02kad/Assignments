#include <iostream>
#include <vector>

using namespace std;
int main()
{
    //! [-2, 0, 3, -5, 2, -1]

    vector<int> up;

    up.push_back(-2);
    up.push_back(0);
    up.push_back(3);
    up.push_back(-5);
    up.push_back(2);
    up.push_back(-1);

    vector<int> preSum(up.size(), 0);

    auto ut = up.begin();
    auto lt = preSum.begin();

    (*lt) = (*ut);

    for (ut = up.begin(); ut != up.end(); ++ut)
    {
        cout << *ut << " ";
    }
    cout << endl;

    for (ut = up.begin()+1,lt = preSum.begin()+1; ut != up.end() && lt != preSum.end(); ++ut, ++lt)
    {
        (*lt) = (*ut) + *(lt-1);
    }

    for (lt = preSum.begin(); lt != preSum.end(); ++lt)
    {
        cout << *lt << " ";
    }

    return 0;
}