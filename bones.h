#include "constants.h"
/*
NOTE: typedef is just a synonym, DOMINO Bones[MAXBONES] is the same as
struct domino Bones[MAXBONES]
*/

/* a domino */ 
typedef struct domino { 
    int left;   /* the value of the left half of the domino */ 
    int right;  /* the value of the right halof of the domino */
    int points; /*The sum of the two sides of the domino*/
    int number; /*The index number of the domino*/
    int select; /*Value determine's wether domino is selected or not*/
    struct domino *next;
    } DOMINO;
    
    DOMINO Bones[MAXBONES];/*Creates 28 Dominoes required for the game*/ 
    DOMINO leftGen, rightGen;

/*Hand*/    
typedef struct hand {
   int played;
   int left;
   int right;
   int points; /*Points per domino*/
   int rest;   /*Double or not */
   int number; /*domino index number in the players' hand*/
   struct hand *nextBone;
   }HAND;
   
   HAND User[HANDSIZE], Cpu[HANDSIZE], Cpu2[HANDSIZE];/*Create's structures for players' hands*/


typedef struct handstats {
   int bonesPlayed;
   int lgstRestIndex;
   int largestRest;
   int restCount;
   int points;
   }HANDSTATS;
   
   HANDSTATS user, cpu, cpu2;

typedef struct Played
   {
          int leftVal;
          int rightVal;

          struct Played *next;/* self referencial */
 
   } ONTABLE;

 /* objects to structure Played for each side of each individual bone */
    ONTABLE startLeft, startRight;
    
    /* structure to store game statistics */
    typedef struct GameStats{
        int id;
        char name[10];
        int games;
        int wins;
        int losses;
        int draw;
        int rating;
        float winRate;
        } STATS;
      
      STATS gameStats, players[7]; //object to game statistics structure
