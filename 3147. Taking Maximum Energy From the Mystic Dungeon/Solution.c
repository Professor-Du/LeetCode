int maximumEnergy(int* energy, int energySize, int k) {
  int i, maxEnergy = INT_MIN;

  for (i = energySize - k - 1; i >= 0; i--) {
    energy[i] += energy[i + k];
  }

  for (i = 0; i < energySize; i++) {
    maxEnergy = fmax (maxEnergy, energy[i]);
  }

  return maxEnergy;
}