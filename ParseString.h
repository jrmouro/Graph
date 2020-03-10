/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParseString.h
 * Author: ronaldo
 *
 * Created on 10 de Março de 2020, 16:29
 */

#ifndef PARSESTRING_H
#define PARSESTRING_H

template<class T>
class ParseString {
public:
    virtual T* parse(const std::string &str) = 0;
};

#endif /* PARSESTRING_H */

