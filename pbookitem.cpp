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


/* 
 * CreateFirst - создание корневого (первого) элемента списка.
 * ВХОД: 	аргументы не передаются
 * ВЫХОД:	указатель на созданный корневой элемент
 */

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


/*
 * Add - добавление нового элемента в конец списка.
 * ВХОД:	указатель на конечный элемент списка
 * 		Данные полей класса (передаются через поля)
 * ВЫХОД: 	Функция ничего не возвращает
 */

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


/*
 * Init - заполнение полей класса через аргументы функции
 * ВХОД:	
 * 		Name - ФИО
 * 		PhoneNumber - номер телефона
 * 		Email - Адресс электронной почты
 * 		EtcInfo - Примечания
 * ВЫХОД:	Функция ничего не возвращает
 */ 

void PBookItem::Init(char *Name, char *PhoneNumber, char *Email, char *EtcInfo)
{
	strcpy(this->Name,Name);
	strcpy(this->PhoneNumber,PhoneNumber);
	strcpy(this->Email,Email);
	strcpy(this->EtcInfo,EtcInfo);
	
}

/*
 * Find - Поиск элемента списка по идентификатору
 * ВХОД:
 * 		pbeg - указатель на корневой элемент списка
 * 		Descriptor - идентификатор элемента, который необходимо найти
 * ВЫХОД:	указатель на найденный элемент или NULL в случае неудачи
 *
 */

PBookItem * PBookItem::Find(PBookItem *pbeg,int Descriptor)
{
	PBookItem *pv=pbeg;
	while(pv)
	{
		if(pv->Descriptor==Descriptor) return pv;
		pv=pv->Next;
	}
	cout << "УКАЗАННЫЙ ИДЕНТИФИКАТОР НЕ НАЙДЕН!" << endl;
	return NULL;	

}


/*
 * Remove - удаление элемента из списка
 * ВХОД:	pbeg - указатель на корневой элемент списка
 * 		Descriptor - идентификатор элемента, который необходимо удалить
 * ВЫХОД:	указатель на корневой элемент списка
 */

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

/*
 * Insert - Вставка элемента в произвольное место списка
 * ВХОД: 	pBeg - указатель на корневой элемент списка
 * 		Descriptor - дескриптор нового элемента
 *		Значение полей вставляемого элемента (через поля)
 * ВЫХОД:	Указатель на вставленный элемент
 */

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

/*
 * Show() - Вывод всех элементов списка на экран
 * ВХОД: 	параметры не передаются
 * ВЫХОД:	Функция ничего не возвращает
 *
 */

void PBookItem::Show()
{
	cout << endl;
	cout << "=====================================" << endl;
	cout << "Descriptor: " << this->Descriptor << endl;	
	cout << "Name: " << this->Name << endl;
	cout << "Phone: " << this->PhoneNumber << endl;
	cout << "Email: " << this->Email << endl;
	cout << "Etc: " << this->EtcInfo << endl;
	//cout << "this->Prev=" << this->Prev << endl;
	//cout << "this=" << this << endl;
	//cout << "this->Next=" << this->Next << endl;
	cout << "====================================="	<< endl;
	
}

