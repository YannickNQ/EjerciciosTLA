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
            acept=true;
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
            }else if(cad.at(cant) == 'b'){
                cant++;
                acept = true;
                estaq2();
            }
        }
    }
    void estaq1(){
        if(cant < cad.size()){
            if(cad.at(cant)=='a'){
                cant++;
                acept = true;
                estaq0();
            }else if(cad.at(cant) == 'b'){
                cant++;
                acept=true;
                estaq2();
            }
        }
    }
    void estaq2(){
        if(cant < cad.size()){
            if(cad.at(cant) == 'a'){
                cant++;
                acept=false;
                estaq1();
            }
        }
    }
};
int main(){

    string cadena("aaabababab");
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
