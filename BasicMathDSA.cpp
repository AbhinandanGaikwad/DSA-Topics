#include<bits/stdc++.h>
using namespace std;

void count(int n){
    int cnt = 0;
    while(n > 0){
        n = n / 10;
        cnt = cnt + 1; 
    }

    cout<<"The number of digits in the given number are : " << cnt << "." <<endl;
}

void reverseOfNumber(int n){
    
    
    int reverseNumber = 0;

    while(n > 0){
        int lastDigit = n % 10;
        
        reverseNumber = (reverseNumber * 10) + lastDigit;

        n = n / 10;
        
    }
    cout<< "The Reverse of the Given Number is : " <<reverseNumber << "." << endl;  
}

void palindrome(int n){
    
    int originalNumber = n;
    int reverseNumber = 0;
    while(n > 0){
        int lastDigit = n % 10;
        
        reverseNumber = (reverseNumber * 10) + lastDigit;

        n = n / 10;
        
    }

    if(reverseNumber == originalNumber) cout << "Number is a palindrome : " << originalNumber << " <-> " <<reverseNumber << " ."<< endl; 
    else cout << "Number is not a palindrome." << endl;

    //Both variables in the 'if' statement will return the same value if it's a palindrome
    //I included it for clarity of user and to debug incase if anything goes wrong

}

void armstrongNumber(int n){
    
    int originalNumber = n;
    int sumOfDigits = 0;
    while(n > 0){
        int lastDigit = n % 10;
        
        sumOfDigits = sumOfDigits + (lastDigit * lastDigit * lastDigit);

        n = n / 10;
        
    }

    if(sumOfDigits == originalNumber) cout << "It is an Armstrong Number since the Sum of the cube of it's digits is equal to the number itself." << endl ;
    else cout << "Not an Armstrong Number." << endl ; 

    //Create a Function to show Armstrong Number Calculation in the Future

}

void printAllDivisors(int n){
    cout<<"(Brute Force) The Divisors for the Given Number in order are : ";
    for(int i = 1;i <= n;i++){
        if(n % i == 0) cout << i << " ";
    }
    cout << "." << endl;

    //The above method is the brute force method with O(n) time complexity
    //we can use the Square Root method to reduce the time complexity to just O(sqrt(n))
    //Note that Square Root Method will only bring the time complexity of the 'for' loop down to O(sqrt(n))
    //The total time complexity of the function below will be O(sqrt(n)) + O((number of factors) * log (number of factors)) + O(number of factors)

    vector<int> listOfDivisors;
    for(int i = 1;i * i <= n;i++){  //Note this way of iterating 'i' till square root of entered number
                                    //i * i <= n will be false when square root of n is the 'i' and loop will be terminated 
                                    //We can also use sqrt(n) for the loop termination 
                                    //however that increases the time complexity since in-built function sqrt is looped as well
        if(n % i == 0){
            listOfDivisors.push_back(i);
            if(n / i != i){
                listOfDivisors.push_back(n / i);
            }
        }
    }

    sort(listOfDivisors.begin(),listOfDivisors.end()); // Time complexity of this statement - O((number of factors) * log (number of factors)) 
    cout<<"(Square Root) The Divisors for the Given Number in order are : ";
    for (auto it : listOfDivisors) cout << it << " ";// Time complexity of this statement - O(number of factors)
    cout << "." << endl;


}

void primeNumber(int n){
    int count = 0;                  //Count Starts from 0 and if Count is 2 , it is a Prime Number
                                    //since the divisors are 1 & the number itself
    for(int i = 1;i * i <= n;i++){  
                                
        if(n % i == 0){
            count++;
            if(n / i != i){
                count++;
            }
        }
    }

    if(count == 2) cout <<"The Given Number is a Prime Number." << endl;
    else cout <<"The Given Number is not a Prime Number."<< endl;
}

void EuclideanGCDHCF(int a,int b){

//We can use the Brute Force method of if( a%i == 0 && b%i == 0) then GCD = i and run the loop , the last value of 'i' 
//when the 'if' condition is true will be GCD/HCF of the two numbers 
//But here we use Euclidean Algorithm to find GCD/HCF using modulus operator , google search for more information 

    while(a > 0 && b > 0){
        if(a > b) a = a % b;
        else b = b % a;
    }

    if (a == 0) cout<<"The GCD/HCF is : " << b << "." << endl;
    else cout<<"The GCD/HCF is : " << a << "." << endl; 

}
int main(){

    cout << "Enter the number of test cases : ";
    int t;
    cin>>t;

    //Functions are written above main function
    //All those functions are commented-out below
    //If you want to see one function at a time (or all) , remove the comment and run the program

    for(int i = 0;i < t;i++){
        cout << "Enter Number for Counting Digits,Reverse of a Number,Check Palindrome ,Check Armstrong Number, Print All Divisors or Check Prime Number : ";
        int n;
        cin >> n;
        cout << "Enter two numbers to find their GCD/HCF : ";
        int a,b;
        cin >> a >> b;
        
        //count(n);
        //reverseOfNumber(n);
        //palindrome(n);
        //armstrongNumber(n);
        //printAllDivisors(n);
        //primeNumber(n);
        //EuclideanGCDHCF(a,b);
    }
    

    return 0;
}