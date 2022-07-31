/*
 * Print_Output.c
 *
 *  Created on: 31 jul. 2022
 *      Author: nlbguz
 */

# include <stdio.h>   
# include <stdlib.h>	

int main()     			
{
    // scanf is a standard library function that allows you to read input from standard in (user - keyboard), but for embedded systems it can be a keypad or touchscreen.
    // By using scanf library function you can read both chars and numbers from the keyboard.
    int age;
    printf("Enter your age: ");          
    scanf("%d", &age);      // reads an integer (%d), puts read value to the address of the age varable!
                            // if you put %c, then the ASCI equavalent should be stored. Since c refers to char and age is defined as int!
    int a = getchar();      // If you just want to read a single character from the keyboard in ASCII format then just use getchar() function. DID NOT WORK FOR ME ON VSC!
                            // Program hangs untill you press a key here.
                            // getchar() function takes no argument and just returns an int value which happens to be the ASCII value of the key pressed.
    int a4 = getchar();     // The reason above code is not working is that we use an input buffer like we did for outputs. When we get an input let`s say 10 , we actually get 10\n
                            // So, 10 sends to variable but \n stays there. So, when we use getchar function, it gets /n. That is why it did not work above!!!
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;

    printf("Enter a number: \n");   // and here it skips this part because of getchar function above, strange!
    scanf("%d", &a1);
    printf("Enter a number: \n");
    scanf("%d", &a2);
    printf("Enter a number: \n");
    scanf("%d", &a3);
    printf("Average: %d \n", ((a1 + a2 + a3) / 3));
    // MULTIOLE INPUTS:
    printf("Enter 3 numbers: \n");   // and here it uses the value that we got above, strange!
    scanf("%d %d %d", &a1, &a2, &a3);  // Values can be entered by putting space between three numbers and one enter or press enter after typing each number!
    double b1=0, b2 = 90;
    printf("%lf %lf", b1, b2);
    // It might happen that you can not see your message on the console of some IDEs. This is because each IDE uses different console. In order to see your message you can use below command:
	// fflush(stdout);    // Normally when you print something to console it goes to your softwares output buffer first and then goes to the console. By using this command you are sending the buffer to console.
    // We needed this fflush on Eclipse`s console. However, it printf works fine with VSCs or windows`console (cmd).
    // If we do not type below code and run the .exe file by double clicking it on windows, we can not see average number since program is just terminated just after it. So use below code to terminate the program with an entry from user.
    printf("Please press a button to exit the program!");
    // getchar();
    // getchar();
    
    // or below is more proper way.
    while (getchar() != '\n')
    {

    }
    getchar();


}