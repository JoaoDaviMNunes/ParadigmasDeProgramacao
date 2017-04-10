% 1o exercício
somaQuad(X, Y, Q) :- Q is X*X + Y*Y.

% 2o exercício
zeroInit(L) :- nth0(0, L, X), X =:= 0.

% 3o exercício
hasEqHeads(L1, L2) :- nth0(0, L1, X), nth0(0, L2, Y), X =:= Y.

% 5o exercício
hasN(L, N) :- length(L, N).

% 7o exercício
mesmaPosicao(A, L1, L2) :- nth0(X, L1, A), nth0(Y, L2, A), X =:= Y.
