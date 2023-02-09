/*****************************************************************************/
/* Skeleton provided by S. Bassil (Spring 2022)                              */
/*                                                                           */
/* Programmer: Ian Jones                                                     */
/*                                                                           */
/* Program: assignment05                                                     */
/*                                                                           */
/* Approximate Completion Time: 4 hours                                      */
/*****************************************************************************/

/*
  This program builds a linked list and traverses it iteratively.
*/

#include <iostream>
using namespace std;

/* declaration of structure */
struct node {
  int data;
  node *next;
};

/* functions prototypes */
node* insert_node(node *ptr, node *new_ptr);
node* find_node(node *ptr, int n);
node* delete_node(node *ptr, int n, bool &success_flag);
void print_backward(node *ptr);
void menu();

int main()
{
  int userChoice = 0; // holds the user menu choice
  int userSearch; // holds the integer to search
  node *nodePtr = nullptr; //holds the pointer to the first node of the list
  node *newPtr; //holds a pointer new node to be inserted into the list
  node *searchNode; //holds the pointer to the node with the search value
  bool flag; //indicates whether a deletion was successful or not

  //Welcomes the user
  cout << "Welcome to the Linked List program!" << endl << endl;

  //repeats the program until the user enters 5
  while (userChoice != 5)
  {
    //prompts the user with a menu and asks for a decision
    menu();
    cin >> userChoice;
    cout << endl;
    
    //validates the user input
    while (userChoice < 1 || userChoice > 5)
    {
      cout << "Invalid input!" << endl << endl;
      menu();
      cin >> userChoice;
      cout << endl;
    }

    //determines which actions to do depending on user input
    switch (userChoice)
    {
      case 1:
        
        //creates a new node to be entered
        newPtr = new node;
        
        //prompts the user for the interger to be put into the node
        cout << "Input an integer to be inserted into the linked list: ";
        cin >> newPtr -> data;
        cout << endl;
        
        //inserts the node into the list
        nodePtr = insert_node(nodePtr, newPtr);
        
        //displays a message to the user that a node has been entered
        cout << nodePtr -> data << " has been entered into the linked list"
             << endl << endl;
             
        break;

      case 2:

        //prompts the user for a search value
        cout << "Enter an integer to search in the linked list: ";
        cin >> userSearch;
        cout << endl;

        //assigns a pointer that points to the node with the searched integer
        searchNode = find_node(nodePtr, userSearch);
        
        //if the pointer is not the nullptr the condition will be true
        if (searchNode)
        {
          //displays a message to the user saying the search was successful
          cout << searchNode -> data << " has been found in the linked list"
               << endl << endl;
        }
        else
        { 
          //displays a message to the user saying the search failed
          cout << userSearch << " was not found in the linked list"
               << endl << endl; 
        }

        break;

      case 3:
        
        //prompts the user for which integer should be deleted from the list
        cout << "Enter an integer to be deleted from the linked list: ";
        cin >> userSearch;
        cout << endl;
        
        //deletes the node and returns a pointer to the new list
        nodePtr = delete_node(nodePtr, userSearch, flag);

        //flag will be true if deletion was successful and false otherwise
        if (flag)
        {
          //displays a message to the user confirming deletion
          cout << userSearch << " has been found and deleted " 
               << "from the linked list" << endl << endl;
        }
        else
        { 
          //displays a message to the user saying deletion failed
          cout << userSearch << " was not found in the linked list" 
               << endl << endl;
        }

        break;

      case 4:
        
        //displays the list in the order integers were entered into it
        cout << "The integers in the order they were entered are: ";
        print_backward(nodePtr);
        cout << endl << endl;

        break;

      case 5:
        cout << "Thank you for using my program!" << endl;
        break;
    }
  } 

  return 0;
}

/******************************************************************************/
/* Function: insert_node                                                      */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, ptr to the node to be inserted  */
/*                                                                            */
/* Data out: ptr to the first node in new linked list                         */
/******************************************************************************/

node* insert_node(node *ptr, node* new_ptr)
{
  //assigns the next pointer to be the old list pointer and returns the new
  //pointer
  new_ptr -> next  = ptr;
  return new_ptr;
}
 
/******************************************************************************/
/* Function: find_node                                                        */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, the integer searching for       */
/*                                                                            */
/* Data out: ptr to the node with data equals to integer searched for,        */
/*           nullptr if integer searched for was not found                    */
/******************************************************************************/

node* find_node(node *ptr, int n)
{
  //searches through the entire linked list for a value and returns the pointer
  //if the value is found
  while (ptr != nullptr)
  {
    if (ptr -> data == n)
      return ptr;

    ptr = ptr -> next;
  }

  //if ptr is nullptr then the entire list has been search, so return nullptr
  return nullptr;
}

/******************************************************************************/
/* Function: delete_node                                                      */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list, the integer searching for,      */
/*          flag to be set to:                                                */
/*            - true if integer was found and corresponding node deleted      */
/*            - false otherwise                                               */
/*                                                                            */
/* Data out: ptr to the first node in new linked list                         */
/******************************************************************************/

node* delete_node(node *ptr, int n, bool &success_flag)
{
  node *listPtr = ptr; //holds the pointer for the list
  node *deletePtr; //holds the pointer to be deleted

  //iterates through the whole list until ptr is nullptr
  while (ptr != nullptr)
  {
    //this is the case that the first item in the list is the item that 
    //should be deleted
    if (ptr -> data == n && listPtr == ptr)
    { 
      //listptr now points to the next item and ptr is deallocated
      listPtr = ptr -> next; 
      delete ptr;

      success_flag = true;
      return listPtr;
    }
    //this is the case that the value between the first and last items
    //in the list
    else if (ptr -> next != nullptr && ptr -> next -> data == n 
             && ptr -> next -> next != nullptr)
    {
      //deleteptr points to the node that needs to be deleted and the list
      //is changed to link the previous and next values
      deletePtr = ptr -> next;
      ptr -> next = ptr -> next -> next;
      delete deletePtr;

      success_flag = true;
      return listPtr;
    }
    //this is the case that the value is at the end of the list
    else if (ptr -> next != nullptr && ptr -> next -> data == n 
             && ptr -> next -> next == nullptr)
    {
      //the node that ptr -> next points to is deleted and the pointer
      //becomes a nullptr
      delete ptr -> next;
      ptr -> next = nullptr;

      success_flag = true;
      return listPtr;
    }

    ptr = ptr -> next;
  }
  
  //if the entire list was searched through then the value is not in the list
  success_flag = false;
  return listPtr;
}

/******************************************************************************/
/* Function: print_backward                                                   */
/*                                                                            */
/* Description: Write a brief description of what the function does           */
/*                                                                            */
/* Data in: ptr to first node in linked list                                  */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void print_backward(node *ptr)
{
  node *listPtr = ptr; //holds the pointer to the list
  node *lastPtr = nullptr; //holds the pointer that points to the last pointer
                           //in the list
  
  //loops until the lastPtr which points to the end of the list
  //points to the start of the list
  while (lastPtr != listPtr)
  { 
    //resets ptr to the start of the list
    ptr = listPtr;
     
    //loops until ptr becomes the lastptr
    while (ptr != lastPtr)
    {
      //checks that the next ptr is lastpoint, displays the integer and sets
      //lastPtr to be the current ptr moving lastPtr forward
      if (ptr -> next == lastPtr)
      {  
        cout << ptr -> data << " ";
        lastPtr = ptr;
      }
      else
        //moves the pointer one more down the list 
        ptr = ptr -> next;
    }
  }
}

/******************************************************************************/
/* Function: menu                                                             */
/*                                                                            */
/* Description: displays menu                                                 */
/*                                                                            */
/* Data in: none                                                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void menu()
{
  //displays the menu options to the user
  cout << "1. Insert Integer into Linked List" << endl
       << "2. Find Integer in Linked List" << endl
       << "3. Delete Integer from Linked List" << endl
       << "4. Print out Integers" << endl
       << "5. Quit" << endl << endl
       << "Enter 1, 2, 3, 4, or 5: ";
}
