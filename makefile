//Aashish Kumar and Wilder Emanuel Garcia
pr4.out: pr4.o listADTgen.o listclient.o stock.o 
	gcc	-std=gnu90 -g -o pr4.out pr4.o listADTgen.o listclient.o stock.o 

pr4.o: pr4.c listADTgen.h listclient.h stock.h
	gcc -std=gnu90 -g -c -Wall pr4.c 
	
listADTgen.o: listADTgen.c listADTgen.h
	gcc -std=gnu90 -g -c -Wall listADTgen.c

listclient.o: listclient.c listclient.h
	gcc -std=gnu90 -g -c -Wall listclient.c
	
stock.o: stock.c stock.h
	gcc -std=gnu90 -g -c -Wall stock.c





