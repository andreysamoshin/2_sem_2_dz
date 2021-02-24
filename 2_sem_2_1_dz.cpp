#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = { 1, 2, 3 };
	v.resize(100);
	v.push_back(1);
	std::cout << v.capacity() << std::endl;


	for (int i = 0; i < 3; i++)
	{
		int cap = v.capacity();
		std::cout << "Vector capacity before added elements:" << std::endl;
		std::cout << cap << std::endl;
		int size = v.size();
		std::cout << "Vector size before added elements:" << std::endl;
		std::cout << v.size() << std::endl;
		int delta = cap - size;
		for (int j = 0; j < delta + 1; j++)
		{
			v.push_back(j);
		}
		std::cout << "Vector capacity after added elements:" << std::endl;
		std::cout << v.capacity() << std::endl;
		std::cout << "Vector size before added elements:" << std::endl;
		std::cout << v.size() << std::endl;
	}



	// the cycle shown above shows that vector capacity is multiplied by 3/2 every time the previous capa
	// city is full

	std::cout << "\nUsing the reserve() member function" << std::endl;

	std::vector < int > v_2;
	v_2.reserve(5);

	std::cout << "Size      = " << v_2.size() << std::endl;
	std::cout << "Capacity  = " << v_2.capacity() << std::endl;


	// Lets try to reserve huge amount of memory
	try
	{
		v.reserve(1e11); //for example, let's try to reserve 10^11 elements
	}
	catch (std::exception& except)
	{
		std::cerr << "\nLimiting case\n" << except.what() << std::endl;
	}

	system("pause");


	return EXIT_SUCCESS;

}