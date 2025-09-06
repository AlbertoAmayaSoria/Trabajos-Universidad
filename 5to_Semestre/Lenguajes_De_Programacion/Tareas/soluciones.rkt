;;Ejercicio 1.1 Escribe la definición inductiva de los siguientes conjuntos. Escribe cada definición en los tres estilos (de arriba a abajo, de abajo a arriba y reglas de inferencia). Utilizando tus reglas, musetra la derivación de cadad conjunto.
;; llamamos x al resultado de una operación
;; 1.- {3n+2 | n ∈ N};
;;  -Abajo hacia arriba
;;    Definimos el conjunto S donde el subconjunto más pequeño que si cumple con las siguientes propiedades
;;    1. 2 ∈ S, y
;;    2. Si x ∈ S, entonces x+3 ∈ S.
;;    Probamos para n=0
;;    3(0)+2 = 2, entonces 2 ∈ S
;;    3(1)+2 = 5, entonces 2 ∈ S
;;    3(2)+2 = 8, entonces 2 ∈ S
;;    ....
;;    Probamos con la definición de abajo hacia arriba
;;    2 ∈ S, 2+3 = 5 ∈ S, 5+3 = 8 ∈ S
;;
;;  -Arriba hacia abajo
;;    Un número natuarl n esta contenido en S si y solo si
;;    1. n = 2, o
;;    2. n-3 ∈ S
;;
;;    Probamos para n = 8
;;    8 ≠ 2, enotnces 8 - 3 = 5 ∈ S
;;    5 ≠ 2, entonces 5 - 3 = 2 ∈ S
;;    2 = 2, entonces 8 si pertenece al conjunto
;;    
;;    Probamos para n = 9
;;    8 ≠ 2, enotnces 9 - 3 = 6 ∈ S
;;    6 ≠ 2, entonces 6 - 3 = 3 ∈ S
;;    3 = 2, entonces 3 - 3 = 0 ∉ S, ya que 0 es menor al caso base (2), por lo tanto 9 no pertenece al conjunto
;;
;;  -Reglas de inferencia
;;                 x ∈ S
;;    ---------  ---------
;;      2 ∈ S     x+3 ∈ S
;;
;; 2.- {2n+3m+1 | n,m ∈ N}
;;  -Abajo hacia arriba
;;    Definimos el conjunto como el conjunto de todos los naturales a exepcion de 0 y 2
;;    1. 1 ∈ S, y
;;    2. Si x ∈ S, entonces (x+2 o x+3) ∈ S
;;    Probamos combinaciones de n y m para conformar los elementos de S
;;    2(0) + 3(0) + 1= 1, entonces 1 ∈ S
;;    2(1) + 3(0) + 1= 3, entonces 3 ∈ S
;;    2(0) + 3(1) + 1  = 4, entonces 4 ∈ S
;;    2(2) + 3(0) + 1= 5, entonces 5 ∈ S
;;    2(1) + 3(1) + 1= 6, entonces 6 ∈ S
;;    2(0) + 3(2) + 1= 7, entonces 7 ∈ S
;;    ....
;;
;;  -Arriba hacia abajo
;;    Una dupla de números perteneces a S si y solo si
;;    1. x = 1, o
;;    2. (x-2) o (x-3) ∈ S
;;
;;  -Reglas de inferencia
;;                 x ∈ S       x ∈ S
;;    ---------  --------- o ---------
;;      1 ∈ S    (x+2) ∈ S   (x+3) ∈ S
;;
;; 3.- {(n, 2n+1) | n ∈ N}
;;  -Abajo hacia arriba
;;    Definimos el conjunto desde el subconjunto más pequeño contenido en el conjunto que cumple con las siguientes reglas
;;    1. (0, 1) ∈ S, y
;;    2. si n,m ∈ S, entonces, (n+1, m+2) ∈ S
;;
;;  -Arriba hacia abajo
;;    Definimos el conjunto como el conjunto de duplas con n siendo los naturales y m como los multipos de 2 + 1
;;    1. (n, m) = (0, 1), y
;;    2. (n-1, m -2) ∈ S
;;
;;  -Reglas inductivas
;;                  (n,m) ∈ S
;;    ---------  ---------------
;;    (0,1) ∈ S  (n+1, m+1) ∈ S
;;
;; 4.- {(n, n²) | n ∈ N}
;;  -Abajo hacia arriba
;;    1. (n, )
;;
;;
;;
;;
;;
;;
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.2
;;  ¿Qué conjuntos se definen por los siguientes pares de reglas? Explica porqué.
;;
;;  1.- (0,1) ∈ s     (n,k) ∈ s
;;                  -------------
;;                  (n+1,k+7) ∈ S
;;    Sigamos las reglas para construir los primeros elementos del conjunto
;;    (0, 1), (1, 8), (2, 15), (3, 22), (4, 29)....
;;    Podemos ver un patrón en el comportamiento de k, crece de 7 en 7, a excepcion de su primer elemento, por lo cual podemos decir que el conjunto es
;;    
;;    {(n, 7n+1 | n ∈ N}
;;
;;  2.- (0,1) ∈ S     (n,k) ∈ S
;;                  ------------
;;                  (n+1,2k) ∈ S
;;    Sigamos las reglas para construir los primeros elementos del conjunto
;;    (0, 1), (1, 2), (2, 4), (3, 8), (4, 16)....
;;    k tiene un comportamiento exponencial de la forma 2^n, ya que el siguiente elemento de k es el doble que el anterior
;;
;;    {(n, n^2)| n ∈ N}
;;
;;
;;  3.- (0,0,1) ∈ S      (n,i,j) ∈ S
;;                    -----------------
;;                    (n+1, j, i+j) ∈ S
;;    Sigamos las reglas para construir los primeros elementos del conjunto
;;    (0,0,1), (1,1,1), (2,1,2), (3,2,3), (4,3,5), (5,5,8), (6,8,13), (7,13,21)....
;;    Podemos encontrar el mismo patron en i y j, solo que uno inicia desde una posicion antes, el elemento es la suma de sus dos elementos anteriores, lo que se define como fib(n) y fib(n+1)
;;
;;    {(n, fib(n), fib(n+1)) | n ∈ N}
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.3
;;  Encuentre el conjunto T de números naturales tales que 0 ∈ T, y siempre que n ∈ T, entonces n + 3 ∈ T, pero T≠S, donde S es el conjunto {3n | n ∈ N}
;;
;;  T = {n | n ∈ N}
;;  T≠S y S es subconjunto de T
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.4
;;  Escribe la derivación de List-of-int para
;;
;;  (-7.(3.(14.())))
;;
;;  List-of-int ::= ()
;;              ::= (int. List-of-int)
;;  (int. List-of-int)
;;  (-7. (int. List-of-int))
;;  (-7. (3. (int. List-of-int)))
;;  (-7. (3. (14. ())))
;;  (-7. (3. (14 )))
;;  (-7. (3. 14))
;;  (-7 3 14)
;;
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.5
;;  Demuestre que si e ∈ LcExp, entonces, hay el mismo número de paréntesis izquierdo y derecho en e
;;  LcExp ::= e
;;        ::= (lambda (e) LcExp)
;;        ::= (LcExp LcExp)
;;  -Hipotesis de inducción
;;  Cuando LcExp es solo un identifier, ebtinces parentesis izquiero = PI(e) = 0 y parentesis derecho = PI = 0, esto es trivial
;;
;;  -Cuando LcExp es una función anonima
;;  LcExp ::= (lambda (e) LcExp)
;;  Tenemos PI = 1 antes de "lambda" y PI = 2 antes de "e", tambien tenemos PD = 1 después de "e" y PD = 2 despues de LcExp, si LcExp fue generada dentro de otra LcExp (función anonima) esta esta ordenada con PI = PD, los cuales al sumarlos a PI_externos = m + PI = m = PD = PD_externos.
;;
;;  -Cuando LcExp es una aplicación
;;  Tenemos PI = 1 antes de LcExp y PD = 1 después de LcExp, por lo tanto PI = PD.
;;
;;  Debido a que, en cualquiera de las producciones de LcExp genera el mismo número de parentesis de apertura como de clausura, podemos afirmar que cualquier estructura generada por LcExp tendra parentesis balanceados, ya que las subestrcutura siempre se mantienen en balance, e ∈ LcExp.
;;
;;
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.12
;;  Eliminar la única llamada a subst-in-s-exp dentro de subst remplazandolo por su definición y simplificando el procedimiento resultante. El resultado será una versión de subst que no necesite subst-in-s-exp.
;;  Esta técica es llamada inlining (o "expansión en linea") y es utilizada por los compiladores para optimizar código.
;;
;;  sexp = car slist
;;
;;  subst : sym x sym x s-list → s-list
    (define subst
      (lambda (new old slist)
        (if (null? slist) 
            '()                                ;  Caso base: lista vacía → devuelve lista vacía
            (cons 
              (if (symbol? (car slist))        ;  Revisamos el primer elemento de la lista
                  (if (eqv? (car slist) old)   ;  Si es un símbolo, lo comparamos con "old"
                      new                      ;  - Si coincide con "old", lo reemplazamos por "new"
                      (car slist))             ;  - Si no coincide, lo dejamos igual
                  (subst new old (car slist))) ;  Si el primer elemento es una sublista, recursión dentro
              (subst new old (cdr slist))))))  ;  Luego seguimos procesando el resto de la lista


;;------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.18
;;  (Swapper s1 s2 slist) devuelve una lista igual que slist, pero con todas las ocurrencias de s1 reemplazadas por s2 y todas las ocurrencias de s2 reemplazadas por s1

    (define swapper
      (lambda (s1 s2 slist)
        (cond ;Condicional multiple, evalua en orden y selecciona la primera verdadera
          ;;  Caso base, lista vacía devuelve una lista vacía
          ((null? slist) '())

          ;;  Si el primer elemento es una sublista aplicamos recursión en la sublista
          ((list? (car slist))
           (cons (swapper s1 s2 (car slist))
                 (swapper s1 s2 (cdr slist))))

          ;;  Si el simbolo es igual a s1 lo remplaza por s2
          ((eqv? (car slist) s1)
           (cons s2 (swapper s1 s2 (cdr slist))))

          ;;  Si el simbolo es igual a s2 lo remplaza por s1
          ((eqv? (car slist) s2)
           (cons s1 (swapper s1 s2 (cdr slist))))

          ;;  En cualquier otro caso se queda igual
          (else
            (cons s1 (car slist) (swapper s1 s2 (cdr slist)))))))


;;------------------------------------------------------------------------------------------------------------------
