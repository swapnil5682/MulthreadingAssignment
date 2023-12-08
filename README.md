# Multithreaded Data Processing Application

This C++ application demonstrates a multithreaded program that reads data from multiple files concurrently, processes the data, and ensures proper synchronization using mutexes.

## How to Compile and Run

### Prerequisites
- Make sure you have a C++ compiler installed on your system (e.g., g++).

### Compilation
1. Open a terminal.
2. Navigate to the directory containing the source code file (`multithreadedExample.cpp`).
3. Compile the code using the following command:

   	```bash
   	g++ -std=c++11 -pthread multithreadedExample.cpp -o multithreadedExample

### Execution

Run the compiled executable:

	```bash
	./multithreadedExample



# Design Choices

## Multithreading
The program utilizes the `<thread>` and `<mutex>` headers to implement multithreading. The `thread` class is used to create threads, and a `mutex` is employed for synchronization.

## Data Processing
The `processData` function simulates data processing from a file. Each thread processes data independently, and a mutex ensures that the output to `cout` is synchronized to avoid race conditions.

## User Input
The program prompts the user to input the number of files and the filenames. It dynamically allocates threads based on the number of files provided.

## Error Handling
The code incorporates proper error handling for file opening failures. If a file cannot be opened, an error message is displayed.

## Performance Considerations
The code aims for simplicity and readability. For more complex applications, additional optimizations and error-handling mechanisms may be required.
