// Interface file for class romanType,
// which stores a number using Roman numerals,
// with functions to print the number in Roman
// numeral and decimal formats.
// Implementation for the class romanType is in
// the file romanType.cpp
const int MAX_SIZE = 20;
const int NUM_VALS = 7;

class romanType
{
public:
    void convertDecimal();
    // Precondition: romanValue stored as c-string value using
    //  values from the numerals array.
    // Postcondition: romanValue converted to decimal number
    //  and stored in the int variable decimalValue.

    void printRoman() const;
    // Precondition: romanValue stored as c-string value using
    //  values from the numerals array.
    // Postcondition: Numeral stored in romanValue printed
    //  to console.

    void printDecimal();
    // Precondition: romanValue stored as c-string value using
    //  values from the numerals array.
    // Postcondition: If decimalValue has been declared, it
    //  has been printed to console, else convertDecimal()
    //  called and then printed.
    
    romanType(char numeral[], int l);
    // Constructor with parameter for c-string representing
    //  Roman numeral value to be stored.
private:
    int decimalValue;
    int length;
    char romanValue[MAX_SIZE];
    char numerals[NUM_VALS] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int values[NUM_VALS] = {1000, 500, 100, 50, 10, 5, 1};
};
