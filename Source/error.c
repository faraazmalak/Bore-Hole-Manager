#include "main.h"
#include "error.h"

void throwError(error error)
{
	if(strcmp(error.display,"graphic")==0)
	{
		setcolor(COLOR(255,0,0));
		outtextxy(2,2,error.msg);
		
		
	
	}
	else
	{
		printf("\n%s\n",error.msg);
	
	}

}

