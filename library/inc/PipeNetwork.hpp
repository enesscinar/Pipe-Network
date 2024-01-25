#pragma once
#include <string>
#include "Node.hpp"
#include "Tube.hpp"
#include <vector>

namespace cie
{
	namespace pipenetwork
	{
		class PipeNetwork
		{
			public:

			PipeNetwork(const std::string& filename);

			~PipeNetwork();
		
			std::vector<double> computeFluxes() const ;


			private:

			std::vector<Node> nodes_;
			std::vector<Tube> tubes_;

			int numberOfNodes_;
			int numberOfTubes_;

		};

	}
}