#include "easyfind.hpp"
#include <vector>

int main()
{
  // º¤ÅÍ »ý¼º
  std::vector<int> v;

  for (int i = 0; i < 5; i++)
	  v.push_back(i);

  std::vector<int>::iterator it = v.begin() + 1;

  std::cout << *it;

  std::cout << *easyfind(v, 3);

	return 0;
}
