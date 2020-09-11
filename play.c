#include <stdio.h>
#include <stdlib.h>
#include "bones.h"
#include "prototypes.h"
#include "constants.h"
//#include "textcolor.h"


int i;

/*Checks if a domino can be played at a certain side of the train*/
int directionTest(HAND *ptr, int direction)
{
   if (ptr->right==LR_VALUE[1] && direction==2)//tests if left of selected is equal to left table value 
   {
      flipBone(ptr);/*Flips domino*/
      return 1;
   }
   
   else if (ptr->left==LR_VALUE[0] && direction==1 )//tests if right of selected is equal to right table value 
   {
      flipBone(ptr);/*Flips domino*/
      return 1;
   }
   
   else if (ptr->right==LR_VALUE[0] && direction==1)//tests if left of selected is equal to left table value 
   {
      return 1;
   }
   
   else if (ptr->left==LR_VALUE[1] && direction==2 )//tests if right of selected is equal to right table value 
   {
      return 1;
   }
   
   else 
      return 0;
}
//----------------------------------------------------------------------------//

/*Checks if a domino can be played*/
int isValid(HAND *ptr)
{
   
   if (ptr->right==LR_VALUE[0])//tests if right of selected is equal to left table value 
   {
      return 1;
   }
   
   else if (ptr->left==LR_VALUE[1])//tests if left of selected is equal to right table value 
   {
      return 1;
   }
   
   else if (ptr->right==LR_VALUE[1])//tests if left of selected is equal to left table value 
   {
      return 1;
   }
   
   else if (ptr->left==LR_VALUE[0])//tests if right of selected is equal to right table value 
   {
      return 1;
   }
   else 
      return 0;
      
}

//----------------------------------------------------------------------------//
void flipBone(HAND *ptr)
{
   int temp;
   temp=ptr->left;
   ptr->left=ptr->right;
   ptr->right=temp;   
}
//----------------------------------------------------------------------------//
/*Gets domino choice*/
int userChoice()
{
   txtcolor("WHITE");
   int dominoChoice=0, ok=0;
   char choice[1];/*To check input*/

   while (1)
      {
         txtcolor("WHITE");
         fflush(stdin);/*Clears Input buffer*/
         printf ("\nEnter the number corresponding to the domino you would like to play, OR press R to RAP!:");
        
         scanf ("%s", choice);
         
           if (choice[0]=='r' || choice[0]=='R')
            {
               
               if(!(checkHand(&User[0])))
               {
                  fflush(stdin);
                  return 7;
                  break;
               }
               
               else
               {
                  txtcolor("LIGHTRED");
                  printf("\a"); 
                  printf("\nYou Cannot Rap, You Have a Playable Domino.\n");
                  txtcolor("WHITE");
                  ok++;
                  
               }
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
               continue;
            }
            
            
            
            dominoChoice=atoi(choice);
            if (dominoChoice >6 || dominoChoice <0)
            {
               txtcolor("LIGHTRED");
               printf("\a"); 
               printf ("\nIncorrect Choice.\n");
               fflush(stdin);
               txtcolor("WHITE");
               continue;
            }
            
                        
            else
            {
               return dominoChoice;
               break;
            } 
      
      }
}
//----------------------------------------------------------------------------//
/*Gets direction choice*/
int directionChoice()
{
   int dChoice=0;
   char choice[1];/*To check input*/

   while (1)
      {
         txtcolor("WHITE");
         fflush(stdin);/*Clears Input buffer*/
         printf ("\n1:\tPlace Domino Left\n2:\tPlace Domino Right:");
         scanf ("%s", choice);
         
            /*Ensures that only a number is entered for a domino choice*/
            if(!(isdigit(choice[0])))
            {
               txtcolor("LIGHTRED");
               printf("\a"); 
               printf ("\nPlease Enter a Number.\n");
               fflush(stdin);
               txtcolor("WHITE");
               continue;
            }

            
            dChoice=atoi(choice);
            if (dChoice >2 || dChoice <0)
            {
               txtcolor("LIGHTRED");
               printf("\a"); 
               printf ("\nIncorrect Choice.\n");
               fflush(stdin);
               txtcolor("WHITE");
               continue;
            }
            
                        
            else
            {
               return dChoice;
               break;
            } 
      
      }
}
//----------------------------------------------------------------------------//
void printNewHand(HAND *ptr)
{
   printf("\nYour hand has:\n\n");
   for (i=0; i<HANDSIZE; i++)
   {
      if (ptr->played==0)
      {
         
         printf("%d:",ptr->number);
         
         if(ptr->rest)
            txtcolor("YELLOW");
         else
            txtcolor("LIGHTGRAY");
         
         if (start > 0)
            if (ptr->left==LR_VALUE[0] || ptr->right == LR_VALUE[0] || ptr->left==LR_VALUE[1] || ptr->right == LR_VALUE[1])  
               txtcolor("LIGHTGREEN");
         
         printf("[%d|%d]\t", ptr->left, ptr->right);
                  
      }
      
      txtcolor("WHITE");

      ptr=ptr->nextBone;
   }
   
   printf("\n");
}
//----------------------------------------------------------------------------//
void showHand(HAND *ptr)
{
  
   for (i=0; i<HANDSIZE; i++)
   {
      if (ptr->played==0)
      {
          if(ptr->rest)
            txtcolor("YELLOW");
         else
            txtcolor("LIGHTGREEN");
         printf("[%d|%d]\t",ptr->left, ptr->right);
                  
      }

      ptr=ptr->nextBone;
   }
   txtcolor("WHITE");
   printf("\n");
}
//----------------------------------------------------------------------------//
void setPlayed(HAND *ptr)
{
   ptr->played=1;/*Sets the play value of a domino to 1*/
}
//----------------------------------------------------------------------------//
int isPlayed(HAND *ptr)
{
   return ptr->played;/*Returns play value of a domino 1= yes, 0 = no*/
}
//----------------------------------------------------------------------------//
int returnIndex(HANDSTATS *ptr)
{
   return ptr->lgstRestIndex; /*Returns the index number of the highest Rest or double*/
}
//----------------------------------------------------------------------------//
int gameOver(int domsPlayed_u, int domsPlayed_c, int domsPlayed_c2)
{
   if (domsPlayed_u==7)
      return 1;
   else if (domsPlayed_c==7)
      return 2;
   else if (domsPlayed_c2==7)
      return 3;
   else
      return 0;
}
//----------------------------------------------------------------------------//
void placeBone(ONTABLE *startLeft, ONTABLE *startRight, HAND *insert, int direction)
{
           
     start++;
     /* pointers to new sides of bones */
     ONTABLE *insertLeft, *insertRight, *temp; 
          
     /* create left and right sides of current bone */
     insertLeft = malloc(sizeof(ONTABLE));
     insertRight = malloc(sizeof(ONTABLE));
     
     insertLeft->leftVal = insert->left; /* place left value in left side of bone */
     insertRight->rightVal = insert->right; /* place right value in right side of bone */
     
     /* nodes point to null values */
     insertLeft->next = NULL;
     insertRight->next = NULL;
     
     /* test which side bone is to be inserted */
     if(direction == 2)
     {    
                  /* insert to right side of start bone */
                  
                  while(startLeft->next)
                        startLeft = startLeft->next; /* go to last left side bone */
                  
                  startLeft->next = insertLeft; //insert left side of bone

         
                  while(startRight->next)
                        startRight = startRight->next; /* go to last right side bone */
                     
                  startRight->next = insertRight;//insert right side of bone
     }/* end if */
     
/*--------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------*/

     if(direction == 1)
     {
                 /*-----FIRST INSERT LEFT-SIDE BONE-----*/ 
                
                 temp = startLeft; /* temporarily hold address of start position of left bone */
                 /* move from beginning of left bone to previous left bone value */
                 startLeft = startLeft->next;
                 
                 insertLeft->next = startLeft; /* insert left bone to previous left bone */
                 
                 startLeft = temp; /* go back to start of left bone list */
                 /* point start of left bone list to bone inserted */
                 startLeft->next = insertLeft; 
                 
                 /*-----NOW INSERT RIGHT-SIDE BONE-----*/
                 
                 temp = startRight; /* temporarily hold address of start position of right bone */
                 /* move from beginning of right bone to previous right bone value */
                 startRight = startRight->next;
                 
                 insertRight->next = startRight; /* insert right bone to previous right bone */
                 
                 startRight = temp; /* go back to start of right bone list */
                 /* point start of left bone list to bone inserted */
                 startRight->next = insertRight;                
     }/* end if */    
     
     /* ---RETURN LEFTMOST AND RIGHT MOST VALUES OF BONES ON TABLE--- */
     
     /* first get leftmost vaue */
     startLeft = startLeft->next;
     
     /* now itereate to rightmost value */
     while(startRight->next)
           startRight = startRight->next;
     
     /*store left and rightmost values */
     if (start==1 && direction==2)
     {
            
        LR_VALUE[0] = startLeft->leftVal;
        
        LR_VALUE[1] = startRight->rightVal;
     }
      
     else if (start>1 && direction==2)
        LR_VALUE[1] = startRight->rightVal;
         
     else if (start>1 && direction==1)
        LR_VALUE[0] = startLeft->leftVal;
      
            
        
     
}/* end placeBone */   

//----------------------------------------------------------------------------//
void displayTable(ONTABLE *left, ONTABLE *right)
{
   printf("\nThe Table has the following Dominoes:-\n\n");
     /* display all bones on table starting from left most bone */
     while(left->next)
     {
           left = left->next; 
           printf(" [%d|", left->leftVal);
           right = right->next; 
           printf("%d] ", right->rightVal);          
     }/* end while */
   
}/* end displayTable */

//----------------------------------------------------------------------------//
int calculatePoints(HAND *user, HAND *computer, HAND *computer2)
{
    txtcolor("WHITE");  
    
    HAND *user_default = user , *computer_default = computer, *computer2_default = computer2;
    
    int i, cpuPoints,cpu2Points, userPoints; 
    cpuPoints = userPoints = cpu2Points= 0;
    
 /* now compute points for first cpu*/
    for(i = 0; i < HANDSIZE; i++)
    {
       if(computer->played == 0)
           cpuPoints = cpuPoints + computer->points;      
    
       computer++; //move to next bone in computer's hand
    }
 
 /* now compute points for user*/
    for(i = 0; i < HANDSIZE; i++)
    {
       if(user->played == 0)
       userPoints = userPoints + user->points;
       
       user++; //move to next bone in user's hand
    }
 /* now compute points for second cpu*/ 
    for(i = 0; i < HANDSIZE; i++)
    {
       if(computer2->played == 0)
           cpu2Points = cpu2Points + computer2->points;      
    
       computer2++; //move to next bone in computer's hand
    }
    
  int diff;
 
 if(cpuPoints < userPoints && cpuPoints < cpu2Points)
 {
    if (userPoints < cpu2Points)  
      diff=userPoints-cpuPoints;
    else
      diff=cpu2Points-cpuPoints ; 
 }

 else if(cpu2Points < userPoints && cpu2Points < cpuPoints)
 {
    if (userPoints < cpuPoints)  
      diff=userPoints-cpu2Points;
    else
      diff=cpuPoints-cpu2Points; 
 }
 
 else if(userPoints < cpu2Points && userPoints < cpuPoints)
 {
    if (cpu2Points < cpuPoints)  
      diff=cpu2Points-userPoints;
    else
      diff=cpuPoints-userPoints; 
 }
 
 system("cls");
 printf("AWWW! Everyone has Rapped, there are no more playable dominoes!\n");
 printf("\nYour hand has:");
 showHand(user_default);
 printf("Your Points: %d\n\n", userPoints);
 printf("%s's hand has:", players[opp1].name);
 showHand(computer_default);
 printf("%s's Points: %d\n\n", players[opp1].name, cpuPoints);
 printf("%s's hand has:",  players[opp2].name);
 showHand(computer2_default);
 printf("%s's Points: %d\n\n", players[opp2].name, cpu2Points);
 
 if(cpuPoints < userPoints && cpuPoints < cpu2Points)
 {
    printf("\n%s has won by %d Point(s).", players[opp1].name, diff);
    gameStats.losses++;
    gameStats.rating-=8;
    players[opp1].wins++;
    players[opp2].losses++;
    players[opp1].rating+=8;
    players[opp2].rating-=8;
 }

 else if(cpu2Points < userPoints && cpu2Points < cpuPoints)
 {
   printf("\n%s has won by %d Point(s).", players[opp2].name, diff);
   gameStats.losses++;
   gameStats.rating-=8;
   players[opp2].wins++;
   players[opp1].losses++;
   players[opp1].rating-=8;
   players[opp2].rating+=10;
 }
 
 else if(userPoints < cpu2Points && userPoints < cpuPoints)
 {
    printf("\nYou have won by %d Point(s).", diff);
    gameStats.wins++;
    gameStats.rating+=10;
    players[opp2].losses++;
    players[opp1].losses++;
    players[opp1].rating-=8;
    players[opp2].rating-=8;
 }

 else 
 {
    printf("The Game is tied.\n");
    gameStats.draw++;
    players[opp2].draw++;
    players[opp1].draw++;
 }
    /* call function to calculate games played and win rate */
    calculateGamesWinRate();
    /* call function which calls other functions to write stats to file then display stats */
    saveCpuStats();
    GameStatsDisplay(1);
 
}/* end calculatePoints */
//----------------------------------------------------------------------------//

int checkHand(HAND *ptr)
{
   for(i = 0; i < HANDSIZE; i++)
     {
         if(ptr->played == 0) // test if bone has already been played
            if(ptr->left == LR_VALUE[0] || ptr->right == LR_VALUE[0] || ptr->left == LR_VALUE[1] || ptr->right == LR_VALUE[1])
               return 1;
         ptr++; /* move to next bone */
     }
     
   return 0;
}     
//----------------------------------------------------------------------------//
int endGame(int dominoesPlayed_u, int dominoesPlayed_c, int dominoesPlayed_c2)
{
   int winner=gameOver(dominoesPlayed_u, dominoesPlayed_c, dominoesPlayed_c2);/*Checks if someone has won the game*/
      
      if(winner==1)
      {
         system("cls");
         printf("You have played:");
         showBone(&User[user_choice]);
         
         displayTable(&startLeft, &startRight);
         
         printf("\n\nDOMINO!!!\nYou Have won the game.\n");
         gameStats.wins++;
         gameStats.rating+=10;
         players[opp1].losses++;
         players[opp2].losses++;
         players[opp1].rating-=8;
         players[opp2].rating-=8;
         
         /* call function to calculate games played and win rate */
         calculateGamesWinRate();
         /* call function which calls other functions to write stats to file then display stats */
         GameStatsDisplay(1);
         saveCpuStats();
         return 1;
      }
      
      else if (winner==2)
      {
         
         system("cls");
         printf("%s has played:",  players[opp1].name);
         showBone(&Cpu[cpu_choice]);
         
         displayTable(&startLeft, &startRight);
         
         printf("\n\nDOMINO!!!\n%s Has won the game.\n",  players[opp1].name);
         gameStats.losses++;
         gameStats.rating-=8;
         players[opp1].wins++;
         players[opp2].losses++;
         players[opp1].rating+=10;
         players[opp2].rating-=8;
         
         /* call function to calculate games played and win rate */
         calculateGamesWinRate();
         /* call function which calls other functions to write stats to file then display stats */
         GameStatsDisplay(1);
         saveCpuStats();
         return 1;
      }
      
      else if (winner==3)
      {
         
         system("cls");
         printf("%s has played:",  players[opp2].name);
         showBone(&Cpu2[cpu2_choice]);
        
         displayTable(&startLeft, &startRight);
         
         printf("\n\nDOMINO!!!\n%s Has won the game.\n",  players[opp2].name);
         gameStats.losses++;
         gameStats.rating-=8;
         players[opp2].wins++;
         players[opp1].losses++;
         players[opp2].rating+=10;
         players[opp1].rating-=8;
         
         /* call function to calculate games played and win rate */
         calculateGamesWinRate();
         /* call function which calls other functions to write stats to file then display stats */
         GameStatsDisplay(1);
         saveCpuStats();
         return 1;
      }
      
      else 
         return 0;
}
