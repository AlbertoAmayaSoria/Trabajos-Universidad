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

    (define plus                                      ;Suma
      (lambda (int1 int2)                                   ;Elementos a sumar
        (if (is-zero? int1)                              ;Si x es 0
            int2                                         ;Devolvemos y
            (successor (plus (predecessor int1) int2)))))   ;

    (define mult
      (lambda (int1 int2)
        (...)))
