dupli(X,K,Y):-duplicate(X,K,K,Y).

duplicate([],_,_,[]).
duplicate([X|Xs],K,K2,[X|Ys]) :-K>1,K1 is K-1, duplicate([X|Xs],K1,K2,Ys).
duplicate([X|Xs],K,K2,[X|Ys]) :-K=:=1,duplicate(Xs,K2,K2,Ys).


reverse(X,Z):-testreverse(X,Z,[]).
testreverse([],Z,Z).
testreverse([H|T],Z,Acc) :- testreverse(T,Z,[H|Acc]).



twosComplement(X,W):-reverse(X,Z),twos(Z,0,Y),reverse(Y,W).
twos([],_,[]).
twos([H|T],P,[H|Y]):-P=\=1,H=\=1,twos(T,P,Y).
twos([H|T],P,[H|Y]):-P=\=1,H=:=1,twos(T,1,Y).
twos([H|T],P,[0|Y]):-P=:=1,H=:=1,twos(T,1,Y).
twos([H|T],P,[1|Y]):-P=:=1,H=:=0,twos(T,1,Y).






