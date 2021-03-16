#include <iostream>
#include "app.h"
#include "acta.h"
#include "persona.h"
#include "criterioEvaluacion.h"
using std::cout;
using std::endl;

enum roles{
    JURADO1, JURADO2, DIRECTOR, CODIRECTOR
};

App::App(){}

//Métodos App

//Verifica que la persona con idPersona haga parte del acta (ya sea director o jurado)
Acta* App::verificarPersona( int idPersona, int idActa ){
    
    list <Acta> :: iterator it;

    //itera la lista de actas para encontrar el acta
    for( it = this->actas.begin(); it != this->actas.end(); it++ ){

        if( it->getId() == idActa ){
            if( it->getJurado1().getId() == idPersona || it->getJurado2().getId() == idPersona || it->getDirector().getId() == idPersona || it->getCoDirector().getId() ){
                return &it;
            }else{
                cout << "Usuario[" << idPersona << "] no hace parte del acta." << endl;
                return null;
            }
        }
    }

    cout << "Acta[" << idActa << "] no encontrada." << endl;
    return null;
}

void App::agregarObservacion( Acta *pActa, int criterio, string observacion ){

    list <criteriosEvaluacion> :: iterator it;

    if( criterio <= criteriosEvaluacion.end() || criterio => criteriosEvaluacion.begin() ){

        for( it = this->criteriosEvalucion.begin(); it != criteriosEvaluacion.end(); it++ ){

            if( it == criterio){

                setObservacion( int criterio, string observacion );

            }

        }

    }
    
    else{

        cout << "El numero de criterio se encuentra por fuera del rango almacenado."

    }

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
void App::agregarCalificacion( Acta *pActa, int nCalificacion ){

    list <calificaciones> :: iterator it;

    if( nCalificacion <= calificaciones.end() || nCalificacion => calificaciones.begin() ){

        for( it = this->calificaciones.begin(); it != calificaciones.end(); it++ ){

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
//se usan enums 
int App::identificarRolActa( int idPersona, int idActa ){
    list <Acta> :: iterator it;

    for( it = this->actas.begin(); it != this->actas.end(); it++ ){
        if( it->getId() == idActa ){
            if( it->getJurado1().getId() == idPersona ){
                return JURADO1;
            }else if( it->getJurado2().getId() == idPersona ){
                return JURADO2;
            }else if( it->getDirector().getId() == idPersona ){
                return DIRECTOR;
            }else{
                return CODIRECTOR;
            }
        }
    }

    return -1;
}