#include <stdio.h>

void bubblesort(int vet[], int tam) {
    int aux;
    for(int i=0; i < tam-1; i++) {
        for(int j=i+1; j < tam; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void mostrarVetor(int vet[], int tam, char msg[]) {
    printf("%s\n", msg);
    for (int i = 0; i < tam; i++) {
        printf("vetor[%d] --> %d\n", i, vet[i]);
    }
}

int main() {

    FILE *file;
    int vetor[10];
    file = fopen("bolhaa.dat", "rb");
    if(file != NULL) {
        printf("\nArquivo aberto lendo...!\n");
        fread(&vetor, sizeof(int), 10, file);
        fclose(file);
        mostrarVetor(vetor, sizeof(vetor)/sizeof(vetor[0]), "Desordenado!!!");
        bubblesort(vetor, sizeof(vetor)/sizeof(vetor[0]));
    }
    else
        printf("\nError!\n");

    file = fopen("ordenado.dat", "wb");
    if (file != NULL) {
        mostrarVetor(vetor, sizeof(vetor)/sizeof(vetor[0]), "Ordenado!!!");
        printf("\nArquivo aberto gravando...\n");
        for(int i=0; i < sizeof(vetor)/sizeof(vetor[0]); i++)
            fwrite(&vetor[i], sizeof(int), 1, file);
    }
    else
        printf("\nError!\n");

    printf("\n");
    fclose(file);
    return 0;
}