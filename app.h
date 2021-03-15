#ifndef APP
#define APP
#include "string"
#include "persona.h"
#include "acta.h"
#include <list>
using std::string;
using std::list;

class App{
    private:
        list <Acta> actas; //Contiene todas las actas
    public:
        App( );
        bool verificarPersona( int idPersona, int idActa );
        void modificarObservacionActa( );
        void modificarCalificacionActa( );
        int identificarRolActa( int idPersona, int idActa );
};

#endif