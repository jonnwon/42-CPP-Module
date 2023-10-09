#include "Serializer.hpp"

int main()
{
	Data *data = new Data;

	data->str = "abc";
	data->num = 123;

	std::cout << "=== data ===" << std::endl;
	std::cout << "str: " << data->str << std::endl;
	std::cout << "num: " << data->num << std::endl;

	uintptr_t ptr = Serializer::serialize(data);

	Data *data2 = Serializer::deserialize(ptr);

	std::cout << "=== data2 ===" << std::endl;
	std::cout << "str: " << data2->str << std::endl;
	std::cout << "num: " << data2->num << std::endl;
	
	delete data;

	return 0;
}
