#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pbookitem.h"
#include "user.h"

using namespace std;


int main()
{
	extern PBookItem *ListHead;
	extern PBookItem *ListTail;
	extern PBookItem *Temp;

	ListHead=NULL;
	ListTail=NULL;
	//Temp=NULL;

	while(1) MainMenu();
		
	
	return 0;
}
