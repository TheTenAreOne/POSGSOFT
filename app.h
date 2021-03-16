#ifndef APP
#define APP
#include "string"
#include "persona.h"
#include "acta.h"
#include <vector>
using std::string;
using std::vector;

class App{
    private:
        vector<Acta> actas; //Contiene todas las actas
        vector<Persona> personas; //contiene todas las personas
        int idPersonas = 0;
    public:
        App( );
        void crearActa( );
        void cerrarActa( );
        void agregarPersona( );
        int verificarPersona( int idPersona, int idActa );
        void agregarObservacion( int indexActa, int nCriterio, string observacion);
        void borrarObservacion( int indexActa, int nCriterio );
        void agregarCalificacion( int indexActa , int nCalificacion, float calificacion );
        void borrarCalificacion( int indexActa , int nCalificacion );
        int identificarRolActa( int idPersona, int indexActa );
};

#endif