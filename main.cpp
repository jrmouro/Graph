/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ronaldo
 *
 * Created on 8 de Março de 2020, 17:01
 */

#include <iostream>

#include "Graph.h"
#include "Node.h"
#include "Arch.h"
#include "Edge.h"

using namespace std;

class Pessoa{
public:
    std::string nome;
    Pessoa(std::string nome) : nome(nome) {}
    
    
    virtual std::string toString()const{
        return this->nome;
    }
};

class Aluno: public Pessoa{
public:
    std::string matricula;
    Aluno(std::string nome, std::string matricula) : Pessoa(nome), matricula(matricula) {}

    virtual std::string toString()const{
        return Pessoa::toString() + " - " + this->matricula;
    }
    
    
    friend std::ostream& operator<<(std::ostream& os, const Aluno& obj) {
        os << obj.toString();
        return os;
    }
    

};

class AlGraph : public Graph<Aluno,float>{
public:
    AlGraph() : Graph<Aluno,float>() {}
        
};


class AlNode : public Node<Aluno,float>{
public:
    AlNode(const Aluno &aluno) : Node<Aluno,float>(aluno) { }
};


class AlFloatLink : public Arch<Aluno,float>{
public:
    AlFloatLink(AlNode* node, const float& info) : Arch<Aluno,float>(node, info) {}    
};




/* 
 * 
 */
int main(int argc, char** argv) {
    
    
    Aluno vitor("Vitor", "123");
    Aluno isa("Isa", "456");
    Aluno pedro("Pedro", "789");
    Aluno maria("Maria", "321");
    
    
    AlNode nVitor(vitor);
    AlNode nIsa(isa);
    AlNode nPedro(pedro);
    AlNode nMaria(maria);
    
    nVitor.smartAdd(new AlFloatLink(&nIsa, 1.0));
    nPedro.smartAdd(new AlFloatLink(&nMaria, 1.0));
    nMaria.smartAdd(new AlFloatLink(&nVitor, 0.5));
    
    AlGraph g;
    
    g.smartAdd(&nVitor);
    g.smartAdd(&nPedro);
    
    
    
    
    
    cout << g;
   
    
    
    
    
    
  

    return 0;
    
}

