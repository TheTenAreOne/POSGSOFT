#include "criterioEvaluacion.h"
#include "string"

//constructor
criterioEvaluacion::criterioEvaluacion( string idCriterio, string titulo, string observacionJurado1, string observacionJurado2, float calificacionJurado1, float calificacionJurado2, float porcentajePonderacion, float calificacionCriterio ){
    this->idCriterio = idCriterio;
    this->titulo = titulo;
    this->observacionJurado1 = observacionJurado1;
    this->observacionJurado2 = observacionJurado2;
    this->calificacionJurado1 = calificacionJurado1;
    this->calificacionJurado2 = calificacionJurado1;
    this->porcentajePonderacion = porcentajePonderacion;
}

//setter de observacionJurado1
//observacionJurado1 : es la observacion del jurado
void criterioEvaluacion::agregarObservacionJurado1( string observacionJurado1 ){

    this->observacionJurado1 = observacionJurado1;

}

//setter de observacionJurado2
//observacionJurado2 : es la observacion del jurado
void criterioEvaluacion::agregarObservacionJurado2( string observacionJurado2 ){

    this->observacionJurado2 = observacionJurado2;

}

//setter de la calificacion del jurado1
//calificacionJurado1 : es la calificacion del jurado 
void criterioEvaluacion::agregarCalificacionJurado1( float calificacionJurado1 ){

    this->calificacionJurado1 = calificacionJurado1;

}

//setter de la calificacion del jurado2
//calificacionJurado2 : es la calificacion del jurado 
void criterioEvaluacion::agregarCalificacionJurado2( float calificacionJurado2 ){

    this->calificacionJurado2 = calificacionJurado2;

}

//getter de la calificacion del criterio (total)
float criterioEvaluacion::getCalificacionCriterio(){

    return this->calificacionCriterio = ( ( this->calificacionJurado1 + this->calificacionJurado2 ) / 2 ) * ( this->porcentajePonderacion / 100 );

}

//getter de la calificacion del jurado 1
float criterioEvaluacion::getCalificacionJurado1(){
    return this->calificacionJurado1;
}

//getter de la calificacion del jurado 2
float criterioEvaluacion::getCalificacionJurado2(){
    return this->calificacionJurado2;
}

//getter de la del id del criterio
string criterioEvaluacion::getIdCriterio(){
    return this->idCriterio;
}

//getter del titulo
string criterioEvaluacion::getTitulo(){
    return this->titulo;
}

//getter de la observacion del jurado 1
string criterioEvaluacion::getObservacionJurado1(){
    return this->observacionJurado1;
}

//getter de la observacion del jurado 2
string criterioEvaluacion::getObservacionJurado2(){
    return this->observacionJurado2;
}

//getter del porcentaje de ponderacion
float criterioEvaluacion::getPorcentajePonderacion(){
    return porcentajePonderacion;
}