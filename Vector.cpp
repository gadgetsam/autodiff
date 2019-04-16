//
// Created by Nameer Hirschkind on 2019-04-15.
//

#include "Vector.h"

Vector operator+ (const Vector& a, const Vector& b) {

    return Vector(a.extract()*b.extract());
}