#include <iostream>
#include <vector>

using namespace std;

double get_average_mark(vector<double>& marks);
void print_smart_students(vector<double>& marks);

int main()
{
    int N = 0;
    cin >> N;

    vector<double> marks(N); 
    for (int i = 0; i < marks.size(); i++)
        cin >> marks[i];

    print_smart_students(marks);

    return 0;
}

double get_average_mark(vector<double>& marks)
{
    double average = 0;
    for (auto mark : marks)
        average += mark;
    average /= marks.size();

    return average;
}

void print_smart_students(vector<double>& marks)
{
    double average = get_average_mark(marks);
    for (int i = 1; i <= marks.size(); i++)
        if (marks[i-1] > average) cout << i << " ";
}
