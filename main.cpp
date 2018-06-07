#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pbookitem.h"

using namespace std;


int main()
{
	PBookItem *ListHead=new PBookItem;
	PBookItem *ListTail=new PBookItem;
	PBookItem *Tmp=new PBookItem;
		
	sprintf(Tmp->Name,"Марселло");
	sprintf(Tmp->PhoneNumber,"666-66-66");
	sprintf(Tmp->Email,"kot@gornostay.ru");
	sprintf(Tmp->EtcInfo,"Castration");c

	ListHead=Tmp->CreateFirst();
	ListTail=ListHead;

	Tmp->Init((char *)"Котэлло",(char *)"8(999)000-00-00",(char *)"email",(char *)"");
	Tmp->Descriptor=2;
	Tmp->Add(&ListTail);

	Tmp->Init((char *)"Кастрелло",(char *)"666-77-88",(char *)"localhost@localhost",(char *)"desc");
	Tmp->Descriptor=666;
	Tmp->Add(&ListTail);

	Tmp=ListHead;
	while(Tmp!=NULL)
	{
		Tmp->Show();
		Tmp=Tmp->Next;
		cout << "===========================" << endl;
	}

	Tmp=Tmp->Find(ListHead,2);
	
	if (Tmp != NULL) // А вдруг ничего не найдется и вернётся NULL
	{
		cout << "FOUND: " << endl;
		Tmp->Show();
	}
	esle
	{
		cout << "NOT FOUND :(" << endl;
	}
	
	
	return 0;
}
