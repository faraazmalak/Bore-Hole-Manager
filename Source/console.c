#ifndef MAIN_HEADER
#define MAIN_HEADER 1
#include "main.h"
#endif


#include"console.h"
#include "graphic_window.h"

//Function Implementation
/*Beginning of processInput() routine
This function processes the user input. It decides the depth (from every bore hole), that is closest to the user input. 
Then it displays the data at that
depth to the user*/
void processInput(struct hole holeData[MAX_HOLES],soil_palette soilPalette,float inputDepth,char label1[50], char label2[50],struct graphicWindow*dimenPtr,char* choice,int legend)
{


				/*This proceedure takes the user input, loops through holeData[] array and calculates the minimum 
				difference between the user input and  soilPalette depths  (as contained in holeData[..].soilData[..] array) for every bore hole
				This minimum difference is stored in min variable and the index of  depth at which the difference was minimum is stored
				in soilIndex variable.And  Soil Info at this depth is then displayed to the user*/
	
				int holeIndex;
				int soilCounter;
				int min=0;
				int soilIndex=0;
				double diff=0;


	
				//Erase graphics already drawn on the window
				eraseGraphics();
	

	
				//Uses a for loop to display all the bore hole information
				for(holeIndex=0;holeIndex<MAX_HOLES;holeIndex++)
				{
		
								printf("\n-------------------------------------------------------\n");
								printf("\n%s %s\n",label1,label2);
								printf("%s %lf %lf %d\n",holeData[holeIndex].Name,holeData[holeIndex].eastX,holeData[holeIndex].northY, holeData[holeIndex].numSamples);
	
								//Uses this nested for loop to calculate the depth from which soilPalette information should be displayed
								for(soilCounter=0;soilCounter<holeData[holeIndex].numSamples;soilCounter++)
								{
												//Calculates the difference between user input and the actual depth
												diff=abs((holeData[holeIndex].soilData[soilCounter].depth)-(inputDepth));
			
												//If user input is not equal to the actual depth, then below code is executed
												if (holeData[holeIndex].soilData[soilCounter].depth !=inputDepth)
												{
																if(soilCounter==0  )
																{
																				//If this is the first time the loop is executing, assigns the difference to this var.
																				min=diff;
			
																}
																else if((min)>(diff))
																{
																				//If min var is greater than diff var, then min=diff
																				min=diff;
																				soilIndex=soilCounter;
				
			
																}
					
			
				
												}
			
												//If user input is equal to actual depth, then below code is executed
												else if(holeData[holeIndex].soilData[soilCounter].depth ==inputDepth)
												{
																soilIndex=soilCounter;
												}
		
		
			
								}
		
		
		
								//After calculations made above, below code prints the results on the Console
								printf("\n%s",label2);
								printf("%.2f ",holeData[holeIndex].soilData[soilIndex].depth);
								
							
						
						
							
							for(int i=0;i<strlen(choice);i++)
							{
								if(choice[i]=='1')
								{
									printf("%s\n",holeData[holeIndex].soilData[soilIndex].type);
								
								}
								else if(choice[i]=='2')
								{
									printf("%s\n",holeData[holeIndex].soilData[soilIndex].color);
								}
								else if(choice[i]=='3')
								{
									printf("%s\n",holeData[holeIndex].soilData[soilIndex].strength);
								}
							
							}
								/*switch (choice)
								{
												case 1:
												{
																printf("%s\n",holeData[holeIndex].soilData[soilIndex].type);
																break;
												}
				
												case 2:
												{
																printf("%s\n",holeData[holeIndex].soilData[soilIndex].color);	
																break;
												
												}
												case 3:
												{
				
																printf("%s\n",holeData[holeIndex].soilData[soilIndex].strength);
																break;
												}
												case 12:
												{	 
																printf("%s %s\n",holeData[holeIndex].soilData[soilIndex].type,holeData[holeIndex].soilData[soilIndex].color);
																break;
												}
									
												case 13:
												{
																printf("%s %s\n",holeData[holeIndex].soilData[soilIndex].type,holeData[holeIndex].soilData[soilIndex].strength);
																break;
												}
								
												case 23:
												{
				
																printf("%s %s\n",holeData[holeIndex].soilData[soilIndex].color,holeData[holeIndex].soilData[soilIndex].strength);
																break;
												}
								
												case 123:
												{
																printf("%s %s %s\n",holeData[holeIndex].soilData[soilIndex].type,holeData[holeIndex].soilData[soilIndex].color,holeData[holeIndex].soilData[soilIndex].strength);
																break;
												}
								
												default:
												{
												printf("\nInvalid Entry\n");
												break;
												}
			
								}*/
			
		
								/*After printing the results on the console, drawGraphics routine is called, which
								draws results on the Graphics Window*/
								drawGraphics(holeData,soilPalette,holeIndex,soilIndex,choice,dimenPtr,legend);
		
								legend=0;
				}
	
				printf("\nTotal Number of Bore holes: %d\nMinimum X: %.3lf; Maximum X: %.3lf; Range X: %.3lf\nMinimum Y: %.3lf; Maximum Y: %.3lf\n RangeY: %.3lf\n",MAX_HOLES,dimenPtr->minX,dimenPtr->maxX,dimenPtr->rangeX,dimenPtr->minY,dimenPtr->maxY,dimenPtr->rangeY);
		

}
//End of processInput() routine


/*Beginning of displaySoilMenu() routine

This function asks the user what soilPalette Data he wants to be displayed*/
char* displaySoilMenu()
{

				/*This function returns the integer value entered by the user. 
				Do...while loop is used to make sure user does not enter a value other than 
				the expected values. This function returns the user entered number to the main(void) routine.*/

				static char choice[3]={NULL,NULL,NULL};
				do
				{
								fflush(stdin);
								printf("\nSelect the data you wish to display:\n");
								printf("1= Soil Type\n2= Soil Color\n3= Soil Strength\n");
								printf("12= Soil Type & Soil Color\n13= Soil Type & Soil Strength\n23= Soil Color & Soil Strength\n123= Soil Type, Soil Color & Soil Strength\n");
	
								scanf("%s",choice);
							//	  printf("\nPrinting choice value: %i: ",check_choice(choice[0]));

				}while(check_choice(choice[0])==false || check_choice(choice[1])==false || check_choice(choice[2])==false );
	
				
				printf("\nYour input is %s",choice);
				return choice;

}
/*End of displaySoilMenu() routine*/

bool check_choice(char choice)
{
	if(choice=='1' || choice=='2' || choice=='3' || choice==NULL)
	{

		return true;
	
	}
	else
	{

		return false;
	
	}


}


/*Beginning of displayMainMenu() routine
This function displays the user-options on the console*/

int displayMainMenu()

{

				/*This function returns the integer number entered by the user. 
				Do...while loop is used to make sure that the user does not enter value 
				other than 1(select a depth) or 2(quit). This function returns the user entered number 
				to the main(void) routine.*/
	
				int choice=0;

	
	
				do
				{
	
								fflush(stdin);
	
								printf("\nDisplay Choices:\n");
								printf("1. Select a depth:\n");
								printf("2.Quit\n");
								printf("Enter number of your choice:");
	
								scanf("%d",&choice);
	
	
				}while( (choice!=1 && choice!=2));
	
				/*char*choiceStr;
				*choiceStr='a';
				printf("\nChar Test: %c",choiceStr);*/
				
				return choice;

}
//End of displayMenu() routine










/*Beginning of showAllData() routine
This function prints all data read from text file (and stored in holeData[MacHoles] array)*/
void showAllData(struct hole holeData[MAX_HOLES],char label1[LABEL_LENGTH], char label2[LABEL_LENGTH],struct graphicWindow*dimenPtr)
{


				int soilIndex=0;
		
				int soilCounter;
				int holeCounter;
		
	
				//This for loop prints all the bore hole information on the console
				for(holeCounter=0;holeCounter<MAX_HOLES;holeCounter++)
				{
	
							printf("\n-------------------------------------------------------\n");
							printf("\n%s %s\n",label1,label2);
				  
			
							printf("%s %lf %lf %d\n",holeData[holeCounter].Name,holeData[holeCounter].eastX,holeData[holeCounter].northY, holeData[holeCounter].numSamples);
	
							//This nested for loop prints all the soilPalette information for every depth of a perticular hole
							for(soilCounter=0;soilCounter<holeData[holeCounter].numSamples;soilCounter++)
							{
											printf("%.2f %s %s %s\n",holeData[holeCounter].soilData[soilCounter].depth,holeData[holeCounter].soilData[soilCounter].type,holeData[holeCounter].soilData[soilCounter].color,holeData[holeCounter].soilData[soilCounter].strength);
				
							}
		
		
			
				}
				printf("\n-------------------------------------------------------\n");
		
				//This prints total bore holes, minimum and maximum X and Y coords and x and y ranges (all in meters)
				printf("\nTotal Number of Bore holes: %d\nMinimum X: %.3lf; Maximum X: %.3lf; Range X: %.3lf\nMinimum Y: %.3lf; Maximum Y: %.3lf\n RangeY: %.3lf\n",MAX_HOLES,dimenPtr->minX,dimenPtr->maxX,dimenPtr->rangeX,dimenPtr->minY,dimenPtr->maxY,dimenPtr->rangeY);
		
}
//End of showAllData() routine

