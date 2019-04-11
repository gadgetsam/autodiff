//
// Created by Nameer Hirschkind on 2019-03-14.
//
#include <iostream>
#include <math.h>
#ifndef FORWARDAUTODIFF_DUAL_H
#define FORWARDAUTODIFF_DUAL_H


class Dual {
double real;
double dual;

public:
    explicit Dual(double r) { real = r; dual = 0;}
    Dual(double r, double d) { real = r; dual = d;}


    double r() const {return real;}
    double d() const {return dual;}

    void operator+=(const Dual& b) {
        real+=b.r();
        dual+=b.d();
    }

    void operator+=(const double& b) {
        real+=b;
    }

    void operator-=(const Dual& b) {
        real-=b.r();
        dual-=b.d();
    }

    void operator-=(const double& b) {
        real-=b;
    }
};
std::ostream & operator << (std::ostream &out, const Dual &d)
{
    out << d.r();
    out << " + "<<d.d()<<" epsilon" << std::endl;
    return out;
}


Dual operator+ (const Dual& a, const Dual& b) {
    return Dual(a.r()+b.r(),b.d()+a.d());
}

Dual operator+(const Dual& a, const double& b) {
    return a+Dual(b);
}

Dual operator+(const double& a,const Dual& b) {
    return  Dual(a)+b;
}

Dual operator- (const Dual& a, const Dual& b) {
    return Dual(a.r()-b.r(),a.d()-b.d());
}

Dual operator-(const Dual& a,const double& b) {
    return a-Dual(b);
}

Dual operator-(const double& a, const Dual& b) {
    return Dual(a)-b;
}

Dual operator-(const Dual& a) {
    return Dual(-a.r(),-a.d());
}


Dual operator*(const Dual& a, const Dual& b) {
    return Dual(a.r()*b.r(),a.r()*b.d()+a.d()*b.r());
}

Dual operator*(const Dual& a, const double& b) {
    return a*Dual(b);
}

Dual operator*(const double& a,const Dual& b) {
    return Dual(a)*b;
}

Dual operator/(const Dual& a, const Dual& b) {
    return Dual(a.r()/b.r(),(a.d()*b.r() - a.r()*b.d()) / (b.r()*b.r()));
}

Dual operator/(const Dual& a, const double& b) {
    return a/Dual(b);
}

Dual operator/(const double& a, const Dual& b) {
    return Dual(a)/b;
}

Dual square(const Dual& a) {
    return a*a;
}

Dual pow(const Dual& a,const double& b) {
    return Dual(pow(a.r(),b),a.d()*b*pow(a.r(),b-1));
}

Dual exp(const Dual& a) {
    return Dual(exp(a.r()),a.d()*exp(a.r()));
}

Dual sin(const Dual& a) {
    return Dual(sin(a.r()),a.d()*cos(a.r()));
}

Dual cos(const Dual& a) {
    return Dual(cos(a.r()),-a.d()*sin(a.r()));
}

Dual tan(const Dual& a) {
    return Dual(tan(a.r()),a.d()*pow(1/cos(a.r()),2));
}
#endif //FORWARDAUTODIFF_DUAL_H
