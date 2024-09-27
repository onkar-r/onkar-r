/**********************************************************
 * Author: Onkar Rajopadhye
 *
 * How to run this program:
 * [prompt]$ g++ -Wall -g stl_algos.cpp -o stl_algos
 * [prompt]$ ./stl_algos
 *
**********************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;


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

  // ================= next_permutation ==============================
  std::string str("abc"); // already sorted
  cout << "\nPrinting all permutations of a string:\n" << str << '\n';
  while(std::next_permutation(str.begin(), str.end())) {
    cout << str << '\n';
  }

  return 0;
}