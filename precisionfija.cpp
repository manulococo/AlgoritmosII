#include "precisionfija.h"

using namespace std;
precision_fija::precision_fija()
{
}
precision_fija::precision_fija(istream &iss, ostream &oss, int *precision){
    iss_ = &iss;
    oss_ = &oss;
    this->precision = *precision; // precicisón por defecto, se podría usar una deficion global para definirla
}
precision_fija::~precision_fija(){
    
}
void precision_fija::captura(){
    string s; //se almacenará la lína 
    smatch m; // ver regex c++, se almacenará las "captura" realizadas por el regex

    //validacion regex---> https://regex101.com/  consultar: (\b\d+|\-\d+|\+\d+)(\+|\*|\-)(\d+|\-\d+|\+\d+)$
    regex e ("(\\d+|\\-\\d+|\\+\\d+)(\\+|\\*|\\-)(\\d+|\\-\\d+|\\+\\d+)$"); 

    // Recibo el flujo isstream y lo guarda en un string
    while (getline(*iss_, s)){
        if (s.empty() == true){ // si la linea está vacía,
                cout<<"Finished program"<<endl;       
                break;
        }
        while (std::regex_search (s,m,e)) {
            //for (auto x:m) std::cout << x << ".."; realiza lo mismo que el for de abajo
            //for (unsigned i=0; i<m.size(); ++i) {
            //    cout << "[" << m[i] << "] ";
            //}
            /////////////////////////////////////////////////////////////////////////////////    
            // m.str(i)
            // En i=0 se encentra toda el string, i=1 1er bignum, i=2 la operacion, i=3 2do bignum
            string a=m.str(1); 
            string b=m.str(3);

            bignum aa(a, precision);
            bignum bb(b, precision);
            //bignum c;

            switch (m.str(2)[0])
            {
            case '+':
                //c = aa + bb;
                *oss_ << aa + bb; 
                break;
            case '-':
                //c = aa - bb;
                *oss_ << aa - bb;
                break;
            case '*':
                //c = aa * bb;
                *oss_ << aa * bb;
                break;
            default:
                // validado desde el regex, no es posible que llegue acá;
                break;
            }
            s = m.suffix().str(); // se reinicia para la proxima captura
         }
    } 
    if (iss_->bad()) {
        cerr << "cannot read from input stream."
        << endl;
        exit(1);
    }
}