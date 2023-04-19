#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void new_bus_request();
void buses_for_stop_request();
void stops_for_bus_request();
void all_buses_request();

map<string, vector<string>> m_buses;
map<string, vector<string>> m_stops;

int main()
{
    int requests_count = 0;
    cin >> requests_count;

    string request;
    getchar();

    for (int i = 0; i < requests_count; i++)
    {
        cin >> request;

        if      (request == "NEW_BUS")         new_bus_request();
        else if (request == "BUSES_FOR_STOP")  buses_for_stop_request();
        else if (request == "STOPS_FOR_BUS")   stops_for_bus_request();
        else if (request == "ALL_BUSES")       all_buses_request();
    }

    return 0;
}

void new_bus_request()
{
    string bus_name;
    cin >> bus_name;

    vector<string> v_stops;
    m_buses.insert({bus_name, v_stops});

    int stops_count;
    cin >> stops_count;

    string stop_name;
    for (int i = 0; i < stops_count; i++)
    {
        cin >> stop_name;
        m_buses[bus_name].push_back(stop_name);

        if (!m_stops.count(stop_name))
        {
            vector<string> v_buses;
            m_stops.insert({stop_name, v_buses});
        }
        m_stops[stop_name].push_back(bus_name);
    }
}

void buses_for_stop_request()
{
    string stop_name;
    cin >> stop_name;

    if (!m_stops.count(stop_name))
        cout << "No stop" << endl;
    else
    {
        cout << "Stop " << stop_name << ": ";
        for (auto bus_name : m_stops[stop_name])
            cout << bus_name << " ";
        cout << endl;
    }
}

void stops_for_bus_request()
{
    string bus_name;
    cin >> bus_name;

    if (!m_buses.count(bus_name))
        cout << "No bus" << endl;
    else
    {
        for (auto stop_name : m_buses[bus_name])
        {
            cout << "Stop " << stop_name << ": ";
            int flag_count = 0;
            for (auto stops_bus_name : m_stops[stop_name])
            {
                if (stops_bus_name != bus_name)
                {
                    cout << stops_bus_name << " ";
                    flag_count++;
                }
            }
            if (flag_count)
                cout << endl;
            else
                cout << "no interchange" << endl;
        }
    }
}

void all_buses_request()
{
    if (!m_buses.size())
        cout << "No buses" << endl;
    else
    {
        for (auto bus_pair : m_buses)
        {
            cout << "Bus " << bus_pair.first << ": ";
            for (auto stop_name : bus_pair.second)
                cout << stop_name << " ";
            cout << endl;
        }
    }
}
