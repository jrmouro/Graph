/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: ronaldo
 *
 * Created on 08/03/2020, 17:22:35
 */

#include "newtestclass.h"
#include "Vertex.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testVertex() {
    const INFO1& info;
    Vertex vertex(info);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

