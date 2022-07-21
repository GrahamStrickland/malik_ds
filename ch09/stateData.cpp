#include "stateData.h"

istream& >>(const istream& infile, stateData& state)
{
    std::string line;
    std::size_t pos;
    char c;
    int inpOrder = 0;

    while ((line = getline(line, 25, infile)) != EOF) {
        pos = line.find(':', 0);
        switch(inpOrder) {
        case 0:
            state.name = line.substr(pos+1);
            break;
        case 1:
            state.capital = line.substr(pos+1);
            break;
        case 2:
            state.area = line.substr(pos+1);
            break;
        case 3:
            state.yearOfAdmission = line.substr(pos+1);
            break;
        case 4:
            state.orderOfAdmission = line.substr(pos+1);
            break;
        default:
            std::cerr << "Error: invalid input to >>\n";
            break;
        }
        inpOrder++;
    }
}

ostream& <<(const ostream& outfile, const stateData& state) const
{
    outfile << "Name: " << state.name << "\nCapital: "
            << state.capital << "\nArea: " << state.area
            << "\nYear of Admission to Union: " << state.yearOfAdmission
            << "\nOrder of Admission to Union: " << state.orderOfAdmission
            << '\n';
}