#include <iostream>
#include "acta.h"

Acta::Acta(){}

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
//Métodos pendientes por definir para acta

// Comentario de prueba