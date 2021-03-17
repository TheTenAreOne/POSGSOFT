#ifndef APP
#define APP
#include "string"
#include "persona.h"
#include "acta.h"
#include <vector>
using std::string;
using std::vector;

enum roles{
    JURADO1, JURADO2, DIRECTOR, CODIRECTOR
};
enum tipoUniversidad{
    INTERNO = true, EXTERNO = false
};
enum modalidad{
    INVESTIGACION = 1, INDUSTRIA = 2
};

class App{
    private:
        vector<Acta> actas; //Contiene todas las actas
        vector<Persona> personas; //contiene todas las personas
        int idActas;
        int idPersonas;
    public:
        App( );
        void crearActa( );
        void cerrarActa( );
        void mostrarActasPorModalidad( int modalidad );
        void imprimirActa( int indexActa );
        void agregarPersona( );
        void mostrarPersonas( );
        string generarNumeroActa( string periodo );
        int verificarPersona( int idPersona, int idActa );
        void agregarObservacion( int indexActa, int nCriterio, string observacion);
        void borrarObservacion( int indexActa, int nCriterio );
        void agregarCalificacion( int indexActa , int nCriterio, float calificacion );
        void borrarCalificacion( int indexActa , int nCriterio );
        int identificarRolActa( int idPersona, int indexActa );
        void menu( );
        void trabajoDirigidos( int indexPersona );
        void verJuradosActasRegistradas( );
};

#endif