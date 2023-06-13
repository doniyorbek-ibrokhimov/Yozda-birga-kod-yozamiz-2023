#include <iostream>
#include <vector>

using namespace std;

int findBusiestPeriod( const vector<vector<int> >& data ) 
{
  // your code goes here
  int currentTimeStamp = data[0][0];
  int currentSumOfVisitors = (data[0][2] == 1) ? data[0][1] : -data[0][1];
  int resultSumOfVisitors = INT_MIN;
  int resultTimeStamp;
  
  if (data.size() == 1) return data[0][0];
  
  for(int i = 1; i < data.size(); i++) {
    
    if(data[i][0] == currentTimeStamp) {
      currentSumOfVisitors = (data[i][2] == 1) ? (currentSumOfVisitors + data[i][1]) : (currentSumOfVisitors - data[i][1]);
    }
    else if(i == data.size() - 1 or data[i][0] != currentTimeStamp) {
      
      cout << "currentSumOfVisitors: " << currentSumOfVisitors << endl;
      cout << "currentTimeStamp: " << currentTimeStamp << endl;
      
      if (resultSumOfVisitors < currentSumOfVisitors) {
        resultSumOfVisitors = currentSumOfVisitors;
        resultTimeStamp = currentTimeStamp;
      }
      
      currentTimeStamp = data[i][0];
      currentSumOfVisitors = (data[i][2] == 1) ? data[i][1] : -data[i][1];
    }
  }

  return resultTimeStamp;
    
}
  

int main() {

  
  return 0;
}
