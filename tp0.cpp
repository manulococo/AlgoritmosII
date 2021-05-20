#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "bignum.h"
#include "cmdline.h"

//#include "IteradorLista.h"
//#include "Lista.h"
//#include "Nodo.h"
//#include "distmin.h"


//#include "metodos.cpp"
//#include "dist_min.cpp"

#define tipo_dato_ double //podemos cambiar el tipo de dato que manejamos

using namespace std;

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_help(string const &);
static void opt_precision(string const &);

// Tabla de opciones de línea de comando. El formato de la tabla
// consta de un elemento por cada opción a definir. A su vez, en
// cada entrada de la tabla tendremos:
//
// o La primera columna indica si la opción lleva (1) o no (0) un
//   argumento adicional.
//
// o La segunda columna representa el nombre corto de la opción.
//
// o Similarmente, la tercera columna determina el nombre largo.
//
// o La cuarta columna contiene el valor por defecto a asignarle
//   a esta opción en caso que no esté explícitamente presente
//   en la línea de comandos del programa. Si la opción no tiene
//   argumento (primera columna nula), todo esto no tiene efecto.
//
// o La quinta columna apunta al método de parseo de la opción,
//   cuyo prototipo debe ser siempre void (*m)(string const &arg);
//
// o La última columna sirve para especificar el comportamiento a
//   adoptar en el momento de procesar esta opción: cuando la
//   opción es obligatoria, deberá activarse OPT_MANDATORY.
//
// Además, la última entrada de la tabla debe contener todos sus
// elementos nulos, para indicar el final de la misma.
//
static option_t options[] = {
    {1, "p", "precision",NULL, opt_precision, OPT_MANDATORY},
    {1, "i", "input",  "-", opt_input,  OPT_DEFAULT},
    {1, "o", "output", "-", opt_output, OPT_DEFAULT},
    {0, "h", "help",  NULL, opt_help,   OPT_DEFAULT},
    {0, },
};

static fstream pfs; //-p  precision
static istream *pss = 0;

static istream *iss = 0;
static ostream *oss = 0;
static fstream ifs;
static fstream ofs;

static void
opt_precision(string const &arg)
{
    // Si el nombre del archivos es "-", usaremos la entrada
    // estándar. De lo contrario, abrimos un archivo en modo
    // de lectura.
    // -p es mandatory
    if (arg == "-") { //nunca va a pasar, supongo lo borro luego, hacer casos de prueba
        pss = &cin;
    } else {
        pfs.open(arg.c_str(), ios::in);
        pss = &pfs;
    }
    
    // Verificamos que el stream este OK.
    //
    if (!pss->good()) {
        cerr << "cannot open "
        << arg
        << "."
        << endl;
        exit(1);
    }
}

static void
opt_input(string const &arg)
{
    // Si el nombre del archivos es "-", usaremos la entrada
    // estándar. De lo contrario, abrimos un archivo en modo
    // de lectura.
    //
    if (arg == "-") {
        iss = &cin;
    } else {
        ifs.open(arg.c_str(), ios::in);
        iss = &ifs;
    }
    
    // Verificamos que el stream este OK.
    //
    if (!iss->good()) {
        cerr << "cannot open "
        << arg
        << "."
        << endl;
        exit(1);
    }
}

static void
opt_output(string const &arg)
{
    // Si el nombre del archivos es "-", usaremos la salida
    // estándar. De lo contrario, abrimos un archivo en modo
    // de escritura.
    //
    if (arg == "-") {
        oss = &cout;
    } else {
        ofs.open(arg.c_str(), ios::out);
        oss = &ofs;
    }
    
    // Verificamos que el stream este OK.
    //
    if (!oss->good()) {
        cerr << "cannot open "
        << arg
        << "."
        << endl;
        exit(1);
    }
}

static void
opt_help(string const &arg)
{
    cout << "tp0 [-p file] [-i file] [-o file]"
    << endl;
    exit(0);
}


int
main(int argc, char * const argv[])
{
    
    cmdline cmdl(options);
    cmdl.parse(argc, argv);
    
    string str;
    int precision;
    cin >> str;
    cin >> precision;
    bignum a(str, precision);
    a.emitir_bignum();



    /* distmin<tipo_dato_> distmin_(*iss,*pss,*oss);
    
    distmin_.acumular();
    distmin_.distance();
    distmin_.Liberar_memoria(); */
    
    
    if (iss->bad()) {
        cerr << "cannot read from input stream."
        << endl;
        exit(1);
    }
    return 0;
}
