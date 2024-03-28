#include <set>
namespace std
{
    int findkth(int a[], int n, int k)
    {
        set<int> kc;
        for (int i = 0; i < n; i++)
        {
            if (kc.size() > k)
            {
                kc.insert(a[i]);
            }
            else
            {
                auto b = kc.cbegin();
                if( *b < a[i]){
                    kc.erase(b);
                    kc.insert(a[i]);
                }
            }
        }
        return *kc.cbegin();
    }
}