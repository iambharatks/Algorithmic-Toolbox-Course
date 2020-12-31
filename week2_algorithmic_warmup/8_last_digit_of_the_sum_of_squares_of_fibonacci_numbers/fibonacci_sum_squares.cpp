#include <bits/stdc++.h>

using namespace std;
vector<long long> F;
void fibonacci_sum(long long n)
{
    F.push_back(0);
    F.push_back(1);
    for (long long i = 2; i <= n; i++)
    {
        F.push_back((F[i - 1] + F[i - 2]) % 10);
    }
}

long long fibonacciSquareSum(long long n)
{
    fibonacci_sum(n);
    return (F[n] * (F[n - 1] + F[n]))%10;
}

int main()
{
    long long n;
    cin >> n;
    n %= 60;
    cout<<fibonacciSquareSum(n);
    return 0;
}
