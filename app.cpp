#include <iostream>
#include "app.h"
#include "acta.h"
#include "persona.h"
#include "criterioEvaluacion.h"
#include <ctime>
using std::cout;
using std::cin;
using std::string;
using std::endl;


App::App(){

    this->idPersonas = 1;

    this->idActas = 1;

    Persona NA( "NA", -1, false );

    this->personas.push_back(NA);
}


//Menu - desde aqui se llaman todas las demas funciones
void App::menu( ){

    int opcion, indexActa, indexPersona, opcionJuradoIE, opcTipoActa;
    string observacion;

    do{

        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n Bienvenido al sistema de actas " << endl;
        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n 1: Agregar Personas" << endl;
        cout << " 2: Crear Acta" << endl;
        cout << " 3: Modificar Acta" << endl;
        cout << " 4: Imprimir Acta" << endl;
        cout << " 5: Agregar observaciones adicionales" << endl;
        cout << " 6: Cerrar acta" << endl;
        cout << " 7: Mostrar trabajos de tipo aplicado" << endl;
        cout << " 8: Mostrar trabajos de tipo investigacion" << endl;
        cout << " 9: Mostrar trabajos de los que ha sido jurado una persona" << endl;
        cout << " 10: Mostrar trabajos que ha dirigido una persona" << endl;
        cout << " 11: Mostrar todos los jurados de las actas registradas" << endl;
        cout << " 12: Mostrar jurados por tipo [Externo] [Interno]" << endl;
        cout << " 13: Mostrar criterios de evaluacion" << endl;
        cout << " 14: Borrar acta" << endl;
        cout << " 15: Mostrar todas las actas" << endl;
        cout << " 16: Mostrar actas [Abierto] [Cerrado]" << endl;
        cout << " 17: Guardar acta en txt" << endl;
        cout << " 18: Salir" << endl;
        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\nSeleccione la opcion que desea realizar: ";
        cin >> opcion;

        switch ( opcion ){

            case 1:

                this->agregarPersona();
                break;

            case 2:

                this->crearActa();
                break;

            case 3:

                int opcionMenuModificar;

                do{

                    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
                    cout << "\nBienvenido al sistema de modificacion de actas " << endl;
                    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
                    cout << "\n 1: Modificar calificacion del jurado #1" << endl;
                    cout << " 2: Modificar calificacion del jurado #2" << endl;
                    cout << " 3: Modificar observaciones jurado #1" << endl;
                    cout << " 4: Modificar observaciones jurado #2" << endl;
                    cout << " 5: Volver al menu principal" << endl;
                    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
                    cout << "\nSeleccione la opcion que desea realizar: ";
                    cin >> opcionMenuModificar;

                    switch ( opcionMenuModificar ){

                        case 1:

                            agregarCalificacionJurado1();

                            break;

                        case 2:

                            agregarCalificacionJurado2();

                            break;

                        case 3:

                            agregarObservacionJurado1();

                            break;

                        case 4:

                            agregarObservacionJurado2();

                            break;

                        default:

                            break;
        
                    }

                }while( opcionMenuModificar != 5 );

                break;

            case 4:

                mostrarTodasActas();

                cout << "\nIngrese el numero del acta que desea imprimir: ";

                cin >> indexActa;

                indexActa--;

                imprimirActa(indexActa);

                break;

            case 5:

                if( actas.size() == 0 ){
                    cout << "No hay actas creadas" << endl;
                    break;
                }

                mostrarTodasActas();

                cout << "\nSeleccione el acta a modificar: ";

                cin >> indexActa;

                indexActa--;

                if( indexActa < 0 || indexActa > actas.size() ){
                    cout << "\nIndex invalido" << endl;
                    break;
                }

                cout << "\nIngrese la observacion adicional que desea agregar: ";
                cin.clear();
                fflush(stdin);
                std::getline(cin, observacion);

                agregarObservacionesAdicionalesActa( indexActa, observacion );

                break;

            case 6:

                mostrarTodasActas();

                cout << "\nSeleccione el acta a cerrar: ";

                cin >> indexActa;

                indexActa--;

                cerrarActa( indexActa );

                break;
                
            case 7:

                mostrarActasPorModalidad( INDUSTRIA );

                break;

            case 8:

                mostrarActasPorModalidad( INVESTIGACION );

                break;

            case 9:

                mostrarPersonas();

                cout << "\n\nSeleccione la persona a buscar: ";

                cin >> indexPersona;

                indexPersona--;

                trabajoJurado( indexPersona );

                break;

            case 10:

                mostrarPersonas();

                cout << "\n\nSeleccione la persona a buscar: ";

                cin >> indexPersona;

                indexPersona--;

                trabajoDirigidos( indexPersona );

                break;

            case 11:

                verJuradosActasRegistradas();

                break;

            case 12:

                cout << "[1]Externo [2]Externo";

                cin >> opcionJuradoIE;

                if( opcionJuradoIE == 1){

                    verJuradosIE( EXTERNO );

                }else{

                    verJuradosIE( INTERNO );

                }

                break;

            case 13:

                mostrarTodasActas();

                cout << "\nSeleccione el acta de la cual quiere conocer sus criterios de evaluacion: ";

                cin >> indexActa;

                indexActa--;

                mostrarCriteriosEvaluacion( indexActa);


            case 14:

                mostrarTodasActas();

                cout << "Seleccione el acta a borrar" << endl;

                cin >> indexActa;

                indexActa--;

                if( borrarActa( indexActa ) == false ){

                    cout << "\nHa seleccionado un acta cerrada..." << endl;

                }else{

                    cout << "\nActa borrada exitosamente..." << endl;

                }

                break;
            
            case 15:

                mostrarTodasActas();
                break;

            case 16:
                cout << "\nIngrese el tipo de actas que desea buscar [1] Abiertas [2]Cerradas: ";
                cin >> opcTipoActa;
                if( opcTipoActa == 1 ){
                    mostrarActasAC( ABIERTA );
                }else{
                    mostrarActasAC( CERRADA );
                }
                break;
            case 17:
                mostrarTodasActas();
                cout << "Acta: ";
                cin >> indexActa;
                indexActa--;
                imprimirATxt( indexActa );
                break;
            default:

                break;

        }

    }while( opcion != 18 );

}


//agrega una persona al vector de personas
void App::agregarPersona(){

    int continuar = 1;

    while(continuar == 1){

        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n        Agregando persona       " << endl;
        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
 
        string nombre;

        int tipoUniversidadEntero = 0;

        int tipoUniversidad;

        string tipoUniversidadString;

        cin.ignore(100, '\n');

        cout << "\nNombre: ";

        getline(cin, nombre);

        do{

            cout << "\nQue es esta persona respecto a la universidad? [1: Interno] | [2: Externo]: ";

            cin >> tipoUniversidadEntero;

            if(tipoUniversidadEntero == INTERNO){
                tipoUniversidadString = "Interno";
                tipoUniversidad = true;
                break;
            }

            else if(tipoUniversidadEntero == EXTERNO){
                tipoUniversidadString = "Externo";
                tipoUniversidad = false;
                break;
            }

            else{
                cout << "\nEl valor ingresado no es valido, por favor, intentalo de nuevo." << endl;
            }

        }while(true);

        Persona newPersona( nombre, idPersonas++, tipoUniversidad );
        this->personas.push_back( newPersona );

        cout << "\n" << nombre << " [" << tipoUniversidadString << "] agregado con exito." << endl;

        cout << "\nDesea continuar ingresando personas? [1: Si] [2: No]: ";

        cin >> continuar;

    }

}

// Genera la fecha del sistema en el formato "mes de dia de año", por ejemplo "17 de febrero de 2003".
string App::generarFecha(){

    string fecha;

    string mes;

    time_t now = time(0);

    tm *ltm = localtime(&now);

    if(1 + ltm->tm_mon == 1){
        mes = "enero";
    }

    else if(1 + ltm->tm_mon == 2){
        mes = "febrero";
    }

    else if(1 + ltm->tm_mon == 3){
        mes = "marzo";
    }

    else if(1 + ltm->tm_mon == 4){
        mes = "abril";
    }

    else if(1 + ltm->tm_mon == 5){
        mes = "mayo";
    }

    else if(1 + ltm->tm_mon == 6){
        mes = "junio";
    }

    else if(1 + ltm->tm_mon == 7){
        mes = "julio";
    }

    else if(1 + ltm->tm_mon == 8){
        mes = "agosto";
    }

    else if(1 + ltm->tm_mon == 9){
        mes = "septiembre";
    }

    else if(1 + ltm->tm_mon == 10){
        mes = "octubre";
    }

    else if(1 + ltm->tm_mon == 11){
        mes = "noviembre";
    }

    else if(1 + ltm->tm_mon == 12){
        mes = "diciembre";
    }

    string dia = std::to_string(ltm->tm_mday);

    string anio = std::to_string(1900 + ltm->tm_year);

    fecha = mes + " " + dia + " de " + anio;

    return fecha;

}

//genera un numero de acta concatenando idActas con periodo
//periodo : periodo en que se creo el acta
string App::generarNumeroActa( string periodo){
    string numero;
    numero = std::to_string(this->idActas++) + "-" + periodo;
    return numero;
}


//muestra las personas del vector personas
void App::mostrarPersonas(){

    int i;

    int indexPersonas;

    if( personas.size() == 1){

        cout << "No hay personas disponibles para mostrar." << endl;

    }

    else{

        for( i = 1; i < personas.size(); i++ ){

            cout <<" [" << i << "] " << personas[ i ].getNombre();

        }

    }

}

//Crear un acta
void App::crearActa(){

    if(personas.size() == 1){

        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n             Error              " << endl;
        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\nAgrega personas antes de intentar crear un acta." << endl;

    }

    else{
        
        string nombreDelTrabajo, autor, periodo, numero, enfasis, fecha, idAutor, observacionesAdicionales;

        int director, codirector = 0, jurado1, jurado2, modalidad, existenciaCoDirector;

        float nota = 0;

        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n          Creando acta          " << endl;
        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

        cout << "\nNombre del trabajo: ";

        cin.ignore(100, '\n');

        getline(cin, nombreDelTrabajo);

        cout << "\nAutor: ";
        getline(cin, autor);

        cout << "\nIngrese el ID del autor: ";

        getline(cin, idAutor);

        cout << "\nPeriodo: ";
        getline(cin, periodo);

        cout << "\nPersonas disponibles:";
        mostrarPersonas();

        cout << "\n\nIngrese el numero de la persona para asignarle el rol de Director: ";

        cin >> director;


        while(existenciaCoDirector){

            cout << "\nExiste un Co Director? [1: Si] [2: No]: ";

                cin >> existenciaCoDirector;

            if(existenciaCoDirector == 1){
                do{
                    cout << "\nIngrese el numero de la persona para asignarle el rol de Co Director: ";
                    cin >> codirector;
                    if( codirector == director ){
                        cout << "\nEl co-director no puede ser la misma pesona que el director..." << endl;
                    }
                }while( codirector == director );
                break;
            }

            //SE REQUIERE DE UNA U OTRA MANERA DECLARAR UN CODIRECTOR O EL CONSTRUCTOR DE ABAJO SE ROMPE POR COMPLETO

            else if(existenciaCoDirector == 2){
                codirector = 0;
                break;
            }

            else{
                cout << "\nEl valor ingresado no es valido, por favor, intentalo de nuevo." << endl;
            }
        }

        cin.ignore(100, '\n');

        cout << "\nIngrese el enfasis: ";
        getline(cin, enfasis);

        while(modalidad){

            cout << "\nModalidad [1: Investigacion] [2: Industria]: ";

            cin >> modalidad;

            if(modalidad == INVESTIGACION){
                break;
            }

            else if(modalidad == INDUSTRIA){
                break;
            }

            else{
                cout << "\nEl valor ingresado no es valido, por favor, intentalo de nuevo." << endl;
            }

        }     

        cout << "\nPersonas disponibles:";
        mostrarPersonas();
        do{
            cout << "\n\nIngrese el numero de la persona para signarle el rol de Jurado #1: ";
            cin >> jurado1;
            if( jurado1 == codirector || jurado1 == director ){
                cout << "\nEl jurado 1 no puede ser la misma persona que el co-director o director...";
            }
        }while( jurado1 == codirector || jurado1 == director );

        do{
            cout << "\nIngrese el numero de la persona para signarle el rol de Jurado #2: ";
            cin >> jurado2;
            if( jurado2 == codirector || jurado2 == director || jurado2 == jurado1 ){
                cout << "\nEl jurado 2 no puede ser la misma persona que el co-director, director o jurado 1...";
            }
        }while( jurado2 == codirector || jurado2 == director || jurado2 == jurado1 );
        numero = generarNumeroActa( periodo );
        fecha = generarFecha();

        if(codirector != 0){
            Acta nuevaActa( nombreDelTrabajo, autor, idAutor, periodo, this->personas[ director ], this->personas[ codirector ], enfasis, modalidad, this->personas[ jurado1 ], this->personas[ jurado2 ], fecha, numero, observacionesAdicionales, nota );
            this->actas.push_back( nuevaActa );
        }else{
            Acta nuevaActa( nombreDelTrabajo, autor, idAutor, periodo, this->personas[ director ], this->personas[ 0 ], enfasis, modalidad, this->personas[ jurado1 ], this->personas[ jurado2 ], fecha, numero, observacionesAdicionales, nota );
            this->actas.push_back( nuevaActa );
        }

        cout << "\nActa " << numero << " ha sido creada con exito." << endl;

    }

}

//verifica el rol que cumple una persona en determinada acta
//idPersona : es el id de la persona a buscar
//idActa : es el id del acta a buscar
int App::verificarPersona( int idPersona, int idActa ){
    int i;
    for( i = 0; i < this->actas.size(); i++ ){
        if( this->actas[i].getJurado1().getId() == idPersona || this->actas[i].getJurado2().getId() == idPersona || this->actas[i].getDirector().getId() == idPersona || this->actas[i].getCoDirector().getId() == idPersona){
            return i;
        }else{
            cout << "La persona identificada con el ID #[" << idPersona << "] no hace parte del acta." << endl;
            return -1;
        }
    }
    cout << "Acta [" << idActa << "] no fue encontrada." << endl;
    return -1;
}

//agrega una observacion a un acta como jurado 1
void App::agregarObservacionJurado1(){

    int indexActa, indexCriterioEvaluacion;

    string observacionJurado1;

    mostrarActasAC( false );

    cout << "\nIngrese el numero del acta en la que desea realizar modificaciones: ";

    cin >> indexActa;

    indexActa--;

    for(int i = 0; i < this->actas[ indexActa ].criteriosEvaluacion.size(); i++){

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n" << this->actas[ indexActa ].criteriosEvaluacion[i].getIdCriterio() << ". " << this->actas[ indexActa ].criteriosEvaluacion[i].getTitulo() << endl;
        cout << "\nCalificacion Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado1() << endl;
        cout << "\nCalificacion Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado2() << endl;
        cout << "\nPonderacion: " << this->actas[ indexActa ].criteriosEvaluacion[i].getPorcentajePonderacion() << "%" << endl;

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\nIngrese el numero del criterio de evaluacion en el que desea realizar modificar la observacion del jurado #1: ";

    cin >> indexCriterioEvaluacion;

    indexCriterioEvaluacion--;

    cout << "\nIngrese la observacion que desea ingresar para el criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": ";

    cin.ignore(100, '\n');

    getline(cin, observacionJurado1);

    this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].agregarObservacionJurado1( observacionJurado1 );

    cout << "\nObservacion agregada con exito al criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": " << endl;

}

//agrega una observacion a un acta como jurado 2
void App::agregarObservacionJurado2(){

    int indexActa, indexCriterioEvaluacion;

    string observacionJurado2;

    mostrarActasAC( false );

    cout << "\nIngrese el numero del acta en la que desea realizar modificaciones: ";

    cin >> indexActa;

    indexActa--;

    for(int i = 0; i < this->actas[ indexActa ].criteriosEvaluacion.size(); i++){

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n" << this->actas[ indexActa ].criteriosEvaluacion[i].getIdCriterio() << ". " << this->actas[ indexActa ].criteriosEvaluacion[i].getTitulo() << endl;
        cout << "\nCalificacion Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado1() << endl;
        cout << "\nCalificacion Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado2() << endl;
        cout << "\nPonderacion: " << this->actas[ indexActa ].criteriosEvaluacion[i].getPorcentajePonderacion() << "%" << endl;

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\nIngrese el numero del criterio de evaluacion en el que desea realizar modificar la observacion del jurado #1: ";

    cin >> indexCriterioEvaluacion;

    indexCriterioEvaluacion--;

    cout << "\nIngrese la observacion que desea ingresar para el criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": ";

    cin.ignore(100, '\n');

    getline(cin, observacionJurado2);

    this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].agregarObservacionJurado2( observacionJurado2 );

    cout << "\nObservacion agregada con exito al criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": " << endl;

}

//agrega la calificacion a un acta como jurado 1
void App::agregarCalificacionJurado1(){

    int indexActa, indexCriterioEvaluacion;

    float calificacionJurado1;

    mostrarActasAC( false );

    cout << "\nIngrese el numero del acta en la que desea realizar modificaciones: ";

    cin >> indexActa;

    indexActa--;

    for(int i = 0; i < this->actas[ indexActa ].criteriosEvaluacion.size(); i++){

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n" << this->actas[ indexActa ].criteriosEvaluacion[i].getIdCriterio() << ". " << this->actas[ indexActa ].criteriosEvaluacion[i].getTitulo() << endl;
        cout << "\nCalificacion Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado1() << endl;
        cout << "\nCalificacion Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado2() << endl;
        cout << "\nPonderacion: " << this->actas[ indexActa ].criteriosEvaluacion[i].getPorcentajePonderacion() << "%" << endl;

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\nIngrese el numero del criterio de evaluacion en el que desea realizar modificar la calificacion del jurado #1: ";

    cin >> indexCriterioEvaluacion;

    indexCriterioEvaluacion--;

    cout << "\nIngrese la calificacion que desea ingresar para el criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": ";

    cin >> calificacionJurado1;

    this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].agregarCalificacionJurado1( calificacionJurado1 );

    cout << "\nCalificacion agregada con exito al criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": " << endl;

}

//agrega la calificacion a un acta como jurado 2
void App::agregarCalificacionJurado2(){
    int indexActa, indexCriterioEvaluacion;
    
    float calificacionJurado2;

    mostrarActasAC( false );

    cout << "\nIngrese el numero del acta en la que desea realizar modificaciones: ";

    cin >> indexActa;

    indexActa--;

    for(int i = 0; i < this->actas[ indexActa ].criteriosEvaluacion.size(); i++){

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n" << this->actas[ indexActa ].criteriosEvaluacion[i].getIdCriterio() << ". " << this->actas[ indexActa ].criteriosEvaluacion[i].getTitulo() << endl;
        cout << "\nCalificacion Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado1() << endl;
        cout << "\nCalificacion Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado2() << endl;
        cout << "\nPonderacion: " << this->actas[ indexActa ].criteriosEvaluacion[i].getPorcentajePonderacion() << "%" << endl;

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\nIngrese el numero del criterio de evaluacion en el que desea realizar modificar la calificacion del jurado #2: ";

    cin >> indexCriterioEvaluacion;

    indexCriterioEvaluacion--;

    cout << "\nIngrese la calificacion que desea ingresar para el criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": ";

    cin >> calificacionJurado2;

    this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].agregarCalificacionJurado2( calificacionJurado2 );

    cout << "\nCalificacion agregada con exito al criterio #" << this->actas[ indexActa ].criteriosEvaluacion[ indexCriterioEvaluacion ].getIdCriterio() << ": " << endl;

}

//identifica el rol que cumple una persona en determinada acta
//idPersona : es el id de la persona a buscar
//indexActa : es el index en el vector de actas del acta
int App::identificarRolActa( int idPersona, int indexActa ){

    if( this->actas[ indexActa ].getJurado1().getId() == idPersona ){
        return JURADO1;
    }else if( this->actas[ indexActa ].getJurado2().getId() == idPersona ){
        return JURADO2;
    }else if( this->actas[ indexActa ].getDirector().getId() == idPersona ){
        return DIRECTOR;
    }else{
        return CODIRECTOR;
    }

    return -1;
}

//imprime las actas dependiendo de la modalidad seleccionada
//modalidad : es un entero que indica la modalidad a mostrar
void App::mostrarActasPorModalidad( int modalidad ){

    int i, contador = 0;

    cout << "Modalidad: ";

    if( modalidad == INVESTIGACION ){

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

        cout << "\n          Actas Disponibles Investigacion           " << endl;

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    }else{

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

        cout << "\n             Actas Disponibles Industria            " << endl;

        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    }

    for(i = 0; i < this->actas.size(); i++ ){

        if( this->actas[i].getModalidad() == modalidad ){

            imprimirActa( i );
            contador++;

        }
        
    }

    if(contador == 0){
        cout << "\nNo hay actas de ese tipo" << endl;
    }

}

//Imprime el acta seleccionada
//indexActa : es el index en el vector actas de acta
void App::imprimirActa( int indexActa ){

    string modalidadImprimir;

    string estadoCerrada;

    
    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\n             Facultad de Ingenieria                 " << endl;

    cout << "\n             Maestria en Ingenieria                 " << endl;

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\nFecha: " << this->actas[ indexActa ].getFecha() <<"  "<< endl;

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\nActa: " << this->actas[ indexActa].getNumero() << "                       "<< endl;

    cout << "\nTrabajo de grado denominado: "<< this->actas[ indexActa ].getNombreTrabajo() << endl; 

    cout << "\nAutor: " << this->actas[ indexActa ].getAutor() << endl;

    cout << "\nPeriodo: " << this->actas[ indexActa ].getPeriodo() << endl;

    cout << "\nDirector: " << this->actas[ indexActa ].getDirector().getNombre() << endl;

    cout << "\nCo-Director: " << this->actas[ indexActa ].getCoDirector().getNombre() << endl;

    if(this->actas[ indexActa ].getModalidad() == 1){
        modalidadImprimir = "Investigacion";
    }
    
    else{
        modalidadImprimir = "Industria";
    }

    cout << "\nEnfasis: " << modalidadImprimir << endl;

    cout << "\nJurado 1: " << this->actas[ indexActa ].getJurado1().getNombre() << endl;

    cout << "\nJurado 2: " << this->actas[ indexActa ].getJurado2().getNombre() << endl;

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\n                Criterios de Evaluacion             " << endl;

    for(int i = 0; i < this->actas[ indexActa ].criteriosEvaluacion.size(); i++){
        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n" << this->actas[ indexActa ].criteriosEvaluacion[i].getIdCriterio() << ". " << this->actas[ indexActa ].criteriosEvaluacion[i].getTitulo() << endl;
        cout << "\nCalificacion Parcial Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado1() << endl;
        cout << "\nCalificacion Parcial Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado2() << endl;
        cout << "\nPonderacion: " << this->actas[ indexActa ].criteriosEvaluacion[i].getPorcentajePonderacion() << "%" << endl;
        cout << "\nObservaciones Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getObservacionJurado1() << endl;
        cout << "\nObservaciones Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getObservacionJurado2() << endl;

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    calcularNotaFinal( indexActa );

    cout << "\nComo resultado de estas calificaciones parciales y sus podenceraciones, la calificacion del Trabajo de Grado es: " << this->actas[ indexActa ].getNotaFinal() << endl;

    cout << "\nObservaciones Adicionales: " << this->actas[ indexActa ].getObservacionesAdicionales() << endl;

    

    if(this->actas[ indexActa ].estadoCerrada() == 0){
        estadoCerrada = "Abierta";
    }
    
    else{
        estadoCerrada = "Cerrada";
    }

    cout << "\nEstado del Acta: " << estadoCerrada << endl;

}

//muestra los trabajos que ha dirigido una persona
//indexPersona es el index en el vector personas de la persona
void App::trabajoDirigidos( int indexPersona ){

    int idPersona = this->personas[ indexPersona ].getId();

    int i, counter = 0;

    for( i = 0; i < this->actas.size(); i++ ){

        if( this->actas[i].getDirector().getId() == idPersona ){

            counter++;

            cout << this->actas[i].getNombreTrabajo() << " por " << this->actas[i].getAutor() << endl;
        }

        cout << "\nTrabajos dirigidos: " << counter << endl;
    }

}

//muestra los criterios de evaluacion del acta
//indexActa : es el index del acta en el vector actas
void App::mostrarCriteriosEvaluacion( int indexActa){

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\n                Criterios de Evaluacion             " << endl;

    for(int i = 0; i < this->actas[ indexActa ].criteriosEvaluacion.size(); i++){
        cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n" << this->actas[ indexActa ].criteriosEvaluacion[i].getIdCriterio() << ". " << this->actas[ indexActa ].criteriosEvaluacion[i].getTitulo() << endl;
        cout << "\nCalificacion Parcial Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado1() << endl;
        cout << "\nCalificacion Parcial Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionJurado2() << endl;
        cout << "\nPonderacion: " << this->actas[ indexActa ].criteriosEvaluacion[i].getPorcentajePonderacion() << "%" << endl;
        cout << "\nObservaciones Jurado #1: " << this->actas[ indexActa ].criteriosEvaluacion[i].getObservacionJurado1() << endl;
        cout << "\nObservaciones Jurado #2: " << this->actas[ indexActa ].criteriosEvaluacion[i].getObservacionJurado2() << endl;

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>===<>===<>===<>===<>" << endl;
}

void App::trabajoJurado( int indexPersona ){

    int idPersona = this->personas[ indexPersona ].getId();

    int i, counter = 0;

    for( i = 0; i < this->actas.size(); i++ ){

        if( ( this->actas[i].getJurado1().getId() == idPersona ) || ( this->actas[i].getJurado2().getId() == idPersona ) ){

            counter++;

            cout << this->actas[i].getNombreTrabajo() << " por " << this->actas[i].getAutor() << endl;

        }

        cout << "\nTrabajos de los que ha sido jurado: " << counter << endl;

    }

}

//Muestra todos los jurados de las actas registradas
void App::verJuradosActasRegistradas( ){

    int i, j;

    vector<Persona> juradosRepetidos;

    vector<Persona> jurados;

    bool agregado;

    //Agrega las personas que han sido jurados

    for( i = 0; i < this->personas.size(); i++ ){

        for( j = 0; j < this->actas.size(); j++ ){

            if( this->personas[i].getId() == this->actas[j].getJurado1().getId() || this->personas[i].getId() == this->actas[j].getJurado2().getId() ){

                juradosRepetidos.push_back( this->personas[i] );

            }

        }

    }


    //Crea el vector con jurados no repetidos
    for( i = 0; i < juradosRepetidos.size(); i++ ){
        agregado = false;
        for( j = 0; j < jurados.size(); j++ ){
            if( juradosRepetidos[i].getId() == jurados[j].getId() ){
                agregado = true;
            }
        }
        if( !agregado ){
            jurados.push_back( juradosRepetidos[ i ] );
        }
    }

    for( i = 0; i < jurados.size(); i++ ){
        cout << jurados[i].getNombre() << endl;
    }
    
}



//Muestra todas las actas en el vector actas
void App::mostrarTodasActas( ){

    string estadoCerradaString;

    int i;

    cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\n        Actas Disponibles       " << endl;

    cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

    for( i = 0; i < this->actas.size(); i++ ){

        if(this->actas[i].getCerrada() == false){

            estadoCerradaString = "Abierta";

        }

        else{

            estadoCerradaString = "Cerrada";

        }

        cout << "\n[" <<  (i + 1) << "] | " << this->actas[i].getNumero() << " | " << this->actas[i].getFecha() << " | " << this->actas[i].getAutor() << " | " << this->actas[i].getNotaFinal() << " | " << estadoCerradaString << endl;

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

}

//muestra las actas abiertas o cerradas
//cerrada : indica el tipo de acta a buscar, abierta o cerrada
void App::mostrarActasAC( bool cerrada ){

    int i;

    cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

    cout << "\n        Actas Disponibles       " << endl;

    cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

    for( i = 0; i < this->actas.size(); i++ ){

        if( this->actas[i].estadoCerrada() == cerrada ){

            cout << "\n[" <<  (i + 1) << "] | " << this->actas[i].getNumero() << " | " << this->actas[i].getFecha() << " | " << this->actas[i].getAutor() << endl;

        }else if( this->actas[i].estadoCerrada() == !cerrada ){

            cout << "\n[" <<  (i + 1) << "]" << this->actas[i].getNumero() << " | " << this->actas[i].getFecha() << " | " << this->actas[i].getAutor() << endl;

        }

    }

    cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

}

//borra un acta
//indexActa : es el index en el vector actas del acta a borrar
bool App::borrarActa( int indexActas ){

    if( this->actas[indexActas].estadoCerrada() == ABIERTA ){
        this->actas.erase( this->actas.begin() + indexActas );
        return true;
    }
    return false;
}

//calcula la nota final de un acta
//indexActas : es el index del acta a borrar en el vector actas
void App::calcularNotaFinal( int indexActas ){

    int i;
    
    float notaFinal = 0;

    try{
        if( indexActas < 0 || indexActas > this->actas.size() ){
            throw( indexActas );
        }
        for(i = 0; i < this->actas[ indexActas ].criteriosEvaluacion.size(); i++){
            notaFinal += this->actas[ indexActas ].criteriosEvaluacion[i].getCalificacionCriterio();
        }
        this->actas[indexActas].setNotaFinal( notaFinal );
        if( notaFinal > 3.5 ){
            this->actas[indexActas].setAprobada( APROBADA );
        }else{
            this->actas[indexActas].setAprobada( REPROBADA );
        }

    }catch( int index ){
        cout << "Ha seleccionado un numero invaliado para el acta." << endl;
    }

}

//Cerrar acta
//indexActa : es el index del acta a cerrar en el vector actas
void App::cerrarActa( int indexActa ){
    calcularNotaFinal( indexActa );
    cout << "\nActa #" << indexActa+1 << " cerrada con exito.";
    this->actas[ indexActa ].setCerrada( CERRADA );
}


//Ver jurados internos y externos
//IE : InternoExterno
void App::verJuradosIE( bool IE ){
    int i, j;
    vector<Persona> juradosRepetidos;
    vector<Persona> jurados;
    bool agregado;
    //Agrega las personas que han sido jurados
    for( i = 0; i < this->personas.size(); i++ ){
        for( j = 0; j < this->actas.size(); j++ ){
            if( (this->personas[i].getId() == this->actas[j].getJurado1().getId() || this->personas[i].getId() == this->actas[j].getJurado2().getId()) && (this->personas[i].getTipoUniversidad() == IE) ){
                juradosRepetidos.push_back( this->personas[i] );
            }
        }
    }

    //Crea el vector con jurados no repetidos
    for( i = 0; i < juradosRepetidos.size(); i++ ){
        agregado = false;
        for( j = 0; j < jurados.size(); j++ ){
            if( juradosRepetidos[i].getId() == jurados[j].getId() ){
                agregado = true;
            }
        }
        if( !agregado ){
            jurados.push_back( juradosRepetidos[ i ] );
        }
    }

    //Imprime los jurados
    for( i = 0; i < jurados.size(); i++ ){
        cout << jurados[i].getNombre() << endl;
    }
    
    return;
}

//Agregar observaciones adicional
//indexActa : es el index del acta en el vector actas
//observacion : es la observacion a adicionar en el acta
void App::agregarObservacionesAdicionalesActa( int indexActa, string observacion ){
    this->actas[indexActa].agregarObservacionAdicional( observacion );
    return;
}

//Imprime a un txt el acta seleccionada
//indexActa : es el index del acta en el vector actas
void App::imprimirATxt( int indexActa ){
    string fileName;
    int i;
    cout << "nombre del archivo: ";
    cin >> fileName;


    ofstream archivoActa(fileName);


    archivoActa << this->actas[ indexActa ].getNumero() << "               " << this->actas[ indexActa ].getFecha() << endl;
    archivoActa << "               ACTA DE EVALUACIÓN DE TRABAJO DE GRADO" << endl;
    archivoActa << "               "  << this->actas[ indexActa ].getNombreTrabajo() << endl;
    archivoActa << "Autor: " << this->actas[ indexActa ].getAutor();
    archivoActa << "Periodo: " << this->actas[ indexActa ].getPeriodo() << endl;
    archivoActa << "Director: " << this->actas[ indexActa ].getDirector().getNombre() << endl;
    archivoActa << "Co-director: " << this->actas[ indexActa ].getCoDirector().getNombre() << endl;
    archivoActa << "Jurado 1: " << this->actas[ indexActa ].getJurado1().getNombre() << endl;
    archivoActa << "Jurado 2: " << this->actas[ indexActa ].getJurado2().getNombre() << endl;

    for( i = 0; i < this->actas[ indexActa ].criteriosEvaluacion.size(); i++ ){
        archivoActa << this->actas[ indexActa ].criteriosEvaluacion[i].getIdCriterio() << "  " << this->actas[ indexActa ].criteriosEvaluacion[i].getTitulo() << endl;
        archivoActa << "Calificación parcial: " << this->actas[ indexActa ].criteriosEvaluacion[i].getCalificacionCriterio() << "               " << this->actas[ indexActa ].criteriosEvaluacion[i].getPorcentajePonderacion() << "%" << endl;
        archivoActa << "Observaciones: " << this->actas[ indexActa ].criteriosEvaluacion[i].getObservacionJurado1() << endl;
        archivoActa << this->actas[ indexActa ].criteriosEvaluacion[i].getObservacionJurado2() << endl;
        archivoActa << "___________________________________________________________" << endl;
        archivoActa << "___________________________________________________________" << endl;
    }
    cout << "Archivo creado con exito." << endl;
    return;
}