/*  
*   Eli-Henry Dykhne
*   0996524
*   20/03/2019
*	A4
*/

#ifndef A4_H
#define A4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char * word;
    int count;
    double avgComps;
    struct node * left;
    struct node * right;
} node;

int compar(const void *l, const void *r);
void findWord(node *head, char* word, int num, int greedy);
node * createOptimalTreeGreedy(node **nodes, int l, int r);
node * createOptimalTreeDynamic(node **nodes, int n, int num);
node * buildFromTable(node **nodes, double **C, int **R, int n, int s);

#endif  