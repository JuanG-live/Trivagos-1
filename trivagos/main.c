#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "librerias/vista.h"
#include "librerias/gotoxy.h"
#include "librerias/usuarios.h"
#include "librerias/utilities.h"

int main()
{
    settearConsola();
    hidecursor(SI);
    menuIngreso();
    salirSistema();
    return 0;
}


