

#ifndef MAIN_HEADER
#define MAIN_HEADER 1
#include "main.h"
#endif
#include "error.h"
/*Beginning of throwReadError() routine 
This function is called when there is an error reading data from file*/
int throwReadError(char*msg)
{
		
			
	
				struct error error;
				error.display="console";
				error.msg=msg;
				throwError(error);
				
			int readAgain=0;
	
			
					printf("\nPossible reasons are:\n1. File does not exist.\n2. You have entered incorrect file name or file path"
						  "\n\nDo you want to attempt to read from the file once again?\n1=Yes\n2=No"
						  "\nEnter number of your choice:\n");
						  
			
						
				scanf("%d",&readAgain);
		
				//If a value of 2 is returned, program exits. Else if 1 is returned, read is again attemted
				return readAgain;
		
}
/*End of throwReadError() routine*/


/*Beginning of readData() routine
This function reads data from the user-specified file*/
int readData(struct hole holeData[MAX_HOLES],char label1[LABEL_LENGTH],char label2[LABEL_LENGTH])
{

	
				int iHole;
				int iSoil=0;
	
				FILE* dataFile;
	
	
	
	
				//Indicates number of assignments made by fscanf() for a hole
				int numHoleRead=0;
	
				//Indicates number of assignments made by fscanf() for every depth for a bore hole
				int numSoilRead=0;
	
				//As long as this variable is not equal to 2 , the below do...while loop is executed
				int readAgain=2;
	
				int result=0;

				do
				{
	
	
	
								readAgain=2;
								
								
	
							
	
								dataFile=fopen(DATA_FILE_NAME,"r");
	
	

	
								//If there is no problem opening data file, below code is executed
								if (dataFile!=NULL)
								{
												printf("\nData file found! Press enter to read data....\n");
												if(getchar())
												{
												
												
												
													printf("\nReading data from file. Please wait...\n");
												//This for loop reads the 2 labels at the top of the boreholes.txt file
												for(iHole=0;iHole<2;iHole++)
												{
			
																switch(iHole)
																{
															
																	case 0:
																	{
																			fgets(label1,LABEL_LENGTH,dataFile);
																			break;
																	}
											
					
																	case 1:
																	{
																			fgets(label2,LABEL_LENGTH,dataFile);
																			break;
																	}
																	
																	default:
																	{
																			printf("\nUnexpected error occoured\n");
																	
																	}
																}
			
			
												}
	
	
	
												//This for loop reads data for every bore hole
												for(iHole=0;iHole<MAX_HOLES;iHole++)
												{
							
																numHoleRead=fscanf(dataFile,"%s %lf %lf %d",&holeData[iHole].Name,&holeData[iHole].eastX,&holeData[iHole].northY,&holeData[iHole].numSamples);
						
																/*If number of assignments made for every bore hole==4 then below code is
																executed, else an error is thrown*/
								 								if (numHoleRead==4)
																{
					
																				//This for loop reads data at different depths
										 										for(iSoil=0;iSoil<holeData[iHole].numSamples;iSoil++)
																				{
																							numSoilRead=fscanf(dataFile,"\n%f %s %s %s\n",&holeData[iHole].soilData[iSoil].depth,&holeData[iHole].soilData[iSoil].type,&holeData[iHole].soilData[iSoil].color,&holeData[iHole].soilData[iSoil].strength);
																				}
								
																				/*If number of assignments made by fscanf() is less than 4,
																				error is throwReadError() is called*/
																				if(numSoilRead<4)
																				{
							
																							result=1;
											
																							readAgain=throwReadError("Error occoured while reading the file.");
											
																							break;
							
																				}	   	   	   
																}

			
																else
																{
																				/*If number of assignments made by fscanf() for a bore hole !=4,
																				throwReadError() is called*/
																				result=1;
											
																				readAgain=throwReadError("Error occoured while reading the file.");
						
																				break;
					
																}
				
						
																result=0;
		
												}




			
									}

								}
			

								//If there is a problem opening data file, throwReadError() is called
								else if(dataFile==NULL)
								{					
												result=1;
											
												readAgain=throwReadError("Could not find boreholes.txt");
								}
 
	
			
					}while(readAgain!=2);

	
					//After the do...while loop, if read is successful (result==0), user is shown below message
					if(result==0)
					{
									printf("\nData successfully read from file.\n");
					}
					return result;


}
//End of readData()

