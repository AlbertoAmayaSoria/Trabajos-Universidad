;;  AMAYA SORIA ANGEL ALBERTO
;;
;;  SECCION 2
;;
;;  EJERCICIO 2.1
;;  Implementa las cuatro operaciones necesarias para los bigits. Luego utiliza tu implementación para calcular el factorial de 10.
;;  ¿Cómo varía el tiempo de ejecución a medida que cambia este argumento?
;;  
;;  ¿Cómo varía el tiempo de ejecución a medida que cambia la base?
;;  
;;  Explica por qué.
;;
;;  IMPLEMENTACIÓn
;;
    (define zero (lambda () 0))                 ; cero como función que devuelve 0
    (define is-zero? (lambda (n) (zero? n)))    ; comprueba si un número es 0
    (define successor (lambda (n) (+ n 1)))     ; suma 1
    (define predecessor (lambda (n) (- n 1)))   ; resta 1

    (define plus                                            ; Suma
      (lambda (int1 int2)                                   ; Elementos a sumar
        (if (is-zero? int1)                                 ; Si x es 0
            int2                                            ; Devolvemos y
            (successor (plus (predecessor int1) int2)))))   ; 

    ;(define mult referencia de tabulador

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
          ((
          ((equal? int 0) 1)                                  ; El factorial de 0 es 1 caso base

          (else 
            (mult int [factorial(predecessor int)])))))))     ; Aplicamos recursión sobre la multipliación, (int x (int-1 x (...(1))))

    .
