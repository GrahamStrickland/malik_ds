//**************************************************************
// Author: D.S. Malik
//
// Program: Election Resulsts
// Given candidates' voting this program determines the winner
// of the election. The program outputs the votes received by
// each candidate and the winner.
//**************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "candidateType.h"
#include "orderedArrayListType.h"

const int NO_OF_CANDIDATES = 6;

void fillNames(std::ifstream& inFile,
                orderedArrayListType<candidateType>& cList);

void processVotes(std::ifstream& inFile,
                    orderedArrayListType<candidateType>& cList);

void addVotes(orderedArrayListType<candidateType>& cList);

void printHeading();

void printResults(orderedArrayListType<candidateType>& cList);

int main()
{
    orderedArrayListType<candidateType>
        candidateList(NO_OF_CANDIDATES);

    std::ifstream inFile;

    inFile.open("candData.txt");

    fillNames(inFile, candidateList);

    candidateList.selectionSort();

    inFile.close();

    inFile.open("voteData.txt");

    processVotes(inFile, candidateList);

    addVotes(candidateList);

    printHeading();

    printResults(candidateList);

    return 0;
}

void fillNames(std::ifstream& inFile,
                orderedArrayListType<candidateType>& cList)
{
    std::string firstN;
    std::string lastN;

    candidateType temp;

    for (int i = 0; i < NO_OF_CANDIDATES; i++)
    {
        inFile >> firstN >> lastN;
        temp.setName(firstN, lastN);
        cList.insertAt(i, temp);
    }
}

void processVotes(std::ifstream& inFile,
    orderedArrayListType<candidateType>& cList)
{
    std::string firstN, lastN, region, votes;

    candidateType temp;

    while (inFile >> firstN >> lastN >> region >> votes)
    {
        //temp.setName(firstN, lastN)
        //cList.binarySearch(temp);
        //temp.updateVotesByRegion(region, votes);
        //cList.replaceAt(i, temp);
    }
}

void addVotes(orderedArrayListType<candidateType>& cList)
{
    candidateType temp;

    for (int i = 0; i < NO_OF_CANDIDATES; i++)
    {
        cList.retrieveAt(i, temp);
        temp.calculateTotalVotes();
        cList.replaceAt(i, temp);
    }
}

void printHeading()
{
    std::cout << " .     ----------------------Election Results---------"
              << "------------" << '\n' << '\n';
    std::cout << "                                      Votes" << '\n';
    std::cout << "  Candidate Name  Region1 Region2 Region3 "
              << "Region4   Total" << '\n'
              << "----------------  ------- ------- ------- "
              <<"--------   -------  -----" << '\n';
}

void printResults(orderedArrayListType<candidateType>& cList)
{
    int sumVotes = 0, largestVotes = 0, winLoc = 0;
    candidateType temp;

    for (int i = 0; i < NO_OF_CANDIDATES; i++)
    {
        cList.retrieveAt(i, temp);
        temp.printData();
        sumVotes += temp.getTotalVotes();
        if (largestVotes < temp.getTotalVotes())
        {
            largestVotes = temp.getTotalVotes();
            winLoc = i; //this is the ith candidate
        }
    }
    // Output the final lines of the output.
}