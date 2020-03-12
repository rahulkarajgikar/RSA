#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b)
{
	if(a==0)
		return b;
	gcd(b%a,a);
}

int main(int argc, char* argv[])
{
	//2 primes
	int a = 3;
	int b = 7;
	int msg = atoi(argv[1]);
	//get modulus n
	int n = a*b;

	//obtain totient(n)
	int totient = (a-1) * (b-1);

	//choose public key as relatively prime with totient(i.e gcd with totient = 1) from [3,totient(n))
	int e = 2;
	while(e<totient)
	{
		if(gcd(e,totient)==1)
			break;
		e++;
	}

	//NOW WE HAVE TO FIND INVERSE d SUCH THAT d*e = 1 mod (totient) ie d*e = k*totient + 1
	//therefore d = (1 + k*totient)/e where k is arbitrary
	//d is the private key
	int k = 2;//arbitrary
	int d;
	for(d=1;d<totient;d++)
	{
		if(((d*e)%totient)==1)
			break;
	}

	//now we have public key and private key, we must see if the message encryption, decryption works
	int c = (int)pow(msg,e) % n;	//Encryption
	int m = (int)pow(c,d) % n;	//Decrypting encrypted message

	printf("\n\nMessage data = %d",msg);
    printf("\np = %d",a);
    printf("\nq = %d",b);
    printf("\nn = pq = %d",n);
    printf("\ntotient = %d",totient);
    printf("\ne = %d",e);
    printf("\nd = %d",d);
    printf("\nEncrypted data = %d",c);
    printf("\nOriginal Message Sent = %d\n\n",m);
}