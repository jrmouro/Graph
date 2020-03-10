/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arch.h
 * Author: ronaldo
 *
 * Created on 9 de Março de 2020, 16:50
 */

#ifndef ARCH_H
#define ARCH_H

#include "Node.h"


template<class I1, class I2>
class Arch : public Link<I1,I2>{
public:
    
    Arch(Node<I1, I2>* node, const I2 &info) : Link<I1, I2>(node, info) { }
        
    virtual bool isDual(){
        return false;
    }
            
    virtual Link<I1,I2>* get(Node<I1,I2> *node, const I2 &info, Link<I1,I2>* dual){
        return this->get(node, info);
    }
    
    virtual Link<I1,I2>* get(Node<I1,I2> *node, const I2 &info) = 0;
    
    
};

#endif /* ARCH_H */

