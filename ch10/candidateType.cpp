//*************************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement a candidate.
//*************************************************************

#include "candidateType.h"
#include <iomanip>

void candidateType::setVotes(int region, int votes) {
  votesByRegion[region - 1] = votes;
}

void candidateType::updateVotesByRegion(int region, int votes) {
  votesByRegion[region - 1] = votesByRegion[region - 1] + votes;
}

void candidateType::calculateTotalVotes() {
  totalVotes = 0;

  for (int i = 0; i < NO_OF_REGIONS; i++)
    totalVotes += votesByRegion[i];
}

int candidateType::getTotalVotes() const { return totalVotes; }

void candidateType::printData() const {
  std::cout << std::left << std::setw(10) << firstName << " " << std::setw(10)
            << lastName << " ";

  std::cout << std::right;

  for (int i = 0; i < NO_OF_REGIONS; i++)
    std::cout << std::setw(7) << votesByRegion[i] << " ";
  std::cout << std::setw(7) << totalVotes << '\n';
}

candidateType::candidateType() {
  for (int i = 0; i < NO_OF_REGIONS; i++)
    votesByRegion[i] = 0;

  totalVotes = 0;
}

bool candidateType::operator==(const candidateType &right) const {
  return (firstName == right.firstName && lastName == right.lastName);
}