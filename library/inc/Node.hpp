#pragma once

namespace cie
{
	namespace pipenetwork
	{

		class Node
		{
		public:

			Node(double x, double y, double flow, int id);

			~Node();

			double x() const;

			double y() const;

			double flow() const;

			int id() const;

		private:

			double x_, y_, flow_, id_;	

		};

	}
}

