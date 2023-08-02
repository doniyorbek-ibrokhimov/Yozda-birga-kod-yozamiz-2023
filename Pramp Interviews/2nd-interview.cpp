#include <iostream>
#include <vector>

using namespace std;

double findGrantsCap(vector<int> grantsArray, int newBudget) 
{
  sort(grantsArray.begin(), grantsArray.end(), greater<>());
  // 1000, 120, 100, 50, 2
  
  double size = grantsArray.size();
  double leftElements;
  double remainingSum;
  double result = 0;
  
  for(int i = 0; i < size; i++) {
    
    if(grantsArray[i] * size < newBudget) {
      leftElements = i;
      remainingSum = 0;
      
      if (i != size - 1) {
        for (int j = i+1; j < size; j++) {
          remainingSum += grantsArray[j];
        }
      }
      else {
        remainingSum = grantsArray[i];
      }
      
      double v = newBudget - remainingSum;
      result = v / leftElements;
      return result;
    }
  }
  return 0;
}

int main() {
  vector<int> arr = {2, 100, 50, 120, 1000};

  int n = 190;
  
  cout << findGrantsCap(arr, n);
  
  return 0;
  
}

//https://www.onlinegdb.com/online_c_compiler#

/* If you peer is stuck, ask them how they can use sorting in order to arrive to the solution. It’s probably easier to solve if the array is sorted in a descending order. However, this is not a must.
  
If your peer doesn’t know how to proceed, suggest to them to test out each of the values in the sorted grants array as a potential cap.
  
A key step in the solution is knowing how to test whether a certain value is indeed the cap. Push your peer to provide a clear explanation on how to do that.
  
If your peer is in the right direction, they’d be able to find out a lower bound to the cap, based on the given grants values. The next step in the solution then would be to calculate the exact cap given that lower bound. */

