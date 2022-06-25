#include <iostream>
#include <ostream>
#include <tuple>
#include <string>

template <char delim, bool printIdx, typename ...Args>
void printImpl(const Args&... args)
{
    auto idx{0};
    auto printElem = [&idx](const auto& elem)
    {
        if(idx > 0)
            std::cout << delim;

        if(printIdx)
            std::cout << "(" << idx << ", ";
        std::cout << elem;
        if(printIdx)
            std::cout << ")";

        ++idx;
    };

    (..., printElem(args));
    std::cout << '\n';
}

template <char delim=' ', bool printIdx=false, typename ...Args>
void printTupleApplyFn(const std::tuple<Args...>& tup)
{
    std::apply(printImpl<delim, printIdx, Args...>, tup);
}

int main(int argc, char* argv[])
{
    const std::tuple myTup{3.14, std::string{"hej"}, 42.4};
    printTupleApplyFn<' ', true>(myTup);
    return 0;
}
