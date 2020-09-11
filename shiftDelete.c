/* ---GEE I HOPE ALL THIS WORKS!--- */

/*----------------------*/
/* THIS IS BLASPHEMY!!  */
/* THIS IS MADNESS!!    */
/* MADNESS!??           */
/* THIS IS CSI!!!       */
/*----------------------*/
#include <stdio.h>
#include <time.h>
#include "bones.h"
#include "prototypes.h"
#include "constants.h"



void createBones(DOMINO *leftGen, DOMINO *rightGen, DOMINO *bone)/* just pass Bones without an index value */
{
     DOMINO *getLeft, *getRight;
     
     int i, j, loop, domNumber;
 
       for(i = 0; i <= MAXVALUE; i++)
       {
            /* first generate and temporarily store values */
             for(j = i; j <=MAXVALUE; j++)
             {
                      getLeft = malloc(sizeof(DOMINO)); /* create left bone */
                      getRight = malloc(sizeof(DOMINO)); /* create right bone */
 
                   getLeft->left = i; /* assign value to left bone */
                   getRight->right = j; /* assign value to right bone */
                   
                   /* point left and right side of current bone to null */
                   getLeft->next = NULL; 
                   getRight->next = NULL;
                   
                   bone++; /* go to next bone */
             
             /* ----NOW APPEND LEFT VALUE ONTO LIST----- */
       
                    /* go to end of left side */
                   while(leftGen->next)
                         leftGen = leftGen->next;
             
                   /* now insert to left side */
                   leftGen->next = getLeft;
              
                   
             /* ----NOW APPEND RIGHT VALUE ONTO LIST----- */
                
                /* go to end of right side */
                while(rightGen->next)
                      rightGen = rightGen->next;
                      
                      rightGen->next = getRight;
             }
}
       
}/* end generateBones */

//----------------------------------------------------------------------------//
void printGenerated(DOMINO *left, DOMINO *right)
{
     while(left->next)
     {
           left = left->next; 
           printf(" [%d|", *left);
           
           right = right->next; 
           printf("%d] ", right->right);          
     }/* end while */
                      
}/* end printGenerated */

//----------------------------------------------------------------------------//
void randomSelect(DOMINO *bones, HAND *user, HAND *computer, HAND *computer2, HANDSTATS *cpuStats, HANDSTATS *userStats, HANDSTATS *cpu2Stats)
{
     srand(time(NULL));

     int i, randReturn = 0, select = MAXBONES;
     user->number = 0;
     computer->number = 0;
     computer2->number = 0;

     /* first select for User */
     for(i = 0; i < HANDSIZE; i++)
     {
           randReturn = 1 + rand()%(select - i); /* generate random number */
           user->left = returnLeft(&leftGen, randReturn); /* select left bone */
           user->right = returnRight(&rightGen, randReturn);/* select bone with same index position as left bone */
           user->points = user->left + user->right; /* calculate points */
           
           /* test for rest/double bone */
           if(user->left == user->right)
           {
               user->rest = 1;
               userStats->restCount++;
           }
           
           user->number = i; /* keep track of index position in user's hand of selected bones */
           user->played = 0; /* bones have not been played yet. set this value to zero */
           user++; /* go to next position to get attributes for next bone */
          
           /*Links the dominoes to each other*/
           User[i].nextBone=&User[i+1];
           if(i==HANDSIZE-1)
            User[i].nextBone=NULL;
     }

     select = select - HANDSIZE; /* since one hand has already been selected reduce select by HANDSIZE (7) */
     
     /* then select for CPU */
     for(i = 0; i < HANDSIZE; i++)
     {
           randReturn = 1 + rand()%(select - i); /* generate random number */
           computer->left = returnLeft(&leftGen, randReturn); /* select left bone */
           computer->right = returnRight(&rightGen, randReturn); /* select bone with same index position as left bone */
           computer->points = computer->left + computer->right; /* calculate points */
           
           /* test for rest bone */
           if(computer->left == computer->right)
           {
               cpuStats->restCount++;
               computer->rest = 1;
           }
           
           computer->number = i; /* keep track of index position in user's hand of selected bones */
           computer->played = 0; /* bones have not been played yet. set this value to zero */
           computer++; /* go to next position to get attributes for next bone */
           
           /*Links the dominoes to each other*/
           Cpu[i].nextBone=&Cpu[i+1];
           if(i==HANDSIZE-1)
            Cpu[i].nextBone=NULL;
     }
     
     select = select - HANDSIZE;/* since 2 hands have already been selected reduce select by HANDSIZE (7) more */
     
     /* then select for CPU 2 */
     for(i = 0; i < HANDSIZE; i++)
     {
           randReturn = 1 + rand()%(select - i); /* generate random number */
           computer2->left = returnLeft(&leftGen, randReturn); /* select left bone */
           computer2->right = returnRight(&rightGen, randReturn); /* select bone with same index position as left bone */
           computer2->points = computer2->left + computer2->right; /* calculate points */
           
           /* test for rest bone */
           if(computer2->left == computer2->right)
           {
               cpu2Stats->restCount++;
               computer2->rest = 1;
           }
           
           computer2->number = i; /* keep track of index position in user's hand of selected bones */
           computer2->played = 0; /* bones have not been played yet. set this value to zero */
           computer2++; /* go to next position to get attributes for next bone */
           
           /*Links the dominoes to each other*/
           Cpu2[i].nextBone=&Cpu2[i+1];
           if(i==HANDSIZE-1)
            Cpu2[i].nextBone=NULL;
     }
      

      
}/* end randomSelect */

//----------------------------------------------------------------------------//
int returnLeft(DOMINO *left, int choosen)
{
    int loop = 0, store, i;
    
    DOMINO *temp, *start, *temp2, *obliterate;
    
    start = left; /* keep pointer to start of left list */

    /* go to randomly selected bone */
    while(loop != choosen)
    {
    left = left->next;
    loop++;
    }

    /* test if value to be removed is at end of list */
    if(left->next == NULL)
    {
                  /* hold it temporarily */
                  temp = left;
                  
                  store = left->left; /* store value at position so that it can be returned */
                  
                  /* go to start */
                  left = start;
                  
                  /* go to previous position */
                  for(i = 0; i < (loop-1); i++)
                      left = left->next;
                      
                  /* point to NULL */
                  left->next = NULL;
                  
                  /* delete left side bone */
                  free(temp);
                  
                  /* return value */
                  return store;
    }
    
    store = left->left; /* store value at position so that it can be returned */
    obliterate = left;
    
    if(choosen == 1)
    {
           /* go back to start */
          left = start;
           
          /* go to first value */
          left = left->next;
          store = left->left;
          /* temporarily hold first value */
          temp = left;
          
          /* now go back to start */
          left = start;
          
          /* go to second value */
          left = left->next;/* 1st postition is null postition */
          left = left->next;
                    
          /* hold second value */
          temp2 = left;
          
          /* lol now go back to start ONE LAST TIME :) */
          left = start;
          
          /* point start to second postion */
          left->next = temp2;
          
          /* delete first postion */
          free(temp);

          return store;   
    }
          
    /* if insertion is not to be done at start or end of list */
             
    left = start;
    
    /* go to previous postion of value to be removed in list */ 
    for(i = 0; i < (loop-1); i++)
    left = left->next;
    
    /* temporarily store that position */
    temp = left;
    
    /* now go to next position of value to be removed from list */
   
   left = left->next; left = left->next;

        /* now point previous postion to next position */
        temp->next = left;
        
        /* free list position */
        free(obliterate);
        
        /* return value */
        
        return store;
}/* end returnLeft */

//----------------------------------------------------------------------------//
int returnRight(DOMINO *right, int choosen)
{
    int loop = 0, store, i;
    
    DOMINO *temp, *start, *temp2, *obliterate;
    
    start = right; /* keep pointer to start of right list */

    /* go to randomly selected position */
    while(loop != choosen)
    {
    right = right->next;
    loop++;
    }
    
  
    if(right->next == NULL)
    {
                  /* hold it temporarily */
                  temp = right;
                  
                  store = right->right; /* store value at ramdomly selected position */
                  
                  /* go to start */
                  right = start;
                  
                  /* go to previous position */
                  for(i = 0; i < (loop-1); i++)
                      right = right->next;
                      
                  /* point to NULL */
                  right->next = NULL;
                  
                  /* delete left side bone */
                  free(temp);
                  
                  /* return value */
                  return store;
    }
    
    store = right->right;
    obliterate = right;

    if(choosen == 1)
    {
           /* go back to start */
          right = start;
           
          /* go to first value */
          right = right->next;
          store = right->right;
          
          /* temporarily hold first value */
          temp = right;
          
          /* now go back to start */
          right = start;
          
          /* go to second value */
          right = right->next;/* 1st postition is null postition */
          right = right->next;
          //right = right->next;
          
          /* hold second value */
          temp2 = right;
          
          /* lol now go back to start ONE LAST TIME */
          right = start;
          
          /* point start to second postion */
          right->next = temp2;
          
          /* delete first postion */
          free(temp);
     
          return store;
    }
    
     /* go to previous postion of value to be removed in list */      
    
    right = start;
    for(i = 0; i < (loop-1); i++)
    right = right->next;
    
    /* temporarily store that position */
    temp = right;

    /* now go to next position of value to be removed from list */
 
        right = right->next; right = right->next; 
    
        /* now point previous postion to next position */
        temp->next = right;
        
        /* free list position */
        free(obliterate);
        
        /* return value */
        
        return store;
}/* end returnRight */

void pickUpBonesLeft(ONTABLE *pickUpLeft, int tableLength)
{
     int i, k, end = 0;
     ONTABLE *temp, *startLeft, *startLeft0; //create variables to keep trak of start
     startLeft0 = pickUpLeft;
     
     pickUpLeft = pickUpLeft->next; /* move ahead one position away from root nodes */
     
     /* hold start position */
     startLeft = pickUpLeft;
        
     /* now we start the madness */
     for(k = 0; k < tableLength; k++) /* WATCH THE <= HERE */
     {
         /* go to end of left side of table */
         while(pickUpLeft->next != NULL)
         {
             pickUpLeft = pickUpLeft->next;
             end++; /* increment counter to keep track of last position */
         }
         
           /* now put back value onto pack */
           putBackLeft(&leftGen, pickUpLeft->leftVal); 

         /* temporarily hold position so it can be freed later */
         temp = pickUpLeft;
         
         /* go back to start */
         pickUpLeft = startLeft;
         
         /* now go to previous position of node to be deleted */
         for(i = 0; i < (end-1); i++)
         pickUpLeft = pickUpLeft->next;
         
         /* point value to null */
         pickUpLeft->next = NULL; 
         
         /* now free node */
         free(temp);
         /* go back to start */
         pickUpLeft = startLeft;
      
         end = 0; //reset counter
     } /* end outer for */
     pickUpLeft = startLeft0; /* go right back to root of list */
     pickUpLeft->next = NULL; /* point root to null */

}/* end pickUp BonesLeft */

void pickUpBonesRight(ONTABLE *pickUpRight, int tableLength)
{
     int i, k, end = 0;
     ONTABLE *temp, *startRight, *startRight0;
     startRight0 = pickUpRight;
     
     pickUpRight = pickUpRight->next;
     /* hold start positions */
     startRight = pickUpRight;
          
     /* now we start the madness */
     for(k = 0; k < tableLength; k++) /* WATCH THE <= HERE */
     {
         /* go to end of right size of table */
         while(pickUpRight->next != NULL)
         {
             pickUpRight = pickUpRight->next;
             end++; /* increment counter to keep track of last position */
             //printf("Right side # %d, value: %d\n", end, pickUpRight->rightVal);
         }
         /* now put back value onto pack */
           putBackRight(&rightGen, pickUpRight->rightVal); 

         /* temporarily hold position so it can be freed later */
         temp = pickUpRight;
         
         /* go back to start */
         pickUpRight = startRight;
         
         /* now go to previous position of node to be deleted */
         for(i = 0; i < (end-1); i++)
         pickUpRight = pickUpRight->next;
         
         /* point value to null */
         pickUpRight->next = NULL; 
         
         /* now free node */
         free(temp);
       
         end = 0; //reset counter
         /* now go back to start */
         pickUpRight = startRight;
     } /* end outer for */
     pickUpRight = startRight0; /* go right back to beginning of list */
     pickUpRight->next = NULL; /* point root to null */
}/* end pickUpBonesRight */

void putBackLeft(DOMINO *packLeft, int leftVal)
{
     int i;
     DOMINO *startLeft, *insertLeft;
     
     startLeft = packLeft; /* keep track of start position */

     /* go to last postition */
     while(packLeft->next)
       packLeft = packLeft->next;
  
    insertLeft = malloc(sizeof(DOMINO)); /* create left side to be inserted */  
    
    insertLeft->left = leftVal; /* assign value to be inserted */
    
    packLeft->next = insertLeft; /* point end of list to side just created */
    
    insertLeft->next = NULL; /* finally point side created to NULL */

}/* end putBackLeft */

void putBackRight(DOMINO *packRight, int rightVal)
{
     int i;
     DOMINO *startRight, *insertRight;
     
     startRight = packRight; /* keep track of start position */
     
     /* go to end of list */
     while(packRight->next)
       packRight = packRight->next;
    
    /* create right side to be inserted */   
    insertRight = malloc(sizeof(DOMINO));
    
    insertRight->right = rightVal; /* assign value to be inserted */
    
    packRight->next = insertRight; /* point end of list to side just created */
    insertRight->next = NULL; /* finally point side created to NULL */

}/* end putBackRight */
