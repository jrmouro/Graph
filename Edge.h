/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.h
 * Author: ronaldo
 *
 * Created on 9 de Março de 2020, 16:47
 */

#ifndef EDGE_H
#define EDGE_H

#include "Link.h"

template<class I1, class I2>
class Edge : public Link<I1,I2>{
    
    private:
        
        Link<I1,I2>* dual;
    
    public:
        
        Edge(Node<I1, I2> *node, const I2 &info) : Link<I1, I2>(node, info), dual(0) {}
        
        Edge(Node<I1, I2> *node, const I2 &info, Link<I1,I2>* dual) : Link<I1, I2>(node, info), dual(dual) {}
        
        
        virtual bool isDual(){
            return true;
        }
        
        virtual Link<I1,I2>* getDual(){
            return this->dual;
        }
        
        void setDual(Link<I1, I2>* dual) {
            this->dual = dual;
        }
        
        virtual Link<I1,I2>* get(Node<I1,I2> *node, const I2 &info){
            return new Edge<I1,I2>(node, info);
        }
        
        virtual Link<I1,I2>* get(Node<I1,I2> *node, const I2 &info, Link<I1,I2>* dual){
            return new Edge<I1,I2>(node, info, dual);
        }

};

#endif /* EDGE_H */

