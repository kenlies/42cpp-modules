
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data
{
	int num;
};

class Serializer
{
	private:
		Serializer();
		Serializer( const Serializer &bur );
		Serializer &operator=( const Serializer &bur );
		virtual ~Serializer() = 0;

	public:
		static uintptr_t serialize( Data* ptr );
		static Data* deserialize( uintptr_t raw );
};

#endif