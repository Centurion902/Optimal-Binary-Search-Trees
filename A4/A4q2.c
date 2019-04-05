/*	
*	Eli-Henry Dykhne
*	0996524
* 	20/03/2019
*	A4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A4.h"

int main(){
	int num = 0;
	char *buf = malloc(sizeof(char)*300);
	FILE *file = fopen("data_7.txt", "r");
	node **wordNodes = malloc(sizeof(node*)*3000);
	node *head = NULL;
	if(file == NULL){
		printf("file not found\n");
		return 0;
	}

	int i;
	wordNodes[0] = NULL;
	//to get rid of the start of file char
	fseek(file, 3, SEEK_SET);
	while(EOF!=fscanf(file, " %s ", buf)){
		i = 0;
		while(wordNodes[i]){
			if(strcmp(buf, wordNodes[i]->word)==0){
				wordNodes[i]->count++;
				break;
			}
			i++;
		}
		//creating uniqe word struct
		if(!wordNodes[i]){
			wordNodes[i] = malloc(sizeof(node));
			wordNodes[i]->word = malloc(sizeof(char)*(strlen(buf)+1));
			strcpy(wordNodes[i]->word, buf);
			wordNodes[i]->count = 1;
			wordNodes[i]->left = NULL;
			wordNodes[i]->right = NULL;
			wordNodes[i+1] = NULL;
		}
		num++;
	}
	i++;
	fclose(file);
	
	qsort(wordNodes, i, sizeof(node*), compar);

	head = createOptimalTreeGreedy(wordNodes, 0, i-1);
	do{
		printf("Enter a key: ");
		scanf("%s", buf);
		findWord(head, buf, num, 1);
		printf("Would you like to exit? y/n: ");
		scanf("%s", buf);
		printf("\n");
	}while(strcmp(buf, "y")!=0);
	free(buf);
	int j = 0;
	while(wordNodes[j]){
		free(wordNodes[j]->word);
		free(wordNodes[j]);
		j++;
	}
	free(wordNodes);
	return 0;
}