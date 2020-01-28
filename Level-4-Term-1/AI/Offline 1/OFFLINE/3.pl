findmax([H],M):-M = H. 
findmax([H|T],R):-findmax(T,R1),R1@>H,R = R1.
findmax([H|T],R):-findmax(T,R1),R1@<H,R = H.