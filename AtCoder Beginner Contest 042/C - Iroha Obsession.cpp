#include <bits/stdc++.h>

using namespace std;

bool containsDislikedDigits(int num, const set<int>& disliked_digits) {
    while (num > 0) {
        int digit = num % 10;
        if (disliked_digits.find(digit) != disliked_digits.end()) {
            return true;
        }
        num /= 10;
    }
    return false;
}

int findMinimumAmount(int N, const set<int>& disliked_digits) {
    int amount = N;
    while (containsDislikedDigits(amount, disliked_digits)) {
        amount++;
    }
    return amount;
}

int main() {
    int N, K;
    cin >> N >> K;

    set<int> dislike_digitals;

    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        dislike_digitals.insert(d);
    }
    
    int result = findMinimumAmount(N, dislike_digitals);
    cout << result << endl;

    return 0;
}
