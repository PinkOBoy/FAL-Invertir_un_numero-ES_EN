/*
* USUARIO DEL JUEZ: G04
* NOMBRE Y APELLIDOS: JAIME BENEDI GALDEANO
*/
#include <iostream>
using namespace std;

//--ENGLISH--------------------------------------------------------------------------
/**RECURRENCE EQUATIONS
* For every call, the size of the problem is reduced in one unit,
* that is, in each call does some calculations (O(1)) on a number
* of one digit lesser than the previous call.
*
* Defining:
*
*   n::= number of digits of the value has.
*
* We know, thanks to the Generalitation techniques for recursive
* algorithms, that, in case the problem gets reduced in a specific
* amount of data (a constant is subtracted from thesize of the problem
* in each call), its recurrence equations will be:
* 
*        | c0                       0 <= n <= n0
*   T(n)=|
*        | a * T(n - b) + c1 * n^k  n >= n0
*
* Where:
*
*   a::= number of recursive calls inside of the algorithm.
*   b::= subtrahend
*   k::= a number so n^k represents the complexity of the non-recursive code
*        of our algorithm.
*
* Therefore, we can affirm that the recurrence equations of our algorithm are:
* 
*          |c0                         n = 1
*    T(n)= |
*          |1 * T(n - 1) + c1 * n^0    n > 1
*/
/** COMPLEXITY OF THE ALGORITHM
 * Thanks to the previosly defined information and to the Generalitation
 * techniques for recursive algorithms, we know that, when the recurrence
 * equations look like:
 * 
 *        | c0                       0 <= n <= n0
 *   T(n)=|
 *        | a * T(n - b) + c1 * n^k  n >= n0
 *
 * The following assumptions are correct:
 * 
 *  a = 1 -> T(n) belongs to O(n ^ k+1)
 *  a > 1 -> T(n) belongs to O(a ^ n/b)
 * 
 * Applying it to our recurrence equations:
 * 
 *  a = 1 -> T(n) belongs to O(n ^ 0+1)
 * 
 * Therefore, T(n) belongs to O(n).
*/

//--SPANISH--------------------------------------------------------------------------
/*ECUACIONES DE RECURRENCIA:
* Por cada llamada, el tamaño del problema se reduce en una unidad,
* es decir, por cada llamada, hay que realizar los calculos sobre
* un numero con un digito menos que la anterior llamada.
* 
* Definimos:
* 
*   n::= cantidad de digitos que tiene el numero.
* 
* Sabemos, por la generalizacion de las ecuaciones de recurrencia
* de un algoritmo y el estudio de su coste, que, cuando problema
* se reduce un numero concreto de datos (se resta una constante al
* tamaño del problema por cada llamada), su ecuacion de recurrencia
* sera:
* 
*        | c0                       0 <= n <= n0
*   T(n)=|
*        | a * T(n - b) + c1 * n^k  n >= n0
* 
* Donde:
* 
*   a ::= numero de llamadas recursivas dentro del algoritmo
*   b ::= constante equivalente a cuanto reducimos el tamaño del problema por llamada
*   k ::= numero tal que n^k represente el coste de eficiencia del
*         resto del codigo no recursivo del algoritmo.
* 
* Por ello, declaramos las ecuaciones de recurrencia de nuestro algoritmo como:
* 
*       |c0                         n = 1
* T(n)= |
*       |1 * T(n - 1) + c1 * n^0    n > 1
*/
/*COMPLEJIDAD DEL ALGORITMO:
* Dado los datos definidos anteriormente y gracias a la Generalizacion
* de las ecuaciones de recurrencia de un algoritmo y el estudio de sus costes,
* sabemos que, cuando las ecuaciones de recurrencia de un algoritmo tienen
* apariencia tal que:
* 
*        | c0                       0 <= n <= n0
*   T(n)=|
*        | a * T(n - b) + c1 * n^k  n >= n0
* 
* Se cumplira lo siguiente:
* 
*   a = 1 -> T(n) pertenece a O(n ^ k+1)
*   a > 1 -> T(n) pertenece a O(a ^ n/b)
* 
* Aplicandolo a nuestra ecuacion de recurrencia:
* 
*   a = 1 -> T(n) pertenece a O(n ^ 0+1)
* 
* Por lo tanto, T(n) pertenece a O(n).
*/
int inv(int n, int& base) {
    //CASO BASE: cuando sea no se pueda dividir en mas digitos
    //DIRECT CASE: when more digits cannot be extracted any longer
    if (n / 10 == 0)
        return n;
        //base = 1;
    //CASO RECURSIVO: Se puede seguir dividiendo y hay que construir el nuevo numero
    //RECURSIVE DESCOMPOSITION: there is more than one digit and we have to pass the new number 
    else {
        int u = inv(n / 10, base);
        base *= 10;
        return (n % 10) * base + u;
    }
}

bool solve() {
    // read case
    int n;
    cin >> n;
    if (n < 0)
        return false;

    // compute solution
    int b = 1;

    // write solution
    cout << inv(n,b) << endl;

    return true;
}

int main() {
    // uncomment to read from a file instead of standard input
    // ifstream ifs("sample.in");
    // cin.rdbuf(ifs.rdbuf());

    while (solve());

    return 0;
}