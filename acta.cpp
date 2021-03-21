#include <iostream>
#include "acta.h"
#include "criterioEvaluacion.h"

Acta::Acta(){}

Acta::Acta( string autor, string periodo, Persona director, Persona coDirector, string enfasis, int modalidad, Persona jurado1, Persona jurado2, string fecha ){

    this->autor = autor;
    this->periodo = periodo;
    this->director = director;
    this->coDirector = coDirector;
    this->enfasis = enfasis;
    this->modalidad = modalidad;
    this->jurado1 = jurado1;
    this->jurado2 = jurado2;
    this->fecha = fecha;
    this->cerrada = ABIERTA;
    this->observacionesAdicionales = "";
    
    criterioEvaluacion criterio1( "1", "Desarrollo y profundidad en el tratamiento del tema", "", "", "", 0.0, 0.0, 20, 0.0);
    criterioEvaluacion criterio2( "2", "Desafío académico y científico del tema", "", "", "", 0.0, 0.0, 15, 0.0);
    criterioEvaluacion criterio3( "3", "Cumplimiento de los objetivos propuestos", "", "", "", 0.0, 0.0, 10, 0.0);
    criterioEvaluacion criterio4( "4", "Creatividad e innovación de las soluciones y desarrollos propuestos", "", "", "", 0.0, 0.0, 10, 0.0);
    criterioEvaluacion criterio5( "5", "Validez de los resultados y conclusiones", "", "", "", 0.0, 0.0, 20, 0.0);
    criterioEvaluacion criterio6( "6", "Manejo y procesamiento de la información y bibliografía", "", "", "", 0.0, 0.0, 10, 0.0);
    criterioEvaluacion criterio7( "7", "Calidad y presentación del documento escrito", "", "", "", 0.0, 0.0, 7.5, 0.0);
    criterioEvaluacion criterio8( "8", " Presentación oral", "", "", "", 0.0, 0.0, 7.5, 0.0);

    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio2);
    this->criteriosEvaluacion.push_back(criterio3);
    this->criteriosEvaluacion.push_back(criterio4);
    this->criteriosEvaluacion.push_back(criterio5);
    this->criteriosEvaluacion.push_back(criterio6);
    this->criteriosEvaluacion.push_back(criterio7);
    this->criteriosEvaluacion.push_back(criterio8);
}


int Acta::getId( ){
    return this->id;
}

Persona Acta::getJurado1( ){
    return this->jurado1;
}

Persona Acta::getJurado2( ){
    return this->jurado2;
}

Persona Acta::getDirector( ){
    return this->director;
}

Persona Acta::getCoDirector( ){
    return this->coDirector;
}

bool Acta::estadoCerrada( ){
    return this->cerrada;
}

int Acta::getModalidad( ){
    return this->modalidad;
}

string Acta::getAutor(){
    return this->autor;
}

string Acta::getPeriodo(){
    return this->periodo;
}

string Acta::getNombreTrabajo(){
    return this->nombreTrabajo;
}

string Acta::getFecha(){
    return this->fecha;
}

int Acta::getNota(){
    return this->nota;
}

string Acta::getNumero(){
    return this->numero;
}

void Acta::setNotaFinal( float nota ){
    this->nota = nota;
}

void Acta::setAprobada( bool aprobada ){
    this->aprobada = aprobada;
}

void Acta::setCerrada( bool cerrada ){
    this->cerrada = CERRADA;
}

void Acta::agregarObservacionAdicional( string observacion ){
    this->observacionesAdicionales += observacion;
}