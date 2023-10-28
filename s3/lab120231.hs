-- Pregunta 1
convertirAListaTail :: String -> [Int] -> [Int]
convertirAListaTail numTarjeta listaParcial =
    if null numTarjeta
        then listaParcial
        else convertirAListaTail 
                (tail numTarjeta)
                ( concat [  
                    listaParcial,
                    [( read [(head numTarjeta)] :: Int)] ])


convertirALista :: String -> [Int]
convertirALista numTarjeta = convertirAListaTail numTarjeta []

-- Pregunta 2
esPar :: Int -> Bool
esPar num = (mod num 2) == 0

