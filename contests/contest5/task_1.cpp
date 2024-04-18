#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    multiset<int> box;
    vector<int> string(n);

    for (int x = 0; x < n; ++x)
    {
        cin >> string[x];
    }
    for (int x = 0; x < k; ++x)
    {
        box.insert(string[x]);
    }
    cout << *box.begin() << "\n";
    for (int x = k; x < n; ++x)
    {
        box.erase(box.find(string[x - k]));
        box.insert(string[x]);
        cout << *box.begin() << "\n";
    }
    return 0;
}