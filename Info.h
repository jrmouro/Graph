/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Info.h
 * Author: ronaldo
 *
 * Created on 8 de Março de 2020, 22:39
 */

#ifndef INFO_H
#define INFO_H

template<class T>
class Info{
    
private:
    
    T info;
    
public:
    
    Info(const T &info) : info(info) {}
    
    virtual ~Info(){}
    
    T getInfo() const {
        return info;
    }

    void setInfo(const T &info) {
        this->info = info;
    }
    
    
    friend std::ostream& operator<<(std::ostream& os, const Info<T>& obj) {
        os << obj.getInfo();
        return os;
    }


};

#endif /* INFO_H */

