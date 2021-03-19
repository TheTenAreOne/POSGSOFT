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
        Persona( string nombre, int id, bool tipoUniversidad );
        string getNombre( );
        int getId( );
        bool getTipoUniversidad( );
};

#endif 