
#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };

const long long MIN_BALANCE = 5000; // Rs 50 in paise
const int PEAK_SURCHARGE = 20;
const int WEEKEND_DISCOUNT = 10;

const long long FARES[] = {
    1000, 2000, 3000, 6000
}; // Rs 10, 20, 30, 60 in paise

long long calculateFare(Zone zone, bool peak, bool weekend) {
    long long fare = FARES[static_cast<int>(zone)];

    if (weekend) {
        fare -= fare * WEEKEND_DISCOUNT / 100;
    } else if (peak) {
        fare += fare * PEAK_SURCHARGE / 100;
    }

    return fare;
}

class MonthlyPass {
private:
    Zone zone1, zone2;

public:
    MonthlyPass(Zone first, Zone second)
        : zone1(first), zone2(second) {}

    bool covers(Zone zone) const {
        return zone == zone1 || zone == zone2;
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long initialBalance)
        : balance(initialBalance) {}

    bool travel(long long fare) {
        if (fare < 0 || balance - fare < MIN_BALANCE)
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

void testJourney(
    SmartCard& card,
    const MonthlyPass& pass,
    Zone zone,
    bool peak,
    bool weekend
) {
    long long fare = pass.covers(zone)
                   ? 0
                   : calculateFare(zone, peak, weekend);

    cout << "Fare: Rs " << fare / 100.0 << " | ";

    if (card.travel(fare))
        cout << "Journey Allowed";
    else
        cout << "Journey Denied";

    cout << " | Balance: Rs "
         << card.getBalance() / 100.0 << '\n';
}

int main() {
    cout << fixed << setprecision(2);

    SmartCard card(20000); // Initial balance Rs 200

    // Monthly pass covers Outer and Airport zones
    MonthlyPass pass(Zone::Outer, Zone::Airport);

    cout << "Metro Smart Card - Task 12\n";

    // Inner zone, weekday peak
    testJourney(card, pass, Zone::Inner, true, false);

    // Airport zone, weekend discount
    // Pass covers Airport, so fare is zero
    testJourney(card, pass, Zone::Airport, true, true);

    // Middle zone, weekend discount
    testJourney(card, pass, Zone::Middle, true, true);

    // Outer zone, covered by monthly pass
    testJourney(card, pass, Zone::Outer, false, false);

    return 0;
}
