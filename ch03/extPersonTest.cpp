#include "extPersonType.h"
#include <iostream>
#include <string>

int main() {
  using namespace std;

  extPersonType person1;
  extPersonType person2("Bertrand", "Russell", 5, 18, 1872, "Ravenscroft",
                        "Trellech", "Monmouthshire", "NP15 1AA",
                        "Family Member", "0100111010");

  cout << "Details of person2:\n";
  person2.print();
  cout << endl;

  person1.setName("George", "Moore");
  person1.setDate(11, 4, 1873);
  person1.setAddress("Upper Norwood", "London", "Greater London", "SE19");
  person1.setPhone("0821094987");
  person1.setRelationship();
  cout << "Details of person1:\n";
  person1.print();
  cout << endl;

  return 0;
}
