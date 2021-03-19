#include <iostream>
#include "acta.h"
#include "criterioEvaluacion.h"

Acta::Acta( string autor, string periodo, Persona director, Persona coDirector, string enfasis, int modalidad, Persona jurado1, Persona jurado2, string fecha ){
    this->autor = autor;
    this->periodo = periodo;
    this->director = director;

    criterioEvaluacion criterio1( "1", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );
    criterioEvaluacion criterio1( "2", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );
    criterioEvaluacion criterio1( "3", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );
    criterioEvaluacion criterio1( "4", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );
    criterioEvaluacion criterio1( "5", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );
    criterioEvaluacion criterio1( "6", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );
    criterioEvaluacion criterio1( "7", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );
    criterioEvaluacion criterio1( "8", "Desarrollo y profundidad en el tratamiento del tema", "", 0.0, 0.20 );

    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio1);
    this->criteriosEvaluacion.push_back(criterio1);
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

//verifica si esta cerrada
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
//Métodos pendientes por definir para acta

// Comentario de prueba