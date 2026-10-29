#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const long long MIN_BALANCE = 5000;

bool isPeak(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(int zone, int hour)
{
    long long baseFare;

    switch (zone)
    {
        case 1: baseFare = 1000; break;
        case 2: baseFare = 2000; break;
        case 3: baseFare = 3000; break;
        default: return -1;
    }

    if (isPeak(hour))
        baseFare += baseFare * 20 / 100;

    return baseFare;
}

long long readNumber(const char* message)
{
    long long value;

    while (true)
    {
        cout << message;

        if (cin >> value)
            return value;

        cout << "Invalid input! Enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    long long recharge = readNumber("Enter initial balance (Rs): ");

    if (recharge < 0 ||
        recharge > numeric_limits<long long>::max() / 100)
    {
        cout << "Invalid balance!\n";
        return 0;
    }

    long long balance = recharge * 100;
    long long totalFare = 0;

    int n = static_cast<int>(readNumber("Enter number of journeys: "));

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of journeys!\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "\nJourney " << i << '\n';

        int zone = static_cast<int>(
            readNumber("Enter zone (1=Inner, 2=Middle, 3=Outer): "));

        int hour = static_cast<int>(
            readNumber("Enter hour (0-23): "));

        if (zone < 1 || zone > 3 || hour < 0 || hour > 23)
        {
            cout << "Invalid journey details!\n";
            continue;
        }

        long long fare = calculateFare(zone, hour);

        cout << fixed << setprecision(2);

        if (balance - fare >= MIN_BALANCE)
        {
            balance -= fare;
            totalFare += fare;

            cout << "Fare: Rs " << fare / 100.0 << '\n';
            cout << "Journey allowed\n";
        }
        else
        {
            cout << "Journey denied (minimum Rs 50 must remain)\n";
        }

        cout << "Balance: Rs " << balance / 100.0 << '\n';
    }

    cout << "\n----- FINAL REPORT -----\n";
    cout << "Total fare paid: Rs " << totalFare / 100.0 << '\n';
    cout << "Final balance: Rs " << balance / 100.0 << '\n';

    return 0;
}