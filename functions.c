#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <time.h>
#include <string.h>
#include "bones.h"
#include "prototypes.h"
#include "constants.h"
#define SIZE 150


//----------------------------------------------------------------------------//
void initPlayers()
{
   char opponents[7][10] = {"Julius","Maxx","Champ","Roger","Deceiver","Maverick","Xan"};
   int i;
   
   strcpy(gameStats.name, "Your");
   for(i=0;i<7;i++)
   {
      players[i].id = i;
      strcpy(players[i].name, opponents[i]);
      players[i].winRate = 0;
      players[i].draw = 0;
      players[i].losses = 0;
      players[i].wins = 0;
      
   }
   
}      
//----------------------------------------------------------------------------//      


//----------------------------------------------------------------------------//

void selectOpponents()
{
   
   srand(time(NULL));
   opp1 = rand()% 7;
   while (1)
   {
      opp2= rand()%7;
      
      if (opp2== opp1)
         opp2 = rand()%7;
      
      else
         break;
   }      
}/* end selectOpponets */
         
//----------------------------------------------------------------------------//
void progressBar()
{
   int i,j;
   char bar='=';
   
   for(i=0;i<=100;i++)
   {
      txtcolor("WHITE");
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t");
      printf("Loading New Game...%d %% Complete", i);
      printf("\n\t\t\t");
         
      if (i<=35)
         txtcolor("LIGHTRED");
      else if (i > 35 && i < 65)
         txtcolor("LIGHTBLUE");
      else
         txtcolor("LIGHTGREEN");
      
      for(j=0;j<=i/2.85;j++)
      {
         printf("%c", bar);
      }
      
      printf("\n\t\t\t");
      
      for(j=0;j<=i/2.85;j++)
      {
         printf("%c", bar);
      }
         
      if(i==100)
      {
         sleep(1500);
      } 
      else  
         sleep(25);
            
         system("cls");
      }
      
      system("pause");
      system("cls");
}
   



//----------------------------------------------------------------------------//
void printLoading()
{
   printGamename();
   
   int i,j;
   char bar='=';
   char items[5][10]={
                     "Dominoes",
                     "AI",
                     "User",
                     "Table",
                     "Interface"
                     };
   int Current;                   
   for(i=0;i<=100;i++)
   {
      txtcolor("WHITE");
      if (i<=15)
      Current=0;
      else if (i>15 && i<=45)
      Current=1;
      else if (i>45 && i<=60)
      Current=2;
      else if (i>60 && i<=80)
      Current=3;
      else if (i>80)
      Current=4;
      
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t");
      printf("Initializing: %s...%d %% Complete",items[Current], i);
      
      printf("\n\t\t\t");
      
      if (i<=35)
         txtcolor("LIGHTRED");
      else if (i > 35 && i < 65)
         txtcolor("LIGHTBLUE");
      else
         txtcolor("LIGHTGREEN");
      
      for(j=0;j<=i/2.5;j++)
      {
         printf("%c", bar);
      }
      printf("\n\t\t\t");
      for(j=0;j<=i/2.5;j++)
      {
         printf("%c", bar);
      }   
      
      if(i==100)
      {
         sleep(1500);
      }
      else if (i > 15 && i < 45 )
      {
         sleep(200);
      }
      else if (i > 45 && i < 65 )
         sleep(150);
      else
         sleep(85);
         
      system("cls");
   }
   txtcolor("WHITE");
   printf("Loading Complete\n");
   printf("Press any key to wash dominoes.\n");
   getch();
   printf("Washing Dominoes...\n");

   sleep(1000);
   system("cls");
   printf("Washing Completed.\n");
   printf("Press any key to pick your hand.\n");
   getch();
   system("cls");
}

//----------------------------------------------------------------------------//
void callCreateBones()
{
     createBones(&leftGen, &rightGen, Bones);
}

//----------------------------------------------------------------------------//
void callRandomSelect()
{
     randomSelect(Bones, User, Cpu, Cpu2, &user, &cpu, &cpu2);
}

//----------------------------------------------------------------------------//

void pickUpBones(int amountPlayed)
{
     pickUpBonesLeft(&startLeft, amountPlayed);
     pickUpBonesRight(&startRight, amountPlayed);
     //displayTable(&startLeft, &startRight);
     putBackHand(&User[0], &Cpu[0], &Cpu2[0]);
     //printf("END OF DELETION OF BONES ON TABLES\n");
//     getch();
   
}
//----------------------------------------------------------------------------//
void printGamename()
{
   printf("\n\n\n\n\n");
   txtcolor("LIGHTRED");
   printf("\t\tDDDD    OOO   MM   MM  **   N     N   OOO    EEEE   SSSS \n");
   printf("\t\tD   D  O   O  M MMM M       N N   N  O   O   E     S     \n");
   printf("\t\tD   D  O   O  M  M  M  II   N  N  N  O   O   EEEE   SSSS      \n");
   printf("\t\tD   D  O   O  M     M  II   N    NN  O   O   E          S  \n");
   printf("\t\tDDDD    OOO   M     M  II   N     N   OOO    EEEE   SSSS   \n");
   
   printf("\n");
   printf("\n");
   
   txtcolor("LIGHTGREEN");
   printf("\t                         GGGGGGGG      TTTTTTTT \n");
   printf("\t                        GG                TT    \n");
   printf("\t                        GG                TT    \n");
   printf("\t                        GG     GGGG       TT    \n");
   printf("\t                        GG      GG   **   TT    \n");
   printf("\t                         GGGGGGGGG   **   TT    \n");
   
   printf("\n");
   printf("\n");
   
   txtcolor("YELLOW");
   printf("\t\t\t   SSSS   TTTTTT YY   YY  L      EEEE   \n");
   printf("\t\t\t  S         TT     YYY    L     E          \n");
   printf("\t\t\t   SSSS     TT      Y     L      EEEE       \n");
   printf("\t\t\t       S    TT      Y     L     E       \n");
   printf("\t\t\t   SSSS     TT      Y     LLLL   EEEE    \n");
   
   getch();
   system("cls");
   
}
//----------------------------------------------------------------------------//
int loadStats()
{
     /*--------------------------------------------------*/
     /* NOTE: It is of importance to manally             */
     /* create stats.txt if the game is going            */
     /* to be run for the very frist time                */
     /* and set all initial values                       */ 
     /* to be read to zero. This is because of reasons   */
     /* of incrementation and such.                      */
     /*--------------------------------------------------*/
     FILE *fp; /* create file pointer */
          
     fp = fopen("data\\stats.st", "r"); /* open file for reading */
     
     /* test if file opened successfully */
     if(fp == NULL)
     {
           printf("Error loading stats. Stats Data File does not exist\n");
           printf("The file will now be created. Please Restart the game.\n");
           resetStats();
           printf("Press Any Key To Exit.\n");
           getch();
           exit(-1);
           return 0;
     }
     
     /* read data from file into structure */
     fscanf(fp, "%d %d %d %d %f %d", &gameStats.games, &gameStats.wins, &gameStats.losses, 
     &gameStats.draw, &gameStats.winRate, &gameStats.rating);
     fclose(fp);/* close file */
     
}/* end load */
//----------------------------------------------------------------------------//
int saveStats()
{
     FILE *fp; /* create file pointer */
     
     fp = fopen("data\\stats.st", "w"); /* open file for writing */
     
     /* test if file opened successfully */
     if(fp == NULL)
     {
           printf("Error saving Stats.\n");
           getch();
           return 0;
     }
     
     /* save data in structure to file */
     fprintf(fp, "%d %d %d %d %.0f %d", gameStats.games, gameStats.wins, gameStats.losses, 
     gameStats.draw, gameStats.winRate, gameStats.rating);
     
     fclose(fp);/* close file */
}/* end saveStats */
//----------------------------------------------------------------------------//
void resetStats()
{
   FILE *fp; /* create file pointer */
          
   fp = fopen("data\\stats.st", "w"); /* open file for reading */
   
   fprintf(fp, "0 0 0 0 0 1000");/*Set all values to 0*/
     
   fclose(fp);/* close file */
}/* end resetStats */

//----------------------------------------------------------------------------//

int getCpuStats()
{
   char data[SIZE];
   int i=0;
   
   FILE *fp; /* create file pointer */
   
   fp = fopen("data\\cpu.st", "r"); /* open file for reading */
   
   if(fp == NULL)
   {
        printf("Error Loading Cpu Stats. Re-creating Stats data.\n");
        printf("Please Restart the game.\n"); 
        printf("Press Any Key To Exit.\n");
        getch();
        resetCpuStats();
        exit(-1);
        return 0;
   }
    
   while( fscanf(fp, "%d %d %d %d %f %d", &players[i].games, &players[i].wins, &players[i].losses, 
        &players[i].draw, &players[i].winRate, &players[i].rating) !=EOF )
  {
        i++;
  }     
    
   fclose(fp);/* close file */
}
//----------------------------------------------------------------------------//  
int saveCpuStats()
{
   players[opp1].games++; /* increment amout of games played */   
   players[opp1].winRate = (players[opp1].wins / (float)players[opp1].games) * 100; /* calculate win rate */
    
   players[opp2].games++; /* increment amout of games played */   
   players[opp2].winRate = (players[opp2].wins / (float)players[opp2].games) * 100; /* calculate win rate */  
  
    
   int i;
   FILE *fp; /* create file pointer */
   
   fp = fopen("data\\cpu.st", "w"); /* open file for writing */
   
   if(fp == NULL)
     {
           printf("Error saving Stats.\n");
           getch();
           return 0;
     }
   
   for (i = 0; i < 7 ; i++)
   {
      fprintf(fp, "%d %d %d %d %.0f %d\n", players[i].games, players[i].wins, players[i].losses, 
      players[i].draw, players[i].winRate, players[i].rating);
   }   
   fclose(fp);/* close file */
}  
//----------------------------------------------------------------------------// 
int resetCpuStats()
{
  
  int i;
   FILE *fp; /* create file pointer */
   
   fp = fopen("data\\cpu.st", "w"); /* open file for writing */
   
   if(fp == NULL)
     {
           printf("Error saving Stats.\n");
           getch();
           return 0;
     }
   
   for (i = 0; i < 7 ; i++)
   {
      fprintf(fp, "0 0 0 0 0 1000\n");
   }
   
     fclose(fp);
 }    
//----------------------------------------------------------------------------//   
void showRating(STATS *ptr)
{
 
  if (ptr->rating >= 1000 && ptr->rating <= 1050)
    txtcolor("CYAN");
  else if (ptr->rating > 1050 && ptr->rating <= 1100)
    txtcolor("LIGHTGREEN");
  else if (ptr->rating >1100 && ptr->rating <= 1200)
    txtcolor("LIGHTCYAN");
  else if (ptr->rating >1200)
    txtcolor("LIGHTMAGNETA");
  else if (ptr->rating >= 900 && ptr->rating < 1000)
    txtcolor("YELLOW");
  else if (ptr->rating < 900)
    txtcolor("LIGHTRED");
    
    printf("%d", ptr->rating);
    
    txtcolor("WHITE");
}  
  
//----------------------------------------------------------------------------//  

void playerStatsDisplay(int id)
{
    
   /* now display stats */ 
   txtcolor("LIGHTRED");
   printf("Player: %s\n", players[id].name);
   txtcolor("YELLOW");
   printf("---------------------------------------------------\n");
   printf("  Games\t Wins\tLosses\tDraws\tWin Rate   Rating\n");
   printf("---------------------------------------------------\n");
   txtcolor("LIGHTGREEN");
   printf("    %d\t  %d\t  %d\t  %d\t  %.0f%%\t   ", 
   players[id].games, players[id].wins, players[id].losses, players[id].draw, players[id].winRate);
   showRating(&players[id]);
   txtcolor("YELLOW");
   printf("\n\n---------------------------------------------------\n\n");
   txtcolor("WHITE");
}/* endGameStatsDisplay */
//----------------------------------------------------------------------------// 
void rankings()
{
   int i;
   txtcolor("YELLOW");
   printf("-----------------------------------------------------------\n");
   printf(" Games\t Wins\tLosses\tDraws\tWin Rate  Rating  Player\n");
   printf("-----------------------------------------------------------\n");
   for(i = 0; i < 7 ; i++)
   {
      txtcolor("LIGHTRED");
      txtcolor("YELLOW");
      
      if (i==0)
      {
         txtcolor("LIGHTGREEN");
         printf(" %d\t  %d\t  %d\t  %d\t  %.0f%%  \t",
         gameStats.games, gameStats.wins, gameStats.losses, gameStats.draw, gameStats.winRate);
         printf("   ");showRating(&gameStats);
         printf("\t  You");  
         printf("\n");
      }
         
      txtcolor("LIGHTGREEN");
      printf(" %d\t  %d\t  %d\t  %d\t  %.0f%%\t   ", 
      players[i].games, players[i].wins, players[i].losses, players[i].draw, players[i].winRate);
      showRating(&players[i]);
      printf("\t  %s", players[i].name);
      printf("\n"); 
      txtcolor("YELLOW");
   }
      printf("\n\n-----------------------------------------------------------\n\n");
      txtcolor("WHITE");
      printf("Press any key to return to Main Menu.\n");
      getch();
      system("cls");
      menu();
}

//----------------------------------------------------------------------------//  

void GameStatsDisplay(int save)
{
   
   if(save == 1)
    /* write stats to file */
   saveStats();
   
   /* now display stats */ 
   loadStats(); 
   
   printf("\nDOMINOES STATISTICS\n");
   txtcolor("YELLOW");
    printf("---------------------------------------------------\n");
   printf("  Games\t Wins\tLosses\tDraws\tWin Rate   Rating\n");
   printf("---------------------------------------------------\n");;
   txtcolor("LIGHTGREEN");
   printf("    %d\t  %d\t  %d\t  %d\t  %.0f%%\t   ", 
   gameStats.games, gameStats.wins, gameStats.losses, gameStats.draw, gameStats.winRate);
   showRating(&gameStats);
   txtcolor("YELLOW");
   printf("\n\n---------------------------------------------------\n\n");
   txtcolor("WHITE");
   printf("\nPress any key to continue.\n");
   getch();
}/* endGameStatsDisplay */
//----------------------------------------------------------------------------//
void calculateGamesWinRate()
{
    /* THIS IS PROBABLY THE SMALLEST FUNCTION I'VE EVER WRITTEN!!! LOL */
    gameStats.games++; /* increment amout of games played */   
    gameStats.winRate = (gameStats.wins / (float)gameStats.games) * 100; /* calculate win rate */
 
}/* end calculateGamesWinRate */
//----------------------------------------------------------------------------//
void putBackHand(HAND *userHand, HAND *cpuHand, HAND *cpu2Hand)
{
     int i;
     
     for(i = 0; i < HANDSIZE; i++)
     {     
         if(userHand->played == 0)
         {
           putBackLeft(&leftGen, userHand->left);
           putBackRight(&rightGen, userHand->right);
         }
         
         if(cpuHand->played == 0)
         {
           putBackLeft(&leftGen, cpuHand->left);
           putBackRight(&rightGen, cpuHand->right);
         }
         
         if(cpu2Hand->played == 0)
         {
           putBackLeft(&leftGen, cpu2Hand->left);
           putBackRight(&rightGen, cpu2Hand->right);
         }
         
         userHand++; //go to next bone in user's hand
         cpuHand++; //go to next bone in cpu's hand
         cpu2Hand++; //go to next bone in cpu2's hand
     }/* end for */
} /* end putBackHand */ 

//----------------------------------------------------------------------------//
int menu()
{
   system("cls");
   char choice[1];
   int menuChoice, ok;
   
    
   
   
   do
   {
      system("cls");
      txtcolor("YELLOW");
       printf("\n\n\n\n\n\n\t\t\t    DOMINOES");
       txtcolor("LIGHTGREEN");
       printf(" GT");
       txtcolor("YELLOW");
       printf(" STYLE\n");
       txtcolor("WHITE");
       printf("\t\t\t         MAIN MENU\n");
       txtcolor("LIGHTRED");
       printf("\t\t\t *************************\n");
       printf("\t\t\t **  ");
       txtcolor("WHITE");
       printf("1 - Play Game");
       txtcolor("LIGHTRED");
       printf("      **\n");
       printf("\t\t\t **  ");
       txtcolor("WHITE");
       printf("2 - View Help");
       txtcolor("LIGHTRED");
       printf("      **\n");
       printf("\t\t\t **  ");
       txtcolor("WHITE");
       printf("3 - View Rankings");
       txtcolor("LIGHTRED");
       printf("  **\n");
       printf("\t\t\t **  ");
       txtcolor("WHITE");
       printf("X - To QUIT");
       txtcolor("LIGHTRED");
       printf("        **\n");
       printf("\t\t\t *************************\n");
     
         choice[0] = getch();
         system("cls");
      
      if (choice[0]=='x' || choice[0]=='X')
      {
         printf("Press Any Key to Quit.");
         getch();
         exit(-1);
      }
         
      else
      {
         ok++;
            
      }
        
     /*Ensures that only a number is entered for a domino choice*/
      if(!(isdigit(choice[0])))
      {
         
         if(ok==0)
         {
            txtcolor("LIGHTRED");
            printf("\a"); 
            printf ("\nPlease Enter a Number.\n");
            txtcolor("WHITE");
         }
            
         fflush(stdin);
         
      }
      
      
      
      menuChoice=atoi(choice);
      if (menuChoice >4 || menuChoice <0)
      {
         txtcolor("LIGHTRED");
         printf("\a"); 
         printf ("\nIncorrect Choice.\n");
         fflush(stdin);
         txtcolor("WHITE");
         
      }
      
                  
      else
      {
         if (menuChoice == 1)
         {
            system("cls");
            break;
         }
         else if (menuChoice == 2)
         {
            viewHelp();
            break;
         }
         else if (menuChoice == 3)
         {
            rankings();
            break;
         }
      }
       
      
   }while(choice[0] != 'x' || choice[0] != 'X');
}

//----------------------------------------------------------------------------//

int viewHelp()
{  
   system("data\\help.html");
   system("cls");
   menu();
   return 0;
}
