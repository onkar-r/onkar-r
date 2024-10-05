#include <iostream>


using std::vector;
using std::cout;

int main()
{
   vector<int> nums1 {1, 2, 3, 0, 0, 0};
   vector<int> nums2 {2, 5, 6};
   
   int i = 0;
   for (j: nums2) {
      if ( nums2[j] > nums1[i] ) {
         ++i;
      } else if ( nums2[j] == nums1[i] ) {
         
      } else if ( nums2[j] < nums1[i] ) {
         nums3.push_back(nums1[i]);
         nums[i] = nums2[j]; // Put the smaller element found in num2 into num1
      }
   }
}