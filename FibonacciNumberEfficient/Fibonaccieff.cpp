#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long > F;
    F.push_back(0);
    F.push_back(1);
    for(int i  = 2; i <= n ; i++)
        F[i] = F[i-1] + F[i-2];
    cout<<F[n];
    return 0 ;
}
