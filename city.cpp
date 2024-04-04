// given a list of cities with their population, like NY:5M, SF:7M, LA:8M, generate city name by a probaility based on their populiation
// e.g., there is a 7/(5+7+8) to generate 'SF'
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
string city(map<string, int> &cities)
{
    // caculate the range of population in the total range for each city
    // store the ranges in a set,
    //  create a mapping between the ranges to the name of cities
    set<int> ranges;
    vector<string> from_index_to_city;
    int prev = 0;
    int counter = 0;
    int total = 0;
    for (auto i = cities.cbegin(); i != cities.cend(); i++)
    {
        ranges.insert(i->second + prev);
        counter++;
        prev = i->second;
        from_index_to_city.push_back(i->first);
        total += i->second;
    }
    if(total == 0) return string("");
    int r = rand() % total;
    return from_index_to_city[*ranges.upper_bound(r)];
}