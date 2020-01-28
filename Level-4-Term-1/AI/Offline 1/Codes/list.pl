%Finding Member
member(X,[X|T]).
member(X,[H|T]) :- member(X,T).


%length

len([],0).
len([_|T],N) :- len(T,X), N is X+1.



%Last Element Finding
my_last(X,[X]).
my_last(X,[_|L]) :- my_last(X,L).



%SecondLast Element Finding

second_last_conventional(X,[X,_]).
second_last_conventional(X,[Y|Ys]) :- second_last_conventional(X,Ys).


%Finding the k-th element
element_at(X,[X|_],1).
element_at(X,[_|L],K) :- K > 1, K1 is K - 1, element_at(X,L,K1).


%duplicating each element:
% input : duplicate([a,b,b,d],X)   -> X = [a,a,b,b,b,b,d,d]

duplicate([],[]).
duplicate([X|Xs],[X,X|Ys]) :- duplicate(Xs,Ys).

duplicate1([],[]).
duplicate1([H|T],[H,H|Y]):-duplicate1(T,Y).

element_k(X,[X|_],1).
element_k(X,[_|T],K):-K>1,K1 is K-1,element_k(X,T,K1).

second_last1(X,[X,_]).
second_last1(X,[_|T]):-second_last1(X,T).


cat([],[],[]).
cat(X,[],X).
cat([],Y,Y).
cat([H|T],Y,[H|Z]):-cat(T,Y,Z).
