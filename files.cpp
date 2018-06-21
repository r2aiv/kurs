#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "pbookitem.h"

extern PBookItem * Temp;
extern PBookItem * ListHead;
extern PBookItem * ListTail;
extern int FlagBookCreated;

FILE *WorkFile;

void ReadBookFromFile()
{
	WorkFile=fopen("pbook.dat","r");
	if(WorkFile==NULL)
	{
		cout << "Не могу открыть файл!!!" << endl;
		return;
	}

	// Если книга не создана - создаем
	if(FlagBookCreated==0)
	{
		fread((void *)Temp,sizeof(PBookItem),1,WorkFile);		
		ListHead=Temp->CreateFirst();
		ListTail=ListHead;
		FlagBookCreated=1;
	}

		while(!feof(WorkFile))		
		{
			fread((void *)Temp,sizeof(PBookItem),1,WorkFile);			
			if(!feof(WorkFile))
				{
				Temp->Descriptor=(ListTail->Descriptor)+1;
				Temp->Add(&ListTail);
				}
		};

	fclose(WorkFile);
}

void SaveBookToFile()
{
	WorkFile=fopen("pbook.dat","w");

	Temp=ListHead;
	while(Temp!=0)
	{
		fwrite((void *)Temp,sizeof(PBookItem),1,WorkFile);
		Temp=Temp->Next;
	}	
	fclose(WorkFile);


}

