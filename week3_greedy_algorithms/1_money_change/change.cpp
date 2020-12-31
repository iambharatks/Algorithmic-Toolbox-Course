#include <iostream>

int get_change(int m) {
  //write your code here
  int coins = m/10;
  m %= 10;
  coins += m/5;
  m %= 5;
  coins += m;
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
