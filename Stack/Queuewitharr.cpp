void MyQueue::push(int x) {
    if (rear < 100005) { // Ensure the queue doesn't overflow
        arr[rear++] = x; // Add the element and move `rear` to the next position
    }
}

// Function to pop an element from the queue and return it.
int MyQueue::pop() {
    if (front == rear) { // Check if the queue is empty
        return -1;
    }
    return arr[front++]; // Return the front element and move `front` forward
}