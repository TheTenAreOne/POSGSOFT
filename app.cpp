#include <iostream>
#include "app.h"
#include "acta.h"
#include "persona.h"
#include "criterioEvaluacion.h"
using std::cout;
using std::string;
using std::endl;

enum roles{
    JURADO1, JURADO2, DIRECTOR, CODIRECTOR
};

App::App(){}

//Métodos App

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

void App::agregarObservacion( int indexActa, int nCriterio, string observacion ){

    this->actas[ indexActa ].getCriteriosEvaluacion( )[ nCriterio ].setObservacion( observacion );
    

}

void App::borrarObservacion( Acta *pActa, int criterio ){

    list <criteriosEvaluacion> :: iterator it;

    if( criterio <= criteriosEvaluacion.end() || criterio => criteriosEvaluacion.begin() ){

        for( it = this->criteriosEvalucion.begin(); it != criteriosEvaluacion.end(); it++ ){

            if( it == criterio){

                setObservacion( int criterio, string "" );

            }

        }

    }
    
    else{

        cout << "El numero de criterio se encuentra por fuera del rango almacenado."

    }

}

// [ C1, C2, C3, C4, C5, C6, C7, C8 ]

void App::agregarCalificacion( Acta *pActa, int nCriterioEvaluacion, float calificacion ){

    if( calificacion < 0 || calificacion > 5 ){
        cout << "Calificacion invalida" << endl;
        return;
    }

    list <criterioEvaluacion> :: iterator it; 

    if( nCalificacion <= pActa->get.end() || nCalificacion => nCriterioEvaluacion.begin() ){

        for( it = pActa->calificaciones.begin(); it != pActa->calificaciones.end(); it++ ){

            if( it == nCalificacion){

                setCalificacion( float calificacion );

            }

        }

    }
    
    else{

        cout << "El numero de criterio se encuentra por fuera del rango almacenado."

    }

}
void App::borrarCalificacion( Acta *pActa){

    list <calificaciones> :: iterator it;

    if( nCalificacion <= calificaciones.end() || nCalificacion => calificaciones.begin() ){

        for( it = this->calificaciones.begin(); it != calificaciones.end(); it++ ){

            if( it == nCalificacion){

                setCalificacion( float 0.0 );

            }

        }

    }
    
    else{

        cout << "El numero de criterio se encuentra por fuera del rango almacenado."

    }

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