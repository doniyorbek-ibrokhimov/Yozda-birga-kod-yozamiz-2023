int calcDroneMinEnergy( const vector<vector<int>>& route ) 
{
  if (route.size() == 1) return 0;
  
  bool didSpentEnergy = false;
  
  int minEnergy = INT_MAX;
  int startEnergy = route[0][2];
  
  for (int i = 1; i < route.size(); i++) {
    int currentEnergy = route[i][2];
    int energyDifference = startEnergy - currentEnergy;
    
    if (energyDifference < 0) {
      minEnergy = min(energyDifference, minEnergy);
      didSpentEnergy = true;
    }
  }
  
  return (didSpentEnergy) ? -minEnergy : 0;
  
}