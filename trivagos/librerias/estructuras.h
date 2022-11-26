#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include "constantes.h"

typedef struct{
    int color;
    int fondo;
    int caracter;
} stMatriz; /// MATRIZ PARA DIBUJAR VENTANAS.

typedef struct{
    int idHotel;
    float precio;
} stReserva; /// ESTRUCTURA QUE SE GUARDA EN RESERVAS.BIN DE CADA USUARIO.

typedef struct {
    int idHotel;
    int idUsuario;
    int voto;
} stPuntos; /// ESTRUCTURA QUE SE GUARDA EN PUNTAJES.BIN.

typedef struct {
    int idUsuario;
    int voto;
    struct nodoVoto* siguiente;
} nodoVoto; /// NODO PARA LA LISTA DE LISTA DE PUNTAJES.

typedef struct {
    int id;
    char name[NAME];
    int type;
    int cantEstrellas;
    float puntaje;
    float precio;
    int wifi;
    int pileta;
    int parking;
    int active;
} stHospedaje;

typedef struct {
    stHospedaje dato;
    struct nodoHospedaje* siguiente;
    struct nodoHospedaje* anterior;
} nodoHospedaje; // Lista doble de Hospedajes

typedef struct {
    int idHotel;
    struct nodoFavoritos* siguiente;
} nodoFavoritos; // Lista de favoritos, se arma para cada usuario legueado.

typedef struct {
    stReserva dato;
    struct nodoReservas* siguiente;
} nodoReservas; // Lista de reservados, se arma para cada usuario legueado.

typedef struct{
    int idHotel;
    int esFavorito;
    struct arbolFavoritos* izquierda;
    struct arbolFavoritos* derecha;
} arbolFavoritos; // Arbol para que sea mas agil, marcar o desmarcar favoritos.-

typedef struct{
    stReserva dato;
    int estaReservado;
    struct arbolReservas* izquierda;
    struct arbolReservas* derecha;
} arbolReservas; // Arbol para que sea mas agil, marcar o desmarcar las reservas y sus importes.-

typedef struct {
    int idHotel;
    struct nodoVoto* votos;
    struct nodolistaOfListaPuntajes* siguiente;
} nodoListaOfListaPuntajes;

typedef struct{
    int id;
    char name[NAME];
    char address[ADDRESS];
    char phone[PHONE];
    char mail[MAIL];
    char password[PASSWORD];
    int active;
    int administrator;
} stUsuario;

typedef struct {
    stUsuario dato;
    struct nodoUsuario* siguiente;
    struct nodoUsuario* anterior;
} nodoUsuario; // Lista doble de Hospedajes

#endif // ESTRUCTURAS_H_INCLUDED
