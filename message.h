#ifndef MESSAGE_H
#define MESSAGE_H

typedef struct{
  // Total length of the message
  unsigned int length;

  // From where in the receive key should we start?
  unsigned int key_index;
} message_header;

#endif MESSAGE_H
