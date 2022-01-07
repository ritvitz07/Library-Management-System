#include<iostream> 
#include<conio.h>
#include<string>

using namespace std;

class Book {

	private:
		string isbn, title, author, edition, publication; //private variables

	public:
		//setters - assigning user value to private variables
		// void setstid(string s){
		// 	sci = s;
		// }

		void setIsbn(string a){
            isbn = a;
        }

		void setTitle(string b){
            title = b;
        }

		void setAuthor(string c)
        {
            author = c;
        }

		void setEdition(string d)
        {
            edition = d;
        }

		void setPublication(string e)
        {
            publication = e;
        }

		//getters - getting the values from private variables
		// string getstid(){
		// 	return sci;
		// }

		string getIsbn()
        {
            return isbn;
        }

		string getTitle()
        {
            return title;
        }

		string getAuthor()
        {
            return author;
        }

		string getEdition()
        {
            return edition;
        }

		string getPublication()
        {
            return publication;
        }
};

//initializing functions with counter as parameter
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void issueBook();
void quit();

//counter for Book array
int counter = 0;

//function for incrementing counter
void increment(int a){
	a++;
	counter = a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	counter = a;
}

//Book class array initialization
Book books[10];
//vector<book> b;

//main function

int main()
{
	system("CLS");
    string choice;
    //Main Menu
    //string pass;
    // system("CLS");
    // cout<<"\n\nLIBRARY MANAGEMENT SYSTEM\n\n";
    // cout << "Enter Your Password To Login : ";
    // getline(cin, pass);
    // if(pass == "5794")
    // {
    //     cout << "Access Granted...\n\n";
 
        system("CLS");
        cout << "\nLIBRARY MANAGEMENT SYSTEM\n\n";
        cout << "1. ADD BOOK\n";	
        cout << "2. DELETE BOOK\n";	
        cout << "3. EDIT BOOK\n";	
        cout << "4. SEARCH BOOK\n";	
        cout << "5. VIEW ALL BOOKS\n";	
		cout << "6. ISSUE A BOOK\n";
        cout << "7. QUIT\n\n";

        cout << "ENTER YOUR CHOICE : ";
        getline(cin, choice);
        system("CLS");

        if(choice == "1"){
            addBook(counter); //function call
        }		

        else if(choice == "2"){	
            deleteBook(counter); //function call
        }

        else if(choice == "3"){
            editBook(counter); //function call	
        }

        else if(choice == "4"){
            searchBook(counter); //function call	
        }

        else if(choice == "5"){
            viewAllBooks(counter); //function call	
        }

        else if(choice == "6"){
            issueBook();	 //function call
        }

		else if(choice == "7"){
			quit();	 //function call
		}

        else{
            main();  //function call to self(main)
        }
            
        _getch();
        return 0;
    //}

    // else{
    //     cout << "Incorrect Password...\n\n";
    //     main();
    // }

}


//addBook function
void addBook(int counter)
{
	string isbn, title, author, edition, publication, sci;
	cout << "\nADD BOOK\n\n";
	if(counter < 10)
    {
		// cout << "Enter Student Id : ";
		// getline(cin, sci);
		cout << "Enter ISBN No. : ";
		getline(cin, isbn); //getline - just like cin but includes white spaces
		cout << "Enter Title : ";
		getline(cin, title);
		cout << "Enter Author : ";
		getline(cin, author);
		cout << "Enter Edition : ";
		getline(cin, edition);
		cout << "Enter Publication : ";
		getline(cin, publication);
		//books[counter].setstid(sci);
		books[counter].setIsbn(isbn); //assigning the values entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);	
		increment(counter);	//calling function to increment counter
		cout << "\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .\n\n";
		_getch();
		main();
	}
	else
    {
		cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\nPress any key to continue . . .\n\n";
		_getch();
		main();
	}
}

//deleteBook function
void deleteBook(int counter)
{
	string isbn;
	int choice;
	cout << "\nDELETE BOOK\n\n";
	if(counter == 0)
    {
		cout << "THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .\n\n";
		_getch();
		main();
	}
	cout << "Enter ISBN : ";
	getline(cin, isbn);

	for(int i = 0; i < counter; i++)
    {
		//finding a match using for loop
		if(books[i].getIsbn() == isbn)
        {
			cout << "\nBOOK FOUND\n\n";
			cout << "Do you want to delete ?\n[1] Yes\n[2] No\n\nEnter Your Choice : ";
			cin >> choice;

			if(choice == 1){
				//books[i].setstid("");
				books[i].setIsbn(""); //setting the value to none
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");

				for(int a = i; a < counter; a++)
                {
					//adjusting the values after deletion of data eg. data from book[4] copied to book[3]
					books[a] = books[a + 1];
				}

				//books[9].setstid("");
				books[9].setIsbn(""); //adjustment if the library is full(10 books)
				books[9].setTitle("");
				books[9].setAuthor("");
				books[9].setEdition("");
				books[9].setPublication("");
				decrement(counter); //calling function to decrement counter
				cout << "\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .\n\n";
				_getch();
				main();
			}
			else
            {
				main();
			}
		}
	}
	cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .\n\n";
	_getch();
	main();
	
}
void editBook(int counter)
{
	//system("CLS");
	string editIsbn, choice;
	string isbn, title, author, edition, publication;
	cout << "\nEDIT BOOK\n\n";
	if(counter == 0)
    {
		cout << "THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .\n\n";
		_getch();
		main();
	}

	cout << "Enter ISBN : ";
	getline(cin, editIsbn);
	for(int i = 0; i < counter; i++)
    {
		//finding a match using for loop
		if(books[i].getIsbn() == editIsbn)
        {
			cout << "\nBOOK FOUND!\n\n";
			cout << "ISBN: " << books[i].getIsbn()<<endl;
			cout << "TITLE: " << books[i].getTitle()<<endl;
			cout << "AUTHOR: " << books[i].getAuthor()<<endl;
			cout << "EDITION: " << books[i].getEdition()<<endl;
			cout << "PUBLICATION: " << books[i].getPublication()<<endl;
			cout << "\nDo you want to edit ?\n[1] Yes\n[2] No\n\nEnter Your Choice : ";
			getline(cin,choice);

			if(choice == "1")
            {
				//re-entering values
				cout << "\nEnter ISBN : ";
				getline(cin, isbn);
				cout << "Enter Title : ";
				getline(cin, title);
				cout << "Enter Author : ";
				getline(cin, author);
				cout << "Enter Edition : ";
				getline(cin, edition);
				cout << "Enter Publication : ";
				getline(cin, publication);
				books[i].setIsbn(isbn);
				books[i].setTitle(title);
				books[i].setAuthor(author);
				books[i].setEdition(edition);
				books[i].setPublication(publication);	
				cout << "\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .\n\n";
				_getch();
				main();
				//editBook(counter);//function call to self
			}
			else{
				main();
			}			
		}
	}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .\n\n";
	_getch();
	main();
}

void searchBook(int counter)
{
	//system("CLS");
	string isbn;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout << "\nSEARCH BOOK\n\n";
	if(counter == 0)
    {
		cout << "THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .\n\n";
		_getch();
		main();
	}
	cout << "Enter ISBN : ";
	getline(cin, isbn);

	for(int i = 0; i < counter; i++)
    {
		//finding a match using for loop
		if(books[i].getIsbn() == isbn)
        { 
			cout << "\nBOOK FOUND!\n\n";
			cout << "ISBN : " << books[i].getIsbn()<<endl;
			cout << "TITLE : " << books[i].getTitle()<<endl;
			cout << "AUTHOR : " << books[i].getAuthor()<<endl;
			cout << "EDITION : " << books[i].getEdition()<<endl;
			cout << "PUBLICATION : " << books[i].getPublication()<<endl;
			print = true;
		}
	}

	if(print)
    {
		cout << "\n\nPress any key to continue . . .\n\n";
		_getch();
		main();
	}

	//if there's no book found
	else
    {
		cout << "\nBOOK NOT FOUND!\n\nPress any key to continue . . .\n\n";
		_getch();
		main();		
	}
}

void viewAllBooks(int counter)
{
	//iterating all the values on the library using book array
	//system("CLS");
	cout << "\nVIEW ALL BOOKS\n\n";
	
	cout<<"BOOK DETAILS\n\n";
	for(int i=0;i<counter;i++)
    {
		cout << "ISBN : " << books[i].getIsbn()<<endl;
		cout << "TITLE : " << books[i].getTitle()<<endl;
		cout << "AUTHOR : " << books[i].getAuthor()<<endl;
		cout << "EDITION : " << books[i].getEdition()<<endl;
		cout << "PUBLICATION : " << books[i].getPublication()<<endl<<endl;
	}
	cout << "Press any key to continue . . .\n\n";
	_getch();
	main();
}


// book Issue

string forGettingTitleOfBook(string isbn, int counter)
{
	for(int i = 0; i < counter; i++)
    {
		//finding a match using for loop
		if(books[i].getIsbn() == isbn)
        { 
			return books[i].getTitle();
		}
	}
}


string viewAllBooksForStudent(int counter, string stid)
{
	//iterating all the values on the library using book array
	//cout<<"VIEW ALL BOOKS\n\n";
    cout << "\n\nBOOK DETAILS\n\n";

	for(int i = 0; i < counter; i++)
    {
		cout << "ISBN : " << books[i].getIsbn()<<endl;
		cout << "TITLE : " << books[i].getTitle()<<endl;
		cout << "AUTHOR : " << books[i].getAuthor()<<endl;
		cout << "EDITION : " << books[i].getEdition()<<endl;
		cout << "PUBLICATION : " << books[i].getPublication()<<endl<<endl;
	}
	//cout<<"Press any key to continue . . .\n\n";
    cout << "\nWhich Book Do You Want To Issue : ";
    string choice;
    getline(cin, choice);
	return forGettingTitleOfBook(choice, counter);
    //cout << "Book Titled " << forGettingTitleOfBook(choice, counter) << " is Issued To Student Id : " << stid;
	//return isbn;
	_getch();
}

int calcFine(int d1, int m1, int d2, int m2)
{
	//calculating total no. of days
	int totalDays = 0;
	int monthdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(m1 == m2)
    {
        totalDays += d2 - d1 + 1;
    }
    else
    {
        for(int i = m1; i < m2; i++)
        {
            totalDays += monthdays[i];
        }

        totalDays += d2 - d1 + 1;
    }
	// cout << "\ntotal number of days are : " << totalDays;

	// calculating fine

	float fine = 0;

	if (totalDays <= 5)
	{
		fine = 0;
	}
	else if (totalDays > 5 && totalDays <= 10)
	{
		fine = (totalDays - 5) * 5;
	}
	else if (totalDays > 10 && totalDays <= 30)
	{
		//     ----5 days---   --between 10 and 30---
		fine = 5 * 5 + (totalDays - 10) * 10;
	}
	else
	{
		//     -5 days-   -10 , 30-       -  >30  -
		fine = 5 * 5 + 20 * 10 + (totalDays - 30) * 15;
		cout << "\nCanceled your Membership\n";
	}
 
	//cout<<"Your fine : " << fine<<" Rs. ";
    return fine;
}


int toCheckFine(int d1, int m1, int d2, int m2)
{
	cout << "\nEnter the date on which the Book was returned by a student : ";
	int d, m, y;
	cin >> d; // read the day
	if (cin.get() != '/' ) // make sure there is a slash between DD and MM
	{
		cout << "expected /\n";
		return 1;
	}
	cin >> m; // read the month
	if (cin.get() != '/' ) // make sure there is a slash between MM and YYYY
	{
		cout << "expected /\n";
		return 1;
	}
	cin >> y;

	if(m == m2 && ((d - d2) + 1 ) <= 5)
	{
		cout << "\nNo Fine ";
		return 0;                           //   0 :  means there is no fine 
	}
	else
	{
		return calcFine(d1, m1, d, m);
	}

}

void issueBook()
{
	//system("CLS");
	cout<<"\nISSUE A BOOK\n\n";
	string stid;
	cout << "Enter Your Student Id To Issue A Book : ";
	getline(cin, stid);
	// cout << "Which Book You Want To Issue\n";
    string title = viewAllBooksForStudent(counter, stid);
    // dateOfIssue();

	cout << "\nEnter Date of Issue Of Book : ";
	int d1, m1, y1;
	cin >> d1; // read the day
	if (cin.get() != '/' ) // make sure there is a slash between DD and MM
	{
		cout << "expected /\n";
		return;
	}
	cin >> m1; // read the month
	if (cin.get() != '/' ) // make sure there is a slash between MM and YYYY
	{
		cout << "expected /\n";
		return;
	}
	cin >> y1;

	//cout << "Book Titled " << title << " is Issued To Student Id : " << stid << " on " << d1 << "/" << m1 << "/" << y1 << "\n\n";

	cout << "\nEnter Date of Return Of Book : ";
	int d2, m2, y2;
    cin >> d2;
	if (cin.get() != '/' ) // make sure there is a slash between DD and MM
	{
		cout << "expected /\n";
		return;
	}
    cin >> m2;
	if (cin.get() != '/' ) // make sure there is a slash between MM and YYYY
	{
		cout << "expected /\n";
		return;
	}
	cin >> y2;

	int checkFine = toCheckFine(d1, m1, d2, m2);

	if(checkFine == 0){
		cout << "\nYour total fine is : " << checkFine;
	}
	else
	{
		cout << "\nYour total fine is : " << checkFine;
	}	

    // int totalFine = calcFine(d1, m1, d2, m2);
	// cout << " Your total fine is : " << totalFine;
	_getch();
	main();

}

void quit()
{
	//quit function
	_exit(1);
}


/***************************************************** THE END ***************************************************************/








// void fine()
// {
//     int days;
// 	float fine = 0;
// 	cout<< "Enter total days : ";
// 	cin>>days;
 
// 	if (days <= 5)
// 	{
// 		fine = 0;
// 	}
// 	else if (days > 5 && days <= 10)
// 	{
// 		fine = (days - 5) * 5;
// 	}
// 	else if (days > 10 && days <= 30)
// 	{
// 		//     ----5 days---   --between 10 and 30---
// 		fine = 5 * 5 + (days - 10) * 10;
// 	}
// 	else
// 	{
// 		//     -5 days-   -10 , 30-       -  >30  -
// 		fine = 5 * 5 + 20 * 10 + (days - 30) * 15;
// 		cout<<"Canceled your Membership\n";
// 	}
 
// 	cout<<"Your fine : " << fine<<" Rs. ";
//     return 0;
// }


/********************************************************************************************************************/


// void dateOfIssue()
// {
// 	cout << "\n\nEnter Date of Issue : ";
// 	int d;
// 	int m;
// 	int y;
// 	cin >> d; // read the day
// 	if (cin.get() != '/' ) // make sure there is a slash between DD and MM
// 	{
// 		cout << "expected /\n";
// 		return;
// 	}
// 	cin >> m; // read the month
// 	if (cin.get() != '/' ) // make sure there is a slash between MM and YYYY
// 	{
// 		cout << "expected /\n";
// 		return;
// 	}
// 	cin >> y; // read the year
// 	cout << "issued date: " << d << "/" << m << "/" << y << "\n\n";


// } 