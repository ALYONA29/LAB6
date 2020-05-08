//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
class TInf
{
public:
int key;
String fio;
};
class TTree
{
 public:
 TInf Inf;
 TTree *A1;
 TTree *A2;
};

class MyTree : public TTree
{
    public:
	TTree Tr;
	MyTree *Left;
	MyTree *Right;
};

void FindWord(MyTree **p, String ch)
{
		if (*p == NULL)return;
		if((*p)->Inf.fio[0] == )
		{
			Form2->Memo1->Lines->Add((*p)->Inf.fio+" "+(*p)->Inf.key);
		}
		FindWord((&(*p)->Left), ch);
		FindWord((&(*p)->Right), ch);
}

int n = 9;  TTree *proot; TTree *List;
int size = 0;
MyTree* root;

void MakeList(TTree**, TInf);
void DobTree(TTree*, TInf);
void ViewTree(TTree*, int);
void DeleteTree(TTree**);
void WrtTree(TTree**);

void MakeList(TTree **p, TInf Inf)
{
*p = new TTree;
(*p)->Inf = Inf;
(*p)->A1=NULL;
(*p)->A2=NULL;
}

void DobTree(TTree *proot, TInf Inf)
{
TTree *p = proot, *q;
bool bl;
while (p != NULL) {
q = p;
bl = ( Inf.key < p->Inf.key);
if (bl) p = p->A1;
else p = p->A2;
}
MakeList(&p, Inf);
if (bl) q->A1=p; else q->A2=p;
}

void MakeMyList(MyTree **p, TTree Tr)
{
*p = new MyTree;
(*p)->Tr.Inf = Tr.Inf;
(*p)->Left=NULL;
(*p)->Right=NULL;
}

void DobMyTree(MyTree *proot, TTree Tr)
{
MyTree *p = proot, *q;
bool bl;
while (p != NULL) {
q = p;
bl = (Tr.Inf.key < p->Inf.key);
if (bl) p = p->Left;
else p = p->Right;
}
MakeMyList(&p, Tr);
if (bl) q->A1=p; else q->A2=p;
}

void ViewTree(TTree *p, int kl)
{
if (p == NULL) return;
if (kl == -1)
Form2->TreeView1->Items->AddFirst(NULL,p->Inf.fio+" = "+IntToStr(p->Inf.key));
else
Form2->TreeView1->Items->AddChildFirst(Form2-> TreeView1->Items->
Item[kl], p->Inf.fio+" = "+IntToStr(p->Inf.key));
kl++;
ViewTree(p->A1,kl);
ViewTree(p->A2,kl);
kl--;
}

void DeleteTree(TTree **p)
{
if (*p == NULL)return;
DeleteTree(&(*p)->A1);
DeleteTree(&(*p)->A2);
delete(*p);
*p=NULL;
}

void WrtTree(TTree**p) {
if (*p == NULL)return;
Form2->Memo1->Lines->Add((*p)->Inf.fio+" "+(*p)->Inf.key);
WrtTree((&(*p)->A1));
WrtTree((&(*p)->A2));
}
//
void WrtTreeBack(TTree**p) {
	if (*p == NULL)return; //Пока не встретится пустой узел
	WrtTreeBack((&(*p)->A1)); //Рекурсивная функция для левого поддерева
	WrtTreeBack((&(*p)->A2)); //Рекурсивная функция для правого поддерева
	Form2->Memo1->Lines->Add((*p)->Inf.fio+" "+(*p)->Inf.key); //Отображаем корень дерева
}

void WrtTreeIncrease(TTree**p) {
	if (*p == NULL) return;//Пока не встретится пустой узел
	WrtTreeIncrease((&(*p)->A1)); //Рекурсивная функция для левого поддерева
	Form2->Memo1->Lines->Add((*p)->Inf.fio+" "+(*p)->Inf.key); //Отображаем корень дерева
	WrtTreeIncrease((&(*p)->A2)); //Рекурсивная функция для левого поддерева
}

void Del(int key_del)
{
	TTree *Del, *Prev_Del, *R, *Prev_R;
	Del = proot;
	Prev_Del = NULL;
	while(Del != NULL && Del->Inf.key != key_del)
	{
		Prev_Del = Del;
		if(Del->Inf.key > key_del)
		{
			Del = Del->A1;
		}
		else
		{
			Del = Del->A2;
        }
	}
	if(Del == NULL)
	{
		Form2->Memo1->Clear();
		Form2->Memo1->Lines->Add("No key");
        return;
	}
	if(Del->A2 == NULL)
	{
		R = Del->A1;
	}
	else if(Del->A1 == NULL)
	{
		R = Del->A2;
	}
	else
	{
		Prev_R = Del;
		R = Del->A1;
		while(R->A2 != NULL)
		{
			Prev_R = R;
			R = R->A2;
		}
		if(Prev_R == Del)
		{
			R->A2 = Del->A2;
		}
		else
		{
			R->A2 = Del->A2;
			Prev_R->A2 = R->A1;
			R->A1 = Prev_R;
        }
	}
	if(Prev_Del == NULL)
	{
		proot = Prev_Del = R;
	}
	else if(Del->Inf.key < Prev_Del->Inf.key)
	{
		Prev_Del->A1 = R;
	}
	else
	{
		Prev_Del->A2 = R;
	}
	Form2->Memo1->Clear();
	String num = IntToStr(Del->Inf.key);
	Form2->Memo1->Lines->Add("Delete " + num + " element");
	size--;
	delete Del;
}

void Copy(TTree* treeOriginal, MyTree** treeNew){

if (treeOriginal == NULL) //base case to end recursion when at tree end
treeNew = NULL;
else{
MyTree* treeNew = new MyTree;  //create the node and set the new key to original
treeNew->Inf.key = treeOriginal->Inf.key;
treeNew->Inf.fio = treeOriginal->Inf.fio;

// Just call recursively to copy the subtrees:
Copy(treeOriginal->A1, &treeNew->Left);
Copy(treeOriginal->A2, &treeNew->Right);
}
}

void Find(int key_del)
{
	TTree *Del, *Prev_Del, *R, *Prev_R;
	Del = proot;
	Prev_Del = NULL;
	while(Del != NULL && Del->Inf.key != key_del)
	{
		Prev_Del = Del;
		if(Del->Inf.key > key_del)
		{
			Del = Del->A1;
		}
		else
		{
			Del = Del->A2;
        }
	}
	if(Del == NULL)
	{
		Form2->Memo1->Clear();
		Form2->Memo1->Lines->Add("No key");
        return;
	}
	Form2->Memo1->Clear();
	String num = IntToStr(Del->Inf.key);
	Form2->Memo1->Lines->Add("Find " + num + " element");
	Form2->Memo1->Lines->Add("Information " + Del->Inf.fio);
}

void Strip (TTree* node, TTree* &List, int &size)
{  if ( node != NULL )
   {//Retain pointer to left subtree.
	  TTree* Left;
	  Left = node->A1;
	//In the degenerate tree, all left pointers are NULL
	  node->A1  = NULL;
	//Reversed; hence right, middle, then left.
	  Strip (node->A2, List, size);
	//Stack discipline in building the list
	  node->A2 = List;
	  List = node;
	  size++;           // Count the number of nodes
	  Strip(Left, List, size );
   }
}

void compression (TTree* root, int count)
{  TTree* scanner = root;

   for ( int j = 0; j < count; j++ )
   {//Leftward rotation
	  TTree* child = scanner->A2;
	  scanner->A2 = child->A2;
	  scanner = scanner->A2;
	  child->A2 = scanner->A1;
	  scanner->A1 = child;
   }  // end for
}  // end compression

void vine_to_tree (TTree* root, int size)
{  int NBack = size - 1;
   for ( int M = NBack / 2; M > 0; M = NBack / 2)
   {  compression ( root, M );
      NBack = NBack - M - 1;
   }
}

int FullSize (int size)    // Full portion of a complete tree
{  int Rtn = 1;
   while ( Rtn <= size )     // Drive one step PAST FULL
      Rtn = Rtn + Rtn + 1;   // next pow(2,k)-1
   return Rtn/2;
}

/*void vine_to_tree ( TTree* root, int size )
{  int full_count = FullSize (size);
   compression(root, size - full_count);
   for ( size = full_count ; size > 1 ; size /= 2 )
      compression ( root, size / 2 );
}


void tree_to_vine (TTree* root, int &size)
{
   TTree *vineTail, *remainder, *tempPtr;
   vineTail = root;
   remainder = vineTail->A2;
   size = 0;
   while (remainder != NULL)
   {//If no leftward subtree, move rightward
	  if (remainder->A1 == NULL )
      {  vineTail = remainder;
		 remainder = remainder->A2;
         size++;
      }
    //else eliminate the leftward subtree by rotations
      else  // Rightward rotation
	  {  tempPtr = remainder->A1;
		 remainder->A2 = tempPtr->A1;
		 tempPtr->A2 = remainder;
         remainder = tempPtr;
         vineTail->A2 = tempPtr;
      }
   }
   vine_to_tree (root, size);
}*/

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	StringGrid1->FixedCols=0;  StringGrid1->ColCount=2;
	StringGrid1->RowCount=10;
	StringGrid1->Cells[0][0] = "Ф.B.О.";
	StringGrid1->Cells[1][0]="Ключ";
	StringGrid1->Cells[0][1]="asd"; StringGrid1->Cells[1][1]="5";
	StringGrid1->Cells[0][2]="fgh"; StringGrid1->Cells[1][2]="2";
	StringGrid1->Cells[0][3]="try"; StringGrid1->Cells[1][3]="4";
	StringGrid1->Cells[0][4]="asdf"; StringGrid1->Cells[1][4]="1";
	StringGrid1->Cells[0][5]="re"; StringGrid1->Cells[1][5]="7";
	StringGrid1->Cells[0][6]="cbv"; StringGrid1->Cells[1][6]="6";
	StringGrid1->Cells[0][7]="aazc"; StringGrid1->Cells[1][7]="8";
	StringGrid1->Cells[0][8]="dfh"; StringGrid1->Cells[1][8]="0";
	StringGrid1->Cells[0][9]="fdh"; StringGrid1->Cells[1][9]="9";
    Edit1->Clear();
    Memo1->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	TInf A;
A.fio = StringGrid1->Cells[0][1];
A.key = StrToInt(StringGrid1->Cells[1][1]);
MakeList(&proot,A);
for(int i=2; i<=n; i++){
A.fio = StringGrid1->Cells[0][i];
A.key = StrToInt(StringGrid1->Cells[1][i]);
DobTree(proot,A);
}
size++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
     int kl=-1;
TreeView1->Items->Clear();
ViewTree(proot,kl);
TreeView1->FullExpand();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	DeleteTree(&proot);
Memo1->Clear();
TreeView1->Items->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
Memo1->Clear();
WrtTree(&proot);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	n = StrToInt(Edit1->Text);
    StringGrid1->RowCount = n+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
	int num = StrToInt(Edit2->Text);
	Del(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
	Memo1->Clear();
	WrtTreeBack(&proot);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
	Memo1->Clear();
	WrtTreeIncrease(&proot);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{
	int num = StrToInt(Edit3->Text);
	Find(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
	//Memo1->Clear();

	//Strip (proot, List, size);
	//vine_to_tree (proot, size);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)
{
	//Copy(proot, &root);
		TTree B;
		B.Inf.fio = StringGrid1->Cells[0][1];
		B.Inf.key = StrToInt(StringGrid1->Cells[1][1]);
		MakeMyList(&root,B);
		for(int i=2; i<=n; i++){
		B.Inf.fio = StringGrid1->Cells[0][i];
		B.Inf.fio = StrToInt(StringGrid1->Cells[1][i]);
		DobMyTree(root,B);
		}
		FindWord(&root, Edit3->Text);
}
//---------------------------------------------------------------------------

