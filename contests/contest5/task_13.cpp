#include <iostream>
#include <cstdlib> // For abs() function

class Rational {
private:
    int numer;
    int denom;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void normalize() {
        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
        int div = gcd(abs(numer), abs(denom));
        numer /= div;
        denom /= div;
    }

public:
    Rational(int numerator = 0, int denominator = 1) : numer(numerator), denom(denominator) {
        normalize();
    }

    Rational operator+(const Rational& other) const {
        return Rational(numer * other.denom + other.numer * denom, denom * other.denom);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numer * other.denom - other.numer * denom, denom * other.denom);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numer * other.numer, denom * other.denom);
    }

    Rational operator/(const Rational& other) const {
        return Rational(numer * other.denom, denom * other.numer);
    }

    Rational& operator+=(const Rational& other) {
        *this = *this + other;
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        *this = *this - other;
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        *this = *this * other;
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        *this = *this / other;
        return *this;
    }

    Rational operator++() {
        return *this += Rational(1);
    }

    Rational operator++(int) {
        Rational temp = *this;
        *this += Rational(1);
        return temp;
    }

    Rational operator--() {
        return *this -= Rational(1);
    }

    Rational operator--(int) {
        Rational temp = *this;
        *this -= Rational(1);
        return temp;
    }

    bool operator==(const Rational& other) const {
        return numer == other.numer && denom == other.denom;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    int Numerator() const {
        return numer;
    }

    int Denominator() const {
        return denom;
    }
};
