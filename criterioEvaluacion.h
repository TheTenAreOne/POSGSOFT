#ifndef CRITERIOEVALUACION
#define CRITERIOEVALUACION
#include <string>
using std::string;

//Te comiste una "a" en "Evaluacion" y también olvidaste el lowerCamelCase

class criterioEvaluacion{
    private:
        string id;
        string titulo;
        string observacion;
        float calificacion;
        float porcentajePonderacion;

    public:
        criterioEvaluacion( );
        void setObservacion(string observacion);
        void setCalificacion(float calificacion);
};

#endif