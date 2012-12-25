

//This a a program to read and display bore hole data

//Please refer to the report included for a synopsys of what each function does

#include <stdio.h>
#include"winbgim.h"
#include<string.h>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cmath>


#define MAX_HOLES 11/*Maximum number of bore holes*/
#define MAX_DEPTHS 21/*Maximum number of depths*/
#define METER_BORDER 100
#define PIXEL_BORDER METER_BORDER*0.35


	int colorValue[9];
	char* colorName[9];
	
	int hardColor[10];
	char*hardName[10];
	
		
	int typeColor[9];
	char*typeName[9];	 
	
//Fuction ProtoTypes
void initSoilType();
void initSoilStr();
void initSoilClr( );
void labelHole(struct holeStruct holeData[MAX_HOLES],int holeIndex,int radius);
void drawLegend(struct dimenssionStruct*dimenPtr);
void eraseGraphics();
void drawSoilType(struct holeStruct holeData[MAX_HOLES],int holeIndex,int soilIndex);
void drawSoilStr(struct holeStruct holeData[MAX_HOLES],int holeIndex,int soilIndex);
void drawSoilClr(struct holeStruct holeData[MAX_HOLES],int holeIndex,int soilIndex);
void drawGraphics(struct holeStruct holeData[MAX_HOLES],int holeIndex, int soilIndex,int choice,struct dimenssionStruct*dimenPtr,int legend);
void initGraphics(struct dimenssionStruct*dimenPtr);
void calcHoleCoord(struct holeStruct holeData[MAX_HOLES],struct dimenssionStruct*dimenPtr);
void calcDimen(struct holeStruct holeData[MAX_HOLES],struct dimenssionStruct*dimenPtr);
void processPrint(struct holeStruct holeData[MAX_HOLES],float inputDepth,char label1[50], char label2[50],struct dimenssionStruct*dimenPtr,int choice,int legend);
int throwReadError();
int readData(struct holeStruct holeData[MAX_HOLES],char label1[50],char label2[50]);
int displayMainMenu();
int displaySoilMenu();
void showAllData(struct holeStruct holeData[MAX_HOLES],char label1[50], char label2[50],struct dimenssionStruct*dimenPtr);
//End of ProtoTypes
	
	
	/*VARIABLES     USED   IN   THE  CODE
		holeData[] - Array containing  all the bore hole data
		holeData[..].soilData[..] - Array containing  all the soil info. for a particular bore hole
		
		holeIndex - index / subscript of a hole in holeData[] array. This is passed on to different routines for them to take action on that particular hole
		soilIndex - index / subscript of soilData[] array. This is passed on to different routines for them to take actions on that particular hole at that depth 
		
		
		
		colorName[] - Array containing string representation of soil colors
		colorValue[] - Array containing integer values for soil colors
		
		typeName[]- Array containing string representation of soil Types
		typeColor - Array containing integer values (representing colors) for corresponding soil types
		
		hardName[] - Array containing string representation of soil strengths
		hardColor[]- Array containing integer values (representing colors) for corresponding soil strengths

		*/


//Defines the struct for soil sample found at a perticular depth
struct soilStruct
{
				//Will contain type of soil
				char type[20];
	
				//Will contain color of the soil
				char color[20];

				//Will contain strength of the soil
				char strength[20];
	
				//Will contain the depth, at which the sample was found
				float depth;	

};
//End of soilStruct definition




//Defines struct for a bore hole
struct holeStruct
{


				//Will contain Name of the hole
				char Name[50];
	
				//Will contain X coordinate (in meters ) of the hole
				double eastX;
	
	
				//Will contain Y coordinate (in meters ) of the hole
				double northY;
	
				//Will contain X coordinate (in pixels ) of the hole
				double pixelX;
	
				//Will contain Y coordinate (in pixels) of the hole
				double pixelY;
	
	
				//Will contain the number of total soil samples obtained for a bore hole
				int numSamples;

				//Will contain soil attributes for a particular soil sample
				struct soilStruct soilData[21];


};
//End of holeStruct




//Defines struct to contain the dimenssions of the Graphics Window
struct dimenssionStruct
{

	
//This section of struct members will contain all the values in meters

				//Will contain X range in meters
				double rangeX;
	
				//Will contain Y Range in meters
				double rangeY;
	
				//Will contain the minimum value for the X Coordinate in meters
				double minX;
	
				//Will contain the maximum value for the X Coordinate in meters
				double maxX;
	
				//Will contain the minimum value for the Y Coordinate in meters
				double minY;
	
				//Will contain the maximum value for the Y Coordinate in meters
				double maxY;
	
//End of first section
	
	
	
	
//This section of struct members will contain all the values in pixels (after scaling from meters to pixels)


				//Will contain minimum value of X
				double minXScale;
	
				//Will contain maximum value of X
				double maxXScale;
	
				//Will contain minimum value of Y
				double minYScale;
	
				//Will contain maximum value of Y
				double maxYScale;

				//Will contain X Range (maximum value of X coordinate minus minimum value of X coordinate)
				double rangeXScale;
	
				//Will contain Y Range (maximum value of Y coordinate minus minimum value of Y coordinate)
				double rangeYScale;
};
//End of dimenssionStruct












//Functions to initialize soil attributes

//Beginning of initSoilType proceedure. This initializes name(strings) and corresponding colors for different soil types
void initSoilType()
{

				setcolor(BLACK);	  	  //Create dark Gray
				int darkGray=getcolor();
	
				setcolor(BLUE);			//Create blue
				int blue=getcolor();
	
				setcolor(RED);
				int red=getcolor();		//Create Red


				setcolor(COLOR(202,139,59));	//Create Orangish Yellow
				int orangeYellow=getcolor();
	
	
				setcolor(COLOR(121,102,58));	//Create Greyish Brown
				int grayBrown=getcolor();
	
				setcolor(COLOR(160,160,160));	   	   	   //Create Gray
				int gray=getcolor();
	
				setcolor(COLOR(16,19,6));	   	   	   //Create black
				int black=getcolor();
	
				setcolor(LIGHTGRAY);		//Create light gray
				int lightGray=getcolor();
	
				setcolor(WHITE);		//Create White
				int white=getcolor();
	
	
				//Puts the integer color values into an array
				typeColor[0]=darkGray;
				typeColor[1]=blue;
				typeColor[2]=red;
				typeColor[3]=orangeYellow;
				typeColor[4]=grayBrown;
				typeColor[5]=gray;
				typeColor[6]=black;
				typeColor[7]=lightGray;
				typeColor[8]=white;
	
				/*Puts the  strings representing soil types into typeName Array. 
				Each value in this array represents 
				soil type and corresponds to a value in typeColor Array*/
	
				typeName[0]="Silt";
				typeName[1]="Water";
				typeName[2]="Clay";
				typeName[3]="Sand";
				typeName[4]="SandStone";
				typeName[5]="MudStone";
				typeName[6]="SiltStone";
				typeName[7]="Shale";
				typeName[8]="Concrete";
	

}
//End of initSoilType proceedure




//Beginning of initSoilStr proceedure. This initializes name(strings) and corresponding colors for different soil strengths
void initSoilStr()
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
				hardColor[0]=black;
				hardColor[1]=darkGray;
				hardColor[2]=gray;
				hardColor[3]=lightGray;
				hardColor[4]=darkGray;
				hardColor[5]=lightGray;
				hardColor[6]=white;
				hardColor[7]=black;
				hardColor[8]=darkGray;
				hardColor[9]=gray;
	
	
	
				/*Puts the  strings representing soil strengths into hardName Array. 
				Each value in this array represents 
				soil strength and corresponds to a value in hardColor Array*/
				hardName[0]="Hard";
	
				hardName[1]="Stiff";
	
				hardName[2]="Firm";
	
				hardName[3]="Soft";
	
				hardName[4]="Dense";
	
				hardName[5]="Medium";
	
				hardName[6]="Loose";
	
				hardName[7]="Strong";
	
				hardName[8]="Moderately-strong";
	
				hardName[9]="Weak";
	
	
}
//End of initSoilStr routine.


//Beginning of initSoilClr routine. This initializes name(strings) and corresponding integer color values for different soil colors 
void initSoilClr( )
{





				setcolor(COLOR(160,160,160)); /* Create grey */
    			int grey = getcolor( );
	
	
				setcolor(DARKGRAY); /* Create dark grey */
   				int darkGrey = getcolor( );
	
	
				setcolor(COLOR(220,220,220)); /* Create whitish grey */
   				int whiteGrey = getcolor( );
	
	
    			setcolor(COLOR(220,205,80)); /* Create yellowish grey */
    			int yellowGrey = getcolor( );
	



				setcolor(BROWN); /* Create brown */
   				int brown = getcolor( );
	
	
				setcolor(COLOR(200,140,60)); /* Create light brown */
    			int lightBrown = getcolor( );
	
	
	
				setcolor(COLOR(195,160,100)); /* Create brownish grey */
   			 	int brownGrey = getcolor( );
	
	
				setcolor(COLOR(225,180,20)); /* Create brownish yellow */
    			int brownYellow = getcolor( );
	

	
				setcolor(BLUE); /* Create Blue */
    			int blue = getcolor( );
	

	

				//Puts the integer color values into an array
				colorValue[0]=grey;
				colorValue[1]=darkGrey;
				colorValue[2]=whiteGrey;
				colorValue[3]=yellowGrey;
				colorValue[4]=brown;
				colorValue[5]=lightBrown;
				colorValue[6]=brownGrey;
				colorValue[7]=brownYellow;
				colorValue[8]=blue;
	
				/*Puts the  strings representing soil colors into colorName Array. 
				Each value in this array represents 
				soil color and corresponds to a value in colorValue Array*/
				colorName[0]="grey";
				colorName[1]="dark-grey";
				colorName[2]="whitish-grey";
				colorName[3]="yellowish-grey";
				colorName[4]="brown";
				colorName[5]="light-brown";
				colorName[6]="brownish-grey";
				colorName[7]="brownish-yellow";
				colorName[8]="blue";

}
//End of initSoilClr routine



//End of routines that define Soil Attributes




//Beginning of labelHole proceedure. This draws a number on the window representining a  bore hole
void labelHole(struct holeStruct holeData[MAX_HOLES],int holeIndex,int radius)
{
		
				//Holds the hole number
				char holeNum[3];
	
				//Converts the int representing hole num. into string
				sprintf(holeNum,"%d",holeIndex+1);



				//Sets the drawing color to white
				setcolor(WHITE);
	
				//Draws the hole number on the graphics window, based on the radius parameter, X nad Y coords
				outtextxy((int)holeData[holeIndex].pixelX+radius,(int)holeData[holeIndex].pixelY-8,holeNum);


}
//End of labelHole routine




//This function drwas the legend and the corresponding lables on the graphics window
void drawLegend(struct dimenssionStruct*dimenPtr)
{

				//This array defines coords for the legend keys (rectangular boxes)
				int coords[]={0,0,0,0,0,0,0,0};
		
				//Counter var
				int i;
	
				//Sets x coord for the  legend, which is x range of bore hole display area (including the borders) + another 35px
				int  x=(int)dimenPtr->rangeXScale+35;
				
				//This variable contains total distance from the top of the window
				int height=0;
	
			//-----------------
				//Draws legend for Soil Type
				setcolor(WHITE);
				outtextxy(x,2,"SOIL TYPE");
		
		
		
				//Initializes variable to the height of this text
				height=textheight("SOIL TYPE");
	
		
				//Sets drawing color to white and shows the text on graphics window
				setcolor(WHITE);
				outtextxy(x,2,"SOIL TYPE");
		
		
				for(i=0;i<9;i++)
				{
		
	
			
							//Top top left coord
					
								coords[0]=x;
					
					
								//Adds a padding of 10 px on the top
								coords[1]=height+10;
					
							//End of top left coord
				
				
				
				
							//Top right coord
					
								//Makes the legend key 20px wide
								coords[2]=x+20;
					
								//Adds padding of 10px from the top
								coords[3]=height+10;
					
							//End of top right coord
					
					
							//Bottom Right Coord
				
								//Makes the legend key 20px wide
								coords[4]=x+20;
					
					
								//Adds 25px to the height variable (Equation= total height from top of the window + 5 px top padding + 20px height)
								coords[5]=height+25;
				
					
							//End of Bottom Right Coord
				
				
							//Botton Left coord
				
								coords[6]=x;
					
								//Adds 25px to the height variable (Equation= total height from top of the window + 5 px top padding + 20 px height)
								coords[7]=height+25;
					
							//End of Botton Left coord
				
				
								height+=20;
					
								//Draws the Legend Key
								setcolor(typeColor[i]);
								setfillstyle(SOLID_FILL,typeColor[i]);
								fillpoly(4,coords);
					
					
					
								//Draws the label for this legend key
								setcolor(WHITE);
								outtextxy(coords[2]+4,coords[1],typeName[i]);
				
				
				
		

	


				}
		//---------------------

		
		
		//------------------------
		//Draws legend for sample color
	
		
		
				//Sets drawing color to white and shows the text on graphics window
				setcolor(WHITE);
				outtextxy(x,height+12,"SAMPLE COLORS");
		
				//Sets the top padding to 10px
				height+=textheight("SAMPLE COLORS")+10;
		
				for(i=0;i<9;i++)
				{
		
	
			
					
							//Top top left coord
								coords[0]=x;
					
					
								//Adds a padding of 10 px on the top
								coords[1]=height+10;
					
							//End of top left coord
				
				
				
				
							//Top right coord
					
								//Makes the legend key 20px wide
								coords[2]=x+20;
					
								//Adds padding of 10px from the top
								coords[3]=height+10;
					
							//End of top right coord
					
					
							//Bottom Right Coord
				
								//Makes the legend key 20px wide
								coords[4]=x+20;
					
					
								//Adds 25px to the height variable (Equation= total height from top of the screen + 5 px top padding + 20px height)
								coords[5]=height+25;

					
							//End of Bottom Right Coord
				
				
								//Botton Left coord
				
								coords[6]=x;
					
								//Adds 25px to the height variable (Equation= total height from top of the screen + 5 px top padding + 20 px height)
								coords[7]=height+25;
					
							//End of Botton Left coord
				
								height+=20;
					
								//Draws the Legend Key
								setcolor(colorValue[i]);
								setfillstyle(SOLID_FILL,colorValue[i]);
								fillpoly(4,coords);
					
					
					
								//Draws the label for this legend key
								setcolor(WHITE);
								outtextxy(coords[2]+4,coords[1],colorName[i]);
				
	

				}
		//------------------
		
		//----------------------------
		//Draws legend for sample strength
		
		
				//Sets drawing color to white and shows the text on graphics window
				setcolor(WHITE);
				outtextxy(x,height+12,"SAMPLE STRENGTH");
	
				//Sets the top padding to 10px
				height+=textheight("SAMPLE STRENGTH")+10;
		
				for(i=0;i<10;i++)
				{
		
	
			
							//Top top left coord
					
								coords[0]=x;
					
					
								//Adds a padding of 10 px on the top
								coords[1]=height+10;
					
							//End of top left coord
				
				
				
				
							//Top right coord
					
								//Makes the legend key 20px wide
								coords[2]=x+20;
					
								//Adds padding of 10px from the top
								coords[3]=height+10;
					
							//End of top right coord
					
					
							//Bottom Right Coord
				
								//Makes the legend key 20px wide
								coords[4]=x+20;
					
					
								/*Adds 25px to the height variable 
								(Equation= total height from top of the screen + 5 px top padding + 20px height)*/
								coords[5]=height+25;
					
							//End of Bottom Right Coord
				
				
							//Botton Left coord
				
								coords[6]=x;
					
								//Adds 25px to the height variable (Equation= total height from top of the screen + 5 px top padding + 20 px height)
								coords[7]=height+25;
					
							//End of Botton Left coord
				
				
					
				
								height+=20;
					
								//Draws the Legend Key
								setcolor(hardColor[i]);
								setfillstyle(SOLID_FILL,hardColor[i]);
								fillpoly(4,coords);
					
					
					
								//Draws the label for this legend key
								setcolor(WHITE);
								outtextxy(coords[2]+4,coords[1],hardName[i]);;
	


				}
		

}


//End of drawLegend routine



//This routine erases the graphics already drawn
void eraseGraphics()
{								


				//Erases the graphics already drawn
				cleardevice();

				//Sets fill & drawing colors
				setcolor(GREEN);
				setfillstyle(SOLID_FILL,GREEN);
	
	
				//Fills the graphics window with a green
				floodfill(0,0,GREEN);
								

}
//End of eraseGraphics routine




//This set of routines draw circles on graphics window, representing soil Attributes




//Draws circles representing soil types
void drawSoilType(struct holeStruct holeData[MAX_HOLES],int holeIndex,int soilIndex)
{
				int i;
	
	
		
				//Loops through typeName (strings representing soil Types)
				for(i=0;i<9;i++)
		
				{
							
							
								//Checks if typeName (strings representing soil Types) = holeData[hole].soilData[soil].type
								if(strcmp(typeName[i],holeData[holeIndex].soilData[soilIndex].type)==0)
								{
						
												//Sets drawing & fill colors (to the integer value contained at typeColor[i])
												setcolor(typeColor[i]);
												setfillstyle(SOLID_FILL,typeColor[i]);
									
												//Draws a circle and fills it up with color contained at typeColor[i]
												circle(holeData[holeIndex].pixelX,holeData[holeIndex].pixelY,15);
							 					floodfill((int)holeData[holeIndex].pixelX,(int)holeData[holeIndex].pixelY,typeColor[i]);
								
								
								}
							
							
							
				}
}


//End of drawSoilType routine





//Draws circles representing soil strengths
void drawSoilStr(struct holeStruct holeData[MAX_HOLES],int holeIndex,int soilIndex)
{
				int i;
		
				//Loops through hardName Array (strings representing soil Strengths)
				for(i=0;i<10;i++)
				{
		
		
								//Checks if hardName (strings representing soil Strengths) = holeData[holeIndex].soilData[soilIndex].strength
								if(strcmp(hardName[i],holeData[holeIndex].soilData[soilIndex].strength)==0)
								{
								
						
												//Sets drawing & fill colors (to the integer value contained at hardColor[i])
												setcolor(hardColor[i]);
												setfillstyle(SOLID_FILL,hardColor[i]);
									
									
												//Draws a circle and fills it up with color contained at hardColor[i]
												circle(holeData[holeIndex].pixelX,holeData[holeIndex].pixelY,5);
							 					floodfill((int)holeData[holeIndex].pixelX,(int)holeData[holeIndex].pixelY,hardColor[i]);;	
								
								}
							
							
							
				}
}
//End of soil drawSoilStr routine




//Draws circles representing soil colors
void drawSoilClr(struct holeStruct holeData[MAX_HOLES],int holeIndex,int soilIndex)
{
				int i;
	
	
				//Loops through hardName Array (strings representing soil Strengths)
				for(i=0;i<9;i++)
				{
				
								//Checks if colorName (strings representing soil colors) = holeData[hole].soilData[soil].color
								if(strcmp(colorName[i],holeData[holeIndex].soilData[soilIndex].color)==0)
								{
								
												//Sets drawing & fill colors (to the integer value contained at ColorValue[i])
												setcolor(colorValue[i]);
												setfillstyle(SOLID_FILL,colorValue[i]);
									
									
												//Draws a circle and fills it up with color contained at ColorValue[i]
												circle(holeData[holeIndex].pixelX,holeData[holeIndex].pixelY,10);
							 					floodfill((int)holeData[holeIndex].pixelX,(int)holeData[holeIndex].pixelY,colorValue[i]);
								}
							
							
							
				}
}
//End of drawSoilClr routine




//End of Functions that draw soil attributes on the graphics window





//This function controls drawing of bore holes and the Legend
void drawGraphics(struct holeStruct holeData[MAX_HOLES],int holeIndex, int soilIndex,int choice,struct dimenssionStruct*dimenPtr,int legend)
{
						
		
				int i;
			
				//If the legend parameter=1, then drawLegend proceedure is called
				if(legend==1)
				{
								drawLegend(dimenPtr);
	
				}



				//Dpending on the value of choice parameter, appropriate proccedure to draw bore hole circles is called,
				switch (choice)
				{
								case 1:
								{
				
						
												drawSoilType(holeData,holeIndex,soilIndex);
								
												labelHole(holeData,holeIndex,15);
						
												break;
									
								}
				
								case 2:
								{
				
												drawSoilClr(holeData,holeIndex,soilIndex);
								
												labelHole(holeData,holeIndex,10);
					
												break;
								}
								
								case 3:
								{
												drawSoilStr(holeData,holeIndex,soilIndex);
											
												labelHole(holeData,holeIndex,5);
												
												break;
								}
								case 12:
				
								{
						
												drawSoilType(holeData,holeIndex,soilIndex);
							
												drawSoilClr(holeData,holeIndex,soilIndex);
				
												labelHole(holeData,holeIndex,15);
						
									
												break;
								}
								case 13:
								{
												drawSoilType(holeData,holeIndex,soilIndex);
									
												drawSoilStr(holeData,holeIndex,soilIndex);
									
												labelHole(holeData,holeIndex,15);

												break;
								
								}
								
								case 23:
								{
												drawSoilClr(holeData,holeIndex,soilIndex);
							
												drawSoilStr(holeData,holeIndex,soilIndex);
														
												labelHole(holeData,holeIndex,10);
							
												break;
								}
								
								case 123:
								{
												drawSoilType(holeData,holeIndex,soilIndex);
							
												drawSoilClr(holeData,holeIndex,soilIndex);
							
												drawSoilStr(holeData,holeIndex,soilIndex);
									
												labelHole(holeData,holeIndex,15);
									
									
				
												break;
												
								}
								
								default:
								{
									printf("\nUnexpected parameter passed\n");
									break;
								
								}
				};
			
			
}

//End of drawGraphics








//Beginning of initGraphics proceedure. This initializes the graphics window and the arrays used in graphical operations
void initGraphics(struct dimenssionStruct*dimenPtr)
{


				//Draws graphics window, based on X range in pixels(+200px border for legend) and Y range in px
				initwindow((int)dimenPtr->rangeXScale+200,(int)dimenPtr->rangeYScale);
		
		
				
				initSoilClr();
	
				initSoilStr();
	
				initSoilType();
	
				//Sets drawing and fill color to GREEN
				setcolor(GREEN);
				setfillstyle(SOLID_FILL,GREEN);
	
				//Fills the Graphics window with a Green
				floodfill(0,0,GREEN);
}
//End of  initGraphics routine




//Beginning of calcHoleCoord proceedure. This calculates X and Y coords for every  bore hole (in px) and puts
//them into pixelX and pixelY respectively
void calcHoleCoord(struct holeStruct holeData[MAX_HOLES],struct dimenssionStruct*dimenPtr)
{

				//Contains difference between hole's X coord(in px) and maxX(in px)
				double xDiff=0;
	
	
				//Contains difference between hole's Y coord(in px) and maxY(in px)
				double yDiff=0;
	
				int i;
	
				for (i=0;i<MAX_HOLES;i++)
				{
	
	
							//Calculating X Coordinate
	
	
		
								//Checks if hole's X coord is same as minX
								if(holeData[i].eastX-METER_BORDER==dimenPtr->minX)
								{
												//Sets X coord to PIXEL_BORDER / Aligns the hole to the extreme left + 35px border
												holeData[i].pixelX=PIXEL_BORDER;
		
								}
	
	
								//Checks if hole's X Coord = maxX
								else if(holeData[i].eastX+METER_BORDER==dimenPtr->maxX)
								{
				
												//Sets X coord to X range (in px)-35px / Aligns the hole to the extreme right - 35px border
												holeData[i].pixelX=dimenPtr->rangeXScale-35;
		
	
	
								}
								else
								{
			
			
											//Holds the difference between X Coord of the hole (in px) and the maxX (in px)
											xDiff=abs((holeData[i].eastX*0.35)-dimenPtr->maxXScale);
				
				
											//Checks the difference
	
	
											//If the difference <35, shows below message
											if(xDiff<35)
											{
															printf("Graphics Window Is Not Large Enough to Display the Bore Holes");	
				 
											}
	
	
											//If difference is greater than rangeXScale-35 (right border),shows below message
											else if(xDiff>(dimenPtr->rangeXScale-35))
											{
															printf("Graphics Window Is Not Large Enough to Display the Bore Holes");	
				 	   	   	   	   
											}
	
											else
											{
						
															//Takes out the difference(in px)  between hole's X coord and minX
															holeData[i].pixelX=(holeData[i].eastX*0.35 - dimenPtr->minXScale);
			
											}
								}
		
				
	
	
 
		
		
							//Calculating Y Coordinate
	
								//Checks if hole's Y coord is same as minY
								if(holeData[i].northY-METER_BORDER==dimenPtr->minY)
								{
												//Aligns the hole to the bottom of the window-35px
												holeData[i].pixelY=dimenPtr->rangeYScale-35;
	
								}
		
								//Checks if hole's Y coord is same as maxY
								else if(holeData[i].northY+METER_BORDER==dimenPtr->maxY)
								{
												//Aligns the hole to the top of the window +35 px
												holeData[i].pixelY=35;
		
		
	
								}
	
								else
								{
												//Holds the difference between X Coord of the hole (in px) and the maxX (in px)
												yDiff=abs((holeData[i].northY*0.35)-dimenPtr->maxYScale);
		
	
		
 					 							if(yDiff<35)
												{
														setcolor(WHITE);
														outtextxy(2,2,"Graphics Window is not large enogh to display bore holes");	  
												}
					
												else if(yDiff> (dimenPtr->rangeYScale-35))
												{
														setcolor(WHITE);
														outtextxy(2,2,"Graphics Window is not large enogh to display bore holes");	  
				
												}
					
					
												else
												{
																//Takes out the difference(in px)  between hole's X coord and minX
																holeData[i].pixelY=(dimenPtr->maxYScale-holeData[i].northY*0.35);
												}
	
	
	
								}
				}
}
//End of calcHoleCoords() routine	 
	


//This routine calculates x and Y ranges of the survey area
void calcDimen(struct holeStruct holeData[MAX_HOLES],struct dimenssionStruct*dimenPtr)
{


				int i;
	
				//Declares and initializes variables
				dimenPtr->minX=holeData[0].eastX;
	
				dimenPtr->maxX=holeData[1].eastX;
	
				dimenPtr->rangeX=0;
	
				dimenPtr->minY=holeData[0].northY;
	
				dimenPtr->maxY=holeData[1].northY;
	
				dimenPtr-> rangeY=0;
	
				//Loops through holeData[] array to get minX, maxX , minY, maxY,
				for(i=0;i<MAX_HOLES;i++)
				{
	
								//Calculates maxX
								if (holeData[i].eastX>dimenPtr->maxX)
								{
			
												dimenPtr->maxX=holeData[i].eastX;
		
								}
		
		
								//Calculates minX
								else if(holeData[i].eastX<dimenPtr->minX)
								{
												dimenPtr->minX=holeData[i].eastX;
		
								}
		
		
		
		
								//Calculates maxY
								if (holeData[i].northY>dimenPtr->maxY)
								{
												dimenPtr->maxY=holeData[i].northY;
		
								}
		
								//Calculates minY
								else if(holeData[i].northY<dimenPtr->minY)
								{
												dimenPtr->minY=holeData[i].northY;
		
								}
	
				}

	
	
				//Apply border of 200m to X and Y Ranges to make a border of 100m around the bore hole display area
				dimenPtr->minX-=METER_BORDER;
				dimenPtr->maxX+=METER_BORDER;
	
				dimenPtr->minY-=METER_BORDER;
				dimenPtr->maxY+=METER_BORDER;
	
	
				//Calculate X and Y Ranges (in meters)
				dimenPtr->rangeX=(dimenPtr->maxX-dimenPtr->minX);
				dimenPtr->rangeY=(dimenPtr->maxY-dimenPtr->minY);
	

			//Now, scaling  from meters to pixels
	
	

				//Scaling X and Y co-ordinates from meters to pixels
				dimenPtr->minXScale=dimenPtr->minX*0.35;
				dimenPtr->maxXScale=dimenPtr->maxX*0.35;
		
				dimenPtr->minYScale=dimenPtr->minY*0.35;
				dimenPtr->maxYScale=dimenPtr->maxY*0.35;
		
				//Calculate X and Y Ranges (in pixels)
				dimenPtr->rangeXScale=(dimenPtr->maxXScale-dimenPtr->minXScale);
				dimenPtr->rangeYScale=(dimenPtr->maxYScale-dimenPtr->minYScale);

}

//End of calcDimen() routine



/*Beginning of processPrint() routine
This function processes the user input. It decides the depth (from every bore hole), that is closest to the user input. 
Then it displays the data at that
depth to the user*/
void processPrint(struct holeStruct holeData[MAX_HOLES],float inputDepth,char label1[50], char label2[50],struct dimenssionStruct*dimenPtr,int choice,int legend)
{


				/*This proceedure takes the user input, loops through holeData[] array and calculates the minimum 
				difference between the user input and  soil depths  (as contained in holeData[..].soilData[..] array) for every bore hole
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
	
								//Uses this nested for loop to calculate the depth from which soil information should be displayed
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
		
								switch (choice)
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
			
								}
			
		
								/*After printing the results on the console, drawGraphics routine is called, which
								draws results on the Graphics Window*/
								drawGraphics(holeData,holeIndex,soilIndex,choice,dimenPtr,legend);
		
								legend=0;
				}
	
				printf("\nTotal Number of Bore holes: %d\nMinimum X: %.3lf; Maximum X: %.3lf; Range X: %.3lf\nMinimum Y: %.3lf; Maximum Y: %.3lf\n RangeY: %.3lf\n",MAX_HOLES,dimenPtr->minX,dimenPtr->maxX,dimenPtr->rangeX,dimenPtr->minY,dimenPtr->maxY,dimenPtr->rangeY);
		

}
//End of processPrint() routine


/*Beginning of throwReadError() routine 
This function is called when there is an error reading data from file*/
int throwReadError()
{
		
				int readAgain=0;
	
				printf("\nError occoured while reading the file.\n");
				printf("\nPossible reasons are:\n1. File does not exist.\n2. You have entered incorrect file name or file path");
						
				printf("\nDo you want to attempt to read from the file once again?\n1=Yes\n2=No");
						
				printf("\nEnter number of your choice:\n");
						
				scanf("%d",&readAgain);
		
				//If a value of 2 is returned, program exits. Else if 1 is returned, read is again attemted
				return readAgain;
}
/*End of throwReadError() routine*/


/*Beginning of readData() routine
This function reads data from the user-specified file*/
int readData(struct holeStruct holeData[MAX_HOLES],char label1[50],char label2[50])
{

				char fileName[14];
	
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
								printf("\nEnter name of the file, from which you wish to read the data.\n");
								scanf("%s",fileName);
	
								printf("\nReading data from file. Please wait...\n");
	
								dataFile=fopen(fileName,"r");
	
	

	
								//If there is no problem opening data file, below code is executed
								if (dataFile!=NULL)
								{
		
												//This for loop reads the 2 labels at the top of the boreholes.txt file
												for(iHole=0;iHole<2;iHole++)
												{
			
																switch(iHole)
																{
																	case 0:
																	{
																			fgets(label1,50,dataFile);
																			break;
																	}
											
					
																	case 1:
																	{
																			fgets(label2,50,dataFile);
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
											
																							readAgain=throwReadError();
											
																							break;
							
																				}	   	   	   
																}

			
																else
																{
																				/*If number of assignments made by fscanf() for a bore hole !=4,
																				throwReadError() is called*/
																				result=1;
											
																				readAgain=throwReadError();
						
																				break;
					
																}
				
						
																result=0;
		
												}




			
	

								}
			

								//If there is a problem opening data file, throwReadError() is called
								else if(dataFile==NULL)
								{					
												result=1;
											
												readAgain=throwReadError();
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
	
				return choice;

}
//End of displayMenu() routine


/*Beginning of displaySoilMenu() routine

This function asks the user what soil Data he wants to be displayed*/
int displaySoilMenu()
{

				/*This function returns the integer value entered by the user. 
				Do...while loop is used to make sure user does not enter a value other than 
				the expected values. This function returns the user entered number to the main(void) routine.*/
	
				int choice=0;
				do
				{
								fflush(stdin);
								printf("\nSelect the data you wish to display:\n");
								printf("1= Soil Type\n2= Soil Color\n3= Soil Strength\n");
								printf("12= Soil Type & Soil Color\n13= Soil Type & Soil Strength\n23= Soil Color & Soil Strength\n123= Soil Type, Soil Color & Soil Strength\n");
	
								scanf("%d",&choice);

				}while(choice!=1 && choice!=2 && choice !=3 && choice !=12 && choice !=23 && choice!=13 && choice!=123);
	
				return choice;

}
/*End of displaySoilMenu() routine*/







/*Beginning of showAllData() routine
This function prints all data read from text file (and stored in holeData[MacHoles] array)*/
void showAllData(struct holeStruct holeData[MAX_HOLES],char label1[50], char label2[50],struct dimenssionStruct*dimenPtr)
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
	
							//This nested for loop prints all the soil information for every depth of a perticular hole
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


//Beginning of main(void)
int main(void)
{
	
	


	
				//Initializes variables
				struct holeStruct holeData[MAX_HOLES];
	
				struct dimenssionStruct dimenssion;
	
				struct dimenssionStruct*dimenPtr=&dimenssion;
	
				char label1[50];
	
				char label2[50];
	
				float inputDepth=0;
	
				//Holds input indicating if user wants to run or quit the program	 
				int mainChoice=0;
	
				//This hold the value (as returned by scanf()) indicating number of assignments made
				int validDepth=0;
	
				int soilChoice=0;
	
	
	

				int readResult=0; 
	
				//result from readData function is stored in readResult var.
				readResult=readData(holeData,label1,label2);
	
				
				switch(readResult)
				{
	
					case 0:
					{
		
								
									//If readResult=0, below code is executed
										   
									calcDimen(holeData,dimenPtr);
	
									calcHoleCoord(holeData,dimenPtr);
	
									initGraphics(dimenPtr);
	
									showAllData(holeData,label1,label2,dimenPtr);

									setcolor(WHITE);
									outtextxy(2,2,"Enter a depth in the console to see the soil information at that depth here.");	  
				 
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
					
																soilChoice=displaySoilMenu();
					
																processPrint(holeData,inputDepth,label1,label2,dimenPtr,soilChoice,1);
					
						
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



