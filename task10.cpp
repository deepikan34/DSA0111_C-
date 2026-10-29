#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

void compareTotals(long long n)
{
    double totalRupees = 0.0;
    long long totalPaise = 0;

    for (long long i = 0; i < n; i++)
    {
        totalRupees += 0.10;
        totalPaise += 10;
    }

    cout << "\nJourneys: " << n << '\n';
    cout << setprecision(15);
    cout << "Double total: Rs " << totalRupees << '\n';
    cout << fixed << setprecision(2);
    cout << "Integer-paise total: Rs "
         << totalPaise / 100.0 << '\n';

    cout << setprecision(10);
    cout << "Difference: Rs "
         << totalRupees - totalPaise / 100.0 << '\n';

    cout.unsetf(ios::floatfield);
}

int main()
{
    compareTotals(20000);
    compareTotals(500000);
    compareTotals(3000000);

    long long networkTotalPaise = 3000000LL * 3000;

    cout << "\n----- NETWORK TOTAL -----\n";
    cout << "Total paise: " << networkTotalPaise << '\n';
    cout << "Total rupees: Rs "
         << fixed << setprecision(2)
         << networkTotalPaise / 100.0 << '\n';

    if (networkTotalPaise > INT_MAX)
        cout << "int overflow: Yes, total exceeds INT_MAX\n";
    else
        cout << "int overflow: No\n";

    cout << "long long stores the total safely.\n";

    return 0;
}