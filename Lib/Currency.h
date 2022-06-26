#pragma once
#include <ctime>
#include <string>
#include "Api.h"
#include <vector>
#include <chrono>


class Currency
{
public:
    std::string code;
    int intPart;
    int fractPart;
    Currency() : code("PLN"), intPart(0), fractPart(0) {};
    Currency(std::string currCode, int intP, int fractP) : code(currCode), intPart(intP), fractPart(fractP) {};
    void setCode(std::string code) { this->code = code; };
    void setInt(int intP) { this->intPart = intP; };
    void setFract(int fractP) { this->fractPart = fractP; };
    std::string toString();
    Currency convert(Currency& to);
    bool operator==(Currency& curr);
    Currency operator*(int) const;
    Currency operator-(Currency& curr) const;
    Currency* operator-=(Currency& curr);
    Currency operator+(Currency& curr);
    Currency* operator+=(Currency& curr);
    friend std::ostream& operator<<(std::ostream& os, Currency& c);
    friend std::istream& operator>>(std::istream& is, Currency& c);
};

class Payment
{
private:
    int id;
    std::chrono::system_clock::time_point date;
    std::string descr;
    Currency* amount;
public:
    Payment(): id(0), amount(nullptr), date(std::chrono::system_clock::now()) {};
    Payment(unsigned int id, Currency* amount, std::string descr):
        id(id), amount(amount), date(std::chrono::system_clock::now()), descr(descr) {};
    std::string toString();
    Currency* getAmount() { return amount; };
};

class CurrencyApi : public Api {
public:
    CurrencyApi(){};
    CurrencyApi(std::string api, std::string apiKey) { this->api = api; this->apiKey = apiKey; };
    Currency convert(Currency from, Currency to) { return Currency(to.code, from.intPart, from.fractPart); };
};

class Wallet
{
private:
    int userId;
    std::vector<Payment*> payments;
public:
    Currency* balance;
    ~Wallet() { if (balance) delete balance; };
    Wallet(int userId) : userId(userId) { Currency b = Currency(); balance = &b; };
    void setUserId(int id) { this->userId = id; };
    int getUserId() { return userId; };
    std::string toString() { return balance->toString(); };
    Currency* getBalance() { return balance; };
    void addPayment(Payment* p) { this->payments.push_back(p); };
    std::vector<Payment*> getPayments() { return payments; };
    bool pay(Currency*);
    bool topUp(Currency*);

    friend std::ostream& operator<<(std::ostream& os, Wallet& w);
    friend std::istream& operator>>(std::istream& is, Wallet& w);
};

