#include <iostream>
#include <cstdio>
#include "pbookitem.h"
#include "user.h"
#include "files.h"

PBookItem * Temp=new PBookItem;
PBookItem * ListHead=new PBookItem;
PBookItem * ListTail=new PBookItem;

int TempDesc=0;
char TempName[50];
char TempNumber[20];
char TempEmail[50];
char TempEtcInfo[100];

int FlagBookCreated=0;

void MainMenu()
{
	int MenuChoice=0;

	cout << "*****************************" << endl;
	cout << "*     ТЕЛЕФОННАЯ КНИГА      *" << endl;
	cout << "*****************************" << endl;

	cout << "1) Создать телефонную книгу" << endl;
	cout << "2) Добавить запись в конец" << endl;
	cout << "3) Вставить запись в середину книги" << endl;
	cout << "4) Поиск записи по идентификатору" << endl;
	cout << "5) Удаление записи" << endl;
	cout << "6) Просмотр всех записей" << endl;
	cout << "7) Чтение книги из файлы" << endl;
	cout << "8) Запись книги в файл" << endl;

	cout << "0) Выход" << endl;

	cout << "Выбор: ";
	cin >> MenuChoice;

	switch(MenuChoice)
	{
		case 1:
			if(FlagBookCreated!=0)
			{
				cout << "====< ОШИБКА! Книга уже создана! >=====" << endl;
				getchar();
				return;
			}
			cout << "Создание первой записи." << endl;
			AskForFieldsData();
			Temp->Descriptor=1;
			ListHead=Temp->CreateFirst();
			ListTail=ListHead;
			FlagBookCreated=1;
			break;

		case 2:
			if(FlagBookCreated==0)
			{
				cout << "====< ОШИБКА! Книга не существует! >====" << endl;
				getchar();
				return;
			}

			AddItemToEnd();

			break;
		case 3:
			if(FlagBookCreated==0)
			{
				cout << "====< ОШИБКА! Книга не создана! >====" << endl;
				getchar();
				return;
			}

			cout << "Введите идентификатор вставляемой записи: ";
			cin >> Temp->Descriptor;
			cout << "Введите дескриптор ПОСЛЕ которого вставляем запись: ";
			cin >> TempDesc;
			AskForFieldsData();
			Temp->Insert(ListHead,TempDesc);

			break;
		case 4:
			if(FlagBookCreated==0)
			{
				cout << "====< ОШИБКА! Книга не существует! >====" << endl;
				getchar();
				return;			
			}

			cout << "Введите идентификатор: ";
			cin >> TempDesc;

			Temp=ListHead;
			while(Temp!=0)
			{
				if(Temp->Descriptor==TempDesc) 
				{
					Temp->Show();
					return;
				}
				Temp=Temp->Next;
			}


			break;
		case 5:
			cout << "Введите индентификатор для удаления: ";
			cin >> TempDesc;
			Temp->Remove(ListHead,TempDesc);


			break;
		case 6:
			ShowAllItems();
			break;

		case 7:
			ReadBookFromFile();
			break;
			
		case 8:
			SaveBookToFile();
			break;

		case 0:
			exit(0);
			break;
		default:
			MainMenu();
			break;
	}	
}

void AskForFieldsData()
{
	cout << "Имя: "; cin >> TempName;
	cout << "Номер телефона: "; cin >> TempNumber;
	cout << "E-mail: "; cin >> TempEmail;
	cout << "Примечание: "; cin >> TempEtcInfo;

	strcpy(Temp->Name,TempName);
	strcpy(Temp->PhoneNumber,TempNumber);
	strcpy(Temp->Email,TempEmail);
	strcpy(Temp->EtcInfo,TempEtcInfo);
}

void ShowAllItems()
{
	Temp=ListHead;
	while(Temp!=0)
	{
		Temp->Show();
		Temp=Temp->Next;
		cout << endl << endl;
	}

}

void AddItemToEnd()
{
	AskForFieldsData();	
	Temp->Descriptor=(ListTail->Descriptor)+1;
	Temp->Add(&ListTail);	
}
