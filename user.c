#include <stdio.h>
#include "bones.h"
#include "constants.h"
#include "prototypes.h"


/****************************USER'S TURN*********************************/
int userPlay()
{
      int dominoChoice, direction;
      system("cls");
      displayTable(&startLeft, &startRight);
      printf("\n\n");
      
           
      printNewHand(&User[0]);/*Displays user's hand*/
      
      dominoChoice=userChoice();/*Get user's choice of dominoes*/
      
      
      /*Loops until a valid domino is picked or user RAPS*/
      while(1)
      {
         
         if (dominoChoice==7)
         {
            txtcolor("LIGHTRED");    
            printf("\nYou have Rapped!!!\n\n");
            txtcolor("WHITE"); 
            system("pause");
            system("cls");
            return -1;
         }
         
         else if (isPlayed(&User[dominoChoice]))/*Checks if domino has been played*/
         {
            txtcolor("LIGHTRED");
            printf("\nYou Have already played that Domino.\n");
            txtcolor("WHITE");
            
            dominoChoice=userChoice();
            
         }
         
         else if (!(isValid(&User[dominoChoice])))/*Checks if domino can be played*/
         {
            txtcolor("LIGHTRED");
            printf ("The chosen Domino does not match.\n");
            txtcolor("WHITE");
            dominoChoice=userChoice(); /*Get user input*/
         }
         
         else
            break;

      }
      
      if (dominoChoice!=7)
      {
         printf("\nYou have chosen:");
            
         showBone(&User[dominoChoice]); /*Displays selected domino*/
      }
               
      while (1)
      {
         
         if (dominoChoice!=7)
         {
            /*Checks is chosen direction is OK and flips the chosen domino if necessary*/
            direction = directionChoice();
            
            while(1)
            {
               if (direction==1 || direction==2 )/*Checks if direction is valid*/
                  break;
               
               else
               {
                  txtcolor("LIGHTRED"); 
                  printf ("Invalid Choice.");
                  txtcolor("WHITE");
                  direction = directionChoice(); /*Get user input for direction*/
               }
            }
         }
         
         else 
            break;
                  
         if(directionTest(&User[dominoChoice],direction))
            break;
         else
         {
            txtcolor("LIGHTRED"); 
            printf("You Cannot Play that domino there.\n");
            txtcolor("WHITE");
         }   
            
      }
                      
      if (dominoChoice!=7)
      {
         placeBone(&startLeft, &startRight, &User[dominoChoice], direction ); /*Plays a domino*/
         setPlayed(&User[dominoChoice]);/*Sets play value of a domino to 1*/

         system("cls");
         
         printf("You have played:");
         showBone(&User[dominoChoice]); /*Displays selected domino*/
         printf("\n");
         displayTable(&startLeft, &startRight);
         printf("\n\n");
         system("pause");
         system("cls");
         
         
         return dominoChoice;
      }
}
