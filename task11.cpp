#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr long long MIN_BALANCE = 5000;
constexpr int PEAK_SURCHARGE = 20;
constexpr long long BASE_FARE[] = {1000, 2000, 3000};

long long calculateFare(Zone zone, bool peak)
{
    long long fare = BASE_FARE[static_cast<int>(zone)];

    if (peak)
        fare += fare * PEAK_SURCHARGE / 100;

    return fare;
}

class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long initialBalance)
    {
        balance = initialBalance;
    }

    bool canTravel(long long fare) const
    {
        return fare >= 0 &&
               balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare)
    {
        if (!canTravel(fare))
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const
    {
        return balance;
    }
};

int main()
{
    SmartCard card(10000);

    Zone zone = Zone::Outer;
    bool peak = true;

    long long fare = calculateFare(zone, peak);

    cout << fixed << setprecision(2);

    cout << "Metro Smart Card Report\n";
    cout << "Fare: Rs " << fare / 100.0 << '\n';

    if (card.deduct(fare))
        cout << "Journey Status: Allowed\n";
    else
        cout << "Journey Status: Denied\n";

    cout << "Remaining Balance: Rs "
         << card.getBalance() / 100.0 << '\n';

    return 0;
}