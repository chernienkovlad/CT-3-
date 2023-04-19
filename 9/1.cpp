#include <iostream>
#include <string>
#include <map>

using namespace std;

void is_anagramm(pair<string, string> words_pair);
map<char, int> get_letters_map(string str);

int main()
{
    int N = 0;
    cin >> N;

    pair<string, string> p;
    for (int i = 0; i < N; i++)
    {
        cin >> p.first >> p.second;
        is_anagramm(p);
    }
    
    return 0;
}

void is_anagramm(pair<string, string> words_pair)
{
    if (get_letters_map(words_pair.first) == get_letters_map(words_pair.second))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

map<char, int> get_letters_map(string str)
{
    map<char, int> tmp_map;
    for (auto letter : str)
    {
        if (tmp_map.count(letter))
            tmp_map[letter]++;
        else
            tmp_map.insert({letter, 1});
    }

    return tmp_map;
}
