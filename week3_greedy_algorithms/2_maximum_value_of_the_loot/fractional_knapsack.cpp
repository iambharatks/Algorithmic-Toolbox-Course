#include <bits/stdc++.h>

using namespace std;


double get_optimal_value(double &capacity,vector<pair<double , pair<double,double>>> & item) {
  double value = 0.0 ;
//  int i=0 , pos = 0;
//  while(capacity > 0)
//  {
//      ratio_ = 0.0;
//      i= 0;
//      for(int i = 0 ;i < rati.size() ; i++){
//        if(ratio_ < item[i].first){
//            ratio_ = item[i].first;
//            pos = i;
//        }
//      }
      //cout<<"\n ratio = "<<ratio_<<"\t";
//      item[pos].first  = 0;
//      double weight = min(capacity ,item[pos].second.second );
//      value += (weight/weights[pos]) * values[pos];
//      capacity -= weight;
  int i = 0;
  while(capacity >0 && i < item.size())
  {
      double weight = min(capacity , item[i].second.second) ;
      value += (weight/item[i].second.second) *item[i].second.first ;
      capacity -= weight;
      i++;
  }
  return value;
  }



int main() {
  int n;
  double capacity;
  cin >> n >> capacity;
  vector<pair<double , pair<double,double>>> item(n);
//  ios::sync_with_stdio(0);
//  cin.tie(0);
  for (int i = 0; i < n; i++) {
    cin >> item[i].second.first >> item[i].second.second;
    item[i].first = item[i].second.first /item[i].second.second ;
//    cout<<fixed<<setprecision(4)<<rati[i]<<"\n";
    //cout<<rati[i]<<"\n";
  }
  sort(item.begin() ,item.end()  , greater<>());
  double optimal_value = get_optimal_value(capacity, item);
  cout<<fixed;
  cout<<setprecision(4) << optimal_value << endl;
  //cout<<capacity<<" ";
  return 0;
}
