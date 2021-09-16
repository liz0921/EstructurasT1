
#include <iostream>
#include "nodoS.h"
#include "gestor.h"
using namespace std;
void menu(); 

int main()
{
    menu(); 
}


void menu() {
    char otro='s';
    int n1, n2, n3,n4; 
    gestor* gest = new gestor();
   
    gest->setLista(NULL);
    gest->setCola(NULL);
    gest->setPila(NULL);

    
    do
    {
        cout << "\n" << endl;
        cout << "----------MENU----------" << endl;
        cout << " 1. Hacer una lista:" << endl;
        cout << " 2. Mostrar lista:" << endl;
        cout << " 3. Hacer una pila:" << endl;
        cout << " 4. Mostrar una pila:" << endl;
        cout << " 5. Hacer una cola:" << endl;
        cout << " 6. Mostrar una cola:" << endl;
        cout << " 7. Pasar Lista a cola:" << endl;
        cout << " 8. Pasar Lista a pila:" << endl;
        cout << " 9. Pasar Pila a lista:" << endl;
        cout << "10. Pasar Pila a cola:" << endl;
        cout << "11. Pasar Cola a lista:" << endl;
        cout << "12. Pasar Cola a pila:" << endl;

        cout << " --------------------" << endl;
        cout << " Elija una opcion." << endl;
        cin >> n1;
        switch (n1)

        {
        case 1:
         
            do
            {
                cout << " Digite un numero:" << endl;
                cin >> n2;
                gest->agregarLista(n2);
                cout << " Se agrego correctamente el valor:"<<n2 << endl;
                cout << " Desea agregar otro valor?  s/n " << endl;
                cin >> otro;
            } while (otro!='n');
          
            break;
        case 2:
            gest->imprimirLista();
            break;
        case 3:
            do
            {
                cout << " Digite un numero:" << endl;
                cin >> n3;
                gest->agregarPila(n3);
                cout << " Se agrego correctamente el valor:" << n3 << endl;
                cout << " Desea agregar otro valor?  s/n " << endl;
                cin >> otro;
            } while (otro != 'n');
            break;


        case 4:
            gest->imprimirPila();
            break;
        
        case 5:

            do
            {
                cout << " Digite un numero:" << endl;
                cin >> n4;
                gest->agregarCola(n4);
                cout << " Se agrego correctamente el valor:" << n4 << endl;
                cout << " Desea agregar otro valor?  s/n " << endl;
                cin >> otro;

            } while (otro != 'n');
            break;

        case 6:
            gest->imprimirCola();
            break;
         case 7:
            gest->pasarListaCola(); 
            break;

         case 8:
             gest->pasarListaPila();
             break;
         case 9:
             gest->pasarPilaLista();
             break;
         case 10:
             gest->pasarPilaCola();
             break;
         case 11:
             gest->pasarColaLista();
             break;
         case 12:
             gest->pasarColaPila();
             break;
        }
    } while (true);
}
