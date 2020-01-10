#ifndef LISTCLIENT_H
#define LISTCLIENT_H

typedef struct client_type *Client;

int getClientSize();
int getClientId(Client);
void setClientId(Client, int);
char* getClientName(Client);
void setClientName(Client, char *);
char* getClientNumber(Client);
void setClientNumber(Client, char *);
char* getClientEmail(Client);
void setClientEmail(Client, char *);
Client createClient();
void destroyClient(Client);
#endif



