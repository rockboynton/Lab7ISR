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

static volatile RingBuffer sendBuffer = {0,0,BUF_SIZE};

void put(RingBuffer* buffer, char element) {
    while (!hasSpace(buffer)) {
    }
    buffer->buffer[buffer->put] = element;
    buffer->put++;
    // check if wrap needed
    if (buffer->put >= buffer->size) {
        buffer->put = 0; // wrap back to 0
    }
}

char get(RingBuffer* buffer) {
    while (!hasElement(buffer)) {
    }
    char element = buffer->buffer[buffer->get];
    if (get >= buffer->size) {
        buffer->get = 0;
    }
    buffer->get++;
    return element;
}

int hasSpace(RingBuffer * buffer) { 

}

int hasElement(RingBuffer * buffer) {

}