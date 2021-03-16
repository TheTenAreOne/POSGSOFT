#include "persona.h"

Persona::Persona(){}

Persona::Persona( string nombre, int id, bool tipoUniversidad ){
    this->nombre = nombre;
    this->id = id;
    this->tipoUniversidad = tipoUniversidad;
}
//Métodos Persona

string Persona::getNombre(){

    return this->nombre;

}

int Persona::getId(){

    return this->id;

}

bool Persona::getTipoUniversidad(){

    return this->tipoUniversidad;

}