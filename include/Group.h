#ifndef GROUP_H
#define GROUP_H

#include<Permutation.h>

namespace AlgLib
{
	class GroupElement
	{
	public:
		GroupElement();
		virtual ~GroupElement();
		virtual GroupElement inverse();
		virtual GroupElement compose(GroupElement other); // not overloading operator since groups can be both additive and multiplicative
	};

}
#endif
