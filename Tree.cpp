//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void TTree::MakeList(TTree **p, TInf Inf)
{
	*p = new TTree;
	(*p)->Inf = Inf;
	(*p)->A1 = NULL;
	(*p)->A2 = NULL;
}

void TTree::DeleteTree(TTree **p)
{
	if (*p == NULL)
	{
		return;
	}
	DeleteTree(&(*p)->A1);
	DeleteTree(&(*p)->A2);
	delete(*p);
	*p = NULL;
}

void TTree::DobTree(TTree *proot, TInf Inf)
{
	TTree *p = proot, *q;
	bool bl;
	while (p != NULL)
	{
		q = p;
		if(Inf.key == p->Inf.key)
		{
			ShowMessage("Так как некоторые ключи повторяются, часть была пропущена");
            return;
		}
		bl = (Inf.key < p->Inf.key);
		if (bl)
		{
			p = p->A1;
		}
		else
		{
			p = p->A2;
		}
	}
	MakeList(&proot, Inf);
	if (bl)
	{
		q->A1=proot;
	}
	else
	{
		q->A2=proot;
	}
}

