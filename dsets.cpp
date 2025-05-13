#include "dsets.h"
void DisjointSets::addelements(int num)
{
    std::vector<int> to_add(num, -1);
    elems_.insert(elems_.end(), to_add.begin(), to_add.end());
}

int DisjointSets::find(int elem)
{
    int idx = elem;
    std::deque<int> path;
    while (elems_[idx] >= 0)
    {
        path.push_back(idx);
        idx = elems_[idx];
    }
    while (!path.empty())
    {
        elems_[path.front()] = idx;
        path.pop_front();
    }
    return idx;
}

void DisjointSets::setunion(int a, int b)
{
    int a_canonical = find(a);
    int b_canonical = find(b);
    if (a_canonical == b_canonical)
        return;
    int a_size = elems_[a_canonical];
    int b_size = elems_[b_canonical];
    if ((-1 * a_size) < (-1 * b_size))
    {
        elems_[a_canonical] = b_canonical;
        elems_[b_canonical] = a_size + b_size;
    }
    else
    {
        elems_[b_canonical] = a_canonical;
        elems_[a_canonical] = a_size + b_size;
    }
}

int DisjointSets::size(int elem)
{
    return -1 * elems_[find(elem)];
}

int DisjointSets::getValue(int elem) const
{
    return elems_[elem];
}