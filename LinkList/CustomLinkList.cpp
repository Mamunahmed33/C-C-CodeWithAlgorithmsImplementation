//Khandaker Mamun Ahmed

#include <iostream>

using namespace std;

struct node{
    int info;
    node *next;
};

void Traverse();
void Search();
void Insert();
void InsertElementSecond();
void InsertingAtBegining();
void DeleteElement();

int searchElement, insertingElement;                //Global integer variables
node *head;						//Global node type vairable for tracking head

int main(void)				//main function
{
    int element,count=0,inp;
    node *old;

    cout<<"Enter total number of elements you want to enter in the link list:";
    cin >> element;

    cout<<"Enter elements:";
    for(int i=0; i<element; i++)
    {
        count++;
        cin>>inp;

		node *nn;
        nn = new node[1];

        nn[0].info = inp;
        nn[0].next = NULL;

        if(count==1)
            head=&nn[0];
        else
            old->next=&nn[0];

        old=&nn[0];
    }

	Traverse();
	Search();
	Insert();
	Traverse();
	InsertElementSecond();
	Traverse();
	DeleteElement();
}								//End of main function


void Traverse()					//Traverse Function
{
    node *current;
	current=head;

	while(1){

       cout << current->info << endl;
		if(current->next == NULL) break;
		current = current->next;
    }
}								//End of Traverse Function


void Search()					//Searching function
{
	node *track,*current;
	current=head;
	cin >> searchElement;

	while(1)
	{
		if(searchElement==current->info)
		{
			track=current->next;
			break;
		}
		else
			current=current->next;
	}

	cout<<"\n\n\tSearch Element : "<<searchElement<<" \n\tThe next element after search element : "<<track->info<<endl;

}									//end of Searching function

//Insertion function 1
void Insert()						//Insert function
{
	node *track, *current;
	cin >> insertingElement;

	current=head;

	while(1)
	{
		if(searchElement==current->info)
		{
			track=current->next;
			break;
		}
		else
			current=current->next;
	}

	node *nn;
	nn = new node[1];

    nn[0].info = insertingElement;
    nn[0].next = NULL;

	current->next= nn;

	nn->next = track;

	cout<<"\n\nInsert element on line 13 after element on line 12 is complete mama.\n"<<endl;
}												//End of Insert function


void InsertElementSecond()							//Start of InsertElementSecond function
{
	node *track, *current;

	current = head;
	int flag = 0;

	while(1)
	{
		if(current->info==searchElement)
			flag++;

		else{
			track = current;
			current=current->next;
		}

		if(flag==1)
		{
			node *nn;
			nn = new node[1];

			nn[0].info = insertingElement;
			nn[0].next = NULL;

			track->next = nn;
			nn[0].next = current;

			cout<<"Insert the element on line 13 before element on line 12 complete mama.\n"<<endl;
			break;
		}
	}
	InsertingAtBegining();							//Calling InsertingAtBeginingg function
}													//End of InsertSecondElement function

void InsertingAtBegining()							//Start of InsertingAtBeginingg function
{
	node *nn;
	nn = new node[1];

	nn[0].info = insertingElement;
	nn[0].next = NULL;

	nn->next = head;

	head = nn;

	cout<<"Inserting at the begining is complete."<<endl;
}													//End of InsertingAtBeginingg function

void DeleteElement()								//Deleting link list function
{
	node *current;
	while((head != NULL))
	{
		current = head;
		head = head->next;
		delete [] current;
	}

	cout<<"Deleting link list is complete";
}
