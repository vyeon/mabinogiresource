#pragma once

#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */



class CMersenneTwister
{
public:

	CMersenneTwister(void);
	~CMersenneTwister(void);

	/* initializes mt[N] with a seed */
	void init_genrand(unsigned long s);

	/* generates a random number on [0,0xffffffff]-interval */
	unsigned long genrand_int32(void);

private:
	unsigned long mt[N]; /* the array for the state vector  */
	int mti; /* mti==N+1 means mt[N] is not initialized */
};
