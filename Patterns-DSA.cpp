#include<iostream>
using namespace std;

void print1(int n){
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            cout << "* ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print2(int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print3(int n){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <=i;j++){
            cout<< j << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print4(int n){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <=i;j++){
            cout<< i << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print5(int n){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print6(int n){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-i+1;j++){
            cout<< j << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print7(int n){
    for(int i = 0;i < n ;i++){
        for(int j = 0;j < n-i-1;j++){
            cout<<" ";
        }
        for(int j = 0;j < 2*i + 1;j++){
            cout<<"*";
        }
        for(int j = 0;j < n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;

    }

    //The space - star - space problem
    //Remember always calculate the rows then relate the columns with them
    //To find how many times the inner loop will iterate, we will have to calculate all columns mathematically and find a pattern 
    
}
void print8(int n){
    for(int i = 0;i < n ;i++){
        for(int j = 0;j < i;j++){
            cout<<" ";
        }
        for(int j = 0;j < 2*n - (2*i + 1);j++){
            cout<<"*";
        }
        for(int j = 0;j < i;j++){
            cout<<" ";
        }
        cout<<endl;
    }

    //This one is the exact opposite of the previous pattern
    //However this doesnt mean that we flip the values in the 'for' loop and we get the opposite pattern
    //We have to calculate the column pattern mathematically again and connect it with the rows  

    
}
void print9(int n){
    print7(n);
    print8(n);
    cout<<endl;
}
void print10(int n){
    for(int i = 1;i <= 2*n - 1 ; i++){
        int stars = i;
        if(i > n) stars = 2*n - i;
        for(int j = 1 ; j <= stars ; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    //We used the 'stars' variable here to print this pattern
    //It might seem like a symmetry but it is not and hence we used 'stars' variable with the 'if' statement to create the pattern
    cout<<endl;
}
void print11(int n){
        int element = 1;
    for (int i = 1;i <=n;i++){
        if(i%2 == 0) element = 0;
        else element = 1;
        for(int j = 1;j <=i;j++){

            cout<<element<<" ";
            element = 1 - element;
        }
        cout<<endl;  
    }

    //Here, element should be flipped between 0 & 1 , since the pattern is alternating
    //Also the 'else' statement is necessary to handle the case where initial element of row is 1
    //If 'else' statement is missing, then element will be zero for the odd row since it was flipped in the inner for loop before
    //We can also use 1-based indexing here , the 'if' and 'else' statements will have flipped values of 0 & 1
    cout<<endl;
}
void print12(int n){
    int spaces = 2*(n-1);
    for(int i = 1;i <=n;i++){
        
        for(int j = 1;j<=i;j++){
            cout<<j;
        }
        for(int j = 1;j<=spaces;j++){
            cout<<" ";
        }
        for(int j = i;j>=1;j--){
            cout<<j;
        }
        
        cout<<endl;
        spaces -=2;  
    }
    //We used 'spaces' variable here to print spaces accordingly
    //'j<=2*(n-i)' also worked here BUT it will only work when 1-based indexing is used since 'i' will always start from 1.
    //Hence it is important to use 'spaces = 2*(n-1)' as it will correctly decrement the spaces to be printed
    cout<<endl;

}
void print13(int n){
    int number = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            cout<<number<<" ";
            number++; // Here, we can use number = number + 1 as well
        }
        cout<<endl;
    }
    cout<<endl;
}
void print14(int n){
    for(int i = 0;i < n;i++){
        for(char j = 'A';j <= 'A' + i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    //'A' is a character initialized to j
    //'A' + i means that let's say i = 2
    //So 'A' + i will be A + 2
    //This means that the variable will print value till 2 places ahead of 'A' i.e 'ABC'
    //This means that the newly incremented value of j will be 'AB' or 'ABC' or 'ABCD' 
    //ASCII Values of characters is the reason why incrementing(or decrementing) the value of a 'A' or any character will give correct alphabetical order.
    //Other characters like %,& etc are also given ASCII Values so do check if confusion arises, however they won't interfere in the alphabetical order.    

    cout<<endl;
}
void print15(int n){
    for(int i = 0;i < n;i++){
        for(char j = 'A';j <= 'A' + (n - i - 1);j++){
            cout<<j<<" ";
        }
        cout<<endl; 
    }
    //Important thing to notice here is that if 0-based indexing is followed , (n-i-1) is the condition for reverse right angled triangle pattern
    //For 1-based indexing, (n-i+1) is the condition for reverse right angled triangle pattern 
    //Always calculate the correct formula for the condition by looking at the pattern and considering all types of indexing
    //These conditional values above are not generalised so do not assume them as it , always check according to the indexing and other considerations
    
    cout<<endl;
}
void print16(int n){
    char ch = 'A';
    for(int i = 0;i < n;i++){
        //
        for(int j = 0;j <=i;j++){ //Again , indexing both loops may change the pattern , so check carefully
            cout<<ch<<" ";
        }
        cout<<endl;
        ch++; 
    }

    //We can also use char = 'A' + i at the '//' above the inner loop

    cout<<endl;
}
void print17(int n){
    for(int i = 0;i < n ;i++){
        for(int j = 0;j < n-i-1;j++){
            cout<<" ";
        }
        char ch = 'A';
        //
        for(int j = 1;j <= 2*i + 1;j++){
            cout<<ch;
            if(j>(2*i + 1)/2) ch--; 
            else ch++;
        }
        for(int j = 0;j < n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }

    //We can also use a 'breakpoint' variable at '//' above the character 'for' loop to hold (2*i + 1)/2
    //We can also flip the 'if' & 'else' statements , but we need to flip the 'ch' variable increment & decrement as well

    cout<<endl;
}
void print18(int n){
    for(int i = 1;i <= n;i++){
        char ch = 'A';
        ch = 'A' + (n - i);
        for(int j = 1;j <= i;j++){
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }

    // Many different ways to execute this pattern
    //Do keep in mind how you index the loops , and accordingly change the condition
    //Hardcoding the value of a character is not recommended (Striver hardcoded 'E' inside inner for loop but comment section found this method without hardcoding 'E')

    cout<<endl;
}
void print19(int n){
    int spaces = 0;
     for(int i = 1;i <= n ;i++){
        for(int j = 1;j <= n - i + 1;j++){
            cout<<"*";
        }

        for(int j = 1;j<=spaces;j++){
            cout<<" ";
        }

        for(int j = 1;j <= n - i + 1;j++){
            cout<<"*";
        }
        cout<<endl;
        spaces += 2;     
     }

     spaces = 2*n - 2;
     for(int i = 1;i <= n ;i++){
        for(int j = 1;j <= i;j++){
            cout<<"*";
        }

        for(int j = 1;j<=spaces;j++){
            cout<<" ";
        }

        for(int j = 1;j <= i;j++){
            cout<<"*";
        }
        cout<<endl;
        spaces -= 2;     
     }    

     //Mirror image pattern
     //First build logic for one half of the pattern
     //Then build logic for the remaining half
     //Combine the two for creating the original pattern
     //We can also create two seperate functions for the mirror images 

     cout<<endl;
}
void print20(int n){
    int spaces = 2*(n - 1);
    for(int i = 1; i <= 2*n - 1;i++){
        int stars = i;
        if (i > n) stars = 2*n - i;
        for(int j = 1;j<=stars;j++){
            cout<<"*";
        }

        for(int j = 1;j<= spaces;j++){
            cout<<" ";
        }

        for(int j = 1;j<=stars;j++){
            cout<<"*";
        }
        cout<<endl;
        if(i < n) spaces -=2;
        else spaces +=2;
    }

    //Not a mirror image even though it seems like it's symmetrical
    //Check all conditions carefully along with proper variables

    cout<<endl;
}
void print21(int n){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == 1 || i == n || j == 1 || j==n) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;

        //Use of 'if' statement inside 'for' loop along with boundary conditions to satisfy the pattern requirements

        cout<<endl;
    }
}
void print22(int n){
    for(int i = 0;i < 2*n - 1;i++){
        for(int j = 0;j < 2*n -1;j++){
            int top = i;
            int left = j;
            int bottom = (2*n - 2) - i;
            int right = (2*n - 2) - j;
            cout<<(n - min(min(top,bottom),min(left,right)));
        }
        cout<<endl;
    }

    //Unique pattern 
    //We subtract the min operation (which is a matrix) from n to get our pattern , the resultant matrix
    //n - original.matrix(pattern given) = new.matrix(matrix with '0' boundary we obtained after doing this operation )
    //n -  new.matrix = original.matrix
    //Watch the patterns video from Strivers A2Z DSA for more clarification 
}

int main(){
    int t;
    cin>>t;

    for (int i = 0;i < t ;i++){
        int n;
        cin>>n;

        //This code is designed according to test-cases input on various competitive programming websites
        //Enter the number of times you want to run a pattern(or multiple patterns) as 't'
        //'n' is the input for the functions of patterns
        //All function calls of the functions of patterns are commented out
        //Switch - case isn't used because I felt it would overcomplicate stuff
        

        //print1(n);
        //print2(n);
        //print3(n);
        //print4(n);
        //print5(n);
        //print6(n);
        //print7(n);
        //cout<<endl;
        //print8(n);
        //cout<<endl;

        //For pattern 9, we can see that it is a combination of the previous two patterns - print7 & print8
        //In such scenarios , be smart and use existing code to avoid extra efforts
        //However , do keep in mind that only combine code if patterns are mirror images
        //Patterns ahead will clarify when patterns are mirror images and when they are different , and we have to create unique function for them.
        //Pattern 9 will be:-
        //print7(n);
        //print8(n);

        //Also just to avoid confusion for next problem numbers, I have created print9 function 
        //This function has both the previous functions in body to create the same pattern 
        //print9(n);

        //print10(n);
        //print11(n);
        //print12(n);
        //print13(n);
        //print14(n);
        //print15(n);
        //print16(n);
        //print17(n);
        //print18(n);
        //print19(n);
        //print20(n);
        //print21(n);
        //print22(n);

    }
}
