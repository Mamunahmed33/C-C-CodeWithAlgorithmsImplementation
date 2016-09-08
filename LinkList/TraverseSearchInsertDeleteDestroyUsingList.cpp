/*      Khandaker Mamun Ahmed
        IIT, University of Dhaka
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<list>

using namespace std;

void Destroy();
void TraverseElement();
void InsertElement(int searchElement, int inputElement);
void menu(int searchElement, int inputElement);
void SearchElement(int searchElement);
void DeleteElement();


list <int> myList;

int main(void)															//Main Function
{
	ifstream fin("input.txt");
    if(fin.fail()){
	    cout<<"Can not open the file "<<endl;
	    exit(1);
	}

	int element, searchElement, inputElement,input;
	fin>>element;

	for(int i =0; i<element; i++)
	{
		fin>>input;
		myList.push_back(input);
	}

	cout<<"\nTaking input from file complete"<<endl;

	fin>>searchElement>>inputElement;

	fin.clear();                                                                //clearing the buffer
	fin.close();
	menu(searchElement, inputElement);
}																				//end Main Function


//you can this function always in the screen because it is the menu to work
void menu(int searchElement, int inputElement)									//Menu Function
{
    for( ; ; )
	{
		cout<<"\nWhat to you want to do? \n\t1.Search the element\n\t2.Traverse Elements\n\t3.Insert element\n\t4.Delete a element\n\t5.Destroy the Link List\n\t6.Clear the Screen\n\t7.exit\n\nEnter your choice: ";
		int choice;
		cin>>choice;

		switch(choice){

			case 1: SearchElement(searchElement);
				break;
			case 2: TraverseElement();
				break;
			case 3: InsertElement( searchElement, inputElement);
				break;
			case 4:DeleteElement();
				break;
			case 5: Destroy();
				break;
			case 6: system("cls");
				break;
			case 7: exit(1);

			default: cout<<"\nYou entered wrong."<<endl;
				break;
		}
    }
}																					//end Menu Function

void TraverseElement()															//Traverse Function
{
	int choice;

	cout<<"\n\t1.Traverse from first to last\n\t2.Traverse from last to first";
	cout<<"\nEnter your choice: ";
	cin>>choice;

	switch(choice){

		case 1: for(list <int>:: iterator it= myList.begin(); it!=myList.end(); it++)       //Traverse from first to last
					cout<<"\t\t"<<*it<<endl;
			break;
		case 2: {                                                                       //Traverse from last to first
                    list <int>:: iterator it1 = myList.end();

                    while(1)
                    {
                        it1--;
                        cout<<"\t\t"<<*it1<<endl;

                        if( it1==myList.begin())
                            break;
                    }
                break;
		}
		default: cout<<"oh bulshit.You entered wrong."<<endl;
					exit(1);
	}
}																					//end Traverse Function


void SearchElement(int searchElement)												//Searching function
{

	for(list <int>:: iterator it= myList.begin(); it!=myList.end(); it++)
	{
		if(*it==searchElement){
			cout<<"\nSearch Element: "<<*it;
			it--;
			cout<<"\nIt's Previous Element: "<<*it;
			it++;it++;
			cout<<"\nIt's next Element: "<<*it<<endl;
			break;
		}
	}
}																					//end Searching function


void InsertElement(int searchElement, int inputElement)								//Insert Function
{
	int choice;
		cout<<"\n\t1.Insert the element on line 13 after element on line 12"
		    <<"\n\t2.Insert the element on line 13 before element on line 12."
			<<"\n\t3.Insert element on line 12 at the beginning of the list."
			<<"\nEnter your choice: ";

		cin>>choice;

			switch(choice)
			{
				case 1: for(list <int>:: iterator it= myList.begin(); it!=myList.end(); it++)

							if(*it==searchElement)
							{	it++;
							    myList.insert(it,inputElement);
							    break;
							}
							cout<<"Insert complete";
                    break;

                case 2: for(list <int>:: iterator it= myList.begin(); it!=myList.end(); it++)
							if(*it==searchElement)
							{
							    it--;
								myList.insert(it,inputElement);
                                break;
							}
							cout<<"Insert complete";
                    break;
                case 3: myList.insert(myList.begin(),inputElement);
						cout<<"Insert complete";
					break;

                default: cout<<"You entered wrong.";
                break;
			}
}																					//end Insert Function


void Destroy()																        //Destroy Function
{
    cout<<"Before deleting my list size is: "<<myList.size()<<endl;

    myList.clear();
    cout<<"Delete list is complete"<<endl;
    cout<<"After deleting my list size is: "<<myList.size()<<endl;

	cout<<"\n\t\tNow there is no element on the link list";
}																					//end destroy function


//This function deletes the element when it found the element in the list. No mater the if the element is more than one times it deletes all
//If the element is not in list then function shows delete complete but doesn't work
void DeleteElement()                                                                //Delete function
{
	int deleteElement;
	cout<<"\nEnter the element to delete: ";
	cin>>deleteElement;
	myList.remove(deleteElement);
	cout<<"Delete complete mama"<<endl;
}                                                                               ////end Delete function
