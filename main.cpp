
#include <iostream>
#include <fstream>
#include <cmath>


// function prototypes
int *allocateArray(int *array, int *size);
double calcAvg(int *array, int size);

int main() // main function
{
    std::ifstream inFile("nums.txt"); //open  input file
    std::ofstream outFile("out.txt"); // open an output file
    int *array = nullptr; // num array
    int size = 0; // size of array
    double average = 0; //average variable
     int i = 0; // counter for size
  
    inFile >> size; // read the size of the array

        // validate size to be between [100,250] and % by 25
       if(((size % 25) == 0) && size <= 250 && size >= 100)
       {
             array = allocateArray(array, &size); // allocate the memory of the array
            
            std::cout << size <<  std::endl; // output to console the size
            outFile << size <<  std::endl; // output to the txt file the size
           
            while(inFile >> array[i]) // read the file the numbers to the array
            {
                i++;
                if(i == ceil((size * 0.9)))// if capacity of array reaches 90%
                {
                    average = calcAvg(array, i); // calculate average
                    // output the size and average
                    std::cout << i << " " << average << std::endl; //print to the console
                    outFile << i << " " << average <<  std::endl; //print to the outfile
                
                    array = allocateArray(array, &size); // expand the array
                 }
            }
                average = calcAvg(array,i); // calc avg
                std::cout << size << " " << i << " " << average << std::endl; // print size, nums, and average to console
                outFile << size << " " << i << " " << average << std::endl; // print size, nums, and average to outfile
                outFile.close(); //close the file
                inFile.close(); //close the file
                delete[] array; // release memory
       } else 
             {
               std::cout <<"Error"; //print error if not a valid size
            exit(1); //exit program
            }
   return 0;
}

// Function Name:allocateArray(int*, int*);
//Purpose: To allocate an array and increase its percentage
//         then return the new array
int *allocateArray(int *array, int *size)
{
   if(array == nullptr)
   {    array = new int[*size];
       return array;
   }
   else // expand the array
   {
       int *newArr = new int[(int)(*size * 1.3)]; // allocate a temporary array (newarr)
      
        for(int i = 0; i < (*size); i++) // copy the numbers from old array to new array
       {
           newArr[i] = array[i];
        }
      *size = floor((*size * 1.3)); // update size
       delete[] array; // delete old Array
       return newArr; // return new array
   }
}
// Function Name: calcAvg(int*, int);
// Purpose: To calculate average of the array
double calcAvg(int *array, int size)
{
   double sum = 0; //to hold the sum
   if(array != nullptr) //as long as the array is not empty
   {
       for(int i = 0; i < size; i++) //add the numbers from the aray to the sum
           sum += array[i]; 
    
         return (sum / size); // return average
   }
   return 0;
}
