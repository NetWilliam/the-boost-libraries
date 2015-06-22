/***************************************************************************
 *
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file simpilfy_program3.cpp
 * @author liuweibo01(com@baidu.com)
 * @date 2015/06/22 13:30:39
 * @brief
 *
 **/

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/lambda/lambda.hpp>

#define _AFTER_

void execute_function(boost::function<int (const char *)> fun, const char * str)
{
    std::cout << fun(str) << std::endl;
}

int main()
{
#ifdef _BEFORE_
    std::vector<int(*)(const char*)> processors;
    processors.push_back(std::atoi);
    processors.push_back(reinterpret_cast<int(*)(const char*)>(std::strlen));
#endif
#ifdef _AFTER_
    std::vector<boost::function<int (const char *)> > processors;
    processors.push_back(std::atoi);
    //processors.push_back(reinterpret_cast<int(*)(const char*)>(std::strlen));
    processors.push_back(std::strlen);
#endif

    const char data[] = "1.23";

#ifdef _BEFORE_
    for (std::vector<int(*)(const char*)>::iterator it = processors.begin(); it != processors.end(); ++it) {
        std::cout << (*it)(data) << std::endl;
    }
#endif
#ifdef _AFTER_
    std::for_each(processors.begin(), processors.end(), boost::bind(execute_function, _1, data));
#endif
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
