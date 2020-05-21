/*
Ricardo Cuevas Mondragón

Título: Proyecto Final. C Intermedio.
*/

//Bibliotecas
#include<stdio.h>
#include<string.h>

//Prototipo de funciones.
void titulo(void);

//Funcion Princiapl.
int main(){
    FILE *ap;
    int opcion;
    char usuario[30], contra[30];
    char usr[30], cont[30];

    ap = fopen("UsuariosMixUp.txt","a+");

    system("title Proyecto C Intermedio");
    system("color 0B");

    do{
        system("cls");
        titulo();
        printf("\n\t  %c %c %c   BIENVENIDO A LA TIENDA DE MUSICA ONLINE   %c %c %c\n\n",14,14,14,14,14,14);
        printf("Crea una cuenta o registrate.");
        printf("\n\n1) Registrarse\n2) Iniciar sesion\n3) Salir\n\n");
        printf("Ingresa la opcion deseada => ");
        scanf("%d",&opcion);

        switch(opcion){

            case 1:
                printf("\nIngresa tu usuario: ");
                fflush(stdin);
                gets(usuario);
                printf("Ingresa tu contrase%ca: ",164);
                fflush(stdin);
                gets(contra);
                fprintf(ap,"\nUsuario: %s \tContraseña: %s",usuario,contra);
                printf("\n\nHas sido registrado en MixUp! %c %c %c\n\n",14,14,14);
                system("pause");
                break;

            case 2:
                printf("\nIngresa tu usuario: ");
                fflush(stdin);
                gets(usuario);
                printf("Ingresa tu contrase%ca: ",164);
                fflush(stdin);
                gets(contra);

                if(strcmp(usuario,"admin")==0 && strcmp(contra,"admin")==0){
                    system("cls");
                    titulo();
                    printf("\nBienvenido de nuevo administrador!!\n\n\n");
                    system("pause");
                    opcion=3;
                    break;

                }else{
                    fseek(ap,0,SEEK_SET);
                    while(feof(ap)==0){
                    fscanf(ap,"\nUsuario: %s \tContraseña: %s",usr,cont);
                        if(strcmp(usuario,usr)==0 && strcmp(contra,cont)==0){
                            system("cls");
                            titulo();
                            printf("\nBienvenid@ %s!! %c %c %c\n\n\n",usuario,14,14,14);
                            system("pause");
                            opcion=3;
                            break;
                        }
                    }

                    if(opcion!=3){
                        printf("\n\t\t\t\tUPS!");
                        printf("\n\tUsuario o contrase%ca incorrectos. Intentelo de nuevo.\n\n",164);
                        system("pause");
                    }
                }

                break;

            case 3:
                printf("\nHas seleccionado SALIR.\n");
                break;

            default:
                printf("\nOpcion no valida.\n\n");
                system("pause");
        }

    }while(opcion!=3);

    fclose(ap);

    return 0;
}

//Funciones.
void titulo(void){
        printf("\n");
        printf("88b           d88 88             88        88\n");
        printf("888b         d888 8b             88        88\n");
        printf("88`8b       d8'88                88        88\n");
        printf("88 `8b     d8' 88 88 8b,     ,d8 88        88 8b,dPPYba,\n");
        printf("88  `8b   d8'  88 88  `Y8, ,8P'  88        88 88P'    '8a\n");
        printf("88   `8b d8'   88 88    )888(    88        88 88       d8\n");
        printf("88    `888'    88 88  ,d8' '8b,  Y8a.    .a8P 88b,   ,a8'\n");
        printf("88     `8'     88 88 8P'     `Y8  `'Y8888Y'   88`YbbdP'\n");
        printf("                                              88\n");
        printf("                                              88\n");
}
