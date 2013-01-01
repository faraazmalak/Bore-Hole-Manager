



//Data structure
struct soil_palette
{
	struct color strength[9];
	struct color type[9];
	struct color color[9];


};


//Interface
void initSoilType(soil_palette*soilPalette);
void initSoilStr(soil_palette*soilPalette);
void initSoilClr(soil_palette*soilPalette);






