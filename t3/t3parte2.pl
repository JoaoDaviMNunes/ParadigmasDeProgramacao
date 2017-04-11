% 1o exercício
somaQuad(X, Y, Q) :- Q is X*X + Y*Y.

% 2o exercício
zeroInit(L) :- nth0(0, L, X), X =:= 0.

% 3o exercício
hasEqHeads(L1, L2) :- nth0(0, L1, X), nth0(0, L2, Y), X =:= Y.

% 4o exercício
has5(L) :- last(L, X), nth0(4, L, X).

% 5o exercício
hasN(L, N) :- length(L, N).

% 6o exercício
isBin([0]).
isBin([1]).
isBin(L):- L = [H|T], member(H, [0,1]), isBin(T).

% 7o exercício
mesmaPosicao(A, L1, L2) :- nth0(X, L1, A), nth0(Y, L2, A), X =:= Y.

% 8o exercício
repete5(E, L) :- L = [E,E,E,E,E].

% 9o exercício
sumQuads([],0).
sumQuads(L, S) :- L=[H|T], K is H*H, sumQuads(T, S1), S is K+S1.

% 11o exercício
mapop([], []).
mapop(L1,L2) :- L1 = [H|T], K is 2*H+1, mapop(T,X), L2 = [K|X].

% 12o exercício
positivos([],[]).
positivos(L1, L2) :- 
		L1 = [H|T], H > 0, positivos(T, C), L2 = [H|C].
positivos(L1, L2) :-
		L1 = [H|T], H =< 0, positivos(T, L2).
