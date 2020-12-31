#include <bits/stdc++.h>

using namespace std;

template <class T>
void swapxy(T &x , T &y){
    T temp  = x ;
    x = y;
    y = temp;
}
void Bubblesort(vector<long long> &a)
{
    for(int i = 0; i < a.size()-1 ; i++)
    {
        for(int j = 0 ; j < a.size()-i-1 ; j++)
            if(a[j] > a[j+1])
                swapxy(a[j],a[j+1]);
    }
}
long long max_dot_product(vector<long long > &a, vector<long long> &b) {
  // write your code here
  long long result = 0;
  for(int i = 0 ;i < a.size() ; i++){
    result += ((long long) a[i])*b[i];
  }

  return result;
}

int main() {
  vector<long long>::size_type n;
  cin>>n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  Bubblesort(a);
  Bubblesort(b);

  cout << max_dot_product(a, b) << endl;
}
