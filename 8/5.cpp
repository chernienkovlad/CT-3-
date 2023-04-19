#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int letter_counter(string str, char ch);

int main()
{
    vector<string> vec(3);
    for (int i = 0; i < vec.size(); i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    for (auto string : vec)
        cout << string << endl;

    cout << "The number of 'o' in the first word: " << letter_counter(vec[0], 'o') << endl;

    return 0;
}

int letter_counter(string str, char ch)
{
    int count = 0;

    for (int i = 0; i < str.size(); i++)
        if (str[i] == 'o')
            count++;

    return count;
}
