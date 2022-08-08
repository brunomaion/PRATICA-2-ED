typedef struct grafo Grafo;

Grafo *cria_Grafo(int num_vertices, int grau_max, int ponderado);
int insere_aresta(Grafo* gr, int origem, int destino, int digrafo, float peso);
int remove_aresta(Grafo* gr, int origem, int destino, int digrafo);
void libera_grafo(Grafo* gr);

void imprime_Grafo(Grafo *gr, FILE *file);


