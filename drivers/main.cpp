#include "PipeNetwork.hpp"
#include <iostream>

int main()
{

	cie::pipenetwork::PipeNetwork network("C:\\Users\\eness\\Desktop\\CIE1\\MTT\\source\\pipedata.txt");

	std::vector<double> Fluxes = network.computeFluxes();
	
	std::cout << "Fluxes at tubes: \n" << std::endl;

	for (size_t i = 0; i < Fluxes.size(); i++)
	{
		std::cout << i+1 << ":  " << Fluxes[i] << std::endl;
	}


}

