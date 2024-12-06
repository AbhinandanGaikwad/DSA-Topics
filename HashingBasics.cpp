#include<bits/stdc++.h>
using namespace std;

int main(){

    //Map is used to solve the problem but Arrays is also used with it's Brute Force Method, Optimal method as well as character hashing is also demonstrated
    //Remove the comments to check the respective codes

    
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements : ";
    for (int i = 0;i < n;i++){
        cin >> arr[i];
    }
    
    /*
    cout << "Enter the string : ";
    string str;
    cin >> str;
    */
    

    //Brute Force method

    int f;
    cout << "Enter the number of queries for which you want to search their frequency in the array : ";
    cin >> f;

    /*
    while(f--){   // I find this a unique way of writing the 'while' loop.
                  //It terminates when f = 0, so it runs exactly the amount of times as the number of queries
        int b;
        cout << "Enter the number whose frequency you want to find :";
        cin >> b;
    
        int count = 0;
        for(int i = 0;i < n;i++){
            if (arr[i] == b) count ++;
        }

        cout << "The number "<< b <<" appears " << count << " times in the array.";
        cout << endl;

    }
    */
    
    
    //The above method will take O(Q*N) time complexity where Q is the number of queries and N is the number of elements in the array
    //Obviously it will take a lot of time when both of these are huge numbers such as 10^5,10^6 etc
    //We solve the problem in less time using hashing concept 

    // Hashing
    /*
    //Pre - Compute
    int hashArray[13] = {0}; // Taking size 13 to keep it simple , and initializing all elements with 0
    for(int i = 0;i < n ; i++){
        hashArray[arr[i]]++;
        //We increment the index of the element in hashArray , which is present in the original array
        //This will count the frequency of all elements in the original array
    }

    while(f--){
        int number;
        cout << "Enter the number whose frequency you want to find :";
        cin >> number;
        
        //Fetch
        cout << "The number "<< number <<" appears " << hashArray[number] << " times in the array.";
        cout << endl;
    }
    */

    // Character hashing 

    /*
    
    //Pre - Compute
    int hashString[26] = {0};
    //int bigHash[256] = {0};
    for(int i = 0;i < str.size();i++){
        hashString[str[i] - 'a']++;
        //Here, we used ASCII of the lowercase alphabet 'a' to subtract from the characters of the given string
        //What this does is , it stores all lowercase values of alphabets in 0 - 25 indexes , thus making it simple for us to understand
        //bigHash[str[i]]++;
        //On the contrary we can also use array of size 256 , which will store all characters from 0 - 255 as their ASCII code
        //Both of the two methods will retrieve the frequency of the characters in the given string , we can use any method of the two.
    }

    while(f--){
        char c;
        cout << "Enter the character whose frequency you want to find :";
        cin >> c;
        
        //Fetch

        cout << "The character "<< c <<" appears " << hashString[c - 'a'] << " times in the array.";  
        // Note that even while printing , we have to subtract the value of 'a' from the input character since it will be ASCII here

        //cout << "The character "<< c <<" appears " << bigHash[c] << " times in the array."; 
        cout << endl;
    }

    */


    // Number hashing - Using Map

    //Pre - Compute

    map<int,int> mapHash;
    for(int i = 0; i < n; i++){
        mapHash[arr[i]]++;
        //Map stores the elements and it's frequencies in a key-value pair respectively, in a sorted manner.
        //To store a large group of numbers such as 10^5,10^6 values , we can use long , long long, to avoid segmentation faults which occured during arrays
    }

    unordered_map<int,int> unmapHash;
    for(int i = 0;i < n;i++){
        unmapHash[arr[i]]++;
        //Unordered Map does the same thing as map , storing in key-value pairs
        //However the keys are not stored in sorted manner . It is randomized and different compilers can have different orders of storing same elements
    }

    //Note that we can declare mapHash & unmapHash where array was declared and while taking array elements as input, we can simulataneously hash them using these.
    //If we do this, Since time complexity was O(2N) before , and will be O(N) after, thus this is not a huge difference in time taken to execute the code

    //Also to Clarify how elements are stored , we can print elements of both map & unordered_map

    /*
    cout<<"Map : " << endl; 
    for(auto it: mapHash){
        cout << it.first << "->" <<it.second << endl;
        //Elements will be in sorted Order
    }


    cout<<"Unordered Map :" << endl;
    for(auto it: unmapHash){
        cout << it.first << "->" <<it.second << endl;


        //Elements will be in random Order
    }
    */
    
    while(f--){
        int number;
        cout << "Enter the number whose frequency you want to find :";
        cin >> number;

        //Fetch
        cout << "The number "<< number <<" appears " << mapHash[number] << " times in the array." << endl;
        //cout << "The number "<< number <<" appears " << unmapHash[number] << " times in the array." << endl;
        cout << endl;

    }

    //Finding the highest/lowest frequency elements in the array

    int highestFrequency = 0, highestElement = 0;
    int lowestFrequency = n, lowestElement = 0;

    for(auto it : unmapHash){
        if(it.second > highestFrequency) {
           highestFrequency = it.second;
           highestElement = it.first;
        }

        if(it.second < lowestFrequency){
            lowestFrequency = it.second;
            lowestElement = it.first;
        }

        //We use Unordered Map 'unmapHash' to find the highest & lowest frequency elements
        //Please remember to check which variable we are assigning and what we are assigning it to
        //A very crucial mistake I did while writing the code was I assigned stuff like this 'it.second = highestfrequency' & 'it.first = element' 
        //This cannot be done because 'it.first' is a unique key which cannot be modified so it cannot be used to allocate it's value to highest/lowest element
        //and the value of 'it.second' will change when we try to alloacate it's value to highest/lowest frequency
        //I tried to directly operate on the unordered_map which is a bad practice
        //Avoid such mistakes , always assign the variables with values and not directly on the data structures  
        


    }

    cout << "The number " << highestElement <<" has the highest frequency appearing " << highestFrequency << " times." << endl;
    cout << "The number " << lowestElement <<" has the lowest frequency appearing " << lowestFrequency << " times." << endl;




     
    return 0;
}