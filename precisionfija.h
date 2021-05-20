#ifndef _PRECISIONFIJA_H_INCLUDED_
#define _PRECISIONFIJA_H_INCLUDED_

#include "bignum.h"
#include <regex>

//manejo de los streams de entrada y salida, asigna los streams a los bignum
class precision_fija
{
    istream *iss_;			// stream de entrada de donde se obtendran los datos de consulta
    istream *pss_;	        // stream de entrada points de la base de datos
    ostream *oss_;			// stream de salida donde se emitiran la ditancia min
    
    int precision;       // precision de los cálculos a realizarse
    

    // tengo que declarar los dos numeros bignum con los cuales voy a laburar
    bignum a(std::string&, int); //chequear
    bignum b(std::string&, int); //chequear

public:
    
    precision_fija(); //puede ser privado!
    precision_fija(istream &,ostream &,int *);//Constructor con argumento, paso los streams por referencia
    ~precision_fija();
    
    void acumular(); //manejo de streams, cambiar nombre luego CAPTURAR
    void distance();
    void emite();
    void Liberar_memoria();
};

#endif