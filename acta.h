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
    APROBADA = true, REPROBADO = false
};

class Acta{
    private:
        int id;
        string numero;
        string fecha;
        string autor;
        string nombreTrabajo;

        // Modalidad deberia ser cambiado por string tipoTrabajo, de otra manera es inutil hacer uso de enums en esta parte

        int modalidad;
        string periodo;
        Persona director;


        // Siempre existira un director, mas no siempre un CoDirector, por lo tanto; habria que preguntar si en cada acta en especifico este se encuentra presente

        Persona coDirector;
        string enfasis;
        Persona jurado1;
        Persona jurado2;
        float nota;
        bool cerrada;
        bool aprobada;

        //AÑADI ESTO DE APROBADA O REPROBADA // DANIEL LEEME // DANIEL LEEME
        
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
        int getNota();
        void setNotaFinal( float nota );
        void setAprobada( bool aprobada );

};

#endif