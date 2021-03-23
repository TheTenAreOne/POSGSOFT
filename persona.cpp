#include "persona.h"

Persona::Persona(){}

//constructor
Persona::Persona( string nombre, int id, bool tipoUniversidad ){
    this->nombre = nombre;
    this->id = id;
    this->tipoUniversidad = tipoUniversidad;
}

//getter de nombre
string Persona::getNombre(){
    return this->nombre;
}

//getter de id
int Persona::getId(){
    return this->id;
}

//getter de tipoUniversidad
bool Persona::getTipoUniversidad(){
    return this->tipoUniversidad;
}