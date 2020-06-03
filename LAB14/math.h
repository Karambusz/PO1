#pragma once
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <string>

template<int n,const double *x1,const double *x2>
class IntegralXn{
public:
    static constexpr double value = n > 0 ? (pow(*x2, n+1)/(n+1)) - (pow(*x1, n+1)/(n+1)) : 0.0;
};

template<typename T>
class GroupZn {
public:
    int size;
    std::map<int, T> mp1;
    std::map<T, int> mp2;
    GroupZn(const std::vector<T> &vec){
        size = vec.size();
        for(int i = 0; i < size; i++){
            mp1[i+1] = vec.at(i);
            mp2[vec.at(i)] = i;
        }
    }
    T operator() (T a, T b){
        int tmp = mp2[a] + mp2[b];
        if(tmp<size){
            return mp1[tmp+1];
        }
        return mp1[tmp+1-size];
    }
};