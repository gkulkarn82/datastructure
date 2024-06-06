/*
std::reference_wrapper is a class template that wraps a reference in a copyable, assignable object.

Specifically, std::reference_wrapper is a CopyConstructible and CopyAssignable wrapper around a 
reference to object or reference to function of type T

Instances of std::reference_wrapper are objects (they can be copied or stored in containers) but they 
are implicitly convertible to T&, so that they can be used as arguments with the functions that take the 
underlying type by reference.

If the stored reference is Callable, std::reference_wrapper is callable with the same arguments.

Helper functions std::ref and std::cref are often used to generate std::reference_wrapper objects.

std::reference_wrapper is used to pass objects by reference to std::bind, the constructor of std::thread, 
or the helper functions std::make_pair and std::make_tuple. It can also be used as a mechanism to store 
references inside standard containers (like std::vector) that cannot normally hold references.

*/

/*
std::reference_wrapper implementation

namespace detail
{
    template<class T> constexpr T& FUN(T& t) noexcept { return t; }
    template<class T> void FUN(T&&) = delete;
}
 
template<class T>
class reference_wrapper
{
public:
    // types
    using type = T;
 
    // construct/copy/destroy
    template<class U, class = decltype(
        detail::FUN<T>(std::declval<U>()),
        std::enable_if_t<!std::is_same_v<reference_wrapper, std::remove_cvref_t<U>>>()
    )>
    constexpr reference_wrapper(U&& u)
        noexcept(noexcept(detail::FUN<T>(std::forward<U>(u))))
        : _ptr(std::addressof(detail::FUN<T>(std::forward<U>(u)))) {}
 
    reference_wrapper(const reference_wrapper&) noexcept = default;
 
    // assignment
    reference_wrapper& operator=(const reference_wrapper& x) noexcept = default;
 
    // access
    constexpr operator T& () const noexcept { return *_ptr; }
    constexpr T& get() const noexcept { return *_ptr; }
 
    template<class... ArgTypes>
    constexpr std::invoke_result_t<T&, ArgTypes...>
        operator() (ArgTypes&&... args ) const
            noexcept(std::is_nothrow_invocable_v<T&, ArgTypes...>)
    {
        return std::invoke(get(), std::forward<ArgTypes>(args)...);
    }
 
private:
    T* _ptr;
};
 
// deduction guides
template<class T>
reference_wrapper(T&) -> reference_wrapper<T>;



*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>
 
void print(auto const rem, std::ranges::range auto const& v)
{
    for (std::cout << rem; auto const& e : v)
        std::cout << e << ' ';
    std::cout << '\n';
}
 
int main()
{
    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);
 
    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
 
    std::ranges::shuffle(v, std::mt19937{std::random_device{}()});
 
    print("Contents of the list: ", l);
    print("Contents of the list, as seen through a shuffled vector: ", v);
 
    std::cout << "Doubling the values in the initial list...\n";
    std::ranges::for_each(l, [](int& i) { i *= 2; });
 
    print("Contents of the list, as seen through a shuffled vector: ", v);
}