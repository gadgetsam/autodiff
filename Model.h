//
// Created by Nameer Hirschkind on 2019-04-15.
//

#ifndef AUTODIFF_MODEL_H
#define AUTODIFF_MODEL_H
#include "Tape.h"
#include "Differentiator.h"
#include "Backprop.h"
#include "Dualdiff.h"

class Model {

    Differentiator* differentiator;

public:
    explicit Model(const std::string& name) {
        if (name=="backprop" || name=="Backprop") {
            differentiator = new Backprop;
        }
        else if (name=="Tape" || name=="tape") {
            differentiator = new Tape;
        }
        else if (name=="dual" || name=="Dual") {
            differentiator = new Dualdiff;
        }
        else {
            differentiator = new Tape;
        }
    }

};


#endif //AUTODIFF_MODEL_H
