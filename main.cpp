//============================================================================
// Name        : a2.cpp
// Author      : arsany
// Version     :
// Copyright   : Your copyright notice
//
//============================================================================

#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include "inord_list.h"
using namespace std;

int charcs = 0;

void charCount(inordList &li) {
    cout << charcs << " characters" << endl;
}


int main(int argc, char* argv[]) {
	if(argc != 3){
		cout<<" Incorrect number of arguments"<< endl;

	}
	else{

		inordList wList;

		ListElemType word;
        int lineNumber = 0, wNumber=0;
		ListElemType exc = "()[]{}.&:;',?!";

		ifstream testFile (argv[1]);
		if (testFile.is_open()) {
			string myLine;
	        while (getline(testFile,myLine)) {
                charcs++;
                lineNumber++;
    			for(unsigned char p=0; p<exc.length();p++)
    			{
    				replace( myLine.begin(), myLine.end(), exc[p], ' ' );
    			}
                istringstream ss(myLine);

                while (ss>>word){
                	wNumber++;
                	for(unsigned char u=0; u<word.length(); u++){
                		word[u]=tolower(word[u]);
                	}
                	wList.insert(word, lineNumber);

                }
                charcs += myLine.length();
	        }
	        wList.wordoccur();

	        testFile.close();
		}
		else {
            cout << "File not found" << endl;
        }


        ifstream cmndFile (argv[2]);
	    if (cmndFile.is_open()) {
	    	ListElemType myLine;
	        while (getline(cmndFile,myLine)) {

	        	int numCounter =1;
	        	for(unsigned char q =0; q<myLine.length(); q++){
	        		if(((myLine[q] == ' ') || (myLine[q] == '\t')) && isalpha(myLine[q+1])){
	        			numCounter++;
	        		}
	        	}

                ListElemType comm[5];
                int m = 0;
                while( m < numCounter){
                    unsigned char n = 0;
                    while ((n < myLine.length()) && ((myLine[n] == ' ') || (myLine[n] == '\t'))){
                        n++; }
                    while ((n < myLine.length()) && (myLine[n] != ' ') && (myLine[n] != '\t')) {
                        comm[m] += myLine[n];
                        n++;
                    }
                    myLine = myLine.substr(n, myLine.length());
                    m++;
                }

                if (comm[0] == "charCount") {
                    if (numCounter == 1)
                        charCount(wList);
                    else
                        cout << "Incorrect number of arguments" << endl;
                }

                else if ( comm[0] == "countWord") {
                	if (numCounter == 2)
                        wList.countWord(comm[1]);
                    else
                    	cout << "Incorrect number of arguments" << endl;
               }

                else if ( comm[0]== "wordCount") {
                    if (numCounter == 1)
                    	wList.wordCount();
                    else
                        cout << "Incorrect number of arguments" << endl;
                }

                else if ( comm[0]== "distWords") {
                    if (numCounter == 1)
                    	wList.distWords();
                    else
                    	cout << "Incorrect number of arguments" << endl;
                }

                else if ( comm[0] == "frequentWord") {
                    if (numCounter == 1){

                    	wList.frequentWord();
                    }

                    else
                        cout << "Incorrect number of arguments" << endl;
                }

                else if (comm[0] == "search") {
                     if (numCounter == 2)
                     	wList.search(comm[1]);
                     else
                         cout << "Incorrect number of arguments" << endl;
                 }

                else if (comm[0] == "starting") {
                    if (numCounter == 2)
                        wList.starting(comm[1]);
                    else
                        cout << "Incorrect number of arguments" << endl;
                }

                else if (comm[0] == "containing") {
                    if (numCounter == 2)
                    	wList.containing(comm[1]);
                    else
                        cout << "Incorrect number of arguments" << endl;
                }

                 else {
                     cout << "Undefined command" << endl;
                 }

            }
	        cmndFile.close();
	    }
        else {
            cout << "File not found";
        }
	    wList.dels(); //destructor
	}
	return 0;
}





