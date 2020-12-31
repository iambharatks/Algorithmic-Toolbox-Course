#include <bits/stdc++.h>

using namespace std;

//long long Fibo(v)
//{
//    vector<int>
//}
//long long fibonacci_fast(long long n , long long m) {
//    // write your code here
//    vector<long long> F;
//    F.push_back(0);
//    F.push_back(1);
//    for(int i = 2 ; i <= n ; i++)
//        F.push_back( F[i-1]%m + F[i-2]%m );
//    return F[n]%m;
//}
//long long pisanoperiod(long long m )
//{
//    vector<long long> F;
//    F.push_back(0);
//    F.push_back(1);
//    //cout<<F[0]%m<<"\t"<<F[1]%m<<"\t";
//    for(long long i = 2 ; i <= m*m ; i++)
//        {
//            F.push_back( F[i-1] + F[i-2] );
//            F[i] = F[i]%m;
//            if(F[i] == 1 && F[i-1] == 0)
//                {
//                    //cout<<endl;
//                    return i-1;
//                }
//            //cout<<F[i]<<"\t";
//        }
//}

//long long fibonacci_fast(long long n ) {
//    // write your code here
//    vector<long long> F;
//    F.push_back(0);
//    F.push_back(1);
//    for(long long i = 2 ; i <= n ; i++)
//        F.push_back( F[i-1] + F[i-2] );
//    return F[n];
//}


int main() {
    long long n, m;
    cin >> n>> m ;
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
                    m = i-1;
                    break;
                }
            //cout<<F[i]<<"\t";
        }
//    m = pisanoperiod(m);
    n %= m;
    cout<<F[n];
//    cout<<fibonacci_fast(n)%m<<endl;
//    cout<<fibonacci_fast(n)%m;
    return 0;
//    cout << fibonacci_fast(n, m) << '\n';
}
