#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include "usuarios.h"


void mostrarDatosUsuario(stUsuario usuario){
    Color(NEGRO,AMARILLO);
    gotoxy(33,10);
    printf("%s", usuario.name);
    gotoxy(33,13);
    printf("%s", usuario.address);
    gotoxy(33,16);
    printf("%s", usuario.phone);
    gotoxy(33,19);
    printf("%s", usuario.mail);
}

int CambiarPassword(stUsuario* usuario){
    char passwordVieja[PASSWORD];
    char passwordNueva[PASSWORD];
    char passwordValidacion[PASSWORD];
    int primeraValidacion=0;
    int segundaValidacion=0;
    int teclaCaptura = 0;
    hidecursor(NO);
    while(primeraValidacion==0 && teclaCaptura ==0)
    {
        teclaCaptura = CapturarPalabra(passwordVieja,57,13,PASSWORD, OCULTO, RETICULA, AMARILLO);
        if (teclaCaptura != ESC)
        {
            if(strcmp(passwordVieja,usuario->password)==0)
            {
                primeraValidacion=1;
            }
            else
            {
                MensajesAdvertencias("LAS CONTRASENIAS NO COINCIDEN", 28, 23, BLANCO);
                limpiaFormulario(57, 66, 13, LIGHTBLOCK, NEGRO, AMARILLO);
                teclaCaptura = 0;
            }
        }
    }
    teclaCaptura = 0;
    while(segundaValidacion==0 && primeraValidacion==1 && teclaCaptura == 0)
    {
        do {
            CapturarPalabra(passwordNueva,57,16,PASSWORD, OCULTO, RETICULA, AMARILLO);
            if (strlen(passwordNueva) == 0){
                MensajesAdvertencias("LA CONTRASENIA NO PUEDE ESTAR VACIA", 28,23, BLANCO);
                limpiaFormulario(57, 66, 16, LIGHTBLOCK, NEGRO, AMARILLO);
                teclaCaptura = 0;
            }

        } while (strlen(passwordNueva) <= 0);
        teclaCaptura = CapturarPalabra(passwordValidacion,57,19,PASSWORD,OCULTO, RETICULA, AMARILLO);
        if (teclaCaptura != ESC)
        {
            if(strcmp(passwordNueva,passwordValidacion)==0)
            {
                MostrarMensaje("CONTRASENIA CAMBIADA CORRECTAMENTE");
                strcpy(usuario->password,passwordNueva);
                segundaValidacion=1;
            }
            else
            {
                MensajesAdvertencias("LAS CONTRASENIAS NUEVAS NO COINCIDEN", 28,23, BLANCO);
                limpiaFormulario(57, 66, 16, LIGHTBLOCK, NEGRO, AMARILLO);
                limpiaFormulario(57, 66, 19, LIGHTBLOCK, NEGRO, AMARILLO);
                teclaCaptura = 0;
            }
        }
    }
    hidecursor(SI);
    return segundaValidacion;
}

void menuIngreso(){

    int barraOpciones = 0;
    int barraBusqueda = 0;
    ventanaPrincipal();
    Color(NEGRO,BLANCO);
    char key;

    do{
        fflush(stdin);
        key = getch();
        switch(key)
        {
        case F1: // Muestro el menu
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUPPAL); /// EL segundo parametro es para saber que menu usar.
            break;
        case UNO: // LogIN
            loginUsuario(archivoUsuarios);
            barraOpciones = 0;
            break;
        case DOS: // REGISTRO
            userRegistration(archivoUsuarios);
            ventanaPrincipal();
            break;
        case ESC: /// SALIR
            system("cls");
            MostrarMensaje("GRACIAS POR USAR NUESTRO SISTEMA.");
            gotoxy(1,23);
            break;
        }
    }
    while (key != ESC);
}

void loginUsuario(const char* fileName){
    system("cls");
    hidecursor(1);
    stUsuario usuario;
    char username[MAIL];
    char password[PASSWORD];
    int userLogued = 0;
    int datosLogueado = 0; // 0 SI FALTA INFORMACION DE LOGUEO, 1 SI EL USUARIO ESCRIBIO USUARIO Y CLAVE
    int teclaUserName = 0;
    int teclaPassword = 0;
    int barraOpciones = 0;
    int barraBusqueda = 0;
    int exit = 0;
    ventanaLogIn();
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENULOGIN);
    Color(NEGRO,BLANCO);
    do {
        teclaUserName = CapturarPalabra(username, 31, 9, MAIL, VISIBLE, RETICULA, AMARILLO); // el ultimo parametro es para saber si tiene que escribir el caracter o *
        if (teclaUserName == ENTER){
            teclaPassword = CapturarPalabra(password, 31, 13, PASSWORD, OCULTO, RETICULA, AMARILLO);
            if (teclaPassword == ENTER){
                datosLogueado = 1;
            }
        }
    } while (datosLogueado != 1 && teclaUserName != ESC && teclaPassword != ESC);
    if (datosLogueado == 1) {
        VerificarUserPassword(fileName, &usuario, &userLogued, username, password);
    }
    if (userLogued == 1) { // USUARIO NORMAL
        mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENULOGIN); // 1
        hotelesPorUsuario(usuario);
    } else if (userLogued == 2){ // USUARIO ADMIN
        menuAdmin(usuario);
    } else if (userLogued == 3) { // DADO DE BAJA
        MostrarMensaje("USUARIO DADO DE BAJA, SOLICITAR REACTIVACION.");
    } else if (teclaUserName != ESC && teclaPassword != ESC) {
        MostrarMensaje("USUARIO INVALIDO");
    } else {
        MostrarMensaje("CANCELANDO...");
    }
    hidecursor(SI);
    Color(NEGRO, BLANCO);
    system("cls");
    ventanaPrincipal();
}

void IngresarNombre(int* salirRegistro, stUsuario* usuario){
    int validaIngreso = 0;
    do{
        Color(NEGRO,AMARILLO);
        *salirRegistro = CapturarPalabra(usuario->name,33,7, NAME, VISIBLE, RETICULA, AMARILLO);
        if(strlen(usuario->name) == 0 && *salirRegistro != ESC){
            MensajesErroresRegistro("ERROR - EL NOMBRE NO PUEDE ESTAR VACIO", 21, 24);
        }else{
            validaIngreso = 1;
        }
    }while (validaIngreso == 0);
}

void IngresarMail(int* salirRegistro, stUsuario* usuario, char fileName[]){
    int validaMail = 0;
    int validaIngreso = 0;
    while(validaIngreso == 0 && *salirRegistro != ESC){
        *salirRegistro = CapturarPalabra(usuario->mail,33,16,MAIL-2, VISIBLE, RETICULA, AMARILLO);
        if(strlen(usuario->mail) == 0){
            MensajesErroresRegistro("ERROR - EL MAIL NO PUEDE ESTAR VACIO.",22 ,24);
        }else{
            //VERIFICAR @
            validaMail = ValidaMailCorrecto(usuario->mail);
            if(validaMail == 1){
                //VERIFICA DUPLICADO
                validaIngreso = validaExistenciaMail(fileName,usuario->mail);
                if(validaIngreso == 0){
                    MensajesErroresRegistro("ERROR - EL MAIL YA ESTA REGISTRADO.", 22,24);
                    LimpiarMailErroneo();
                }
            }else{
                MensajesErroresRegistro("ERROR - EL MAIL NO ES VALIDO.",21,24);
                LimpiarMailErroneo();
            }
        }
        Color(NEGRO,AMARILLO);
    }
}

void IngresarPassword(int* salirRegistro, stUsuario* usuario){
    char validatePassword[PASSWORD];
    int validaIngreso = 0;
    int validaPassword = 0;
    while (validaIngreso == 0 && *salirRegistro != ESC){
        Color(NEGRO, AMARILLO);
        validaPassword = 0;
        while(validaPassword == 0 && *salirRegistro != ESC){
            *salirRegistro = CapturarPalabra(usuario->password,33,19,PASSWORD, OCULTO, RETICULA, AMARILLO);
            if(strlen(usuario->password) == 0){
                MensajesErroresRegistro("ERROR - EL PASSWORD NO PUEDE ESTAR VACIO.",20,24);
            }else{
                validaPassword = 1;
            }
        }
        if(*salirRegistro != ESC){
            CapturarPalabra(validatePassword,33,22,PASSWORD, OCULTO, RETICULA, AMARILLO);
            if(strcmp(usuario->password, validatePassword) == 0){
                validaIngreso = 1;
            }else{
                MensajesErroresRegistro("ERROR - LAS CONTRASENIAS NO COINCIDEN.",22,24);
                limpiaFormulario(36, 66, 24, BLOCK, NEGRO, NEGRO);
            }
        }
        Color(NEGRO, AMARILLO);
    }
}

int userRegistration(const char fileName[]){
    hidecursor(NO);
    stUsuario usuario;
    int barraOpciones = 0;
    int barraBusqueda = 0;
    int validaIngreso = 0; /// VALIDA CADA CAMPO DEL FORMULARIO
    int resultado = 0; /// DEVOLVEMOS > 0 SI SE ESCRIBIO BIEN
    int salirRegistro = 0; /// PARA ESCAPAR DE LA CARGA DE DATOS

    registrationMenu(); /// MOSTRAR MENU DE REGISTRO
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENULOGIN);

    IngresarNombre(&salirRegistro, &usuario);
    if (salirRegistro != ESC){
        salirRegistro = CapturarPalabra(usuario.address,33,10,ADDRESS, VISIBLE, RETICULA, AMARILLO);
    }
    if (salirRegistro != ESC){
        salirRegistro = CapturarPalabra(usuario.phone,33,13,PHONE, VISIBLE, RETICULA, AMARILLO);
    }
    if (salirRegistro != ESC){
        IngresarMail(&salirRegistro, &usuario, fileName);
    }
    if (salirRegistro != ESC){
        IngresarPassword(&salirRegistro, &usuario);
    }
    usuario.active = 1;
    usuario.administrator = 0;
    // BUSCAR ID Y GENERAR UN ID NUEVO
    // DECLARO UN LECTOR PARA GUARDAR EL ULTIMO ARCHIVO
    if(salirRegistro != ESC){
        resultado = registrarUsuario(usuario, fileName);
        MostrarMensaje("USUARIO REGISTRADO SATISFACTORIAMENTE.");
    }
    hidecursor(SI);
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENULOGIN);
    return resultado;
}

void ModificarNombre(int* salirRegistro, stUsuario* usuarioModificado, stUsuario* usuario){
    do {
        if (*salirRegistro != ESC){
            *salirRegistro = ModificarPalabra(usuarioModificado->name, usuario->name,33,10, NAME, AMARILLO, AMARILLO, LBLOCK);
            if (strlen(usuarioModificado->name) <=0){
                MensajesAdvertencias("EL NOMBRE NO PUEDE ESTAR VACIO", 28,23, BLANCO);
                Color(NEGRO,AMARILLO);
                for (int x = 33; x < 59; x++)
                {
                    gotoxy(x, 10);
                    printf("%c", LIGHTBLOCK);
                }
                gotoxy(33,10);
                printf("%s", usuario->name);
            }
        }

    } while (*salirRegistro != ESC && strlen(usuarioModificado->name) <= 0);
}

int ModificarMail(stUsuario* usuarioModificado, stUsuario* usuario){
    int validaIngreso = 0;
    int validaMail = 0;
    int salirRegistro = 0;
    while(validaIngreso == 0 && salirRegistro != ESC){
        salirRegistro = ModificarPalabra(usuarioModificado->mail, usuario->mail, 33, 19,MAIL, AMARILLO, AMARILLO, LBLOCK);
        if (salirRegistro != ESC){
            if(strlen(usuarioModificado->mail) == 0){
                MensajesAdvertencias("ERROR - EL MAIL NO PUEDE ESTAR VACIO.",28 ,23, BLANCO);
            } else if (strcmp(usuarioModificado->mail, usuario->mail) == 0){
                validaIngreso = 1;
            }else{
                //VERIFICAR @
                validaMail = ValidaMailCorrecto(usuarioModificado->mail);
                if(validaMail == 1){
                    //VERIFICA DUPLICADO
                    validaIngreso = validaExistenciaMail(archivoUsuarios,usuarioModificado->mail);
                    if(validaIngreso == 0){
                        MensajesAdvertencias("ERROR - EL MAIL YA ESTA REGISTRADO.", 28,23, BLANCO);
                        validaMail = 0;
                    }
                }else{
                    MensajesAdvertencias("ERROR - EL MAIL NO ES VALIDO.",28,23, BLANCO);
                }
            }
            Color(NEGRO,AMARILLO);
            if (validaMail == 0){
                gotoxy(33,19);
                printf("%s", usuario->mail);
            }
        }
    }
    return salirRegistro;
}

void ModificarPerfil(stUsuario* usuario, int* huboCambios){
    int salirRegistro = 0;
    stUsuario* usuarioModificado;
    usuarioModificado = usuario;
    char palabra[MAIL]; // USO LA CONSTANTE MAIL YA QUE ES EL CAMPO MAS GRANDE POR LO TANTO EN ESE ARREGLO ENTRAN TODAS LAS ANTERIORES
    Color(NEGRO,AMARILLO);

    ModificarNombre(&salirRegistro, usuarioModificado, usuario);
    if (salirRegistro != ESC){
        salirRegistro = ModificarPalabra(usuarioModificado->address, usuario->address, 33,13, PHONE, AMARILLO, AMARILLO, LBLOCK);
    }
    if (salirRegistro != ESC){
        salirRegistro = ModificarPalabra(usuarioModificado->phone, usuario->phone, 33,16, PHONE, AMARILLO, AMARILLO, LBLOCK);
    }
    if (salirRegistro != ESC){
        salirRegistro = ModificarMail(usuarioModificado, usuario);
    }
    if (salirRegistro != ESC){
        GuardarInfoUsuario(archivoUsuarios, *usuarioModificado);
        usuario = usuarioModificado;
        *huboCambios = 1;
    }

}

int profileModification(stUsuario* usuario){
    int huboCambios = 0;

    int barraOpciones = 0;
    int barraBusqueda = 0;
    int perfilClave = 0;
    int cambioOk = 0;
    char validatePassword[PASSWORD];
    int validaIngreso = 0; /// VALIDA CADA CAMPO DEL FORMULARIO
    int resultado = 0; /// DEVOLVEMOS > 0 SI SE ESCRIBIO BIEN
    int salirRegistro = 0; /// PARA ESCAPAR DE LA CARGA DE DATOS
    char key;

    hidecursor(SI);
    editProfileWindow(); /// MOSTRAR MENU DE REGISTRO
    mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);

    do{
        fflush(stdin);
        key = getch();
        switch(key)
        {
        case F1:
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);
            break;
        case UNO: // Muestro el menu
            hidecursor(NO);
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);
            mostrarDatosUsuario(*usuario);
            ModificarPerfil(usuario, &huboCambios);
            hidecursor(SI);
            Color(NEGRO,AMARILLO);
            editProfileWindow();
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);
            break;
        case DOS: // LogIN
            /// Deslizar las ventanas
            hidecursor(SI);
            AnimacionVentanasPerfil();
            cambioOk = CambiarPassword(usuario);
            if (cambioOk == 1 ){
                /// Persistir clave
                GuardarInfoUsuario(archivoUsuarios, *usuario);
                huboCambios = 1;
            }
            editProfileWindow(); /// MOSTRAR MENU DE REGISTRO
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);
            break;
        case ESC: /// SALIR
            mostrarOcultarBarra(&barraOpciones, &barraBusqueda, MENUEDITPERFIL);
            break;
        }
    }
    while (key != ESC);
    hidecursor(SI);
    return huboCambios;
}

void menuAdmin(){
    administrador();
}
