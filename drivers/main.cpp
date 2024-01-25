#include "PipeNetwork.hpp"
#include <iostream>

int main()
{

	cie::pipenetwork::PipeNetwork network("pipedata.txt"); // Use input file path in the computer like: "C:\\Users\\.....\\source\\pipedata.txt"

	std::vector<double> Fluxes = network.computeFluxes();
	
	std::cout << "Fluxes at tubes: \n" << std::endl;

	for (size_t i = 0; i < Fluxes.size(); i++)
	{
		std::cout << i+1 << ":  " << Fluxes[i] << std::endl;
	}


}

