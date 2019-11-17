#include <algorithm>
#include <numeric>
#include "Ran.h"

using namespace std;

bool cmp(const Nocase &a, const Nocase &b)
{
    return a.num < b.num;
}

int main(void)
{
    std::vector<Nocase> n;
    n.push_back(Nocase(17));
    n.push_back(Nocase(80));
    n.push_back(Nocase(30));

    std::sort(n.begin(), n.end(), [](const Nocase &a, const Nocase &b) {
        return a.num < b.num;
    });//比較関数をラムダ式で作る

    for (auto itr : n)
    {
      cout << itr.num << endl;
    }

    return 0;
}
