#include <iostream>
#include <iterator>
#include <vector>


template <typename Iter, typename T>
Iter find(Iter begin, Iter end, T& elem)
{
    while (begin != end)
    {
        if(*begin == elem)
        {
            return begin;
        }
        ++begin;
    }
    return begin;
    
}

int main() {
    std::vector<int> vec {1,2,3,4,5,6,7};
    int n = 5;
    auto result =  find(begin(vec), end(vec), n);
    std::cout << *result;
    return 0;
}