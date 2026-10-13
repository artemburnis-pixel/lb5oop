#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money {
private:
    long hryvnia;
    unsigned char kopyiky;

    long long toKopyiky() const;

public:
    Money();
    Money(long h);
    Money(long h, long k);
    Money(const Money& m);
    ~Money();

    bool Init(long h, long k);
    void Read();
    std::string toString() const;
    void Display() const;

    Money Add(const Money& m) const;
    Money Subtract(const Money& m) const;
    double Divide(const Money& m) const;
    Money DivideByFactor(double factor) const;
    Money MultiplyByFactor(double factor) const;

    bool IsEqual(const Money& m) const;
    bool IsGreaterThan(const Money& m) const;
    bool IsLessThan(const Money& m) const;
};

#endif