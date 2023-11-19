# Estruturas existentes:
- Array
- Lista
- Lista Linkada (linked list)
- Array Dinamico


- Pilha (FIFO)
  - Pilha din�mica?
- Fila (FILO)
  - Fila din�mica?

- Grafo (graph)
- Árvore (tree) 
 
## Funcoes que lineares devem ter:
- getAtIndex
- getFirst
- getLast
- loopAll
 
## Funcoes que não lineares devem ter
- findByValue


# Objetivos:
1. criar funcao para instanciar uma lista de referencia de objetos
2. criar um objeto do tipo "

# Funcoes para criar
1. funcao recebe um ponteiro como referencia para qual objeto tratar

# Notas:
- Endereço de memorias são calculados em bytes
- Cada tipo possui um tamanho especificado.
  - int = 4 bytes
  - char = 1 byte (?)
  - bool = 1 bit (?)
- Endere�os podem ser descobertos fazendo aritmetica basica:
  1. Endere�o em X = int;
  2. Proximo endere�o ser� X + sizeof(type)
  3. E.g: 
    0x0ff0d10 + sizeof(int)
    0x0ff0d10 + 4
    0x0ff0d14
- Tipos "compostos" funcionam da mesma forma, porém: Como são alocados??

E.g:
```
    Tree { int id; char name[10]; Tree pChildren[5] }
    [int][int][int][int][char][char][char][char][char][char][char][char][char][char][Tree][Tree][Tree][Tree][Tree]
```

# Análise: Array Din�mico

Arrays tem tamanho fixo quando criados

Arrays são nada mais nada menos que aritm�tica de ponteiro simplificada --> Endere�o + sizeof(type);

Array[0] é o primeiro elemento. Subsequentes adiciona-se na aritm�tica.

Para aumentar array:
- Endere�os de mem�ria seguintes n�o est�o ocupados.
    E.g:
        [int][int][int][int][][][][][][][][][][other][other][other][other]
    O que fazer?
        1. Checar se sizeof(type) pode ser inserido totalmente em todos os endere�os seguintes
            Se sim: alocar normalmente a mem�ria
            E.g: 
                    [int][int][int][int][][][][][][][][][][other][other][other][other]                
                    [int][int][int][int][X][X][X][X][][][][][][other][other][other][other]
                    
                    Sucess
                    End

- Endere�os seguintes est�o ocupados.
    E.g: 
        [int][int][int][int][][][][other][other][other][other][][]

    O que fazer?
        Receber sizeof() do endere�o que impede inserir, verificar se no endere�o ap�s sua mem�ria ocupada (na ponta final) � poss�vel inserir;
                -> Se sim: alocar nosso tipo na mem�ria e adicionar no final um ponteiro que retorna para nosso array (isso gerar� array fragmentado, semelhante a linked list, mas o penultimo elemento n�o tem referencia do ultimo...
                    E.g: 
                                                        \/ Error                                                        
                            [int][int][int][int][X][X][X][other][other][other][other][][] ERRO !
                            pOther = 0x001d;
                            sizeof(other) = 4;

                            pAddressAttempt = 0x001d + 4;
                            pAddressAttempt = 0x0022;
                                                                                    \/ attempt
                            [int][int][int][int][][][][other][other][other][other][0x0022][0x0023][...][][]
                            [int][int][int][int][][][][other][other][other][other][X][X][X][X][]
                            Sucesso

                -> Se n�o: repetir instru��o at� encontrar espa�o livre.
                    E.g:
                                            \/ Attempt
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][][][][]
                                                    \/ Error
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][][][][]
                        sizeof(other) = 4;
                                                                                \/ Attempt
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][][][][]
                                                                                    \/ Error
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][][][][]
                        sizeoOf(sysFlag) = 2;
                                                                                                    \/ Attempt
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][][][][]
                        sizeoOf(sysFlag) = 2;
                                                                                                            \/ Error
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][][][][]
                        sizeoOf(sysFlag) = 2;
                                                                                                                            \/ Attempt
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][][][][]
                                                                                                                            \/ Sucess
                        [int][int][int][int][][][][other][other][other][other][][][sysFlag][sysFlag][][][sysFlag][SysFlag][X][X][X][X][oriArr]
                    
                        End

# No geral
- A instancia��o de arrays din�micos � diferente de arrays comuns: ser�o linked lists ou double linked lists(?)
- A instancia��o de arrays din�micos pode ocorrrer como arrays comuns. Por�m, fun��es de adicionar e remover elementos precisam adicionar sistema de [double] linked list?
    E.g: 
        type X --> sizeof() = 3;
        [X1][X1][X1][X2][X2][X2][][][other][other][bool][][][]
        
- Dois �ltimos endere�os de cada elemento � um endere�o para o anterior e o seguinte, respectivamente (?)
    E.g:
        type X --> sizeof() = 2;

        [X1][X1][X2][X2][pNext][][other][other][][][][][]

        X.addEntry()     
                                                            \/ Added
        [X1][X1][X2][X2][pNext][][][other][other][X3][X3][pPrev][][other2][other2][][][]

        X.addEntry()
                                                                    \/ Added                         \/ Added
        [X1][X1][X2][X2][pNext][][][other][other][X3][X3][pPrev][pNext][other2][other2][X4][X4][pPrev]
- O primeiro endere�o refere ao endere�o do elemento anterior, e o �ltimo endere�o refere ao elemento seguinte se houver (?)
    E.g:

        [X1][X1][X2][X2][pNext][][][other][other][X3][X3][pPrev][pNext][other2][other2][X4][X4][pPrev]

# Notas 2
- Se quisermos um array dinamico unidirecional, apenas uma refer�ncia para frente � necess�rio, assim um overhead de 1 byte com um ponteiro deve ser reservado para INSTANCIAR e para ADICIONAR/REMOVER
- Se quisermos um array dinamico bidirecional, duas referencias s�o necessarias: anterior e pr�ximo. O overhead � de 2 bytes com ponteiros que devem 
/
