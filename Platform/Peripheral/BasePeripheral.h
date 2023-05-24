//
// Created by Whisky on 2023/5/23.
//
#ifndef HELLOWORLD_BASEPERIPHERAL_H
#define HELLOWORLD_BASEPERIPHERAL_H
#include "EmbeddedSystem.h"

class BasePeripheral : public EmbeddedSystem{
public:
    BasePeripheral() = default;
    ~BasePeripheral() = default;

    virtual void init() = 0;
};

#endif //HELLOWORLD_BASEPERIPHERAL_H
