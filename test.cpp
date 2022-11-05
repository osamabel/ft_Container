#include <iostream>
#include <string>
#include <memory>
#include <stdbool.h>
class c
{
public:
	void operator () (std::string x)
	{
		std::cout << "class : " << x << std::endl;
	}
};

void foo(std::string x)
{
	std::cout << "function : " << x << std::endl;
}

template <class T, int S> class dim
{
	static_assert(S > 2,"lol");
	T l;
};

int main ()
{
	// c foo;
	// foo("osama");
	// dim<int, 4> d;
	// dim<int, 0> s;
	std::allocator<int> alloc;
	int *p = alloc.allocate(4611686018);
	std::cout << alloc.max_size();
// while (1);
	return 0;
}