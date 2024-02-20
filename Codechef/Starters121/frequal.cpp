#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> prime_numbers;

void sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime_numbers.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    int count = 0;
    if (n % 2 == 1) {
        cout << 1 << " ";
        count++;
    }
    int i = 0;
    while (count < n) {
        cout << prime_numbers[i] << " " << prime_numbers[i] << " ";
        i++;
        count += 2;
    }
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    sieve_of_eratosthenes(1000000);
    while (t--) {
        solve();
    }
}