#include <stdio.h>
#include <stdlib.h>

#include "hashtag.h"
#include "mergesort.h"

/*  Aplica a funcao MERGE auxiliar do mergesort
    Versao estavel (usa vetor auxiliar b)
    INPUT : Item para ordenar, limite inferior(low), medio(mid)
    e limite superior (high) */
void merge(ItemToSort a, int low, int mid, int high){

    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if(less_sort(a[i],a[j]))
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}

/* Mergesort
   INPUT : Item para ordenar(a), limite inferior(l), limite superior(r) */
void mergesort(ItemToSort a, int l, int r){
 	int m = (r+l)/2;
 	if (r <= l) return;
 	mergesort(a, l, m); 	
 	mergesort(a, m+1, r); 	
 	merge(a, l, m, r);
}

/* Aplica algoritmo de mergesort ao vetor auxiliar usando
   memoria dinamica
   INPUT : Item para ordenar(a), limite inferior(r), limite superior(l) */
void Sort(ItemToSort a, int r, int l){
	if(l <= r) return;

    /*cria vetor auxiliar*/
	b = (ItemToSort)malloc(sizeof(Item)*(l-r+1));

	mergesort(a, r, l);

    /*liberta vetor auxiliar*/
	free(b);
}
