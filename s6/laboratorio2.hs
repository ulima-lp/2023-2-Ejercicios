import Data.List
import Games

convertStringToNumber :: String -> Float
convertStringToNumber cadena =
    if ((last cadena) == 'K')
        then (read (init cadena) :: Float) * 1000
        else read cadena :: Float

pregunta1 :: [RegistroVideojuego] -> String -> Float
pregunta1 listaVideojuegos genero =
    sum (map (\(_,_,_,_,_,_,_,_,_,_,cantidad,_,_,_) -> (convertStringToNumber cantidad) ) 
        (filter (\(_,_,_,_,_,_,_,generos,_,_,_,_,_,_) -> (isInfixOf genero generos)) 
            listaVideojuegos))