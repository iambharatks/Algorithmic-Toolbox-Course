#include <bits/stdc++.h>

using namespace std;

long long pisanoperiod(long long m )
{
    vector<long long> F;
    F.push_back(0);
    F.push_back(1);
    //cout<<F[0]%m<<"\t"<<F[1]%m<<"\t";
    for(long long i = 2 ; i <= m*m ; i++)
        {
            F.push_back( F[i-1] + F[i-2] );
            F[i] = F[i]%m;
            if(F[i] == 1 && F[i-1] == 0)
                {
                    //cout<<endl;
                    return i-1;
                }
            //cout<<F[i]<<"\t";
        }
}
int main() {
    long long n, m =10;
    cin >> n ;
    vector<long long> F;
    long long sum = 1;
    F.push_back(0);
    F.push_back(1);
    n %= pisanoperiod(m);
    //cout<<F[0]%m<<"\t"<<F[1]%m<<"\t";
    for(long long i = 2 ; i <= n ; i++)
        {
            F.push_back( F[i-1] + F[i-2] );
            F[i] = F[i]%m;
            sum = (sum + F[i]) % 10;
//            if(F[i] == 1 && F[i-1] == 0)
//                {
//                    //cout<<endl;
//                    m = i-1;
//                    break;
//                }
            //cout<<F[i]<<"\t";
        }
//    m = pisanoperiod(m);
    if(n == 0)
        cout<<sum-1;
    else
        cout<<sum;
//    cout<<F[n];
//    cout<<fibonacci_fast(n)%m<<endl;
//    cout<<fibonacci_fast(n)%m;
    return 0;
//    cout << fibonacci_fast(n, m) << '\n'; 
}
//int main()
//{
//    long long n;
//    cin>>n;
//    long long sum = 1;
//    cout<<0<<"\t"<<sum<<"\t";
//    vector<long long> F;
//    F.push_back(0);
//    F.push_back(1);
//    for(long long i = 2 ; i <= n ; i++)
//        {
//            F.push_back( F[i-1] + F[i-2] );
//            sum  +=  F[i];
//            cout<<sum%10<<"\t";
//        }
//
//    return 0;
//}
//int fibonacci_sum_naive(long long n) {
//    if (n <= 1)
//        return n;
//
//    long long previous = 0;
//    long long current  = 1;
//    long long sum      = 1;
//
//    for (long long i = 0; i < n - 1; ++i) {
//        long long tmp_previous = previous;
//        previous = current;
//        current = tmp_previous + current;
//        sum += current;
//    }
//
//    return sum % 10;
//}
//
//int main() {
//    long long n = 0;
//    std::cin >> n;
//    std::cout << fibonacci_sum_naive(n);
//}
