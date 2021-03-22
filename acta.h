#ifndef ACTA
#define ACTA
#include "persona.h"
#include "criterioEvaluacion.h"
#include <string>
#include <vector>
using std::string;
using std::vector;


enum{
    CERRADA = true, ABIERTA = false
};

enum{
    APROBADA = true, REPROBADA = false
};

class Acta{
    private:
        string numero;
        string fecha;
        string autor;
        string nombreTrabajo;
        string observacionesAdicionales;
        int modalidad;
        string periodo;
        Persona director;
        Persona coDirector;
        string enfasis;
        Persona jurado1;
        Persona jurado2;
        float nota;
        bool cerrada;
        bool aprobada;

    public:
        Acta();
        vector<criterioEvaluacion> criteriosEvaluacion;
        Acta( string nombreDelTrabajo, string autor, string idAutor, string periodo, Persona director, Persona coDirector, string enfasis, int modalidad, Persona jurado1, Persona jurado2, string fecha, string numero, string observacionesAdicionales );


        Persona getJurado1( );
        Persona getJurado2( );
        Persona getDirector( );
        Persona getCoDirector( );
        bool estadoCerrada( );
        int getModalidad( );
        string getNumero();
        void setNumero( string numero);
        string getFecha();
        string getAutor();
        string getNombreTrabajo();
        string getPeriodo();
        int getNota();
        void setNotaFinal( float nota );
        void setAprobada( bool aprobada );
        void setCerrada( bool cerrada );
        void agregarObservacionAdicional( string observacion );
        string getObservacionesAdicionales();
        
};

#endif