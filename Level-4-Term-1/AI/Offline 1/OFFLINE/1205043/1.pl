sum([],0).
sum([H|T],R):-sum(T,R1), R is R1+H.
