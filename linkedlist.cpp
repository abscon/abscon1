#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 32760
using namespace std;


class node
{
public:
  int digit;
  node* next;
  node* prev;

  node()
  {
    digit = 0;
    next = NULL;
    prev = NULL;
  }

};




class intlist
{
public:
  node* start;

  intlist()                  
  {
    start = NULL;
  }

  ~intlist()                 //The destructor
  {
    node* track = start;
    node* clear;

    while(track != NULL)
      {
	clear = track;
	track = track->next;
	delete clear;
      }
    cout<<endl<<"intlist destructor called, memory cleared."<<endl;
  }




  void insert(int digit)
  {
    node* ptr;
    node* track;
    ptr = new node;
    ptr->digit = digit;
    track = start;

    if(track == NULL)
      {
	start = ptr;
	cout<<endl<<digit<<" is the first element in the list"<<endl;
      }
    else
      {
	
	while(track->next != NULL)
	  {
	    track = track->next;
	  }
	
	track->next = ptr;
	ptr->prev = track;
	cout<<endl<<digit<<" has been inserted after "<<track->digit<<endl;
      }
    
  }


  void insertatbeg(int digit)
  {
    if(start == NULL)
      {
	insert(digit);
      }
    else
      {
	node* newnode = new node;
	newnode->digit = digit;
	newnode->next = start;
	start->prev = newnode;
	start = newnode;
      }
  }




  node* listsearch(int val)
  {
    node* track = start;
    while(track != NULL)
      {
	if(track->digit == val)
	  {
	    return track;
	  }
	track = track->next;
      }
    return NULL;
  }



  void removenode(node* track)
  {
    if((track->next == NULL)&&(track->prev == NULL))
      {
	delete track;
	start = NULL;
      }
    else if (track->next == NULL)
      {
	(track->prev)->next = NULL;
	delete track;
      }
    else if(track->prev == NULL)
      {
	start = start->next;
	start->prev = NULL;
	delete track;
      }
    else
      {
	(track->prev)->next = track->next;
	(track->next)->prev = track->prev;
	delete track;
      }
  }






  void removedigit(int digit)
  {
    node* track;
    track = start;

    if(track == NULL)
      {
	cerr<<endl<<"No elements to remove."<<endl;
      }
    else
      {
	do
	  {
	    if(track->digit == digit)
	      {
		removenode(track);
		return;
	      }
	    track = track->next;
	  }
	while(track != NULL);
      }
    cerr<<endl<<"Element not found."<<endl;
  }


  node* freenode(node* track)
  {
    node* orphan;
    if((track->next == NULL)&&(track->prev == NULL))
      {
	start = NULL;
	orphan =  track;
      }
    else if (track->next == NULL)
      {
	(track->prev)->next = NULL;
	orphan =  track;
      }
    else if(track->prev == NULL)
      {
	start = start->next;
	start->prev = NULL;
	orphan =  track;
      }
    else
      {
	(track->prev)->next = track->next;
	(track->next)->prev = track->prev;
	orphan =  track;
      }

    orphan->next = NULL;
    orphan->prev = NULL;
    return orphan;
  }


  void insertafter(node* pi,node* key)      //pi should not be null
  {
    if(pi->next == NULL)
      {
	key->prev = pi;
	pi->next = key;
      }
    else
      {
	key->next = pi->next;
	key->prev = pi;
	(pi->next)->prev = key;
	pi->next = key;
      }
  }





  void insertionsortlist()
  {
    node* key;
    node* pi;
    node* pj;

    if(start == NULL)
      {
	cerr<<endl<<"No elements to sort."<<endl;
      }
    else if((start->next) == NULL)
      {
	cout<<endl<<"Only one element."<<endl;
      }
    else
      {

	for(pj = start->next; pj != NULL;pj = pj->next)
	  {
	    key = pj;
	    pi = pj->prev;

	    while((pi != NULL)&&(pi->digit > key->digit))
	      {
		pi = pi->prev;
	      }


	    if(pi == NULL)
	      {
		node* tmp = freenode(key);
		tmp->next = start;
		start->prev = tmp;
		start = tmp;
	      }
	    else
	      {
		node* tmp = freenode(key);
		insertafter(pi,tmp);
	      }
	  }
      }
  }



   
  
  void printall()
  {
    node* track = start;
    
    cout<<endl<<"The list elements are :"<<endl;
    while(track != NULL)
      {
	cout << track->digit ;
	track = track->next;
      }
  }



};



main()
{
  intlist obj;
  obj.insert(2);
  obj.insert(3);
  obj.insert(8);
  obj.insert(4);
  obj.insert(5);
  obj.insertatbeg(7);
  obj.printall();
  cout<<endl;
  obj.insertionsortlist();
  obj.printall();
  obj.removedigit(3);
  obj.removedigit(2);
  obj.removedigit(2);
  obj.removedigit(4);
  obj.removedigit(5);
  obj.removedigit(8);
}





	    
	












