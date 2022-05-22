#include <iostream>
#include <string>
#include "extPersonType.h"

int main()
{
    using namespace std;

    extPersonType person1;
    extPersonType person2("Graham", "Strickland", 1, 28, 1991,
            "30 Oxford Street", "Cape Town", "Western Cape", "7708",
            "Family Member", "0727131038");

    cout << "Details of person2:\n";
    person2.print();
    cout << endl;
    
    person1.setName("Brett", "Martindale");
    person1.setDate(10, 29, 1990);
    person1.setAddress("30 Oxford Street", "Cape Town", "Western Cape",
            "7708");
    person1.setPhone("0761666761");
    person1.setRelationship();
    cout << "Details of person1:\n";
    person1.print();
    cout << endl;

    return 0;
}
