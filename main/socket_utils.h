#include "lwip/sockets.h"
int send_all_as_chunks(int sock, void *buf, int buf_size, struct sockaddr_in dest_addr);
