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
        Acta* verificarPersona( int idPersona, int idActa );
        void agregarObservacion( Acta*, int criterio, string observacion);
        void borrarObservacion( Acta*, int criterio );
        void agregarCalificacion( Acta*, int nCalificacion, float calificacion );
        void borrarCalificacion( Acta*, int nCalificacion, float calificacion );
        int identificarRolActa( int idPersona, int idActa);
};

#endif