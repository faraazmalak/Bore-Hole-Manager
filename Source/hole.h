
//#include "graphic_window.h"
//Structure Definition

struct hole
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
//	  struct soilSample soilData[21];
	//Defines the struct for soil sample found at a perticular depth
		struct soilSample
	{
		//Will contain type of soil
		char type[20];
		//Will contain color of the soil
		char color[20];
		//Will contain strength of the soil
		char strength[20];
		//Will contain the depth, at which the sample was found
		float depth;
	}soilData[21];

};
//Interface
//Function Implementation

