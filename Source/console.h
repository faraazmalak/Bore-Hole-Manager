//Fuction ProtoTypes
void processInput(struct hole holeData[MAX_HOLES],soil_palette soilPalette,float inputDepth,char label1[50], char label2[50],struct graphicWindow*dimenPtr,char* choice,int legend);
int displayMainMenu();
char* displaySoilMenu();
void showAllData(struct hole holeData[MAX_HOLES],char label1[LABEL_LENGTH], char label2[LABEL_LENGTH],struct graphicWindow*dimenPtr);
bool check_choice(char choice);


