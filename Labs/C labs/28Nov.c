<stdio.h>
#include <math.h>#include <stdlib.h>#include <string.h>
//--------------------------------------------------------------------
//TASKS 1-7
//--------------------------------------------------------------------

/*
typedef struct Body {
float position[3];
float velocity[3];
double mass;
} Body;

int galactus(Body a)
{
      double gmass = a.mass / 10;
      printf("%f \n", gmass);
}
int main()
{
      // Tasks 1-3
      //declaration and initialisation;
      int vec1[6]={0,1,2,3,4,5};
      int i;
      for (i = 1; i < 6; ++i)
      {
            printf("%p/n \n", &vec1[i]);
      }
      
      
      // Task 4
      //declaration and initialisation;
      int vec1[3][2];
      int i,j;
      for (i = 0; i < 3; ++i)
      {
            for (j = 0; j < 2; ++j)
            {
                  int element = i*10+j;
                  vec1[i][j]=element;
                  //print values
                  printf("%d \n", vec1[i][j]);
                  //print memory
                  printf("%p/n \n", &vec1[i][j]);
            }
      }
      
      
      // Task 4.2
      //declaration and initialisation;

      char my_string[10];
      scanf("%s", my_string[0]);
      
      
      // Task 5 & 6
      //declaration and initialisation;

      int my_integer;
      printf("\nEnter the value to be searched : ");
      scanf("%d", &my_integer);
      printf("\nInput value : ");
      printf("%d" \n, my_integer);
      
      
      // Task 7
      
      //declaration and initialisation;
      Body earth;
      earth.mass = 5.972e27; // earth mass in grams
      galactus(earth);
      
      }


//--------------------------------------------------------------------
//WORKED PROBLEMS
//--------------------------------------------------------------------

//Problem 1float modulus(float vec1[],float vec2[]) {
      float mod;
      int i,n;

      n=3; mod=0.0;
      for (i=0;i<n;i++) {
            mod = (vec2[i]*vec2[i]) - (vec1[i]*vec1[i]);
      }
      mod=sqrt(mod);
      return mod;
}

float dotproduct(float vec1[],float vec2[]) {
      float dot;

      dot = (vec2[0]*vec1[0]) + (vec2[1]*vec1[1]) + (vec2[2]*vec1[2]);
      
      return dot;
}

float angle(float vec1[],float vec2[]) {
      float mod,dot,angle;

      mod = modulus(vec1,vec2);
      dot = dotproduct(vec1,vec2);
      angle = dot/mod;
      
      return angle;
}

int main()
{
      //declaration and initialisation;
      float positionVector1[]={3.0,4.0,0.0};
      float positionVector2[]={4.0,5.0,1.0};
      float len,product,theta;
      
      len=modulus(positionVector1,positionVector2);
      printf("length is %.2f\n",len);
      
      product=dotproduct(positionVector1,positionVector2);
      printf("dot product is %.2f\n",product);
      
      theta=angle(positionVector1,positionVector2);
      printf("angle between two vectors is %.2f\n",theta);
}


//Problem 2

int main() {
      // list of marks, declared as an array
      int marks[]={4.0, 6.0, 7.0, 5.0, 6.0, 8.0,
      10.0, 3.0, 9.0, 4.0};

      int i, n;
      n=10;
      printf("Marks: ");
      for (i=0;i<n;i++) {
            printf("%.1d ",marks[i]);
      }
      printf("\n");
      
      int max = 0.0;
      for (i=0;i<n;i++) {
            if(marks[i]>max){
                  max = marks[i];
            }
      }
      printf("Highest Mark: %d \n", max);
      
      int average;
      int sumtot = 0;
      for (i=0;i<n;i++) {
            sumtot = sumtot + marks[i];
      }
      average = sumtot / n;
      printf("Average: %d \n", average);
      
      int variance;
      int varsum = 0;

      for (i=0;i<n;i++) {
            varsum = varsum + average - marks[i];
      }
      variance = varsum / n;
      printf("Variance: %d \n", variance);
}
// Program to read marks from a file (moodle: readMarks.c).
//It stops either when ’maxNum’ numbers have been
//read or when the end of the file is reached.
int main() {
      FILE *inputFile;
      int index,n,maxNum;
      float marks[100];
      char finished;
      
      // this variable is set to the size of the array "marks"
      //if you need to input more than this number of marks
      //you need to change both the value of maxNum and the
      //size of the array ’marks[]’
      maxNum=100;
      
      // try to open file, checking that it exists
      inputFile=fopen("marks.dat","r");
      
      if ( ! inputFile ) {
            printf("could not open file: marks.dat\n");
            exit(1);
      }
      
      finished=0; // zero means not finished
      index=0;
      
      while ( finished == 0 ) {
            fscanf(inputFile,"%f",&marks[index]);
            // feof function checks for End Of File (EOF)
            if ( feof(inputFile) ) { finished=1; }
            else index++;
            if ( index==maxNum ) { finished=1; }
      }
      
      n=index;
      printf("read %d marks, stored as marks[0] to marks[%d]\n",n,n-1);
      printf("first mark is %.2e\n",marks[0]);
      printf("last mark is %.2e\n",marks[n-1]);
}*/

//Problem 3
int main() {
      char foo[] = {3,4,5};
      char bar[] = {6,7,8};
      char combinedString[7];
      int x;
      
      strcpy(combinedString,foo); //add foo to combined string
      printf("%s",combinedString);
      
      
      x=strcmp(combinedString,foo);
      printf("%d",x); //checking for 0
      
      strcat(combinedString,bar); //add bar
      printf("%s",combinedString);
