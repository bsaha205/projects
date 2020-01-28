location(tokyo, 35, -139).
location(rome, 41, -12).
location(london, 51, 0).
location(canberra, -31, -149).
location(madrid, 48, 3).
%  north latitudes and west longitudes are positive.
north_of(X, Y) :-
        location(X, Lat1, _),
        location(Y, Lat2, _),
        Lat1 > Lat2.
%south latitudes and east longitudes are negative.
west_of(X, Y) :-
        location(X, _, Long1),
        location(Y, _, Long2),
        Long1 > Long2.
south_of(X,Y):-
	location(X,Lat1,_),
	location(Y,Lat2,_),
	Lat1<Lat2.