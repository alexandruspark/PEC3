#include <stdio.h>

#define MAXFILENAME 20+1
#define MAX_ELEMS 3

int main() {
    char filename[MAXFILENAME];
    char board[MAX_ELEMS][MAX_ELEMS];
    char winner = '-';
    int empty = 0;    
    FILE *file;
    

    // pregunta por el nombre de fichero
    printf("INPUT\n");    
    printf("FILENAME?\n");
    scanf("%s", filename);

    // abre el fichero
    file = fopen(filename, "r");


    // lee la matrix 3x3
    fscanf(file, " %c %c %c", &board[0][0], &board[0][1], &board[0][2]);
    fscanf(file, " %c %c %c", &board[1][0], &board[1][1], &board[1][2]);
    fscanf(file, " %c %c %c", &board[2][0], &board[2][1], &board[2][2]);

    fclose(file);

    // mirar si el ganador es X o O
    
    // filas
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '-')
        winner = board[0][0];
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '-')
        winner = board[1][0];
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '-')
        winner = board[2][0];

    // columnas
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '-')
        winner = board[0][0];
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '-')
        winner = board[0][1];
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '-')
        winner = board[0][2];

    // diagonales
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
        winner = board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
        winner = board[0][2];

    // resultados
    printf("OUTPUT\n");        
    
    if (winner == 'X') {
        printf("X WINS\n");
    } 
    else {
        if (winner == 'O') {
            printf("O WINS\n");
        } 
        else {

            if (board[0][0] == '-' || board[0][1] == '-' || board[0][2] == '-' ||
                board[1][0] == '-' || board[1][1] == '-' || board[1][2] == '-' ||
                board[2][0] == '-' || board[2][1] == '-' || board[2][2] == '-')
                empty = 1;

            if (empty == 1)
                printf("GAME IN PROGRESS\n");
            else
                printf("DRAW\n");
        }
    }

    return 0;
}