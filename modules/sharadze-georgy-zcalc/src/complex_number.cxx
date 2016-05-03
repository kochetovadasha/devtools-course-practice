// Copyright 2016 Sharadze Georgy

#include "include/complex_number.h"
#include <string>
#include <limits>

const double epsilon = std::numeric_limits<double>::epsilon();

ComplexNumber::ComplexNumber() {
    re = 0.0;
    im = 0.0;
}

ComplexNumber::ComplexNumber(double _re, double _im) {
    re = _re;
    im = _im;
}

ComplexNumber::ComplexNumber(const ComplexNumber& z) {
    re = z.re;
    im = z.im;
}

double ComplexNumber::getRe() const {
    return re;
}

double ComplexNumber::getIm() const {
    return im;
}

void ComplexNumber::setRe(const double _re) {
    re = _re;
}

void ComplexNumber::setIm(const double _im) {
    im = _im;
}

ComplexNumber ComplexNumber::operator + (const ComplexNumber& z) const {
    ComplexNumber result;
    result.setRe(getRe() + z.getRe());
    result.setIm(getIm() + z.getIm());
    return result;
}

ComplexNumber ComplexNumber::operator - (const ComplexNumber& z) const {
    ComplexNumber result;
    result.setRe(getRe() - z.getRe());
    result.setIm(getIm() - z.getIm());
    return result;
}

ComplexNumber ComplexNumber::operator * (const ComplexNumber& z) const {
    ComplexNumber result;
    result.setRe((getRe() * z.getRe()) - (getIm() * z.getIm()));
    result.setIm((getRe() * z.getIm()) + (getIm() * z.getRe()));
    return result;
}

ComplexNumber ComplexNumber::operator / (const ComplexNumber& z) const {
    if (equalsToZero(z)) {
        throw std::string("Can\'t divide with zero");
    } else {
        ComplexNumber result;
        result.setRe((getRe() * z.getRe() + getIm() * z.getIm())
                     / (z.getRe() * z.getRe() + z.getIm() * z.getIm()));
        result.setIm((z.getRe() * getIm() - getRe() * z.getIm())
                     / (z.getRe() * z.getRe() + z.getIm() * z.getIm()));
        return result;
    }
}

ComplexNumber& ComplexNumber::operator = (const ComplexNumber& z) {
    setRe(z.re);
    setIm(z.im);
    return *this;
}

bool ComplexNumber::operator == (const ComplexNumber& z) const {
    return equalsToZero(*this - z);
}

bool ComplexNumber::operator != (const ComplexNumber& z) const {
    return !(*this == z);
}

bool ComplexNumber::equalsToZero(const ComplexNumber& z) const {
    return z.getRe() <= epsilon && z.getRe() >= -epsilon &&
           z.getIm() <= epsilon && z.getIm() >= -epsilon;
}

ComplexNumber calc(const ComplexNumber& z1,
                   const ComplexNumber& z2,
                   const char op) {
    ComplexNumber result;
    switch (op) {
    case '+':
        result = z1 + z2;
        break;
    case '-':
        result = z1 - z2;
        break;
    case '*':
        result = z1 * z2;
        break;
    case '/':
        result = z1 / z2;
        break;
    default:
        throw std::string("Wrong operation format!");
    }
    return result;
}
