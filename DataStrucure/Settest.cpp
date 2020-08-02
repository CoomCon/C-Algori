#include <iostream>
#include<set>

using namespace std;

int main()
{
    set<int> dataset;
    dataset.insert(1);
    dataset.insert(2);

    dataset.insert(3);dataset.insert(1);
    dataset.insert(4);

    int res = dataset.count(1);

    return 0;
}