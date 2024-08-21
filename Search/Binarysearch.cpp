#include <iostream>
#include <vector>

template <typename Collection>
using ValueType = typename Collection::value_type;

template <typename Collection>
using SizeType = typename Collection::size_type;

template <typename Collection>
int binary_search(const Collection& collection, const ValueType<Collection>& value) noexcept
{
    SizeType<Collection> begin = 0;
    SizeType<Collection> end = collection.size() - 1;

    while (begin <= end)
    {
        SizeType<Collection> middle = begin + (end - begin) / 2;

        if (collection[middle] == value)
        {
            return middle;
        }
        else if (collection[middle] < value)
        {
            begin = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }
    return -1;   
}

int main(int argc, char* argv[])
{
    const std::vector<int> container = { 1, 2, 3, 5, 10, 11, 12, 23, 58, 78, 82, 86, 98, 99 };
    std::cout << "Index: " << binary_search(container, 86) << std::endl;
    
    return EXIT_SUCCESS;
}