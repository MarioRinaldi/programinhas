/*
 change hosts - V 2.00
 software para alteração de hosts de acordo com dev, homol, ou prod
 Mario Felipe Rinaldi - lalo.rinaldi@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Prototipes */
void change(int, char **);
void printFile(char **);
void clearScreen(void);

int main(void) {
    int choice;
    char *file_name;
    
    clearScreen();
    
    puts("qual hosts voce deseja?\n");
    puts("1: Desenvolvimento");
    puts("2: Homologacao");
    puts("3: Producao");
    puts("q: Sair");
    puts("\n");
    printf("escolha [1-5]: ");
    scanf("%d",&choice);

    change(choice, &file_name);
    printFile(&file_name);

    return 0;
}

/* define the file to use later */
void change(int choice, char** file_name) {
    
    switch (choice) {
        case 1:
            puts("voce escolheu dev");
            *file_name = "hosts.dev";
            break;
        case 2:
            puts("voce escolheu homol");
            *file_name = "hosts.homol";
            break;
        case 3:
            puts("voce escolheu prod");
            *file_name = "hosts.prod";            
            break;
        default:
            puts("saindo...");
            exit (1);
            break;
    }

}

/* Function: copy file */
void printFile(char** file_name){
    FILE *original, *copia;
    char caracter;
    
    original = fopen(*file_name, "rb");
    copia = fopen("hosts", "wb");
    
    if ((original=fopen (*file_name, "rb")) == NULL){
        printf ("o arquivo %s nao pode ser aberto\n", *file_name);
        exit (1);
    }
    if ((copia=fopen ("hosts", "wb")) == NULL){
        printf ("o arquivo hosts nao pode ser aberto\n");
        exit (1);
    }

    while(!feof(original)){ 
        caracter = getc(original);
        if(ferror(original)) {
            printf("erro lendo o arquivo %s", *file_name);
            break;
        }
        putc(caracter, copia);
        if(ferror(copia)) {
            printf("erro na gravacao do arquivo hosts");
            break;
        }
    }
    
    fclose(original);
    fclose(copia);
}

/* Function: try clear screen in *nix, if can't, try in windows */
void clearScreen(void){
    int a=0;
    a=system("clear");
    if (a==1) {
        system("cls");
    }
}
