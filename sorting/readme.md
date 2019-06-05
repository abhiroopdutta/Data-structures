Comparing sorting algorithms based on - 
1. Time Complexity
2. Space complexity
3. Stability - A sorting algorithm is said to be stable if two objects with equal keys
appear in the same order in sorted output as they appear in the input unsorted array. 
4. Internal, external sort - In internal sorting all the data to sort is stored in memory at all times
while sorting is in progress.
In external sorting data is stored outside memory (like on disk) and only loaded into memory in small chunks.
External sorting is usually applied in cases when data can't fit into memory entirely.
So in internal sorting you can do something like shell sort - just access whatever array elements you want at whatever
moment you want. 
You can't do that in external sorting - the array is not entirely in memory, so you can't just randomly access any element in memory and accessing it randomly on disk is usually extremely slow.
The external sorting algorithm has to deal with loading and unloading chunks of data in optimal manner.


