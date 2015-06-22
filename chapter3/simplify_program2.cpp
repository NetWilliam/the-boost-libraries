/***************************************************************************
 *
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file simplify_program2.cpp
 * @author liuweibo01(com@baidu.com)
 * @date 2015/06/22 11:58:14
 * @brief
 *
 **/

#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>

//#define _BEFORE_
#define _AFTER_

void add_size(std::vector<int> &sz_vec, std::string &st)
{
        sz_vec.push_back(st.size());
}

int main()
{
    std::vector<std::string> strings;
    strings.push_back("Boost");
    strings.push_back("C++");
    strings.push_back("Libraries");

    std::vector<int> sizes;
#ifdef _BEFORE_
    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it) {
        sizes.push_back(it->size());
    }
#endif
#ifdef _AFTER_
    //std::for_each(strings.begin(), strings.end(), sizes.push_back(boost::lambda::_1));
    std::for_each(strings.begin(), strings.end(), boost::bind(add_size, boost::ref(sizes), (_1)));
#endif
#ifdef _BEFORE_
    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); ++it) {
        std::cout << *it << std::endl;
    }
#endif
#ifdef _AFTER_
    std::for_each(sizes.begin(), sizes.end(), std::cout << boost::lambda::_1 << "\n");
#endif
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
