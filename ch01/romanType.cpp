// Implementation file for class romanType,
// Interface for the class romanType is in
// the file romanType.h
#include "romanType.h"
#include <iostream>
using namespace std;

void romanType::convertDecimal() {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < NUM_VALS; j++) {
      if (romanValue[i] == numerals[j]) {
        if (j % 2 == 1) {
          if (romanValue[i + 1] == numerals[j + 1])
            decimalValue += values[j + 1] - values[j];
        } else
          decimalValue += values[j];
      }
    }
  }
}

void romanType::printRoman() const { cout << romanValue << endl; }

void romanType::printDecimal() {
  if (!decimalValue)
    convertDecimal();
  cout << decimalValue << endl;
}

romanType::romanType(char numeral[], int l) {
  int i = 0;

  while (i < l && numerals[i] != '\0')
    romanValue[i] = numeral[i];
}
