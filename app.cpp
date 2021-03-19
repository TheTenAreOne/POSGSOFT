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

App::App(){}

// Menú para muestra y selección de las diferentes opciones dentro del programa.

void App::menu( ){

    int opc;

    do{
        cout << "<>===<>===<>===<>===<>===<>===<>" << endl;
        cout << " 1 : Agregar persona" << endl;
        cout << " 2 : Crear acta" << endl;
        cout << " 3 : Agregar observacion" << endl;
        cout << " 4 : Cerrar acta" << endl;
        cout << " 5 : Salir" << endl;
        cin >> opc;
    }while( opc != 5 );

    switch ( opc )
    {
    case 1:
        agregarPersona();
        break;
    case 2:
        crearActa();
        break;
    case 3:

        break;
    case 4:
        break;
    default:
        break;
    }

    return;
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

string App::generarNumeroActa( string periodo){
    string numero;
    numero = this->idActas++ + "-" + periodo;
    return numero;
}

void App::mostrarPersonas(){
    int i;
    int indexPersonas;
    cout << "[" << 0 << "]"<< "N/A" << endl;
    for( i = 0; i < personas.size(); i++ ){
        cout <<"[" << i+1 << "] " << personas[ i ].getNombre();
    }
    return;
}

//Crear un acta

void App::crearActa(){
    string nombreDelTrabajo, autor, periodo, numero, enfasis, fecha, existenciaCoDirector;
    int director, codirector, jurado1, jurado2, modalidad;
    cout << "<>===<>===<>===<>===<>===<>===<>" << endl;
    cout << "             Creando acta" << endl;

    cout << "Nombre del trabajo: " << endl;
    cin >> nombreDelTrabajo;

    cout << "Autor: " << endl;
    cin >> autor;

    cout << "Periodo: " << endl;
    cin >> periodo;

    cout << "Personas disponibles: " << endl;
    mostrarPersonas();

    cout << "Ingresar numero de persona para elegir rol: " << endl;
    cout << "Director: " << endl;
    cin >> director;
    director--;

    cout << "¿Existe un Co Director? [Si] [No]: " << endl;

    cin >> existenciaCoDirector;

    if( existenciaCoDirector == "Si"){

        cout << "Co director: " << endl;
        cin >> codirector;
        codirector--;

    }

    // DANIEL REVISAME

    //Necesito ayuda para hacer bien este condicional // DANIEL REVISAME // Permita a la asistente de la maestría crear una nueva acta: Esta acta tiene la información de la fecha, el número del acta, nombre del estudiante, nombre del trabajo, tipo de trabajo, director, codirector (si existe), jurado 1 y jurado 2.  El estado del acta cuando es creada por la asistente es “abierto”. 

    // DANIEL REVISAME

    cout << "Enfasis en: " << endl;
    cin >> enfasis;

    cout << "Modalidad [1:Investigacion] [2:Industria]" << endl;
    cin >> modalidad;

    cout << "Personas disponibles: " << endl;
    mostrarPersonas();

    cout << "Jurado #1: " << endl;
    cin >> jurado1;
    jurado1--;

    cout << "Jurado #2: " << endl;
    cin >> jurado2;
    jurado2--;

    numero = generarNumeroActa( periodo );
    generarFecha( );

    Acta nuevaActa( autor, periodo, this->personas[ director ], this->personas[ codirector ], enfasis, modalidad, this->personas[ jurado1 ], this->personas[ jurado2 ], fecha );
    this->actas.push_back( nuevaActa );
    cout << "Acta creada" << endl;

    return;

}

int App::verificarPersona( int idPersona, int idActa ){
    int i;
    for( i = 0; i < this->actas.size(); i++ ){
        if( this->actas[i].getJurado1().getId() == idPersona || this->actas[i].getJurado2().getId() == idPersona || this->actas[i].getDirector().getId() == idPersona || this->actas[i].getCoDirector().getId() == idPersona){
            return i;
        }else{
            cout << "El usuario [" << idPersona << "] no hace parte del acta." << endl;
            return -1;
        }
    }
    cout << "Acta [" << idActa << "] no fue encontrada." << endl;
    return -1;
}

void App::agregarPersona( ){
    string nombre;
    bool tipoUniversidad;

    cout << "Nombre: " << endl;
    cin >> nombre;

    cout << "Interno o externo a la universidad: " << endl;
    cout << "[1:Interno]|[2:Externo]" << endl;
    cin >> tipoUniversidad;

    Persona newPersona( nombre, idPersonas++, tipoUniversidad );
    this->personas.push_back( newPersona );

    cout << nombre << "[" << tipoUniversidad << "] agregado." << endl;
    
    return;
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
    cout << this->actas[ indexActa ].getNumero() << endl;
    cout << this->actas[ indexActa ].getId() << endl;
    cout << this->actas[ indexActa ].getJurado1().getNombre() << endl;
    cout << this->actas[ indexActa ].getJurado2().getNombre() << endl;
    cout << this->actas[ indexActa ].getDirector().getNombre() << endl;
    cout << this->actas[ indexActa ].getCoDirector().getNombre() << endl;
    cout << this->actas[ indexActa ].estadoCerrada() << endl;

    return;
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



//DANIEL LEEEME

//DANIEL LEEME

// PQ HAY DOS DE ESTAS FUNCIONES, PQ UNA ES AC Y LA OTRA NO, QUE HACEN

void App::mostrarTodasActas( ){
    int i;
    cout << "====Todas las actas====" << endl;
    for( i = 0; i < this->actas.size(); i++ ){
        cout << this->actas[i].getNumero() << "-" << this->actas[i].getFecha() << "-" << this->actas[i].getAutor() << "-" << this->actas[i].getNota() << "-" << this->actas[i].estadoCerrada() << endl;
    }
    cout << "=======================" << endl;
    return;
}

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
    }
    return false;
}
