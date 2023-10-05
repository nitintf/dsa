#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  vector<int> nums3;
  int n1 = nums1.size(), n2 = nums2.size();
  int i = 0, j = 0;

  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      nums3.push_back(nums1[i++]);
    }
    else {
      nums3.push_back(nums2[j++]);
    }
  }

  while (i < n1) nums3.push_back(nums1[i++]);
  while (j < n2) nums3.push_back(nums2[j++]);

  int n = (n1 + n2);
  if (n % 2 == 1) {
    return nums3[n / 2];
  }
  return (double)((double)(nums3[n / 2] + (double)(nums3[n / 2 - 1])) / 2.0);
}

double betterFindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int n1 = nums1.size(), n2 = nums2.size();
  int n = n1 + n2;
  int i = 0, j = 0;
  int idx2 = n / 2;
  int idx1 = idx2 - 1;
  int count = 0;
  int elmAtIdx1 = -1, elmAtIdx2 = -1;

  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      if (count == idx1) elmAtIdx1 = nums1[i];
      if (count == idx2) elmAtIdx2 = nums1[i];
      count++;
      i++;
    }
    else {
      if (count == idx1) elmAtIdx1 = nums2[j];
      if (count == idx2) elmAtIdx2 = nums2[j];
      count++;
      j++;
    }
  }

  while (i < n1) {
    if (count == idx1) elmAtIdx1 = nums1[i];
    if (count == idx2) elmAtIdx2 = nums1[i];
    count++;
    i++;
  }


  while (j < n2) {
    if (count == idx1) elmAtIdx1 = nums2[j];
    if (count == idx2) elmAtIdx2 = nums2[j];
    count++;
    j++;
  }

  if (n % 2 == 1) {
    return elmAtIdx2;
  }

  return (double)((double)(elmAtIdx2 + (double)(elmAtIdx1)) / 2.0);
}
