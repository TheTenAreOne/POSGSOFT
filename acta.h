#ifndef ACTA
#define ACTA
#include "persona.h"
#include <string>
using std::string;

class Acta{
    private:
        string numero;
        string fecha;
        string autor;
        string nombreTrabajo;
        int tipoTrabajo;
        string periodo;
        Persona director;
        Persona coDirector;
        Persona jurado1;
        Persona jurado2;
    public:
        Acta( );
};

#endif