README
/*  
*   Eli-Henry Dykhne
*   0996524
*   20/03/2019
*   A4
*/
The file given to us has 3 start of file chars at the begining. Thus they have been removed by my parser. If you use a different file with no beginning of file chars, it is likely that the first word in the file will become cut off. (coding is the first word in the given file.) Should the first word be unsearchable, check to see if it is being mangled by the parser and if so, remove the fseek command before parsing starts in A4q1 and A4q2. This should not be a problem if you just test with the included file, or the one from the moodle page.

The programs may be compiled with make.
Run the programs with the commands ./A4q1 and ./A4q2 respectively.

The programs will prompt you for a key. After the search completes, the program will ask you if you would like to exit.
Enter y for yes. Enter anything else for no.

Due to floating point imprecision some values may be off by ~0.01.

Due to display of only two digits in q1, some values will display 0.00. This does not mean their cost is zero. It may just be too small to be shown with only two decimal places.

SAMPLE RUN A4q1:
---------------------------------------------------------
Enter a key: wine
Compared with of (6.15), go right subtree.
Compared with the (1.97), go right subtree.
Compared with university (0.41), go right subtree.
Compared with which (0.13), go right subtree.
Compared with with (0.04), go left subtree.
Compared with will (0.01), go right subtree.
Compared with winter (0.00), go left subtree.
Not found.
Would you like to exit? y/n: n   

Enter a key: undergraduate
Compared with of (6.15), go right subtree.
Compared with the (1.97), go right subtree.
Compared with university (0.41), go left subtree.
Compared with to (0.16), go right subtree.
Compared with undergraduate (0.05), found.
Would you like to exit? y/n: n

Enter a key: your
Compared with of (6.15), go right subtree.
Compared with the (1.97), go right subtree.
Compared with university (0.41), go right subtree.
Compared with which (0.13), go right subtree.
Compared with with (0.04), go right subtree.
Compared with writing (0.01), go right subtree.
Compared with year (0.00), go right subtree.
Compared with you (0.00), go right subtree.
Compared with your (0.00), found.
Would you like to exit? y/n: y

---------------------------------------------------------
END SAMPLE RUN

SAMPLE RUN A4q2:
---------------------------------------------------------
Enter a key: wine
Compared with the (0.0611), go right subtree.
Compared with to (0.0308), go right subtree.
Compared with university (0.0181), go right subtree.
Compared with with (0.0054), go left subtree.
Compared with which (0.0039), go right subtree.
Compared with winter (0.0020), go left subtree.
Compared with will (0.0015), go right subtree.
Not found.
Would you like to exit? y/n: n

Enter a key: undergraduate
Compared with the (0.0611), go right subtree.
Compared with to (0.0308), go right subtree.
Compared with university (0.0181), go left subtree.
Compared with universities (0.0054), go left subtree.
Compared with undergraduate (0.0044), found.
Would you like to exit? y/n: n

Enter a key: your
Compared with the (0.0611), go right subtree.
Compared with to (0.0308), go right subtree.
Compared with university (0.0181), go right subtree.
Compared with with (0.0054), go right subtree.
Compared with year (0.0015), go right subtree.
Compared with you (0.0005), go right subtree.
Compared with your (0.0005), found.
Would you like to exit? y/n: y

---------------------------------------------------------
END SAMPLE RUN