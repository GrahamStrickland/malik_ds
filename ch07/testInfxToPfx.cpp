// This is a driver program to test the ADT InfxToPfx.

#include "infxToPfx.h"

using namespace std;

int main() {
  InfxToPfx converter;

  converter.getInfix("A + B - C;");
  converter.showInfix();
  converter.showPostfix();

  converter.getInfix("(A + B) * C;");
  converter.showInfix();
  converter.showPostfix();

  converter.getInfix("(A + B) * (C - D);");
  converter.showInfix();
  converter.showPostfix();

  converter.getInfix("A + ((B + C) * (E - F) - G) / (H - I);");
  converter.showInfix();
  converter.showPostfix();

  converter.getInfix("A + B * (C + D) - E / F * G + H;");
  converter.showInfix();
  converter.showPostfix();

  return 0;
}
