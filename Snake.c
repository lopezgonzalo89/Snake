#include <stdio.h>
#define V 21
#define H 65
#define N 100

// Estructuras
typedef struct Snake
{
    int x, y;
    int ModX, ModY;
    char imagen;
}snk;

typedef struct 
{
    int x, y;
}frt;

snk snake[N];
frt fruta;

// Prototipos de funciones
void inicio(int *tam, char campo[V][H]);
void Intro_Campo(char campo[V][H]);
void Intro_Datos( char campo[V][H], int tam);
void draw(char campo[V][H]);

int main(){
    int tam;
    char campo[V][H];

    inicio(&tam, campo);

    draw(campo);

    system("pause");
    return 0;
}

void inicio(int *tam, char campo[V][H]){
    int i;

    // snake[0] = Cabeza
    snake[0].x = 32;
    snake[0].y = 10;

    // tamaño inicial
    *tam = 4;

    //Coordenadas de la fruta
    srand(time(NULL));

    while( fruta.x == 0){
        fruta.x = rand() % (H - 1);
    };
    while( fruta.y == 0){
        fruta.y = rand() % (V - 1);
    };
    
    for( i =0; i < *tam; i++){
        snake[i].ModX = 1;
        snake[i].ModY = 0;
    }

    // Iniciar el campo y los datos
    Intro_Campo(campo);
    Intro_Datos(campo, *tam);
}

// Creacion del campo
void Intro_Campo(char campo[V][H]){
    int i, j;

    for(i = 0; i < V; i++){
        for(j = 0; j < H; j++){
            if ( i == 0 || i == V - 1){
                campo[i][j] = '_';
            }
            else if (j == 0 || j == H - 1){
                campo [i][j] = '|';
            }
            else {
                campo[i][j] = ' ';
            }
        }
    }
}

// Insertar datos en la matriz del campo
void Intro_Datos( char campo[V][H], int tam){
    int i;

    // Cabeza de la snake
    snake[0].imagen = 'O';

    // Cuerpo de la snake
    for(i = 1; i < tam; i++){
        snake[i].x = snake[i - 1].x - 1;
        snake[i].y = snake[i - 1].y;

        // Imagen del cuerpo
        snake[i].imagen = 'X';
    }

    // Dibuja la snake en el campo
    for(i = 0; i < tam; i++){
        campo[snake[i].y][snake[i].x] = snake[i].imagen;        
    }

    // Dibuja la frurta en el campo
    campo[fruta.y][fruta.x] = '%';
}

void draw(char campo[V][H]){
    int i, j;

    for( i = 0; i < V; i++){
        for( j = 0; j < H; j++){
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }
}