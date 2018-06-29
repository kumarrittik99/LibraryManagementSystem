#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
inline void mainMenu();
inline void chooseOption();
inline void setBookTitle();
inline void setMemberTitle();
fstream myFile;
myFile.open("D:libraryManagementSystem.txt",iso_base::app|iso_base::in|iso_base::ate);
class Library
{
	private:
		string libraryName;
	public:
		Library()
		{
			
		}
		Library(string name)
		{
			libraryName=name;
		}
		void showLibraryName()
		{
			cout<<libraryName<<endl;
		}
};
class Book : public Library
{
	private:
		string bookName,bookAuthor;
		long bookId,stock,srNo=0;
		Book *next;
		Book *start=NULL;
	public:
		Book* createNode()
		{
			Book *temp = new Book;
			cout<<"Enter the name of the book.\n";
			getline(cin>>ws,temp->bookName);
			cout<<"Enter the name of the author of the book.\n";
			getline(cin>>ws,temp->bookAuthor);
			cout<<"Enter book ID.\n";
			cin>>temp->bookId;
			cout<<"Enter the number of books available.\n";
			cin>>temp->stock;
			temp->srNo=++srNo;
			temp->next=NULL;
			return temp;
		}
		void addBook()
		{
			Book *temp=start;
			if(start==NULL)
			{
				start=createNode();
			}
			else
			{
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=createNode();
			}
		}
		void removeBook(int pos)
		{
			Book *temp=start,*t;
			if(start==NULL)
			{
				cout<<"There is no book in the library!!! Please add some books to the library.\n";
			}
			else 
			{
				for(int i=0;i<pos-2;i++)
				{
					temp=temp->next;
				}
				t=temp->next;
				temp->next=temp->next->next;
				delete t;
				cout<<"This book was permanently deleted from the library!!!\n";
			}
		}
		void showBook()
		{
			Book *temp=start;
			if(start==NULL)
			{
				cout<<"There is no book in the library!!! Please add some books to the library.\n";
			}
			else
			{
				while(temp!=NULL)
				{
	                cout<<setw(20)<<temp->srNo<<setw(20)<<temp->bookId<<setw(20)<<temp->bookName<<setw(20)<<temp->bookAuthor<<setw(20)<<temp->stock<<endl;
	                myFile<<setw(20)<<temp->srNo<<setw(20)<<temp->bookId<<setw(20)<<temp->bookName<<setw(20)<<temp->bookAuthor<<setw(20)<<temp->stock<<endl;
					temp=temp->next;
				}
			}
		}
};
class Member : public Library
{
	private:
		string memberName;
		long memberId,phNo,srNo=0;
		Member *next;
		Member *start=NULL;
	public:
		Member* createNode()
		{
			Member *temp=new Member;
			cout<<"Enter the name of the new member.\n";
			getline(cin>>ws,temp->memberName);
			cout<<"Enter member Id.\n";
			cin>>temp->memberId;
			cout<<"Enter phone number.\n";
			cin>>temp->phNo;
			temp->next=NULL;
			temp->srNo=++srNo;
			return temp;
		}
		void addMember()
		{
			Member *temp=start;
			if(start==NULL)
			{
				start=createNode();
			}
			else
			{
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=createNode();
			}
		}
		void removeMember(int pos)
		{
			Member *temp=start,*t;
			if(start==NULL)
			{
				cout<<"There are no members in the library!!! Please add some members to the library.\n";
			}
			else
			{
				for(int i=0;i<pos-2;i++)
				{
					temp=temp->next;
				}
				t=temp->next;
				temp->next=temp->next->next;
				delete t;
				cout<<"This member was permanently removed from the library!!!\n";
			}
	   }
	   	void showMember()
		{
			Member *temp=start;
			if(start==NULL)
			{
				cout<<"There are no members in the library!!! Please add some members to the library.\n";
			}
			else
			{
				while(temp!=NULL)
				{
					cout<<setw(20)<<temp->srNo<<setw(20)<<temp->memberId<<setw(20)<<temp->memberName<<setw(20)<<temp->phNo<<endl;
				    myFile<<setw(20)<<temp->srNo<<setw(20)<<temp->memberId<<setw(20)<<temp->memberName<<setw(20)<<temp->phNo<<endl;
					temp=temp->next;
				}
			}
		}
};
void mainMenu()
{
	cout<<"1 Add a new book to the library.\n";
	cout<<"2 Remove a book from the library.\n";
	cout<<"3 Show all the books of the library.\n";
	cout<<"4 Add a new member to the library.\n";
	cout<<"5 Remove a member from the library.\n";
	cout<<"6 Show all the members of the library.\n";
	cout<<"7 Press to exit.\n";
}
void chooseOption()
{
	int n;
	cout<<"Press 1 to return to the main menu.\nPress 2 to exit the program.\n";
	cin>>n;
	if(n==1)
	{
		system("CLS");
		mainMenu();
	}
	else
	{
		exit(false);
	}
}
void setBookTitle()
{
	cout<<"\n\n\n"<<setw(20)<<"Serial Number"<<setw(20)<<"Book ID"<<setw(20)<<"Book Name"<<setw(20)<<"Author"<<setw(20)<<"Stock"<<"\n\n\n";
	myFile<<"\n\n\n"<<setw(20)<<"Serial Number"<<setw(20)<<"Book ID"<<setw(20)<<"Book Name"<<setw(20)<<"Author"<<setw(20)<<"Stock"<<"\n\n\n";
}
void setMemberTitle()
{
	cout<<"\n\n\n"<<setw(20)<<"Serial Number"<<setw(20)<<"Member ID"<<setw(20)<<"Member Name"<<setw(20)<<"Phone Number"<<"\n\n\n";
	myFile<<"\n\n\n"<<setw(20)<<"Serial Number"<<setw(20)<<"Member ID"<<setw(20)<<"Member Name"<<setw(20)<<"Phone Number"<<"\n\n\n";
}
int main()
{
	int choice,pos;
	Book b;
	Member m;
	mainMenu();
	while(true)
	{
		cout<<"Enter your choice.\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				system("CLS");
				setBookTitle();
				b.showBook();
				b.addBook();
				chooseOption();
				break;
			case 2:
				system("CLS");
				setBookTitle();
				b.showBook();
				cout<<"Enter the serial number of the book.\n";
				cin>>pos;
				b.removeBook(pos);
				chooseOption();
				break;
			case 3:
				system("CLS");
				setBookTitle();
				b.showBook();
				chooseOption();
				break;
			case 4:
				system("CLS");
				setMemberTitle();
				m.showMember();
				m.addMember();
				chooseOption();
				break;
			case 5:
				system("CLS");
				setMemberTitle();
				m.showMember();
				cout<<"Enter the serial number of the book.\n";
				cin>>pos;
				m.removeMember(pos);
				chooseOption();
				break;
			case 6:
				system("CLS");
				setMemberTitle();
				m.showMember();
				chooseOption();
				break;
			case 7:
				exit(false);
				break;
			default:
				cout<<"Invalid choice. Please enter a valid choice.\n";
				break;
		}
	}
	return 0;
}
