#pragma warning(disable : 4996)
#include "Currency.h"
#include "User.h"
#include "Parking.h"
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>


std::ostream& operator<<(std::ostream& os, Currency& c)
{
    return os << c.toString();
}

std::istream& operator>>(std::istream& is, Currency& c)
{
    std::string str, tmp;
    is >> str;
    int comas = 0;
    unsigned int intPart = 0;
    unsigned int fractPart = 0;
    std::string code = "PLN";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',') {
            switch (comas) {
                case 0: code = tmp; tmp = ""; break;
                case 1: intPart = std::stoi(tmp); tmp = ""; break;
            }
            comas++;
            continue;
        }
        tmp += str[i];
    }
    fractPart = std::stoi(tmp);
    c.setCode(code);
    c.setInt(intPart);
    c.setFract(fractPart);
    return is;
}

std::ostream& operator<<(std::ostream& os, Wallet& w)
{
    return os << w.toString();
}

std::istream& operator>>(std::istream& is, Wallet& w)
{
    return is >> *w.balance;
}

std::string Currency::toString()
{
    std::string string;
    string += code;
    string += ",";
    string += std::to_string(intPart);
    string += ",";
    string += std::to_string(fractPart);
    return string;
}

Currency Currency::convert(Currency& to)
{
    CurrencyApi api;
    return api.convert(*this, to);
}

bool Currency::operator==(Currency& curr)
{
    if (code != curr.code) return false;
    if (intPart != curr.intPart) return false;
    if (fractPart != curr.fractPart) return false;
    return true;
}

Currency Currency::operator*(int k) const
{
    double intP = (double)this->intPart * k;
    int fractP = (double)this->fractPart * k;
    double rest = intP - (int)intP;
    fractP += rest;
    while (fractP >= 100) {
        intP++;
        fractP -= 100;
    }
    return Currency(code, (int)intP, fractP);
}

Currency Currency::operator-(Currency& curr) const
{
    int fractP, intP;
    if (code != curr.code) {
        Currency tempCurr = Currency(code, 0, 0);
        curr.convert(tempCurr);
        intP = this->intPart - tempCurr.intPart;
        fractP = this->fractPart - tempCurr.fractPart;
    }
    else {
        intP = this->intPart - curr.intPart;
        fractP = this->fractPart - curr.fractPart;
    }
    while (fractP < 0 && intP > 0) {
        fractP += 100;
        intP--;
    }
    return Currency(code, intP, fractP);
}

Currency* Currency::operator-=(Currency& curr)
{
    int fractP, intP;
    intP = this->intPart - curr.intPart;
    fractP = this->fractPart - curr.fractPart;
    while (fractP < 0 && intP > 0) {
        fractP += 100;
        intP--;
    }
    this->intPart = intP;
    this->fractPart = fractP;
    return this;
}

Currency Currency::operator+(Currency& curr)
{
    int fractP, intP;
    if (code != curr.code) {
        Currency tempCurr = Currency(code, 0, 0);
        curr.convert(tempCurr);
        intP = this->intPart + tempCurr.intPart;
        fractP = this->fractPart + tempCurr.fractPart;
    }
    else {
        intP = this->intPart + curr.intPart;
        fractP = this->fractPart + curr.fractPart;
    }
    while (fractP > 100) {
        fractP -= 100;
        intP++;
    }
    return Currency(code, intP, fractP);
}

Currency* Currency::operator+=(Currency& curr)
{
    int fractP, intP;
    if (code != curr.code) {
        Currency tempCurr = Currency(code, 0, 0);
        curr.convert(tempCurr);
        intP = this->intPart + tempCurr.intPart;
        fractP = this->fractPart + tempCurr.fractPart;
    }
    else {
        intP = this->intPart + curr.intPart;
        fractP = this->fractPart + curr.fractPart;
    }
    while (fractP > 100) {
        fractP -= 100;
        intP++;
    }
    this->intPart = intP;
    this->fractPart = fractP;
    return this;
}

bool Wallet::pay(Currency* c)
{
    *balance -= *c;
    return true;
}

bool Wallet::topUp(Currency* c)
{
    *balance += *c;
    return true;
}

//Payment PaymentSystem::pay(User& u, Currency& amount, std::string descr)
//{
//    if (u.pay(amount)) {
//        return Payment(0, u.getId(), 0, amount, descr);
//    }
//    return Payment();
//}

std::string Payment::toString()
{
    std::string tmp;
    std::time_t t = std::chrono::system_clock::to_time_t(date);
    tmp += amount->toString();
    tmp += ",";
    tmp += std::ctime(&t);
    tmp += ",";
    tmp += descr;
    return tmp;
}
