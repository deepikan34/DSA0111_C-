
#include <iostream>
#include <string>
using namespace std;

// SmartCard class
class SmartCard {
private:
    long long balancePaise;

public:
    SmartCard(long long balance) {
        balancePaise = balance;
    }

    long long getBalance() {
        return balancePaise;
    }

    bool canTravel(long long farePaise) {
        return balancePaise - farePaise >= 5000;
    }

    bool deduct(long long farePaise) {
        if (canTravel(farePaise)) {
            balancePaise -= farePaise;
            return true;
        }
        return false;
    }
};

// Passenger class
class Passenger {
public:
    string name;
    string category;

    Passenger(string n, string c) {
        name = n;
        category = c;
    }
};

// Journey class
class Journey {
public:
    string zone;
    int hour;

    Journey(string z, int h) {
        zone = z;
        hour = h;
    }

    bool isPeakHour() {
        return (hour >= 8 && hour < 10) ||
               (hour >= 17 && hour < 20);
    }
};

// FareTable class
class FareTable {
public:
    long long calculateFare(string zone, bool peak) {
        long long fare = 0;

        if (zone == "Inner")
            fare = 1000;
        else if (zone == "Middle")
            fare = 2000;
        else if (zone == "Outer")
            fare = 3000;
        else
            return -1;

        if (peak)
            fare += fare * 20 / 100;

        return fare;
    }
};

int main() {
    Passenger p("Deepika", "Regular");
    SmartCard card(10000);
    Journey journey("Outer", 9);
    FareTable table;

    long long fare = table.calculateFare(
        journey.zone, journey.isPeakHour()
    );

    cout << "Passenger: " << p.name << '\n';
    cout << "Zone: " << journey.zone << '\n';

    if (fare == -1) {
        cout << "Invalid zone\n";
    } else if (card.deduct(fare)) {
        cout << "Fare: Rs " << fare / 100
             << '.' << (fare % 100 < 10 ? "0" : "")
             << fare % 100 << '\n';

        cout << "Remaining balance: Rs "
             << card.getBalance() / 100 << '\n';
    } else {
        cout << "Journey denied: minimum balance rule\n";
    }

    return 0;
}
