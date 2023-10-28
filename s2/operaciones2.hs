cuadrado :: Float -> Float
cuadrado num = num * num

distancia :: Float -> Float -> Float -> Float -> Float
distancia x1 y1 x2 y2 =
    sqrt (
        cuadrado (x2 - x1) 
        + 
        cuadrado (y2 - y1)
    )

listaNumeros :: [Float] = [1, 3, 5,7, 9]

longitud :: [Float] -> Float
longitud lista =
    if null lista
        then 0-- caso base
        else (longitud (tail lista) + 1) -- caso recursivo

-- Implementar una funcion que sume los elemenos de una lista
-- sumarLista tiene que recibir como argumento de entrada una lista
sumarLista :: [Float] -> Float
sumarLista lista =
    if null lista
        then 0
        else (sumarLista (tail lista)) 
             + 
             (head lista)

-- Implementar una funcion pos que devuelva un elemento de la lista de una posicion determinada
pos :: [Int] -> Int -> Int
pos lista posicion =
    if posicion == 0
        then head lista
        else pos (tail lista) (posicion - 1)

-- Implementar una funcion llamada promediar que calcule el promedio de una lista de numeros Float
promediar :: [Float] -> Float
promediar lista =
    (sumarLista lista) / (longitud lista)

-- Implementar una funcion llamada mayor que devuelva el elemento mayor de una lista de numeros
mayor :: [Int] -> Int -> Int
mayor lista numMayor =
    if null lista
        then numMayor
        else mayor 
                (tail lista) 
                (if (head lista) > numMayor
                    then (head lista)
                    else numMayor)




