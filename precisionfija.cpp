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
void precision_fija::acumular(){
    string string_aux;
    size_t dato; //comparo con un unsigned int

    size_t flag_firstline = 0;
    size_t iterador = 0;
    cout<<"Entraste a a acumular"<<endl;
    cout<< precision <<endl;

    string s;
    smatch m;
    regex e ("\\b(\\d+|\\-\\d+|\\+\\d+)(\\+|\\*|\\-)(\\d+|\\-\\d+|\\+\\d+)$"); 

   

    while (getline(*iss_, s)){
        while (std::regex_search (s,m,e)) {
            //for (auto x:m) std::cout << x << "..";
            for (unsigned i=0; i<m.size(); ++i) {
                cout << "[" << m[i] << "] ";
            }
            std::cout << std::endl;
            s = m.suffix().str();
         }
    } 

 


    
    // T * vector_datos; //puntero para pedir memoria para almacenar points
    
    //Primero se re asigna la precision tomada por consola

   
}/* 
    ///////ahora se obtiene los puntos para el stream de entrada////
    //////////////////LAS CONSULTAS////////////////////
    
    size_t lineavacia= 0;
    
    while (getline(*iss_,string_aux))
    {
        if (string_aux.empty()==true) // si la linea está vacía,
        {
            break;
        }

        stringstream stream (string_aux); // convierte a flujo la linea
        
        vector_datos = new T [dimension_coordenadas];
        
        while (stream >> dato){ // mientras pueda interpretar el numero los almaceno en el vector creado
            if(iterador > dimension_coordenadas) break;
            vector_datos[iterador] = dato;
            iterador++;
        }
        if (iterador!=dimension_coordenadas || iterador<=1){ cerr << "Error different size or caracter unknown."
            << endl;
            exit(1);
        }
        iterador = 0; //reinicio iterador
        //aca tengo que mandar el nodo,
        lista_input.altaFinal(vector_datos);
        lineavacia = 0;
    }
    
    if (iss_->bad()) {
        cerr << "cannot read from input stream."
        << endl;
        exit(1);
    }
    
} */