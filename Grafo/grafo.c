#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo {
    int ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

int remove_aresta(Grafo* gr, int origem, int destino, int digrafo){
   if(gr == NULL)
        return -1;
    if(origem < 0 || origem >= gr->num_vertices)
        return 0;
    if(destino < 0 || destino >= gr->num_vertices)
        return 0;

    int i = 0;

    while(i < gr->grau[origem] && gr->arestas[origem][i] != destino){
        i++;
    }

    if(i == gr->grau[origem]){
        return 0;
    }

    gr->grau[origem]--;
    gr->arestas[origem][i] = gr->arestas[origem][gr->grau[origem]];

    if(gr->ponderado){
        gr->pesos[origem][i] = gr->pesos[origem][gr->grau[origem]];
    }
    if(digrafo == 0){
        remove_aresta(gr, destino, origem, 1);
    }

    return 1;
}

int insere_aresta(Grafo* gr, int origem, int destino, int digrafo, float pesos){
    if(gr == NULL)
        return -1;
    if(origem < 0 || origem >= gr->num_vertices)
        return 0;
    if(destino < 0 || destino >= gr->num_vertices)
        return 0;

    gr->arestas[origem][gr->grau[origem]] = destino;

    if(gr->ponderado){
        gr->pesos[origem][gr->grau[origem]] = pesos;
    }

    gr->grau[origem]++;

    if(digrafo == 0){
        insere_aresta(gr,destino,origem,1,pesos);
    }
    return 1;
}

void libera_grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->num_vertices; i++){
            free(gr->arestas[i]);
        }
        free(gr->arestas);

        if(gr->ponderado){
            for(i = 0; i < gr->num_vertices; i++){
                free(gr->pesos[i]);
            }
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

Grafo *cria_Grafo(int num_vertices, int grau_max, int ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));

    if(gr != NULL){

        int i;

        gr->num_vertices = num_vertices;
        gr->grau_max = grau_max;
        gr->ponderado = (ponderado != 0)?1:0;

        gr->grau = (int*) calloc(num_vertices,sizeof(int));
        gr->arestas = (int**)malloc(num_vertices*sizeof(int));

        for(i = 0; i < num_vertices; i++){
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
        }
        if(gr->ponderado){
            gr->pesos=(float**)malloc(num_vertices*sizeof(float*));
            for(i = 0; i < num_vertices; i++)
                gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
        }

    }
    return gr;
}

void imprime_Grafo(Grafo *gr, FILE *file){

    int i, j;
    file = fopen("saida.txt", "a");
    fprintf(file,"Grafo:\n");

    for(i = 0; i < gr->num_vertices; i++){
        fprintf(file,"%d: ", i);
        printf("%d: ", i);
        for(j = 0; j < gr->grau[i]; j++){
            if(gr->ponderado){
                fprintf(file,"%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            }else{
                fprintf(file,"%d, ", gr->arestas[i][j]);
                printf("%d, ", gr->arestas[i][j]);
            }
        }
        fprintf(file,"\n");
        printf("\n");
    }

    fprintf(file,"\n");
    fclose(file);

}