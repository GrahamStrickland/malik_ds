//This is the implementation of the ADT stataData,
//the interface is in the file stateData.h

#include <cassert>
#include "stateData.h"

std::istream& operator >>(const std::istream& ins, stateData& state)
{
    std::string line;
    std::size_t pos;
    int inpOrder = 0, exp = 1;

    while (ins) {
        std::getline(ins, line);
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
            exp = 1;
            line = line.substr(pos+1);
            state.yearOfAdmission = 0;
            for (int i = 0; i < line.length(); i++) {
                state.yearOfAdmission += 
                state.yearOfAdmission * exp + line.at(i) - '0';
                exp *= 10;
            }
            break;
        case 4:
            exp = 1;
            line = line.substr(pos+1);
            state.orderOfAdmission = 0;
            for (int i = 0; i < line.length(); i++) {
                state.orderOfAdmission += 
                state.orderOfAdmission * exp + line.at(i) - '0';
                exp *= 10;
            }
            break;
        default:
            std::cerr << "Error: invalid input to >>\n";
            break;
        }
        inpOrder++;
    }
}

std::ostream& operator <<(std::ostream& outs, const stateData& state)
{
    outs << "Name: " << state.name << "\nCapital: "
         << state.capital << "\nArea: " << state.area
         << "\nYear of Admission to Union: " << state.yearOfAdmission
         << "\nOrder of Admission to Union: " << state.orderOfAdmission
         << '\n';
}

stateData::stateData(std::string n, std::string c, std::string a, int y, int o)
    : name(n), capital(c), area(a), yearOfAdmission(y), orderOfAdmission(o)
{
    assert(yearOfAdmission > 1776 && yearOfAdmission < 2022);
    assert(orderOfAdmission >= 1 && orderOfAdmission <= 50);
}

bool stateData::operator ==(const stateData& otherState) const
{
    return name == otherState.name;
}

bool stateData::operator !=(const stateData& otherState) const
{
    return name != otherState.name;
}

bool stateData::operator <(const stateData& otherState) const
{
    return name < otherState.name;
}

bool stateData::operator >(const stateData& otherState) const
{
    return name > otherState.name;
}

bool stateData::operator <=(const stateData& otherState) const
{
    return name <= otherState.name;
}

bool stateData::operator >=(const stateData& otherState) const
{
    return name >= otherState.name;
}

void stateData::setStateInfo(std::string n, std::string c, std::string a,
    int y, int o)
{
    assert(y >= 1776 && y <= 2022);
    assert(o >= 1 && o <= 50);
    name = n;
    capital = c;
    area = a;
    yearOfAdmission = y;
    orderOfAdmission = o;
}

void stateData::getStateInfo(std::string& n, std::string& c, std::string& a,
    int& y, int& o) const
{
    n = name;
    c = capital;
    a = area;
    y = yearOfAdmission;
    o = orderOfAdmission;
}