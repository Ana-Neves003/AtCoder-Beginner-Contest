#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    
    vector<string> strings(N);
    for (int i = 0; i < N; ++i) {
        cin >> strings[i];
    }
    
    sort(strings.begin(), strings.end());
    
    string result;
    for (const string &str : strings) {
        result += str;
    }

    cout << result << endl;
    
    return 0;
}
