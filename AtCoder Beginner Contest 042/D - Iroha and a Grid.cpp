#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

// Função para calcular a potência modular
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Função para calcular o fatorial e o fatorial inverso até n
void computeFactorials(int n, vector<long long>& fact, vector<long long>& invFact, int mod) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[n] = modPow(fact[n], mod - 2, mod);
    for (int i = n - 1; i > 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }
}

// Função para calcular a combinação C(n, k) % mod
long long comb(int n, int k, const vector<long long>& fact, const vector<long long>& invFact, int mod) {
    if (k > n || k < 0) return 0;
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<long long> fact(H + W), invFact(H + W);
    computeFactorials(H + W - 2, fact, invFact, MOD);

    long long result = 0;
    for (int i = 0; i < H - A; ++i) {
        long long ways1 = comb(i + B - 1, i, fact, invFact, MOD);
        long long ways2 = comb((H - 1 - i) + (W - 1 - B), H - 1 - i, fact, invFact, MOD);
        result = (result + ways1 * ways2 % MOD) % MOD;
    }

    cout << result << endl;
    return 0;
}
