
#include <memory>

int main()
{
	std::unique_ptr<int[]> p(new int[3]);

	std::unique_ptr<int[]> pp = std::make_unique<int[]>(3);

	return 0;
}