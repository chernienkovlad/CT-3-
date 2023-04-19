#include <iostream>
#include <vector>

using namespace std;

void find_element(vector<int>& vec, int n);

int main()
{
    int N = 0, n = 0;
    cin >> N >> n;

    vector<int> vec(N);
    for (int i = 0; i < vec.size(); i++)
        cin >> vec[i];

    find_element(vec, n);

    return 0;
}

void find_element(vector<int>& vec, int n)
{
    int id = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > n)
        {
            id = i;
            break;
        }
    }

    for (int i = 0; i < vec.size(); i++)
        if (vec[i] > n && vec[i] < vec[id])
            id = i;

    cout << id << endl;
}
