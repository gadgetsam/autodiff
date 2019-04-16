//
// Created by Nameer Hirschkind on 2019-04-15.
//

#ifndef AUTODIFF_VECTOR_H
#define AUTODIFF_VECTOR_H
#include "Eigen/Eigen"
#include <iostream>
#include "Model.h"

using Eigen::MatrixXd;

class Vector {
MatrixXd* data;
Model* model;

public:
    explicit Vector(MatrixXd inp) {
        data = &inp;
    }

    MatrixXd extract() {
        return *data;
    }

    void print() {
        std::cout << *data << std::endl;
    }

};


#endif //AUTODIFF_VECTOR_H
