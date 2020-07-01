#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
class list {
	struct node {
		int data;
		node* next;
	};
public:

	node* head = NULL;
	int insert(int v, int ref) {
		node* ne = new node;
		ne->data = v;
		node* temp = head;
		node* pr = temp;
		temp = temp->next;
		if (ref == 0) {
			ne->next = pr;
			head = ne;
			return 0;
			          
		}
		else if (ref < 0) {
			return 0;
		}
		else {
			int x = 0;
			while (x < ref - 1) {
				pr = pr->next;
				temp = temp->next;
				x++;
			}
			pr->next = ne;
			ne->next = temp;
			return 0;
		}
     
	}
	void append(int val) {
		node* newnode = new node;
		newnode->data = val;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}

	int remove(int vl) {
		node* temp = head;
		node* pr = temp;
		temp = temp->next;
		if (head->data == vl) {
			head = head->next;
			delete pr;
			return 0;
		}
		while (temp->data != vl) {
			temp = temp->next;
			pr = pr->next;
		}
		if (temp->data == vl) {
			pr->next = temp->next;
			delete temp;
			return 1;
		}
		else {
			return 0;
		}


	}

	void print() {
		node* temp = head;
		while (temp->next != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}
	
};
int main() {
	list list;
	for (int x = 0; x < 4; x++) {
		int g;
		cin >> g;
		list.append(g);
	}
	list.print();
	list.insert(9, 2);
	list. print();
}