#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <stdexcept>

using namespace std;

int main()
{
    map<string, int> m = {{"sania", 3}, {"vitek", 100500}, {"david", 1}};

    // m["sania"] = 5;
    // m["vitek"] = 100500;
    // m["david"] = 0;

    // m.erase("vitek");
    // cout << "vitek: " << m.count("vitek") << endl;

    try
    {
        if (m.at("belka") == 0)
            cout << "belochka prishla" << endl;
        else
            cout << "no squirrels here" << endl;
    }
    catch(exception& ex)
    {
        cout << "belok tut net! (" << ex.what() << ")" << endl;
    }

    // for (auto i : m)
    //     cout << i.first << ": " << i.second << endl;

    for (pair<string, int> i : m)
        cout << i.first << ": " << i.second << endl;

    return 0;
}
