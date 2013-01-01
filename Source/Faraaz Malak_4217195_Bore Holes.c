/*Student Name: Faraaz Malak
ID: 4217195*/

//This a a program to read and display bore hole data

//Please refer to the report included for a synopsys of what each function does




#include<cctype>
#include<cstdio>
#include<cmath>



#ifndef MAIN_HEADER
#define MAIN_HEADER 1
#include "main.h"
#endif

#include "graphic_window.h"
#include "console.h"
#include "io.h"


#include "error.h"





//	  struct soilPalette soilPalette;	 
	
	
	
/*VARIABLES     USED   IN   THE  CODE
		holeData[] - Array containing  all the bore hole data
		holeData[..].soilData[..] - Array containing  all the soilPalette info. for a particular bore hole
		
		holeIndex - index / subscript of a hole in holeData[] array. This is passed on to different routines for them to take action on that particular hole
		soilIndex - index / subscript of soilData[] array. This is passed on to different routines for them to take actions on that particular hole at that depth 
		
		
		
		colorName[] - Array containing string representation of soilPalette colors
		colorValue[] - Array containing integer values for soilPalette colors
		
		typeName[]- Array containing string representation of soilPalette Types
		typeColor - Array containing integer values (representing colors) for corresponding soilPalette types
		
		hardName[] - Array containing string representation of soilPalette strengths
		hardColor[]- Array containing integer values (representing colors) for corresponding soilPalette strengths

*/




//End of ProtoTypes


















//End of routines that define Soil Attributes







 
	











//Beginning of main(void)
int main(void)
{

	
	//Initializes variables
			  struct hole holeData[MAX_HOLES];
	
				struct graphicWindow gfxWin;
				
				struct soil_palette soilPalette;
	
				char label1[LABEL_LENGTH];
	
				char label2[LABEL_LENGTH];
	
				float inputDepth=0;
	
				//Holds input indicating if user wants to run or quit the program	 
				int mainChoice=0;
	
				//This hold the value (as returned by scanf()) indicating number of assignments made
				int validDepth=0;
	
			
	
	
	

				int readResult=0; 
	
				//result from readData function is stored in readResult var.
				readResult=readData(holeData,label1,label2);
	
				
				switch(readResult)
				{
	
					case 0:
					{
		
								
									//If readResult=0, below code is executed
										   
									calcDimen(holeData,&gfxWin);
	
									initGraphics(&gfxWin,&soilPalette);
									
									calcHoleCoord(holeData,&gfxWin);
	
									
									
								
	
									showAllData(holeData,label1,label2,&gfxWin);	
								   
				 
									/*This do..while loop calls the routines inside it 
									as long as user does not decide to quit the program*/
								  do{
		
		
		
													mainChoice=displayMainMenu();
		
		
													if(mainChoice==1)
													{
				
																do
																{
																			printf("\nEnter a depth (in meters):");
							
																			fflush(stdin);
							
																			validDepth=scanf("%f",&inputDepth);
							
						
																}while(validDepth==0);
						
							
																inputDepth=fabs(inputDepth);
					
															
																processInput(holeData,soilPalette,inputDepth,label1,label2,&gfxWin,displaySoilMenu(),1);
					
						
													}
		
		
			
	
	
	
										}while(mainChoice!=2);
	
	
				
										break;
					}


	
					case 1:
					{
			
										printf("You have chosen to exit the program because data from the file could not be read.\n Press Enter to exit.");
		
										break;
			
					}
					
					default:
					{
							printf("\nUnexpected error occoured in main(void)\n");
							break;
					}
		
	
	
				}
			return readResult;

	
			

	
	
}



