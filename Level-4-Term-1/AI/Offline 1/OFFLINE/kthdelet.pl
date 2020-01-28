delete(X,K,Y):-testdelete(X,1,K,Y).
testdelete([],_,_,[]).
testdelete([H|T],P,K,[H|Y]):-0 =\= mod(P,K),P1 is P+1,testdelete(T,P1,K,Y). 
testdelete([H|T],P,K,Y):-0 =:= mod(P,K),P1 is P+1,testdelete(T,P1,K,Y). 