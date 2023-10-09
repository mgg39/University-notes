Task 1
/*
// pre-compiler inclusion commands
#include <stdio.h> // include access to the printf statement and file I/O
#include <math.h> // for sin, log command. Compile with the -lm option

double F(double x)
{
// return the requested function
return sin(x) - 2. * log(x + 1.) + x * x / 5.;
}
void write_file(char *filename, double x0, double x1)
{
// This function prints 101 values of the function F to file. The function
// evaluations lie between x0 and x1, the filename is the argument filename
int i; // define an integer i to use as loop counter
double x; // define x, which we will use to denote the current position
// within the interval.
FILE *p_file; // a pointer to a file.
// open the file for writing
p_file = fopen(filename, "w");
// perform a loop using the loop counter
for (i = 0; i <= 100; i++)
{
// set x to current position within the interval
x = x0 + i * (x1 - x0) / 100;
// step size Delta x = (x1 - x0) / 100, for 100 steps
fprintf(p_file, "%e, %e\n", x, F(x)); // print in scientific notation two
// values, the first the value of x, the second the return value of
// the function that can be found in memory starting at the location
// pointed at by p_func
}
// don’t forget to close the file afterwards
fclose(p_file);
}

int main()
{
// call the function to write the file
write_file("data.txt", 0., 5.);
return 0; // return ’all is well’ when exiting program
}

*/

//Task 2
/*
#include <stdio.h>
#include <gsl/gsl_rng.h> // the Random Number Generator GSL sub-library
int main (void)
{
// Demonstration of GSL random numbers. There are different random
// number generators in GSL. These are enumerated in global
// variables declared in the GSL libraries. Since these variables
// do not change over the course of the program (they’re labels,
// after all), these global variables get the additional indication
// ’const’ in front of them.
// declare pointer to a constant variable of specific type
const gsl_rng_type * T;
// a pointer to our current random number generator for use in the
// program
gsl_rng * r;
int i, n = 10; // declare loop counter i, will count for n steps
gsl_rng_env_setup(); // set up environment for random number generation
// set our pointer to a random number generator type to point
// at the label associated with the default random number generator
T = gsl_rng_default;
r = gsl_rng_alloc (T); // initialize our current random number generator
gsl_rng_set(r, 1); // set a random number sequence ’seed’
// print n random numbers evenly spaced between 0 and 1, lower bound
// inclusive, upper bound exclusive
for (i = 0; i < n; i++)
{
double u = gsl_rng_uniform (r);
printf ("%.5f\n", u);
}
// free memory allocated for our current random number generator
gsl_rng_free (r);
return 0; // return zero, i.e. "all is well"
}
*/

//Task3
/*
#include <stdio.h>
#include <math.h>
double F(double x)
{
return log(x) - 3./2. + 1./2. * sin(x / 2.);
}
double find_zero(double x0, double x1)
{
double x_mid = 0.5 * (x1 - x0) + x0;
int i;
double f0, f_mid, f1;
f0 = F(x0);
f1 = F(x1);
for (i = 0; i < 100; i++)
{
f_mid = F(x_mid);
if (f0 * f_mid < 0)
{
f1 = f_mid;
x1 = x_mid;
}
else
{
f0 = f_mid;
x0 = x_mid;
}
x_mid = 0.5 * (x1 - x0) + x0;
}
return x_mid;
}
int main()
{
printf("find zero outcome: %e\n", find_zero(1., 10.));
return 0;
}
*/

//Task 4 - contains re-used task 3 code
/*
#include <stdio.h>
#include <math.h>
double F(double x)
{
return log(x) - 3./2. + 1./2. * sin(x / 2.);
}
double Fdx(double x, double h)
{
return (-2*F(x-h)-3*F(x)+6*F(x+h)-F(x+2*h))/(6*h);
}
double find_zero(double x0, double x1)
{
double x_mid = 0.5 * (x1 - x0) + x0;
int i;
double f0, f_mid, f1,h;

printf("Type h: \n");
scanf("%lf", &h);

f0 = Fdx(x0,h);
f1 = Fdx(x1,h);
for (i = 0; i < 100; i++)
{
f_mid = Fdx(x_mid,h);
if (f0 * f_mid < 0)
{
f1 = f_mid;
x1 = x_mid;
}
else
{
f0 = f_mid;
x0 = x_mid;
}
x_mid = 0.5 * (x1 - x0) + x0;
}
return x_mid;
}
int main()
{
printf("find zero outcome: %e\n", find_zero(1., 10.));
return 0;
}
*/

/*
//Task5 - contains re-used task 3 code
#include <stdio.h>
#include <math.h>

double F(double x)
{
return log(x) - 3./2. + 1./2. * sin(x / 2.);
}

double find_zero(double x0, double x1)
{
double x_mid = 0.5 * (x1 - x0) + x0;
int i;
double f0, f_mid, f1;
f0 = F(x0);
f1 = F(x1);
for (i = 0; i < 100; i++)
{
f_mid = F(x_mid);
if (f0 * f_mid < 0)
{
f1 = f_mid;
x1 = x_mid;
}
else
{
f0 = f_mid;
x0 = x_mid;
}
x_mid = 0.5 * (x1 - x0) + x0;
}
return x_mid;
}

double simpson(double F){
  int n,i;
  double a,b,h,x,sum=0,integral;
  //Ask the user for necessary input
  printf("\nEnter the no. of sub-intervals(EVEN): ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  //Begin Simpson's Procedure:
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    if(i%2==0){
      sum=sum+2*F;
    }
    else{
      sum=sum+4*F;
    }
  }
}

int main()
{
int x = 10;
printf("zn Integral is: %e\n", simpson(F(x)));
return 0;
}
*/
//Task 6
#include<stdio.h>
#include<math.h>
 
/* Define the function to be integrated here: */
double f(double x){
  return log(x) - 3./2. + 1./2. * sin(x / 2.);
}
 
/*Function definition to perform integration by Simpson's 1/3rd Rule */
double simpsons(double f(double x),double a,double b,int n){
  double h,integral,x,sum=0;
  int i;
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    if(i%2==0){
      sum=sum+2*f(x);
    }
    else{
      sum=sum+4*f(x);
    }
  }
  integral=(h/3)*(f(a)+f(b)+sum);
  return integral;
}
 
/*Program begins*/
int main(){
  int n,i=2;
  double a,b,h,x,sum=0,integral,eps,integral_new;
   
  /*Ask the user for necessary input */
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  printf("\nEnter the desired accuracy: ");
  scanf("%lf",&eps);
  integral_new=simpsons(f,a,b,i);
 
  /* Perform integration by simpson's 1/3rd for different number of sub-intervals until they converge to the given accuracy:*/
  do{
    integral=integral_new;
    i=i+2;
    integral_new=simpsons(f,a,b,i);
  }while(fabs(integral_new-integral)>=eps);
   
  /*Print the answer */
  printf("\nThe integral is: %lf for %d sub-intervals.\n",integral_new,i);
