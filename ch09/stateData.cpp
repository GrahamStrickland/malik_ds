//This is the implementation of the ADT stataData,
//the interface is in the file stateData.h

#include <cassert>
#include "stateData.h"

std::istream& operator >>(std::istream& ins, stateData& state)
{
    std::string line;
    std::size_t pos;
    int inpOrder = 0;

    //Input line by line.
    while (inpOrder < 5) {   //Order lines for data.
        //Test for length of each line and newlines.
        if (std::getline(ins, line)) {
            if (line.length() == 0)
                continue;

            //Find ':' to separate label from data.
            pos = line.find(':', 0);
            switch(inpOrder) {  //Extract data.
            case 0:
                state.name = line.substr(pos+2);
                break;
            case 1:
                state.capital = line.substr(pos+2);
                break;
            case 2:
                state.area = line.substr(pos+2);
                break;
            case 3:
                line = line.substr(pos+2);
                state.yearOfAdmission = 0;

                //Extract number.
                for (int i = 0; i < line.length(); i++) {
                    state.yearOfAdmission = 
                    state.yearOfAdmission * 10 + static_cast<int>(line.at(i) - 48);
                }
                break;
            case 4:
                line = line.substr(pos+2);
                state.orderOfAdmission = 0;

                //Extract number.
                for (int i = 0; i < line.length(); i++) {
                    state.orderOfAdmission = 
                    state.orderOfAdmission * 10 + static_cast<int>(line.at(i) - 48);
                }
                break;
            default:
                break;
            }
            inpOrder++;
        } else {
            break;
        }
    }
    return ins;
}

std::ostream& operator <<(std::ostream& outs, const stateData& state)
{
    outs << "Name: " << state.name << "\nCapital: "
         << state.capital << "\nArea: " << state.area
         << "\nYear of Admission to Union: " << state.yearOfAdmission
         << "\nOrder of Admission to Union: " << state.orderOfAdmission
         << '\n';
    return outs;
}

stateData::stateData(std::string n, std::string c, std::string a, int y, int o)
    : name(n), capital(c), area(a), yearOfAdmission(y), orderOfAdmission(o)
{
    assert(yearOfAdmission >= 1776 && yearOfAdmission <= 2022);
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