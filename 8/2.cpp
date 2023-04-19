#include <iostream>
#include <vector>

using namespace std;

void reverse_vector(vector<int>& vec);

int main()
{
    int N = 0;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < vec.size(); i++)
        cin >> vec[i];

    reverse_vector(vec);

    for (auto element : vec)
        cout << element << " ";

    return 0;
}

void reverse_vector(vector<int>& vec)
{
    int tmp = 0;
    for (int i = 0; i < vec.size() / 2; i++)
    {
        tmp = vec[i];
        vec[i] = vec[vec.size()-i-1];
        vec[vec.size()-i-1] = tmp;
    }
}
