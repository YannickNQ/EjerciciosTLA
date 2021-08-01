#include <iostream>
#include <string>
using namespace std;

class Automata{
private:
    string cad;
    bool acept;
    int cant;
public:
    Automata(string cad){
        this->cad = cad;
        acept = false;
        cant=0;
    }
    void Iniciar(){
            if(cad.size() == 0){
                acept = false;
            }else{
                estaq0();
            }
    }
    bool Aceptado(){
        return acept;
    }
    void estaq0(){
        if(cant < cad.size()){
            if(cad.at(cant) == 'a'){
                cant++;
                acept = false;
                estaq1();
            }
        }
    }
    void estaq1(){
        if(cant < cad.size()){
            if(cad.at(cant) == 'a'){
                cant++;
                acept = true;
                estaq3();
            }else if(cad.at(cant) == 'b'){
                cant++;
                acept = false;
                estaq2();
            }else if(cad.at(cant) == 'c'){
                cant++;
                acept=false;
                estaq1();
            }
        }
    }
    void estaq2(){
        if(cant < cad.size()){
            if(cad.at(cant) == 'a'){
                cant++;
                acept=true;
                estaq3();
            }else if(cad.at(cant) == 'c'){
                cant++;
                acept=false;
                estaq1();
            }
        }
    }
    void estaq3(){
       if(cant < cad.size()){
            if(cad.at(cant) == 'a'){
                cant++;
                acept = true;
                estaq3();
            }else if(cad.at(cant) == 'b'){
                cant++;
                acept = false;
                estaq1();
            }else if(cad.at(cant) == 'c'){
                cant++;
                acept=false;
                estaq4();
            }
       }
    }
    void estaq4(){
        if(cant < cad.size()){
            if(cad.at(cant) == 'a'){
                cant++;
                acept = true;
                estaq3();
            }else if(cad.at(cant) == 'b'){
                cant++;
                acept = false;
                estaq2();
            }else if(cad.at(cant) == 'c'){
                cant++;
                acept=false;
                estaq4();
            }
       }
    }
};
int main(){

    string cadena("aaabcbccbacabacabcacba");
    Automata *au = new Automata(cadena);
    au->Iniciar();
    if(au->Aceptado() == 1){
        cout<<"La cadena "<<cadena<<" es reconocida por el automata."<<endl;
    }else{
        cout<<"La cadena no es reconocida por el automata."<<endl;
    }
    system("PAUSE");
    return 0;
}
