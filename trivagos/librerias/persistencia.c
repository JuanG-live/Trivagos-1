#include "persistencia.h"

nodoHospedaje* crearListaHoteles(const char nombreArchivo[NAME], int* cantidadFiltrado){
    stHospedaje hotel;
    nodoHospedaje* listaHoteles;
    listaHoteles = inicListaHoteles();

    FILE* pFile = fopen(nombreArchivo, "rb");
    if (pFile != NULL){
        while (fread(&hotel, sizeof(stHospedaje), 1, pFile) > 0){
            listaHoteles = agregarNodoPpioHoteles(listaHoteles, crearNodoHoteles(hotel));
            *cantidadFiltrado +=1;
        }
        fclose(pFile);
    }

    return listaHoteles;
}

nodoHospedaje* crearListaHotelesUser(const char nombreArchivo[NAME], int* cantidadFiltrado){
    stHospedaje hotel;
    nodoHospedaje* listaHoteles;
    listaHoteles = inicListaHoteles();

    FILE* pFile = fopen(nombreArchivo, "rb");
    if (pFile != NULL){
        while (fread(&hotel, sizeof(stHospedaje), 1, pFile) > 0){
            if(hotel.active==1){
                listaHoteles = agregarNodoPpioHoteles(listaHoteles, crearNodoHoteles(hotel));
                *cantidadFiltrado +=1;
            }
        }
        fclose(pFile);
    }

    return listaHoteles;
}

nodoHospedaje* crearListaFavoritos(stUsuario usuario){
    int idHotel;
    nodoFavoritos* listaFavoritos;
    listaFavoritos = inicListaFavoritos();
    char buffer[50] = "";
    int error = 0;
    obtenerDirectorio(usuario, buffer, &error);
    if (!error){
        mkdir(buffer);
        chdir(buffer);
        FILE* pFile = fopen(archivoFavoritos, "rb");
        if (pFile != NULL){
            while (fread(&idHotel, sizeof(idHotel), 1, pFile) > 0){
                listaFavoritos = agregarNodoPpioFavoritos(listaFavoritos, crearNodoFavoritos(idHotel));
            }
            fclose(pFile);
        }
        chdir("..");
    }

    return listaFavoritos;
}

nodoReservas* crearListaReservas(stUsuario usuario){
    stReserva dato;
    nodoReservas* listaReservas;
    listaReservas = inicListaReservas();
    char buffer[50] = "";
    int error = 0;
    obtenerDirectorio(usuario, buffer, &error);
    if (!error){
        mkdir(buffer);
        chdir(buffer);

        FILE* pFile = fopen(archivoReservas, "rb");
        if (pFile != NULL){
            while (fread(&dato, sizeof(stReserva), 1, pFile) > 0){
                listaReservas = agregarNodoPpioReservas(listaReservas, crearNodoReservas(dato));
            }
            fclose(pFile);
        }
        chdir("..");
    }
    return listaReservas;
}

nodoListaOfListaPuntajes* crearListaOfListaVotos(){
    stPuntos dato;
    nodoListaOfListaPuntajes* listaPuntajes;
    listaPuntajes = inicListaOfListaPuntajes();
    FILE* pFile = fopen(archivoPuntajes, "rb");
    if (pFile != NULL){
        while (fread(&dato, sizeof(stPuntos), 1, pFile) > 0){
            if (listaPuntajes == NULL){
                nodoListaOfListaPuntajes* nuevoNodoLista = crearNodoPuntajes(dato.idHotel);
                nuevoNodoLista->votos = agregarNodoPpioVotos(nuevoNodoLista->votos, crearNodoVoto(dato.idUsuario, dato.voto));
                listaPuntajes = nuevoNodoLista;
//                nodoVoto* votos = listaPuntajes->votos;
//                printf("%i %i", votos->idUsuario, votos->voto);
//                system("pause");
            } else { // Busco el id del hotel
                int existe = 0;
                nodoListaOfListaPuntajes* iterador = listaPuntajes;
                while (iterador != NULL){
                    if (iterador->idHotel == dato.idHotel){
                        /// Agregar un nuevo nodo a la lista dentro de la lista
                        iterador->votos = agregarNodoPpioVotos(iterador->votos, crearNodoVoto(dato.idUsuario, dato.voto));
                        existe = 1;
                    }
                    iterador = iterador->siguiente;
                }
                if (existe == 0){ // No existe el hotel en la lista de lista pero no esta vacia
                    listaPuntajes = agregarNodoPpioListaOfListaPuntajes(listaPuntajes, crearNodoPuntajes(dato.idHotel));
                    listaPuntajes->votos = agregarNodoPpioVotos(listaPuntajes->votos, crearNodoVoto(dato.idUsuario, dato.voto));
                }
            }
        }
        fclose(pFile);
    }
    return listaPuntajes;
}

void VerificarUserPassword(const char fileName[], stUsuario* usuario, int* userLogued, char username[], char password[]){
    stUsuario user;
    int flag = 0;
    FILE* pFile = fopen(fileName, "rb");
    if (pFile != NULL){
        while (fread(&user, sizeof(stUsuario), 1, pFile) > 0 && flag == 0){
            if (strcmp(username, user.mail) == 0 && strcmp(password, user.password) == 0){
                flag = 1;
                *usuario = user;
                if (user.administrator == 1){
                    *userLogued = 2;
                } else {
                    *userLogued = 1;
                }
                if (user.active == 0){
                    *userLogued = 3;
                }
            }
        }
        fclose(pFile);
    }
    if (strcmp(username, "ADMIN") == 0 && strcmp(password, "ADMIN") == 0){
        *userLogued = 2;
        usuario->active = 1;
        strcpy(usuario->name, "ADMIN");
        usuario->id = -1;
        usuario->administrator = 1;
    }
}

int validaExistenciaMail(const char fileName[],char mail[]){
    stUsuario usuario;
    int resultado = 0; //EXISTE
    int flag = 0;
    FILE* pFile = fopen(fileName,"rb");
    if(pFile != NULL){
        while(fread(&usuario, sizeof(stUsuario),1,pFile) > 0 && flag == 0){
            if(strcmp(usuario.mail,mail) == 0){
                resultado = 0;
                flag = 1;
            }else{
                resultado = 1; //NO EXISTE
            }
        }
        fclose(pFile);
    }else{
        resultado = 1; //NO EXISTE
    }
    return resultado;
}

int CantidadRegistros(const char nombreArchivo[], int sizeStruct){
    int cantidadRegistros = 0;
    FILE* pFile = fopen(nombreArchivo, "rb");
    if (pFile != NULL){
        fseek (pFile, 0, SEEK_END);
        cantidadRegistros = ftell (pFile) / sizeStruct;
        fclose(pFile);
    }
    return cantidadRegistros;
}

int registrarUsuario(stUsuario usuario, const char fileName[]){
    int resultado = 0;
    stUsuario ultimoUsuario;
    int cantidadRegistros = CantidadRegistros(fileName, sizeof(stUsuario));
    FILE* pFile = fopen(fileName, "rb");
    if (pFile != NULL){
        fseek(pFile, (cantidadRegistros - 1)*sizeof(stUsuario), SEEK_SET); // ME PARO AL PRINCIPIO Y LE DIGO QUE VAYA HASTA EL INICIO DEL ULTIMO REGISTRO
        fread(&ultimoUsuario, sizeof(stUsuario), 1, pFile);
        fclose(pFile);
        usuario.id = ultimoUsuario.id + 1;
    } else {
        usuario.id = 1;
    }
    pFile = fopen(fileName, "ab");
    if (pFile != NULL){
        resultado = fwrite(&usuario, sizeof(stUsuario), 1, pFile);
        fclose(pFile);
    }
    return resultado;
}

void obtenerDirectorio(stUsuario usuario, char buffer[], int* error){
    char* num;
    if (asprintf(&num, "%d", usuario.id) == -1) {
        *error = 1;
    } else {
        strcat(buffer, num);
        free(num);
    }
}

void grabarFavoritosArchivo(stUsuario usuario, nodoFavoritos* listaFinalFavoritos){
    int error = 0;
    char buffer[50] = "";
    obtenerDirectorio(usuario, buffer, &error);
    if (!error){
        mkdir(buffer); // Creamos la carpeta
        chdir(buffer); // ingresamos a ella

        FILE* archivo = fopen(archivoFavoritos, "wb");
        if (archivo != NULL){
            while (listaFinalFavoritos != NULL){
                int idHotel = listaFinalFavoritos->idHotel;
                fwrite(&idHotel, sizeof(idHotel), 1, archivo);
                listaFinalFavoritos = listaFinalFavoritos->siguiente;
            }
            fclose(archivo);
        }
        chdir(".."); // Volvemos al nivel anterior del directorio
    }

}

void grabarReservasArchivo(stUsuario usuario, nodoReservas* listaFinalReservas){
    int error = 0;
    char buffer[50] = "";
    obtenerDirectorio(usuario, buffer, &error);
    if (!error){
        mkdir(buffer); // Creamos la carpeta
        chdir(buffer); // ingresamos a ella

        FILE* archivo = fopen(archivoReservas, "wb");
        if (archivo != NULL){
            while (listaFinalReservas != NULL){
                stReserva reserva = listaFinalReservas->dato;
                fwrite(&reserva, sizeof(reserva), 1, archivo);
                listaFinalReservas = listaFinalReservas->siguiente;
            }
            fclose(archivo);
        }
        chdir(".."); // Volvemos al nivel anterior del directorio
    }

}

void grabarUsuariosArchivo(nodoUsuario* listaUsuarios){
    FILE* archivo = fopen(archivoUsuarios, "wb");
    if (archivo != NULL){
        while (listaUsuarios != NULL){
            stUsuario usuario = listaUsuarios->dato;
            fwrite(&usuario, sizeof(usuario), 1, archivo);
            listaUsuarios = listaUsuarios->siguiente;
        }
        fclose(archivo);
    }
}

void GuardarInfoUsuario(const char nombreArchivo[], stUsuario usuarioModificado){
    stUsuario usuario;
    int flag = 0;
    FILE* pFile = fopen(nombreArchivo, "r+b");
    if (pFile != NULL){
        while (flag == 0 && fread(&usuario, sizeof(stUsuario), 1, pFile) > 0 ){
            if (usuario.id == usuarioModificado.id) {
                // Encontre el registro que debo sobrescribir
                flag = 1;
                int posicion = ftell(pFile) - sizeof(stUsuario);
                fseek(pFile,posicion,SEEK_SET);
                if (fwrite(&usuarioModificado, sizeof(stUsuario), 1, pFile) > 0){
                    MostrarMensaje("DATOS MODIFICADOS CORRECTAMENTE.");
                } else {
                    MostrarMensaje("ERROR AL GRABAR LOS CAMBIOS");
                }
            }
        }
        fclose(pFile);
    }else {
        MostrarMensaje("ERROR AL GRABAR LOS CAMBIOS");
    }
}

void modificarVotacion(const char nombreArchivo[], stPuntos puntosNuevos){
    stPuntos puntos;
    int flag = 0;
    FILE* pFile = fopen(nombreArchivo, "r+b");
    if (pFile != NULL){
        while (flag == 0 && fread(&puntos, sizeof(stPuntos), 1, pFile) > 0 ){
            if (puntos.idHotel == puntosNuevos.idHotel) {
                // Encontre el registro que debo sobrescribir
                flag = 1;
                int posicion = ftell(pFile) - sizeof(stPuntos);
                fseek(pFile,posicion,SEEK_SET);
                fwrite(&puntosNuevos, sizeof(stPuntos), 1, pFile);
            }
        }
        fclose(pFile);
    }else {
        MostrarMensaje("ERROR AL GRABAR LOS CAMBIOS");
    }
}

void agregarVotacion(const char nombreArchivo[], stPuntos puntosNuevos){
    FILE* pFile = fopen(nombreArchivo, "a+b");
    if (pFile != NULL){
        fwrite(&puntosNuevos, sizeof(stPuntos), 1, pFile);
        fclose(pFile);
    }else {
        MostrarMensaje("ERROR AL GRABAR LOS CAMBIOS NUEVO VOTO");
    }
}

void guardarPromedioHotel(const char nombreArchivo[], stHospedaje hospedajeActualizado){
    stHospedaje hospedaje;
    int flag = 0;
    FILE* pFile = fopen(nombreArchivo, "r+b");
    if (pFile != NULL){
        while (flag == 0 && fread(&hospedaje, sizeof(stHospedaje), 1, pFile) > 0 ){
            if (hospedaje.id == hospedajeActualizado.id) {
                // Encontre el registro que debo sobrescribir
                flag = 1;
                int posicion = ftell(pFile) - sizeof(stHospedaje);
                fseek(pFile,posicion,SEEK_SET);
                if (fwrite(&hospedajeActualizado, sizeof(stHospedaje), 1, pFile) > 0){
                    MostrarMensaje("DATOS MODIFICADOS CORRECTAMENTE.");
                } else {
                    MostrarMensaje("ERROR AL GRABAR LOS CAMBIOS PROMEDIO");
                }
            }
        }
        fclose(pFile);
    }else {
        MostrarMensaje("ERROR AL ABRIR ARCHIVO PROMEDIO");
    }

}

void guardarHotel(const char nombreArchivo[], nodoHospedaje* hospedajeActualizado){
    stHospedaje hospedaje;
    int flag = 0;
    FILE* pFile = fopen(nombreArchivo, "r+b");
    if (pFile != NULL){
        while (flag == 0 && fread(&hospedaje, sizeof(stHospedaje), 1, pFile) > 0 ){
            if (hospedaje.id == hospedajeActualizado->dato.id) {
                // Encontre el registro que debo sobrescribir
                flag = 1;
                fseek(pFile,sizeof(stHospedaje)*-1,SEEK_CUR);
                fwrite(&(hospedajeActualizado->dato), sizeof(stHospedaje), 1, pFile);
            }
        }
        fclose(pFile);
    }
}

void GuardarInfoHotel(const char nombreArchivo[], stHospedaje hotelModificado){
    stHospedaje hotel;
    int flag = 0;
    FILE* pFile = fopen(nombreArchivo, "r+b");
    if (pFile != NULL){
        while (flag == 0 && fread(&hotel, sizeof(stHospedaje), 1, pFile) > 0 ){
            if (hotel.id == hotelModificado.id) {
                // Encontre el registro que debo sobrescribir
                flag = 1;
                int posicion = ftell(pFile) - sizeof(stHospedaje);
                fseek(pFile,posicion,SEEK_SET);
                if (fwrite(&hotelModificado, sizeof(stHospedaje), 1, pFile) > 0){
                    MostrarMensaje("DATOS MODIFICADOS CORRECTAMENTE.");
                } else {
                    MostrarMensaje("ERROR AL GRABAR LOS CAMBIOS");
                }
            }
        }
        fclose(pFile);
    }else {
        MostrarMensaje("ERROR AL GRABAR LOS CAMBIOS");
    }
}

int grabarHospedaje(stHospedaje hospedaje){
    stHospedaje ultimoHospedaje;
    int resultado = 0;
    int cantidadRegistros = CantidadRegistros(archivoHoteles, sizeof(stHospedaje));
    FILE* pFile = fopen(archivoHoteles, "rb");
    if (pFile != NULL){
        fseek(pFile, (cantidadRegistros - 1)*sizeof(stHospedaje), SEEK_SET); // ME PARO AL PRINCIPIO Y LE DIGO QUE VAYA HASTA EL INICIO DEL ULTIMO REGISTRO
        fread(&ultimoHospedaje, sizeof(stUsuario), 1, pFile);
        fclose(pFile);
        hospedaje.id = ultimoHospedaje.id + 1;
    } else {
        hospedaje.id = 1;
    }
    pFile = fopen(archivoHoteles, "ab");
    if (pFile != NULL){
        resultado = fwrite(&hospedaje, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
    }
    return resultado;
}

nodoUsuario* crearListaUsuarios(const char nombreArchivo[NAME], int* cantidadFiltrado){
    stUsuario usuario;
    nodoUsuario* listaUsuarios;
    listaUsuarios = inicListaUsuarios();

    FILE* pFile = fopen(nombreArchivo, "rb");
    if (pFile != NULL){
        while (fread(&usuario, sizeof(stUsuario), 1, pFile) > 0){
            listaUsuarios = agregarNodoPpioUsuarios(listaUsuarios, crearNodoUsuario(usuario));
            *cantidadFiltrado +=1;
        }
        fclose(pFile);
    }

    return listaUsuarios;
}

/// FUNCION QUE CARGO LOS PRIMEROS HOTELES

void DarDeAltaHoteles(const char nombreArchivo[NAME]){
    stHospedaje hotel;
    hotel.active = 1;
    hotel.id = 1;
    strcpy(hotel.name, "NH Buenos Aires City");
    hotel.type = 1;
    hotel.cantEstrellas = 3;
    hotel.puntaje = 8.1;
    hotel.precio = 3500;
    hotel.wifi = 1;
    hotel.pileta = 1;
    hotel.parking = 1;
    FILE* pFile = fopen(nombreArchivo, "wb");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 2;
    strcpy(hotel.name, "Luces de la Selva");
    hotel.type = 2;
    hotel.cantEstrellas = 4;
    hotel.puntaje = 8.1;
    hotel.precio = 3700;
    hotel.wifi = 1;
    hotel.pileta = 1;
    hotel.parking = 0;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 3;
    strcpy(hotel.name, "Deptos VILLAHERMOSA");
    hotel.type = 3;
    hotel.cantEstrellas = 3;
    hotel.puntaje = 7.1;
    hotel.precio = 2500;
    hotel.wifi = 1;
    hotel.pileta = 0;
    hotel.parking = 1;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 4;
    strcpy(hotel.name, "Hotel Sari-Mar");
    hotel.type = 1;
    hotel.cantEstrellas = 2;
    hotel.puntaje = 7.8;
    hotel.precio = 2800;
    hotel.wifi = 1;
    hotel.pileta = 1;
    hotel.parking = 1;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 5;
    strcpy(hotel.name, "Hotel Ambassador");
    hotel.type = 1;
    hotel.cantEstrellas = 4;
    hotel.puntaje = 8.7;
    hotel.precio = 3900;
    hotel.wifi = 1;
    hotel.pileta = 1;
    hotel.parking = 1;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 6;
    strcpy(hotel.name, "Hotel TWO");
    hotel.type = 1;
    hotel.cantEstrellas = 2;
    hotel.puntaje = 7.7;
    hotel.precio = 2900;
    hotel.wifi = 1;
    hotel.pileta = 1;
    hotel.parking = 0;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 7;
    strcpy(hotel.name, "Top Rentals Libertador");
    hotel.type = 3;
    hotel.cantEstrellas = 4;
    hotel.puntaje = 8.7;
    hotel.precio = 17500;
    hotel.wifi = 0;
    hotel.pileta = 1;
    hotel.parking = 1;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 8;
    strcpy(hotel.name, "byblos Palermo Soho");
    hotel.type = 1;
    hotel.cantEstrellas = 4;
    hotel.puntaje = 8.5;
    hotel.precio = 43500;
    hotel.wifi = 0;
    hotel.pileta = 1;
    hotel.parking = 1;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 9;
    strcpy(hotel.name, "Hostal Isla Mucura");
    hotel.type = 2;
    hotel.cantEstrellas = 3;
    hotel.puntaje = 6.9;
    hotel.precio = 23500;
    hotel.wifi = 0;
    hotel.pileta = 1;
    hotel.parking = 1;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}

    hotel.active = 1;
    hotel.id = 10;
    strcpy(hotel.name, "Punta Norte");
    hotel.type = 2;
    hotel.cantEstrellas = 4;
    hotel.puntaje = 8.1;
    hotel.precio = 33200;
    hotel.wifi = 0;
    hotel.pileta = 1;
    hotel.parking = 1;
    pFile = fopen(nombreArchivo, "ab");
    if (pFile != NULL){
        fwrite(&hotel, sizeof(stHospedaje), 1, pFile);
        fclose(pFile);
  	}
}
