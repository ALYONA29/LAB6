//---------------------------------------------------------------------------

#ifndef MyTreeH
#define MyTreeH
//---------------------------------------------------------------------------
#endif

#include "Tree.h"

class MyTree : public TTree
{
	public:
	TTree Tr;
	MyTree *Left;
	MyTree *Right;
	void MakeMyList(MyTree **p, TTree Tr);
	void DobMyTree(MyTree *proot, TTree Tr);
};
