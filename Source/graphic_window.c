#ifndef MAIN_HEADER
#define MAIN_HEADER 1
#include "main.h"
#endif
#include "error.h"
#include "graphic_window.h"
//#include "soil_palette.h"//included from main.h
//#include "hole.h"
//Function Implementation
//Beginning of labelHole proceedure. This draws a number on the window representining a  bore hole
void labelHole(struct hole holeData[MAX_HOLES], int holeIndex, int radius)
{
	//Holds the hole number
	char holeNum[3];
	//Converts the int representing hole num. into string
	sprintf(holeNum, "%d", holeIndex + 1);
	//Sets the drawing color to white
	setcolor(WHITE);
	//Draws the hole number on the graphics window, based on the radius parameter, X nad Y coords
	outtextxy((int)holeData[holeIndex].pixelX + radius, (int)holeData[holeIndex].pixelY - 8, holeNum);
}
//End of labelHole routine
//This function drwas the legend and the corresponding lables on the graphics window
void drawLegend(struct graphicWindow*dimenPtr, soil_palette soilPalette)
{
	//This array defines coords for the legend keys (rectangular boxes)
	int coords[] = {0, 0, 0, 0, 0, 0, 0, 0};
	//Counter var
	int i;
	//Sets x coord for the  legend, which is x range of bore hole display area (including the borders) + another 35px
	int  x = (int)dimenPtr->rangeXScale + PIXEL_BORDER;
	//This variable contains total distance from the top of the window
	int height = 0;
	//-----------------
	//Draws legend for Soil Type
	setcolor(WHITE);
	outtextxy(x, 2, "SOIL TYPE");
	//Initializes variable to the height of this text
	height = textheight("SOIL TYPE");
	//Sets drawing color to white and shows the text on graphics window
	setcolor(WHITE);
	outtextxy(x, 2, "SOIL TYPE");
	for (i = 0;i < 9;i++)
	{
		//Top top left coord
		coords[0] = x;
		//Adds a padding of 10 px on the top
		coords[1] = height + 10;
		//End of top left coord
		//Top right coord
		//Makes the legend key 20px wide
		coords[2] = x + 20;
		//Adds padding of 10px from the top
		coords[3] = height + 10;
		//End of top right coord
		//Bottom Right Coord
		//Makes the legend key 20px wide
		coords[4] = x + 20;
		//Adds 25px to the height variable (Equation= total height from top of the window + 5 px top padding + 20px height)
		coords[5] = height + 25;
		//End of Bottom Right Coord
		//Botton Left coord
		coords[6] = x;
		//Adds 25px to the height variable (Equation= total height from top of the window + 5 px top padding + 20 px height)
		coords[7] = height + 25;
		//End of Botton Left coord
		height += 20;
		//Draws the Legend Key
		setcolor(soilPalette.type[i].value);
		setfillstyle(SOLID_FILL, soilPalette.type[i].value);
		fillpoly(4, coords);
		//Draws the label for this legend key
		setcolor(WHITE);
		outtextxy(coords[2] + 4, coords[1], soilPalette.type[i].name);
	}
	//---------------------
	//------------------------
	//Draws legend for sample color
	//Sets drawing color to white and shows the text on graphics window
	setcolor(WHITE);
	outtextxy(x, height + 12, "SAMPLE COLORS");
	//Sets the top padding to 10px
	height += textheight("SAMPLE COLORS") + 10;
	for (i = 0;i < 9;i++)
	{
		//Top top left coord
		coords[0] = x;
		//Adds a padding of 10 px on the top
		coords[1] = height + 10;
		//End of top left coord
		//Top right coord
		//Makes the legend key 20px wide
		coords[2] = x + 20;
		//Adds padding of 10px from the top
		coords[3] = height + 10;
		//End of top right coord
		//Bottom Right Coord
		//Makes the legend key 20px wide
		coords[4] = x + 20;
		//Adds 25px to the height variable (Equation= total height from top of the screen + 5 px top padding + 20px height)
		coords[5] = height + 25;
		//End of Bottom Right Coord
		//Botton Left coord
		coords[6] = x;
		//Adds 25px to the height variable (Equation= total height from top of the screen + 5 px top padding + 20 px height)
		coords[7] = height + 25;
		//End of Botton Left coord
		height += 20;
		//Draws the Legend Key
		setcolor(soilPalette.color[i].value);
		setfillstyle(SOLID_FILL, soilPalette.color[i].value);
		fillpoly(4, coords);
		//Draws the label for this legend key
		setcolor(WHITE);
		outtextxy(coords[2] + 4, coords[1], soilPalette.color[i].name);
	}
	//------------------
	//----------------------------
	//Draws legend for sample strength
	//Sets drawing color to white and shows the text on graphics window
	setcolor(WHITE);
	outtextxy(x, height + 12, "SAMPLE STRENGTH");
	//Sets the top padding to 10px
	height += textheight("SAMPLE STRENGTH") + 10;
	for (i = 0;i < 10;i++)
	{
		//Top top left coord
		coords[0] = x;
		//Adds a padding of 10 px on the top
		coords[1] = height + 10;
		//End of top left coord
		//Top right coord
		//Makes the legend key 20px wide
		coords[2] = x + 20;
		//Adds padding of 10px from the top
		coords[3] = height + 10;
		//End of top right coord
		//Bottom Right Coord
		//Makes the legend key 20px wide
		coords[4] = x + 20;
		/*Adds 25px to the height variable
		(Equation= total height from top of the screen + 5 px top padding + 20px height)*/
		coords[5] = height + 25;
		//End of Bottom Right Coord
		//Botton Left coord
		coords[6] = x;
		//Adds 25px to the height variable (Equation= total height from top of the screen + 5 px top padding + 20 px height)
		coords[7] = height + 25;
		//End of Botton Left coord
		height += 20;
		//Draws the Legend Key
		setcolor(soilPalette.strength[i].value);
		setfillstyle(SOLID_FILL, soilPalette.strength[i].value);
		fillpoly(4, coords);
		//Draws the label for this legend key
		setcolor(WHITE);
		outtextxy(coords[2] + 4, coords[1], soilPalette.strength[i].name);
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
	setfillstyle(SOLID_FILL, GREEN);
	//Fills the graphics window with a green
	floodfill(0, 0, GREEN);
}
//End of eraseGraphics routine
//This set of routines draw circles on graphics window, representing soilPalette Attributes
//Draws circles representing soilPalette types
void drawSoilType(struct hole holeData[MAX_HOLES], soil_palette soilPalette, int holeIndex, int soilIndex)
{
	int i;
	//Loops through typeName (strings representing soilPalette Types)
	for (i = 0;i < 9;i++)
	{
		//Checks if typeName (strings representing soilPalette Types) = holeData[hole].soilData[soilPalette].type
		if (strcmp(soilPalette.type[i].name, holeData[holeIndex].soilData[soilIndex].type) == 0)
		{
			//Sets drawing & fill colors (to the integer value contained at typeColor[i])
			setcolor(soilPalette.type[i].value);
			setfillstyle(SOLID_FILL, soilPalette.type[i].value);
			//Draws a circle and fills it up with color contained at typeColor[i]
			circle(holeData[holeIndex].pixelX, holeData[holeIndex].pixelY, 15);
			floodfill((int)holeData[holeIndex].pixelX, (int)holeData[holeIndex].pixelY, soilPalette.type[i].value);
		}
	}
}
//End of drawSoilType routine
//Draws circles representing soilPalette strengths
void drawSoilStr(struct hole holeData[MAX_HOLES], soil_palette soilPalette, int holeIndex, int soilIndex)
{
	int i;
	//Loops through hardName Array (strings representing soilPalette Strengths)
	for (i = 0;i < 10;i++)
	{
		//Checks if hardName (strings representing soilPalette Strengths) = holeData[holeIndex].soilData[soilIndex].strength
		if (strcmp(soilPalette.strength[i].name, holeData[holeIndex].soilData[soilIndex].strength) == 0)
		{
			//Sets drawing & fill colors (to the integer value contained at hardColor[i])
			setcolor(soilPalette.strength[i].value);
			setfillstyle(SOLID_FILL, soilPalette.strength[i].value);
			//Draws a circle and fills it up with color contained at hardColor[i]
			circle(holeData[holeIndex].pixelX, holeData[holeIndex].pixelY, 5);
			floodfill((int)holeData[holeIndex].pixelX, (int)holeData[holeIndex].pixelY, soilPalette.strength[i].value);;
		}
	}
}
//End of soilPalette drawSoilStr routine
//Draws circles representing soilPalette colors
void drawSoilClr(struct hole holeData[MAX_HOLES], soil_palette soilPalette, int holeIndex, int soilIndex)
{
	int i;
	//Loops through hardName Array (strings representing soilPalette Strengths)
	for (i = 0;i < 9;i++)
	{
		//Checks if colorName (strings representing soilPalette colors) = holeData[hole].soilData[soilPalette].color
		if (strcmp(soilPalette.color[i].name, holeData[holeIndex].soilData[soilIndex].color) == 0)
		{
			//Sets drawing & fill colors (to the integer value contained at ColorValue[i])
			setcolor(soilPalette.color[i].value);
			setfillstyle(SOLID_FILL, soilPalette.color[i].value);
			//Draws a circle and fills it up with color contained at ColorValue[i]
			circle(holeData[holeIndex].pixelX, holeData[holeIndex].pixelY, 10);
			floodfill((int)holeData[holeIndex].pixelX, (int)holeData[holeIndex].pixelY, soilPalette.color[i].value);
		}
	}
}
//End of drawSoilClr routine
//End of Functions that draw soilPalette attributes on the graphics window
//This function controls drawing of bore holes and the Legend
void drawGraphics(struct hole holeData[MAX_HOLES], soil_palette soilPalette, int holeIndex, int soilIndex, char* choice, struct graphicWindow*dimenPtr, int legend)
{
	int i;
	//If the legend parameter=1, then drawLegend proceedure is called
	if (legend == 1)
	{
		drawLegend(dimenPtr, soilPalette);
	}
	
	for (int i = 0;i < strlen(choice);i++)
	{
		if (choice[i] == '1')
		{
			drawSoilType(holeData, soilPalette, holeIndex, soilIndex);
			labelHole(holeData, holeIndex, 15);
		}
		else if (choice[i] == '2')
		{
			drawSoilClr(holeData, soilPalette, holeIndex, soilIndex);
			labelHole(holeData, holeIndex, 10);
		}
		else if (choice[i] == '3')
		{
			drawSoilStr(holeData, soilPalette, holeIndex, soilIndex);
			labelHole(holeData, holeIndex, 5);
		}
		break;
	}
	//Dpending on the value of choice parameter, appropriate proccedure to draw bore hole circles is called,
	/*	  switch (choice)
		{
						case 1:
						{
		
				
										drawSoilType(holeData,soilPalette,holeIndex,soilIndex);
						
										labelHole(holeData,holeIndex,15);
				
										break;
							
						}
		
						case 2:
						{
		
										drawSoilClr(holeData,soilPalette,holeIndex,soilIndex);
						
										labelHole(holeData,holeIndex,10);
			
										break;
						}
						
						case 3:
						{
										drawSoilStr(holeData,soilPalette,holeIndex,soilIndex);
									
										labelHole(holeData,holeIndex,5);
										
										break;
						}
						case 12:
		
						{
				
										drawSoilType(holeData,soilPalette,holeIndex,soilIndex);
					
										drawSoilClr(holeData,soilPalette,holeIndex,soilIndex);
		
										labelHole(holeData,holeIndex,15);
				
							
										break;
						}
						case 13:
						{
										drawSoilType(holeData,soilPalette,holeIndex,soilIndex);
							
										drawSoilStr(holeData,soilPalette,holeIndex,soilIndex);
							
										labelHole(holeData,holeIndex,15);
										break;
						
						}
						
						case 23:
						{
										drawSoilClr(holeData,soilPalette,holeIndex,soilIndex);
					
										drawSoilStr(holeData,soilPalette,holeIndex,soilIndex);
												
										labelHole(holeData,holeIndex,10);
					
										break;
						}
						
						case 123:
						{
										drawSoilType(holeData,soilPalette,holeIndex,soilIndex);
					
										drawSoilClr(holeData,soilPalette,holeIndex,soilIndex);
					
										drawSoilStr(holeData,soilPalette,holeIndex,soilIndex);
							
										labelHole(holeData,holeIndex,15);
							
							
		
										break;
										
						}
						
						default:
						{
							printf("\nUnexpected parameter passed\n");
							break;
						
						}
		};
	*/
}
//End of drawGraphics
//Beginning of calcHoleCoord proceedure. This calculates X and Y coords for every  bore hole (in px) and puts
//them into pixelX and pixelY respectively
//Beginning of calcHoleCoord proceedure. This calculates X and Y coords for every  bore hole (in px) and puts
//them into pixelX and pixelY respectively
void calcHoleCoord(struct hole holeData[MAX_HOLES], struct graphicWindow*dimenPtr)
{
	//Contains difference between hole's X coord(in px) and maxX(in px)
	double xDiff = 0;
	//Contains difference between hole's Y coord(in px) and maxY(in px)
	double yDiff = 0;
	int i;
	for (i = 0;i < MAX_HOLES;i++)
	{
		//Calculating X Coordinate
		//Checks if hole's X coord is same as minX
		if (holeData[i].eastX - METER_BORDER == dimenPtr->minX)
		{
			//Sets X coord to PIXEL_BORDER / Aligns the hole to the extreme left + 35px border
			holeData[i].pixelX = PIXEL_BORDER;
		}
		//Checks if hole's X Coord = maxX
		else if (holeData[i].eastX + METER_BORDER == dimenPtr->maxX)
		{
			//Sets X coord to X range (in px)-35px / Aligns the hole to the extreme right - 35px border
			holeData[i].pixelX = dimenPtr->rangeXScale - PIXEL_BORDER;
		}
		else
		{
			//Holds the difference between X Coord of the hole (in px) and the maxX (in px)
			xDiff = abs((holeData[i].eastX * PIXEL_SCALE_VALUE) - dimenPtr->maxXScale);
			//Checks the difference
			/*If the difference <35,
			*OR
			*If difference is greater than rangeXScale-35 (right border),
			*shows below error msg
			*/
			if ((xDiff < PIXEL_BORDER) || (xDiff > (dimenPtr->rangeXScale - PIXEL_BORDER)))
			{
				struct error error;
				error.display = "graphic";
				error.msg = "Graphics Window Is Not Large Enough to Display the Bore Holes";
				throwError(error);
			}
			else
			{
				//Takes out the difference(in px)  between hole's X coord and minX
				holeData[i].pixelX = (holeData[i].eastX * PIXEL_SCALE_VALUE) - dimenPtr->minXScale;
			}
		}
		//Calculating Y Coordinate
		//Checks if hole's Y coord is same as minY
		if (holeData[i].northY - METER_BORDER == dimenPtr->minY)
		{
			//Aligns the hole to the bottom of the window-35px
			holeData[i].pixelY = dimenPtr->rangeYScale - PIXEL_BORDER;
		}
		//Checks if hole's Y coord is same as maxY
		else if (holeData[i].northY + METER_BORDER == dimenPtr->maxY)
		{
			//Aligns the hole to the top of the window +35 px
			holeData[i].pixelY = PIXEL_BORDER;
		}
		else
		{
			//Holds the difference between X Coord of the hole (in px) and the maxX (in px)
			yDiff = abs((holeData[i].northY * PIXEL_SCALE_VALUE) - dimenPtr->maxYScale);
			if ((yDiff < PIXEL_BORDER) || (yDiff > (dimenPtr->rangeYScale - PIXEL_BORDER)))
			{
				setcolor(WHITE);
				outtextxy(2, 2, "Graphics Window is not large enogh to display bore holes");
			}
			else
			{
				//Takes out the difference(in px)  between hole's X coord and minX
				holeData[i].pixelY = (dimenPtr->maxYScale - holeData[i].northY * PIXEL_SCALE_VALUE);
			}
		}
	}
}
//End of calcHoleCoords() routine
//This routine calculates x and Y ranges of the survey area
void calcDimen(struct hole holeData[MAX_HOLES], struct graphicWindow*dimenPtr)
{
	int i;
	//Declares and initializes variables
	dimenPtr->minX = holeData[0].eastX;
	dimenPtr->maxX = holeData[1].eastX;
	dimenPtr->rangeX = 0;
	dimenPtr->minY = holeData[0].northY;
	dimenPtr->maxY = holeData[1].northY;
	dimenPtr-> rangeY = 0;
	//Loops through holeData[] array to get minX, maxX , minY, maxY,
	for (i = 0;i < MAX_HOLES;i++)
	{
		//Calculates maxX
		if (holeData[i].eastX > dimenPtr->maxX)
		{
			dimenPtr->maxX = holeData[i].eastX;
		}
		//Calculates minX
		else if (holeData[i].eastX < dimenPtr->minX)
		{
			dimenPtr->minX = holeData[i].eastX;
		}
		//Calculates maxY
		if (holeData[i].northY > dimenPtr->maxY)
		{
			dimenPtr->maxY = holeData[i].northY;
		}
		//Calculates minY
		else if (holeData[i].northY < dimenPtr->minY)
		{
			dimenPtr->minY = holeData[i].northY;
		}
	}
	//Apply border of 200m to X and Y Ranges to make a border of 100m around the bore hole display area
	dimenPtr->minX -= METER_BORDER;
	dimenPtr->maxX += METER_BORDER;
	dimenPtr->minY -= METER_BORDER;
	dimenPtr->maxY += METER_BORDER;
	//Calculate X and Y Ranges (in meters)
	dimenPtr->rangeX = (dimenPtr->maxX - dimenPtr->minX);
	dimenPtr->rangeY = (dimenPtr->maxY - dimenPtr->minY);
	//Now, scaling  from meters to pixels
	//Scaling X and Y co-ordinates from meters to pixels
	dimenPtr->minXScale = dimenPtr->minX * PIXEL_SCALE_VALUE;
	dimenPtr->maxXScale = dimenPtr->maxX * PIXEL_SCALE_VALUE;
	dimenPtr->minYScale = dimenPtr->minY * PIXEL_SCALE_VALUE;
	dimenPtr->maxYScale = dimenPtr->maxY * PIXEL_SCALE_VALUE;
	//Calculate X and Y Ranges (in pixels)
	dimenPtr->rangeXScale = (dimenPtr->maxXScale - dimenPtr->minXScale);
	dimenPtr->rangeYScale = (dimenPtr->maxYScale - dimenPtr->minYScale);
}
//End of calcDimen() routine
void drawText(char*txt)
{
	resetWindow();
	setcolor(WHITE);
	clearviewport();
	outtextxy(2, 2, txt);
}
void resetWindow()
{
	//Sets background color to GREEN
	setbkcolor (GREEN);
	//Sets drawing color to WHITE
	setcolor(WHITE);
	clearviewport();
}
//Beginning of initGraphics proceedure. This initializes the graphics window and the arrays used in graphical operations
void initGraphics(struct graphicWindow*dimenPtr, soil_palette*soilPalette)
{
	//Draws graphics window, based on X range in pixels(+200px border for legend) and Y range in px
	initwindow((int)dimenPtr->rangeXScale + 200, (int)dimenPtr->rangeYScale);
	resetWindow();
	drawText("Enter a depth in the console to see the soil info. at that depth.");
	initSoilClr(soilPalette);
	initSoilStr(soilPalette);
	initSoilType(soilPalette);
}
//End of  initGraphics routine

