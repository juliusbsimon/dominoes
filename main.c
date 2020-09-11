/* PROFANITY IS THE ONLY LANGUAGE A PROGRAMMER UNDERSANDS */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "bones.h"
#include "constants.h"
#include "prototypes.h"
#include "constants.h"

 int firstPlayer, userHighest, cpuHighest, cpu2Highest;
   int dominoesPlayed_u=0, dominoesPlayed_c=0, dominoesPlayed_c2=0, dominoesPlayed_total=0;
   int winner=0;
   
   int token=0;


int main(int argc, char *argv[])
{
   /***********************MISCELLANEOUS FUNCTION CALLS************************/  
    srand(time(NULL)); /* set random initializer */
    system("color f"); /*Sets Defualt Text Color to White*/
    //system("mode con: cols=99 lines=35"); /* set default height and width */
   /****************************VARIABLES**************************************/
   
   user_choice=0;
   cpu_choice=0;
   cpu2_choice=0;       
   
   /*Counters*/
   int i;
   
   char reload[22], reload2[25];
   strcpy(reload, "\"Dominoes GT style.exe\"");
   strcpy(reload2, "\"Dominoes GT style.exe\" 1");
        
  
   //printLoading(); /* where should we put this? */
   

   /******************************END VARIABLES********************************/
   
    /***************************MAIN GAME EXECUTION BEGINS*********************/
    char quit;
    
    
    
    callCreateBones(); /* create bones */

    initPlayers();/*Creates Cpu Players*/
    /* begin while for entire game */
    while(1)
    {
        
       getCpuStats();
       loadStats(); 
       menu();
       callRandomSelect(); /* randomly select bones for players */
       selectOpponents();
       
       GameStatsDisplay(0);/* load and display game statistics */
       printf("\n");
       system("cls");
       
   /* loop until at least one double gets placed into a players hand so the game can begin */
   while (user.restCount == 0 && cpu.restCount == 0 && cpu2.restCount == 0)
   {
      printf("\nUh Oh !!! There are no Dominoes to start the game with.\n");
      printf("Press any key to re-select dominoes.\n\n");
      getch();
      system("cls");
      printf("Dominoes have been shuffled and re-selected. The Game may now begin.\n");
      system("pause");
      system("cls");
      
      reset();
   }
      
   /*This if test checks which player is to play first*/
   userHighest = getLargestRest(&User[0], &user); 
   cpuHighest = getLargestRest(&Cpu[0], &cpu);
   cpu2Highest = getLargestRest(&Cpu2[0], &cpu2);
   
   
   printf("\nYour Opponents are %s and %s.\n", players[opp1].name, players[opp2].name); 
   printf("\nOPPONENTS' STATISTICS\n\n");
      
   playerStatsDisplay(opp1);
   playerStatsDisplay(opp2);
   
   system("pause");
   system("cls");
   
   
   
   //tests the values of the players' doubles to see who plays first
   if (userHighest > cpuHighest && userHighest > cpu2Highest)
   {
      firstPlayer=1;
      printf("You Play First.\n\n");
   }
   else if (cpuHighest > cpu2Highest &&  cpuHighest > userHighest)
   {
      firstPlayer=2;
      printf("%s Plays First.\n\n", players[opp1].name);
   }
   
   else 
   {
      firstPlayer=3;
      printf("%s Plays First.\n\n", players[opp2].name);
   }
   
   
   printNewHand(&User[0]);//Prints the users hand
   
   printf("\nPress any key to start game\n");
   getch();
   system("cls");
   
   switch(firstPlayer)
   {
      case 1:
       
      printf("You have played:");
      showBone(&User[returnIndex(&user)]);
      
      setPlayed(&User[returnIndex(&user)]); /*Sets the attribute value of the domino to played*/
      
      placeBone(&startLeft, &startRight, &User[returnIndex(&user)], 2); /*Places the domino on the table*/ 
      displayTable(&startLeft, &startRight);
      printf("\n\n");
      system("PAUSE");
      dominoesPlayed_u++;  /*Increment total dominoes played by the User by 1*/
      dominoesPlayed_total++;
      token=2;
      break;
            
      case 2:
          
      printf("%s has played:", players[opp1].name);
      
      showBone(&Cpu[returnIndex(&cpu)]);
      
      printf("\n");
      
      setPlayed(&Cpu[returnIndex(&cpu)]);/*Sets the attribute value of the domino to played*/
      
      placeBone(&startLeft, &startRight, &Cpu[returnIndex(&cpu)], 2); /*Places the domino on the table*/ 
      displayTable(&startLeft, &startRight);
      printf("\n\n");
      system("PAUSE");
      dominoesPlayed_total++;
      dominoesPlayed_c++;  /*Increment total dominoes played by Cpu by 1*/
      token=3;
      break;
         
      case 3:
         
      printf("%s has played:", players[opp2].name);
      
      showBone(&Cpu2[returnIndex(&cpu2)]);
      
      printf("\n");
      
      setPlayed(&Cpu2[returnIndex(&cpu2)]);/*Sets the attribute value of the domino to played*/
      
      placeBone(&startLeft, &startRight, &Cpu2[returnIndex(&cpu2)], 2); /*Places the domino on the table*/ 
      displayTable(&startLeft, &startRight);
      printf("\n\n");
      system("PAUSE");
      dominoesPlayed_total++;
      dominoesPlayed_c2++;  /*Increment total dominoes played by Cpu by 1*/
      token=1;
      break;
      
      
   }
   displayTable(&startLeft, &startRight);
   
//----------------------------------------------------------------------------// 
  /*Main Loop, this handles the playing of the game*/
  
   while(dominoesPlayed_total<=21)
   {
      if(cpu_choice == -1 && user_choice == -1 && cpu2_choice == -1)
      {
         /* call function to calculate and display points of winner */
         calculatePoints(&User[0], &Cpu[0], &Cpu2[0]); 
         break;
      }
      
      if(endGame(dominoesPlayed_u, dominoesPlayed_c, dominoesPlayed_c2))
        break;
      
      else
      {
          if(cpu_choice == -1 && user_choice == -1 && cpu2_choice == -1)
          {
             /* call function to calculate and display points of winner */
             calculatePoints(&User[0], &Cpu[0], &Cpu2[0]); 
             break;
          }
                  
//----------------------------------------------------------------------------//         
//----------------------------------------------------------------------------//  
//----------------------------------------------------------------------------//  
         if(token == 1) //ensures that if user plays first CPU will be next to play
         {
            user_choice = userPlay();
            if(user_choice!=-1)
            {
               dominoesPlayed_u++;/*increments total number of dominoes played by user*/
               
               dominoesPlayed_total++;/*increments total number of dominoes played*/
            }
         
            
            if(cpu_choice == -1 && user_choice == -1 && cpu2_choice == -1)
            {
             /* call function to calculate and display points of winner */
             calculatePoints(&User[0], &Cpu[0], &Cpu2[0]); 
             break;
            }
            
                        
            if(endGame(dominoesPlayed_u, dominoesPlayed_c, dominoesPlayed_c2))
            break;
            
            token=2;
         }
         
         if (token ==2)
         {        
            
            cpu_choice = cpuPlay(); /* computer plays matching domino */
            
            if(cpu_choice == -1)
            {
                txtcolor("LIGHTRED");   
                printf("\n\n%s Has Rapped!\n\n", players[opp1].name);
                  
                txtcolor("WHITE");
                system("PAUSE");
            }
      
            else
            {
                dominoesPlayed_c++;
              
                dominoesPlayed_total++;
            }
             
            if(cpu_choice == -1 && user_choice == -1 && cpu2_choice == -1)
            {
             /* call function to calculate and display points of winner */
             calculatePoints(&User[0], &Cpu[0], &Cpu2[0]); 
             break;
            }
            
            if(endGame(dominoesPlayed_u, dominoesPlayed_c, dominoesPlayed_c2))
            break;
            token = 3;
            
         }
         
         if (token == 3)
         {            
            cpu2_choice = cpu2Play(); /* computer plays matching domino */
               
            if(cpu2_choice == -1)
            {
                txtcolor("LIGHTRED");   
                printf("\n\n%s Has Rapped\n\n",  players[opp2].name);
                  
                txtcolor("WHITE");
                system("PAUSE");
            }
      
            else
            {
                dominoesPlayed_c2++;
              
                dominoesPlayed_total++;
            }
            
                  
           /* test if both cpus and User rap */
           if(cpu_choice == -1 && user_choice == -1 && cpu2_choice == -1)
           {
             /* call function to calculate and display points of winner */
             calculatePoints(&User[0], &Cpu[0], &Cpu2[0]); 
             break;
           }
            
            if(endGame(dominoesPlayed_u, dominoesPlayed_c, dominoesPlayed_c2))
            break;
            
        
           token =1;
         }   
 
     }//End else
   }//End While
   
   
   printf("\n");
   printf("%s 's New Rating is ", players[opp1].name );
   showRating(&players[opp1]);
   printf("%s 's New Rating is ", players[opp2].name );
   showRating(&players[opp2]);
     
   printf("Quit? [Y]. Any other key to continue.\n");
   quit = getch();
   
   if(quit == 'Y' || quit == 'y')
   exit(-1);
  
   else
   {
      system("cls");
      progressBar();
      reset();
   }
      
   
   
}/* end while for entire game */
   printf("\n\n");
   system("PAUSE");	
   return 0;
}/* end main */
/*----------------------------------------------------------------------*/
/* Function to reset variables so game can go on */
void reset()
{
    pickUpBones(dominoesPlayed_total);
    
   user_choice=0;
   cpu_choice=0;
   cpu2_choice=0; 
   firstPlayer = userHighest = cpuHighest = cpu2Highest = 0;
   dominoesPlayed_u = dominoesPlayed_c = dominoesPlayed_c2 = dominoesPlayed_total = 0;
   winner = 0;
   token = 0;
   start = 0;
   LR_VALUE[1] = 0;
   LR_VALUE[2] = 0;
   
   
     /* clear all attributes of players' hands */
     int i;
     for(i = 0; i < HANDSIZE; i++){
     User[i].left = 0;
     User[i].right = 0;
     Cpu[i].left = 0;
     Cpu[i].right = 0;
     Cpu2[i].left = 0;
     Cpu2[i].right = 0;
     User[i].rest = 0;
     Cpu[i].rest = 0;
     Cpu2[i].rest = 0;
     User[i].number = i;
     Cpu[i].number = i;
     Cpu2[i].number = i;
     }
     
     user.lgstRestIndex = 0;
     cpu.lgstRestIndex = 0;
     cpu2.lgstRestIndex = 0;
     
     user.largestRest = 0;
     cpu.largestRest = 0;
     cpu2.largestRest = 0;

} /* end reset */
