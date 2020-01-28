%sad(X) :- \+ happy(X).

sad(X) :- \+ beautiful(X), rich(X).
sad(X) :- beautiful(X), \+ rich(X).
sad(X) :- \+ beautiful(X), \+ rich(X).


sad(X) :- \+ rich(X), beautiful(X).
sad(X) :- rich(X), \+ beautiful(X).
sad(X) :- \+ rich(X), \+ beautiful(X).


happy(X) :- beautiful(X), rich(X).
rich(bill).
rich(michael).
beautiful(michael).
beautiful(cinderella).

