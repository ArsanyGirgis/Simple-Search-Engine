# Simple-Search-Engine

A tool that analyzes a text file and returns information about its content. It also allows a simple search for words in the file.

The program reads the input file word-by-word. Separators such as , ; : ' \` & " " . { } ( ) are discarded.
Each word is then inserted into the in-order list, along with the line number in which it exists in the file. First line in the file is line #1. Note: book, Book and BOOK are the same word (Case insensitive).

The programs reads the commands line-by-line and executes them.

1. command: wordCount > Prints the number of words in the file.
2. command: distWords > Prints the number of distinct words in the file.
3. command: charCount > Prints the number of characters in the file (including spaces and newlines/carriage return).
4. command: frequentWord > Prints the word(s) that had occurred the most in the input file excluding common language constructs like (a, an, the, in, on, of, and, is , are). If two or more words have the same number of repetitions, one should print all of them sorting them in an alphabetical order.
5. command: countWord myword > prints the number of myword occurrence in the file.
6. command: starting mysub > Prints all words that start with "mysub" followed by their number of occurrences. For example, if the command is "starting Te", it shall print all words starting with "Te", for example "Temperature" "Temperament".
7. command : containing mystr > Prints all words that contain the string "mystr" followed by their number of occurrences. E.g. if the program is passed a command "containing al", it shall print words such as "shall" "all" in a table format.
8. command: search mystr > Prints all words that contain the string "mystr"along with the line numbers in which they exist.

The following is a sample CommandFile<br>
wordCount <br>
distWords <br>
charCount <br>
containing mega <br>
countWord Biology <br>
ending migo ==> should produce "Undefiened command" error search class
