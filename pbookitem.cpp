/*

	PBOOKITEM.CPP
	Определение класса "Запись в телефонной книге".
	Определение методов этого класса.
	Совков Д.С. ЗВБЗ-01-17

*/

#include <string.h>
#include <iostream>
#include "pbookitem.h"


using namespace std;


// Создает корень списка и возвращает указатель на него
PBookItem * PBookItem::CreateFirst()
{
	PBookItem *pv=new PBookItem;
	pv->Descriptor=1;
	strcpy(pv->Name,this->Name);
	strcpy(pv->PhoneNumber,this->PhoneNumber);
	strcpy(pv->Email,this->Email);
	strcpy(pv->EtcInfo,this->EtcInfo);

	Prev=NULL;
	Next=NULL;
	
	return pv; 	
}


// Добавляет новый элемент в список
void PBookItem::Add(PBookItem **pend)
{
	PBookItem *pv=new PBookItem;
	pv->Next=NULL;
	pv->Prev=*pend;

	pv->Descriptor=this->Descriptor;
	strcpy(pv->Name,this->Name);
	strcpy(pv->PhoneNumber,this->PhoneNumber);
	strcpy(pv->Email,this->Email);
	strcpy(pv->EtcInfo,this->EtcInfo);

	(*pend)->Next=pv;
	*pend=pv;
}

void PBookItem::Init(char *Name, char *PhoneNumber, char *Email, char *EtcInfo)
{
	strcpy(this->Name,Name);
	strcpy(this->PhoneNumber,PhoneNumber);
	strcpy(this->Email,Email);
	strcpy(this->EtcInfo,EtcInfo);
	
}

PBookItem * PBookItem::Find(PBookItem *pbeg,int Descriptor)
{
	PBookItem *pv=pbeg;
	while(pv)
	{
		if(pv->Descriptor==Descriptor) return pv;
		pv=pv->Next;
	}
	cout << "УКАЗАННЫЙ ИДЕНТИФИКАТОР НЕ НАЙДЕН!" << endl;
	return pv;	

}



PBookItem * PBookItem::Remove(PBookItem *pBeg, int Descriptor)
{
	PBookItem *Prev;
	PBookItem *ToRemove;
	PBookItem *Next;

	ToRemove=this->Find(pBeg,Descriptor);
	if(ToRemove==NULL) return NULL;

	Prev=ToRemove->Prev;
	Next=ToRemove->Next;
	Prev->Next=Next;
	Next->Prev=Prev;
	delete ToRemove;
	return pBeg;
}

PBookItem * PBookItem::Insert(PBookItem *pBeg,int Descriptor)
{
	PBookItem *Prev;
	PBookItem *ToInsert=new PBookItem;
	PBookItem *Next;

	// Filling item to insert by fields of this temp item
	ToInsert->Descriptor=this->Descriptor;
	strcpy(ToInsert->Name,this->Name);
	strcpy(ToInsert->PhoneNumber,this->PhoneNumber);
	strcpy(ToInsert->Email,this->Email);
	strcpy(ToInsert->EtcInfo,this->EtcInfo);

	// Serching for item to insert after	
	Prev=this->Find(pBeg,Descriptor);

	if(Prev==NULL) return NULL;

	ToInsert->Next=Prev->Next;
	ToInsert->Prev=Prev;
	Prev->Next=ToInsert;
	(Prev->Next)->Prev=ToInsert;
	Prev->Next=ToInsert;

	return ToInsert;
}

void PBookItem::Show()
{
	cout << endl;
	cout << "=====================================" << endl;
	cout << "Descriptor: " << this->Descriptor << endl;	
	cout << "Name: " << this->Name << endl;
	cout << "Phone: " << this->PhoneNumber << endl;
	cout << "Email: " << this->Email << endl;
	cout << "Etc: " << this->EtcInfo << endl;
	cout << "this->Prev=" << this->Prev << endl;
	cout << "this=" << this << endl;
	cout << "this->Next=" << this->Next << endl;
	cout << "====================================="	<< endl;
	cout << endl;
}

