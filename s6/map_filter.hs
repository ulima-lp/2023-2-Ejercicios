import Data.String

-- [1 , 2 , 3] =====>  [1, 4, 9]
cuadradoLista :: [Int] -> [Int]
cuadradoLista lista = 
    map (\num -> num * num) lista

-- Se tiene una lista de números en forma de Strings. ["1", "2", ...]
-- Implementar una función que nos permita convertir estos 
-- números a enteros. Utilizar map
-- ["1", "2"] => [1, 2]
convertirString :: [String] -> [Int]
convertirString listaStrings = 
    map (\numString -> 
            (fromEnum 
                (head numString) ) - (fromEnum '0')
        ) listaStrings

listaAlumnos :: [[Float]] = [ [11, 14], [10, 11], [18, 19], [4, 9] ]
-- Implementar una funcion que calcule el promedio de notas de TODO el salon.
-- Utilizar map
promedioNotas :: [[Float]] -> Float
promedioNotas listaNotas = 
    (sum (map (\notas -> (sum notas) / 2) listaNotas)) 
        / (fromIntegral (length listaNotas))

    
listaNumeros :: [Int] = [1, 4, -3, 2]
devolverListaPositivos :: [Int] -> [Int]
devolverListaPositivos listaNumeros =
    filter (\num -> (num > 0)) listaNumeros

-- Implementar una funcion que calcule la cantidad de alumnos aprobados
-- del salon.
cantidadAprobados listaNotas =
    length(
        filter (\num -> (num >= 10.5)) 
                (map (\notas -> (sum notas)/ (fromIntegral(length notas))) 
                listaNotas))



persona = ("Juler", 25, 1.69, True)
(nombre, edad, estatura, egresado) = persona

-- Implementar una función que me devuelva el alumno (nombre)
-- que tuvo la mayor nota promedio de todo el salón.
listaNotasAlumnos :: [(String, Float, Float)] = [
    ("Juan", 11, 14),
    ("Pedro", 10, 10),
    ("Leo", 18, 19),
    ("Juler", 20 ,20)]

obtenerAlumnoMayorTail :: [(String, Float)] -> (String, Float) -> (String, Float)
obtenerAlumnoMayorTail listaPromedios mayor=
    if null listaPromedios
        then mayor
        else obtenerAlumnoMayorTail (tail listaPromedios)
                                    (if ((snd (head listaPromedios)) > (snd mayor))
                                        then (head listaPromedios)
                                        else mayor)

mayorNotaAlumno :: [(String, Float, Float)] -> String
mayorNotaAlumno listaNotas =
    fst (obtenerAlumnoMayorTail (map (\(nombre, nota1, nota2) -> (nombre , ((nota1 + nota2) / 2) ) ) 
        listaNotas)
        (head (map (\(nombre, nota1, nota2) -> (nombre , ((nota1 + nota2) / 2) ) ) 
        listaNotas)))

third :: (String, Float, Float) -> Float
third (nombre, nota1, nota2) = nota2

-- Implementar una funcion que me devuelva un elemento de una posicion pos de una tupla
obtenerElemento :: (String, Float, Float, Float) -> Int -> String
obtenerElemento (nombre, nota1, nota2, nota3) 0 = nombre 
obtenerElemento (nombre, nota1, nota2, nota3) 1 = (show nota1 )
obtenerElemento (nombre, nota1, nota2, nota3) 2 = (show nota2)
obtenerElemento (nombre, nota1, nota2, nota3) 3 = (show nota3)



 