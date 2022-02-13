#include "CoreTypes.h"

#include <iostream>
#include <Memory/Allocator.h>

class Test
{
public:
	~Test()
	{
		printf("Called dctor\n");
	}

private:

};



int main()
{
	Allocator<int32> alloc;

	int32* t = (int32*)alloc.Allocate(1);
	alloc.Destruct(t);
}