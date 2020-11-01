# problemset4
This problem set will introduce you to loops (while, for, do...while), and command line arguments. In this problem set, you will
build upon the previous assignment. You will first learn how to get, error check, and use command line arguments to get data
passed into your program. You will then add looping to get input from the user multiple times, and to . Be sure to read this
problem set thoroughly, especially the sections of Collaboration and the Hand-in Procedure.
Collaboration
Collaboration amongst students is allowed to the extent outlined in the syllabus. That being the case, the goal of these
assignments is not to share code, but to learn the tools you need to succeed as a computer scientist. Students are expected to
write their own code free of plagiarism from any other student past or current. All assignments will be cross referenced across
all sections of CS135 using the Measure Of Software Similarity (Moss) to automatically determine the similarity of programs.
Refer to the syllabus for further details and consequences of breaking this policy.
Program: Multiple Airports Distance Calculator
Problem 1
The airplane company is happy with your software and wants to keep working to develop it into a more robust program. The
program you have already built is helping the airplane company calculate distances airplanes will have to fly and calculating
slopes airplanes will have to fly at to get to cruising altitude. To enhance the calculator the airplane company wants to be able to
send options to the program when it is initially run, and they want to be able to enter in multiple data points to find the
manhattan/euclidean distance on.
The airplane company wants to be able to send 2 options to the program as it is initially run: which type of distance they would
like to compute (manhattan/euclidean) and how many data points they want to calculate distance between. Inputting this data
into the program as it is initially ran is easily accomplished with command line arguments. You will need to intake 2 additional
command line arguments aside from ./a.out: -m/-e and iterationCnt. -m will run manhattan distance when the program is
running. -e will run euclidean distance when the program is running. iterationCnt will determine how many points the pilot
wants to calculate distance between while running your program on their flights.
In this step you also need to do some error checking on the command line arguments. If there is only 1 command line argument
your program should display a usage message showing what arguments to use with your program. The second command line
argument needs to be checked if it is valid i.e. “-m” or “-e”. If one of these two options is not input as the second command line
argument then an error should be displayed as shown below. For now you should add debugging statements printing which
distance will be calculated in each section of code based on which distance was selected when running the program. The third
command line argument will be checked in the following problems. Build a program that:
1. Gets 3 command line arguments from the user as described above.
a. If “./a.out” is entered display, “Usage: ./a.out -m/-e iterationCnt" and terminate the program.
b. If the number of command line args != 1 or 3 an error, "Error: Incorrect amount of command line arguments,"
should occur and the program should terminate.
2. Error checks the second command line argument as described above. If the second command line argument doesn’t
follow as described above an error, “Error: Not a valid option,” should be displayed and the program should terminate.
To check this problem is complete, you should be able to run the program with ./a.out and it just spit the usage message, run the
program with 2/4+ command line args and an error should display, run the program with the second command line arg being
something either then “-m” or “-e” and an error should display. Once the errors are working, you should be able to run the
program with proper command line args (3 args, second arg “-m”/”-e”) and if you choose “-m” the program prints manhattan,
and if “-e” the program prints euclidean. Don’t worry about arg 3 at this point. These prints are not required for the assignment
and are just debugging statements that should be left out of your final submission.
Problem 2
We must now error check our third command line argument. This option represents how many data points the pilot wants to
calculate distance on while running their program. Since command line arguments are strings and we need the argument as an
integer, we will need to convert the string to an integer. To do this we can use the atoi(string) function from stdlib. This 1
function will convert the string to an integer if there is one in the string, or return 0 if there is no integer in the string. Once the
string is converted to an integer we need to verify it is in range, for the sake of this problem set we will keep our range from 2-5
distances. This range is nice because if an invalid range such as a word is entered by the pilot, we can easily error check it as we
will get 0 back from atoi(string) which is out of range. If the entered distance is out of range an error should be displayed as
shown below. Add to your program:
1. The ability to get the desired iteration count from the user as an integer. If an integer is not entered an error, “Error:
Iteration count not in range 2-5,” should occur and your program should terminate.
2. The ability to check if the integer entered is in range 2-5. Your program should error if the integer isn’t in range.
To check this problem is complete, pass “-m” or “-e” as your second argument followed by anything not the integers 1-5 as
third command line argument, this should trigger the error above. These errors should match the example output exactly. You
can still have your debugging statements of which distance will be calculated in each section of code here, but the should be
removed in the next problem.
Problem 3
Now that we have checked all the command line arguments to be valid we can run the desired computation the pilot wants to
perform. To accomplish this you need to get input from the pilot in the form of (x, y) data points, run the respective distance the
user wants on the data points, then find the slope between the points. You will also need to keep track of which slope is the
highest and lowest slope while your program is running, and output your findings at the end.
You should get your data points just as you have in previous problem sets and you must error check the inputs the user is
inputting. If an input error does occur, you will need to loop until a valid input is taken in. You will also need to error if the user
enters an x or y value that is lower/higher than the minimum/maximum x and y values of 0/100. These min/max values should
be defined as global constants.
Once you have error checked your user input you can run the calculation your user wants to perform. You will need to either
perform manhattan or euclidean distance based on the command line arguments the user input in earlier problems. After the
distance has been computed you will need to find the slope between the 2 points. Once all of this data has been computed you
will output your results to the screen. You will then need to check if your current slope is the lowest/highest slope you have
calculated so far, if it is you need to keep track of it and the points that made it to output at the end of your program.
Once you have finished calculating the distance iterationCnt times you will need to output the min/max slopes you calculated,
the points that got you to them, and the distance between them in the form the user selected in the command line arguments.
Formatting for this output can be found in the example output.
One last thing, for the sake of learning all types of loops, you should perform your manhattan distance calculations inside of a
for loop, and your euclidean distance calculations inside of a do while loop, and error checking inside of while loops.
Add to your program:
1. The ability to get points from the user iterationCnt times.
(continued on next page)
1 http://www.cplusplus.com/reference/cstdlib/atoi/
2. Error checking to each user input, looping if an input failure occurs until one does not.
a. Error on cin failure
b. Error if entered x/y value is less than 0.
c. Error if the entered x/y value is greater than 100.
3. The ability to calculate manhattan/euclidean distance based off which selection the user makes in the command line
arguments.
4. The ability to calculate slope.
5. The ability to keep track of the greatest slope and the 2 points that create that slope.
6. Output of all of your calculations that matches the example output exactly. Note: to accomplish this you will need to
use the iomanip library.
The equation for manhattan distance is:
manDist = |x2 − x1| + |y2 − y1|
The equation for euclidean distance is:
eucDist = √(x x ) (y y ) 2 − 1
2 + 2 − 1
2
The equation for slope is:
slope = (y2 − y1) / (x2 − x1)
To check this problem is complete, verify your program is getting the same output as the samples in the example output.
