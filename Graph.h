/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: ronaldo
 *
 * Created on 9 de Março de 2020, 16:42
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"
#include "Link.h"

template<class I1, class I2>
class Graph {
public:

    Graph() { }

    virtual ~Graph() { }

    void add(Node<I1, I2>* node) {
        this->nodes.push_back(node);
    }

    void add(Link<I1, I2>* link) {
        this->links.push_back(link);
    }
    
    void smartAdd(Node<I1, I2>* node) {
        
        if(!this->contains(node)){
            
            this->nodes.push_back(node);
            
            node->list([this](Link<I1,I2> *link){
                this->smartAdd(link);
                return false;
            });            
            
        }
        
    }

    void smartAdd(Link<I1, I2>* link) {
        if(!this->contains(link)){
            this->links.push_back(link);
            this->smartAdd(link->getNode());
        }
    }

    void listNodes(const std::function<bool(Node<I1, I2>*)> &func)const {
        std::find_if(this->nodes.begin(), this->nodes.end(), [&func](Node<I1, I2>* node) {
            return func(node);
        });
    }
    
    void listLinks(const std::function<bool(Link<I1, I2>*)> &func)const {
        std::find_if(this->links.begin(), this->links.end(), [&func](Link<I1, I2>* link) {
            return func(link);
        });
    }
    
    bool contains(Node<I1, I2>* node){
        return this->nodes.end() != std::find(this->nodes.begin(),this->nodes.end(), node);
    }
    
    bool contains(Link<I1, I2>* link){
        return this->links.end() != std::find(this->links.begin(),this->links.end(), link);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Graph<I1, I2>& obj) {
        obj.listNodes([&os](Node<I1,I2> *node){
            os << *node;
            return false;
        });
        return os;
    }


private:

    std::vector<Node<I1, I2>*> nodes;
    std::vector<Link<I1, I2>*> links;

};

#endif /* GRAPH_H */

