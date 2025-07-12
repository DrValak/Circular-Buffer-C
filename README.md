# Circular Buffer in C

This project implements a **Circular Buffer (Ring Buffer)** in C, demonstrating core data structure operations such as insertion, removal, and displaying buffer contents.  
It is designed to help you understand how circular buffers work, how to manage buffer overflow and underflow, and how to perform basic operations efficiently.

## Features

- **Fixed-size buffer (size 10)**
- **Insert data** into the buffer
- **Remove data** from the buffer
- **Display current buffer contents**
- **Overflow and underflow protection**
- Simple, easy-to-understand code structure

## How It Works

A circular buffer uses a fixed-size array and two indices:  
- `head`: points to the oldest element (for removal)
- `tail`: points to the next position for insertion
- `full`: flag indicating if the buffer is full

When inserting or removing data, the indices are managed so the buffer "wraps around" the array, making it efficient for streaming applications or producer-consumer problems.

### Main Operations

- **Insert (`insertData`)**:  
  Adds a value at the `tail` position. If the buffer is full, insertion is refused.

- **Remove (`removeData`)**:  
  Removes the value at the `head` position. If the buffer is empty, removal is refused.

- **Show (`showData`)**:  
  Prints all valid values currently stored in the buffer.

## Usage

### Compile

```sh
gcc circular_buffer.c -o circular_buffer
```

### Run

```sh
./circular_buffer
```

### Sample Interaction

```
Inserting values from 1 to 9.
Showing data from buffer
1
2
3
4
5
6
7
8
9
Testing remove function.
How many elements do you want to remove? 3
Removed: 1
Removed: 2
Removed: 3
4
5
6
7
8
9
Testing insert function.
Buffer is full!
Buffer is full!
Buffer is full!
4
5
6
7
8
9
```

## Code Structure

- **CircularBuffer struct**:  
  Holds the buffer array and control variables.

- **startBuffer**:  
  Initializes the buffer.

- **insertData**:  
  Inserts data; checks for overflow.

- **removeData**:  
  Removes data; checks for underflow.

- **showData**:  
  Displays all valid data.

- **main**:  
  Interactive console program to demonstrate buffer usage.

## Customization

- You can change the buffer size by modifying the array size and updating logic where `10` appears.
- You can add more interactive features for advanced buffer management.

## Applications

Circular buffers are widely used in:
- Audio/video streaming
- Embedded systems
- Producer-consumer scenarios
- Data logging

## License

This project is provided for academic and learning purposes.
