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

	return EXIT_SUCCESS;

}

// приведённый выше цикл доказывает, что коэффициент умножения ёмкости вектора - 3/2