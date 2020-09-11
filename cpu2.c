/* Created a separate file anticipating this file growing in complexity */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bones.h"
#include "prototypes.h"
#include "constants.h"

int cpu2Play()
{
              int indexReturned = 0;
              
              int random;
              srand(time(NULL));
              
              random = rand () % 2;
              
              if(random)
              {
                 indexReturned = cpu2AI(&Cpu2[0]); /* computer plays matching domino */
              }
              else
              {
                 indexReturned = cpu2AI_PlayLargest(&Cpu2[0]);/*Computer plays largest matching domino*/
              }
              
              if(indexReturned == -1)
              return indexReturned;
              
               
               /* depending on the value of the left and right side of the bone returned we either just append or flip then append */
              system("cls");
              printf("%s has played:",  players[opp2].name);
              showBone(&Cpu2[indexReturned]); /*Displays selected domino*/
              printf("\n");
              /* if left value of bone matches with right most value we simply append to the right side */
              if(Cpu2[indexReturned].left == LR_VALUE[1])
                 placeBone(&startLeft, &startRight, &Cpu2[indexReturned], 2);
    
              /* if right value of bone matches with left most value we simply append to the left side */
              else if(Cpu2[indexReturned].right == LR_VALUE[0])
                   placeBone(&startLeft, &startRight, &Cpu2[indexReturned], 1);
              
              else if(Cpu2[indexReturned].left == LR_VALUE[0])
              {
                   /* if left value of bone matches with left most value we flip then append to the left side */
                   flipBone(&Cpu2[indexReturned]);
                   placeBone(&startLeft, &startRight, &Cpu2[indexReturned], 1);
              }
              
              else
              {
                  /* if right value of bone matches with right most value we flip then append to the right side */
                  flipBone(&Cpu2[indexReturned]);
                  placeBone(&startLeft, &startRight, &Cpu2[indexReturned], 2);
              }
              
              printf("\n");
              displayTable(&startLeft, &startRight);
              printf("\n\n");
              system("PAUSE");
              return indexReturned;
}

int cpu2AI(HAND *computerHand)
{
     /* 
       the inner if tests for the left or right domino matching the left most
       or right most bone value currently on the table      
     */
     int i;
     
     /* traverse hand to find match */
     for(i = 0; i < HANDSIZE; i++)
     {
         if(computerHand->played == 0) // test if bone has already been played
            if(computerHand->left == LR_VALUE[0] || computerHand->right == LR_VALUE[0] || computerHand->left == LR_VALUE[1] || computerHand->right == LR_VALUE[1])
                  {
                    computerHand->played = 1; /* mark bone as being played */
                    return computerHand->number; /* return index position of bone */
                  }
     computerHand++; /* move to next bone */
     }
         
         /* if no match was found in the above iteration of the hand return -1 to indicate this */
         return -1; /* to test of cpu raps */
}/* end cpuAI */

//----------------------------------------------------------------------------//
int cpu2AI_PlayLargest(HAND *computerHand)
{
   int largest=0, largestIndex,i, match=0;
   
   /* traverse hand to find match */
     for(i = 0; i < HANDSIZE; i++)
     {
         if(computerHand->played == 0) // test if bone has already been played
            if(computerHand->left == LR_VALUE[0] || computerHand->right == LR_VALUE[0] || computerHand->left == LR_VALUE[1] || computerHand->right == LR_VALUE[1])
            {
               if(computerHand->points >= largest)
               {
                  largestIndex = computerHand->number;
                  largest = computerHand->points;
               }
                  
                  match++;
            }
            
         computerHand=computerHand->nextBone; /* move to next bone */   
      }
      
      if (match>0)
      {
         setPlayed(&Cpu2[largestIndex]);
         return largestIndex; /* return index position of bone */
      }
      
      else
         return -1;
}
