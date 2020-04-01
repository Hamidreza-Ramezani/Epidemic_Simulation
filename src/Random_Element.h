/*
 * Random_Element.h
 *
 *  Created on: Apr 1, 2020
 *      Author: guest
 */
#include  <random>
#include <iostream>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
	std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
	std::advance(start, dis(g));
	return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return select_randomly(start, end, gen);
}

//template<typename Iter>
//Iter random_element(Iter start, Iter end) {
//    std::advance(start, rand() % (std::distance(start, end) - 1));
//    return start;
//}

//template <typename I>
//I random_element(I begin, I end)
//{
//    const unsigned long n = std::distance(begin, end);
//    const unsigned long divisor = (RAND_MAX + 1) / n;
//
//    unsigned long k;
//    do { k = std::rand() / divisor; } while (k >= n);
//
//    std::advance(begin, k);
//    return begin;
//}
