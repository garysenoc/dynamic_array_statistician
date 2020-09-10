#include <stdio.h>
#include <stdlib.h>
#include "survey.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	

	int SIZE = 10,count = 0,item,i,*freq = (int*)calloc(SIZE,sizeof(int)),freqsize,add1;
	char opt = 'y';
	Statistician answer = (Statistician)calloc(SIZE,sizeof(int));
	
	printf("Enter responses\n");
	
	for(i=0;i<SIZE;i++){
		fflush(stdin);
		printf("Respnse no. %d: ",i+1);
		scanf("%d",&item);
		add(answer,&count,&SIZE,item);
	}

	while(1){
		fflush(stdin);
		printf("Do you want to add more response/s?\n [y]-Yes/[n]-No : ");
		scanf("%c",&opt);
		if(opt=='n')
			break;
		fflush(stdin);
		printf("How many responses do you want to add? ");
		scanf("%d",&add1);
		for(i=0;i<add1;i++){
		fflush(stdin);
		printf("Response no. %d: ",count+1	);
		scanf("%d",&item);
		add(answer, &count, &SIZE,item);
		}
	}
	
	for(i=0;i<count;i++){
		printf("%d ",answer[i]);
	}
	
	printf("\nMin: %d",min(answer,count));
	printf("\nMax: %d",max(answer,count));
	printf("\nRange: %d",range(answer,count));
	printf("\nMean: %.2f",mean(answer,count));
	printf("\nMedian: %.2f",median(answer,count));
	printf("\nMode/s: ");mode(freq, &freqsize, answer,count);
	histogram(answer,count);
	
	return 0;
}
