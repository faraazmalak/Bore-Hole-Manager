

//Defines struct to contain the dimenssions of the Graphics Window
struct graphicWindow
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

//Interface definition
void labelHole(struct hole,int hole,int radius);
//void drawLegend(struct graphicWindow*dimenPtr,soil_palette soilPalette);
void eraseGraphics();
//void drawSoilType(struct hole holeData[MAX_HOLES],soil_palette soilPalette,int holeIndex,int soilIndex);
void drawSoilType(struct hole holeData[MAX_HOLES],soil_palette soilPalette,int holeIndex,int soilIndex);
void drawSoilStr(struct hole holeData[MAX_HOLES],soil_palette soilPalette,int holeIndex,int soilIndex);
void drawSoilClr(struct hole holeData[MAX_HOLES],soil_palette soilPalette,int holeIndex,int soilIndex);
void drawGraphics(struct hole holeData[MAX_HOLES],soil_palette soilPalette,int holeIndex, int soilIndex,char* choice,struct graphicWindow*dimenPtr,int legend);
void initGraphics(struct graphicWindow*dimenPtr);
void calcHoleCoord(struct hole holeData[MAX_HOLES],struct graphicWindow*dimenPtr);

void calcDimen(struct hole holeData[MAX_HOLES],struct graphicWindow*dimenPtr);

void initGraphics(struct graphicWindow*dimenPtr,soil_palette*soilPalette);


void drawText(char*txt);


void resetWindow();

