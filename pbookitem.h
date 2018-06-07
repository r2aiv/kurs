/*

	PBOOKITEM.CPP
	Описание класса "Запись в телефонной книге".
	Описание и определение методов этого класса.
	Совков Д.С. ЗВБЗ-01-17

*/

#include <string.h>
#include <iostream>

using namespace std;

class PBookItem
{
	public:

	/***** ПОЛЯ *****/
	int Descriptor;				// Дескриптор (ключ) записи
	char Name[50];				// Ф.И.О.
	char PhoneNumber[20];			// Номер телефона
	char Email[50];				// Адрес email
	char EtcInfo[100];			// Примечание

	PBookItem *Prev;			// Ссылка на предыдущий
	PBookItem *Next;			// Ссылка на последующий
	
	/***** МЕТОДЫ *****/
	PBookItem *CreateFirst();	// Создание корня списка
	void Add(PBookItem **pend);		// Добавление записи
	PBookItem *Find(PBookItem *pbeg,int Descriptor);	// Поиск по дескриптору
	void Remove(int Descriptor);		// Удаление по ключу	
	PBookItem *Insert(int Descriptor);	// Вставка после указанной записи
	void Show();
	void Init(char *Name,char *PhoneNumber,char *Email,char *EtcInfo);
};


