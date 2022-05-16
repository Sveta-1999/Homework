#include <iostream>
#include <iterator>
#include <vector>

template <typename Iter>
void advance(Iter& index, int value, std::input_iterator_tag)
{
    while(value != 0)
    {
        ++index;
        --value;
    }
}

template <typename Iter>
void advance(Iter& index, int value, std::bidirectional_iterator_tag)
{
    while(index != value)
    {
        --index;
    }
}

template <typename Iter>
void advance(Iter& index, int value, std::random_access_iterator_tag)
{
    index + value;
}

template <typename Iter>
void advance(Iter& index, int value)
{
    advance(index, value, typename std::__iterator_traits<Iter>::iterator_category);
}

int main() {
    std::vector<int> vec {1,2,3,4,5,6};
}