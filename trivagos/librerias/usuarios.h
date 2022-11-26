#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "hoteles.h"
#include "ventanas.h"
#include "estructuras.h"
#include "vista.h"
#include "constantes.h"
#include "utilities.h"
#include "estructuras.h"
#include "persistencia.h"


void mostrarDatosUsuario(stUsuario usuario);
int CambiarPassword(stUsuario* usuario);
void menuIngreso();
void loginUsuario();
void IngresarNombre(int* salirRegistro, stUsuario* usuario);
void IngresarMail(int* salirRegistro, stUsuario* usuario, char fileName[]);
void IngresarPassword(int* salirRegistro, stUsuario* usuario);
int userRegistration(const char fileName[]);
void ModificarNombre(int* salirRegistro, stUsuario* usuarioModificado, stUsuario* usuario);
int ModificarMail(stUsuario* usuarioModificado, stUsuario* usuario);
void ModificarPerfil(stUsuario* usuario, int* huboCambios);
int profileModification(stUsuario* usuario);
void menuAdmin();

#endif // USUARIOS_H_INCLUDED
