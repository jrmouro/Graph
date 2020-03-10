/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: ronaldo
 *
 * Created on 8 de Março de 2020, 21:56
 */

#ifndef LINK_H
#define LINK_H

#include "Info.h"

template<class I1,class I2>
class Node;

template<class I1,class I2>
class Link : public Info<I2>{

    private:
        
        Node<I1,I2> *node;
    
    public:

        Link(Node<I1,I2> *node, const I2 &info) : Info<I2>(info), node(node){}
        
        virtual ~Link(){}
        
        Node<I1, I2>* getNode() const { return node; }
        
        friend std::ostream& operator<<(std::ostream& os, const Link<I1, I2>& obj) {
            os << obj.getInfo() << " (" << obj.getNode()->getInfo() << ")";
            return os;
        }

        virtual bool isDual() = 0; 
        
        virtual Link<I1,I2>* get(Node<I1,I2> *node, const I2 &info) = 0;
        virtual Link<I1,I2>* get(Node<I1,I2> *node, const I2 &info, Link<I1,I2>* dual) = 0;
        
        virtual Link<I1,I2>* getDual(){
            return 0;
        }
        
        virtual void setDual(Link<I1,I2>* link){}
        
};

#endif /* LINK_H */

