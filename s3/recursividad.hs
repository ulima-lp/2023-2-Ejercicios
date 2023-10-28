notasSalon :: [[Float]]
notasSalon = [
    [10, 11, 12, 15 ,10],
    [20, 11, 13, 11 ,4],
    [15, 7, 11, 17 ,12]]

-- Implementar una funcion llamada promediarNotas que reciba una lista de notas
-- y calcule las notas promedio (devuelva lista de notas promedio)
promediarNotasAlumnoTail :: [Float] -> Float -> Float -> Float
promediarNotasAlumnoTail notas sumaParcial contador =
    if null notas
        then sumaParcial / contador
        else promediarNotasAlumnoTail
                (tail notas)
                ((head notas) + sumaParcial)
                (contador + 1)

promediarNotasTail :: [[Float]] -> [Float] -> [Float]
promediarNotasTail notas listaParcial =
    if null notas
        -- caso base
        then listaParcial 
        -- caso recursivo
        else promediarNotasTail 
                (tail notas) 
                (concat [ listaParcial , [ ( promediarNotasAlumnoTail (head notas) 0 0 ) ] ])


promediarNotas :: [[Float]] -> [Float]
promediarNotas notas =
    promediarNotasTail notas []

-- Implementar una funcion llamada crearLista que reciba un numero entero positivo
-- y que devuelva una lista de numeros comenzando en cero hasta ese numero
-- crearLista 5 => [0, 1, 2, 3, 4]
crearListaTail :: Int -> [Int] -> [Int]
crearListaTail tam listaParcial =
    if tam == 0
        then listaParcial
        --else crearListaTail (tam - 1) ( (tam - 1) : listaParcial )
        else crearListaTail (tam - 1) ( concat [ [(tam - 1)] , listaParcial ] )

crearLista :: Int -> [Int]
crearLista tam = crearListaTail tam []

-- Implementar una funcion llamada reversa que reciba una lista y devuelva una lista en
-- reversa.
-- [1,2,3,4] => [4,3,2,1]
reversaTail :: [Int] -> [Int] -> [Int]
reversaTail lista listaParcial =
    if null lista
        then listaParcial
        else reversaTail 
                (tail lista)
                (concat [ [(head lista)], listaParcial ])

reversa :: [Int] -> [Int]
reversa lista = reversaTail lista []