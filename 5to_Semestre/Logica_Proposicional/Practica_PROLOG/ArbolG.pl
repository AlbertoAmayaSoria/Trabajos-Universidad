%   Comentarios en linea.
/*  Comentarios en varias lineas
 *  para compilar swipl NombreArchivo.pl.
 */


/*
 *******************************************
 *              HECHOS(facts)
 *******************************************
*/
padre(juan,maria).
numero(5).
arista(a,b).
%   Todo termina en .
%   Predicados en minúscula


/*
 *******************************************
 *              REGLAS(rules)
 *******************************************
*/
%   Relaciónes lógicas
abuelo(X,Y):-
    padre(X,Z),
    padre(Z,Y).
%   Se lee: X es abuelo de Y si X es padre de Z y Z es padre de Y


/*
 *******************************************
 *              VARIABLES
 *******************************************
*/
%   Empiezan con mayúsuclas o _
%   X, Y, Nodo, _Temp


/*
 *******************************************
 *              CONSULTAS
 *******************************************
*/
%   Se hacen en la consola de prolog
/*
 *  ?- padre(juan, maria).
 *  ?- abuelo(X, maria).
*/


/*
 *******************************************
 *          OPERADORES LÓGICOS
 *******************************************
*/
/*
 *  ,   (AND)
 *  ;   (OR)
 *  \+  (NOT)
 *  =   (UNIFICACIÓN)
 *
 *      EJEMPO:
 *      humano(X) :- hombre(X).
 *      humano(X) :- mujer(X).
*/


/*
 *******************************************
 *          COMPARACIONES ARITMÉTICAS
 *******************************************
 */
%   No unifican, solo comparan valores.
%   X > Y
%   X < Y
%   X >= Y
%   X <= Y
%   X =:= Y     %   igualdad numérica.
%   X =\= Y     %   distinto numérico.
%
%   PROLOG
%   mayor(X, Y) :- X > Y.


/*
 *******************************************
 *              ARITMÉTICA(is)
 *******************************************
*/
%   Para calcular valores:
%   Correcto
%   Z is X + Y.
%   
%   Incorrecto:
%   Z = X + Y.


/*
 *******************************************
 *                  LISTAS
 *******************************************
*/
%   lista([1,2,3]).
%   [H|T]   % cabeza y cola
%
%   PROLOG:
%   miembro(X, [X|_]).
%   miembro(X, [_|T]) :- miembro(X, T).


/*
 *******************************************
 *      ESTRUCTURAS(muy importante)
 *******************************************
*/
%   ÁRBOL
%
%   arbol(raiz(izq, der)).
%   punto(X, Y).
%
%   EJEMPLO:
%   nodo(a,
%       nodo(b, nil, nil),
%       nodo(c, nil, nil)
%   ).


/*
 *******************************************
 *              RECURSIÓN
 *******************************************
*/
%   PROLOG:
%   profundidad(nil, 0).
%   profundidad(nodo(_, I, D), P) :-
%       profundidad(I, PI),
%       profundidad(D, PD),
%       P is max(PI, PD) + 1.


/*
 *******************************************
 *  ORGANIZACIÓN DE UN PROYECTO PROLOG
 *******************************************
*/

% ===== Hechos =====

% ===== Reglas =====

% ===== Consultas esperadas =====

%   EJEMPLO:

/*
    Hechos
    arista(a, b).
    arista(b, c).

    Reglas
    camino(X, Y) :- arista(X, Y).
    camino(X, Y) :- arista(X, Z), camino(Z, Y).
*/
