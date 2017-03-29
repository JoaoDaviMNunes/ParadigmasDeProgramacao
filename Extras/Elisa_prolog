### 1a parte do código em que irei analizar: ###

-> Código

rules([[remember,5],[
	[1,[_,you,remember,Y],0,
		[do,you,often,think,of,Y,?],
		[does,thinking,of,Y,bring,anything,else,to,mind,?],
		[what,else,do,you,remember,?],
		[why,do,you,remember,Y,just,now,?],
		[what,in,the,present,situation,reminds,you,of,Y,?],
		[what,is,the,connection,between,me,and,Y,?]],
	[2,[_,do,i,remember,Y],0,
		[did,you,think,'I',would,forget,Y,?],
		[why,do,you,think,i,should,recall,Y,now,?],
		[what,about,Y,?],
		[equal,[what,0]],
		[you,mentioned,Y,.]],
	[3,[_],0,
		[newkey]]]]).

-> Explicação

rules([[palavra-chave, importância da palavra-chave], [
  [padrão #, [o padrão], última resposta utilizada,
    [resposta 1],
    [resposta 2],
    ...
    [respota n]]]]).
    
Através da palavra-chave e de sua importância, o programa pode obter uma reação ao usuário quando ele lhe enviar uma resposta.

#############################################################################################################

### 2a parte do código em que irei analizar: ###

-> Código

last_member(End,List) :- append(_,[End],List).

-> Explicação

Recebe a posição final e a lista. Retorna o último elemento da lista.

#############################################################################################################

Em ambos os trechos de código, podemos perceber, através do que é informado no chat pelo usuário, o programa encontra uma palavra-chave,
dado com certo grau de importância, e obtém uma resposta adequada ao caso. Ele fornece mais de uma resposta para cada informação recebida.
