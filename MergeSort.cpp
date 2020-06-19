#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void merge(float A[], int inicio, int meio, int fim) {
    int tamEsq = meio - inicio + 1; //tamanho do subvetor esquerdo
    int tamDir = fim - meio; //tamanho do subvetor direito
    int esq[tamEsq]; //subvetor auxiliar esquerdo
    int dir[tamDir]; //subvetor auxiliar direito
    int idxEsq = 0; //índice do subvetor auxiliar esquerdo
    int idxDir = 0; //índice do subvetor auxiliar direito
    int i, j, k;
    
    //Copia os elementos do subvetor esquerdo para o vetor auxiliar
    for (i = 0; i < tamEsq; i++) {
        esq[i] = A[inicio + i];
    }
    //Copia os elementos do subvetor direito para o vetor auxiliar
    for (j = 0; j < tamDir; j++) {
        dir[j] = A[meio + 1 + j];
    }

    //intercala os vetores
    for (k = inicio; k <= fim; k++) {
        if (idxEsq < tamEsq) {
            if (idxDir < tamDir) {
                if (esq[idxEsq] < dir[idxDir]) {
                    A[k] = esq[idxEsq++];
                } else {
                    A[k] = dir[idxDir++];
                }
            } else {
                A[k] = esq[idxEsq++];
            }
        } else {
            A[k] = dir[idxDir++];
        }
    }
}
void mergeSort(float A[], float inicio, float fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2; //calcula o meio
        mergeSort(A, inicio, meio); //ordena do subvetor esquerdo
        mergeSort(A, meio + 1, fim); //ordena do subvetor direito
        merge(A, inicio, meio, fim); //funde os subvetores esquerdo e direito
    }
}

int main() {
    int n, i;
    float *v;
    printf("Informe o tamanho do vetor: \n");
	scanf ("%d",&n);
    v = (float *)malloc(n * sizeof(float));
    for (i = 0; i < n; ++i) {
        v[i] = i;
    printf("Informe o salario: \n");
	scanf("%f", &v[i]);
	}
	mergeSort(v, 0, n - 1);
	printf("SALARIO DOS FUNCAIONARIOS\n ");
		for (i = 0; i < n; ++i) {
			printf ("R$ %.2f \n", v[i]);
	}
	return 0;        
    printf("\n");
}
	

