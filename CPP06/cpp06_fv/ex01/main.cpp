#include "Serializer.hpp"

int main()
{
	Data data;

	data.str = "abc";
	data.num = 123;

	std::cout << "=== data ===" << std::endl;
	std::cout << "str: " << data.str << std::endl;
	std::cout << "num: " << data.num << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);

	Data *s_data = Serializer::deserialize(ptr);

	std::cout << "=== s_data ===" << std::endl;
	std::cout << "str: " << s_data->str << std::endl;
	std::cout << "num: " << s_data->num << std::endl;

	return 0;
}
