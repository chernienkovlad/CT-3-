#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;

void f(list<int> l)
{

}

int main()
{  
    list<int> l;
    for (int i = 0; i < 10000000; i++)
        l.push_back(i);

    auto start = steady_clock::now();
    f(l);
    auto fin = steady_clock::now();

    auto dur = fin - start;
    cout << duration_cast<milliseconds>(dur).count();
    

    return 0;
}
