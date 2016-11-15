
/*****************************************************************************/
/* include files; define types and  global data objects                      */
/*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "FEalgo.h"

/*****************************************************************************/
/* global data objects                                                       */
/*****************************************************************************/
#define    cbuffsize 81                              /* input buffer sizze   */
int        echomode=0;                               /* echo mode on/off     */
int        udirmode=1;                               /* graph: dir / undir   */
char       cbuff[cbuffsize];                         /* input buffer         */

/****************************************************************************/
/* User dialogue                                                            */
/****************************************************************************/
char ui_getNode() {
   printf(" Enter node: ");
   scanf("%s", cbuff); if (echomode) printf(" %c", cbuff[0]);
   return cbuff[0];
   }
int  ui_getWeight() {
   int w;
   printf(" Enter weight: ");
   scanf("%d", &w); if (echomode) printf(" %d", w);
   return w;
   }

void ui_putGraphEmpty()    { printf("\n The graph is empty "); }

void ui_putGraphNoEdges()  { printf("\n The graph contains no edges "); }

void ui_putTitleList(int nnodes, int nedges)
{ printf("\n\n Adjacency list (%d nodes %d edges): \n\n", nnodes, nedges);}

void ui_putNodeError(char c)   {
  printf("\n *** ERROR Node %c already exists! ", c);
  }

void ui_putNoNodeError(char c)   {
  printf("\n *** ERROR Node %c NOT in graph! ", c);
  }

void ui_putEdgeError(char cs, char cd) {
  printf("\n *** ERROR Edge (%c, %c) already exists! ", cs, cd);
}

void ui_putNoEdgeError(char cs, char cd) {
  printf("\n *** ERROR Edge (%c, %c) NOT in graph! ", cs, cd);
}

void ui_putNodeFound(char c)    { printf("\n Node %c found in graph ", c); }
void ui_putNodeNotFound(char c) { printf("\n Node %c NOT found in graph ", c); }

void ui_putEdgeFound(char cs, char cd) {
   printf("\n Edge (%c, %c) found in graph ", cs, cd);
}
void ui_putEdgeNotFound(char cs, char cd) {
   printf("\n Edge (%c, %c) NOT found in graph ", cs, cd);
}

/****************************************************************************/
/* UI functions                                                             */
/****************************************************************************/

static char ui_get_input() {
   printf("\n Enter choice ==> ");
   scanf("%s", cbuff); if (echomode) printf(" %c", cbuff[0]);
   return cbuff[0];
   }

/*****************************************************************************/
/*  dispmenu: display the user menu                                          */
/*****************************************************************************/
static void dispmenu() {

   printf("\n");
   printf("***************************************************************\n");
   printf("***                                                         ***\n");
   printf("***   a:   display this menu                                ***\n");
   printf("***   b:   all results                                      ***\n");
   printf("***   c:   Bubble Sort-Best Case                            ***\n");
   printf("***   d:   Bubble Sort-Random Case                          ***\n");
   printf("***   e:   Bubble Sort-Worst Case                           ***\n");
   printf("***                                                         ***\n");
   printf("***   f:   Insertion Sort-Best Case                         ***\n");
   printf("***   g:   Insertion Sort-Random Case                       ***\n");
   printf("***   h:   Insertion Sort-Worst Case                        ***\n");
   printf("***                                                         ***\n");
   printf("***   i:   Quicksort Sort-Best Case                         ***\n");
   printf("***   j:   Quicksort Sort-Random Case                       ***\n");
   printf("***   k:   Quicksort Sort-Worst Case                        ***\n");
   printf("***                                                         ***\n");
   printf("***   l:   Linear Search-Best Case                          ***\n");
   printf("***   m:   Linear Search-Random Case                        ***\n");
   printf("***   n:   Linear Search-Worst Case                         ***\n");
   printf("***                                                         ***\n");
   printf("***   o:   Binary Search-Best Case                          ***\n");
   printf("***   p:   Binary Search-Random Case                        ***\n");
   printf("***   q:   Binary Search-Worst Case                         ***\n");
   printf("***                                                         ***\n");
   printf("***   r:   Exit                                             ***\n");
   printf("***************************************************************\n");
   printf("\n");
   }

/****************************************************************************/
/*  runmenu: execute the user menu                                          */
/****************************************************************************/
void runmenu() {
  
   char   choice;                     /* user menu selection  */

   dispmenu();
   do {
      choice = ui_get_input();
      
      switch(choice) {

         case 'a': case 'A': dispmenu();                        break;

         case 'b': case 'B': fe_results();                      break;
         case 'c': case 'C': fe_Bubblesort_best();              break;
         case 'd': case 'D': fe_Bubblesort_random();            break;
         case 'e': case 'E': fe_Bubblesort_worst();             break;

         case 'f': case 'F': fe_InsertionSort(choice);          break;
         case 'g': case 'G': fe_InsertionSort(choice);          break;

         case 'h': case 'H': fe_InsertionSort(choice);          break;
         case 'i': case 'I': fe_QuickSort(choice);              break;

         case 'j': case 'J': fe_QuickSort(choice);              break;
         case 'k': case 'K': fe_QuickSort(choice);              break;

         case 'l': case 'L': fe_linearsearch(choice);           break;
         case 'm': case 'M': fe_linearsearch(choice);           break;
         
         case 'n': case 'N': fe_linearsearch(choice);           break;
         case 'o': case 'O': fe_binarysearch(choice);           break;
         case 'p': case 'P': fe_binarysearch(choice);           break;
         case 'q': case 'Q': fe_binarysearch(choice);           break;

         case 'r': case 'R': printf("\n *** BYE BYE! ***");     break;

         default:  printf("\n INVALID MENU CHOICE ***\n");
                   dispmenu();                                  break;
         }
      } while (choice != 'R' && choice != 'r');
      printf("\n");
   }
/****************************************************************************/
/* end of menu functions                                                    */
/****************************************************************************/

