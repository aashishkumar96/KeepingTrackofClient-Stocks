//Aashish Kumar and Wilder Emanuel Garcia
#include "listclient.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct client_type {
  int client_id;
  char client_name[30];
  char client_number[20];
  char client_email[60];
};


// returns the pointer to the list; NULL if list not created
Client createClient() {
  Client listptr = malloc(sizeof(struct client_type));
  // if allocation was succesfull
  if (listptr != NULL) {
     listptr->client_id = 0;
     listptr->client_name;
     listptr->client_number;
     listptr->client_email;
  }
  return listptr;
}

int getClientSize(){
	return sizeof(struct client_type);
}

int getClientId(Client listptr) {
    return listptr->client_id;
}

void setClientId(Client listptr, int data){
    listptr->client_id = data;
}
char* getClientName(Client listptr){
    return listptr->client_name;
}

void setClientName(Client listptr, char *data){
    strcpy(listptr->client_name, data);
}
char* getClientNumber(Client listptr){
    return listptr->client_number;
}

void setClientNumber(Client listptr, char *data){
    strcpy(listptr->client_number, data);
}
char* getClientEmail(Client listptr){
    return listptr->client_email;
}

void setClientEmail(Client listptr, char *data){
    strcpy(listptr->client_email, data);
}
void destroyClient(Client listptr) {
    free(listptr);
    listptr = NULL;
}


