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

// Constructor por defecto de la clase App que inicializa todo el programa en sí.

App::App(){

    Persona NA( "NA", -1, false );

    this->personas.push_back(NA);
}

// Menú para muestra y selección de las diferentes opciones dentro del programa.

void App::menu( ){

    int opc;

    do{

        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n 1: Agregar Personas" << endl;
        cout << " 2: Crear Acta" << endl;
        cout << " 3: Agregar observacion" << endl;
        cout << " 4: Agregar observaciones adicionales" << endl;
        cout << " 4: Cerrar acta" << endl;
        cout << " 5: Salir" << endl;
        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\nSeleccione la opcion que desea realizar: ";
        cin >> opc;

        switch ( opc ){

        case 1:

            this->agregarPersona();
            break;

        case 2:

            this->crearActa();
            break;

        case 3:

            this->imprimirActa(0);

            break;

        case 4:

            break;

        default:

            break;

    }

    }while( opc != 5 );

}

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
            }

            else if(tipoUniversidadEntero == EXTERNO){
                tipoUniversidadString = "Externo";
                tipoUniversidad = false;
            }

            else{
                cout << "\nEl valor ingresado no es valido, por favor, intentalo de nuevo." << endl;
            }

        }while(tipoUniversidadEntero == 1 || tipoUniversidadEntero == 2);

        //Hago uso de malas prácticas (break) dentro de este while, debido a que nunca logré hacerlo funcionar bien poniendo la condición como debería ser.

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

// FUNCION ON HOLD


string App::generarNumeroActa( string periodo){
    string numero;
    numero = this->idActas++ + "-" + periodo;
    return numero;
}


void App::mostrarPersonas(){

    int i;

    int indexPersonas;

    if( personas.size() == 1){

        cout << "No hay personas disponibles para mostrar." << endl;

    }

    else{

        for( i = 0; i < personas.size(); i++ ){

            cout <<" [" << i+1 << "] " << personas[ i ].getNombre();

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
        
        string nombreDelTrabajo, autor, periodo, numero, enfasis, fecha;

        int director, codirector, jurado1, jurado2, modalidad, existenciaCoDirector;

        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << "\n          Creando acta          " << endl;
        cout << "\n<>===<>===<>===<>===<>===<>===<>" << endl;

        cout << "\nNombre del trabajo: ";

        cin.ignore(100, '\n');

        getline(cin, nombreDelTrabajo);

        cout << "\nAutor: ";
        getline(cin, autor);

        cout << "\nPeriodo: ";
        cin >> periodo;

        cout << "\nPersonas disponibles:";
        mostrarPersonas();

        cout << "\n\nIngrese el numero de la persona para asignarle el rol de Director: ";

        cin >> director;

        director--;

        while(existenciaCoDirector){

            cout << "\nExiste un Co Director? [1: Si] [2: No]: ";

            cin >> existenciaCoDirector;

            if(existenciaCoDirector == 1){
                cout << "\nIngrese el numero de la persona para asignarle el rol de Co Director: ";
                cin >> codirector;
                codirector--;
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

        cout << "\n\nIngrese el numero de la persona para signarle el rol de Jurado #1: ";
        cin >> jurado1;
        jurado1--;

        cout << "\nIngrese el numero de la persona para signarle el rol de Jurado #2: ";
        cin >> jurado2;
        jurado2--;

        numero = generarNumeroActa( periodo );
        generarFecha();

        if(codirector != 0){
            Acta nuevaActa( autor, periodo, this->personas[ director ], this->personas[ codirector ], enfasis, modalidad, this->personas[ jurado1 ], this->personas[ jurado2 ], fecha );
            this->actas.push_back( nuevaActa );
        }else{
            Acta nuevaActa( autor, periodo, this->personas[ director ], this->personas[ 0 ], enfasis, modalidad, this->personas[ jurado1 ], this->personas[ jurado2 ], fecha );
            this->actas.push_back( nuevaActa );
        }

        cout << "\nActa " << numero << " sido creada con exito." << endl;

    }

}

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

void App::agregarObservacionJurado1( int indexActa, int idCriterio, string observacionJurado1 ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].agregarObservacionJurado1( observacionJurado1 );
    cout << "Observacion agregada." << endl;
    return;
}

void App::agregarObservacionJurado2( int indexActa, int idCriterio, string observacionJurado2 ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].agregarObservacionJurado2( observacionJurado2 );
    cout << "Observacion agregada." << endl;
    return;
}

void App::borrarObservacionJurado1( int indexActa, int idCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].borrarObservacionJurado1( );
    cout << "Observacion borrada." << endl;
    return;
}

void App::borrarObservacionJurado2( int indexActa, int idCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].borrarObservacionJurado1( );
    cout << "Observacion borrada." << endl;
    return;
}

void App::agregarCalificacionJurado1( int indexActa, int idCriterio, float calificacion ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].agregarCalificacionJurado1( calificacion );
    cout << "Calificacion agregada." << endl;
    return;
}

void App::agregarCalificacionJurado2( int indexActa, int idCriterio, float calificacion ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].agregarCalificacionJurado2( calificacion );
    cout << "Calificacion agregada." << endl;
    return;
}

void App::borrarCalificacionJurado1( int indexActa, int idCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].borrarCalificacionJurado1();
    cout << "Calificacion borrada." << endl;
    return;
}

void App::borrarCalificacionJurado2( int indexActa, int idCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ idCriterio ].borrarCalificacionJurado2();
    cout << "Calificacion borrada." << endl;
    return;
}

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

void App::mostrarActasPorModalidad( int modalidad ){
    int i;
    cout << "Modalidad : ";
    if( modalidad == INVESTIGACION ){
        cout << "Investigacion" << endl;
    }else{
        cout << "Industria" << endl;
    }

    for(i = 0; i < this->actas.size(); i++ ){
        if( this->actas[i].getModalidad() == modalidad ){
            imprimirActa( i );
        }
    }
    return;
}

void App::imprimirActa( int indexActa ){
    
    cout << this->actas[ indexActa ].getNombreTrabajo() << endl;
    cout << this->actas[ indexActa ].getFecha() << endl;
    cout << this->actas[ indexActa ].getPeriodo() << endl;
    cout << this->actas[ indexActa ].getAutor() << endl;    
    cout << this->actas[ indexActa ].getModalidad() << endl;
    // cout << this->actas[ indexActa ].getNumero() << endl;
    cout << this->actas[ indexActa ].getId() << endl;
    cout << this->actas[ indexActa ].getJurado1().getNombre() << endl;
    cout << this->actas[ indexActa ].getJurado2().getNombre() << endl;
    cout << this->actas[ indexActa ].getDirector().getNombre() << endl;
    cout << this->actas[ indexActa ].getCoDirector().getNombre() << endl;
    cout << this->actas[ indexActa ].estadoCerrada() << endl;

}

void App::trabajoDirigidos( int indexPersona ){
    int idPersona = this->personas[ indexPersona ].getId();
    int i, counter = 0;
    for( i = 0; i < this->actas.size(); i++ ){
        if( this->actas[i].getDirector().getId() == idPersona ){
            counter++;
            cout << this->actas[i].getNombreTrabajo() << " por " << this->actas[i].getAutor() << endl;
        }
        cout << "Trabajos dirigidos: " << counter << endl;
    }
    return;

}

// Aqui queda el metodo de saber de que trabajos ha sido jurado una persona

void App::trabajoJurado( int indexPersona ){
    int idPersona = this->personas[ indexPersona ].getId();
    int i, counter = 0;
    for( i = 0; i < this->actas.size(); i++ ){
        if( ( this->actas[i].getJurado1().getId() == idPersona ) || ( this->actas[i].getJurado2().getId() == idPersona ) ){
            counter++;
            cout << this->actas[i].getNombreTrabajo() << " por " << this->actas[i].getAutor() << endl;
        }
        cout << "Trabajos de los que ha sido jurado: " << counter << endl;
    }
    return;

}

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

    //Imprime los jurados
    for( i = 0; i < jurados.size(); i++ ){
        cout << jurados[i].getNombre() << endl;
    }
    
    return;
}



//Muestra todas las actas en el vector actas
void App::mostrarTodasActas( ){
    int i;
    cout << "====Todas las actas====" << endl;
    for( i = 0; i < this->actas.size(); i++ ){
        cout << this->actas[i].getNumero() << "-" << this->actas[i].getFecha() << "-" << this->actas[i].getAutor() << "-" << this->actas[i].getNota() << "-" << this->actas[i].estadoCerrada() << endl;
    }
    cout << "=======================" << endl;
    return;
}

//Muestra actas todas las abiertas o todas las actas cerradas
//bool cerrada: cuando True muestra las cerradas, cuando False muestra las Abiertas
void App::mostrarActasAC( bool cerrada ){
    int i;
    cout << "====Todas las actas====" << endl;
    for( i = 0; i < this->actas.size(); i++ ){
        if( this->actas[i].estadoCerrada() == cerrada ){
            cout << this->actas[i].getNumero() << "-" << this->actas[i].getFecha() << "-" << this->actas[i].getAutor() << "-" << this->actas[i].getNota() << "-" << this->actas[i].estadoCerrada() << endl;
        }else if( this->actas[i].estadoCerrada() == !cerrada ){
            cout << this->actas[i].getNumero() << "-" << this->actas[i].getFecha() << "-" << this->actas[i].getAutor() << "-" << this->actas[i].getNota() << "-" << this->actas[i].estadoCerrada() << endl;
        }
    }
    cout << "=======================" << endl;
    return;
}

bool App::borrarActa( int indexActas ){

    if( this->actas[indexActas].estadoCerrada() == ABIERTA ){
        this->actas.erase( this->actas.begin() + indexActas );
        return true;
    }
    return false;
}

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
void App::cerrarActa( int indexActa ){
    this->actas[ indexActa ].setCerrada( CERRADA );
}


//Ver jurados internos y externos
//IE : Interno
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
void App::agregarObservacionesAdicionalesActa( int indexActa, string observacion ){
    this->actas[indexActa].agregarObservacionAdicional( string observacion );
    return;
}

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