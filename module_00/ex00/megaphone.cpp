#include <iostream>
#include <string>
#include <cctype> // std::toupper

int main(int argc, char** argv)
{
	int	i;
	int	j;
	std::string resultado;

	i = 1;
	j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		while (i < argc)
		{
			j = 0;
			resultado = "";
			while (argv[i][j]!= '\0')
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				{
					unsigned char uc = static_cast<unsigned char>(argv[i][j]);
					resultado += static_cast<char>(std::toupper(uc));
					//doble cast for types security and for functions params
				}
				else
					resultado += argv[i][j];
				j++;
			}
			std::cout << resultado;
			i++;
		}
		std::cout << std::endl;
	}
}