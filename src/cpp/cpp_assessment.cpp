#include <bits/stdc++.h>

using namespace std;


struct A {
  A()  { cout << "\nctor invoked"; }
  ~A() { cout << "\ndtor invoked"; }
};

struct paddingAlignment {
  int   i;
  char  c;
  float f;
};

int main()
{
  cout << is_array<int>::value;
  cout << is_array<char[10]>::value;
  cout << is_array<float>::value << "\n";
  
  A* pA = new A[5];
  delete []pA;
  
  cout << "\nsizeof(paddingAlignment) = " << sizeof(paddingAlignment);
  
  cout << "\n";
  return 0;
}