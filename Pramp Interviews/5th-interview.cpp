int shiftedArrSearch( const vector<int>& shiftArr, int num ) 
{
  for (int i = 0; i < shiftArr.size(); i++) {
    if(shiftArr[i] == num) return i;
  }

  return -1;
}
