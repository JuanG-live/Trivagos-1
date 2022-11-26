#include "hoteles.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int esHotelFavorito(int idHotel, nodoFavoritos* listaFavoritos){
    int notFound = 0;
    nodoFavoritos* iterador = listaFavoritos;
    while (iterador != NULL && notFound==0){
        if (iterador->idHotel == idHotel){
            notFound = 1;
        }
        iterador = iterador->siguiente;
    }
    return notFound;
}

int esHotelReservado(int idHotel, nodoReservas* listaReservas, stReserva* dato){
    int notFound = 0;
    nodoReservas* iterador = listaReservas;
    while (iterador != NULL && notFound==0){
        if (iterador->dato.idHotel == idHotel){
            notFound = 1;
            dato->idHotel = idHotel;
            dato->precio = iterador->dato.precio;
        }
        iterador = iterador->siguiente;
    }
    return notFound;
}

nodoHospedaje* mostrarTresHoteles(nodoHospedaje* listaHoteles, arbolFavoritos* favoritos, arbolReservas* reservas) {
    int i = 0;
    nodoHospedaje* iterador = listaHoteles;
    while (iterador != NULL && i <= POSICIONTERCERHOTEL){
        mostrarHotel(iterador->dato, buscarFavoritoArbol(iterador->dato.id, favoritos), buscarReservaArbol(iterador->dato.id, reservas), 13+i);
        iterador = iterador->siguiente;
        i += 4;
    }
    return iterador;
}

nodoHospedaje* aplicarFiltroTipo(nodoHospedaje* listaHoteles, int filtroTipo, int* cantidadFiltrado){
    nodoHospedaje* iterador = listaHoteles;
    nodoHospedaje* listaFiltrada = inicListaHoteles();
    while (iterador != NULL){
        if (iterador->dato.type == filtroTipo){
            listaFiltrada = agregarNodoPpioHoteles(listaFiltrada, crearNodoHoteles(iterador->dato));
            *cantidadFiltrado +=1;
        }
        iterador = iterador->siguiente;
    }
    return listaFiltrada;
}

nodoHospedaje* aplicarFiltroWifi(nodoHospedaje* listaHoteles, int* cantidadFiltrado){
    nodoHospedaje* nuevaListaFiltrada = inicListaHoteles();
    *cantidadFiltrado = 0;
    while (listaHoteles != NULL){
        if (listaHoteles->dato.wifi == 1){
            *(cantidadFiltrado) += 1;
            nuevaListaFiltrada = agregarNodoPpioHoteles(nuevaListaFiltrada, crearNodoHoteles(listaHoteles->dato));
        }
        listaHoteles = listaHoteles->siguiente;
    }
    return nuevaListaFiltrada;
}

nodoHospedaje* aplicarFiltroPiscina(nodoHospedaje* listaHoteles, int* cantidadFiltrado){
    nodoHospedaje* nuevaListaFiltrada = inicListaHoteles();
    *cantidadFiltrado = 0;
    while (listaHoteles != NULL){
        if (listaHoteles->dato.pileta == 1){
            *(cantidadFiltrado) += 1;
            nuevaListaFiltrada = agregarNodoPpioHoteles(nuevaListaFiltrada, crearNodoHoteles(listaHoteles->dato));
        }
        listaHoteles = listaHoteles->siguiente;
    }
    return nuevaListaFiltrada;
}

nodoHospedaje* aplicarFiltroParking(nodoHospedaje* listaHoteles, int* cantidadFiltrado){
    nodoHospedaje* nuevaListaFiltrada = inicListaHoteles();
    *cantidadFiltrado = 0;
    while (listaHoteles != NULL){
        if (listaHoteles->dato.parking == 1){
            *(cantidadFiltrado) += 1;
            nuevaListaFiltrada = agregarNodoPpioHoteles(nuevaListaFiltrada, crearNodoHoteles(listaHoteles->dato));
        }
        listaHoteles = listaHoteles->siguiente;
    }
    return nuevaListaFiltrada;
}

nodoHospedaje* filtrarPorNombre(nodoHospedaje* listaHoteles, char busqueda[NAME], int* cantidadFiltrado){
    nodoHospedaje* listaFiltrada = inicListaHoteles();
    nodoHospedaje* iterador = listaHoteles;
    char name[NAME];
    *cantidadFiltrado = 0;
    while (iterador != NULL){
        strcpy(name, iterador->dato.name);
        if (strstr(strlwr(name), strlwr(busqueda)) != NULL){
            *(cantidadFiltrado) +=1;
            listaFiltrada = agregarNodoPpioHoteles(listaFiltrada, crearNodoHoteles(iterador->dato));
        }
        iterador = iterador->siguiente;
    }
    return listaFiltrada;
}

nodoHospedaje* aplicarFiltro(nodoHospedaje* listaHoteles, int filtroTipo, int wifi, int piscina, int parking, int* cantidadFiltrado, int totalHoteles){
    nodoHospedaje* listaFiltrada = inicListaHoteles();
    if (filtroTipo > 0){
        listaFiltrada = aplicarFiltroTipo(listaHoteles, filtroTipo, cantidadFiltrado); /// Devuelvo todos los que sean del tipo
    } else {
        /// Volver a poner cantidadFiltrado en el total
        *cantidadFiltrado = totalHoteles;
        listaFiltrada = listaHoteles; /// Sino completa
    }
    /// Ya aplique el filtro principal, ahora el resto wifi, piscina y parking
    if (wifi > 0){
        listaFiltrada = aplicarFiltroWifi(listaFiltrada, cantidadFiltrado);
    }
    if (piscina > 0){
        listaFiltrada = aplicarFiltroPiscina(listaFiltrada, cantidadFiltrado);
    }
    if (parking > 0){
        listaFiltrada = aplicarFiltroParking(listaFiltrada, cantidadFiltrado);
    }

    return listaFiltrada;
}

nodoFavoritos* pasarArbolFavToListaFav(nodoFavoritos* listaFinalFavoritos, arbolFavoritos* arbolHotelesFavoritos){
    if(arbolHotelesFavoritos != NULL){
        listaFinalFavoritos = pasarArbolFavToListaFav(listaFinalFavoritos, arbolHotelesFavoritos->izquierda);
        if (arbolHotelesFavoritos->esFavorito == 1){
            listaFinalFavoritos = agregarNodoPpioFavoritos(listaFinalFavoritos, crearNodoFavoritos(arbolHotelesFavoritos->idHotel));
        }
        listaFinalFavoritos = pasarArbolFavToListaFav(listaFinalFavoritos, arbolHotelesFavoritos->derecha);
    }
    return listaFinalFavoritos;
}

nodoReservas* pasarArbolReservasToListaReservas(nodoReservas* listaFinalReservas, arbolReservas* arbolHotelesReservados){
    if(arbolHotelesReservados != NULL){
        listaFinalReservas = pasarArbolReservasToListaReservas(listaFinalReservas, arbolHotelesReservados->izquierda);
        if (arbolHotelesReservados->estaReservado == 1){
            listaFinalReservas = agregarNodoPpioReservas(listaFinalReservas, crearNodoReservas(arbolHotelesReservados->dato));
        }
        listaFinalReservas = pasarArbolReservasToListaReservas(listaFinalReservas, arbolHotelesReservados->derecha);
    }
    return listaFinalReservas;
}

nodoHospedaje* obtenerNodoElegido(nodoHospedaje* primeroLista, int posicionVista){
    nodoHospedaje* nodoElegido = primeroLista; /// Voy a guardar el dato del hotel elegido
    int i = 0;
    while (nodoElegido != NULL && i < posicionVista){
        nodoElegido = nodoElegido->siguiente;
        i++;
    }
    return nodoElegido;
}

int puntuarHotel(int yaVoto, int respuesta){
    mostrarVentanaVotar(yaVoto,respuesta);
    Color(NEGRO, AMARILLO);
    gotoxy(37,15);
    printf("%i", respuesta);
    int valorAnterior = respuesta;
    char key;
    do{
        fflush(stdin);
        key = getch();
        switch (key){
            case '-':
                if (respuesta > 0){
                    respuesta--;
                    gotoxy(37,15);
                    if (respuesta < 10){
                        printf("%i ", respuesta);
                    } else {
                        printf("%i", respuesta);
                    }
                }
                break;
            case '+':
                if (respuesta < 10){
                    respuesta++;
                    gotoxy(37,15);
                    if (respuesta < 10){
                        printf("%i ", respuesta);
                    } else {
                        printf("%i", respuesta);
                    }
                }
                break;
        }
    } while (key != ESC && key != ENTER);
    return respuesta;
}

void AgregaModificaVotoArchivo(int idHotel, int idUsuario, int nuevoVoto, int tipo){
    stPuntos puntosNuevos;
    puntosNuevos.idHotel = idHotel;
    puntosNuevos.idUsuario = idUsuario;
    puntosNuevos.voto = nuevoVoto;
    if (tipo == MODIFICA){
        modificarVotacion(archivoPuntajes, puntosNuevos);
    } else {
        agregarVotacion(archivoPuntajes, puntosNuevos);
    }
}

float verificarSiUsuarioVoto(nodoListaOfListaPuntajes* listaPuntajes, int idUsuario, int idHotel){
    float promedioHospedaje = 0;
    int cantidadVotos = 0;
    int sumaVotos = 0;
    int respuesta = 0;
    int nuevoVoto = 0;
    int yaVoto = 0;
    int hotelVotado = 0;
    if (listaPuntajes != NULL){
        nodoListaOfListaPuntajes* iterador = listaPuntajes;
        while (iterador != NULL){
            if (iterador->idHotel == idHotel){
                hotelVotado = 1;
                if (iterador->votos != NULL){
                    nodoVoto* iteradorVotos = iterador->votos;
                    while (iteradorVotos != NULL){
                        cantidadVotos++;
                        respuesta = iteradorVotos->voto;
                        if (iteradorVotos->idUsuario == idUsuario && yaVoto == 0){
                            /// Encontre y se que voto
                            yaVoto = 1;
                            nuevoVoto = puntuarHotel(yaVoto, respuesta);
                            if (nuevoVoto != respuesta && nuevoVoto != 0){ /// Si cambio el voto y no puso 0
                                iteradorVotos->voto = nuevoVoto;
                                /// Persistir modificando registro
                                AgregaModificaVotoArchivo(idHotel,idUsuario,nuevoVoto,MODIFICA);
                                respuesta = nuevoVoto;
                            }
                        }
                        sumaVotos += respuesta;
                        iteradorVotos = iteradorVotos->siguiente;
                    }
                    if (yaVoto == 0){ /// Recorri toda la lista y no estaba el voto del usuario para ese Hospedaje
                        nuevoVoto = puntuarHotel(yaVoto, 0);
                        if (nuevoVoto != 0){ /// Si volvio 0 no es considerado voto
                            iterador->votos = agregarNodoPpioVotos(iterador->votos, crearNodoVoto(idUsuario, nuevoVoto));
                            yaVoto = 1;
                            /// Persistir agregando registro de la votacion
                            AgregaModificaVotoArchivo(idHotel,idUsuario,nuevoVoto, CREA);
                            sumaVotos += nuevoVoto;
                            cantidadVotos++;
                        }
                    }
                }
            }
            iterador = iterador->siguiente;
        }
        if (hotelVotado == 0){ /// EL hotel no esta en la lista de listas, creo el hotel y pido que puntuen
            nuevoVoto = puntuarHotel(yaVoto, respuesta);
            if (nuevoVoto != 0){
                listaPuntajes = agregarNodoPpioListaOfListaPuntajes(listaPuntajes, crearNodoPuntajes(idHotel));
                listaPuntajes->votos = agregarNodoPpioVotos(listaPuntajes->votos, crearNodoVoto(idUsuario, nuevoVoto));
                /// Persistir agregando registro de la votacion
                AgregaModificaVotoArchivo(idHotel,idUsuario,nuevoVoto, CREA);
                sumaVotos = nuevoVoto;
                cantidadVotos = 1;
            }
        }
    } else { /// No hay ningun voto, cargo el primer hotel
        nuevoVoto = puntuarHotel(yaVoto, respuesta);
        if (nuevoVoto != 0){
            listaPuntajes = agregarNodoPpioListaOfListaPuntajes(listaPuntajes, crearNodoPuntajes(idHotel));
            listaPuntajes->votos = agregarNodoPpioVotos(listaPuntajes->votos, crearNodoVoto(idUsuario, nuevoVoto));
            /// Persistir agregando registro de la votacion
            AgregaModificaVotoArchivo(idHotel,idUsuario,nuevoVoto, CREA);
            sumaVotos = nuevoVoto;
            cantidadVotos = 1;
        }
    }
    promedioHospedaje = (float) sumaVotos / cantidadVotos;
    return promedioHospedaje;
}

void IncrementaHuespedes(int huesped, int* cantidadMayores, int* cantidadMenores){
    if (huesped == 0){
        if (*cantidadMayores < 10){
            (*cantidadMayores)++;
        }
        gotoxy(44,9);
        Color(NEGRO,BLANCO);
        printf("%i  ", *cantidadMayores);
    } else {
        if (*cantidadMenores < 10){
            (*cantidadMenores)++;
        }
        gotoxy(59,9);
        Color(NEGRO,BLANCO);
        printf("%i  ", *cantidadMenores);
    }
}

void DecrementaHuespedes(int huesped, int* cantidadMayores, int* cantidadMenores){
    if (huesped == 0){
        if (*cantidadMayores > 1){
            (*cantidadMayores)--;
        }
        gotoxy(44,9);
        Color(NEGRO,BLANCO);
        printf("%i  ", *cantidadMayores);
    } else {
        if (*cantidadMenores > 0){
            (*cantidadMenores)--;
        }
        gotoxy(59,9);
        Color(NEGRO,BLANCO);
        printf("%i  ", *cantidadMenores);
    }
}

void hotelesPorUsuario(stUsuario usuario){
    hidecursor(SI);
    int barraOpciones = 0;
    int barraBusqueda = 0;
    char tecla = 0;
    int filtroTipo = 0; /// 0 Todos, 1 hotel, 2 Hostal, 3 dpto
    int wifi = 0; /// 0 sin tilde, 1 con tilde
    int parking = 0; /// 0 sin tilde, 1 con tilde
    int piscina = 0; /// 0 sin tilde, 1 con tilde
    int huesped = 0; /// 0 adultos, 1 menores
    int cantidadMayores = 1;
    int cantidadMenores = 0;
    int posicionVista = 0; /// Va a varia entre 0 y 2 por las 3 posiciones en la ventana
    int cantidadFiltrado = 0; /// Cuantos hospedajes tengo para mostrar
    int totalHoteles = 0; /// El total de hospedajes
    int posicionSobreLista = 1;

    ventanaHoteles();
    selectHotelFromList(posicionVista, AMARILLO);

    nodoHospedaje* listaHoteles = inicListaHoteles();
    listaHoteles = crearListaHotelesUser(archivoHoteles, &cantidadFiltrado); /// Guardo la lista de hoteles
    totalHoteles = cantidadFiltrado;
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

    nodoListaOfListaPuntajes* listaPuntajes = inicListaOfListaPuntajes();
    listaPuntajes = crearListaOfListaVotos();

    iterador = mostrarTresHoteles(iterador, arbolHotelesFavoritos, arbolHotelesReservados);

    Color(NEGRO, BLANCO);

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
                        selectHotelFromList(posicionVista, BLANCO);
                        posicionVista--;
                        posicionSobreLista--;
                        selectHotelFromList(posicionVista, AMARILLO);
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
                        selectHotelFromList(posicionVista, BLANCO);
                        posicionVista++;
                        posicionSobreLista++;
                        selectHotelFromList(posicionVista, AMARILLO);
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
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUHOTELES); // Barra 2 Hoteles
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
            limpiarVentanaHoteles(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
            break;
        case F3:
            MarcarDesmarcarPiscina(&piscina);
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            limpiarVentanaHoteles(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
            break;
        case F4:
            MarcarDesmarcarWifi(&wifi);
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            limpiarVentanaHoteles(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
			break;
        case F5:
            MarcarDesmarcarParking();
            ReiniciarVista(&cantidadFiltrado, &posicionSobreLista, &posicionVista);
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            limpiarVentanaHoteles(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
			break;
        case F6:
            CambioTipoHuesped(&huesped);
			break;
        case F7:
            // RESERVAR
            nodoElegido = obtenerNodoElegido(primeroLista, posicionVista);
            /// Lo busco en el arbolFavoritos
            int estaReservado = buscarReservaArbol(nodoElegido->dato.id, arbolHotelesReservados);
            int posY = DevolverCoordenadaHoteles(posicionVista);

            if (!estaReservado){
                /// mostrar reserva
                mostrarVentanaReserva(cantidadMayores, cantidadMenores, nodoElegido->dato);
                ventanaHoteles();
                iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
                selectHotelFromList(posicionVista, AMARILLO);
            }
            ModificarReservaEnVista(estaReservado, posY);
            if (barraOpciones == 1){
                mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUHOTELES);
            }
            /// Cambiar estado en el arbolHotelesReservados
            arbolHotelesReservados = cambiarEstadoReserva(arbolHotelesReservados, nodoElegido->dato.id);
			break;
        case F8:
            profileModification(usuario);
            ventanaHoteles();
            selectHotelFromList(posicionVista, AMARILLO);
            Color(NEGRO,BLANCO);
            iterador = listaHoteles;
            iterador = mostrarTresHoteles(iterador, arbolHotelesFavoritos, arbolHotelesReservados);
            if (barraOpciones == 1){
                mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);
            }
            barraOpciones = 0;
            barraBusqueda = 0;
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
            // Aplico el filtro para tener toda la lista completa nuevamente
            iterador = aplicarFiltro(listaHoteles, filtroTipo, wifi, piscina, parking, &cantidadFiltrado, totalHoteles);
            iterador = filtrarPorNombre(iterador, busqueda, &cantidadFiltrado);
            limpiarVentanaHoteles(cantidadFiltrado);
            primeroLista = iterador;
            iterador = mostrarTresHoteles(primeroLista, arbolHotelesFavoritos, arbolHotelesReservados);
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUBUSQUEDA);
            break;
        case F10:
            /// Asignar puntaje
            nodoElegido = obtenerNodoElegido(primeroLista, posicionVista);
            float voto = verificarSiUsuarioVoto(listaPuntajes, usuario.id, nodoElegido->dato.id);
            //guardo nuevo puntaje en archivo de hoteles.
            nodoElegido->dato.puntaje = voto;
            guardarPromedioHotel(archivoHoteles, nodoElegido->dato);
            listaPuntajes = crearListaOfListaVotos();
            ventanaHoteles();
            selectHotelFromList(posicionVista, AMARILLO);
            Color(NEGRO,BLANCO);
            iterador = listaHoteles;
            iterador = mostrarTresHoteles(iterador, arbolHotelesFavoritos, arbolHotelesReservados);
            if (barraOpciones == 1){
                mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUHOTELES);
            }
            barraOpciones = 0;
            barraBusqueda = 0;
            break;
        case ENTER:
            /// Marcar como Favorito.
            nodoElegido = obtenerNodoElegido(primeroLista, posicionVista);
            /// Lo busco en el arbolFavoritos
            int esFavorito = buscarFavoritoArbol(nodoElegido->dato.id, arbolHotelesFavoritos);
            /// Hace o borra el corazon
            posY = DevolverCoordenadaHoteles(posicionVista);
            ModificarFavoritosEnVista(esFavorito,posY);
            /// Cambiar estado en el arbolHotelesFavoritos
            arbolHotelesFavoritos = cambiarEstadoFavorito(arbolHotelesFavoritos, nodoElegido->dato.id);
            break;
        case '+':
            IncrementaHuespedes(huesped, &cantidadMayores, &cantidadMenores);
            break;
        case '-':
            DecrementaHuespedes(huesped, &cantidadMayores, &cantidadMenores);
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
}
