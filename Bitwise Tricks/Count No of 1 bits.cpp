//TC = O(no of set(1) bits)
unsigned int countSetBits(int n)
{
	int count = 0;
	//Count no of 1 bits
	while (n)
	{
		++count;
		//Discards last bit
		n = (n & (n - 1));
	}
	return count;
}


//Another way - but less optimized - but more easy to think

//TC = O(no of total bits)
unsigned int countSetBits(unsigned int n)
{
	//Right shift and check if digit is 1
	unsigned int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}
