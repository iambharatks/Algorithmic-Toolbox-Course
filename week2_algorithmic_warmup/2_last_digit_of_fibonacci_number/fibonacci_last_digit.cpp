#include <bits/stdc++.h>

using namespace std;

int get_fibonacci_last_digit_naive(int n)
{
    vector<long long> F;
    F.push_back(0);
    F.push_back(1);
    for(int i = 2 ; i <= n ; i++)
        F.push_back( F[i-1]%10 + F[i-2]%10 );

    return F[n]%10;
}

int main() {
    int n;
    cin>>n;
    cout<<get_fibonacci_last_digit_naive(n);
    return 0;
}
