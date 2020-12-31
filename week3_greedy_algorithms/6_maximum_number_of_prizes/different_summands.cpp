#include <bits/stdc++.h>

using namespace std;

void optimal_summands(vector<long long> &summands ,long long &n ) {

  //write your code here
  long long i = 1 , c = 0;
  while(n-i>=0){
    summands.push_back(i);
    n -= i;
    c++;
    i++;
  }
  if(n-i < 0 ){
    summands[c-1] += n ;
  }
  return ;
}

int main() {
  long long n;
  cin >> n;
  if(n>0){
  vector<long long> summands;
  optimal_summands(summands , n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
  }
  else
    cout<<n;
  return 0;
}
