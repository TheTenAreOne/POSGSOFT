#ifndef CRITERIOEVALUACION
#define CRITERIOEVALUACION
#include <string>
using std::string;

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