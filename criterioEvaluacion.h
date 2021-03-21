#ifndef CRITERIOEVALUACION
#define CRITERIOEVALUACION
#include <string>
using std::string;

class criterioEvaluacion{
    private:
        string idCriterio;
        string titulo;
        string observacionJurado1;
        string observacionJurado2;
        float calificacionJurado1;
        float calificacionJurado2;
        float calificacionCriterio;
        float porcentajePonderacion;

    public:
        criterioEvaluacion( string idCriterio, string titulo, string observacionJurado1, string observacionJurado2, string observacionesAdicionales, float calificacionJurado1, float calificacionJurado2, float porcentajePonderacion, float calificacionCriterio );
        void agregarObservacionJurado1(string observacionJurado1);
        void agregarObservacionJurado2(string observacionJurado2);
        void agregarObservacionesAdicionales(string observacionesAdicionales);
        void borrarObservacionJurado1();
        void borrarObservacionJurado2();
        void agregarCalificacionJurado1(float calificacionJurado1);
        void agregarCalificacionJurado2(float calificacionJurado2);
        void borrarCalificacionJurado1();
        void borrarCalificacionJurado2();
        float getCalificacionCriterio();
        string getIdCriterio();
        string getTitulo();
        string getObservacionJurado1();
        string getObservacionJurado2();
        float getCalificacionCriterio();
        float getPorcentajePonderacion();       
};

#endif