#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    int vertices, gmax, ponderado, incio, final, dig, procura, op, teste, i;
    float peso;

    FILE *file;

    file = fopen("saida.txt", "w");

    printf("Serao quantas vertices: ");
    scanf("%d", &vertices);
    printf("\nQual sera o grau maximo do grafo: ");
    scanf("%d", &gmax);
    printf("\nGrafo ponderado? \t 0 nao / 1 sim ");
    scanf("%d", &ponderado);

    int ant[vertices];
    float distancia[vertices];
    int visit[vertices], visit2[vertices];
    Grafo *gr;

    gr = cria_Grafo(vertices, gmax, ponderado);
    teste = 1;


    while(teste != -1)
    {
        printf("1 - Adicionar Aresta\n");
        printf("2 - Tirar Aresta\n");
        printf("3 - Apagar todo Grafo\n");
        printf("4 - Imprime o Grafo todo\n");

        scanf("%d",&op);

        switch(op)
        {
            case 1:
                system("clear");

                printf("Inicio: \n");
                scanf("%d", &incio);
                printf("\nFinal: \n");
                scanf("%d", &final);
                printf("0 - Digrafo\t 1 - Nao Digrafo\n");
                scanf("%d", &dig);

                if(ponderado == 1)
                {
                    printf("Peso: \n");
                    scanf("%f", &peso);
                }

                teste = insere_aresta(gr, incio, final, dig, peso);
            if(teste)
            {
                printf("Sucesso!! :D\n");
                getchar();
            }
            else
            {
                printf("Falha!! :c\n");
                getchar();
            }
            break;

        case 2:
            system("clear");
            printf("Inicio: \n");
            scanf("%d", &incio);
            printf("Final: \n");
            scanf("%d", &final);
            printf("0 - Digrafo\t 1 - Nao Digrafo\n");
            scanf("%d", &dig);

            teste = remove_aresta(gr, incio, final, dig);
            if(teste)
            {
                file = fopen("saida.txt", "a");
                fprintf(file,"Deletado com sucesso !!\n");
                printf("Sucesso!! :D\n");
                getchar();
                fclose(file);
            }
            else
            {
                file = fopen("saida.txt", "a");
                fprintf(file,"Erro ao deletar!!\n");
                printf("Falha!! :c\n");
                getchar();
                fclose(file);
            }

            break;

        case 3:
            system("clear");
            libera_grafo(gr);
            printf("Limpo com sucesso!!\n");
            getchar();
            teste = 0;
            break;

        case 4:
            system("clear");
            imprime_Grafo(gr, file);

            break;

        case 0:
            teste = -1;
            fclose(file);
            break;
        }
    }
    return 0;
}
