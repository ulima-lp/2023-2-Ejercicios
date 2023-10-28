%hechos
hombre('Eduardo').
hombre('Juan').
hombre('Pedro').
hombre('Cesar').
hombre('Josue').

mujer('Maria').
mujer('Rocio').

es_padre('Eduardo', 'Juan').
es_padre('Juan', 'Pedro').
es_padre('Juan', 'Cesar').
es_padre('Juan', 'Maria').
es_padre('Cesar', 'Josue').
es_padre('Maria', 'Rocio').

%Reglas
es_abuelo(X,Y):-
    es_padre(X, A),
    es_padre(A,Y).

es_hermano(X,Y):-
    es_padre(A,X),
    es_padre(A,Y),
    X\= Y.

es_madre(X,Y):-
    es_padre(X,Y),
    mujer(X).

es_tio(X,Y):-
    es_padre(A,Y),
    es_hermano(A,X),
    hombre(X).

es_tia(X,Y):-
    es_padre(A,Y),
    es_hermano(A,X),
    mujer(X).

es_primo(X,Y):-
    es_padre(A,X),
    es_padre(B,Y),
    es_hermano(A,B).
