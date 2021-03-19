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
        criterioEvaluacion( string id, string titulo, string observacion, float calificacion, float porcentajePonderacion );
        void agregarObservacion(string observacion);
        void borrarObservacion();
        void agregarCalificacion(float calificacion);
        void borrarCalificacion();
        string getCriterioEvaluacion();
        
};

#endif