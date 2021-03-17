#include "criterioEvaluacion.h"

criterioEvaluacion::criterioEvaluacion(){}

void criterioEvaluacion::agregarObservacion( string observacion ){

    this->observacion += observacion;

}
void criterioEvaluacion::borrarObservacion( ){

    this->observacion = "";
}

void criterioEvaluacion::setCalificacion( float calificacion ){

    this->calificacion = calificacion;

}