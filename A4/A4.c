/*  
*   Eli-Henry Dykhne
*   0996524
*   20/03/2019
*   A4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "A4.h"

//this function compares and orders words alphabetically
int compar(const void *l, const void *r){
    
    node *a = *((node **)l);
    node *b = *((node **)r);
    return strcmp(a->word, b->word);
}

//this function searches the binary tree.
void findWord(node *head, char* word, int num, int greedy){
    if(head==NULL){
        printf("Not found.\n");
    }else if(strcmp(head->word, word)==0){
        if(greedy){
            printf("Compared with %s (%.4f), found.\n", head->word, ((double)head->count)/num);
        }else{
            printf("Compared with %s (%.2f), found.\n", head->word, head->avgComps);
        }
    }else if(strcmp(head->word, word)<0){
        if(greedy){
            printf("Compared with %s (%.4f), go right subtree.\n", head->word, ((double)head->count)/num);
        }else{
            printf("Compared with %s (%.2f), go right subtree.\n", head->word, head->avgComps);
        }
        findWord(head->right, word, num, greedy);
    }else if(strcmp(head->word, word)>0){
        if(greedy){
            printf("Compared with %s (%.4f), go left subtree.\n", head->word, ((double)head->count)/num);
        }else{
            printf("Compared with %s (%.2f), go left subtree.\n", head->word, head->avgComps);
        }
        findWord(head->left, word, num, greedy);
    }
}

//this function creates an optimal tree the greedy way
node * createOptimalTreeGreedy(node **nodes, int l, int r){
    node *head;
    if(l>r){
        return NULL;
    }
    int maxIndex = l;
    for(int i = l; i<=r; i++){
        if((nodes[i]->count)>(nodes[maxIndex]->count)){
            maxIndex = i;
        }
    }
    head = nodes[maxIndex];
    head->left = createOptimalTreeGreedy(nodes, l, maxIndex-1);
    head->right = createOptimalTreeGreedy(nodes, maxIndex+1, r);
    return head;
}

//this function creates the optimal tree from the tables
node * buildFromTable(node **nodes, double **C, int **R, int n, int s){
    node * head = NULL;
    if(C[s][n]==0){
        return NULL;
    }
    nodes[R[s][n]-1]->avgComps = C[s][n];
    head = nodes[R[s][n]-1];
    head->left = buildFromTable(nodes, C, R, R[s][n]-1, s);
    head->right = buildFromTable(nodes, C, R, n, R[s][n]+1);
    return head;
}

//this function generates tables to create an optimal binary tree and determine the search cost of each node
node * createOptimalTreeDynamic(node **nodes, int n, int num){
    double **C = malloc(sizeof(double*)*(n+2));
    int **R = malloc(sizeof(int*)*(n+2));
    for(int i = 0; i<n+2; i++){
        C[i]=calloc((n+1), sizeof(double));
        R[i]=calloc((n+1), sizeof(int));
    }
    for(int i = 1; i<=n; i++){
        C[i][i-1] = 0;
        R[i][i-1] = 0;
        C[i][i] = ((double)nodes[i-1]->count)/num;
        R[i][i] = i;
    }
    C[n+1][n]=0;
    for(int d = 1; d<=n-1; d++){
        //printf("%d\n", d);
        for(int i=1; i<=n-d; i++){

            int j = i+d;
            double minval = LONG_MAX;
            int kmin;
            for(int k = i; k<=j; k++){
                if(C[i][k-1]+C[k+1][j]<minval){
                    minval = C[i][k-1]+C[k+1][j];
                    kmin = k;
                }
            }
            R[i][j] = kmin;
            double sum = ((double)nodes[i-1]->count)/num;
            for(int s=i+1; s<=j; s++){
                sum+=((double)nodes[s-1]->count)/num;
            }
            
            C[i][j] = minval+sum;
        }
    }
    //generating tree
    node * head = buildFromTable(nodes, C, R, n, 1);
    
    for(int i = 0; i<n+2; i++){
        free(C[i]);
        free(R[i]);
    }
    free(C);
    free(R);
    return head;
}
