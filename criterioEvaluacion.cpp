#include "criterioEvaluacion.h"
#include "string"

criterioEvaluacion::criterioEvaluacion( string idCriterio, string titulo, string observacionJurado1, string observacionJurado2, float calificacionJurado1, float calificacionJurado2, float porcentajePonderacion, float calificacionCriterio ){
    this->idCriterio = idCriterio;
    this->titulo = titulo;
    this->observacionJurado1 = observacionJurado1;
    this->observacionJurado2 = observacionJurado2;
    this->calificacionJurado1 = calificacionJurado1;
    this->calificacionJurado2 = calificacionJurado1;
    this->porcentajePonderacion = porcentajePonderacion;
}

void criterioEvaluacion::agregarObservacionJurado1( string observacionJurado1 ){

    this->observacionJurado1 = observacionJurado1;

}

void criterioEvaluacion::agregarObservacionJurado2( string observacionJurado2 ){

    this->observacionJurado2 = observacionJurado2;

}

void criterioEvaluacion::borrarObservacionJurado1( ){

    this->observacionJurado1 = "";
}

void criterioEvaluacion::borrarObservacionJurado2( ){

    this->observacionJurado2 = "";
}

void criterioEvaluacion::agregarCalificacionJurado1( float calificacionJurado1 ){

    this->calificacionJurado1 = calificacionJurado1;

}

void criterioEvaluacion::agregarCalificacionJurado2( float calificacionJurado2 ){

    this->calificacionJurado1 = calificacionJurado2;

}

void criterioEvaluacion::borrarCalificacionJurado1(){

    this->calificacionJurado1 = 0.0;

}

void criterioEvaluacion::borrarCalificacionJurado2(){

    this->calificacionJurado2 = 0.0;

}

float criterioEvaluacion::getCalificacionCriterio(){

    return this->calificacionCriterio = ( ( this->calificacionJurado1 + this->calificacionJurado2 ) / 2 ) * ( this->porcentajePonderacion / 100 );

}

string criterioEvaluacion::getIdCriterio(){
    return this->idCriterio;
}
string criterioEvaluacion::getTitulo(){
    return this->titulo;
}
string criterioEvaluacion::getObservacionJurado1(){
    return this->observacionJurado1;
}
string criterioEvaluacion::getObservacionJurado2(){
    return this->observacionJurado2;
    }
float criterioEvaluacion::getPorcentajePonderacion(){
    return porcentajePonderacion;
}