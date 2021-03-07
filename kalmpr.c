// Author: Panagiotis Giovanos
//    SDI: 2000034
//Program: http://cgi.di.uoa.gr/~ip/iphw2021_1.pdf

/*library declaration*/
#include <stdio.h>    
#include <stdlib.h>
#include <time.h>
/*library declaration*/

/*constant variables declaration*/
#define MINNUM 2100000000                                                 /*Scope : Constant : declare MINNUM , where we define the starting point.                */
#define MAXNUM 2101000000                                                 /*Scope : Constant : declare MAXNUM , where we define the end.                           */
#define MAXK 4                                                            /*Scope : Constant : declare MAXK , where we define the maximum k-almost number.         */
#define COMPUTATIONS 20                                                   /*Scope : Constant : declare COMPUTATIONS , where we define the count of computations.   */
/*constant variables declaration*/

/*Begin of main*/
int main()
{	
    /*First Part of Assignment*/

	printf("Checking numbers in [%d,%d]\n\n",MINNUM,MAXNUM);              /*Scope : Program Output : print range of numbers that will be checked.                 */

	int c_primes = 0;                                                     /*Scope : Variable : declare c_primes , where we will keep the count of primes.         */
    int c_semiprimes = 0;                                                 /*Scope : Variable : declare c_semiprimes , where we will keep the count of semiprimes. */

	for (int k = MINNUM; k <= MAXNUM; k++)                                /*Scope :   loop   : while k<= MAXNUM with start point MINNUM and 1 step per time do :  */
	{
        int count = 0;                                                    /*Scope : Variable : declare count , where we will keep the count of k-almost number.   */
		int n = k;                                                        /*Scope : Variable : declare n , where we keep temporarily the variable k.              */
        int factor = 0;                                                   /*Scope : Variable : declare factor , where we will keep the factor of variable n.      */
       
        while (n % 2 == 0)                                                /*Scope :   loop   : while n is even divide it by 2 until it becomes odd.               */
        { 
            count = count + 1;                                            /*Scope : Variable : add to count , count k-almost.                                     */
            n = n / 2; 
        } 

        for (int i = 3; i*i <= n; i = i+2)                                /*Scope :   loop   : loop until the square of i <= n.                                   */
        { 
            while (n % i == 0)                                            /*Scope :   loop   : while the remainder of n / i is 0 , then do :                      */
            { 
                count = count + 1;                                        /*Scope : Variable : add to count , count k-almost.                                     */
                n = n / i;
                factor = n;                                               /*Scope : Variable : store to factor , store the current factor                         */
            } 
        } 
    
        if (n > 2)                                                        /*Scope : if statement : if n is prime > 2 then do :                                    */
        {
            count = count + 1;                                            /*Scope : Variable : add to count , count k-almost.                                     */
        }
        
        if(count >= 2 && count <= MAXK)                                   /*Scope : if statement : if count (k-almost) >= 2 and count (k-almost) <= MAXK then do :*/
        {
            c_primes = c_primes + 1;                                      /*Scope : Variable : add to c_primes , count primes in range (2 ≤ k ≤ MAXK).            */
        }

        if(count==2)                                                      /*Scope : if statement : if count (k-almost) = 2 then do :                              */
        {
            c_semiprimes++;                                               /*Scope : Variable : add to c_semiprimes , count semiprimes (2k-almost).                */
        }
        
        if(count == 2 && factor > 1 && factor * (k / factor) == k )       /*Scope : if statement : if count is semiprime and interesting then do :                */
        {
            int f1_temp = k / factor;                                     /*Scope : Variable : declare f1_temp , where we will keep temporarily the first factor. */
            int f1 = f1_temp;                                             /*Scope : Variable : declare f1 , where we will keep temporarily the first factor.      */
            int f2 = factor;                                              /*Scope : Variable : declare f2 , where we will keep temporarily the second factor.     */
            
            if(abs((f1 - f2) * 100) / f1 < 1)                             /*Scope : if statement : if the difference between the f1 and f2 is < 1% , then do :    */
            {
                printf("%d * %d = %d is an interesting semiprime\n",      /*Scope : Program Output : print the interesting semiprime number, the divisors and sum.*/
                    f1, f2, f1 * f2);
            }
        }
	}

    printf("\nFound %d k-almost prime numbers (2 <= k <= %d)\n",          /*Scope : Program Output : print the count of k-almost prime numbers.                   */
        c_primes,MAXK);
	printf("Found %d semiprimes\n\n",c_semiprimes);                       /*Scope : Program Output : print the count of semiprime numbers.                        */

    /*End of First Part of Assignment*/
    /*Second Part of Assignment*/

    long curtime;                                                         /*Scope : Variable : declare curtime , where we will keep the current time in seconds.  */
    curtime = time(NULL);                                                 /*Scope : Variable : store curtime , store the current time (in seconds since 1/1/1970).*/

    printf("Current time is %ld\n\n", curtime);                           /*Scope : Program Output : print the current time in seconds.                           */
    printf("Checking %d random numbers\n\n",COMPUTATIONS);                /*Scope : Program Output : print the count of random numbers that will be checked.      */

    srand((unsigned int) curtime);                                        /*Scope : Variable : Class , call srand to seed/generate random number.                 */
    
    for (int k=0 ; k < COMPUTATIONS ; k++)                                /*Scope :   loop   : while k < COMPUTATIONS do :                                        */
    {
        int y = rand();                                                   /*Scope : Variable : declare y , where we will keep the first random number.            */
        int z = rand();                                                   /*Scope : Variable : declare z , where we will keep the first random number.            */
        
        int w = ((y % 32768) + 1) * ((z % 32768) + 1) + 1;                /*Scope : Variable : declare w , where we will keep the sum of given calculation.       */
        int x = w;                                                        /*Scope : Variable : declare x , where we keep temporarily the value of w.              */
        int count = 0;                                                    /*Scope : Variable : declare count , where we will keep the count of k-almost number.   */

        while (x % 2 == 0)                                                /*Scope :   loop   : while x is even divide it by 2 until it becomes odd.               */
        { 
            count = count + 1;                                            /*Scope : Variable : add to count , count k-almost.                                     */
            x = x / 2; 
        } 
 
        for (int i = 3; i*i <= x; i = i+2)                                /*Scope :   loop   : loop until the square of i <= n.                                   */
        { 
 
            while (x % i == 0)                                            /*Scope :   loop   : while the remainder of x / i is 0 , then do :                      */
            { 
                count = count + 1;                                        /*Scope : Variable : add to count , count k-almost.                                     */
                x = x / i;                                                  
            } 
        } 

        if (x > 2)                                                        /*Scope : if statement : if x is prime > 2 then do :                                    */
        {
            count = count + 1;                                            /*Scope : Variable : add to count , count k-almost.                                     */
        }
        
        int gap = 0;                                                      /*Scope : Variable : declare gap , where we will keep the gaps that will be printed.    */
        int x_temp = w;                                                   /*Scope : Variable : declare count , where we will keep temporarily the x.              */
        
        while (x_temp != 0)                                               /*Scope :   loop   : while the x_temp is not 0 , then do :                              */
        {
            x_temp = x_temp / 10;                                         /*Scope : Variable : store to x_temp , the outcoume of x_temp /10.                      */
            gap = gap + 1;                                                /*Scope : Variable : store to gap , the gaps that will be printed.                      */
        }

        printf("%.*s", 10-gap, "          ");                             /*Scope : Program Output : print the gaps.                                              */
        printf("%d is a %d-almost prime number\n",w,count);               /*Scope : Program Output : print number and ?k-almost number.                           */
		
    }
    return 0;
}
/*End of main*/

/*
Code Metrix   :

Lines of code : 174
- Libraries :
    |stdio.h
    |stdlib.h
    |time.h
- Data Types :
    |Constant : 4
    |Variables : 21
        | int : 20
        | long : 1
- Loops :
    |for : 4
    |while : 5
- Program Output :
    |printf : 8

Execution :
- WSL UBUNTU :
    - Time :
        |real : 0m , 7.497s
        |user : 0m , 7.484s
        |sys  : 0m , 0.016s
- Linux DIT :
    - Time :
        |real : 0m , 9.053s
        |user : 0m , 9.050s
        |sys  : 0m , 0.003s
- Code Editor : Microsoft Visual Studio Code

*/