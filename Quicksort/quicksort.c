#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10

void quick_sort(int *a, int left, int right);
 
int main(int argc, char** argv){
 int i, vet[MAX];
 
 FILE *arq;

 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 
 quick_sort(vet, 0, MAX - 1);
 
 printf("\nValores ordenados\n");

 arq = fopen("Resultados.txt", "wt");

if(arq == NULL)printf("Não foi possível abrir o arquivo!!");

else{
 for(i = 0; i < MAX; i++)
 {
    printf("%d ", vet[i]);
    fprintf(arq,"%d ",vet[i]);
 }
 fclose(arq);

 system("pause");
 }
 return 0;
}
 
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}