#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s = {1, 5, 2};

    s.insert(3);
    s.erase(1);
    cout << s.count(1) << endl;

    for (auto i : s)
        cout << i << endl;

    return 0;
}
