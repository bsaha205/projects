  move(1,X,_,Z) :-  
        write('Move disk from '), 
        write(X), 
        write(' to '), 
        write(Z), 
        nl. 
    move(N,X,Y,Z) :- 
        N>1, 
        M is N-1, 
        move(M,X,Z,Y), 
        move(1,X,_,Z), 
        move(M,Y,X,Z).