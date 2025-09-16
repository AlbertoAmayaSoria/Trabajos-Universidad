;;  AMAYA SORIA ANGEL ALBERTO
;;
;;  SECCION 2
;;
;;----------------------------------------------------------------------------
;;  EJERCICIO 2.1
;;  Implementa las cuatro operaciones necesarias para los bigits. Luego utiliza tu implementación para calcular el factorial de 10.
;;  ¿Cómo varía el tiempo de ejecución a medida que cambia este argumento?
;;  Si cambiamos el valor del factorial, mientras mayor es este mayor será el tiempo de ejecución, porque el factorial crece de manera muy acelerada y considerando que estamos trabajando con una lista para representarlo, esta lista será proporcional al tamaño del factorial
;;  
;;  ¿Cómo varía el tiempo de ejecución a medida que cambia la base?
;;  Mientras mayor es la base, es menor el timepo que tarda, ya que es menor la cantidad de divisiones que tiene que realizar recursivamente.
;;
;;  IMPLEMENTACIÓN
;;
    (define zero (lambda () 0))                             ; cero como función que devuelve 0
    (define is-zero? (lambda (n) (zero? n)))                ; comprueba si un número es 0
    (define successor (lambda (n) (+ n 1)))                 ; suma 1
    (define predecessor (lambda (n) (- n 1)))               ; resta 1

    (define plus                                            ; Suma
      (lambda (int1 int2)                                   ; Elementos a sumar
        (if (is-zero? int1)                                 ; Si x es 0
            int2                                            ; Devolvemos y
            (successor (plus (predecessor int1) int2)))))   ; 


    (define mult                                              ; Multipliación
      (lambda (int1 int2)                                     ; Argumentos a multiplicar
        (cond
          ((equal? int1 1) int2)                              ; Multiplicar x por 1 es igual a x
          ((equal? int2 1) int1)
          ((equal? int1 0) 0)                                 ; Multiplicar por 0 es 0
          ((equal? int2 0) 0)

          (else                                               ; Si no
            (plus (mult(predecessor int1) int2) int2)))))     ; Sumamos int1 veces a int2, recursivamente llamamos a (mult (int1 - 1) int2) hasta que int1 sea igual a 1

    (define factorial                                         ; Factorial
      (lambda (int)                                           ; Número a aplicar el factorial
        (cond
          ((< int 0) '"No hay factorial para números menores que 0")
          ((equal? int 0) 1)                                  ; El factorial de 0 es 1 caso base

          (else 
            (mult int (factorial(predecessor int)))))))     ; Aplicamos recursión sobre la multipliación, (int x (int-1 x (...(1))))

    ; Implementar bignum con el metodo de diviciones
    
    (define bignum                                          ; Bignum
      (lambda (base numero)                                 ; Base a convertir, numero a convertir
        (if (< numero base)                                 ; Cuando es menor el numero que la base, se queda de la misma forma
            (list numero)                                   ; Regresamos la lista con el numero como es
                                                            ; Si no aplicamos "división"
            (cons (modulo numero base)                      ; nos quedamos con el residuo de la división y seguimos trabajando con la parte entera de manera recursiva
                  (bignum base (quotient numero base))))))  ; Seguimos trabajando con la parte entera de la división recursivamente


;;----------------------------------------------------------------------------
;;  EJERCICIO 2.2
;; Analiza críticamente cada una de estas representaciones propuestas. ¿En qué medida logran o no cumplir con la especificación del tipo de dato?
;; Logran un buen cumplimineto en general, sin embargo, no son métodos muy eficientes


;;----------------------------------------------------------------------------
;;  EJERCICIO 2.3
;;  Define una representación de todos los enteros (negativos y no negativos) como diff-trees, donde un diff-tree es una lista definida por la gramática:
;;  
;;  Diff-tree ::= (one) | (diff Diff-tree Diff-tree)
;;
;;  La lista (one) representa el número 1. Si t1 representa n1 y t2 representa n2, entonces (diff t1 t2) es una representación de n1 − n2.

;;  Por lo tanto, tanto (one) como (diff (one) (diff (one) (one))) son representaciones del número 1; (diff (diff (one) (one)) (one)) es una representación de −1.

;;  Demuestra que cada número tiene infinitas representaciones en este sistema.

;;  Convierte esta representación de los enteros en una implementación escribiendo las funciones zero, is-zero?, successor y predecessor, como se especifica en la página 32, excepto que ahora también se representan los enteros negativos. Tus procedimientos deben aceptar cualquiera de las múltiples representaciones legales de un entero en este esquema. Por ejemplo, si tu procedimiento successor recibe cualquiera de las infinitas representaciones legales de 1, debería producir una de las representaciones legales de 2. Es aceptable que diferentes representaciones legales de 1 produzcan diferentes representaciones legales de 2.

;;  Escribe un procedimiento diff-tree-plus que realice suma en esta representación.
;;  Tu procedimiento debe estar optimizado para la representación diff-tree y debe realizar su trabajo en tiempo constante (independiente del tamaño de sus entradas). En particular, no debe ser recursivo.
