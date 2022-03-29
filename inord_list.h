

/*
 * inord_list.h
 *
 *  Created on: May 8, 2021
 *      Author: student
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_

#include <string.h>
#include <string>
using namespace std;

#define ListElemType string

class inordList{

	public:
		inordList();
		bool insert (const ListElemType&, const int&);
		void dels();
		void countWord(ListElemType&);
		void search(ListElemType&);
		void starting(ListElemType&);
		void containing(ListElemType&);
		bool wordoccur();
		void wordCount();
		void distWords();
		void frequentWord();
		bool first(ListElemType&, int&);
		bool next(ListElemType&, int&);

	private:
		struct Node;
		typedef Node* link;
		struct Node{
			ListElemType elem;
			int lineNum;
			link next;
			int wcnt;
		};
		link head;
		link current;
		link pred;
};
#endif /* INORD_LIST_H_ */









