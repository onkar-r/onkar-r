#include <algorithm>
#include <iostream>
#include <vector>


// Sorts first elem of a pair in ascending and second element in descending order
bool compPairMixedOrder(const std::pair<int, int> &a, const std::pair<int, int> &b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first == b.first && a.second > b.second) {
    return true;
  }
  return false;    
}

int main() {
  std::vector<std::pair<int,int>> v2 = {{6,3}, {6,4}, {1,3}, {1,5}, {5,5}};
  std::sort(v2.begin(), v2.end(), compPairMixedOrder);

  std::cout << "\nContents after sorting:\n";
  for (auto i: v2) {
    std::cout << i.first << ", " << i.second << '\n';
  }

  return 0;
}