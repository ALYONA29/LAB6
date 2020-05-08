//---------------------------------------------------------------------------

#pragma hdrstop

#include "MyTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void MyTree::MakeMyList(MyTree **p, TTree Tr)
{
	*p = new MyTree;
	(*p)->Tr = Tr;
	(*p)->Left = NULL;
	(*p)->Right = NULL;
}

void MyTree::DobMyTree(MyTree *proot, TTree Tr)
{
	MyTree *p = proot, *q;
	bool bl;
	while (p != NULL)
	{
		q = p;
		bl = (Tr.Inf.key < p->Tr.Inf.key);
		if (bl)
		{
			p = p->Left;
		}
		else
		{
			p = p->Right;
		}
	}
	MakeMyList(&proot, Tr);
	if (bl)
	{
		q->Left=proot;
	}
	else
	{
		q->Right=proot;
    }
}
