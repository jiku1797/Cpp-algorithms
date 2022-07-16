#include <iostream>
#include <ostream>
#include <tuple>
#include <string>

/*
*   Two ways to print a std::tuple
*/

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

template <typename TupleT, std::size_t ...idxs>
std::ostream& printImpl(std::ostream& os, const TupleT& tup, const std::index_sequence<idxs...>&)
{
   auto pos{ 0 };
   auto printElem = [&pos, &os](const auto& elem)
   {
      if (pos > 0) os << "   ";
      os << '[' << pos++ << ", " << elem << ']';
   };

   (..., printElem(std::get<idxs>(tup)));
   return os;
}

template <typename ...TupleArgs>
std::ostream& operator<< (std::ostream& os, const std::tuple<TupleArgs...> tup)
{
   return printImpl(os, tup, std::index_sequence_for<TupleArgs...>{});
}

int main(int argc, char* argv[])
{
    const std::tuple myTup{3.14, std::string{"hej"}, 42.4};
    printTupleApplyFn<' ', true>(myTup); // 1st way...
    std::cout << myTup << '\n'; // ...and 2nd way
    return 0;
}
