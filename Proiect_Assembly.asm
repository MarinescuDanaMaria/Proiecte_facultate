; MARINESCU DANA MARIA  

; CERINTA : SA SE NUMERE CATI BITI DE 1 ARE FIECARE NUMAR SI SA SE AFISEZE .

.MODEL SMALL
.STACK 100H 

.DATA

NR DW 16,17,19           ; exemplu lista cu numere 
NR_NR EQU ( $ - NR )/2   ; lungimea listei
 
.CODE  

MAIN PROC 
    
    
    MOV AX,@DATA   ; pun numerele din segmentul de date in AX
    MOV DS,AX  
    
    MOV SI,0       ; stochez indexul din vector (al citelea octet este cel curent)
    MOV DI,[NR_NR] ; tin evidenta a cate numere mai am de parcurs
   
BITI_DE_1:  

    MOV DX,NR[SI]  ; pun in DX numarul de la offset-ul NR+SI
    MOV CX,8       ; numarul de biti totali ai numarului curent
    MOV AX,0       ; aici contorizez numarul de biti de 1 pentru numarul curent 
 
 TOP: 
    SHR DX,1       ; shiftez la stanga cu 1 pozitie si pun bitul cel mai semnificativ in carry
    JNC NEXT       ; daca nu exista carry , se face jump
    INC AX         ; altfel, daca exista carry, cresc contorul cu 1 
    
    
 NEXT:
    LOOP TOP       ; se repeta functia TOP de 8 ori, pentru fiecare numar , pentru a parcurge toti bitii
  
                   
                   ; printare rezultate
    
    MOV AH,2       ; pentru afisarea unui singur caracter 
    ADD AX,48 
    MOV DX, AX     ; afisez rezultatele pe rand  
    INT 21H  
            
    MOV DL,' '     ; pun spatiu
    INT 21H
    
    ADD SI,2       ; se pregateste urmatorul numar
    DEC DI         ; scade contorul 
    JNZ BITI_DE_1  ; cat timp nu am parcurs toate numerele, se trece la urmatorul
  
    
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP

END MAIN           ; se termina programul