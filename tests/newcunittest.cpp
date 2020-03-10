/*
 * File:   newcunittest.cpp
 * Author: ronaldo
 *
 * Created on 09/03/2020, 16:10:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Info.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testInfo() {
    T info;
    Info info(info);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testGetInfo() {
    Info info;
    T result = info.getInfo();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testSetInfo() {
    T info;
    Info info;
    info.setInfo(info);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testInfo", testInfo)) ||
            (NULL == CU_add_test(pSuite, "testGetInfo", testGetInfo)) ||
            (NULL == CU_add_test(pSuite, "testSetInfo", testSetInfo))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
