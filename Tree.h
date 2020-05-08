//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------
#endif

#include "Info.h"

class TTree
{
	public:
	TInf Inf;
	TTree *A1;
	TTree *A2;
    void MakeList(TTree**, TInf);
	void DobTree(TTree*, TInf);
	void DeleteTree(TTree**);
};
