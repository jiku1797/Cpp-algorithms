#include <iostream>
#include <ostream>
#include <tuple>
#include <string>

template <typename TupleT, typename UnaryPredicate, std::size_t ...Idxs>
void tupleForEachImpl(TupleT& tup, UnaryPredicate p, std::index_sequence<Idxs...>)
{
    (..., p(std::get<Idxs>(tup)));
}

template <typename TupleT, typename UnaryPredicate,
    std::size_t tupSz = std::tuple_size<TupleT>::value>
void tupleForEach(TupleT& tup, UnaryPredicate p)
{
    tupleForEachImpl(tup, p, std::make_index_sequence<tupSz>{});
}

int main(int argc, char* argv[])
{
    auto myTuple{std::make_tuple(45ull, 42, 5.2)};
    tupleForEach(myTuple, [](auto& elem){elem*=2;});
    std::cout << std::get<0>(myTuple) << '\n';
    std::cout << std::get<1>(myTuple) << '\n';
    std::cout << std::get<2>(myTuple) << '\n';
    return 0;
}
