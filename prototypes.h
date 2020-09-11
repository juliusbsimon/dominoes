/*CORE Functions*/

void callCreateBones();
void callRandomSelect();
void createBones(DOMINO *leftGen, DOMINO *rightGen, DOMINO *bones);
void randomSelect(DOMINO *bones, HAND *user, HAND *computer, HAND *computer2, HANDSTATS *userStats, HANDSTATS *cpuStats, HANDSTATS *cpu2Stats);

void printGamename();
void printLoading();
void progressBar();
int gameOver(int domsPlayed_u, int domsPlayed_c, int domsPlayed_c2);

/*Functions Related to Structures*/
int getLargestRest(HAND *ptr1, HANDSTATS *ptr2);

void txtcolor(char color[ 13 ]);
void bgcolor(char color[ 13 ]);
/*Play functions*/
int returnIndex(HANDSTATS *ptr);
void printNewHand(HAND *ptr);
void setPlayed(HAND *ptr);
void flipBone(HAND *ptr);

int calculatePoints(HAND *user, HAND *computer, HAND *computer2);

int userPlay();
int cpuPlay();

int endGame(int dominoesPlayed_u, int dominoesPlayed_c, int dominoesPlayed_c2);

/*Validation Functions*/
int checkHand(HAND *ptr);
int isValid(HAND *ptr);
int isPlayed(HAND *ptr);
int directionTest(HAND *ptr, int direction);

/* function to insert either to the left or right of start bone */
void placeBone(ONTABLE *startLeft, ONTABLE *startRight, HAND *insert, int direction);

/* function to display bones on tables */   
void displayTable(ONTABLE *left, ONTABLE *right);


void printGenerated(DOMINO *left, DOMINO *right);
int returnLeft(DOMINO *left, int choosen);
int returnRight(DOMINO *right, int choosen);


int cpuAI(HAND *computerHand);
int cpuAI_PlayLargest(HAND *computerHand);

int loadStats();
int saveStats();
void resetStats();

int saveCpuStats();
int getCpuStats();
int resetCpuStats();
void showrating(STATS *ptr);

void playerStatsDisplay(int id);
void GameStatsDisplay(int save);
void calculateGamesWinRate();

/* THIS IS SO CRAZY LMAO!!! */
void pickUpBones(int amountPlayed);
void pickUpBonesLeft(ONTABLE *pickUpLeft, int tableLength);
void pickUpBonesRight(ONTABLE *pickUpRight, int tablelength);
void putBackRight(DOMINO *packRight, int rightVal);
void putBackLeft(DOMINO *packLeft, int leftVal);
void putBackHand(HAND *userHand, HAND *cpuHand, HAND *cpu2Hand);
void tempPrintHand(HAND *userHand, HAND *cpuHand, HAND *cpu2Hand);

void reset();

int menu();
int viewHelp();
void rankings();
