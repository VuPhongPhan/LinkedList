#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *pNext;
};
struct SingleList
{
	Node *pHead;
};
void Initialize(SingleList &list)
{
	list.pHead = NULL;
}
Node * CreateNode(int d)
{
	Node *pNode = new Node;	
	if(pNode != NULL)
	{
		pNode->data=d;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"cap phat bo nho that bai!";
	}
	return pNode;
}
void PrintList(SingleList list)
{
	Node *pTmp = list.pHead;
	if(pTmp == NULL)
	{
		cout<<"Danh sach rong!";
		return;
	}
	while(pTmp != NULL)
	{
		cout<<pTmp->data<<"\t";
		pTmp = pTmp->pNext;
	}
}
int SizeOfList(SingleList list)
{
	Node *pTmp = list.pHead;
	int nSize = 0;
	while(pTmp != NULL)
	{
		pTmp = pTmp->pNext;
		nSize ++;
	}
	return nSize;
}
void InsertFirst(SingleList &list, int d)
{
	Node *pNode = CreateNode(d);
	if(list.pHead==NULL)
	{
		list.pHead = pNode;
	}
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}
void InsertLast(SingleList &list, int d)
{
	Node *pNode = CreateNode(d);
	if(list.pHead==NULL)
	{
		list.pHead=pNode;
	}
	else 
	{
		Node *pTmp=list.pHead;
		while(pTmp->pNext!=NULL)
		{
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pNode;
	}
}
void InsertMid(SingleList &list, int pos, int d)
{
	if(pos<0 || pos>=SizeOfList(list))
	{
		cout<<"vi tri chen khong hop le!";
		return;
	}
	if(pos==0)
		InsertFirst(list, d);
	else if(pos==SizeOfList(list)-1)
		InsertLast(list, d);
	else
	{
		Node *pNode=CreateNode(d);
		Node *pIns=list.pHead;
		Node *pPre=NULL;
		int i=0;
		while(pIns!=NULL)
		{
			if(i==pos)
				break;
			pPre=pIns;
			pIns=pIns->pNext;
			i++;
		}
		pPre->pNext=pNode;
		pNode->pNext=pIns;
	}
}
void RemoveNode(SingleList &list, int d)
{
	Node *pDel=list.pHead;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong";
	}
	else
	{
		Node *pPre=NULL;
		while(pDel!=NULL)
		{
			if(pDel->data==d)
				break;
			pPre=pDel;
			pDel=pDel->pNext;
		}
		if(pDel==NULL)
		{
			cout<<"khong tim thay"<<d<<"de xoa";
		}
		else
		{
			if(pDel==list.pHead)
			{
				list.pHead=list.pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
			else
			{
				pPre->pNext=pDel->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
		}
	}
}
Node * SearchNode(SingleList list,int d)
{
	Node *pTmp=list.pHead;
	while(pTmp!=NULL)
	{
		if(pTmp->data==d)
			break;
		pTmp=pTmp->pNext;;
	}
	return pTmp;
}
void SortList(SingleList &list)
{
	for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
			if(pTmp2->data<pTmp->data)
			{
				int tmp=pTmp->data;
				pTmp->data=pTmp2->data;
				pTmp2->data=tmp;
			}
		}
	}
}
void FreeMemory(SingleList &list)
{
	cout<<"\nBat dau xoa...\n";
	while(list.pHead!=NULL)
	{
		Node *pTmp=list.pHead;
		list.pHead=pTmp->pNext;
		pTmp->pNext=NULL;
		cout<<pTmp->data<<" da xoa\n";
		delete pTmp;
		pTmp=NULL; 
	}
	cout<"Da xoa!";
}
int main(int argc, char** argv)
{
	SingleList list;
	Initialize(list);
	InsertFirst(list, 10);
	InsertFirst(list, 5);
	InsertFirst(list, 7);
	InsertFirst(list, 3);
	InsertFirst(list, 9);
	InsertLast(list, 13);
	InsertLast(list, 15);
	InsertMid(list, 2, 16);

	PrintList(list);
	cout<<"\nXoa phan tu thu 2:\n";
	RemoveNode(list, 10);
		PrintList(list);
	int n = SizeOfList(list);
	cout<<"\nco "<<n<< " node!";
	
	int d;
	cout<<"\nNhap gia tri muon tim: ";
	cin>>d;
	Node *pSearch=SearchNode(list,d);
	if(pSearch!=NULL)
	{
		cout<<"Thay "<<pSearch->data;
	}
	else 
	{
		cout<<"Khong thay "<<d;
	}
	SortList(list);
	cout<<"\nList sau khi sap xep:\n";
	PrintList(list);
	FreeMemory(list);
	return 0;	
}
