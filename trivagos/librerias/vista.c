#include "vista.h"

void settearConsola(){
    system("mode con cols=80 lines=29");
    SetConsoleTitle("TriVagos+1");
    hidecursor(1);
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_EX_RIGHTSCROLLBAR);
}

void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla
 /// BLACK = 0,  BLUE = 1,  GREEN = 2,  CYAN = 3,  RED = 4,  MAGENTA = 5, BROWN = 6, LGREY = 7, DGREY = 8, LBLUE = 9,
 /// LGREEN = 10, LCYAN = 11, LRED = 12, LMAGENTA = 13, YELLOW = 14, WHITE = 15
 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
 int    New_Color= Text + (Background * 16);
 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}

void mostrarMatriz(stMatriz matriz[COLUMNAS][FILAS], int posX, int posY, int columnas, int filas){
    for (int i = 0; i < filas; i++){
        gotoxy(posX, posY+i);
        for (int j = 0; j < columnas; j++){
            Color(matriz[j][i].fondo, matriz[j][i].color);
            printf("%c", matriz[j][i].caracter);
        }
        printf("\n");
    }
}

void mostrarMatrizHaciaArriba(stMatriz matriz[COLUMNAS][FILAS], int posX, int posY, int columnas, int filas){
    system("cls");
    for (int iterador = FILAS-1; iterador > 0; iterador-=3){

        for (int i = 0; i < filas - iterador; i++){
            gotoxy(posX, iterador+i);
            for (int j = 0; j < columnas; j++){
                Color(matriz[j][i].fondo, matriz[j][i].color);
                printf("%c", matriz[j][i].caracter);
            }
            printf("\n");
        }
    }
}

void mostrarBarraMenu(stMatriz matriz[COLUMNAS][FILASMENU], int posX, int posY, int columnas, int filas){
    for (int iterador = FONDOPANTALLA; iterador > FONDOPANTALLA-filas; iterador-=1){
        for (int i = 0; i <= FONDOPANTALLA - iterador  ; i++){
            gotoxy(posX + 1, iterador + i);
            for (int j = 1; j < columnas - 1; j++){
                Color(matriz[j][i].fondo, matriz[j][i].color);
                printf("%c", matriz[j][i].caracter);
            }
        }
        Sleep(10);
    }
}

void ocultarBarraMenu(stMatriz matriz[COLUMNAS][FILASMENU], int posX, int posY, int columnas, int filas){
    for (int iterador = FONDOPANTALLA-filas; iterador <= FONDOPANTALLA; iterador+=1){
        for (int i = 0; i <= FONDOPANTALLA - iterador  ; i++){
            gotoxy(posX + 1, iterador + i);
            for (int j = 1; j < columnas - 1; j++){
                Color(matriz[j][i].fondo, matriz[j][i].color);
                printf("%c", matriz[j][i].caracter);
            }
        }
        Sleep(10);
    }
}

void selectHotelFromList(int posicion, int colorLetra){
    Color(0, colorLetra);
    gotoxy(1, 12 + posicion * 4);
    printf("%c", 1754);
    gotoxy(1, 13 + posicion * 4);
    printf("%c", 1715);
    gotoxy(1, 14 + posicion * 4);
    printf("%c", 1715);
    gotoxy(1, 15 + posicion * 4);
    printf("%c", 1728);
    gotoxy(72, 12 + posicion * 4);
    printf("%c", 1727);
    gotoxy(72, 13 + posicion * 4);
    printf("%c", 1715);
    gotoxy(72, 14 + posicion * 4);
    printf("%c", 1715);
    gotoxy(72, 15 + posicion * 4);
    printf("%c", 1753);
    for (int i = 1; i < 71; i++){
        gotoxy(1+i, 12 + posicion * 4);
        printf("%c", 1732);
        gotoxy(1+i, 15 + posicion * 4);
        printf("%c", 1732);
    }

}

void selectUsuarioFromList(int posicion, int colorLetra){
    Color(0, colorLetra);
    gotoxy(1, 4 + posicion * 4);
    printf("%c", 1754);
    gotoxy(1, 5 + posicion * 4);
    printf("%c", 1715);
    gotoxy(1, 6 + posicion * 4);
    printf("%c", 1715);
    gotoxy(1, 7 + posicion * 4);
    printf("%c", 1728);
    gotoxy(75, 4 + posicion * 4);
    printf("%c", 1727);
    gotoxy(75, 5 + posicion * 4);
    printf("%c", 1715);
    gotoxy(75, 6 + posicion * 4);
    printf("%c", 1715);
    gotoxy(75, 7 + posicion * 4);
    printf("%c", 1753);
    for (int i = 1; i < 74; i++){
        gotoxy(1+i, 4 + posicion * 4);
        printf("%c", 1732);
        gotoxy(1+i, 7 + posicion * 4);
        printf("%c", 1732);
    }

}

void crearMatrizTituloPerfil(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1732; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 14; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 14; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 14; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 14; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 14; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 14; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 14; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 178; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 178; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 178; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 178; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 178; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 178; matriz[8][1].color = 14; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 178; matriz[9][1].color = 14; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 178; matriz[10][1].color = 14; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 14; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = 178; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 14; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 0; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 'E'; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 'D'; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 'I'; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 'T'; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 'A'; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 'R'; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 219; matriz[21][1].color = 0; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 'P'; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 'E'; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 'R'; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 'F'; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 'I'; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 'L'; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 0; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 178; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 178; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 178; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 178; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 178; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 14; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 14; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1732; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 14; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 14; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 14; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 14; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 14; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 14; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 14; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizTituloClave(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1727; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 0; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 0; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 0; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 0; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 0; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 0; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 0; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 178; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 178; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 178; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 178; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 178; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 178; matriz[8][1].color = 14; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 178; matriz[9][1].color = 14; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 178; matriz[10][1].color = 14; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 14; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = 178; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 14; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 0; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 'E'; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 'D'; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 'I'; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 'T'; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 'A'; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 'R'; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 219; matriz[21][1].color = 0; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 'C'; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 'L'; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 'A'; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 'V'; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 'E'; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 0; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 1731; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 1732; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 1732; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 1732; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 178; matriz[38][1].color = 0; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 0; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 0; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 0; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1753; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 0; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 0; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 0; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 0; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 0; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 0; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 0; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizNombrePerfil(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1732; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 14; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 14; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 14; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 14; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 14; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 14; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 14; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 'N'; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 'O'; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 'M'; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 'B'; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 'R'; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 'E'; matriz[8][1].color = 14; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 178; matriz[9][1].color = 0; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 178; matriz[10][1].color = 0; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 0; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = ':'; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 0; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 178; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 178; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 178; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 178; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 178; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 178; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 178; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 178; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 178; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 178; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 178; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 178; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 178; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 178; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 178; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 178; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 178; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 14; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 14; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1732; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 14; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 14; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 14; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 14; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 14; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 14; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 14; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizLinea(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 0; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 0; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 0; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 0; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 0; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 0; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 0; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 0; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 0; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 0; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 0; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 0; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 0; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 0; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 0; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 0; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 0; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 0; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 0; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 0; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 0; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 0; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 0; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 0; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 0; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 0; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 0; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 0; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 0; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 0; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 0; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 0; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 0; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1732; matriz[34][0].color = 0; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 0; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 0; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 0; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 0; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 0; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 0; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 0; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1732; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 1732; matriz[2][1].color = 14; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 1732; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 1732; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 1732; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 1732; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 1732; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 1732; matriz[8][1].color = 14; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 1732; matriz[9][1].color = 14; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 1732; matriz[10][1].color = 14; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 1732; matriz[11][1].color = 14; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = 1732; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 1732; matriz[13][1].color = 14; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 1732; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 1732; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 1732; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 1732; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 1732; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 1732; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 1732; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 1732; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 1732; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 1732; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 1732; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 1732; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 1732; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 1732; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 1732; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 1732; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 1732; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 1732; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 1732; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 1732; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 1732; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 1732; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 1732; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 1732; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 1732; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 1732; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 1732; matriz[40][1].color = 14; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1732; matriz[41][1].color = 14; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 14; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 0; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 0; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 0; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 0; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 0; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 0; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 0; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 0; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 0; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 0; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 0; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 0; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 0; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 0; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 0; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 0; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 0; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 0; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 0; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 0; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 0; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 0; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 0; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 0; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 0; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 0; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 0; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 0; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 0; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 0; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 0; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 0; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 0; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1732; matriz[34][2].color = 0; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 0; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 0; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 0; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 0; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 0; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 0; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 0; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizDireccionPerfil(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1732; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 14; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 14; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 14; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 14; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 14; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 14; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 14; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 'D'; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 'I'; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 'R'; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 'E'; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 'C'; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 'C'; matriz[8][1].color = 14; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 'I'; matriz[9][1].color = 14; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 'O'; matriz[10][1].color = 14; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 'N'; matriz[11][1].color = 14; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = ':'; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 0; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 178; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 178; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 178; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 178; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 178; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 178; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 178; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 178; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 178; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 178; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 178; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 178; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 178; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 178; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 178; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 178; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 178; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 14; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 14; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1732; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 14; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 14; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 14; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 14; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 14; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 14; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 14; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizClaveAnterior(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1727; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 0; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 0; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 0; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 0; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 0; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 0; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 0; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
     matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 'A'; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 'N'; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 'T'; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 'E'; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 'R'; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 'I'; matriz[8][1].color = 14; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 'O'; matriz[9][1].color = 14; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 'R'; matriz[10][1].color = 14; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 0; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = ':'; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 0; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 178; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 178; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 178; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 178; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 178; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 178; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 178; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 178; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 178; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 178; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 178; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 178; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 1731; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 1732; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 1732; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 1732; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 1732; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 0; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 0; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 0; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1753; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 0; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 0; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 0; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 0; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 0; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 0; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 0; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizTelefonoPerfil(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1732; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 14; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 14; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 14; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 14; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 14; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 14; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 14; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 'T'; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 'E'; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 'L'; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 'E'; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 'F'; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 'O'; matriz[8][1].color = 14; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 'N'; matriz[9][1].color = 14; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 'O'; matriz[10][1].color = 14; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 0; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = ':'; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 0; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 178; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 178; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 178; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 178; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 178; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 178; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 178; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 178; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 178; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 178; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 178; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 178; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 178; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 178; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 178; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 178; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 178; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 14; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 14; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1732; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 14; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 14; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 14; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 14; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 14; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 14; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 14; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizClaveNueva(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1727; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 0; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 0; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 0; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 0; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 0; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 0; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 0; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 'N'; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 'U'; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 'E'; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 'V'; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 'A'; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 178; matriz[8][1].color = 0; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 178; matriz[9][1].color = 0; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 178; matriz[10][1].color = 0; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 0; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = ':'; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 0; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 178; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 178; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 178; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 178; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 178; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 178; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 178; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 178; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 178; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 178; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 178; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 178; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 1731; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 1732; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 1732; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 1732; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 1732; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 1732; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 0; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 0; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1753; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1753; matriz[35][2].color = 0; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1753; matriz[36][2].color = 0; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 0; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 0; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 0; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 0; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 0; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizCorreoPerfil(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1732; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 14; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 14; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 14; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 14; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 14; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 14; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 14; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 'M'; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 'A'; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 'I'; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 'L'; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 219; matriz[7][1].color = 0; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 219; matriz[8][1].color = 0; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 178; matriz[9][1].color = 0; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 178; matriz[10][1].color = 0; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 0; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = ':'; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 0; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 178; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 178; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 178; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 178; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 178; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 178; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 178; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 178; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 178; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 178; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 178; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 178; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 178; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 178; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 178; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 178; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 178; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 14; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 14; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1732; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 14; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 14; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 14; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 14; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 14; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 14; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 14; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void crearMatrizReClaveNueva(stMatriz matriz[COLUMNASMOVIL][FILASMOVIL]){
    matriz[0][0].caracter = 219; matriz[0][0].color = 0; matriz[0][0].fondo = 0;
    matriz[1][0].caracter = 1754; matriz[1][0].color = 14; matriz[1][0].fondo = 0;
    matriz[2][0].caracter = 1732; matriz[2][0].color = 14; matriz[2][0].fondo = 0;
    matriz[3][0].caracter = 1732; matriz[3][0].color = 14; matriz[3][0].fondo = 0;
    matriz[4][0].caracter = 1732; matriz[4][0].color = 14; matriz[4][0].fondo = 0;
    matriz[5][0].caracter = 1732; matriz[5][0].color = 14; matriz[5][0].fondo = 0;
    matriz[6][0].caracter = 1732; matriz[6][0].color = 14; matriz[6][0].fondo = 0;
    matriz[7][0].caracter = 1732; matriz[7][0].color = 14; matriz[7][0].fondo = 0;
    matriz[8][0].caracter = 1732; matriz[8][0].color = 14; matriz[8][0].fondo = 0;
    matriz[9][0].caracter = 1732; matriz[9][0].color = 14; matriz[9][0].fondo = 0;
    matriz[10][0].caracter = 1732; matriz[10][0].color = 14; matriz[10][0].fondo = 0;
    matriz[11][0].caracter = 1732; matriz[11][0].color = 14; matriz[11][0].fondo = 0;
    matriz[12][0].caracter = 1732; matriz[12][0].color = 14; matriz[12][0].fondo = 0;
    matriz[13][0].caracter = 1732; matriz[13][0].color = 14; matriz[13][0].fondo = 0;
    matriz[14][0].caracter = 1732; matriz[14][0].color = 14; matriz[14][0].fondo = 0;
    matriz[15][0].caracter = 1732; matriz[15][0].color = 14; matriz[15][0].fondo = 0;
    matriz[16][0].caracter = 1732; matriz[16][0].color = 14; matriz[16][0].fondo = 0;
    matriz[17][0].caracter = 1732; matriz[17][0].color = 14; matriz[17][0].fondo = 0;
    matriz[18][0].caracter = 1732; matriz[18][0].color = 14; matriz[18][0].fondo = 0;
    matriz[19][0].caracter = 1732; matriz[19][0].color = 14; matriz[19][0].fondo = 0;
    matriz[20][0].caracter = 1732; matriz[20][0].color = 14; matriz[20][0].fondo = 0;
    matriz[21][0].caracter = 1732; matriz[21][0].color = 14; matriz[21][0].fondo = 0;
    matriz[22][0].caracter = 1732; matriz[22][0].color = 14; matriz[22][0].fondo = 0;
    matriz[23][0].caracter = 1732; matriz[23][0].color = 14; matriz[23][0].fondo = 0;
    matriz[24][0].caracter = 1732; matriz[24][0].color = 14; matriz[24][0].fondo = 0;
    matriz[25][0].caracter = 1732; matriz[25][0].color = 14; matriz[25][0].fondo = 0;
    matriz[26][0].caracter = 1732; matriz[26][0].color = 14; matriz[26][0].fondo = 0;
    matriz[27][0].caracter = 1732; matriz[27][0].color = 14; matriz[27][0].fondo = 0;
    matriz[28][0].caracter = 1732; matriz[28][0].color = 14; matriz[28][0].fondo = 0;
    matriz[29][0].caracter = 1732; matriz[29][0].color = 14; matriz[29][0].fondo = 0;
    matriz[30][0].caracter = 1732; matriz[30][0].color = 14; matriz[30][0].fondo = 0;
    matriz[31][0].caracter = 1732; matriz[31][0].color = 14; matriz[31][0].fondo = 0;
    matriz[32][0].caracter = 1732; matriz[32][0].color = 14; matriz[32][0].fondo = 0;
    matriz[33][0].caracter = 1732; matriz[33][0].color = 14; matriz[33][0].fondo = 0;
    matriz[34][0].caracter = 1727; matriz[34][0].color = 14; matriz[34][0].fondo = 0;
    matriz[35][0].caracter = 1732; matriz[35][0].color = 0; matriz[35][0].fondo = 0;
    matriz[36][0].caracter = 1732; matriz[36][0].color = 0; matriz[36][0].fondo = 0;
    matriz[37][0].caracter = 1732; matriz[37][0].color = 0; matriz[37][0].fondo = 0;
    matriz[38][0].caracter = 1732; matriz[38][0].color = 0; matriz[38][0].fondo = 0;
    matriz[39][0].caracter = 1732; matriz[39][0].color = 0; matriz[39][0].fondo = 0;
    matriz[40][0].caracter = 1732; matriz[40][0].color = 0; matriz[40][0].fondo = 0;
    matriz[41][0].caracter = 1727; matriz[41][0].color = 0; matriz[41][0].fondo = 0;
    matriz[42][0].caracter = 219; matriz[42][0].color = 0; matriz[42][0].fondo = 0;
    /// LINEA 8 DE 25
    matriz[0][1].caracter = 1732; matriz[0][1].color = 14; matriz[0][1].fondo = 0;
    matriz[1][1].caracter = 1716; matriz[1][1].color = 14; matriz[1][1].fondo = 0;
    matriz[2][1].caracter = 178; matriz[2][1].color = 0; matriz[2][1].fondo = 0;
    matriz[3][1].caracter = 'N'; matriz[3][1].color = 14; matriz[3][1].fondo = 0;
    matriz[4][1].caracter = 'U'; matriz[4][1].color = 14; matriz[4][1].fondo = 0;
    matriz[5][1].caracter = 'E'; matriz[5][1].color = 14; matriz[5][1].fondo = 0;
    matriz[6][1].caracter = 'V'; matriz[6][1].color = 14; matriz[6][1].fondo = 0;
    matriz[7][1].caracter = 'A'; matriz[7][1].color = 14; matriz[7][1].fondo = 0;
    matriz[8][1].caracter = 178; matriz[8][1].color = 0; matriz[8][1].fondo = 0;
    matriz[9][1].caracter = 178; matriz[9][1].color = 0; matriz[9][1].fondo = 0;
    matriz[10][1].caracter = 178; matriz[10][1].color = 0; matriz[10][1].fondo = 0;
    matriz[11][1].caracter = 178; matriz[11][1].color = 0; matriz[11][1].fondo = 0;
    matriz[12][1].caracter = ':'; matriz[12][1].color = 14; matriz[12][1].fondo = 0;
    matriz[13][1].caracter = 178; matriz[13][1].color = 0; matriz[13][1].fondo = 0;
    matriz[14][1].caracter = 178; matriz[14][1].color = 14; matriz[14][1].fondo = 0;
    matriz[15][1].caracter = 178; matriz[15][1].color = 14; matriz[15][1].fondo = 0;
    matriz[16][1].caracter = 178; matriz[16][1].color = 14; matriz[16][1].fondo = 0;
    matriz[17][1].caracter = 178; matriz[17][1].color = 14; matriz[17][1].fondo = 0;
    matriz[18][1].caracter = 178; matriz[18][1].color = 14; matriz[18][1].fondo = 0;
    matriz[19][1].caracter = 178; matriz[19][1].color = 14; matriz[19][1].fondo = 0;
    matriz[20][1].caracter = 178; matriz[20][1].color = 14; matriz[20][1].fondo = 0;
    matriz[21][1].caracter = 178; matriz[21][1].color = 14; matriz[21][1].fondo = 0;
    matriz[22][1].caracter = 178; matriz[22][1].color = 14; matriz[22][1].fondo = 0;
    matriz[23][1].caracter = 178; matriz[23][1].color = 14; matriz[23][1].fondo = 0;
    matriz[24][1].caracter = 178; matriz[24][1].color = 14; matriz[24][1].fondo = 0;
    matriz[25][1].caracter = 178; matriz[25][1].color = 14; matriz[25][1].fondo = 0;
    matriz[26][1].caracter = 178; matriz[26][1].color = 14; matriz[26][1].fondo = 0;
    matriz[27][1].caracter = 178; matriz[27][1].color = 14; matriz[27][1].fondo = 0;
    matriz[28][1].caracter = 178; matriz[28][1].color = 14; matriz[28][1].fondo = 0;
    matriz[29][1].caracter = 178; matriz[29][1].color = 14; matriz[29][1].fondo = 0;
    matriz[30][1].caracter = 178; matriz[30][1].color = 14; matriz[30][1].fondo = 0;
    matriz[31][1].caracter = 178; matriz[31][1].color = 14; matriz[31][1].fondo = 0;
    matriz[32][1].caracter = 178; matriz[32][1].color = 14; matriz[32][1].fondo = 0;
    matriz[33][1].caracter = 178; matriz[33][1].color = 14; matriz[33][1].fondo = 0;
    matriz[34][1].caracter = 1731; matriz[34][1].color = 14; matriz[34][1].fondo = 0;
    matriz[35][1].caracter = 1732; matriz[35][1].color = 14; matriz[35][1].fondo = 0;
    matriz[36][1].caracter = 1732; matriz[36][1].color = 14; matriz[36][1].fondo = 0;
    matriz[37][1].caracter = 1732; matriz[37][1].color = 14; matriz[37][1].fondo = 0;
    matriz[38][1].caracter = 1732; matriz[38][1].color = 14; matriz[38][1].fondo = 0;
    matriz[39][1].caracter = 178; matriz[39][1].color = 14; matriz[39][1].fondo = 0;
    matriz[40][1].caracter = 219; matriz[40][1].color = 0; matriz[40][1].fondo = 0;
    matriz[41][1].caracter = 1731; matriz[41][1].color = 14; matriz[41][1].fondo = 0;
    matriz[42][1].caracter = 1732; matriz[42][1].color = 14; matriz[42][1].fondo = 0;
     /// LINEA 9 DE 25
    matriz[0][2].caracter = 178; matriz[0][2].color = 0; matriz[0][2].fondo = 0;
    matriz[1][2].caracter = 1728; matriz[1][2].color = 14; matriz[1][2].fondo = 0;
    matriz[2][2].caracter = 1732; matriz[2][2].color = 14; matriz[2][2].fondo = 0;
    matriz[3][2].caracter = 1732; matriz[3][2].color = 14; matriz[3][2].fondo = 0;
    matriz[4][2].caracter = 1732; matriz[4][2].color = 14; matriz[4][2].fondo = 0;
    matriz[5][2].caracter = 1732; matriz[5][2].color = 14; matriz[5][2].fondo = 0;
    matriz[6][2].caracter = 1732; matriz[6][2].color = 14; matriz[6][2].fondo = 0;
    matriz[7][2].caracter = 1732; matriz[7][2].color = 14; matriz[7][2].fondo = 0;
    matriz[8][2].caracter = 1732; matriz[8][2].color = 14; matriz[8][2].fondo = 0;
    matriz[9][2].caracter = 1732; matriz[9][2].color = 14; matriz[9][2].fondo = 0;
    matriz[10][2].caracter = 1732; matriz[10][2].color = 14; matriz[10][2].fondo = 0;
    matriz[11][2].caracter = 1732; matriz[11][2].color = 14; matriz[11][2].fondo = 0;
    matriz[12][2].caracter = 1732; matriz[12][2].color = 14; matriz[12][2].fondo = 0;
    matriz[13][2].caracter = 1732; matriz[13][2].color = 14; matriz[13][2].fondo = 0;
    matriz[14][2].caracter = 1732; matriz[14][2].color = 14; matriz[14][2].fondo = 0;
    matriz[15][2].caracter = 1732; matriz[15][2].color = 14; matriz[15][2].fondo = 0;
    matriz[16][2].caracter = 1732; matriz[16][2].color = 14; matriz[16][2].fondo = 0;
    matriz[17][2].caracter = 1732; matriz[17][2].color = 14; matriz[17][2].fondo = 0;
    matriz[18][2].caracter = 1732; matriz[18][2].color = 14; matriz[18][2].fondo = 0;
    matriz[19][2].caracter = 1732; matriz[19][2].color = 14; matriz[19][2].fondo = 0;
    matriz[20][2].caracter = 1732; matriz[20][2].color = 14; matriz[20][2].fondo = 0;
    matriz[21][2].caracter = 1732; matriz[21][2].color = 14; matriz[21][2].fondo = 0;
    matriz[22][2].caracter = 1732; matriz[22][2].color = 14; matriz[22][2].fondo = 0;
    matriz[23][2].caracter = 1732; matriz[23][2].color = 14; matriz[23][2].fondo = 0;
    matriz[24][2].caracter = 1732; matriz[24][2].color = 14; matriz[24][2].fondo = 0;
    matriz[25][2].caracter = 1732; matriz[25][2].color = 14; matriz[25][2].fondo = 0;
    matriz[26][2].caracter = 1732; matriz[26][2].color = 14; matriz[26][2].fondo = 0;
    matriz[27][2].caracter = 1732; matriz[27][2].color = 14; matriz[27][2].fondo = 0;
    matriz[28][2].caracter = 1732; matriz[28][2].color = 14; matriz[28][2].fondo = 0;
    matriz[29][2].caracter = 1732; matriz[29][2].color = 14; matriz[29][2].fondo = 0;
    matriz[30][2].caracter = 1732; matriz[30][2].color = 14; matriz[30][2].fondo = 0;
    matriz[31][2].caracter = 1732; matriz[31][2].color = 14; matriz[31][2].fondo = 0;
    matriz[32][2].caracter = 1732; matriz[32][2].color = 14; matriz[32][2].fondo = 0;
    matriz[33][2].caracter = 1732; matriz[33][2].color = 14; matriz[33][2].fondo = 0;
    matriz[34][2].caracter = 1753; matriz[34][2].color = 14; matriz[34][2].fondo = 0;
    matriz[35][2].caracter = 1732; matriz[35][2].color = 0; matriz[35][2].fondo = 0;
    matriz[36][2].caracter = 1732; matriz[36][2].color = 0; matriz[36][2].fondo = 0;
    matriz[37][2].caracter = 1732; matriz[37][2].color = 0; matriz[37][2].fondo = 0;
    matriz[38][2].caracter = 1732; matriz[38][2].color = 0; matriz[38][2].fondo = 0;
    matriz[39][2].caracter = 1732; matriz[39][2].color = 0; matriz[39][2].fondo = 0;
    matriz[40][2].caracter = 1732; matriz[40][2].color = 0; matriz[40][2].fondo = 0;
    matriz[41][2].caracter = 1753; matriz[41][2].color = 0; matriz[41][2].fondo = 0;
    matriz[42][2].caracter = 223; matriz[42][2].color = 0; matriz[42][2].fondo = 0;
}

void moverLineasPerfil(stMatriz matrizVista[COLUMNASMOVIL][FILASMOVIL], stMatriz matrizNueva[COLUMNASMOVIL][FILASMOVIL], int posY){
    for (int i = FILASTOTALPERFIL; i > 0; i--){
        for (int x = 0; x < COLUMNASMOVIL; x++){
            for (int j=0; j < FILASMOVIL; j++){
                gotoxy(i+x,j+posY);
                Color(matrizVista[x][j].fondo, matrizVista[x][j].color);
                printf("%c",matrizVista[x][j].caracter);
            }
        }
        for (int k = 0; k <= FILASTOTALPERFIL-i ; k++){
            for (int j = 0; j < FILASMOVIL; j++){
                gotoxy(DESDEPERFIL+i+k, j+posY);
                Color(matrizNueva[k][j].fondo, matrizNueva[k][j].color);
                printf("%c",matrizNueva[k][j].caracter);
            }
        }
    }
    /// Corri el cartel de clave en conjunto con el otro, ahora sigue corriendo solo
    for (int i = FILASTOTALPERFIL+2; i > 0; i--){
        for (int k = 0; k <= FILASTOTALRESTO-i ; k++){
            for (int j = 0; j < 3; j++){
                gotoxy(DESDEPERFILRESTO+i+k, j+posY);
                Color(matrizNueva[k][j].fondo, matrizNueva[k][j].color);
                printf("%c",matrizNueva[k][j].caracter);
            }
        }
        Sleep(15);
    }
}

void mostrarVentanaReserva(int cantidadMayores, int cantidadMenores, stHospedaje hotel){
    ventanaReserva();
    int cantidadHusepedes = cantidadMayores + cantidadMenores;
    Color(DGREY,BLANCO);
    gotoxy(47, 9);
    char fecha[DATES];
    ObtenerFecha(fecha);
    printf("%s", fecha);
    gotoxy(33,11);
    printf("%s", hotel.name);
    gotoxy(39, 13);
    printf("%i", cantidadHusepedes);
    gotoxy(41, 15);
    printf("%.2f", hotel.precio);
    float precioTotal = hotel.precio * cantidadHusepedes;
    gotoxy(46, 17);
    printf("%.2f", precioTotal);
    char key;
    do{
        fflush(stdin);
        key = getch();
    } while (key != ENTER);

}

void mostrarVentanaVotar(int opcion, int voto){
    for (int i = 0; i < COLUMNAS; i++){
        Color(NEGRO,AMARILLO);
        gotoxy(i, 12);
        printf("%c", LINE);
        gotoxy(i, 17);
        printf("%c", LINE);
        Color(NEGRO, NEGRO);
        gotoxy(i,13);
        printf("%c", LINE);
        gotoxy(i,14);
        printf("%c", LINE);
        gotoxy(i,15);
        printf("%c", LINE);
        gotoxy(i,16);
        printf("%c", LINE);
    }
    Color(NEGRO, AMARILLO);
    if (opcion == 0){
        gotoxy(23, 13);
        printf("PUNTUE AL HOSPEDAJE ENTRE 1 Y 10");
    } else {
        gotoxy(19, 13);
        printf("VUELVA A PUNTUAR AL HOSPEDAJE ENTRE 1 Y 10");
    }
    gotoxy(33,14);
    printf("%c%c%c%c%c%c%c%c%c", TOPLEFT, LINE, TARRIBA, LINE, LINE, LINE, TARRIBA, LINE, TOPRIGHT);
    gotoxy(33,15);
    printf("%c-%c   %c+%c", BORDER, BORDER, BORDER, BORDER);
    gotoxy(33,16);
    printf("%c%c%c%c%c%c%c%c%c", BOTTOMLEFT, LINE, TABAJO, LINE, LINE, LINE, TABAJO, LINE, BOTTOMRIGHT);
}

void AnimacionVentanasPerfil(){
    stMatriz matrizVista[COLUMNAS][FILASMOVIL];
    stMatriz matrizNueva[COLUMNAS][FILASMOVIL];

    crearMatrizTituloPerfil(matrizVista);
    crearMatrizTituloClave(matrizNueva);
    moverLineasPerfil(matrizVista, matrizNueva, 6);
    crearMatrizNombrePerfil(matrizVista);
    crearMatrizLinea(matrizNueva);
    moverLineasPerfil(matrizVista, matrizNueva, 9);
    crearMatrizDireccionPerfil(matrizVista);
    crearMatrizClaveAnterior(matrizNueva);
    moverLineasPerfil(matrizVista, matrizNueva, 12);
    crearMatrizTelefonoPerfil(matrizVista);
    crearMatrizClaveNueva(matrizNueva);
    moverLineasPerfil(matrizVista, matrizNueva, 15);
    crearMatrizCorreoPerfil(matrizVista);
    crearMatrizReClaveNueva(matrizNueva);
    moverLineasPerfil(matrizVista, matrizNueva, 18);
}

void limpiarVentanaHoteles(int cantidadFiltrado){
    if (cantidadFiltrado > 0){
        selectHotelFromList(0, AMARILLO);
    } else{
        selectHotelFromList(0, BLANCO);
    }
    selectHotelFromList(1, BLANCO);
    selectHotelFromList(2, BLANCO);
    Color(NEGRO,NEGRO);
    for (int i = 2; i < 72; i++ ){
        gotoxy(i, 22);
        printf(" ");
        gotoxy(i, 21);
        printf(" ");
        gotoxy(i, 18);
        printf(" ");
        gotoxy(i, 17);
        printf(" ");
        gotoxy(i, 14);
        printf(" ");
        gotoxy(i, 13);
        printf(" ");
    }
}

void mostrarHotel(stHospedaje dato, int fav, int reserva, int posY){
    if(dato.active==1){
       Color(NEGRO,LCYAN);
    }else{
       Color(NEGRO,ROJO);
    }
    gotoxy(3,posY);
    printf("                                                                    "); /// borro si hay algo escrito
    gotoxy(3,posY+1);
    printf("                                                                    "); /// borro si hay algo escrito
    gotoxy(3,posY);
    if(dato.active == 0){
        Color(NEGRO,ROJO);
    }
    printf("%s", dato.name);
    if (fav){
        Color(NEGRO, ROJO);
        gotoxy(70,posY);
        printf("%c", HEART); /// Favorito
    }
    if (reserva){
        Color(NEGRO,BROWN);
        gotoxy(60,posY);
        printf("RESERVADO"); /// Reserva
    }
    Color(NEGRO,LGREY);
    gotoxy(35, posY);
    printf("Puntaje %.1f/10", dato.puntaje);
    gotoxy(3,posY+1);
    Color(NEGRO,AMARILLO);
    for (int i=1; i <= dato.cantEstrellas; i++){
        printf("%c ", 15);
    }
    Color(NEGRO, LGREY);
    switch (dato.type){
        case 1:
            printf("- HOTEL");
            break;
        case 2:
            printf("- HOSTAL");
            break;
        case 3:
            printf("- DPTO.");
            break;
    }

    gotoxy(21,posY+1);
    printf("Servicios: ");
    if (dato.wifi == 1){
        printf("wifi - ");
    }
    if (dato.pileta == 1){
        printf("piscina - ");
    }
    if (dato.parking == 1){
        printf("parking");
    }
    Color(NEGRO,LCYAN);
    gotoxy(60,posY+1);
    printf("$%.1f", dato.precio);
    Color(NEGRO,BLANCO);
}

void MarcarTipoHotel(){
    gotoxy(5,6);
    Color(NEGRO, BLANCO);
    printf(" TODOS ");
    gotoxy(13,6);
    Color(4,15);
    printf(" HOTEL ");
}

void MarcarTipoHostal(){
    gotoxy(13,6);
    Color(NEGRO, BLANCO);
    printf(" HOTEL ");
    gotoxy(21,6);
    Color(ROJO,BLANCO);
    printf(" HOSTAL ");
}

void MarcarTipoDpto(){
    gotoxy(21,6);
    Color(NEGRO, BLANCO);
    printf(" HOSTAL ");
    gotoxy(30,6);
    Color(ROJO,BLANCO);
    printf(" DPTO. ");
}

void MarcarTipoTodos(){
    gotoxy(30,6);
    Color(NEGRO, BLANCO);
    printf(" DPTO. ");
    gotoxy(5,6);
    Color(ROJO,BLANCO);
    printf(" TODOS ");
}

void MarcarDesmarcarPiscina(int* piscina){
    if (*piscina == 0){
        gotoxy(13,9);
        Color(NEGRO, BLANCO);
        printf("X");
        *piscina = 1;
    } else {
        gotoxy(13,9);
        Color(NEGRO, BLANCO);
        printf(" ");
        *piscina = 0;
    }
}

void MarcarDesmarcarPiscinaAdmin(int* piscina){
    if (*piscina == 0){
        gotoxy(51,6);
        Color(NEGRO, BLANCO);
        printf("X");
        *piscina = 1;
    } else {
        gotoxy(51,6);
        Color(NEGRO, BLANCO);
        printf(" ");
        *piscina = 0;
    }
}

void MarcarDesmarcarWifi(int* wifi){
    if (*wifi == 0){
        gotoxy(5,9);
        Color(NEGRO, BLANCO);
        printf("X");
        *wifi = 1;
    } else {
        gotoxy(5,9);
        Color(NEGRO, BLANCO);
        printf(" ");
        *wifi = 0;
    }
}

void MarcarDesmarcarWifiAdmin(int* wifi){
    if (*wifi == 0){
        gotoxy(42,6);
        Color(NEGRO, BLANCO);
        printf("X");
        *wifi = 1;
    } else {
        gotoxy(42,6);
        Color(NEGRO, BLANCO);
        printf(" ");
        *wifi = 0;
    }
}

void MarcarDesmarcarParking(int* parking){
    if (*parking == 0){
        gotoxy(24,9);
        Color(NEGRO, BLANCO);
        printf("X");
        *parking = 1;
    } else {
        gotoxy(24,9);
        Color(NEGRO, BLANCO);
        printf(" ");
        *parking = 0;
    }
}

void MarcarDesmarcarParkingAdmin(int* parking){
    if (*parking == 0){
        gotoxy(63,6);
        Color(NEGRO, BLANCO);
        printf("X");
        *parking = 1;
    } else {
        gotoxy(63,6);
        Color(NEGRO, BLANCO);
        printf(" ");
        *parking = 0;
    }
}

void ReiniciarVista(int* cantidadFiltrado, int* posicionSobreLista, int* posicionVista){
    *cantidadFiltrado = 0;
    *posicionSobreLista = 1;
    *posicionVista = 0;
}

void CambioTipoHuesped(int* huesped){
    if (*huesped == 0){
        gotoxy(44,6);
        Color(NEGRO, BLANCO);
        printf(" ADULTO ");
        gotoxy(59,6);
        Color(ROJO,BLANCO);
        printf(" MENOR ");
        *huesped = 1;
    } else {
        gotoxy(59,6);
        Color(NEGRO, BLANCO);
        printf(" MENOR ");
        gotoxy(44,6);
        Color(ROJO, BLANCO);
        printf(" ADULTO ");
        *huesped = 0;
    }
}

int DevolverCoordenadaHoteles(int posicionVista){
    int posY;
    if (posicionVista == 0){
        posY = 13;
    } else if (posicionVista == 1){
        posY = 17;
    } else {
        posY = 21;
    }
    return posY;
}

void ModificarReservaEnVista(int estaReservado, int posY){
    if (!estaReservado){
        Color(NEGRO,BROWN);
        gotoxy(60,posY);
        printf("RESERVADO");
    } else {
        Color(NEGRO,NEGRO);
        gotoxy(60,posY);
        printf("         ");
    }
}

void ModificarFavoritosEnVista(int esFavorito, int posY){
    if (!esFavorito){
        /// mostrar corazon
        Color(NEGRO,ROJO);
        gotoxy(70,posY);
        printf("%c", HEART);
    } else {
        Color(NEGRO,NEGRO);
        gotoxy(70,posY);
        printf(" ");
    }
}

void ModificarActivoVista(int posY, nodoUsuario* nodoElegido){
    int isActive = nodoElegido->dato.active;
    if (!isActive){
        Color(NEGRO, NEGRO);
        gotoxy(65,posY);
        printf("          ");
        nodoElegido->dato.active = 1;
    } else {
        Color(NEGRO,BROWN);
        gotoxy(65,posY);
        printf("INACTIVO");
        nodoElegido->dato.active = 0;
    }
}

void ModificarAdminVista(int posY, nodoUsuario* nodoElegido){
    int isAdmin = nodoElegido->dato.administrator;
    if (!isAdmin){
        Color(NEGRO, LCYAN);
        gotoxy(65,posY);
        printf("ADMIN");
        nodoElegido->dato.administrator = 1;
    } else {
        Color(NEGRO,NEGRO);
        gotoxy(65,posY);
        printf("     ");
        nodoElegido->dato.administrator = 0;
    }
}


/// VISTAS ADMINISTRADOR

void MostrarInfoAdminHospedaje(stHospedaje* hospedaje){
    Color(NEGRO, AMARILLO);
    gotoxy(23,10);
    printf("%s", hospedaje->name);
    gotoxy(60,22);
    printf("%.2f", hospedaje->puntaje);
    gotoxy(53,16);
    printf("%.2f", hospedaje->precio);
    gotoxy(33,16);
    for(int i = 1; i<=hospedaje->cantEstrellas; i++){
        printf("%c",STAR);
    }
    gotoxy(21,19);
    if(hospedaje->wifi == 1){
        printf("X");
    }else{
        printf(" ");
    }
    gotoxy(59,19);
    if(hospedaje->pileta == 1){
        printf("X");
    }else{
        printf(" ");
    }
    gotoxy(24,22);
    if(hospedaje->parking == 1){
        printf("X");
    }else{
        printf(" ");
    }
    switch (hospedaje->type){
        case 1:
            gotoxy(28,13);
            Color(ROJO, BLANCO);
            printf(" HOTEL  ");
            break;
        case 2:
            gotoxy(37,13);
            Color(ROJO, BLANCO);
            printf(" HOSTAL  ");
            break;
        case 3:
            gotoxy(47,13);
            Color(ROJO, BLANCO);
            printf(" DEPARTAMENTO  ");
            break;
    }
    gotoxy(15,10);
    Color(NEGRO,BLANCO);
    printf("NOMBRE:");
}

void mostrarVistaAdminHoteles(int posicionVista, int* barraOpciones, int* barraBusqueda){
    ventanaAdminHoteles();
    selectHotelFromListAdmin(posicionVista, AMARILLO);
    mostrarOcultarBarra(barraOpciones, barraBusqueda, MENUADMINHOSPEDAJES);
}
