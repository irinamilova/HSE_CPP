#include <numeric>
#include <iostream>

using namespace std;

class Rational
{
private:
    int n;
    int d;
    void Reduce()
    {
        int x = gcd(n, d);
        n /= x;
        d /= x;
        if (d < 0)
        {
            n *= -1;
            d *= -1;
        }
    }

public:
    Rational(int num = 0, int den = 1) : n(num), d(den)
    {
        Reduce();
    }
    int numerator() const
    {
        return n;
    }
    int denominator() const
    {
        return d;
    }
    Rational operator+() const
    {
        return {n, d};
    }
    Rational operator-() const
    {
        return Rational(-n, d);
    }
    Rational& operator+=(const Rational& x)
    {
        n = n * x.d + x.n * d;
        d *= x.d;
        Reduce();
        return *this;
    }
    Rational& operator-=(const Rational& x)
    {
        n = n * x.d - x.n * d;
        d *= x.d;
        Reduce();
        return *this;
    }
    Rational& operator*=(const Rational& x)
    {
        n *= x.n;
        d *= x.d;
        Reduce();
        return *this;
    }
    Rational& operator/=(const Rational& x)
    {
        int var = x.n;
        n *= x.d;
        d *= var;
        Reduce();
        return *this;
    }
};

Rational operator+(const Rational& y, const Rational& x)
{
    Rational result = y;
    result += x;
    return result;
}
Rational operator-(const Rational& y, const Rational& x)
{
    Rational result = y;
    result -= x;
    return result;
}
Rational operator*(const Rational& y, const Rational& x)
{
    Rational result = y;
    result *= x;
    return result;
}
Rational operator/(const Rational& y, const Rational& x)
{
    Rational result = y;
    result /= x;
    return result;
}
bool operator==(const Rational& y, const Rational& x)
{
    return y.numerator() == x.numerator() && y.denominator() == x.denominator();
}
bool operator!=(const Rational& y, const Rational& x)
{
    return !(y == x);
}
Rational& operator++(Rational& x)
{
    x += Rational(1);
    return x;
}
Rational operator++(Rational& x, int)
{
    Rational var = x;
    x += Rational(1);
    return var;
}
Rational& operator--(Rational& x)
{
    x -= Rational(1);
    return x;
}
Rational operator--(Rational& x, int)
{
    Rational var = x;
    x -= Rational(1);
    return var;
}
