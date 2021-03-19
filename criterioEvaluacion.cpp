#include "criterioEvaluacion.h"
#include "string"

criterioEvaluacion::criterioEvaluacion( string id, string titulo, string observacion, float calificacion, float porcentajePonderacion ){
        this->id = id;
        this->titulo = titulo;
        this->observacion = observacion;
        this->calificacion = calificacion;
        this->porcentajePonderacion = porcentajePonderacion;
}

void criterioEvaluacion::agregarObservacion( string observacion ){

    this->observacion += observacion;

}
void criterioEvaluacion::borrarObservacion( ){

    this->observacion = "";
}

void criterioEvaluacion::agregarCalificacion( float calificacion ){

    this->calificacion = calificacion;

}

void criterioEvaluacion::borrarCalificacion(){

    this->calificacion = 0.0;

}

string criterioEvaluacion::getCriterioEvaluacion(){

    string textoCalificacion = std::to_string(this->calificacion);

    string textoPorcentajePonderacion = std::to_string(this->porcentajePonderacion);

    string stringCriterioEvaluacion = this->titulo + this->id + this->observacion + textoCalificacion + textoPorcentajePonderacion;

    return stringCriterioEvaluacion;

}
