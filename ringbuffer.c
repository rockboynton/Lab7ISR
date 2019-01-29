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

static volatile RingBuffer sendBuffer = {0,0};

void put(RingBuffer* buffer, char element) {
    while (!hasSpace(buffer)) {
    }

}

char get(RingBuffer* buffer) {
    while (!hasElement(buffer)) {
    }
}

int hasSpace(RingBuffer * buffer) { 

}

int hasElement(RingBuffer * buffer) {

}