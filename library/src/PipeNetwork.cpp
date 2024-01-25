#include "PipeNetwork.hpp"
#include "linalg.hpp"
#include <fstream>
#include <iostream>

namespace cie
{
	namespace pipenetwork
	{
		PipeNetwork::PipeNetwork(const std::string& filename) {

			std::ifstream inputFile(filename);

			inputFile >> numberOfNodes_; 
			inputFile >> numberOfTubes_; 

			nodes_.reserve(numberOfNodes_);
			tubes_.reserve(numberOfTubes_);
			
			for (int i = 0; i < numberOfNodes_; ++i)
			{
				double x, y, flow;

				inputFile >> x;
				inputFile >> y;
				inputFile >> flow;

				Node node(x, y, flow, i);

				nodes_.push_back(node);
			}

			for (int i = 0; i < numberOfTubes_; ++i)
			{
				int id1, id2;
				double d_;

				inputFile >> id1;
				inputFile >> id2;
				inputFile >> d_;

				Tube tube(&nodes_[id1], &nodes_[id2], d_);

				tubes_.push_back(tube);
			}		
		}
		
		std::vector<double> PipeNetwork::computeFluxes() const {
			
			cie::linalg::Matrix B(numberOfNodes_, numberOfNodes_, 0.0);
			
			for (int i = 0; i < numberOfTubes_; i++)
			{
				int id1 = tubes_[i].node1()->id();
				int id2 = tubes_[i].node2()->id();

				B(id1, id1) += tubes_[i].permeability();
				B(id2, id2) += tubes_[i].permeability();
				B(id1, id2) -= tubes_[i].permeability();
				B(id2, id1) -= tubes_[i].permeability();
			}

			std::vector<double> Q;

			Q.reserve(numberOfNodes_);

			for (int i = 0; i < numberOfNodes_; i++)
			{
				Q.push_back(-1*nodes_[i].flow());
			}

			for (int i = 0; i < numberOfNodes_; i++)
			{
				B(i, 0) = 0;
				B(0, i) = 0;
			}

			B(0, 0) = 1;
			Q[0] = 0;

			std::vector<double> h;

			h = cie::linalg::solve(B, Q);

			std::vector<double> q(numberOfTubes_, 0.0);

			for (int i = 0; i < numberOfTubes_; i++)
			{
				int id1 = tubes_[i].node1()->id();
				int id2 = tubes_[i].node2()->id();
				q[i] = tubes_[i].permeability() * (h[id1] - h[id2]);
			}
			return q;

		}

		PipeNetwork::~PipeNetwork()
		{}
	}
}