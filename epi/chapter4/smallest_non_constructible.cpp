#include <bits/stdc++.h>
using namespace std;

/*
 * Given an array nums of n positive integers,
 * find the smallest positive integer that cannot be represented
 * as the sum of elements in nums.
 *
 * The algorithm sorts the numbers and then scans through 
 * the numbers once.
 * The invariant we keep is that, at the beginning of the ith
 * iteration (i=0...n), all numbers from 1 to res can be represented
 * as sum of the first i numbers, but no number > res can.
 *
 * Adding a new number u = nums[i] to the set makes the following
 * numbers representable:
 *
 * 1 2 ... res u u+1 u+2 ... u+res
 *
 * If u > res+1, then res+1 is not going to be representable
 * with numbers nums[0] ... nums[i]. Addition of other numbers
 * won't change this, since they are going to be bigger than or equal to u.
 * Therefore, we can return the result res+1.
 * Otherwise, all numbers from 1 to u+res are going to be representable,
 * and nothing else.
 * So we can update res to u+res and the invariant will be maintained.
 * If we come to the last iteration, only numbers from 1 to res are representable,
 * so we return res+1.
 */

int smallest_non_constructible(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int res = 0;
  for (const int n : nums) {
    if (n > res+1) return res+1;
    res += n;
  }
  return res+1;
}


int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i=0; i<N; ++i) {
    cin >> nums[i];
  }
  cout << smallest_non_constructible(nums) << endl;
  return 0;
}
