#include <iostream>
#include <cmath>

class Complex
{
private:
    double real, imag;

public:
    Complex(double real, double imag);
    Complex(double real);
    double Re() const;
    double Im() const;
    Complex operator+(const Complex& x) const
    {
        return Complex{real + x.real, imag + x.imag};
    }
    Complex operator-(const Complex& x) const
    {
        return Complex{real - x.real, imag - x.imag};
    }
    Complex operator*(const Complex& x) const
    {
        return Complex{(real * x.real) - (imag * x.imag), (imag * x.real) + (real * x.imag)};
    }
    Complex operator*(double x) const
    {
        return (*this) * Complex(x);
    }
    Complex operator/(const Complex& x) const
    {
        return Complex{((real * x.real) + (imag * x.imag)) / ((x.real * x.real) + (x.imag * x.imag)),
                       ((x.real * imag) - (real * x.imag)) / ((x.real * x.real + x.imag * x.imag))};
    }
    Complex operator/(double x) const
    {
        return *this / Complex(x);
    }
    bool operator==(const Complex& x) const
    {
        return (real == x.real) && (imag == x.imag);
    }

    bool operator!=(const Complex& x) const
    {
        return !(*this == x);
    }
    Complex operator-() const
    {
        return Complex(-real, -imag);
    }
    Complex operator+() const
    {
        return *this;
    }
};

Complex operator+(double y, const Complex& x)
{
    return x + y;
}
Complex operator-(double y, const Complex& x)
{
    return y - x;
}
Complex operator*(double y, const Complex& x)
{
    return x * Complex(y);
}
Complex operator/(double y, const Complex& x)
{
    return Complex(y) / x;
}
Complex::Complex(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}

Complex::Complex(double re)
{
    real = re;
}
double Complex::Re() const
{
    return real;
}
double Complex::Im() const
{
    return imag;
}
double abs(const Complex& x)
{
    return std::sqrt((x.Im() * x.Im()) + (x.Re() * x.Re()));
}
