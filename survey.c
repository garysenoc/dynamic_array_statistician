#include "survey.h"
#include <stdio.h>
#include <stdlib.h>




int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


void add(Statistician answer, int *count, int *SIZE, int item){
	if(*count>=*SIZE){
		*SIZE = *SIZE * 2;
		answer =realloc(answer,sizeof(int) * *SIZE);
	}
	
	answer[*count] = item;
	qsort(answer, ++(*count), sizeof(int), cmpfunc);
}

int max(Statistician answer, int count){
	return answer[count-1];
}
int min(Statistician answer, int count){
	return answer[0];
}

int range(Statistician answer, int count){
	return answer[count-1] - answer[0];
}

float mean(Statistician answer, int count){
	int sum = 0,i; 
    for (i = 0; i < count; i++)  
        sum += answer[i]; 
    return (float)sum/(float)count; 
}
float median(Statistician answer, int count){	
       return (count % 2 != 0) ? (float)answer[count/2] : (float)(answer[(count-1)/2] +answer[count/2])/2.0;   
}

void mode(int freq[], int *freqsize, Statistician answer, int count){
	
	int i,max;
	
	for(i=0;i<count;i++)
		freq[answer[i]-1]++;
	
	max =  freq[0];
	
	for(i=1;i<10;i++)
		if(max < freq[i])
			max = freq[i];
			
	for(i=0;i<10;i++)
		if(freq[i] == max)
			printf("%d ",i+1);
}

void histogram(Statistician answer, int count){
	int i,j;
	printf("\n");
	for(i=0;i<9;i++){
		printf("[%d]",i+1);
		for(j=0;j<count;j++)
			if(i+1 == answer[j])
				printf("*");
		printf("\n");
	}
}
