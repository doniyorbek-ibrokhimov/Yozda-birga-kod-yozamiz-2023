
bool isToeplitz(const vector<vector<int>>& arr)
{
  int j = 0;
  int diagonalElement = arr[0][0];
  for (auto &i: arr) {
    if(j < i.size() and diagonalElement != i[j]) return false;
    j++;
  }
  
  diagonalElement = arr[0][1];
  for(int i = 0; i < arr.size(); i++) {
    for(int k = i+1; k < arr[i].size(); k++) {
      if(diagonalElement != arr[i][k]) return false;
    }
  }
  return true;
}
