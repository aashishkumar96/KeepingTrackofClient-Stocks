//Aashish Kumar and Wilder Emanuel Garcia
#include "stock.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct stock_type {
  char stock_symbol[30];
  char stock_price[30];
};


// returns the pointer to the list; NULL if list not created
Stock createStock() {
  // allocate memory for a structure variable containing all
  // list components
  Stock stockptr = malloc(sizeof(struct stock_type));
  // if allocation was succesfull
  if (stockptr != NULL) {
     stockptr->stock_symbol;
     stockptr->stock_price;
  }
  return stockptr;
}

int getStockSize(){
    return sizeof(struct stock_type);
}

char* getStockSymbol(Stock stockptr){
    return stockptr->stock_symbol;
}

void setStockSymbol(Stock stockptr, char *data){
    strcpy(stockptr->stock_symbol, data);
}
char* getStockPrice(Stock stockptr){
    return stockptr->stock_price;
}

void setStockPrice(Stock stockptr, char *data){
    strcpy(stockptr->stock_price, data);
}

void destroyStock(Stock stockptr) {
    free(stockptr);
    stockptr = NULL;
}
