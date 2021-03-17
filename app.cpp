#include <iostream>
#include "app.h"
#include "acta.h"
#include "persona.h"
#include "criterioEvaluacion.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;

enum roles{
    JURADO1, JURADO2, DIRECTOR, CODIRECTOR
};
enum tipoUniversidad{
    INTERNO = true, EXTERNO = false
};
App::App(){}

//Métodos App



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

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].setObservacion( observacion );
    cout << "Observacion agregada." << endl;
    return;
}

// Borra la observacion del criterio nCriterio de acta[ indexActa ]
//indexActa : index para el vector de actas
//nCriterio : index para el vector de criterioEvaluacion
void App::borrarObservacion( int indexActa, int nCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].setObservacion( "" );
    cout << "Observacion borrada." << endl;
    return;
}

// [ C1, C2, C3, C4, C5, C6, C7, C8 ]



// Cambia la calificacion de la calificacion nCriterio de acta[ indexActa ] a la calificacion ingresada
//indexActa : index para el vector de actas
//nCriterio : index para el vector de criterioEvaluacion
//calificacion : calificacion a ingresar

void App::agregarCalificacion( int indexActa, int nCriterio, float calificacion ){

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].setCalificacion( calificacion );
    cout << "Calificacion agregada." << endl;
    return;
}

// Borra la calificacion del criterio nCriterio de acta[ indexActa ]
//indexActa : index para el vector de actas
//nCalificacion : index para el vector de criterioEvaluacion

void App::borrarCalificacion( int indexActa, int nCriterio ){

    this->actas[ indexActa ].criteriosEvaluacion[ nCriterio ].setCalificacion( 0.0 );
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