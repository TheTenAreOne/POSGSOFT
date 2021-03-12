#ifndef PERSONA
#define PERSONA
#include <string>
using std::string;

class Persona{
    private:
        string nombre;
        int id;
        bool tipoUniversidad;
    public:
        Persona( );

        // ----- Getters -----
        string getNombre( );
        string getId( );
        bool getTipoUniversidad( );
};

#endif 