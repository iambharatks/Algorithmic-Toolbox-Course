#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;
void print(vector<int> a)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
  std::cout << "\n";
}

void partition(vector<int> &a, int low, int high, int &i, int &h)
{
  int pivot = a[high];
  // std::cout << pivot << "\n";
  i = low, h = high;
  int m = low;
  while (m <= h)
  {
    if (a[m] < pivot)
    {
      swap(a[i++], a[m++]);
    }
    else if (a[m] == pivot)
    {
      m++;
    }
    else
    {
      swap(a[m], a[h--]);
    }
  }
}

void randomized_quick_sort(vector<int> &a, int low, int high)
{
  if (low >= high)
  {
    return;
  }

  int rPivot = low + rand() % (high - low + 1);
  swap(a[low], a[rPivot]);
  int i, j;
  partition(a, low, high, i, j);
  randomized_quick_sort(a, low, i - 1);
  randomized_quick_sort(a, j + 1, high);
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
  randomized_quick_sort(a, 0, a.size() - 1);
  print(a);
}
