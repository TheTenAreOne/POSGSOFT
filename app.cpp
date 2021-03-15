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
bool App::verificarPersona( int idPersona, int idActa ){
    list <Acta> :: iterator it;

    //itera la lista de actas para encontrar el acta
    for( it = this->actas.begin(); it != this->actas.end(); it++ ){
        if( it->getId() == idActa ){
            if( it->getJurado1().getId() == idPersona || it->getJurado2().getId() == idPersona || it->getDirector().getId() == idPersona || it->getCoDirector().getId() ){
                return true;
            }else{
                return false;
            }
        }
    }
    cout << "Acta[" << idActa << "] no encontrada." << endl;
    return false;
}

void App::modificarObservacionActa( ){}

void App::modificarCalificacionActa( ){}

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