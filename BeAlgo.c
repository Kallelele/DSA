#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 16384
// array first rotation
int best[MAXSIZE];
int worst[MAXSIZE];
int rdm[MAXSIZE];  

int *get_best(){ return best;}
int *get_worst(){ return worst;}
int *get_random(){ return rdm;}


// Initiering av array
void init_array(int best[]){
	int i;
	for(i=1;i<MAXSIZE;i++){ best[i]=i;}
}	

// Bubble Sort
void Bubblesort(int best[]) {
	init_array(best);
	// TODO
	// Kopiera över till en ny array för att inte modifiera start array
	int i,j;
	int e=0;
	bool swapped = false;
	for(i=0;i<MAXSIZE-1-i;i++) {
		swapped = false;
		for(j=0;j<MAXSIZE-i;j++){
			if(best[j-1] > best[j]) {
				e = best[j];
				best[j]=best[j+1];
				best[j+1] = e;
				swapped = true;
			}	
		}
		if(!swapped) {
         break;
		}
	}	
	printf("TO BE DONE Bubble");
}
// TODO 
// Display data

// TODO 
// Insertion Sort




