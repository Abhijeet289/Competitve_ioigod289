````
# Number of different XOR's between two binary strings
	- If we XOR two numbers and we have 'k' set bits in output, we can move those 'k' set bits anywhere.
	- The parity of SET bits in output will be same i.e. if we have 'k' set bits then we cannot have 'k+1' set bits.
	- All we need to do is find the minimum and maximum set bits and iterate between them by += 2
````
