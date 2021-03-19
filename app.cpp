#include <iostream>
#include "app.h"
#include "acta.h"
#include "persona.h"
#include "criterioEvaluacion.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;

App::App(){}

//Métodos App

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
//Crear un acta
void App::crearActa(){
    string nombreDelTrabajo, autor, periodo, numero, enfasis, fecha;
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

    cout << "Co director: " << endl;
    cin >> codirector;
    codirector--;

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

//Agrega una persona
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

//Verifica que la persona con idPersona haga parte del acta (ya sea director o jurado)
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

// Cambia la observacion del criterio nCriterio de acta[ indexActa ] a observacion
//indexActa : index para el vector de actas
//nCriterio : index para el vector de criterioEvaluacion
//observacion : observacion a agregar
void App::agregarObservacion( int indexActa, int nCriterio, string observacion ){

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].agregarObservacion( observacion );
    cout << "Observacion agregada." << endl;
    return;
}

// Borra la observacion del criterio nCriterio de acta[ indexActa ]
//indexActa : index para el vector de actas
//nCriterio : index para el vector de criterioEvaluacion
void App::borrarObservacion( int indexActa, int nCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].borrarObservacion( );
    cout << "Observacion borrada." << endl;
    return;
}

// [ C1, C2, C3, C4, C5, C6, C7, C8 ]



// Cambia la calificacion de la calificacion nCriterio de acta[ indexActa ] a la calificacion ingresada
//indexActa : index para el vector de actas
//nCriterio : index para el vector de criterioEvaluacion
//calificacion : calificacion a ingresar

void App::agregarCalificacion( int indexActa, int nCriterio, float calificacion ){

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].agregarCalificacion( calificacion );
    cout << "Calificacion agregada." << endl;
    return;
}

// Borra la calificacion del criterio nCriterio de acta[ indexActa ]
//indexActa : index para el vector de actas
//nCalificacion : index para el vector de criterioEvaluacion

void App::borrarCalificacion( int indexActa, int nCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].borrarCalificacion();
    cout << "Calificacion borrada." << endl;
    return;
}

//Identifica el rol de persona con idPersona en el acta  con idActa
//1: jurado1, 2: jurado2, 3: director, 4: codirector
// idPersona es el id de la persona que se desea saber el rol
// indexActa es el index en el vector acta correspondiente al acta a verificar
//se usan enums 

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

//Muestra las actas de la modalidad recibida
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

//falta terminar
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

// LEEEME / READ ME // HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

// STEVEN NO ENFERMO LEEME
    
"""
    //a;adir for para que todos los index de criteriosEvaluacion se impriman // Trabajo pausado debido a problemas de salud // 

    Terminar imprimir acta, borrar calificacion, 

tener en cuenta que voy a tener que agregar algo para imprimir criterio de evaluacion
constructor criterios de evaluacion
app cuando imprimas el acta despues de jurado 2 imprimes criterio con titulo, 
cerrar acta acta.h acta.cpp

calculoNotas
final de acta.cpp revisar
jurado a acta rev9sar


"""
    cout << this->actas[ indexActa ].criteriosEvaluacion[1].getCriterioEvaluacion() << endl;
    cout << "hola" << endl;

    return;
}

//Consultar cuántos trabajos de grado ha dirigido un profesor dado. 
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

//Ver la lista (sin repetidos) de todos los jurados que han participado en las actas registradas
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