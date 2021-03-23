#include <iostream>
#include "acta.h"
#include "criterioEvaluacion.h"

Acta::Acta(){}

//constructor de Acta
//Hay 8 criterios de evaluacion que se crean por defecto
Acta::Acta( string nombreTrabajo, string autor, string idAutor, string periodo, Persona director, Persona coDirector, string enfasis, int modalidad, Persona jurado1, Persona jurado2, string fecha, string numero, string observacionesAdicionales, float nota ){

    this->nombreTrabajo = nombreTrabajo;
    this->autor = autor;
    this->periodo = periodo;
    this->director = director;
    this->coDirector = coDirector;
    this->enfasis = enfasis;
    this->modalidad = modalidad;
    this->jurado1 = jurado1;
    this->jurado2 = jurado2;
    this->fecha = fecha;
    this->numero = numero;
    this->cerrada = ABIERTA;
    this->observacionesAdicionales = "";
    this->nota = nota;

        
    criterioEvaluacion criterio1( "1", "Desarrollo y profundidad en el tratamiento del tema", "", "", 0.0, 0.0, 20, 0.0);
    criterioEvaluacion criterio2( "2", "Desafio academico y cientifico del tema", "", "", 0.0, 0.0, 15, 0.0);
    criterioEvaluacion criterio3( "3", "Cumplimiento de los objetivos propuestos", "", "", 0.0, 0.0, 10, 0.0);
    criterioEvaluacion criterio4( "4", "Creatividad e innovacion de las soluciones y desarrollos propuestos", "", "", 0.0, 0.0, 10, 0.0);
    criterioEvaluacion criterio5( "5", "Validez de los resultados y conclusiones", "", "", 0.0, 0.0, 20, 0.0);
    criterioEvaluacion criterio6( "6", "Manejo y procesamiento de la informacion y bibliografia", "", "", 0.0, 0.0, 10, 0.0);
    criterioEvaluacion criterio7( "7", "Calidad y presentacion del documento escrito", "", "", 0.0, 0.0, 7.5, 0.0);
    criterioEvaluacion criterio8( "8", " Presentacion oral", "", "", 0.0, 0.0, 7.5, 0.0);

    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio2);
    this->criteriosEvaluacion.push_back(criterio3);
    this->criteriosEvaluacion.push_back(criterio4);
    this->criteriosEvaluacion.push_back(criterio5);
    this->criteriosEvaluacion.push_back(criterio6);
    this->criteriosEvaluacion.push_back(criterio7);
    this->criteriosEvaluacion.push_back(criterio8);
}

//getter de jurado1
Persona Acta::getJurado1( ){
    return this->jurado1;
}

//getter de jurado2
Persona Acta::getJurado2( ){
    return this->jurado2;
}

//getter de director
Persona Acta::getDirector( ){
    return this->director;
}

//getter de coDirector
Persona Acta::getCoDirector( ){
    return this->coDirector;
}

//getter de cerrada (estado del acta)
bool Acta::estadoCerrada( ){
    return this->cerrada;
}

//getter de modalidad
int Acta::getModalidad( ){
    return this->modalidad;
}

//getter de autor
string Acta::getAutor(){
    return this->autor;
}

//getter de notaFinal
float Acta::getNotaFinal(){
    return this->nota;
}

//getter de periodo
string Acta::getPeriodo(){
    return this->periodo;
}

//getter del nombreTrabajo
string Acta::getNombreTrabajo(){
    return this->nombreTrabajo;
}

//getter de fecha
string Acta::getFecha(){
    return this->fecha;
}

//otro getter de cerrada
bool Acta::getCerrada(){
    return this->cerrada;
}

//getter de numero
string Acta::getNumero(){
    return this->numero;
}

//setter de numero
void Acta::setNumero(string numeroIngresar){
    this->numero = numeroIngresar;
}

//setter de nota
void Acta::setNotaFinal( float nota ){
    this->nota = nota;
}

//setter de aprobada
void Acta::setAprobada( bool aprobada ){
    this->aprobada = aprobada;
}

//setter de cerrada
void Acta::setCerrada( bool cerrada ){
    this->cerrada = CERRADA;
}

//setter de observacionesAdicionales
void Acta::agregarObservacionAdicional( string observacion ){
    this->observacionesAdicionales = observacion;
}

//getter de observaciones adicionales
string Acta::getObservacionesAdicionales(){
    return this->observacionesAdicionales;
}
