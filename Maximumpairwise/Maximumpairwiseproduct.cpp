#include<bits/stdc++.h>

using namespace std;

long long MaxProdPair(vector<long long> &num)
{
    long long m1 = 0  , m2 = 0 , pos;
    for(int i = 0 ; i < num.size() ; i++)
        if(m1 == 0 || m1 < num[i])
            {
                m1 = num[i];
                pos = i;
            }
    for(int i = 0 ; i < num.size() ; i++)
        if((i != pos) && (m2 == 0 || m2 < num[i]))
             m2 = num[i];
    return m1*m2;
}


int main()
{
    int n;
    cin>>n;
    vector<long long> numbers(n);
    for(long long & i : numbers)
        cin>>i;
    cout<<MaxProdPair(numbers);
    return 0;
}
