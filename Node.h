/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: ronaldo
 *
 * Created on 8 de Março de 2020, 17:02
 */

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <functional> 
#include <algorithm>
#include "Link.h"

template<class I1, class I2>
class Node : protected std::vector<Link<I1, I2>*>, public Info<I1> {
public:

    Node(const I1 &info) : std::vector<Link<I1, I2>*>(), Info<I1>(info) {}

    virtual ~Node() {}

    void add(Link<I1, I2> *link) {
        this->push_back(link);
    }

    void smartAdd(Link<I1, I2> *link) {

        if (!this->contains(link)) {

            this->push_back(link);
            
            if (link->isDual()) {
                
                if(link->getDual() != 0){
                    
                    link->getNode()->smartAdd(link->getDual());
                    
                }else{
                    
                    Link<I1,I2> *dual = link->get(this, link->getInfo(), link);
                    link->setDual(dual);
                    link->getNode()->smartAdd(dual);
                    
                }

            }
        }
    }

    int degree() {
        return this->size();
    }

    void list(const std::function<bool(Link<I1, I2>*)> &func)const {
        std::find_if(this->begin(), this->end(), [&func](Link<I1, I2>* link) {
            return func(link);
        });
    }

    friend std::ostream& operator<<(std::ostream& os, const Node<I1, I2>& obj) {
        os << obj.getInfo() << std::endl;
        obj.list([&os](Link<I1, I2> *link) {
            os << "  " << *link << std::endl;
            return false;
        });
        return os;
    }

    bool contains(Link<I1, I2>* link) {
        return this->end() != std::find(this->begin(), this->end(), link);
    }


};

#endif /* NODE_H */

