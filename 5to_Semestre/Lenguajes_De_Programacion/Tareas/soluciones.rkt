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
;;Ejercicio 1.6
;;  Si revertimos el orden de las pruebas en nth-element, ¿qué saldría mal?
;;  
;;    Si se invierte el orden de las pruebas en nth-element:
;;    Primero se intenta hacer (car lst) aunque lst = ()
;;    esto produce un error: car de la lista vacía
;;
;;    Ejemplo de problema:
;;    (nth-element '() 0)
;;    Aquí n = 0 pero la lista está vacía.
;;    La función entra directo a (car lst) sin comprobar antes si es null?.
;;    Resultado: error de Scheme ("car de lista vacía").
;;
;;    Otro caso:
;;    (nth-element-bad '(a) 1)
;;    Primera llamada: n ≠ 0 y la lista no está vacía,
;;    entonces hace recursión sobre (cdr '(a)) = ().
;;    Segunda llamada: ahora n = 0 pero lst = (),
;;    intenta hacer (car ()) y falla.
;;    Resultado: error por aplicar car a una lista vacía.
;;
;;    ;;Version con el orden invertido:
      (define nth-element-bad
        (lambda (lst n)
          (cond
            [(zero? n) (car lst)]     ;;intenta car antes de revisar null?// EROR//
            [(null? lst) (error "lista vacia")]
            [else (nth-element-bad (cdr lst) (sub1 n))])))
;;    
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.7
;;  El mensaje de error de nth-element no es informativo. 
;;  Reescribe nth-element de manera que produzca un mensaje 
;;  de error más informativo, como “(a bc) no tiene 8 elementos.”
;;
    (define (elemento-n-aux lista-original lista n-original n)
      (cond ((null? lista)
             (lista-demasiado-corta lista-original n-original))
        ((zero? n)
         (first lista))
        (else
          (elemento-n-aux lista-original (rest lista) n-original (- n 1)))))

    (define (elemento-n lista n)
      (elemento-n-aux lista lista n n))

    (define (lista-demasiado-corta lista n)
      (error 'lista-demadiado-corta
             "~a no tiene ~a ~a"
             lista (+n 1)
             (if (zero? n) "elemento" "elementos")))
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.8
;;  En la definición de remove-first, si la última línea se reemplazara
;;  por (remove-first s (cdr los)), ¿qué función calcularía el procedimiento
;;  resultante? Proporciona el contrato, incluyendo la declaración de uso, 
;;  para el procedimiento revisado.
;;
      (define remove-first
        (lambda (s los)
          (if (null? los)
              '()
              (if (eqv? (car los) s)
                  (cdr los)
                  (remove-first s (cdr los))))))
;;  Lo que sucede es que al eliminar cons, estamos eliminando los elementos antes de y la primer ocurrencia del valor en caso de que se encuentre para devolver la lista despues del valor, si no se encuentra el valor se eliminan todos los elementos y se devuelve una lista vacia.

;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.9
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.10
;;  Normalmente usamos “or” para significar “o inclusivo”. ¿Qué otros significados puede tener “or”?
;;    Puede ser uno u otro elemento OR, o un elemento exclusivo de dos XOR
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.11
;;  En la última línea de subst-in-s-exp, la recursión se hace sobre sexp y no sobre una subestructura más pequeña. ¿Por qué se garantiza que la recursión terminará?
;;    Cada vez que se subst se llama, trabaja con el cdr de la lista, 
;;    que es más pequeño, eventualmente se llega a la lista vacía. 
;;    En el caso de los simbolos, se toma una desición (ya no hay recursión)
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
;;Ejercicio 1.13
;;  En nuestro ejemplo, comenzamos eliminando la estrella de Kleene en la gramática para S-list. Escribe subst siguiendo la gramática original usando map.
;;
;;    Propósito: reemplazar cada aparición del símbolo "old"
;;    con el símbolo "new" en una s-list.
;;    La solución utiliza recursión y map para recorrer listas 
;;    que pueden ser anidadas.
;;    

      ;;Definición principal, reemplazamos todas las ocurrencias de `old` por `new` en una s-list.
      (define (subst new old slist)
        ;;Usa `map` para aplicar la transformación a cada elemento de la lista.
        ;;Esto evita tener que escribir explícitamente la recursión aquí.
        (map (lambda (sexp) (subst-in-s-exp new old sexp)) slist))

      ;;Función auxiliar: procesa un símbolo o una sublista.
      (define (subst-in-s-exp new old sexp)
        (cond
          ;; Caso 1: si `sexp` es un símbolo, verificamos si coincide con `old`.
          ;; En ese caso lo reemplazamos por `new`; si no, lo dejamos igual.
          ((symbol? sexp) (if (eqv? sexp old) new sexp))

          ;; Caso 2: si `sexp` no es un símbolo, asumimos que es una lista (s-list).
          ;; Aplicamos recursión llamando otra vez a `subst` sobre esa lista.
          (else (subst new old sexp))))

;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.14
;;  Dada la suposición 0 ≤ n < length(v), demuestra que partialvector-sum es correcto.
;;
;;    Partimos de la suposición 0 ≤ n < length(v), esto nos garantiza que el vector v tiene al menos 1 elemento
;;    
;;    aplicamos induccion sobre n
;;    Caso base 
;;    partial-vector-sum(v,n) = vector-ref v 0 = v_0
;;    La suma de indices desde 0 hasta 0 es v_0 
;;    Por lo tanto, la propiedad se cumple para n = 0
;;    
;;
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.15
;;  
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.16
;;  (invert lst), donde lst es una lista de listas de 2 elementos (listas de longitud dos), devuelve una lista con cada sublista de 2 elementos invertida.
;;
    (define (invert slist)
      (if (null? slist)                       ; si la lista está vacía
          '()                                 ; devolvemos lista vacía
          (cons (list (car (cdr (car slist))) ; invertimos la primera sublista
                                              ; (car slist) -> primer sublista
                                              ; (cdr (car slist)) -> devuelve la lista sin el primer elemento
                                              ; (car (cdr (car slist))) toma el primer elemento de la sublista (el que era el primero)
                                              ;
                      (car (car slist)))      ; primer elemento
                                              ; (car slist) -> toma la primer sublista
                                              ; (car (car slist)) -> devuelve el primer elemento de esa sublista
                (invert (cdr slist)))))       ; recursión sobre el resto

;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.17
;;  (down lst) pone paréntesis alrededor de cada elemento de nivel superior de lst.
      (define down
        (lambda (lst)
          (if (null? lst)                 ; caso base
              '()
              (cons (list (car lst))      ; envuelve el primero (x)
                                          ; (car slist) -> toma el primer elemento/sublista
                                          ; (list (car slist)) -> Crea una nueva sublista con el primer elemento de la lista "envolviendo a nivel superior" el elemento
                    (down (cdr lst))))))  ; Recorre el resto de la lista
;;-------------------------------------------------------------------------------------------------------------------
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
            (cons (car slist) (swapper s1 s2 (cdr slist)))))))


;;------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.19
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.20
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.21
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.22
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.23
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.24
;;  (every? pred lst) devuelve #f si algún elemento de lst no satisface pred, y devuelve #t en caso contrario.
    
    (define every?
      (lambda (pred lst)
        (if (null? lst)
            #t                           ; Caso base, si la lista esta vacía todos cumplen
            (if (pred (car lst))         ; El primer elemento cumple con el predicado?
                (every? pred (cdr lst))  ; Si lo cumple, seguimos con el resto
                #f))))                   ; Si no lo cumple, devolvemos #f

;;------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.25
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.26
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.27
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.28
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.29
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.30
;;  (sort/predicate pred loi) devuelve una lista de elementos ordenados segun el predicado pred
    
    (define 
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.31
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.32
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.33
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.34
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.35
;;-------------------------------------------------------------------------------------------------------------------
;;Ejercicio 1.36


