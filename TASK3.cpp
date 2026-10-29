
#include <iostream>
#include <iomanip>
#include <climits>
#include <limits>
using namespace std;

int main() {
    // Display sizes of data types
    cout << "Data Type Sizes (bytes)\n";
    cout << "bool: " << sizeof(bool) << '\n';
    cout << "char: " << sizeof(char) << '\n';
    cout << "int: " << sizeof(int) << '\n';
    cout << "unsigned int: " << sizeof(unsigned int) << '\n';
    cout << "long long: " << sizeof(long long) << '\n';
    cout << "float: " << sizeof(float) << '\n';
    cout << "double: " << sizeof(double) << "\n\n";

    // Integer ranges
    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "INT_MIN: " << INT_MIN << '\n';
    cout << "LONG_LONG_MAX: " << LLONG_MAX << "\n\n";

    // Type compatibility
    int a = 7, b = 2;
    double result1 = a / b;
    double result2 = static_cast<double>(a) / b;
    bool flag = 5;

    cout << "Integer division: " << result1 << '\n';
    cout << "Floating division: " << result2 << '\n';
    cout << "Boolean value: " << flag << "\n\n";

    // Money precision comparison
    double rupees = 0.0;
    long long paise = 0;

    for (int i = 0; i < 10; i++) {
        rupees += 0.10;
        paise += 10;
    }

    cout << setprecision(17);
    cout << "Double total: " << rupees << '\n';
    cout << "Paise total: " << paise << " paise\n\n";

    // Network collection: 3 million journeys at Rs 30 each
    long long totalPaise = 3000000LL * 3000;
    cout << "Network collection: Rs "
         << totalPaise / 100 << '\n';

    cout << "Maximum int: " << INT_MAX << '\n';

    return 0;
}
