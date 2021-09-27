/* Explique qué es lo que hace el siguiente código ((n & (n-1)) == 0)

Nos ayuda a verificar si es una potencia de 2 o 0
la potecias de 0 tienen cierto patron
  
 0   0000   
 
 2   0010   
 
 4   0100   
 
 8   1000   
 
 si a 4 le restemos su antecesor nos quedaria

 0100 & 0011 = 0000

 lo mismo sucede para 8

 1000 % 0111 = 0000

 
*/
