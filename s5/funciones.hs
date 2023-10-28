-- Implementar una funcion que devuelva una lista de numeros enteros pares
-- hasta el 100.
-- TIP: [     | x <- []  , <PREDICADO>  ]

crearEnterosPares :: [Int]
crearEnterosPares = [ x  | x <- [1..100] , (mod x 2) == 0 ]

-- Implementar una funcion que permita operar una lista de numeros del 1 al 50,
-- pero esta operacion sea pasada como argumento de entrada.
-- Esta funcion que se pasa como argumento de entrada solo tendra un operando.
operarLista :: [Int] -> (Int -> Int) -> [Int]
lista :: [Int] = [1..50]
operarLista listaEnteros f =
    [ f x  | x <- listaEnteros  ]

--
-- Funcion encriptar que reciba como argumento de entrada una cadena
-- y nos devuelva otra cadena pero con los valores corridos 3 posiciones
-- "ABC" -> "DEF"
-- Utilizar list comprehension
encriptar :: String -> String
encriptar cadena = [ toEnum ((fromEnum c) + 3) :: Char | c <- cadena ]

