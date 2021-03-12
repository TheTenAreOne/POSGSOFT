#ifndef APP
#define APP
#include "string"
#include "persona.h"
#include "acta.h"
using std::string;

class App{
    private:

    public:
        App( );
        void verificarPersona( );
        void modificarObservacionActa( );
        void modificarCalificacionActa( );
        int identificarRolActa( );
};

#endif