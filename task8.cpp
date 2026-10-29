#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const long long MIN_BALANCE = 5000;

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
    long long balance = readNumber("Enter balance in rupees: ");
    long long zone = readNumber("Enter zone (1=Inner, 2=Middle, 3=Outer): ");
    long long hour = readNumber("Enter journey hour (0-23): ");

    if (balance < 0 || zone < 1 || zone > 3 ||
        hour < 0 || hour > 23)
    {
        cout << "Invalid input details.\n";
        return 0;
    }

    long long baseFare[] = {1000, 2000, 3000};
    long long fare = baseFare[zone - 1] * 100;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += fare * 20 / 100;

    long long balancePaise = balance * 100;

    cout << fixed << setprecision(2);

    cout << "\n----- METRO JOURNEY REPORT -----\n";
    cout << "Zone: " << zone << '\n';
    cout << "Peak hour: " << (peak ? "Yes" : "No") << '\n';
    cout << "Fare: Rs " << fare / 100.0 << '\n';

    if (balancePaise - fare >= MIN_BALANCE)
    {
        balancePaise -= fare;
        cout << "Status: Journey allowed\n";
    }
    else
    {
        cout << "Status: Journey denied (low balance)\n";
    }

    cout << "Remaining balance: Rs "
         << balancePaise / 100.0 << '\n';

    return 0;
}