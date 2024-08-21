#include <iostream>
#include <vector>

template <typename Collection>
using ValueType = typename Collection::value_type;

template <typename Collection>
using SizeType = typename Collection::size_type;

template <typename Collection>
int linear_search_non_recursive(const Collection& collection, const ValueType<Collection>& value) noexcept
{
    for (SizeType<Collection> index = 0; index < collection.size() - 1; ++index)
    {
        if (collection[index] == value)
        {
            return index;
        }
    }

    return -1;
}

template<typename Collection>
int linear_search_recursive(const Collection& collection, const ValueType<Collection>& value, SizeType<Collection> index) noexcept
{
    if (collection.size() == index)
    {
        return -1;
    }
    else if (collection[index] == value)
    {
        return index;
    }
    else
    {
        return linear_search_recursive(collection, value, index + 1);
    }
}

int main(int argc, char* argv[])
{
    const std::vector<int> container = { 1, 2, 3, 5, 32, 11, 12, 45, 58, 9, 0, 86, 98, 1 };
    std::cout << "Index: " << linear_search_recursive(container, 58, 0) << std::endl;
    std::cout << "Index: " << linear_search_non_recursive(container, 11) << std::endl;

    return EXIT_SUCCESS;
}