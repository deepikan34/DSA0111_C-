#include <iostream>
using namespace std;

class SmartCard
{
private:
    long long balance;
    const long long MIN_BALANCE = 5000;

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
    long long fare = 3600;

    if (card.deduct(fare))
        cout << "Fare deducted successfully\n";
    else
        cout << "Travel denied\n";

    cout << "Remaining balance: Rs "
         << card.getBalance() / 100 << '\n';

    return 0;
}