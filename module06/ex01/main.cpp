#include "Serializer.hpp"

int main ()
{
	struct Data *data = new Data;
	data->num = 10;
	uintptr_t res = Serializer::serialize(data);
	std::cout << res << "\n";
	data = Serializer::deserialize(res);
	std::cout << data->num << "\n";

	delete data;

	return 0;
}