# Ass 1
Declare and implement a class ColoredBox which stores a box of
characters (Dynamic 2D array).
The class has private member variables that are attributes of
the box like the box itself(which is a dynamic 2D array of
characters), a character that forms the box, dimensions of the
box (length and width) and color of the box (integer). The class
also has a static member variable that stores the biggest area
among the boxes objects of the class.
This is an example of a box with the character ‘*’ as its building
block, length =5, width = 7, color = 4 (equivalent to Red)
2

This is another box with the character ‘-‘ as its building block,
length =6, width = 10, color = 1 (equivalent to Blue)
The member functions that needs to be implemented in your
class are:
● 1-A constructor or constructors that takes length and width
of the box (mandatory), the character that constructs the
box (optional and if not provided the character is ‘#’), the
color of the box (optional and if not provided the color is
white).
● 2-Getters and setters for the building block character and
color of the box.
● 3-A display function that prints the box
● 4-A function displayTransposed that displays the box
transposed, where the box below will be displayed as
follows:
● 5-A function displayWider that displays the box on a wider
scale, where the box below will be displayed as follows:

● 6-A function that takes a color as a parameter and displays
the box as a chess board where a character is displayed
with the original color of the object, and the next
character is displayed with the parameter color. For
example let’s say we have a box object (boxObj) with
dimensions 4 and 7, the character ‘&’, and the color 14
(yellow). We call the member function:
boxObj.displayChess(4). The displayed box will look like:
● 7-A function getArea that returns the calculated area of the
box (if for ex. Length = 10 and width = 3, then area = 30)
● 8-A static member function getMaxArea that returns the
value of the static member variable.
● 9-A destructor that frees dynamic memory
4
Note that all of the display functions do not change the original
box. They only display the box as required. So, when the
function displayOriginal is called after any of the other display
functions, the box is normal again.
General Notes:
1- To change the text color in your console:
a. Include the header file windows.h(#include<windows.h>)
b. Copy the code in the provided header file
“setColorFun.h” into your code, and use the function
setColor in that file. For example to call the function
such that it sets the text color to blue write setColor(1);
c. The header file setColorFun.h has a comment with the
possible colors and their integer equivalents.
2- Copy the following main function as your main and make sure
it works and provides the output shown. It is also included as
an attachment so that you can easily copy the code.

# Online Shopping System(ASS 2)
Using classes and arrays, the team will develop a set of functions for an online
shopping system. The system is represented by the following structure:
1- Class Item having the following private attributes: (ID, name, quantity, price) and
the following public methods:
- Constructors (default, parameterized, and copy)
- Setters & Getters
- Operator overloading for the ==, +=,-=, >> and << operators
Cairo University, Faculty of
Computers and Artificial Intelligence
Object-Oriented Programming
Assignment 2 (100 Marks )
Note that the ID member variable is not entered or read from the user. It is
automatically set by the class as a serial ID starting with the first item of ID 1 and
incrementing with every new object.
2- Class Seller having the following private attributes: (name, email, items,maxItems),
where items is a dynamic array of objects of type Item with the size maxItems. The
class has the following public methods:
- Constructor (parameterized)
- Operator overloading for the insertion << operators
- Add An Item.
- This will take an Item object as a parameter:
- If the item already exists in the seller's items you will increase the item’s
quantity by the quantity of the parameter item using the (+=) in Item class,
and the price of the parameter object will be ignored. Use the == operator
for this where an item is equal to another if they have the same name.
- Else you will add it to the seller’s items.
- The member function should return a boolean that indicates the successful
addition of item, which will succeed if there is a place in the array and fail
otherwise.
- Sell An Item.
- This will take an item name and a quantity as parameters
- If the quantity is <= item’s quantity you will decrease it from item Using
the (-=) in Item class.
- Else you will print him “There is only {quantity} left for this item”.
- The member function should return a boolean which is true if the item was
found, false otherwise.
- Print Items.
- This will print all the item information for the seller.
- You will print each item using the (<<) operator.
- Find an Item by ID
- This returns an Item object (or a pointer to Item) with the specified ID if
there is an item with such ID.
- Destructor
Cairo University, Faculty of
Computers and Artificial Intelligence
Object-Oriented Programming
Assignment 2 (100 Marks )
3- In the main function,
● First you’ll ask the seller to input his details.
● Then you’ll ask him for his store capacity (maxNumberOfItems).
● Then you will show him a menu to choose from which have the following
options:
1. Print My Info.
a. This will print the seller info using the (<<) operator in Seller class.
2. Add An Item.
3. Sell An Item.
4. Print Items.
5. Find an Item by ID
6. Exit
Writing Good Quality Code
No program stays the same. It will need to change to fix bugs, add new features, etc.
So,
It is very important to write high quality readable code, so that you or other developers
can be able to review and modify this code in the future. In this task, you will:
1. Add a header to your program saying who the author is, the purpose of the
program, etc.
2. Add a header for every function explaining what it does, what parameters it
takes
and what value it returns.
3. Write the code following C++ coding style.
http://geosoft.no/development/cppstyle.html
4. Add comments to any part that is difficult to understand.

# ASS 3
Declare and implement 5 classes: FloatArray, SortedArray,
FrontArray, PositiveArray & NegativeArray.
1- The FloatArray class stores a dynamic array of floats and its
size. It has:
- A parameterized constructor that takes the array size.
- An add method that adds a float at the end of the array.
- Overloading for the insertion operator << to write the array to a
file (ofstream)
- Overloading for the extraction operator >> to read the array
elements from the file (ifstream) and add them to the array.
- A destructor to deallocate the array
2- The SortedArray inherits from FloatArray. It has:
- A parameterized constructor that takes the array size.
- An add method that adds a float at the right place in the array
such that the array remains sorted with every add. Don’t add to
the array then sort but rather add in the right place.
3- The FrontArray inherits from FloatArray. It has:
- A parameterized constructor that takes the array size.
- An add method that adds a float at the front of the array.
4- The PositiveArray that inherits from SortedArray. It has:
- A parameterized constructor that takes the array size.
- An add method that adds a float to the array only if it’s a
positive number. It then uses the add method of SortedArray.
5- The NegativeArray that inherits from SortedArray. It has:
- A parameterized constructor that takes the array size.
- An add method that adds a float to the array only if it’s a
negative number. It then uses the add method of SortedArray.
The only input to your program is the names of the input txt file
and output txt file name. The input text file will have exactly
10 lines. Each line will have:
1-One of 5 words: Array, Front, Sorted, Positive, or Negative.
This indicates the type of array to create.
2-An integer which indicates the number of elements in the
array.
3-The elements to be entered into the array.
The following is an example content of the file:
You should use polymorphism in your code by creating an array
of FloatArray* in main.
Read from the txt file and allocate your objects according to the
type of array and fill the arrays using the extraction operator
>>.
After finishing reading the file, you should write your arrays to
another text file using the insertion operator<<.
The output file for the above text file will be:
Sorted 10 8.4 -4 2.3 11 80 7 77 95 12 100
Array 7 3.4 2 0 9 4.7 3 9
Front 5 8 4 7.9 0.44 1
Array 6 45 23 8.5 3.98 4 2.5
Sorted 4 90 6 4 111
Sorted 8 7 3 4 0 1.1 3.2 88 9
Array 6 13.5 7.6 9 33 1 0
Front 3 7 5 1.5
Positive 7 7.9 -1 -44 9.7 4.3 -1 0
Negative 8 88 -1.5 -40 -9.7 4.3 13 0 -11
Where each line begins with the number of elements followed
by the character ‘|’, a tab, then the array elements separated
by tabs.
Don’t forgot to deallocate by deleting your objects in main after
finishing.
A sample run is found below:
Don’t take any other inputs from the user. Otherwise you will
lose grades.
