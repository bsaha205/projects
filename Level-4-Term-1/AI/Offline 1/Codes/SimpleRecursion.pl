printN(0).
printN(N):- N > 0, M is N - 1, printN(M),writeln(N).

%another program
sumN(0,0).
sumN(N,Sum) :-N >0,M is N -1,sumN(M, Temp),Sum is Temp + N.