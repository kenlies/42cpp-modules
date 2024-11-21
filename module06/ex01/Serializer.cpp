#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer( const Serializer &scal )
{
	*this = scal;
}

Serializer &Serializer::operator=( const Serializer &scal )
{
	if (this != &scal)
	{
		*this = scal;
	}
	return *this;
}

Serializer::~Serializer()
{
}


uintptr_t	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data*>(raw);
}