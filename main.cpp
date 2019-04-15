//
// Created by Nameer Hirschkind on 2019-04-15.
//
#include "Vector.h"

int main () {
    MatrixXd x(2,2);
    Vector* y = new Vector(x);
    y->print();
    return 0;
};
