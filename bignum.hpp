#ifndef _BIGNUM_H_INCLUDED_
#define _BIGNUM_H_INCLUDED_

#include <iostream>
#include <string>
#include <stdio.h>
//#include <cmdline.h>

class bignum
{
private:
	istream *iss_;			// stream de entrada de donde se obtendran los datos de consulta
    istream *pss_;	        // stream de entrada donde se recibe la precisión
    ostream *oss_;			// stream de salida en el cual se plasman los resultados 
	unsigned short *digits;
	int dim;
	bool sign;

public:
	bignum ();
	bignum (bignum&);
	bignum (std::string&, int); //chequear
	bignum (size_t);  //para chequear nosotros en el main
// falta destructor //////////////
	
	/*
	 *
	 * cambiar en el cmdline las letras y funciones de opcion_t
	 *
	 *
	 * agregar en el mismo la opcion -p para la precision
	 *
	 *
	 */

	~bignum();
	bignum operator+(const bignum&);
	bignum operator-(const bignum&);
	bignum operator*(const bignum&);
	bignum& operator=(const bignum&);


	bignum convertir_bignum(std::string&);
	void emitir_bignum(); //usar para chequear, despues borrarlo
	friend std::ostream& operator<<(std::ostream&, const bignum&);
	friend std::istream& operator>>(std::istream&, bignum&);


};
#endif