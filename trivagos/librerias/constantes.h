#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define TOPLEFT 1754
#define TOPRIGHT 1727
#define BOTTOMLEFT 1728
#define BOTTOMRIGHT 1753
#define BORDER 1715
#define LINE 1732
#define LINECUTL 1731
#define LINECUTR 1716
#define BLOCK 219
#define LIGHTBLOCK 178
#define TARRIBA 1730
#define TABAJO 1729
#define HEART 3
#define LBLOCK 178
#define STAR 4

#define MAXISBN 20
#define TITLE 30
#define AUTHOR 30
#define GENDER 20
#define EDITORIAL 30
#define DESCRIPTION 200
#define NAME 30
#define SURNAME 30
#define ADDRESS 30
#define PHONE 30
#define FAVOURITE 10
#define MAIL 28
#define PASSWORD 8
#define NOMBREAPELLIDO 60
#define DATES 128
#define PRIZE 6

#define UNO 49
#define DOS 50
#define TRES 51
#define CUATRO 52
#define OCHO 56
#define NUEVE 57
#define ESC 27
#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define UPARROW 72
#define DOWNARROW 80
#define LEFTARROW 75
#define RIGHTARROW 77
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#define SMAY 115  // LA "S" MAYUSCULA
#define SMIN 83   // LA "s" MINUSCULA

/// Constantes de Barras de Menu
#define MENUEDITPERFIL 4
#define MENUADMINISTRADOR 5
#define MENUPPAL 0
#define MENULOGIN 1
#define MENUHOTELES 2
#define MENUBUSQUEDA 3
#define MENUADMINUSERS 6
#define MENUADMINUSERSFAVYRESERVAS 7
#define MENUADMINHOSPEDAJES 8
#define MENUAGREGAHOSPEDAJE 9

/// Capturar Palabra
#define OCULTO 1
#define VISIBLE 0
#define RETICULA 0
#define FULL 1
#define DARK 2

/// Colores
#define NEGRO 0
#define AZUL 1
#define GREEN 2
#define CYAN 3
#define ROJO 4
#define MAGENTA 5
#define BROWN 6
#define LGREY 7
#define DGREY 8
#define LBLUE 9
#define LGREEN 10
#define LCYAN 11
#define LRED 12
#define LMAGENTA 13
#define AMARILLO 14
#define BLANCO 15

/// Cursor
#define NO 1
#define SI 0

/// Orden
#define NOMBRE 0
#define PRECIO 1

/// Favoritos y reservas
#define NOFAV 0
#define NORESERVA 0

/// Columnas y Filas
#define FILAS 25
#define FILASMENU 5
#define FILASMOVIL 3
#define FILASTOTALPERFIL 18
#define FILASTOTALRESTO 36
#define FILASADMIN 17
#define FILASHOTEL 4
#define COLUMNAS 80
#define COLUMNASMOVIL 43
#define FONDOPANTALLA 28
#define DESDEPERFIL 60
#define DESDEPERFILRESTO 42
#define POSICIONTERCERHOTEL 8

/// Modifica Crea
#define MODIFICA 0
#define CREA 1


const char archivoUsuarios[NAME];
const char archivoFavoritos[NAME];
const char archivoHoteles[NAME];
const char archivoReservas[NAME];
const char archivoPuntajes[NAME];
const char archivoHotelesNuevos[NAME];

#endif // CONSTANTES_H_INCLUDED
