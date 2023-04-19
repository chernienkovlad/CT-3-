#include <iostream>
#include <vector>

using namespace std;

void reverse_sort(vector<int>& vec);

int main()
{
    int N = 0;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < vec.size(); i++)
        cin >> vec[i];

    reverse_sort(vec);

    for (auto element : vec)
        cout << element << " ";

    return 0;
}

void reverse_sort(vector<int>& vec)
{
    int tmp = 0;
    for (int i = 0; i < vec.size()-1; i++)
    {
        for (int j = 0; j < vec.size()-i-1; j++)
        {
            if (vec[j] < vec[j+1])
            {
                tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
}
