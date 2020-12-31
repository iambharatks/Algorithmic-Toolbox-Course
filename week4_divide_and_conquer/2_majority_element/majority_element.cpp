#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  if (left == right)
    return a[left];

  //write your code here
  int mid = left + (right - left) / 2;
  int leftE = get_majority_element(a, left, mid);
  int rightE = get_majority_element(a, mid + 1, right);
  if (leftE == rightE)
    return leftE;
  int leftCount = count(a.begin() + left, a.begin() + mid + 1, leftE);
  int rightCount = count(a.begin() + mid + 1, a.begin() + right + 1, rightE);
  return leftCount > rightCount ? leftE : rightE;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  int ans = get_majority_element(a, 0, a.size() - 1);
  std::cout << (count(a.begin(), a.end(), ans) > n / 2) << "\n";
  return 0;
}
