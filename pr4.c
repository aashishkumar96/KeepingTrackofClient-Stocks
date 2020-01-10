//Aashish Kumar and Wilder Emanuel Garcia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listADTgen.h"
#include "stock.h"
#include "listclient.h"


int compare(int*, int*);
int fpeek(FILE *stream);
int main(void) {
    
    
    FILE *infile = fopen("clients.txt", "r");
    FILE *outfile = fopen("summary.csv", "w");

    
    ListType clientList = create(getClientSize(), (void*) compare);
    ListType stockList = create(getStockSize(), (void*) compare);
    
    int clientid = 0;
    char clientname[30];
    char clientnumber[30];
    char clientemail[60];
    if(infile == NULL){
        puts("file doesn't exist");
        return -1;
    }

    
    Client client;
    while(fscanf(infile, "%d %[^\r] %s %s", &clientid, clientname, clientnumber, clientemail) != EOF) {
        client = createClient();
        setClientId(client, clientid);
        setClientName(client, clientname);
        setClientNumber(client, clientnumber);
        setClientEmail(client, clientemail);
	    //fprintf(outfile, "%d, %s, %s, %s\n", clientid, clientname, clientnumber, clientemail);
        push(clientList, client);
        //destroyClient(client);
          
             
    }
    
   FILE *infile2 = fopen("stocks.csv", "r");
    if(infile2 == NULL){
        puts("file doesn't exist");
        return -1;
    }
    
    char stocksymbol[20];
    char stockprice[30];
    char str[30];
    Stock stock;
    fgets(str, 50, infile2);
    while(!feof(infile2)) {
        if(fpeek(infile2)== EOF) {
            break;
        }
        stock = createStock();
        fgets(str, 50, infile2);
        sscanf(str, "%[^,], %[^,]", stocksymbol, stockprice);
        
        setStockSymbol(stock, stocksymbol);
        setStockPrice(stock, stockprice);
        
       // fprintf(outfile, "%s, %s\n", stocksymbol, stockprice);

        push(stockList, stock);
        //destroyStock(stock);
    }
    

    // printing everything in csv file
    int i = 0;     
    int id = 0;
    int stockCount = 0;
    int shares = 0;
    double totalPrice = 0.00;
    double price = 0.00;
    char line[20], symbol[20], tempID[20], tempStockCount[20], tempShares[20];
   
    FILE *infile3 = fopen("stock_client.txt", "r");
    if(infile3 == NULL){
        puts("file doesn't exist");
        return -1;
    }
  
    while (fgets(line, 20, infile3) != '\0' ) {
        sscanf(line, "%s %s", tempID, tempStockCount); 
        id = atoi(tempID); 
        stockCount = atoi(tempStockCount);
        for (i = 0; i < size_is(clientList); i++) {
            client = getValue(clientList, i); 
            clientid = getClientId(client);
            if (compare(&clientid, &id) == 0) {
                fprintf(outfile, "%d,%s", clientid, getClientName(client));
                fprintf(outfile, ",,%s,%s\n", getClientNumber(client), getClientEmail(client));

            }
        }
        for (i = 0; i < stockCount; i++) {
            fgets(line, 20, infile3);
            sscanf(line, "%s %s", symbol, tempShares);
            shares = atoi(tempShares);
            int j;
            for (j = 0; j < size_is(stockList); j++) {
                stock = getValue(stockList, j); 
                if (strcmp(getStockSymbol(stock), symbol) == 0) {
                    price = strtod(getStockPrice(stock), NULL);
                    fprintf(outfile, ",%s,%d,%g,\n", getStockSymbol(stock), shares, price);
                    totalPrice += (price * shares);
                                      
                }
                
            }
           
        }

        fprintf(outfile, " ,%.3lf,,,\n", totalPrice);       
        totalPrice = 0.00;
        
    }
	
    fclose(infile);
    fclose(infile2);
    fclose(infile3);
    fclose(outfile);
    
    return 0;
}



int fpeek(FILE *stream) {
    int s;
    s = fgetc(stream);
    ungetc(s,stream);
    
    return s;
}
int compare(int *a, int *b) {
    short int toReturn = 0;
    if(*a < *b) 
        toReturn= -1;
    else if (*a > *b) 
        toReturn = 1;
    return toReturn;
}
    
    
    
    


