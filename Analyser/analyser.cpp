// Conversion of analyser lab into C++ by Erik Companhone Andrade de Almeida. 10/8/22.

#include <iostream>
#include "StringData.h"
#include <cmath>

using namespace std;

int linearSearch(vector<string> dataSet, string element)  // This function does a linear search in the data set.
{
    for (int i = 0; i < dataSet.size(); i++)
    {
        if (dataSet.at(i) == element)
            return i;
    }
    return -1;
}

int binarySearch(vector<string> dataSet, string element)  // This function does a binary search in the data set.
{
    int min = 0;
    int max = dataSet.size() - 1;
    int mid = min + (max - min)/2;

    while (min <= max)
    {
        if (element == dataSet.at(mid))
        {
            return mid;
        }
        else if (element < dataSet.at(mid))
        {
            max = mid - 1;
            mid = min + (max - min)/2;
        }
        else if(element > dataSet.at(mid))
        {
            min = mid + 1;
            mid = min + (max - min)/2;
        }
    }
    return -1;
}

int main()
{
    vector <string> elementVector = {"not_here", "mzzzz", "aaaaa"};
    vector <string> dataSet = getStringData();
    int index;
    long long int time, start, end;

    for (int i = 0; i < elementVector.size(); i++)
    {
        //Binary search
        start = systemTimeNanoseconds();
        index = binarySearch(dataSet, elementVector.at(i));
        end = systemTimeNanoseconds();
        time = end - start;
        cout << "Binary search for: \"" << elementVector.at(i) << "\". Index is: " << index << ". Performed in: "  << time << " nanoseconds." << endl;

        //Linear search
        start = systemTimeNanoseconds();
        index = linearSearch(dataSet, elementVector.at(i));
        end = systemTimeNanoseconds();
        time = end - start;
        cout << "Linear search for: \"" << elementVector.at(i) << "\". Index is: " << index << ". Performed in: " << time << " nanoseconds." << endl;
        cout << endl;
    }
    return 0;
}
