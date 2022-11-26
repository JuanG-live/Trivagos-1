#include "utilities.h"

void LimpiarMailErroneo(){
    Color(NEGRO,AMARILLO);
    for (int i = 0; i < MAIL-2; i++){
        gotoxy(33+i, 16);
        printf("%c", LBLOCK);
    }
}

void limpiaFormulario(int fromX, int toX, int posY, int caracter, int fondo, int color){
    Color(fondo, color);
    for (int x = fromX; x < toX; x++)
    {
        gotoxy(x, posY);
        printf("%c", caracter);
    }
}

void MensajesErroresRegistro(char mensaje[], int posX, int posY){
    hidecursor(SI);
    Color(NEGRO,ROJO);
    gotoxy(posX, posY);
    printf("%s", mensaje);
    Color(NEGRO, NEGRO);
    Sleep(1000);
    gotoxy(posX, posY);
    printf("                                          ");
    for (int x = posX; x < 66; x++){
        gotoxy(posX, posY);
        printf("%c", BLOCK);
    }
    hidecursor(NO);
}

void MensajesAdvertencias(char mensaje[], int posX, int posY, int colorLetra){
    hidecursor(SI);
    Color(NEGRO, colorLetra);
    gotoxy(posX, posY);
    printf("%s", mensaje);
    Color(NEGRO, NEGRO);
    Sleep(1500);
    gotoxy(posX, posY);
    for (int i = 0; i < strlen(mensaje); i++){
        gotoxy(posX + i, posY);
        printf(" ");
    }
    hidecursor(NO);
}

int ObtenerFecha(char output[]){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(output,128,"%d/%m/%y",tlocal); //%H:%M:%S
    return 0;
}

int ValidaMailCorrecto(char mail[]){
    //Tiene que tener un @, no puede ser ni el primer, ni el ultimo caracter.
    // Hay mas validaciones como tener un . despues del @ pero no al lado, el . no puede ser el ultimo elemento.
    int mailValido = 0;
    int resultado = strcspn(mail, "@");
    if (resultado >= 1 && resultado < strlen(mail) - 1){
        resultado = strcspn(mail, ".");
        if (resultado >= 1 && resultado < strlen(mail) - 1){
                mailValido = 1;
        }
    }
    return mailValido;
}

int CapturarPalabra(char palabra[], int posX, int posY, int cantidadChar, int type, int modo, int colorLetra){
    char tecla = 0;
    int i = 0;
    int lineaActual = 0;
    int posXMovil = 0;
    gotoxy(posX, posY);
    Color(NEGRO,colorLetra);
    do {
        fflush(stdin);
        tecla = getch();
        if (tecla == BACKSPACE){
            if (i > 0) {
                i--;
                posXMovil--;
                if (posXMovil < 0) {
                  posXMovil = 60;
                  lineaActual--;
                }
                gotoxy(posX+posXMovil,posY+lineaActual);
                if (modo == 0){
                    printf("%c", 178); /// borro con caracter
                } else if (modo == 1) {
                    printf(" "); /// Borro con color letra
                } else {
                    Color(NEGRO, NEGRO);
                    printf(" "); /// Borro en negro
                    Color(NEGRO,colorLetra);
                }
                gotoxy(posX+posXMovil,posY+lineaActual);
            }
        } else if (tecla != TAB && tecla != ESC && tecla != ENTER && tecla != -32) {
            palabra[i] = (char) tecla;
            if (posXMovil > 60) {
                lineaActual++;
                posXMovil = 0;
            }
            if (type == 0) {
                gotoxy(posX+posXMovil, posY + lineaActual);
                printf("%c", palabra[i]);
            } else {
                gotoxy(posX+posXMovil, posY + lineaActual);
                printf("*");
            }
            posXMovil++;
            i++;
        } else {
            if (tecla != ESC && tecla != -32){
                tecla = ENTER;
            }
            if (tecla == -32){
                tecla = getch(); // tomo esa tecla especial para no hacer nada con ella
                fflush(stdin);
                i--; // Achico el indice para compensar la perdida de la tecla que suma luego.
            }
            i++;
        }
    } while (tecla !=ENTER && tecla != ESC && i < cantidadChar);
    if (i >= cantidadChar){ // SI EL USUARIO USO UN MAIL DEL MAXIMO PERMITIDO CORTA POR TAMAÑO ENTONCES LO IGUALO A APRETAR ENTER
        tecla = ENTER;
    }
    palabra[i-1] = '\0';
    return tecla;
}

int ModificarPalabra(char palabra[], char dato[],int posX, int posY, int cantidadChar, int colorLetra, int colorBorra, int formaBorra){
    Color(NEGRO, colorLetra);
    char tecla = 0;
    int cantidadLetras = strlen(dato);
    strcpy(palabra, dato);
    gotoxy(posX + cantidadLetras, posY);

    do {
        fflush(stdin);
        tecla = getch();
        if (tecla == BACKSPACE){
            if (cantidadLetras > 0) { // VERIFICO QUE EL TEXTO NO OCUPE MAS DE 1 LINEA
                cantidadLetras--;
                gotoxy(posX + cantidadLetras,posY);
                Color(NEGRO, colorBorra);
                printf("%c", formaBorra);
                gotoxy(posX + cantidadLetras,posY);
            }
        } else if (tecla != TAB && tecla != ESC && tecla != ENTER && tecla != -32 && cantidadLetras <= cantidadChar) {
            Color(NEGRO, colorLetra);
            palabra[cantidadLetras] = (char)tecla;
            gotoxy(posX + cantidadLetras, posY);
            printf("%c", palabra[cantidadLetras]);
            cantidadLetras++;
        } else {
            if (tecla != ESC && tecla != -32){
                tecla = ENTER;
            }
            if (tecla == -32){
                tecla = getch(); // tomo esa tecla especial para no hacer nada con ella
                fflush(stdin);
                cantidadLetras--; // Achico el indice para compensar la perdida de la tecla que suma luego.
            }
            cantidadLetras++;
        }
    } while (tecla !=ENTER && tecla != ESC && cantidadLetras <= cantidadChar);

    if (tecla == ENTER) {
        palabra[cantidadLetras] = '\0';
    }
    return tecla;
}

void MostrarMensaje(char mensaje[]){
    Color(NEGRO, AMARILLO);
    hidecursor(SI);
    for (int x = 10; x < 68; x++){
        gotoxy(x,17);
        printf("%c", LINE);
        gotoxy(x,18);
        printf(" ");
        gotoxy(x, 19);
        printf("%c", LINE);
    }
    for (int y = 17; y < 19; y++){
        gotoxy(10,y);
        printf("%c", BORDER);
        gotoxy(68,y);
        printf("%c", BORDER);
    }
    gotoxy(10,17);
    printf("%c", TOPLEFT);
    gotoxy(68,17);
    printf("%c", TOPRIGHT);
    gotoxy(10,19);
    printf("%c", BOTTOMLEFT);
    gotoxy(68,19);
    printf("%c", BOTTOMRIGHT);
    int posicion = (56 - strlen(mensaje)) / 2;
    gotoxy(10 + posicion,18);
    printf("%s", mensaje);
    Sleep(2000);
}

void mostrarOcultarBarra(int* barraOpciones, int* barraBusqueda, int idMenu){
    if (idMenu == MENUBUSQUEDA){  /// Llame para mostrar la barra busqueda
        if (*barraOpciones == 1){
            menuBotonesHotelesBajar(); /// Si llamo desde 3 es porque la barra que puede estar en ON es la de Hoteles
            *barraOpciones = 0;
        }
        if (*barraBusqueda == 1){
            menuBusquedaOcultar();
            *barraBusqueda = 0;
        } else{
            menuBusquedaMostrar();
            *barraBusqueda = 1;
        }
    } else { /// Llame a la funcion para mostrar u ocultar una barra que no es busqueda
        if (*barraBusqueda == 1){ /// Verifico que no este mostrandose la busqueda, sino la oculto.
            menuBusquedaOcultar();
            *barraBusqueda = 0;
        }
        if (*barraOpciones == 0){
            *barraOpciones = 1;
            switch (idMenu)
            {
                case MENUPPAL:
                    menuBotonesPrincipalSubir();
                    break;
                case MENULOGIN:
                    menuBotonesLogInSubir();
                    break;
                case MENUHOTELES:
                    menuBotonesHotelesSubir();
                    break;
                case MENUEDITPERFIL:
                    menuCambiarPerfilSubir();
                    break;
                case MENUADMINISTRADOR:
                    menuAdministradorSubir();
                    break;
                case MENUADMINUSERS:
                    menuAdminUsersSubir();
                    break;
                case MENUADMINUSERSFAVYRESERVAS:
                    menuAdminUsersFavResSubir();
                    break;
                case MENUADMINHOSPEDAJES:
                    menuAdminHospedajesSubir();
                    break;
                case MENUAGREGAHOSPEDAJE:
                    menuAgregarHospedajeSubir();
                    break;
            }

        } else {
            *barraOpciones = 0;
            switch (idMenu)
            {
                case MENUPPAL:
                    menuBotonesPrincipalBajar();
                    break;
                case MENULOGIN:
                    menuBotonesLogInBajar();
                    break;
                case MENUHOTELES:
                    menuBotonesHotelesBajar();
                    break;
                case MENUEDITPERFIL:
                    menuCambiarPerfilBajar();
                    break;
                case MENUADMINISTRADOR:
                    menuAdministradorBajar();
                    break;
                case MENUADMINUSERS:
                    menuAdminUsersBajar();
                    break;
                case MENUADMINUSERSFAVYRESERVAS:
                    menuAdminUsersFavResBajar();
                    break;
                case MENUADMINHOSPEDAJES:
                    menuAdminHospedajesBajar();
                    break;
                case MENUAGREGAHOSPEDAJE:
                    menuAgregarHospedajeBajar();
                    break;
            }
        }
    }
}

void salirSistema(){
    Color(NEGRO,BLANCO);
    system("cls");
    printf("GRACIAS POR USAR NUESTRO SISTEMA....");
}
