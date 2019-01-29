/*
 * ringbuffer.h 
 * 
 * API for using a ring buffer for the purpose of buffering 
 * asynchronous serial I/O.
 */

#define BUF_SIZE 50

typedef struct {
	unsigned int put;
	unsigned int get;
	char buffer[BUF_SIZE]; 
} RingBuffer;

// Adds element to buffer.  Will block if there is no space in buffer.
void put(RingBuffer* buffer, char element);

// Gets element from buffer.  Will block if buffer is empty.
char get(RingBuffer* buffer);

// Returns true (non-zero) if there is room for one element in buffer
int hasSpace(RingBuffer *);

// Return true (non-zero) if there is at least one element in buffer
int hasElement(RingBuffer *);