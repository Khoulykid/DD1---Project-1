# DD1-Project-1
### CSCE2301 – Digital Design I Project 1
### Contributers: sarah elsamanody 900212915 - ali elkhouly - nour yasser 900213024
-----

## General Informationa about the Project
- This project is written with C++ and it scripts HTML at one part to generat wavedrom code for excuting curcuit diagrams.
- The output is displayed in the consule and does not use GUI features.

-----
## Purpose of Project :-
This project is for Digital Design I course taken by CE/CS students in the American University in Cairo and its main purpose is to create a program 
that takes a boolean expression in either **SOP** or **POS** form and outputs the corresponding:
1.  Truth Table
2.  Canonical SOP form
3.  Canonical POS form
4.  Displays all possible Prime Implicants
5.  Minterms covered by each Prime Implicant that could be generated
6.  EPIs as a boolean expression
7.  The mintermns not covered by the EPIs
8.  The minimized Boolean Expression by Quine-Mccluskey method
9.  Drawing the K-Map
10. Drawing the logic circuit of the minimized expression using wavedrom

It is a practice to help understand more how boolean expression works and the Quine McCluskey method. It is also a good practice for usage of github as it is a group project.
Since all the outputs are depending on eachothers there has to be communication and this project is a great oppurtuinity for bettering communication skills and SW development integration.

-----
## Division of the Project :-
**The project is divided into 8 tasks represent in 7 functions:**

1. *Input & Validation Function*:

    >This function is responsibile for the input of the user and the validation of SOP and POS form to ensure valid input. It also removes spaces from strings entered and if there is double negation it removes them to reduce further problems.

2. *TruthTable & Canonical SOP/POS Forms Function*:
   
    >This function then takes the formatted input and from it, it displays the truth tables and by the truth table it gets corresponding SOP and POS.

3.  *Prime Implicant Generation & their Minterms Function*:
    
    >This function takes the truth table and works around to generate the PIs and what minterms do they cover and displays the following in their binary representation.

4. *Printing Essential Prime Implicants and the Minterms not Covered by EPIs Function*:

    >This function takes generated prime implicants from function 3 and check from them those defined as essential and prints them out in their boolean expression and then checks for the minterms not covered by the EPIs and prints them in their numbering format.
    
5. *Generating Minimized Expression through Quine McCluskey Function*:

    >This function takes from the one before the eliminated coverage chart which is the second step in Quine McClausky method as it can be automatically accomplished by the NON-EPIs and the minterms not covered by them. Then, with the data provided dominated rows and columns are eliminated leaving us with the minimized expression of the boolean expression.

6. *Generation of the Kmap Function*:

    >This function displays the kmap finalized covers to be taken to achieve the minimized expression from the kmap generated from truth table by showcasing covers through multiple kmaps such that each kmap represents one cover.

7. *Generation of the Circuit using Wavedrom Function*:

    >This function displays the circuit of the minimized expression by using fstream in C++ and writing the script for an html which will then be automatically called to display the minimized expression as a circuit diagram.
     
***For more details check the headers files of each function. Everything is commented to be easily followed and understood.***

------

## TO RUN THE CODE :-

1. First download all header files and the main.cpp.
2. The main contains all header files and calls function 1.
3. Function 1 automatically calls other functions and they all get called within one another.
4. All you need to do is run your cpp file after downloading all files and you shall see placeholder to your input and you exit the code by inserting 1.

-----

## Report :-
You can also find a report on the repo with more details on the thinking process and some of the test cases used in our project for further elaboration if needed.
