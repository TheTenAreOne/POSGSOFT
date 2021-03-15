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
        void agregarObservacion( int criterio );
        void borrarObservacion( int criterio );
        void agregarCalificacion( int criterio );
        void borrarCalificacion( int criterio );
        int identificarRolActa( int idPersona, int idActa );
};

#endif