#include <bits/stdc++.h>

using namespace std;

int main(){
    int A, B, C;
    cin>>A>>B>>C;

    if(A>0 && B>0 && C>0 && A<11 && B<11 && C<11){
        if((A+B+C)<18)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}