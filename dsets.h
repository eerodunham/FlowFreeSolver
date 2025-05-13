#pragma once

#include <vector>
#include <deque>
#include <iostream>
class DisjointSets
{
public:
    void addelements(int num);

    int find(int elem);

    void setunion(int a, int b);

    int size(int elem);

    int getValue(int elem) const;

private:
    std::vector<int> elems_;
};
