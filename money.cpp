#include "money.h"
#include <iostream>

Money::Money() : hryvnia(0), kopyiky(0) {
    std::cout << "[Конструктор 1] " << toString() << " грн\n";
}

Money::Money(long h) {
    if (!Init(h, 0)) {
        hryvnia = 0;
        kopyiky = 0;
    }
    else {
        std::cout << "[Конструктор 2] " << toString() << " грн\n";
    }
}

Money::Money(long h, long k) {
    if (!Init(h, k)) {
        hryvnia = 0;
        kopyiky = 0;
    }
    else {
        std::cout << "[Конструктор 3] " << toString() << " грн\n";
    }
}

Money::Money(const Money& m) : hryvnia(m.hryvnia), kopyiky(m.kopyiky) {
    std::cout << "[Конструктор 4] " << toString() << " грн\n";
}

Money::~Money() {
    std::cout << "[Деструктор] " << toString() << " грн\n";
}

long long Money::toKopyiky() const {
    return (long long)hryvnia * 100 + kopyiky;
}

bool Money::Init(long h, long k) {
    if (h < 0 || k < 0) return false;

    hryvnia = h + (k / 100);
    kopyiky = (unsigned char)(k % 100);
    return true;
}

void Money::Read() {
    long h, k;

    std::cout << "Введіть гривні: ";
    std::cin >> h;
    std::cout << "Введіть копійки: ";
    std::cin >> k;

    while (h < 0 || k < 0) {
        std::cout << "Помилка! Введіть додатні значення:\n";
        std::cout << "Гривні: "; std::cin >> h;
        std::cout << "Копійки: "; std::cin >> k;
    }

    Init(h, k);
}

std::string Money::toString() const {
    std::string res = std::to_string(hryvnia) + ",";
    if (kopyiky < 10) {
        res += "0";
    }
    res += std::to_string((int)kopyiky);
    return res;
}

void Money::Display() const {
    std::cout << toString() << " грн\n";
}

Money Money::Add(const Money& m) const {
    long long sum = toKopyiky() + m.toKopyiky();
    Money res(sum / 100, sum % 100);
    return res;
}

Money Money::Subtract(const Money& m) const {
    long long diff = toKopyiky() - m.toKopyiky();
    if (diff < 0) {
        return Money(0, 0);
    }
    return Money(diff / 100, diff % 100);
}

double Money::Divide(const Money& m) const {
    if (m.toKopyiky() == 0) return 0.0;
    return (double)toKopyiky() / m.toKopyiky();
}

Money Money::DivideByFactor(double factor) const {
    if (factor <= 0) {
        return Money(0, 0);
    }
    long long total = (long long)(toKopyiky() / factor);
    return Money(total / 100, total % 100);
}

Money Money::MultiplyByFactor(double factor) const {
    if (factor < 0) {
        return Money(0, 0);
    }
    long long total = (long long)(toKopyiky() * factor);
    return Money(total / 100, total % 100);
}

bool Money::IsEqual(const Money& m) const {
    return toKopyiky() == m.toKopyiky();
}

bool Money::IsGreaterThan(const Money& m) const {
    return toKopyiky() > m.toKopyiky();
}

bool Money::IsLessThan(const Money& m) const {
    return toKopyiky() < m.toKopyiky();
}