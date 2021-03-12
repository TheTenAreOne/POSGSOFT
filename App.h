#ifndef APP
#define APP
#include <string>
#include <Persona.h>
#include <Acta.h>
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