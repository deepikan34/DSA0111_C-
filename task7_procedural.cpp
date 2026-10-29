#include <iostream>
using namespace std;

const long long MIN_BALANCE = 5000;

bool canTravel(long long balance, long long fare)
{
    return balance - fare >= MIN_BALANCE;
}

bool deduct(long long &balance, long long fare)
{
    if (fare < 0 || !canTravel(balance, fare))
        return false;

    balance -= fare;
    return true;
}

int main()
{
    long long balance = 10000;
    long long fare = 3600;

    if (deduct(balance, fare))
        cout << "Fare deducted successfully\n";
    else
        cout << "Travel denied\n";

    cout << "Remaining balance: Rs " << balance / 100 << '\n';

    return 0;
}