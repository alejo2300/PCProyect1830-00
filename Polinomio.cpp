#include <iostream>
#include <math.h>
using namespace std;

struct Nodo{
    int base;
    int exponente;
    Nodo *sig;
};

struct Lista{
    Nodo *cab;
    int tam;
};

Lista *crearLista();

void insertarPolinomio(int bas, int exp,Lista *a);

void imprimir(Lista *pLista);

bool vacia(Lista *pLista);

Lista *sumarPolinomios(Lista *lista1, Lista *lista2, Lista *resuma);

int evaluarVariable(Lista *evaluar, int evaluador);

int main() {
    Lista *a,*b,*resuma,*evaluar;
    int bas,exp;
    a=crearLista();
    b=crearLista();
    int evaluadito;
    evaluar=crearLista();
    resuma=crearLista();
    cout <<endl;
    int opcion=0;
    while(opcion!=3) {
        cout << "Seleccine lo que desea hacer con sus polinomios\n1.Para sumar dos polinomios\n2.Para evaluar un polinomio\n3.Para salir\nSu opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1 : cout<<"Introduzca el numero de coeficientes para el polinomio A: ";
                     int cofa;
                     cin>>cofa;
                     for (int i = 0; i < cofa; ++i) {
                         cout<<"Introduzca la base del "<<i+1<<" coeficiente: ";
                         cin>>bas;
                         cout<<"Introduzca el exponente del "<<i+1<<" coeficiente: ";
                         cin>>exp;
                         insertarPolinomio(bas,exp,a);
                     }
                     imprimir(a);
                     cout<<"Introduzca el numero de coeficientes para el polinomio B: ";
                     int cofb;
                     cin>>cofb;
                     for (int i = 0; i < cofb; ++i) {
                         cout<<"Introduzca la base del "<<i+1<<" coeficiente: ";
                         cin>>bas;
                         cout<<"Introduzca el exponente del "<<i+1<<" coeficiente: ";
                         cin>>exp;
                         insertarPolinomio(bas,exp,b);
                     }
                     imprimir(b);
                     resuma=sumarPolinomios(a,b,resuma);
                     cout<<endl;
                     imprimir(resuma);
                     cout<<endl;
                break;
            case 2 : cout<<"Introduzca el numero de coeficientes para el polinomio a evaluar: ";
                     int cofeva;
                     cin>>cofeva;
                     cout<<"Intoduzca el numero con el cual desea evaluar el polinomio: ";
                     int evaluador;
                     cin>>evaluador;
                     for (int i = 0; i < cofeva; ++i) {
                         cout << "Introduzca la base del " << i + 1 << " coeficiente: ";
                         cin >> bas;
                         cout << "Introduzca el exponente del " << i + 1 << " coeficiente: ";
                         cin >> exp;
                         insertarPolinomio(bas, exp, evaluar);
                     }
                     evaluadito=evaluarVariable(evaluar,evaluador);
                     cout<<"El resultado del polinomio evaluado es: "<<evaluadito<<endl<<endl;
                break;
            case 3 : cout<<"Hasta luego\n";
                break;
            default : cout<<"Opcion incorrecta\n";
                break;
        }
    }
    return 0;

}

int evaluarVariable(Lista *evaluar, int evaluador) {
    Nodo *eval;
    eval=new Nodo;
    eval=evaluar->cab;
    int numero=0;
    int numero2=0;
    for (int i = 0; i < evaluar->tam; ++i) {
        numero=0;
        numero=pow(evaluador,eval->exponente);
        numero=numero*(eval->base);
        numero2=numero2+numero;
        eval=eval->sig;
    }
    return numero2;
}

Lista *sumarPolinomios(Lista *lista1, Lista *lista2, Lista *resuma) {
    Nodo *a,*b;
    Nodo *resu;
    resu=new Nodo;
    a=new Nodo;
    b=new Nodo;
    a=lista1->cab;
    b=lista2->cab;
    for (int i = 0; i < lista1->tam; ++i) {
        for (int j = 0; j < lista2->tam; ++j) {
            if(a->exponente==b->exponente){
                insertarPolinomio(((a->base)+(b->base)),(a->exponente),resuma);
            }
            b=b->sig;
        }
        a=a->sig;
        b=lista2->cab;
    }
    int bandera=0;
    a=lista1->cab;
    resu=resuma->cab;
    for (int k = 0; k < lista1->tam; ++k) {
        for (int i = 0; i < resuma->tam; ++i) {
            if(a->exponente==resu->exponente){
                bandera++;
            }
            resu=resu->sig;
        }
        if(bandera==0){
            insertarPolinomio(a->base,a->exponente,resuma);
        }
        bandera=0;
        a=a->sig;
        resu=resuma->cab;
    }
    bandera=0;
    b=lista2->cab;
    resu=resuma->cab;
    for (int k = 0; k < lista2->tam; ++k) {
        for (int i = 0; i < resuma->tam; ++i) {
            if(b->exponente==resu->exponente){
                bandera++;
            }
            resu=resu->sig;
        }
        if(bandera==0){
            insertarPolinomio(b->base,b->exponente,resuma);
        }
        bandera=0;
        b=b->sig;
        resu=resuma->cab;
    }
    return resuma;
}

void imprimir(Lista *lista) {
    if(vacia(lista))
    {
        cout<<"Polinomio: "<<endl;
    }
    else
    {
        cout<<"La informacion de la Lista es:"<<endl;
        Nodo * aux;
        aux = lista->cab;
        int pos = 1;
        while(aux != NULL)
        {
            cout<<" "<<aux->base<<"x^"<<aux->exponente<<" ";
            aux = aux->sig;
            pos++;
        }
    }
    cout<<endl;
}

bool vacia(Lista *lista) {
    if(lista->tam == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insertarPolinomio(int bas, int exp, Lista *lista) {
    Nodo * nuevo;
    nuevo = new Nodo;
    nuevo->base = bas;
    nuevo->exponente = exp;
    nuevo->sig = NULL;
    if(lista->tam == 0)
    {
        lista->cab = nuevo;
        lista->tam++;
    }
    else
    {
        Nodo * aux;
        aux = lista->cab;
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
        lista->tam++;
    }
}


Lista *crearLista() {
    Lista * lista = new Lista;
    lista->tam = 0;
    lista->cab = NULL;
    return lista;
}
