#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t mid, size_t right)
{
  int i, j, k;
  long long number_of_inversions = 0;
  i = left, j = mid, k = left;
  while (i <= mid - 1 && j <= right)
  {
    if (a[i] <= a[j])
    {
      b[k++] = a[i++];
    }
    else
    {
      b[k++] = a[j++];

      number_of_inversions += (mid - i);
    }
  }
  while (i <= mid - 1)
  {
    b[k++] = a[i++];
  }
  while (j <= right)
  {
    b[k++] = a[j++];
  }
  for (i = left; i <= right; i++)
  {
    a[i] = b[i];
  }
  return number_of_inversions;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
  long long number_of_inversions = 0;

  if (left < right)
  {
    size_t mid = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, mid);
    number_of_inversions += get_number_of_inversions(a, b, mid + 1, right);
    //write your code here
    number_of_inversions += merge(a, b, left, mid + 1, right);
  }
  return number_of_inversions;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
