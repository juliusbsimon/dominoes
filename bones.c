#include <stdlib.h>
#include "bones.h"
#include "prototypes.h"
#include "constants.h"


int getLargestRest(HAND *ptr1, HANDSTATS *ptr2)
{
   while(1)
   {
      if(ptr1->rest==1)
      {
         /*Determines the largest double in the player's hand*/
         if((ptr1->right) > (ptr2->largestRest))
         {
             ptr2->largestRest=ptr1->right;/*Stores the largest double*/
             ptr2->lgstRestIndex=ptr1->number;/*Stores the location of the largest double*/
         }
         
      }
      ptr1=ptr1->nextBone;/*Move pointer to next bone*/
      if(ptr1==NULL)/*break if the end of the list is reached*/
      break;
   }

   return ptr2->largestRest;
}

void showBone(HAND *ptr)
{
   if(ptr->rest)
   txtcolor("YELLOW");
   
   printf("[%d|%d]", ptr->left, ptr->right);
   
   txtcolor("WHITE");
   
}
