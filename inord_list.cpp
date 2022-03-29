/*
 * inord_list.cpp
 *
 */
#include <iostream>
#include <string.h>
using namespace std;
#include "inord_list.h"

inordList:: inordList(){
	head = NULL;
	current = NULL;
	pred = NULL;
}
bool inordList::insert (const ListElemType &e, const int &n){

	link addedNode;
	link pred;

	addedNode = new Node;
	if (addedNode == NULL){
		return false;
	}
	else{
		addedNode->elem = e;
		addedNode->lineNum = n;
	}

	if (head == NULL || e <= head->elem){
		addedNode->next =head;
		head = addedNode;
		return true;
	}
	else{
		pred = head;
		while (pred->next != NULL && pred->next->elem < e){
			pred = pred->next;
		}
		addedNode->next = pred->next;
		pred->next = addedNode;
		return true;
	}
}


bool inordList::first(ListElemType &e, int &n) {
    if (head == NULL)
        return false;
    else {
        current = head;
        e = current ->elem;
        n = current -> lineNum;
        return true;
    }
}

bool inordList::next(ListElemType &e, int &n) {
	if ((current == NULL) || (current->next == NULL))
        return false;
    else {
        current = current->next;
        e = current ->elem;
        n = current -> lineNum;
        return true;
    }
}


void inordList::dels(){
    link tempTr;
    while (head != NULL) {
        tempTr = head;
        head = head->next;
        delete tempTr;
    }
    current = NULL;
}

bool inordList ::wordoccur(){
	if(head==NULL){
		 return false;
	}
	else{
		int wcnt=0 ;
		link cmp ;
		cmp=head ;
		current=head ;
		while(cmp!=NULL){
			while(current!=NULL){

				if((current->elem).compare(cmp->elem)==0){
					wcnt++ ;
				}
				current=current->next ;
			}
			cmp->wcnt=wcnt ;
			wcnt=0 ;
			current=head ;
			cmp=cmp->next;
		}
	return true;
	}

}



void inordList::countWord(ListElemType &w) {
    int ctr = 0;
    int b;
    ListElemType a;
	first(a, b);
	while (current->next) {
        if (current->elem == w)
            ctr++;
        next(a, b);

	}
    cout << w << " is repeated " << ctr << " times" << endl;
}

void inordList::wordCount() {
    int ctr= 0;
    current=head;
	while (current) {
        ctr++;
        current = current->next;
	}
    cout << ctr << " words" << endl;
}


void inordList::distWords() {
    int ctr = 0;
    int b;
    ListElemType a;
    ListElemType w1 = "";
    ListElemType w2 = "";
    bool lastNode;
    lastNode = first(a, b);
    w2 = a;

	while (lastNode) {
        if (w1 != w2)
            ctr++;
        w1 = w2;
        lastNode = next(a, b);
        w2 = a;
	}
    cout << ctr << " distinct words" << endl;
}

void inordList :: frequentWord (){

	ListElemType freq = "";
	int maxt=0;

	current=head ;
	for(;current!=NULL;(current=current->next)){
		if((current->elem).compare("a")==0 ||(current->elem).compare("an")==0||(current->elem).compare("the")==0||(current->elem).compare("in")==0||(current->elem).compare("on")==0||(current->elem).compare("of")==0||(current->elem).compare("and")==0||(current->elem).compare("is")==0||(current->elem).compare("are")==0){
			continue ;
		}
		else if ((current->next)!=NULL && (current->elem).compare(current->next->elem)==0 ){
			continue ;
		}
		else{
			if((current->wcnt)>maxt){
				maxt=current->wcnt ;
				freq=current->elem ;
			}
			else if (current->wcnt<maxt){
				continue ;
			}

			else{
				freq=freq+" "+current->elem ;
			}
		}

	}
	cout<<"Most frequent word is: "<<freq<<endl ; ;
}

void inordList::search(ListElemType &targ) {
    int d = 0;
    ListElemType cmp, lN, lineNums;
    ListElemType a;
    int b;
	bool lastNode, str, nstr;

	lastNode = first(a,b);

	while (lastNode) {
        lN = to_string(b);

        ListElemType n1= " " + lineNums + " ";
        ListElemType n2 = " " + lN + " ";
        nstr = (n1.find(n2) >= 0) && (n1.find(n2) < n1.length());
        str = (a.find(targ) >= 0) && (a.find(targ) < a.length());
        if ((str) && (a != cmp)) {
            if (lineNums != "") {
                for (unsigned char f = 0; f < lineNums.length(); f++) {
                    cout << lineNums[f];
                }
                cout << endl;
                d++;
            }
            lineNums = "";
            cout << a << ":\tlines ";

            lineNums = lN.append(" ").append(lineNums);
            cmp = a;
        }
        else if ( (str) && (a == cmp)) {
            if (!(nstr)) {
                lineNums = lN.append(" ").append(lineNums);
            }
        }
        lastNode = next(a,b);
	}
    if (lineNums != "") {
    	for (unsigned char fr = 0; fr < lineNums.length(); fr++) {
              cout << lineNums[fr];
        }
        cout << endl;
        d++;
    }
    if (d == 0)
        cout << "Word not found" << endl;

}

void inordList::starting(ListElemType &targ){

	ListElemType found = "" ;
	for(current=head ;current!=NULL;(current=current->next)){
		if ((current->next)!=NULL && (current->elem).compare(current->next->elem)==0 ){
						continue ;
					}
		else{

			if ((current->elem).rfind(targ, 0) == 0) {
				if(found.compare("")!=0){
					found=found+"	"+current->elem +": "+to_string(current->wcnt);
				}
				else{
					found=found+current->elem +": "+to_string(current->wcnt);
				}
			}
		}
	}
	if (found.compare("")==0){
		cout<<"Word not found"<<endl;
	}
	else{
		cout<<found<<endl;
	}

}

void inordList::containing(ListElemType &targ){

	ListElemType found="" ;

	for(current = head; current!=NULL;(current=current->next)){

		if ((current->next)!=NULL && (current->elem).compare(current->next->elem)==0 ){
			continue ;
		}
		else{

			if ((current->elem).find(targ) != string::npos) {
				if(found.compare("")!=0){
					found=found+"	"+current->elem +": "+to_string(current->wcnt);
				}
				else{
					found=found+current->elem +": "+to_string(current->wcnt);
				}
			}
		}
	}

	if (found.compare("")==0){
		cout<<"Word not found"<<endl;
	}
	else{
		cout<<found<<endl;
	}

}












