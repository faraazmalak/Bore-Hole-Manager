#ifndef MAIN_HEADER
#define MAIN_HEADER 1
#include "main.h"
#endif
#include "error.h"
//#include "soil_palette.h"
//Function Implementation
//Functions to initialize soilPalette attributes

//Beginning of initSoilType proceedure. This initializes name(strings) and corresponding colors for different soilPalette types
void initSoilType(soil_palette* soilPalette)
{

  
										 	 	 	 	 	 
					  
				  	  	  	  	  
				setcolor(BLACK);	  	  //Create dark Gray
				soilPalette->type[0].value=getcolor();
				soilPalette->type[0].name="Silt";
				
				setcolor(BLUE);			//Create blue
				soilPalette->type[1].value=getcolor();
				soilPalette->type[1].name="Water";
	
				setcolor(RED);			//Create Red
				soilPalette->type[2].value=getcolor();
				soilPalette->type[2].name="Clay";	    


				setcolor(COLOR(202,139,59));	//Create Orangish Yellow
				soilPalette->type[3].value=getcolor();
				soilPalette->type[3].name="Sand";	    
	
	
				setcolor(COLOR(121,102,58));	//Create Greyish Brown
				soilPalette->type[4].value=getcolor();
				soilPalette->type[4].name="SandStone";	   
				
	
				setcolor(COLOR(160,160,160));	   	   	   //Create Gray
				soilPalette->type[5].value=getcolor();
				soilPalette->type[5].name="MudStone";	 
	
				setcolor(COLOR(16,19,6));	   	   	   //Create black
				soilPalette->type[6].value=getcolor();
				soilPalette->type[6].name="SiltStone";	
	
				setcolor(LIGHTGRAY);		//Create light gray
				soilPalette->type[7].value=getcolor();
				soilPalette->type[7].name="Shale";	
	
				setcolor(WHITE);		//Create White
				soilPalette->type[8].value=getcolor();
				soilPalette->type[8].name="Concrete";	
				
				/*printf("Str %s\n ",soilPalette.type[0].name);
				printf("Str %i \n ",soilPalette.type[6].value);
					printf("Str %s\n ",soilPalette.type[2].name);
					printf("Str %s\n ",soilPalette.type[3].name);
					printf("Str %s\n ",soilPalette.type[4].name);*/

}
//End of initSoilType proceedure


//Beginning of initSoilStr proceedure. This initializes name(strings) and corresponding colors for different soilPalette strengths
void initSoilStr(soil_palette*soilPalette)
{

	
   
	
				setcolor(BLACK);		//Create Black
				int black=getcolor();
	
				setcolor(DARKGRAY);		//Create Dark Gray
				int darkGray=getcolor();

				setcolor(COLOR(160,160,160));  /* Create grey */
				int gray=getcolor();
	
				setcolor(LIGHTGRAY);		//Create Light Gray
				int lightGray=getcolor();
	
	
				setcolor(WHITE);
				int white=getcolor();	 //Create White
	

	
				//Puts the integer color values into an array
				soilPalette->strength[0].value=black;
				soilPalette->strength[1].value=darkGray;
				soilPalette->strength[2].value=gray;
				soilPalette->strength[3].value=lightGray;
				soilPalette->strength[4].value=darkGray;
				soilPalette->strength[5].value=lightGray;
				soilPalette->strength[6].value=white;
				soilPalette->strength[7].value=black;
				soilPalette->strength[8].value=darkGray;
				soilPalette->strength[9].value=gray;
	
	
	
				/*Puts the  strings representing soilPalette strengths into hardName Array. 
				Each value in this array represents 
				soilPalette strength and corresponds to a value in hardColor Array*/
				soilPalette->strength[0].name="Hard";
	
				soilPalette->strength[1].name="Stiff";
	
				soilPalette->strength[2].name="Firm";
	
				soilPalette->strength[3].name="Soft";
	
				soilPalette->strength[4].name="Dense";
	
				soilPalette->strength[5].name="Medium";
	
				soilPalette->strength[6].name="Loose";
	
				soilPalette->strength[7].name="Strong";
	
				soilPalette->strength[8].name="Moderately-strong";
	
				soilPalette->strength[9].name="Weak";
	
	
}
//End of initSoilStr routine.


//Beginning of initSoilClr routine. This initializes name(strings) and corresponding integer color values for different soilPalette colors 
void initSoilClr(soil_palette* soilPalette)
{





				setcolor(COLOR(160,160,160)); /* Create grey */
    			soilPalette->color[0].value = getcolor( );
				soilPalette->color[0].name="grey";
	
	
				setcolor(DARKGRAY); /* Create dark grey */
				soilPalette->color[1].value = getcolor( );
				soilPalette->color[1].name="dark-grey";
	
	
				setcolor(COLOR(220,220,220)); /* Create whitish grey */
   				soilPalette->color[2].value = getcolor( );
				soilPalette->color[2].name="whitish-grey";
	
	
    			setcolor(COLOR(220,205,80)); /* Create yellowish grey */
    			soilPalette->color[3].value = getcolor( );
				soilPalette->color[3].name="yellowish-grey";
	



				setcolor(BROWN); /* Create brown */
   				soilPalette->color[4].value = getcolor( );
				soilPalette->color[4].name="brown";
	
	
				setcolor(COLOR(200,140,60)); /* Create light brown */
    			soilPalette->color[5].value = getcolor( );
				soilPalette->color[5].name="light-brown";
	
	
	
				setcolor(COLOR(195,160,100)); /* Create brownish grey */
   			 	soilPalette->color[6].value = getcolor( );
				soilPalette->color[6].name="brownish-grey";
	
	
				setcolor(COLOR(225,180,20)); /* Create brownish yellow */
    			soilPalette->color[7].value = getcolor( );
				soilPalette->color[7].name="brownish-yellow";
	

	
				setcolor(BLUE); /* Create Blue */
    			soilPalette->color[8].value = getcolor( );
				soilPalette->color[8].name="blue";
	

}
//End of initSoilClr routine

