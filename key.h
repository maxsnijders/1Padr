#ifndef KEYPAIR_H
#define KEYPAIR_H

typedef struct{
  // Total length of the keypair
  unsigned int total_length;

  // Length of the sending buffer
  unsigned int length_send;

  // Length of the receiving buffer
  unsigned int length_receive;

  // Where do we start sending from the next time?
  // in a message, the current receiving index is included
  unsigned int index_send;
} key_header;

#endif
