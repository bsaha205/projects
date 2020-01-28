reverse(X,Z):-testreverse(X,Z,[]).
testreverse([],Z,Z).

testreverse([H|T],Z,Acc) :- testreverse(T,Z,[H|Acc]).