#include <iostream>
#include "acta.h"

Acta::Acta( string autor, string periodo, Persona director, Persona coDirector, string enfasis, int modalidad, Persona jurado1, Persona jurado2, string fecha ){}

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
bool Acta::estadoCerrada(){
    return this->cerrada;
}

//Métodos pendientes por definir para acta

// Comentario de prueba