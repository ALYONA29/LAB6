//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "MyTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int n = 9;
int N = 10;
TTree *proot;
TTree *List;
MyTree* root;

void ViewTree(TTree *p, int kl)
{
	if (p == NULL)
	{
		return;
	}
	if (kl == -1)
	{
		Form2->TreeView1->Items->AddFirst(NULL,p->Inf.fio + " = " + IntToStr(p->Inf.key));
	}
	else
	{
		Form2->TreeView1->Items->AddChildFirst(Form2-> TreeView1->Items->
		Item[kl], p->Inf.fio + " = " + IntToStr(p->Inf.key));
	}
	kl++;
	ViewTree(p->A1,kl);
	ViewTree(p->A2,kl);
	kl--;
}

void WrtTree(TTree**p)
{
	if (*p == NULL)
	{
		return;
	}
	Form2->Memo1->Lines->Add((*p)->Inf.fio + " " + (*p)->Inf.key);
	WrtTree((&(*p)->A1));
	WrtTree((&(*p)->A2));
}
//
void WrtTreeBack(TTree**p)
{
	if (*p == NULL)
	{
		return;
	}
	WrtTreeBack((&(*p)->A1));
	WrtTreeBack((&(*p)->A2));
	Form2->Memo1->Lines->Add((*p)->Inf.fio + " " + (*p)->Inf.key);
}

void WrtTreeIncrease(TTree**p) {
	if (*p == NULL)
	{
		return;
	}
	WrtTreeIncrease((&(*p)->A1));
	Form2->Memo1->Lines->Add((*p)->Inf.fio + " " + (*p)->Inf.key);
	WrtTreeIncrease((&(*p)->A2));
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

bool Del(int key_del)
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
		return false;
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
    return true;
}

void MyFind(MyTree*p, int &coun)
{
	if (p == NULL)
	{
		return;
	}
	if((p)->Tr.Inf.fio[1] == 'a')
	{
		Form2->Memo1->Lines->Add((p)->Tr.Inf.fio + " " + (p)->Tr.Inf.key);
		coun++;
	}
	MyFind((p)->Left, coun);
	MyFind((p)->Right, coun);
}

int Size_Tree(TTree *p)
{
	return p? 1 + Size_Tree(p->A1) + Size_Tree(p->A2) : 0;
}

int Store_Tree(TTree *p, int pos, int *a, String *b)
{
	if (p)
	{
		if(p->A1 != NULL)
		{
			pos = Store_Tree(p->A1, pos, a, b);
		}
		a[pos] = p->Inf.key;
		b[pos] = p->Inf.fio;
		pos++;
		if(p->A2 != NULL)
		{
			pos =Store_Tree(p->A2, pos, a, b);
		}
	}
	return pos;
}

void Make_Blns(TTree **p, int L, int R, int *a, String *b)
{
	if (L == R)
	{
		*p = NULL;
		return;
	}
	else
	{
		int m = (L + R) / 2;
		*p = new TTree;
		(*p)->Inf.key = a[m];
		(*p)->Inf.fio = b[m];
		Make_Blns( &(*p)->A1, L, m, a, b);
		Make_Blns( &(*p)->A2, m + 1, R, a, b);
	}
}

bool CheckStr(String str)
{
	bool check = false;
	if (str == "")
	{
		ShowMessage("������� ������");
		return check;
	}
	int count = 0;
	int len = str.Length();
	for (int i = 1; i <= len; i++)
	{
		if(((str[i] >= 'A') && (str[i] <= 'Z')) || (str[i] >= 'a' && str[i] <= 'z'))
		{
			count++;
		}
	}
	if (count != len)
	{
		ShowMessage("�������� ���� ������");
		return check;
	}
	check = true;
	return check;
}

bool CheckNumber(String str)
{
	bool check = false;
	if (str == "")
	{
		ShowMessage("������� ������");
		return check;
	}
	int count = 0;
	int len = str.Length();
	for (int i = 1; i <= len; i++)
	{
		if((str[i] <= '9') && (str[i] >= '0'))
		{
			count++;
		}
	}
	if (count != len)
	{
		ShowMessage("�������� ���� ������");
		return check;
	}
	check = true;
	return check;
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	StringGrid1->FixedCols = 0;
	StringGrid1->ColCount = 2;
	StringGrid1->RowCount = 10;
	StringGrid1->Cells[0][0] = "�����";
	StringGrid1->Cells[1][0] = "����";
	StringGrid1->Cells[0][1] = "asd";
	StringGrid1->Cells[1][1] = "5";
	StringGrid1->Cells[0][2] = "fgh";
	StringGrid1->Cells[1][2] = "2";
	StringGrid1->Cells[0][3] = "try";
	StringGrid1->Cells[1][3] = "4";
	StringGrid1->Cells[0][4] = "asdf";
	StringGrid1->Cells[1][4] = "1";
	StringGrid1->Cells[0][5] = "re";
	StringGrid1->Cells[1][5] = "7";
	StringGrid1->Cells[0][6] = "cbv";
	StringGrid1->Cells[1][6] = "6";
	StringGrid1->Cells[0][7] = "aazc";
	StringGrid1->Cells[1][7] = "8";
	StringGrid1->Cells[0][8] = "dfh";
	StringGrid1->Cells[1][8] = "0";
	StringGrid1->Cells[0][9] = "fdh";
	StringGrid1->Cells[1][9] = "9";
	Edit1->Clear();
	Edit2->Clear();
    Edit3->Clear();
	Memo1->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	TInf A;
	A.fio = StringGrid1->Cells[0][1];
	if (!CheckStr(StringGrid1->Cells[0][1]) || !CheckNumber(StringGrid1->Cells[1][1]))
	{
		 return;
	}
	A.key = StrToInt(StringGrid1->Cells[1][1]);
	proot->MakeList(&proot, A);
	for(int i = 2; i <= N - 1; i++)
	{
		A.fio = StringGrid1->Cells[0][i];
		if (!CheckStr(StringGrid1->Cells[0][i]) || !CheckNumber(StringGrid1->Cells[1][i]))
		{
			return;
		}
		A.key = StrToInt(StringGrid1->Cells[1][i]);
		proot->DobTree(proot, A);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	int kl = -1;
	TreeView1->Items->Clear();
	ViewTree(proot, kl);
	TreeView1->FullExpand();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	proot->DeleteTree(&proot);
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
    if(Edit1->Text == "")
	{
		ShowMessage("������� ������");
		return;
	}
	n = StrToInt(Edit1->Text);
	N = n + 1;
	StringGrid1->RowCount = n + 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
	if(Edit2->Text == "")
	{
		ShowMessage("������� ������");
		return;
	}
	int num = StrToInt(Edit2->Text);
	bool check = Del(num);
	if(check)
	{
		StringGrid1->RowCount = N - 1;
		N--;
		for(int i = 1; i <= N; i++)
		{
			if(StrToInt(StringGrid1->Cells[1][i]) == num)
			{
				for(int j = i; j + 1 <= N; j++)
				{
					StringGrid1->Cells[1][j] = StringGrid1->Cells[1][j + 1];
					StringGrid1->Cells[0][j] = StringGrid1->Cells[0][j + 1];
				}
			}
		}
	}
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
	if(Edit3->Text == "")
	{
		ShowMessage("������� ������");
		return;
	}
	int num = StrToInt(Edit3->Text);
	Find(num);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button10Click(TObject *Sender)
{
	int i = 0, n = Size_Tree(proot);
	int *mas = new int[n];
	String *mas2 = new String[n];
	Store_Tree(proot, i, mas, mas2);
	Make_Blns(&proot, 0, n, mas, mas2);
	delete[] mas;
    delete[] mas2;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)
{
	TTree A;
	A.Inf.fio = StringGrid1->Cells[0][1];
	A.Inf.key = StrToInt(StringGrid1->Cells[1][1]);
	root->MakeMyList(&root,A);
	for(int i = 2; i <= n; i++)
	{
		A.Inf.fio = StringGrid1->Cells[0][i];
		A.Inf.key = StrToInt(StringGrid1->Cells[1][i]);

		root->DobMyTree(root, A);
	}
	int count = 0;
	Memo1->Clear();
	MyFind(root, count);
	Memo1->Lines->Add("����� ���������� : ");
	Memo1->Lines->Add(IntToStr(count));
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
	if((Key < '0' || Key > '9')&& Key != VK_BACK && Key != VK_DELETE && Key != 13)
	{
		ShowMessage("������������ ������! �������� ���� ����� �����.");
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
    if((Key < '0' || Key > '9')&& Key != VK_BACK && Key != VK_DELETE && Key != 13)
	{
		ShowMessage("������������ ������! �������� ���� ����� �����.");
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
    if((Key < '0' || Key > '9')&& Key != VK_BACK && Key != VK_DELETE && Key != 13)
	{
		ShowMessage("������������ ������! �������� ���� ����� �����.");
		Key = NULL;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button12Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

