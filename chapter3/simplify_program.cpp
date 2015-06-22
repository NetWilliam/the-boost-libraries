/***************************************************************************
 *
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file simplify_program.cpp
 * @author liuweibo01(com@baidu.com)
 * @date 2015/06/20 17:42:38
 * @brief
 *
 **/

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>

#define _AFTER_ 1

#ifdef _BEFORE_
class divide_by
        : public std::binary_function<int, int, int> {
public:
    int operator()(int n, int div) const {
        return n / div;
    }
};
#endif

#ifdef _AFTER_
int divide_by(int n, int div)
{
        std::cout << "first param n get: " << n << std::endl;
        std::cout << "div get: " << div << std::endl;
        return n / div;
}
#endif

int main()
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

#ifdef _BEFORE_
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), std::bind2nd(divide_by(), 2));

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }
#endif

#ifdef _AFTER_
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), boost::bind(divide_by, 300, _1));
    std::for_each(numbers.begin(), numbers.end(), std::cout << boost::lambda::_1 << "\n");
    //std::cout << ((boost::bind(divide_by, _1, 2))(3)) << std::endl;
#endif
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
