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

class Acta{
    private:
        int id;
        string numero;
        string fecha;
        string autor;
        string nombreTrabajo;
        int modalidad;
        string periodo;
        Persona director;
        Persona coDirector;
        string enfasis;
        Persona jurado1;
        Persona jurado2;
        bool cerrada;
        
    public:
        vector<criterioEvaluacion> criteriosEvaluacion;
        Acta( string autor, string periodo, Persona director, Persona coDirector, string enfasis, int modalidad, Persona jurado1, Persona jurado2, string fecha );

        //=======Getters======
        int getId( );
        Persona getJurado1( );
        Persona getJurado2( );
        Persona getDirector( );
        Persona getCoDirector( );
        bool estadoCerrada( );
        int getModalidad( );
        string getNumero();
        string getFecha();
        string getAutor();
        string getNombreTrabajo();
        string getPeriodo();

};

#endif