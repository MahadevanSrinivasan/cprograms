#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

/**
 * @brief Converts all the elements above the index
 * i in the vector provided into a heap. Note that
 * this function is always called with i = 0 for 
 * this problem.
 *
 * @param v - Vector of integers
 * @param i - Starting index of the heap needed
 * @return None
 */
void heapify(vector<int>& v, int i)
{
  while(i < v.size())
  {
    int c;
    if((2*i)+2 < v.size()) {
      c = (v[(2*i)+1] < v[(2*i)+2]) ? ((2*i)+1) : ((2*i)+2);
    } else if(((2*i) + 1)< v.size())
      c = (2*i + 1);
    else break;
    if(v[i] > v[c]) {
      int temp = v[i];
      v[i] = v[c];
      v[c] = temp;
      i = c;
    } else {
      break;
    }
  }
}

/**
 * @brief Forms a heap out of a given vector
 * of integers.
 *
 * @param nums - Vector of integers
 * @return None
 */
void formHeap(vector<int>& v)
{
  int k = v.size();
  for(int i = (k/2); i >= 0; i--) {
    heapify(v, i);
  }
}
/**
 * @brief Finds the kth largest element in the 
 * given vector of integers using a min heap
 * of size k.
 * 
 * @param nums - Vector of integers of size n
 * @param k - Order statistic needed.
 * @return kth largest element, -1 if error
 */

int findKthLargest(vector<int>& nums, int k) {
  if((k <= 0) || (k > nums.size())) return -1;
  vector<int> v(nums.begin(), nums.begin()+k);
  formHeap(v);
  for(int i = k; i < nums.size(); i++)
  {
    if(v[0] < nums[i])
    {
      v[0] = nums[i];
      heapify(v, 0);
    }
  }
  return v[0];
}

int main(int argc, char* argv[])
{
  if(argc == 3)
  {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    vector<int> v(n, 0);
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
      v[i] = rand()%100;
      cout << v[i] << ' ';
    }
    cout << endl << "kth order statistic for k = " << k << " is " << findKthLargest(v, k) << endl;
  }
  else
  {
    cout << "Usage: ./a.out n k" << endl;
  }
}
