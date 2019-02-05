/*
 * ringbuffer.c
 *
 *  Created on: Jan 28, 2019
 *      Author: Rock Boynton
 * 
 * Implements functions specified in ringbuffer.h to use a ring buffer for the purpose of buffering 
 * asynchronous serial I/O.
 */

#include "ringbuffer.h";

// Helper method
static unsigned int modulo_inc (const unsigned int value, const unsigned int modulus);

void put(RingBuffer* buffer, char element) {
    while (!hasSpace(buffer)) {
    }
    buffer->buffer[buffer->put] = element;
    // check if wrap needed
    if (buffer->put >= BUF_SIZE) {
        buffer->put = 0; // wrap back to 0
    } else {
        buffer->put++;
    }
    // modulo_inc(buffer->put, BUF_SIZE);
    buffer->used++;
}

char get(RingBuffer* buffer) {
    while (!hasElement(buffer)) {
    }
    char element = buffer->buffer[buffer->get];
    if (buffer->get >= BUF_SIZE) {
        buffer->get = 0;
    } else {
        buffer->get++;
    }
    // modulo_inc(buffer->get, BUF_SIZE);
    buffer->used--;
    return element;
}

int hasSpace(RingBuffer* buffer) { 
    return BUF_SIZE != buffer->used;
}

int hasElement(RingBuffer* buffer) {
    return buffer->used > 0;
}

static unsigned int modulo_inc (const unsigned int value, const unsigned int modulus) {
    unsigned int my_value = value + 1;
    if (my_value >= modulus) {
      my_value  = 0;
    }
    return (my_value);
    // return (value + 1) >= modulus ? 0 : value + 1; // ? Easier to read?
}
