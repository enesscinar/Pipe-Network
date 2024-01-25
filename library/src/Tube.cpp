#define _USE_MATH_DEFINES
#include "Tube.hpp"
#include "Node.hpp"
#include <cmath>

namespace cie
{
	namespace pipenetwork
	{

		Tube::Tube(Node* node1, Node* node2, double diameter) :
			node1_(node1), node2_(node2), d_(diameter) 
		{}

		Tube::~Tube()
		{}

		const Node* Tube::node1() const
		{
			return node1_;
		}

		const Node* Tube::node2() const
		{
			return node2_;
		}

		double Tube::length() const
		{
			double length = std::sqrt(std::pow(((*node2_).x() - node1_->x()), 2) + std::pow((node2_->y() - node1_->y()), 2));
			return length;
		}
		
		double Tube::permeability() const
		{
			double g = 9.81;
			double nu = 1e-6;
			double B = M_PI * g * std::pow(d_, 4) / (128 * nu * length());
			return B;
		}
	}

}
