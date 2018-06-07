/*

	PBOOKITEM.CPP
	Описание класса "Запись в телефонной книге".
	Описание и определение методов этого класса.
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
		if(pv->Descriptor==Descriptor) break;
		pv=pv->Next;
	}
	return pv;	

}

void PBookItem::Remove(int Descriptor)
{

}

PBookItem * PBookItem::Insert(int Descriptor)
{

}

void PBookItem::Show()
{
	cout << "Descriptor: " << this->Descriptor << endl;	
	cout << "Name: " << this->Name << endl;
	cout << "Phone: " << this->PhoneNumber << endl;
	cout << "Email: " << this->Email << endl;
	cout << "Etc: " << this->EtcInfo << endl;
	cout << "this->Prev=" << this->Prev << endl;
	cout << "this=" << this << endl;
	cout << "this->Next=" << this->Next << endl;	
}

