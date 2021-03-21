#ifndef APP
#define APP
#include "string"
#include "persona.h"
#include "acta.h"
#include "criterioEvaluacion.h"
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::fstream;

// Cuando se usa un enum, lo que se hace es que al nombre de una variable se le asigna un valor, tal como es el ejemplo de INVESTIGACION con 1, entonces, cuando se escriba INVESTIGACION, C++ automáticamente reemplazará ese valor con el de 1.

// Enum para la identificación de los roles del acta.

enum roles{
    JURADO1, JURADO2, DIRECTOR, CODIRECTOR
};

// Enum para la identificación de la modalidad del acta.

enum tipoUniversidad{
    INTERNO = 1, EXTERNO = 2
};

enum modalidad{
    INVESTIGACION = 1, INDUSTRIA = 2

};

// Enum para la identificación de los meses del año.

enum mesesAnio{
    enero = 1, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre
};

class App{
    private:
        vector<Acta> actas; // Contiene a todas las actas.
        vector<Persona> personas; // Contiene a todas las personas.
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
        void agregarObservacionJurado1( int indexActa, int nCriterio, string observacion);
        void agregarObservacionJurado2( int indexActa, int nCriterio, string observacion);
        void borrarObservacionJurado1( int indexActa, int nCriterio );
        void borrarObservacionJurado2( int indexActa, int nCriterio );
        void agregarCalificacionJurado1( int indexActa , int nCriterio, float calificacion );
        void agregarCalificacionJurado2( int indexActa , int nCriterio, float calificacion );
        void borrarCalificacionJurado1( int indexActa , int nCriterio );
        void borrarCalificacionJurado2( int indexActa , int nCriterio );
        int identificarRolActa( int idPersona, int indexActa );
        void menu( );
        void trabajoDirigidos( int indexPersona );
        void trabajoJurado( int indexPersona );
        void verJuradosActasRegistradas( );
        std::string generarFecha( );
        void mostrarTodasActas( );
        void mostrarActasAC( bool cerrada );
        bool borrarActa( int indexActas ); 
        void calcularNotaFinal( int indexActas );
        void cerrarActa( int indexActa);
        void verJuradosIE( bool IE);//IE : Interno Externo
        void imprimirATxt( int indexActa );
};

#endif