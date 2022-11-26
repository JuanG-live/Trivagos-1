#include "administrador.h"

/// ADMINISTRAR HOSPEDAJES

void mostrarMatrizHotel(stMatriz matriz[COLUMNAS][FILASHOTEL], int posX, int posY, int columnas, int filas){
    for (int i = 0; i < filas; i++){
        gotoxy(posX, posY+i);
        for (int j = 0; j < columnas; j++){
            Color(matriz[j][i].fondo, matriz[j][i].color);
            printf("%c", matriz[j][i].caracter);
        }
        printf("\n");
    }
}

void mostrarMatrizAdministrador(stMatriz matriz[COLUMNAS][FILASADMIN], int posX, int posY, int columnas, int filas, int cantidadLineas){
    int y = 0;
    for (int j = cantidadLineas; j > 0; j--){
        for (int i = 0; i < filas; i++){
            gotoxy(79-j, posY+i);
            Color(matriz[y][i].fondo, matriz[y][i].color);
            printf("%c", matriz[y][i].caracter);
        }
        y++;
    }
}

void mostrarMatrizEditar(int posX, int posY){
    for (int i = COLUMNAS-1; i >= posX; i = i-4){
        modificarHospedaje(i, posY, COLUMNAS-i);
    }
    modificarHospedaje(posX, posY, COLUMNAS-1);
}

void mostrarHotelElegido(int posicionLista, stHospedaje hotel){
    int posY = 0;
    int hastaDondeSubir = 0;
    switch (posicionLista){
        case 1:
            posY = 8;
            hastaDondeSubir = 4;
            break;
        case 2:
            posY = 12;
            hastaDondeSubir = 8;
            break;
        case 3:
            posY = 16;
            hastaDondeSubir = 12;
            break;
        case 4:
            posY = 20;
            hastaDondeSubir = 16;
            break;
    }
    mostrarMatrizHotelVacia(0, posY); // 8, 12, 16, 20
    mostrarHotel(hotel, 0, 0, posY+1);
    for (int i = 0; i <= hastaDondeSubir; i++){
        mostrarMatrizHotelVacia(0, posY-i);
        mostrarHotel(hotel, 0, 0, posY+1-i);
        Color(0,0);
        if (i < hastaDondeSubir){
            for (int j = 0; j <76; j++){
                gotoxy(0+j, posY+3-i);
                printf(" ");
            }
        }
        Sleep(5);
    }

}

void limpiarVentanaHotelesAdmin(int cantidadFiltrado){
    if (cantidadFiltrado > 0){
        selectHotelFromListAdmin(0, AMARILLO);
    } else{
        selectHotelFromListAdmin(0, BLANCO);
    }
    selectHotelFromListAdmin(1, BLANCO);
    selectHotelFromListAdmin(2, BLANCO);
    selectHotelFromListAdmin(3, BLANCO);
    Color(NEGRO,NEGRO);
    for (int i = 2; i < 75; i++ ){
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
        gotoxy(i, 10);
        printf(" ");
        gotoxy(i, 9);
        printf(" ");
    }
}

void adminHoteles(int posicionVista, nodoHospedaje* hotelElegido){
    stHospedaje hotel = hotelElegido->dato;
    mostrarHotelElegido(posicionVista, hotel);
    mostrarMatrizEditar(0,8);
    char tecla = modificarHospedajeSeleccionado(&hotel);
    if (tecla != ESC){
        // Persistir info
        GuardarInfoHotel(archivoHoteles, hotel);
    }
}

void ModificarNombreHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado, stHospedaje* hospedaje){
    do {
        *teclaNuevoHospedaje = ModificarPalabra(hospedajeModificado->name, hospedaje->name, 23, 10, NAME, AMARILLO, NEGRO, BLOCK);
        if (strlen(hospedajeModificado->name) <= 0 && *teclaNuevoHospedaje != ESC){
            MensajesAdvertencias("ESTE CAMPO NO PUEDE ESTAR VACIO.",24,22,ROJO);
        }
    } while (strlen(hospedajeModificado->name) <= 0 && *teclaNuevoHospedaje != ESC);
}

void ModificaTipoHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(15,10);
        Color(NEGRO,AMARILLO);
        printf("NOMBRE:");
        gotoxy(19,13);
        Color(NEGRO,BLANCO);
        printf("TIPO");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case RIGHTARROW:
                switch (hospedajeModificado->type) {
                case 1:
                    gotoxy(28,13);
                    Color(NEGRO, AMARILLO);
                    printf(" HOTEL  ");
                    gotoxy(37,13);
                    Color(ROJO, BLANCO);
                    printf(" HOSTAL  ");
                    break;
                case 2:
                    gotoxy(37,13);
                    Color(NEGRO, AMARILLO);
                    printf(" HOSTAL  ");
                    gotoxy(47,13);
                    Color(ROJO,BLANCO);
                    printf(" DEPARTAMENTO  ");
                    break;
                case 3:
                    gotoxy(47,13);
                    Color(NEGRO, AMARILLO);
                    printf(" DEPARTAMENTO  ");
                    gotoxy(28,13);
                    Color(ROJO,BLANCO);
                    printf(" HOTEL  ");
                    break;
                }
                hospedajeModificado->type++;
                if (hospedajeModificado->type==4){
                    hospedajeModificado->type = 1;
                }
                break;
            case LEFTARROW:
                switch (hospedajeModificado->type) {
                case 1:
                    gotoxy(28,13);
                    Color(NEGRO, AMARILLO);
                    printf(" HOTEL  ");
                    gotoxy(47,13);
                    Color(ROJO, BLANCO);
                    printf(" DEPARTAMENTO  ");
                    break;
                case 2:
                    gotoxy(37,13);
                    Color(NEGRO, AMARILLO);
                    printf(" HOSTAL  ");
                    gotoxy(28,13);
                    Color(ROJO,BLANCO);
                    printf(" HOTEL  ");
                    break;
                case 3:
                    gotoxy(47,13);
                    Color(NEGRO, AMARILLO);
                    printf(" DEPARTAMENTO  ");
                    gotoxy(37,13);
                    Color(ROJO,BLANCO);
                    printf(" HOSTAL  ");
                    break;
                }
                hospedajeModificado->type--;
                if (hospedajeModificado->type==0){
                    hospedajeModificado->type = 3;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void ModificaEstrellasHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(19,13);
        Color(NEGRO,AMARILLO);
        printf("TIPO");
        gotoxy(10,16);
        Color(NEGRO,BLANCO);
        printf("CANTIDAD DE ESTRELLAS:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case RIGHTARROW:
                switch (hospedajeModificado->cantEstrellas) {
                case 1:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                   printf("%c%c", STAR, STAR);
                    break;
                case 2:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                   printf("%c%c%c", STAR, STAR, STAR);
                    break;
                case 3:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                   printf("%c%c%c%c", STAR, STAR, STAR, STAR);
                    break;
                case 4:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c%c%c%c", STAR, STAR, STAR, STAR, STAR);
                    break;
                }
                hospedajeModificado->cantEstrellas++;
                if (hospedajeModificado->cantEstrellas>=5){
                    hospedajeModificado->cantEstrellas = 5;
                }
                break;
            case LEFTARROW:
                switch (hospedajeModificado->cantEstrellas) {
                case 1:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                    printf("%c ", STAR);
                    break;
                case 2:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                    printf("%c ", STAR);
                    break;
                case 3:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c ", STAR, STAR);
                    break;
                case 4:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c%c ", STAR, STAR, STAR);
                    break;
                case 5:
                    gotoxy(33,16);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c%c%c ", STAR, STAR, STAR, STAR);
                    break;
                }
                hospedajeModificado->cantEstrellas--;
                if (hospedajeModificado->cantEstrellas<=1){
                    hospedajeModificado->cantEstrellas = 1;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void ModificaPrecioHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado){
    char precioChar[PRIZE];
    float precioFloat = 0;
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(NO);
        gotoxy(10,16);
        Color(NEGRO,AMARILLO);
        printf("CANTIDAD DE ESTRELLAS:");
        gotoxy(45,16);
        Color(NEGRO,BLANCO);
        printf("PRECIO:");
        do{
            gotoxy(53,16);
            Color(0,0);
            printf("        "); // Borro precio anterior
            *teclaNuevoHospedaje = CapturarPalabra(precioChar, 53, 16, 6, VISIBLE, FULL, AMARILLO);
            precioFloat = atoi(precioChar);
            hospedajeModificado->precio = precioFloat;
        } while (strlen(precioChar) <= 0 && *teclaNuevoHospedaje != ESC);
    }
}

void ModificaWifiHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(45,16);
        Color(NEGRO,AMARILLO);
        printf("PRECIO:");
        gotoxy(15,19);
        Color(NEGRO,BLANCO);
        printf("WIFI:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case 32:
                if (!hospedajeModificado->wifi){
                    gotoxy(21,19);
                    Color(NEGRO, AMARILLO);
                    printf("X");
                    hospedajeModificado->wifi = 1;
                } else {
                    gotoxy(21,19);
                    Color(NEGRO, NEGRO);
                    printf(" ");
                    hospedajeModificado->wifi = 0;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void ModificaPiscinaHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(15,19);
        Color(NEGRO,AMARILLO);
        printf("WIFI:");
        gotoxy(51,19);
        Color(NEGRO,BLANCO);
        printf("PILETA:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case 32:
                if (!hospedajeModificado->pileta){
                    gotoxy(59,19);
                    Color(NEGRO, AMARILLO);
                    printf("X");
                    hospedajeModificado->pileta = 1;
                } else {
                    gotoxy(59,19);
                    Color(NEGRO, NEGRO);
                    printf(" ");
                    hospedajeModificado->pileta = 0;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void ModificaParkingHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeModificado){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(51,19);
        Color(NEGRO,AMARILLO);
        printf("PILETA:");
        gotoxy(15,22);
        Color(NEGRO,BLANCO);
        printf("PARKING:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case 32:
                if (!hospedajeModificado->parking){
                    gotoxy(24,22);
                    Color(NEGRO, AMARILLO);
                    printf("X");
                    hospedajeModificado->parking = 1;
                } else {
                    gotoxy(24,22);
                    Color(NEGRO, NEGRO);
                    printf(" ");
                    hospedajeModificado->parking = 0;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

int modificarHospedajeSeleccionado(stHospedaje* hospedaje){
    hidecursor(NO);
    int barraOpciones = 0;
    int barraBusqueda = 0;
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENULOGIN);
    stHospedaje* hospedajeModificado = hospedaje;


    MostrarInfoAdminHospedaje(hospedaje);
    char teclaNuevoHospedaje = 0;

    ModificarNombreHospedaje(&teclaNuevoHospedaje, hospedajeModificado, hospedaje);
    ModificaTipoHospedaje(&teclaNuevoHospedaje, hospedajeModificado);
    ModificaEstrellasHospedaje(&teclaNuevoHospedaje, hospedajeModificado);
    ModificaPrecioHospedaje(&teclaNuevoHospedaje, hospedajeModificado);
    ModificaWifiHospedaje(&teclaNuevoHospedaje, hospedajeModificado);
    ModificaPiscinaHospedaje(&teclaNuevoHospedaje, hospedajeModificado);
    ModificaParkingHospedaje(&teclaNuevoHospedaje, hospedajeModificado);

    if (hospedajeModificado->precio <= 0){
        hospedajeModificado->precio = hospedaje->precio;
    }

    if (teclaNuevoHospedaje != ESC){
        hospedaje = hospedajeModificado;
    }
    return teclaNuevoHospedaje;
}

nodoHospedaje* agregarHospedajeEnOrdenNombre(nodoHospedaje* lista, nodoHospedaje* nuevo) {

   if(lista == NULL) {
      lista = nuevo;
   }else {

      if(strcmp(nuevo->dato.name,lista->dato.name)<0){
         lista = agregarNodoPpioHoteles(lista, nuevo);
      } else {
         // se puede recorrer la lista utilizando un solo puntero??
         nodoHospedaje* ante = lista;
         nodoHospedaje* seg = lista->siguiente;
         while((seg != NULL) &&(strcmp(nuevo->dato.name,seg->dato.name)>0)) {
            ante = seg;
            seg = seg->siguiente;
         }
         ante->siguiente = nuevo;
         nuevo->anterior = ante;
         nuevo->siguiente = seg;
         if (seg!=NULL)
             seg->anterior=nuevo;
      }
   }
   return lista;
}

nodoHospedaje* agregarHospedajeEnOrdenPrecio(nodoHospedaje* lista, nodoHospedaje* nuevo) {

   if(lista == NULL) {
      lista = nuevo;
   }else {
      if(nuevo->dato.precio < lista->dato.precio){
         lista = agregarNodoPpioHoteles(lista, nuevo);
      } else {
         // se puede recorrer la lista utilizando un solo puntero??
         nodoHospedaje* ante = lista;
         nodoHospedaje* seg = lista->siguiente;
         while((seg != NULL) &&(nuevo->dato.precio > seg->dato.precio)) {
            ante = seg;
            seg = seg->siguiente;
         }
         ante->siguiente = nuevo;
         nuevo->anterior = ante;
         nuevo->siguiente = seg;
         if (seg!=NULL)
             seg->anterior=nuevo;
      }
   }
   return lista;
}

nodoHospedaje* ordenarListaHospedajes(nodoHospedaje* primeroLista, int* cantidadFiltrado, int tipoOrden){
    int validos = 0;
    nodoHospedaje* listaOrdenada = inicListaHoteles();
    nodoHospedaje* iterador = primeroLista;
    while (iterador != NULL){
        if (tipoOrden == NOMBRE){
            listaOrdenada = agregarHospedajeEnOrdenNombre(listaOrdenada, crearNodoHoteles(iterador->dato));
        } else {
            listaOrdenada = agregarHospedajeEnOrdenPrecio(listaOrdenada, crearNodoHoteles(iterador->dato));
        }
        validos++;
        iterador = iterador->siguiente;
    }
    *cantidadFiltrado = validos;
    return listaOrdenada;
}

void darDeBaja_AltaHotel(nodoHospedaje* hotel){
    if(hotel->dato.active==1){
        hotel->dato.active=0;
    }else{
        hotel->dato.active=1;
    }
}

void selectHotelFromListAdmin(int posicion, int colorLetra){
    Color(0, colorLetra);
    gotoxy(1, 8 + posicion * 4);
    printf("%c", TOPLEFT);
    gotoxy(1, 9 + posicion * 4);
    printf("%c", BORDER);
    gotoxy(1, 10 + posicion * 4);
    printf("%c", BORDER);
    gotoxy(1, 11 + posicion * 4);
    printf("%c", BOTTOMLEFT);
    gotoxy(75, 8 + posicion * 4);
    printf("%c", TOPRIGHT);
    gotoxy(75, 9 + posicion * 4);
    printf("%c", BORDER);
    gotoxy(75, 10 + posicion * 4);
    printf("%c", BORDER);
    gotoxy(75, 11 + posicion * 4);
    printf("%c", BOTTOMRIGHT);
    for (int i = 1; i < 74; i++){
        gotoxy(1+i, 8 + posicion * 4);
        printf("%c", LINE);
        gotoxy(1+i, 11 + posicion * 4);
        printf("%c", LINE);
    }

}

nodoHospedaje* mostrarCuatroHoteles(nodoHospedaje* listaHoteles) {
    int i = 0;
    nodoHospedaje* iterador = listaHoteles;
    while (iterador != NULL && i <= 12){
        mostrarHotel(iterador->dato, NOFAV, NORESERVA, 9+i); /// FUNCION EN HOTELES.C
        iterador = iterador->siguiente;
        i += 4;
    }
    return iterador;
}

void IngresarNombreHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeAux){
    do {
        gotoxy(15,7);
        Color(NEGRO,BLANCO);
        printf("NOMBRE:");
        *teclaNuevoHospedaje = CapturarPalabra(hospedajeAux->name, 23, 7, NAME, VISIBLE, FULL, AMARILLO);
        if (strlen(hospedajeAux->name) <= 0 && *teclaNuevoHospedaje != ESC){
            MensajesAdvertencias("ESTE CAMPO NO PUEDE ESTAR VACIO.",24,22,ROJO);
        }
    } while (strlen(hospedajeAux->name) <= 0 && *teclaNuevoHospedaje != ESC);
}

void IngresarTipoHospedaje(char* teclaNuevoHospedaje, int* tipoAlojamiento){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(15,7);
        Color(NEGRO, AMARILLO);
        printf("NOMBRE:");
        gotoxy(19,10);
        Color(NEGRO, BLANCO);
        printf("TIPO");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case RIGHTARROW:
                switch (*tipoAlojamiento) {
                case 1:
                    gotoxy(28,10);
                    Color(NEGRO, AMARILLO);
                    printf(" HOTEL  ");
                    gotoxy(37,10);
                    Color(ROJO, BLANCO);
                    printf(" HOSTAL  ");
                    break;
                case 2:
                    gotoxy(37,10);
                    Color(NEGRO, AMARILLO);
                    printf(" HOSTAL  ");
                    gotoxy(47,10);
                    Color(ROJO,BLANCO);
                    printf(" DEPARTAMENTO  ");
                    break;
                case 3:
                    gotoxy(47,10);
                    Color(NEGRO, AMARILLO);
                    printf(" DEPARTAMENTO  ");
                    gotoxy(28,10);
                    Color(ROJO,BLANCO);
                    printf(" HOTEL  ");
                    break;
                }
                (*tipoAlojamiento)++;
                if (*tipoAlojamiento==4){
                    *tipoAlojamiento = 1;
                }
                break;
            case LEFTARROW:
                switch (*tipoAlojamiento) {
                case 1:
                    gotoxy(28,10);
                    Color(NEGRO, AMARILLO);
                    printf(" HOTEL  ");
                    gotoxy(47,10);
                    Color(ROJO, BLANCO);
                    printf(" DEPARTAMENTO  ");
                    break;
                case 2:
                    gotoxy(37,10);
                    Color(NEGRO, AMARILLO);
                    printf(" HOSTAL  ");
                    gotoxy(28,10);
                    Color(ROJO,BLANCO);
                    printf(" HOTEL  ");
                    break;
                case 3:
                    gotoxy(47,10);
                    Color(NEGRO, AMARILLO);
                    printf(" DEPARTAMENTO  ");
                    gotoxy(37,10);
                    Color(ROJO,BLANCO);
                    printf(" HOSTAL  ");
                    break;
                }
                (*tipoAlojamiento)--;
                if (*tipoAlojamiento==0){
                    *tipoAlojamiento = 3;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void IngresarEstrellasHospedaje(char* teclaNuevoHospedaje, int* cantidadEstrellas){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(19,10);
        Color(NEGRO, AMARILLO);
        printf("TIPO");
        gotoxy(10,13);
        Color(NEGRO, BLANCO);
        printf("CANTIDAD DE ESTRELLAS:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case RIGHTARROW:
                switch (*cantidadEstrellas) {
                case 1:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                   printf("%c%c", STAR, STAR);
                    break;
                case 2:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                   printf("%c%c%c", STAR, STAR, STAR);
                    break;
                case 3:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                   printf("%c%c%c%c", STAR, STAR, STAR, STAR);
                    break;
                case 4:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c%c%c%c", STAR, STAR, STAR, STAR, STAR);
                    break;
                }
                (*cantidadEstrellas)++;
                if (*cantidadEstrellas>=5){
                    *cantidadEstrellas = 5;
                }
                break;
            case LEFTARROW:
                switch (*cantidadEstrellas) {
                case 1:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                    printf("%c ", STAR);
                    break;
                case 2:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                    printf("%c ", STAR);
                    break;
                case 3:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c ", STAR, STAR);
                    break;
                case 4:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c%c ", STAR, STAR, STAR);
                    break;
                case 5:
                    gotoxy(33,13);
                    Color(NEGRO, AMARILLO);
                    printf("%c%c%c%c ", STAR, STAR, STAR, STAR);
                    break;
                }
                (*cantidadEstrellas)--;
                if (*cantidadEstrellas<=1){
                    *cantidadEstrellas = 1;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void IngresarPrecioHospedaje(char* teclaNuevoHospedaje, stHospedaje* hospedajeAux){
    char precioChar[15];
    float precioFloat = 0;
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(NO);
        gotoxy(10,13);
        Color(NEGRO,AMARILLO);
        printf("CANTIDAD DE ESTRELLAS:");
        gotoxy(45,13);
        Color(NEGRO,BLANCO);
        printf("PRECIO:");
        do{
            *teclaNuevoHospedaje = CapturarPalabra(precioChar, 53, 13, 6, VISIBLE, FULL, AMARILLO);
            precioFloat = atoi(precioChar);
            hospedajeAux->precio = precioFloat;
            if (*teclaNuevoHospedaje != ESC && precioFloat == 0){
                MensajesAdvertencias("SE USARA PRECIO $0.",24,22,4);
                gotoxy(53,13);
                Color(NEGRO, AMARILLO);
                printf("  0.00");
            }
        } while (strlen(precioChar) <= 0 && *teclaNuevoHospedaje != ESC && precioFloat < 0);
    }
}

void IngresarWifiHospedaje(char* teclaNuevoHospedaje, int* wifi){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(45,13);
        Color(NEGRO,AMARILLO);
        printf("PRECIO:");
        gotoxy(15,16);
        Color(NEGRO,BLANCO);
        printf("WIFI:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case 32:
                if (!(*wifi)){
                    gotoxy(21,16);
                    Color(NEGRO, AMARILLO);
                    printf("X");
                    *wifi = 1;
                } else {
                    gotoxy(21,16);
                    Color(NEGRO, NEGRO);
                    printf(" ");
                    *wifi = 0;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void IngresarPiscinaHospedaje(char* teclaNuevoHospedaje, int* pileta){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(15,16);
        Color(NEGRO,AMARILLO);
        printf("WIFI:");
        gotoxy(51,16);
        Color(NEGRO,BLANCO);
        printf("PILETA:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case 32:
                if (!(*pileta)){
                    gotoxy(59,16);
                    Color(NEGRO, AMARILLO);
                    printf("X");
                    *pileta = 1;
                } else {
                    gotoxy(59,16);
                    Color(NEGRO, NEGRO);
                    printf(" ");
                    *pileta = 0;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void IngresarParkingHospedaje(char* teclaNuevoHospedaje, int* parking){
    if (*teclaNuevoHospedaje != ESC){
        hidecursor(SI);
        gotoxy(51,16);
        Color(NEGRO,AMARILLO);
        printf("PILETA:");
        gotoxy(15,19);
        Color(NEGRO,BLANCO);
        printf("PARKING:");
        do{
            fflush(stdin);
            *teclaNuevoHospedaje = getch();
            switch(*teclaNuevoHospedaje)
            {
            case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
                break;
            case 32:
                if (!(*parking)){
                    gotoxy(24,19);
                    Color(NEGRO, AMARILLO);
                    printf("X");
                    *parking = 1;
                } else {
                    gotoxy(24,19);
                    Color(NEGRO, NEGRO);
                    printf(" ");
                    *parking = 0;
                }
                break;
            }
        } while (*teclaNuevoHospedaje != ENTER && *teclaNuevoHospedaje != ESC);
    }
}

void agregarAlojamientoBD(stHospedaje* hospedajeAux){
    hidecursor(NO);

    char teclaNuevoHospedaje = 0;
    int tipoAlojamiento = 1; /// Arranca siendo hotel
    int cantidadEstrellas = 1;
    int barraOpciones = 0;
    int barraBusqueda = 0;

    int wifi = 0;
    int pileta = 0;
    int parking = 0;


    ventanaAgregarHotel();
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUAGREGAHOSPEDAJE); /// MUESTRO BARRA

    IngresarNombreHospedaje(&teclaNuevoHospedaje, hospedajeAux);
    IngresarTipoHospedaje(&teclaNuevoHospedaje, &tipoAlojamiento);
    IngresarEstrellasHospedaje(&teclaNuevoHospedaje, &cantidadEstrellas);
    IngresarPrecioHospedaje(&teclaNuevoHospedaje, hospedajeAux);
    IngresarWifiHospedaje(&teclaNuevoHospedaje, &wifi);
    IngresarPiscinaHospedaje(&teclaNuevoHospedaje, &pileta);
    IngresarParkingHospedaje(&teclaNuevoHospedaje, &parking);

    if (teclaNuevoHospedaje == ESC){
        hospedajeAux->id = -1;
    } else {
        hospedajeAux->id = 0;
        hospedajeAux->puntaje = 0;
        hospedajeAux->active = 1;
        hospedajeAux->type = tipoAlojamiento;
        hospedajeAux->cantEstrellas = cantidadEstrellas;
        hospedajeAux->parking = parking;
        hospedajeAux->pileta = pileta;
        hospedajeAux->wifi = wifi;
    }

    mostrarOcultarBarra(&barraOpciones, &barraBusqueda , MENUAGREGAHOSPEDAJE); /// OCULTO BARRA
}

void administrarHospedaje(){
    int barraOpciones = 0;
    int barraBusqueda = 0;
    int posicionVista = 0;
    int cantidadFiltrado = 0;
    int filtroTipo = 0; /// 0 Todos, 1 hotel, 2 Hostal, 3 dpto
    int wifi = 0; /// 0 sin tilde, 1 con tilde
    int parking = 0; /// 0 sin tilde, 1 con tilde
    int piscina = 0; /// 0 sin tilde, 1 con tilde
    int totalHoteles = 0;
    int posicionSobreLista = 1;


    stHospedaje nuevoHospedaje;
    nodoHospedaje* listaHoteles = inicListaHoteles(); /// TODOS LOS HOTELES
    nodoHospedaje* iterador = inicListaHoteles();     /// ITERADOR
    nodoHospedaje* primeroLista = inicListaHoteles(); /// VA A LLEVAR EL PRIMERO DE LOS VISUALIZADOS
    nodoHospedaje* nodoElegido = inicListaHoteles();

    mostrarVistaAdminHoteles(posicionVista, &barraOpciones, &barraBusqueda);

    listaHoteles = crearListaHoteles(archivoHoteles, &cantidadFiltrado); /// Guardo la lista de hoteles
    totalHoteles = cantidadFiltrado;
    iterador = listaHoteles;
    primeroLista = listaHoteles;
    iterador = mostrarCuatroHoteles(iterador);

    char key;
    do{
        fflush(stdin);
        key = getch();
        switch(key){
        case F1:
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINHOSPEDAJES);
            break;
        case ENTER:
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINHOSPEDAJES);
            adminHoteles(posicionVista+1, obtenerNodoElegido(primeroLista, posicionVista));
            mostrarVistaAdminHoteles(posicionVista, &barraOpciones, &barraBusqueda);
            listaHoteles = crearListaHoteles(archivoHoteles, &cantidadFiltrado); /// Guardo la lista de hoteles
            totalHoteles = cantidadFiltrado;
            iterador = listaHoteles; /// Itera sobre la lista.
            primeroLista = listaHoteles; /// Va a llevar el primero de los 3 visualizados
            iterador = mostrarCuatroHoteles(iterador);
            break;
        case UPARROW:
            if (totalHoteles > 0){
                if (posicionSobreLista > 0){
                    if (posicionVista > 0){ // Solo cambio colores del recuadro
                        selectHotelFromListAdmin(posicionVista, 15);
                        posicionVista--;
                        posicionSobreLista--;
                        selectHotelFromListAdmin(posicionVista, 14);
                    } else { /// Tengo que cambiar los hoteles
                        if (primeroLista->anterior != NULL){
                            posicionSobreLista--;
                            primeroLista = primeroLista->anterior;
                            iterador = mostrarCuatroHoteles(primeroLista);
                        }
                    }
                }
            }
            break;
        case DOWNARROW:
            if (cantidadFiltrado > 0){
                if (posicionSobreLista < cantidadFiltrado){
                    if (posicionVista < 3){ // Solo cambio colores del recuadro
                        selectHotelFromListAdmin(posicionVista, 15);
                        posicionVista++;
                        posicionSobreLista++;
                        selectHotelFromListAdmin(posicionVista, 14);
                    }else{ /// Tengo que cambiar los hoteles
                        if (iterador != NULL){
                            posicionSobreLista++;
                            primeroLista = primeroLista->siguiente;
                            iterador = mostrarCuatroHoteles(primeroLista);
                        }
                    }
                }
            }
            break;
        case F2: // Cambia filtro tipo
            switch (filtroTipo) {
            case 0:
                MarcarTipoHotel();
                break;
            case 1:
                MarcarTipoHostal();
                break;
            case 2:
                MarcarTipoDpto();
                break;
            case 3:
                MarcarTipoTodos();
                break;
            }
            filtroTipo++;
            if (filtroTipo==4){
                filtroTipo = 0;
            }
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            limpiarVentanaHotelesAdmin(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCuatroHoteles(primeroLista);
            selectHotelFromListAdmin(posicionVista, AMARILLO);
            break;
        case F3:
            MarcarDesmarcarPiscinaAdmin(&piscina);
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            limpiarVentanaHotelesAdmin(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCuatroHoteles(primeroLista);
            break;
        case F4:
            MarcarDesmarcarWifiAdmin(&wifi);
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            limpiarVentanaHotelesAdmin(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCuatroHoteles(primeroLista);
			break;
        case F5:
            MarcarDesmarcarParkingAdmin(&parking);
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            limpiarVentanaHotelesAdmin(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCuatroHoteles(primeroLista);
			break;
        case F6:
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = ordenarListaHospedajes(listaHoteles, &cantidadFiltrado, NOMBRE); // Mando primero en la lista porque es la lista filtrada sin recorrido
            limpiarVentanaHotelesAdmin(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCuatroHoteles(iterador);
            selectHotelFromListAdmin(posicionVista, AMARILLO);
			break;
        case F7:
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = ordenarListaHospedajes(listaHoteles, &cantidadFiltrado, PRECIO); // Mando primero en la lista porque es la lista filtrada sin recorrido
            limpiarVentanaHotelesAdmin(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCuatroHoteles(iterador);
            selectHotelFromListAdmin(posicionVista, AMARILLO);
			break;
        case F8:
            nodoElegido = obtenerNodoElegido(primeroLista,posicionVista);
            darDeBaja_AltaHotel(nodoElegido);
            guardarHotel(archivoHoteles, nodoElegido);
            iterador = mostrarCuatroHoteles(primeroLista);
            break;
        case F9:
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda,  MENUBUSQUEDA); // Barra 3 Busqueda desde Hoteles
            /// Me quedo capturando el texto de la barra hasta que le de enter.
            char busqueda[NAME];
            char teclaBusqueda = 0;
            do {
              teclaBusqueda = CapturarPalabra(busqueda, 3, 27, NAME, VISIBLE, RETICULA, BLANCO);
            } while (teclaBusqueda != ESC && teclaBusqueda != ENTER);
            if (teclaBusqueda == ESC){
                strcpy(busqueda, "");
            }
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            /// Filtrar lista de hoteles por nombre
            // Aplico el filtro para tener toda la lista completa nuevamente
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            iterador = filtrarPorNombre(iterador, busqueda, &cantidadFiltrado);
            limpiarVentanaHotelesAdmin(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCuatroHoteles(primeroLista);
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUBUSQUEDA);
            break;
        case F10:
            if(barraOpciones==1 || barraBusqueda==1){
                mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINHOSPEDAJES);
            }
            ocultarIconoMenu();
            agregarAlojamientoBD(&nuevoHospedaje);
            if (nuevoHospedaje.id != -1){
                if (grabarHospedaje(nuevoHospedaje) == 1){
                    Color(NEGRO, BLANCO);
                    MostrarMensaje("ALOJAMIENTO AGREGADO SATISFACTORIAMENTE.");
                    Sleep(100);
                }
            }
            mostrarVistaAdminHoteles(posicionVista, &barraOpciones, &barraBusqueda);

            listaHoteles = crearListaHoteles(archivoHoteles, &cantidadFiltrado); /// Guardo la lista de hoteles
            totalHoteles = cantidadFiltrado;
            iterador = listaHoteles;
            primeroLista = listaHoteles;
            iterador = mostrarCuatroHoteles(iterador);

            break;
        case ESC:
            Color(NEGRO, BLANCO);
            MostrarMensaje("Saliendo...");
            Sleep(100);
            break;
        }
    }while(key!=ESC);

}


/// ADMINISTRAR USUARIO

nodoUsuario* modificarListaUsuarios(nodoUsuario* firstLista, stUsuario usuario){
    nodoUsuario* iterador = firstLista;
    int encontrado = 0;
    while (iterador != NULL && !encontrado){
        if (iterador->dato.id == usuario.id){
            iterador->dato = usuario;
            encontrado = 1;
        }
        iterador = iterador->siguiente;
    }
    return firstLista;
}

int obtenerCoordenadaActivoAdminUsuario(int posicionVista, int opcion){
    int posY;
    if (posicionVista == 0){
        posY = 5;
    } else if (posicionVista == 1){
        posY = 9;
    } else if (posicionVista == 2) {
        posY = 13;
    } else if (posicionVista == 3) {
        posY = 17;
    } else {
        posY = 21;
    }
    if (opcion == 1){
        posY++;
    }
    if (opcion == 3){
        if (posicionVista == 0){
            posY = 13;
        } else if (posicionVista == 1){
            posY = 17;
        } else {
            posY = 21;
        }
    }
    return posY;
}

nodoUsuario* obtenerNodoElegidoUsuario(nodoUsuario* primeroLista, int posicionVista){
    nodoUsuario* nodoElegido = primeroLista; /// Voy a guardar el dato del hotel elegido
    int i = 0;
    while (nodoElegido != NULL && i < posicionVista){
        nodoElegido = nodoElegido->siguiente;
        i++;
    }
    return nodoElegido;
}

nodoUsuario* filtrarPorNombreUsuario(nodoUsuario* listaUsuarios, char busqueda[NAME], int* cantidadFiltrado){
    nodoUsuario* listaFiltrada = inicListaUsuarios();
    nodoUsuario* iterador = listaUsuarios;
    char name[NAME];
    *cantidadFiltrado = 0;
    while (iterador != NULL){
        strcpy(name, iterador->dato.name);
        if (strstr(strlwr(name), strlwr(busqueda)) != NULL){
            *(cantidadFiltrado) +=1;
            listaFiltrada = agregarNodoPpioUsuarios(listaFiltrada, crearNodoUsuario(iterador->dato));
        }
        iterador = iterador->siguiente;
    }
    return listaFiltrada;
}

void limpiarVentanaHotelesAdminByUser(int cantidadFiltrado){
    if (cantidadFiltrado > 0){
        selectHotelFromListAdminByUser(0, AMARILLO);
    } else{
        selectHotelFromListAdminByUser(0, BLANCO);
    }
    selectHotelFromListAdminByUser(1, BLANCO);
    selectHotelFromListAdminByUser(2, BLANCO);
    Color(NEGRO,NEGRO);
    for (int i = 2; i < 75; i++ ){
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

void selectHotelFromListAdminByUser(int posicion, int colorLetra){
    Color(NEGRO, colorLetra);
    gotoxy(1, 12 + posicion * 4);
    printf("%c", 1754);
    gotoxy(1, 13 + posicion * 4);
    printf("%c", 1715);
    gotoxy(1, 14 + posicion * 4);
    printf("%c", 1715);
    gotoxy(1, 15 + posicion * 4);
    printf("%c", 1728);
    gotoxy(75, 12 + posicion * 4);
    printf("%c", 1727);
    gotoxy(75, 13 + posicion * 4);
    printf("%c", 1715);
    gotoxy(75, 14 + posicion * 4);
    printf("%c", 1715);
    gotoxy(75, 15 + posicion * 4);
    printf("%c", 1753);
    for (int i = 1; i < 74; i++){
        gotoxy(1+i, 12 + posicion * 4);
        printf("%c", 1732);
        gotoxy(1+i, 15 + posicion * 4);
        printf("%c", 1732);
    }

}

void mostrarUsuario(stUsuario dato, int posY){
    Color(NEGRO,LCYAN);
    gotoxy(3,posY);
    printf("                                                                      "); /// borro si hay algo escrito
    gotoxy(3,posY+1);
    printf("                                                                      "); /// borro si hay algo escrito
    gotoxy(3,posY);
    printf("%s", dato.name);
    if (!dato.active){
        Color(NEGRO, BROWN);
        gotoxy(65,posY);
        printf("INACTIVO");
    }
    if (dato.administrator){
        Color(NEGRO,LCYAN);
        gotoxy(65,posY+1);
        printf("ADMIN");
    }
    Color(NEGRO,LGREY);
    gotoxy(35, posY);
    printf("Telefono: %s", dato.phone);
    gotoxy(3,posY+1);
    Color(NEGRO, LGREY);
    printf("%s", dato.address);
    Color(NEGRO,LCYAN);
    gotoxy(35,posY+1);
    printf("Mail: %s", dato.mail);
    Color(NEGRO,BLANCO);
}

nodoUsuario* mostrarCincoUsuarios(nodoUsuario* listaUsuarios) {
    int i = 0;
    nodoUsuario* iterador = listaUsuarios;
    while (iterador != NULL && i <= 16){
        mostrarUsuario(iterador->dato, 5+i);
        iterador = iterador->siguiente;
        i += 4;
    }
    return iterador;
}

void limpiarVentanaCincoUsuarios(int cantidadFiltrado){
    if (cantidadFiltrado > 0){
        selectUsuarioFromList(0, AMARILLO);
    } else{
        selectUsuarioFromList(0, BLANCO);
    }
    selectUsuarioFromList(1, BLANCO);
    selectUsuarioFromList(2, BLANCO);
    selectUsuarioFromList(3, BLANCO);
    selectUsuarioFromList(4, BLANCO);
    Color(NEGRO,NEGRO);
    for (int i = 2; i < 75; i++ ){
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
        gotoxy(i, 10);
        printf(" ");
        gotoxy(i, 9);
        printf(" ");
        gotoxy(i, 6);
        printf(" ");
        gotoxy(i, 5);
        printf(" ");
    }
}

nodoUsuario* agregarUsuarioEnOrden(nodoUsuario* lista, nodoUsuario* nuevo) {

   if(lista == NULL) {
      lista = nuevo;
   }else {

      if(strcmp(nuevo->dato.name,lista->dato.name)<0){
         lista = agregarNodoPpioUsuarios(lista, nuevo);
      } else {
         // se puede recorrer la lista utilizando un solo puntero??
         nodoUsuario* ante = lista;
         nodoUsuario* seg = lista->siguiente;
         while((seg != NULL) &&(strcmp(nuevo->dato.name,seg->dato.name)>0)) {
            ante = seg;
            seg = seg->siguiente;
         }
         ante->siguiente = nuevo;
         nuevo->anterior = ante;
         nuevo->siguiente = seg;
         if (seg!=NULL)
             seg->anterior=nuevo;
      }
   }
   return lista;
}

nodoUsuario* ordenarPorNombreListaUsuarios(nodoUsuario* primeroLista, int* cantidadFiltrado){
    int validos = 0;
    nodoUsuario* listaOrdenada = inicListaUsuarios();
    nodoUsuario* iterador = primeroLista;
    while (iterador != NULL){
        listaOrdenada = agregarUsuarioEnOrden(listaOrdenada, crearNodoUsuario(iterador->dato));
        validos++;
        iterador = iterador->siguiente;
    }
    *cantidadFiltrado = validos;
    return listaOrdenada;
}

nodoUsuario* administrarFavoritosReservasUsuario(nodoUsuario* firstLista, int posVista){
    hidecursor(SI);
    nodoUsuario* nodoUsuarioElegido;
    nodoUsuarioElegido = obtenerNodoElegidoUsuario(firstLista, posVista);
    stUsuario usuario = nodoUsuarioElegido->dato;
    mostrarUsuario(usuario, 5);
    int barraOpciones = 0;
    int barraBusqueda = 0;
    char tecla = 0;
    int cantidadFiltrado = 0;
    int posicionSobreLista = 1;
    int posicionVista = 0;
    int huboCambio = 0;
    int posY = 0;

    /// ARMO LA LISTAS Y ARBOLES QUE HACEN REFERENCIA A LOS HOSPEDAJES, FAVORITOS Y RESERVAS
    nodoHospedaje* listaHoteles = inicListaHoteles();
    listaHoteles = crearListaHoteles(archivoHoteles, &cantidadFiltrado); /// Guardo la lista de hoteles
    nodoHospedaje* iterador = listaHoteles; /// Itera sobre la lista.
    nodoHospedaje* primeroLista = listaHoteles; /// Va a llevar el primero de los 3 visualizados

    nodoFavoritos* listaFavoritos = inicListaFavoritos();
    listaFavoritos = crearListaFavoritos(usuario);
    arbolFavoritos* arbolHotelesFavoritos = inicArbolFavoritos();
    arbolHotelesFavoritos = crearArbolFavoritos(listaHoteles, listaFavoritos);

    nodoReservas* listaReservas = inicListaReservas();
    listaReservas = crearListaReservas(usuario);
    arbolReservas* arbolHotelesReservados = inicArbolReservas();
    arbolHotelesReservados = crearArbolReservas(listaHoteles, listaReservas);

    iterador = mostrarTresHoteles(iterador, arbolHotelesFavoritos, arbolHotelesReservados);
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINUSERSFAVYRESERVAS);
    Color(NEGRO, BLANCO);

    selectHotelFromListAdminByUser(posicionVista, AMARILLO);

    nodoHospedaje* nodoElegido;

    do{
        fflush(stdin);
        tecla = getch();
        switch (tecla){
        case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
            break;
        case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
            break;

        case UPARROW:
            if (cantidadFiltrado > 0){
                if (posicionSobreLista > 0){
                    if (posicionVista > 0){ // Solo cambio colores del recuadro
                        selectHotelFromListAdminByUser(posicionVista, BLANCO);
                        posicionVista--;
                        posicionSobreLista--;
                        selectHotelFromListAdminByUser(posicionVista, AMARILLO);
                    } else { /// Tengo que cambiar los hoteles
                        if (primeroLista->anterior != NULL){
                            posicionSobreLista--;
                            primeroLista = primeroLista->anterior;
                            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
                        }
                    }
                }
            }
            break;
        case DOWNARROW:
            if (cantidadFiltrado > 0){
                if (posicionSobreLista < cantidadFiltrado){
                    if (posicionVista < 2){ // Solo cambio colores del recuadro
                        selectHotelFromListAdminByUser(posicionVista, BLANCO);
                        posicionVista++;
                        posicionSobreLista++;
                        selectHotelFromListAdminByUser(posicionVista, AMARILLO);
                    } else { /// Tengo que cambiar los hoteles
                        if (iterador != NULL){
                            posicionSobreLista++;
                            primeroLista = primeroLista->siguiente;
                            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
                        }
                    }
                }
            }
            break;
        case F1: // Oculta o muestra la barra
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINUSERSFAVYRESERVAS); // Barra 2 Hoteles
            break;

        case ENTER:
            huboCambio = profileModification(&usuario);
            if (huboCambio){ /// Si cambie algo en el perfil creo lista nueva
                firstLista = modificarListaUsuarios(firstLista, usuario);
            }
            system("cls");
            ventanaEditUserByAdmin();
            mostrarUsuario(usuario, 5);
            selectHotelFromListAdminByUser(posicionVista, AMARILLO);
            Color(NEGRO,BLANCO);
            iterador = listaHoteles;
            iterador = mostrarTresHoteles(iterador, arbolHotelesFavoritos, arbolHotelesReservados);
            if (barraOpciones == 1){
                mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);
            }
            barraOpciones = 0;
            barraBusqueda = 0;

            break;
        case F6:
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = ordenarListaHospedajes(primeroLista, &cantidadFiltrado, NOMBRE); // Mando primero en la lista porque es la lista filtrada sin recorrido, el ultimo parametro es la forma de ordenar
            limpiarVentanaHotelesAdminByUser(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarTresHoteles(iterador, arbolHotelesFavoritos, arbolHotelesReservados);
            selectHotelFromListAdminByUser(posicionVista, AMARILLO);
            break;
        case F7:
            /// Marcar como Favorito.
            nodoElegido = obtenerNodoElegido(primeroLista, posicionVista);
            /// Lo busco en el arbolFavoritos
            int esFavorito = buscarFavoritoArbol(nodoElegido->dato.id, arbolHotelesFavoritos);
            posY = obtenerCoordenadaActivoAdminUsuario(posicionVista, 3);
            ModificarFavoritosEnVista(esFavorito, posY);
            /// Cambiar estado en el arbolHotelesFavoritos
            arbolHotelesFavoritos = cambiarEstadoFavorito(arbolHotelesFavoritos, nodoElegido->dato.id);
            break;
        case F8:
            nodoElegido = obtenerNodoElegido(primeroLista, posicionVista);
            /// Lo busco en el arbolFavoritos
            int estaReservado = buscarReservaArbol(nodoElegido->dato.id, arbolHotelesReservados);
            posY = obtenerCoordenadaActivoAdminUsuario(posicionVista, 3);
            ModificarReservaEnVista(estaReservado, posY);
            /// Cambiar estado en el arbolHotelesReservados
            arbolHotelesReservados = cambiarEstadoReserva(arbolHotelesReservados, nodoElegido->dato.id);
			break;
        case F9:
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda,  MENUBUSQUEDA); // Barra 3 Busqueda desde Hoteles
            /// Me quedo capturando el texto de la barra hasta que le de enter.
            char busqueda[NAME];
            char teclaBusqueda = 0;
            do {
              teclaBusqueda = CapturarPalabra(busqueda, 3, 27, NAME, VISIBLE, RETICULA, BLANCO);
            } while (teclaBusqueda != ESC && teclaBusqueda != ENTER);
            if (teclaBusqueda == ESC){
                strcpy(busqueda, "");
            }
            /// Filtrar lista de hoteles por nombre
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = filtrarPorNombre(listaHoteles, busqueda, &cantidadFiltrado);
            primeroLista = iterador;
            limpiarVentanaHotelesAdminByUser(cantidadFiltrado);
            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUBUSQUEDA);
            break;

        case ESC:
            /// Guardar informacion
            Color(NEGRO, BLANCO);
            MostrarMensaje("Guardando datos...");

            nodoFavoritos* listaFinalFavoritos = inicListaFavoritos();
            listaFinalFavoritos = pasarArbolFavToListaFav(listaFinalFavoritos, arbolHotelesFavoritos);
            grabarFavoritosArchivo(usuario, listaFinalFavoritos);

            nodoReservas* listaFinalReservas = inicListaReservas();
            listaFinalReservas = pasarArbolReservasToListaReservas(listaFinalReservas, arbolHotelesReservados);
            grabarReservasArchivo(usuario, listaFinalReservas);

            break;
        }
    } while (tecla != ESC);
    return firstLista; /// DEVULEVO LA LISTA DE USUARIOS POR SI MODIFIQUE EL PERFIL
}

void administrarUsuarios(){
    hidecursor(0);
    int barraOpciones = 0;
    int barraBusqueda = 0;
    char key = 0;
    int posicionVista = 0; /// Va a varia entre 0 y 2 por las 3 posiciones en la ventana
    int cantidadFiltrado = 0; /// Cuantos USUARIOS tengo para mostrar
    int posicionSobreLista = 1;
    int posY = 0;
    nodoUsuario* listaUsuarios = inicListaUsuarios();
    listaUsuarios = crearListaUsuarios(archivoUsuarios, &cantidadFiltrado);

    nodoUsuario* iterador = listaUsuarios; /// Itera sobre la lista.
    nodoUsuario* primeroLista = listaUsuarios; /// Va a llevar el primero de los 5 visualizados
    nodoUsuario* nodoElegido;

    ventanaAdminUsuarios();
    iterador = mostrarCincoUsuarios(iterador);
    selectUsuarioFromList(posicionVista, AMARILLO);
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINUSERS);


    do{
        fflush(stdin);
        key = getch();
        switch(key)
        {
        case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
            break;
        case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
            break;

        case UPARROW:
            if (cantidadFiltrado > 0){
                if (posicionSobreLista > 0){
                    if (posicionVista > 0){ // Solo cambio colores del recuadro
                        selectUsuarioFromList(posicionVista, BLANCO);
                        posicionVista--;
                        posicionSobreLista--;
                        selectUsuarioFromList(posicionVista, AMARILLO);
                    } else { /// Tengo que cambiar los hoteles
                        if (primeroLista->anterior != NULL){
                            posicionSobreLista--;
                            primeroLista = primeroLista->anterior;
                            iterador = mostrarCincoUsuarios(primeroLista);
                        }
                    }
                }
            }
            break;
        case DOWNARROW:
            if (cantidadFiltrado > 0){
                if (posicionSobreLista < cantidadFiltrado){
                    if (posicionVista < 4){ // Solo cambio colores del recuadro
                        selectUsuarioFromList(posicionVista, BLANCO);
                        posicionVista++;
                        posicionSobreLista++;
                        selectUsuarioFromList(posicionVista, AMARILLO);
                    } else { /// Tengo que cambiar los hoteles
                        if (iterador != NULL){
                            posicionSobreLista++;
                            primeroLista = primeroLista->siguiente;
                            iterador = mostrarCincoUsuarios(primeroLista);
                        }
                    }
                }
            }
            break;
        case F1: // Oculta o muestra la barra
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINUSERS);
            break;
        case ENTER: // EDITAR
            system("cls");
            ventanaEditUserByAdmin();
            administrarFavoritosReservasUsuario(primeroLista, posicionVista);
            ventanaAdminUsuarios();
            iterador = mostrarCincoUsuarios(listaUsuarios);
            selectUsuarioFromList(posicionVista, AMARILLO);
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINUSERS);
            break;
        case F6: // ORDENAR
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = ordenarPorNombreListaUsuarios(listaUsuarios, &cantidadFiltrado); // Mando primero en la lista porque es la lista filtrada sin recorrido
            limpiarVentanaCincoUsuarios(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCincoUsuarios(iterador);
            selectUsuarioFromList(posicionVista, AMARILLO);
            break;
        case F7: // ACTIVO
            nodoElegido = obtenerNodoElegidoUsuario(primeroLista, posicionVista);
            posY = obtenerCoordenadaActivoAdminUsuario(posicionVista, 0);
            ModificarActivoVista(posY, nodoElegido);
            break;
        case F8: // ADMIN
            nodoElegido = obtenerNodoElegidoUsuario(primeroLista, posicionVista);
            posY = obtenerCoordenadaActivoAdminUsuario(posicionVista, 1);
            ModificarAdminVista(posY, nodoElegido);
            break;
        case F9: // BUSQUEDA
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda,  MENUBUSQUEDA); // Barra 3 Busqueda desde Hoteles
            /// Me quedo capturando el texto de la barra hasta que le de enter.
            char busqueda[NAME];
            char teclaBusqueda = 0;
            do {
              teclaBusqueda = CapturarPalabra(busqueda, 3, 27, NAME, VISIBLE, RETICULA, BLANCO);
            } while (teclaBusqueda != ESC && teclaBusqueda != ENTER);
            if (teclaBusqueda == ESC){
                strcpy(busqueda, "");
            }
            /// Filtrar lista de hoteles por nombre
            // Aplico el filtro para tener toda la lista completa nuevamente
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = filtrarPorNombreUsuario(listaUsuarios, busqueda, &cantidadFiltrado);
            limpiarVentanaCincoUsuarios(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarCincoUsuarios(primeroLista);
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUBUSQUEDA);
            break;
        case ESC: /// SALIR
            /// PERSISTIR CAMBIOS
            Color(NEGRO, BLANCO);
            MostrarMensaje("Guardando datos...");
            grabarUsuariosArchivo(listaUsuarios);
            break;
        }
    }
    while (key != ESC);
}

/// ENTRADA DE FUNCIONES

void administrador(){
    ventanaAdministrador();
    int barraOpciones = 0;
    int barraBusqueda = 0;
    hidecursor(0);
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINISTRADOR); // Barra 5 ADMIN
    char key;
    do{
        fflush(stdin);
        key = getch();
        switch(key)
        {
        case 0: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
            break;
        case -32: // SE CAPTURA PARA RESOLVER FALLA EN ALGUNOS TECLADOS
            break;
        case F1: // Oculta o muestra la barra
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINISTRADOR);
            break;
        case UNO: // ADMINISTRAR USUARIOS
            system("cls");
            administrarUsuarios();
            ventanaAdministrador();
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINISTRADOR);
            break;
        case DOS: // ADMINISTRAR HOTELES
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINISTRADOR);
            administrarHospedaje();
            ventanaAdministrador();
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUADMINISTRADOR);
            break;
        case ESC: /// SALIR
            break;
        }
    }
    while (key != ESC);

}
