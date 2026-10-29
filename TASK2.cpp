
#include <iostream>
using namespace std;

// Constants: fares stored in paise
constexpr int INNER_FARE_PAISE = 1000;
constexpr int MIDDLE_FARE_PAISE = 2000;
constexpr int OUTER_FARE_PAISE = 3000;

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

// enum class safely identifies each zone
enum class Zone {
    Inner,
    Middle,
    Outer
};

int getBaseFare(Zone zone) {
    switch (zone) {
        case Zone::Inner:
            return INNER_FARE_PAISE;

        case Zone::Middle:
            return MIDDLE_FARE_PAISE;

        case Zone::Outer:
            return OUTER_FARE_PAISE;
    }

    return 0;
}

int calculateFare(Zone zone, bool peak) {
    int fare = getBaseFare(zone);

    if (peak) {
        fare += fare * PEAK_SURCHARGE_PERCENT / 100;
    }

    return fare;
}

int main() {
    Zone selectedZone = Zone::Outer;
    bool peak = true;

    int fare = calculateFare(selectedZone, peak);

    cout << "Base fare: Rs "
         << getBaseFare(selectedZone) / 100 << '\n';

    cout << "Peak surcharge: "
         << PEAK_SURCHARGE_PERCENT << "%\n";

    cout << "Total fare: Rs "
         << fare / 100 << '.'
         << (fare % 100 < 10 ? "0" : "")
         << fare % 100 << '\n';

    cout << "Minimum balance: Rs "
         << MIN_BALANCE_PAISE / 100 << '\n';

    return 0;
}
