#ifndef STOCK_H
#define STOCK_H

typedef struct stock_type *Stock;


char* getStockSymbol(Stock);
void setStockSymbol(Stock, char *);
char* getStockPrice(Stock);
void setStockPrice(Stock, char *);

Stock createStock();
void destroyStock(Stock);
int getStockSize();
#endif



