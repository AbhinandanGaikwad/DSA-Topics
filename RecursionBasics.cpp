#include<bits/stdc++.h>
using namespace std;

void stackOverflow(){
    cout << "1";
    stackOverflow();

    //Function gets recursively called till Stack Overflow occurs 
    //This is because the call stack runs out of memory due to no terminating/returning condition

}
    

int cnt = 0;                    //Global Variable 'cnt'
void basicRecursion(){
    
    if(cnt == 3) {
        cout << endl ;          // This block is only printed only when the 'if' condition is met
                                //Thus , 'endl' is only printed once and not every time the function is called recursively  
        return;
    }
    cout << cnt << endl;
    cnt++;
    basicRecursion();

    //Recursively calls itself till 'cnt' becomes 3
    //Then it returns to the previous function call in the call stack and then the fucntion ultimately ends

}

void printName(int i,int n){
    
    if(i > n) {
        cout << endl;
        return;
    }
    cout << "Abhinandan" << endl;
    printName(i + 1,n);

    //Recursively prints the name 'n' number of times
    //Every time the function is called , 'i' is incremented to ultimately reach the terminating conditon i > n

}

void print1toN(int i,int n){
    
    if(i > n) {
        cout << endl;
        return;
    }
    cout << i << endl;
    print1toN(i + 1,n);

    //Similar to the last function, instead of printing the name, we print 'i'
    //which prints the current value then gets incremented in the function call 
    //and then prints the incremented value when called recursively after

}

void printNto1(int i,int n){
    if(i < 1){              //Condition here is 'i < 1' because we want to print numbers above '1', and function will stop recursion
                            //when value of 'i' is decremented below 1 
        cout << endl;
        return;
    }
    cout << i << endl;
    printNto1(i - 1,n);

    //In main function we can see that (n,n) is passed as the parameter instead of (1,n) in the previous functions
    //This will help us in decrementing the value of 'i' and this decrementing value will be printed in the recursive function call
    //Thus, all numbers from 'n' will be printed till '1' in the descending order
}

void print1toNbackTrack(int i,int n){
    
    if(i < 1) return;
    print1toNbackTrack(i - 1,n);
    cout << i << endl;
    
    
    //Very Important to note that here we print after the recursive function call
    //This will print 1 to N but using backtracking
    //Basically function calls itself till 'i >= 1'
    //After that it returns itself to the previous call in stack
    //In this call , the value of 'i' in that function call is printed and then goes back to the previous call in stack 
    //This is how we can use backtracking in recursive functions

}

void printNto1backTrack(int i,int n){
    if (i > n) return;
    printNto1backTrack(i + 1,n);
    cout << i << endl;
}

void parameterisedSumOf1toN(int i,int sum){
    if(i < 1){
        cout <<  sum << endl;
        return;
    }
    
    return parameterisedSumOf1toN(i - 1,sum + i);

    //Here we used local variable 'sum' to calculate the sum of 'n' numbers
    //'sum' gets 'i' added to it at every recursive function call , subsequently recursion ends when 'i < 1'
    //We did not use 'n' in the local variable scope because we then would have had to declare 'sum' as a global variable outside the function
}

int functionSumOf1toN(int n){
    if(n == 0) return 0;            //Returns '0' since sum of zero numbers is '0' 
    return n + functionSumOf1toN(n - 1);  //This function returns 'n' i.e the current value of n + functionSumOfN(n - 1) which is the sum of 'n-1' previous numbers
                                       //The sum of numbers will keep returning to the previous call in the stack and will be added to the respective value of 'n'
                                       //thus giving us the sum of 'n' numbers from 1 to N  
}

int factorialOfN(int n){
    if (n == 0) return 1;               // we can also use n == 1 since going till '0' or '1' is the same as 0! = 1 & 1! = 1 
    return n * factorialOfN(n - 1);

    //We find factorial of 'n' using functional recursion
    //similar to functionSumOf1toN , we replace '+' with '*'
    //Very important to note that if 'n' = 0, we have to return 1 instead of 0
    //This is because all factorials will turn out to be '0' since it will eventually be multiplied with 0 when n becomes 0

}

void parameterisedFactorialOfN(int i,int factorial){
    if(i < 1){
        cout << factorial << endl;
        return;
    }
    
    return parameterisedFactorialOfN(i - 1,factorial * i);

    //Factorial of 'n' using Parameterised recursion 
}

//Time complexity of all functions till here will be about O(n) since 'n' times the recursive function call occurs

void reverseTheArray(int i,int array[],int n){
    if (i >= n/2) return;
    swap(array[i],array[n - i - 1]);
    reverseTheArray(i + 1,array,n);

    //We reverse the given array by using recursion 
    //Note that we can simply use a 'for' loop to swap the array elements till the mid-way of the array
    //We can also use left & right as variables , keep them at the endpoints of the array 
    //and similarly swap elements in the 'for' loop or using recursion till the mid-way
    //Here , we used internal function swap() to respectively interchange the elements of the array
    //Also , remember that arrays are always passed as reference thus array elements were directly swapped
    //Time complexity here will be O(n/2) since we only swap till the mid-way of array 
}

bool checkPalindromeString(int i,string &s){            //Note that string is passed as reference here to work on the actual string itself
    if (i >= s.size()/2) return true;
    if (s[i] != s[s.size() - i - 1]) return false;
    return checkPalindromeString(i + 1,s);

    //We use 'bool' type function to return 'true' if string is a palindrome or 'false' if it is not
    //If 'i' exceeds mid-way throught the string , this means that (s[i] != s[s.size() - i - 1]) condition is true 
    //thus (i)th element and (n-i-1)th are the same 
    //which further indicates that the string is a palindrome
    //If the same condition is false for even a single recursive call , 'false' is returned indicating that string is not a palindrome
    
}

int fibonacciNumber(int n){
    if (n <= 1) return 1;
    int last = fibonacciNumber(n - 1) ;
    int second_last = fibonacciNumber(n - 2);
    return last + second_last ;

    //We find the number in the Fibonacci Sequence corresponding to 'n' using multiple recursion calls   
    //After defining 'last' as recursive call 1 of 'n - 1' and 'second_last' as recursive call 2 of 'n - 2', we return the sum of the two
    //n < = 1 will always return 1 since F(0) = F(1) = 1
    //Just to know that we can also use a 'for' loop to do the same but here we did it with recursion
    //Time complexity of this program is near about O(2^n), 
    //since every function call is divided into to two recursive calls again 
    //See it's Recursion tree for more understanding
}


int main(){
    
    //The following code is divided into blocks of comments consisting of Recursive Functions
    //Remove the comments to check specific block (or all blocks) of function according to your needs

    //Concepts of Recursion

    /*
    //stackOverflow();
    //basicRecursion();
    */
    
    int n;                  //Do not tamper with this variable as it will be need to take input;

    //Printing Name 'n' Times
    
    /*
    cout << "Enter 'n', for the number of times you want name to be printed : ";
    cin >> n;
    
    printName(1,n);
    */
    

    //Printing from 1 to n or vice versa
    
    /*
    cout << "Enter 'n' to print 1 to n or n to 1 : ";
    cin >> n;
    print1toN(1,n);
    
    printNto1(n,n);
    //Here, in the main function we passed (n,n) as the parameters instead of (1,n) so that it can be decremented in the function calls

    cout << "Using backtracking : " << endl;
    print1toNbackTrack(n,n);
    cout << endl;
    //We pass (n,n) which decreases value of 'i' inside function , but since we use backtracking , the numbers are still printed as 1 to N 

    printNto1backTrack(1,n);
    cout << endl;
    //Similar to the previous one , we pass (1,n) so that it backtracks in the call stack to print the numbers in the reverse order N to 1
    */

    //Printing the sum of 1 to 'n' numbers

    /*
    cout << "Enter 'n' to print the sum of 1 to 'n' numbers : ";
    cin >> n;

    cout << "Parameterised Recursion : "; 
    parameterisedSumOf1toN(n,0);
    //This is known as parameterised recursion since we pass 'sum' as the parameter in the function call 
    //'n' is passed as the sum of 'n' numbers , and 0 is the initial sum of the numbers

    cout << "Functional Recursion : ";
    cout << functionSumOf1toN(n) << endl;
    //Here , we only pass 'n' and print the result
    //Zero is not required to initialize the sum since we directly return the sum from the functional recursion
    //Note that this function is a 'return' function of datatype 'int'
    */

    //Printing the factorial of 'n' 

    /*
    cout << "Enter 'n' to print the factorial of 'n' : ";
    cin >> n;

    cout << "Functional Recursion : ";
    cout << factorialOfN(n) << endl ;
    //we get the factorial directly printed with 'return' type int function

    cout << "Parameterised Recursion : ";
    parameterisedFactorialOfN(n,1);
    //We pass 1 instead of 0 for the same reason as before, multiplying with 0 will always make factorial 0
    */

    //Reversing an array

    /*
    cout << "Enter the number of elements in the array to be reversed : ";
    cin >> n;

    
    cout << "Enter the elements of the array : ";
    int array[n];
    for (int i = 0;i < n; i++){
        cin >> array[i];
    }
    cout << endl;

    reverseTheArray(0,array,n);
    for (int i = 0;i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    */

    //Checking if a string is a palindrome or not
    
    /*
    cout << "Enter the string to check for palindrome : ";
    string str ;
    cin >> str;
   
    if(checkPalindromeString(0,str)) cout << "Given string is a palindrome." << endl ;
    else cout << "Given string is not a palindrome." << endl;
    */

    //Finding the Fibonacci Number corresponding to 'n'

    
    cout << "Enter the number to find it's corresponding number in the Fibonacci Sequence : ";
    cin>>n;
    cout << "F(" << n << ") : " << fibonacciNumber(n) << endl ;
    

}