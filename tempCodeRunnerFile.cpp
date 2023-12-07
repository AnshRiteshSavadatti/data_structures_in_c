#include <iostream>

#define MOD 1000000007

using namespace std;

int main() {
    long long result = 1234567; // Some large number

    // Perform operations and take modulo after each step
    result = (result % MOD + MOD) % MOD; // Ensure the result is positive

    // Print the result modulo 10^9+7
    cout << result << endl;

    return 0;
}
