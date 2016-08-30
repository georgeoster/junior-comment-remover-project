ASSIGNMENT DESCRIPTION:
Write C code to remove /* */-style comments from C code (it does not have to handle
C99’s //-style comments). Your program should take its input from STDIN, and send
its output to STDOUT. It  is suggested that you simply use getchar( ) and putchar( ) 
for input and output and shell redirection (the < and > operators) to run your program
using files for input and output instead of the keyboard and screen.
Your program should produce uncommented code just as gcc does during preprocessing.
Pay particular attention to the spacing rules, the rules for comment characters inside and
outside string literals, and what happens when comments are nested.
When code contains an unterminated comment, print an error message.
