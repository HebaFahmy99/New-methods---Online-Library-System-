#include <iostream>

using namespace std;

class User //Class User
{
private: //members f class user // access modifier is private
	string name;
	int age;
	int id;
	string password;
	string email;
public: //functions of class user //access modifier is public
	static int count;
	User();
	User(string, int, string, string);
	User(User& user);
	int getCount();
	void setName(string n);
	string getName() const;
	void setPassword(string pass);
	string getPassword();
	void setEmail(string mail);
	string getEmail() const;
	void setAge(int a);
	int getAge() const;
	void setId(int id);
	int getId();
	void Print();
	friend ostream& operator<<(ostream& output, const User& userobj);
	friend istream& operator>>(istream& input, User& userobj);
};

//================================================================================================================
class UserList //class userlist
{
private: //members if class userlist //access modifier is private
	User* arrOfUsers; //pointer has data type user
	int capacity;
	int usersCount;
public: //functions of class userist //access modifier is public
	UserList();
	UserList(int c);
	void addUser(User user); // adding a user at the end of the array.
	void Display();
	void searchUser(string name);
	void searchUser(int id);
	void deleteUser(int id);
	friend ostream& operator<<(ostream& output, UserList& userList);   //to display
	~UserList();
};
//================================================================================================================
class Book
{
	//Private members of class Book
private: //access modifier is private
	string title;
	string isbn;
	int id;
	string category;
	double averageRating;
	User* author; //pointer named author of class user


public: // class functions //access modifier is public
	static int count;
	Book();
	Book(string, string, string, User* au);
	Book(const Book& book);
	int getcount();
	void setTitle(string tit);
	string getTitle();
	void setISBN(string is);
	string getISBN();
	void setId(int ID);
	int getId();
	double getAvRating();
	void setCategory(string categ);
	string getCategory();
	void setAuthor(User* au);
	User getAuthor();
	void rateBook(int);
	void Print();
	bool operator==(const Book& book);
	friend ostream& operator<<(ostream& output, const Book& book);
	friend istream& operator>>(istream& input, Book& book);
	void printInfo();

};

//================================================================================================================
class BookList
{
private: //members of class booklist //access modifier is private
    Book* arrOfBooks; // pointer of data type book
    int capacity ;
    int bookCount;
public: // functions of class booklist //access modifier is public
    BookList(const BookList& anotherList); //copy constructor
    void copy (const BookList & anotherList);
    BookList(int c);
    void addBook (Book book);
    void assignAuthor(int id);
    void DisplayWithRateBook();
    void searchBook(string name);
    void searchBook(int id);
    void deleteBook(int id); //delete a book
    Book getTheHighestRatedBook();
    Book* getBooksForUser(User); // get all books of this author
    Book & operator [ ] (int position);
    friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
    ~BookList(); //destructor
};

//================================================================================================================
int main()
{
    UserList userListObj(20); //object of class userlist with capacity 20
    BookList bookListObj(20); //object of class booklist with capacity 20
    int choice, id , deleteChoice;
    string name;
    while (true)
        {
    cout << "Select one of the following choices: \n";
    cout << "1- Books Menu\n";
    cout << "2- Users Menu\n";
    cout << "3-Exit\n";
    cin >> choice;
    if ((choice>3) || (choice < 1) )
    {
        cout << "Exiting" ; //exiting the program when the user enter 3
        break;
    }
    switch (choice) { //showing menu using switch statements
    case 1:
        int answer;
        cout << "How many book will be added\n";
        cin >> answer;
        for (int j = 0 ; j< answer ; j++)
        {
            int bookMenuChoice , bookMenuChoice2;
            cout << "BOOKS MENU\n";
            cout <<"1- Create a book and add it to the list\n";
            cout << "2-Search for a book\n";
            cout << "3-Display all books (with book rating)\n";
            cout << "4-Get the highest rating book\n";
            cout << "5-Get all books of a user\n";
            cout << "6-Copy the current Book list to a new book list and switch to it\n";
            cout << "7-Back to the main menu\n";
            cin >> bookMenuChoice;
            if (bookMenuChoice == 1)
            {
                Book bookObj;
                bookListObj.addBook(bookObj);
                cout << "1-Assign author\n";
                cout << "2-continue\n";
                cin>> bookMenuChoice2;
                if (bookMenuChoice2 == 1 )
                {
                    int id;
                    bookListObj.assignAuthor(id);

                }
                else if (bookMenuChoice2 == 2) //return back to book menu
                    continue;
                else
                    break;
            }
            else if (bookMenuChoice == 2)
            {
                int bookSearchChoice;
                cout << "SEARCH FOR A BOOK\n";
                cout << "1-Search by name\n";
                cout << "2-Search by id\n";
                cout << "3-Return to BOOK menu\n";
                cin >> bookSearchChoice ;
                if (bookSearchChoice == 1)
                    {
                        string name2;
                        int xAnswer;
                        bookListObj.searchBook(name2);

                    }
                else if (bookSearchChoice == 2)
                {
                    int id2;
                    bookListObj.searchBook(id2);

                }
            }

            else if (bookMenuChoice == 3)
            {
                bookListObj.DisplayWithRateBook();
            }
            else if (bookMenuChoice == 4)
            {
                bookListObj.getTheHighestRatedBook() ;
            }
            else if  (bookMenuChoice == 5)
            {
                userListObj.searchUser(id);
                bookListObj.DisplayWithRateBook();
            }
            else if (bookMenuChoice == 6)
            {
                //copy elements of the existing array to a new array
                bookListObj.copy(bookListObj);
                cout << "Copied current list (2 books) to a new List and switched to it\n";
            }

            else
                break;

        }
    continue;
    case 2: // if the user chose 2 it will show user menu
        int number;
        cout << "How many user will be added\n";
        cin >> number;
        for (int i = 0; i < number; i++)
        {
            int userMenuChoice;
            cout << "USERS MENU\n";
            cout << "1-Create a USER and add it to the list\n";
            cout << "2-Search for a user\n";
            cout << "3-Display all users\n";
            cout << "4-Back to the main menu\n";
            cin >> userMenuChoice;
            if (userMenuChoice == 1)
            {
                User userObj; //adding user to the end of userlist array
                userListObj.addUser(userObj);
                continue;

            }
            else if (userMenuChoice == 2)
            {
                int userSearchChoice;
                cout << "SEARCH FOR A USER\n";
                cout << "1-Search by name\n";
                cout << "2-Search by id\n";
                cout << "3-Return to Users menu\n";
                cin >> userSearchChoice ;
                if (userSearchChoice == 1)
                {
                    cout << "Enter name\n";
                    cin >> name;
                    userListObj.searchUser(name);
                }
                else if (userSearchChoice == 2 )
                {
                    userListObj.searchUser(id);
                    cout << "1-Delete user\n";
                    cout << "2-Return to the users menu\n" ;
                    cin >> deleteChoice ;
                    if (deleteChoice == 1){
                        userListObj.deleteUser(id);
                        cout << "SEARCH FOR A USER\n";
                        cout << "1-Search by name\n";
                        cout << "2-Search by id\n";
                        cout << "3-Return to Users menu\n";
                        cin >> userSearchChoice ;
                    }
                    else
                        continue; //return to userlist menu
                }
            }
            else if (userMenuChoice == 3)
            {
                userListObj.Display(); //display all users
                continue;
            }
            else
                cout << "===================================\n";
                break;
        }
    case 3:
        break;
    default:
        break;
    }

    }
    return 0;
}


//================================================================================================================

int User::count = 0; //static variable intialized to zero


User::User()
{
	// default constructor
	id = count;
	name = " "; //intialize name to empty string
	age = 0; //intialize age to zero
	password = " "; //intialize password to empty string
	email = " "; //intialize email to empty string
}



User::User(string n, int a, string mail, string pass)
{
	//parameterized constructor
	count++ ;
	id = count ;
	name = n;
	age = a;
	email = mail;
	password = pass;
}

User::User(User& user)
{
	//copy constructor
	count++ ;
	id= count;
	name = user.name;
	age = user.age;
	password = user.password;
	email = user.email;
}

int User::getCount()
{
    count ++ ;
	//Function to get value of the static variable "count"
	return count;
}

void User::setName(string n)
{
	//Function to set value to name
	name = n;
}

string User::getName() const
{
	//Function to get value of name
	return name;
}

void User::setPassword(string pass)
{
	//Function to set value to password
	password = pass;
}

string User::getPassword()
{
	//Function to get value of password
	return password;
}

void User::setEmail(string mail)
{
	//Function to set value to email
	email = mail;
}

string User::getEmail() const
{
	//Function to get value of email
	return email;
}

void User::setAge(int a)
{
	//Function to set value to age
	age = a;
}

int User::getAge() const
{
	//Function to get value of age
	return age;
}

void User::setId(int ID)
{
	//Function to set value to id
	id = (ID >= 0) ? ID : 0; //ternary operator

}

int User::getId()
{
	//Function to get value of id
	return id;
}

void User::Print()
{
    cout << "======= User " << getId() << " info ======= \n";
    cout <<"Name: " << getName() << endl;
    cout <<"Age: " << getAge() << endl ;
    cout <<"Id: " << getId() << endl;
    cout <<"Email: " << getEmail() << endl ;
    cout << "===================================\n";
}

ostream& operator<<(ostream& output, const User& userobj)
{
	//Operator overloading using "<<"
	//Function to output object
	output << "Name: " << userobj.name << endl;
	output << "Age: " << userobj.age << endl;
	output << "Id: " << userobj.id << endl;
	output << "Email: " << userobj.email << endl;
	return output;
}

istream& operator>>(istream& input, User& userobj)
{
	//Operator overloading using ">>"
	//Function to input object
	input >> userobj.name >> userobj.age >> userobj.email >> userobj.password;
	return input;
}

//================================================================================================================

UserList::UserList()
{
    //default constructor
	capacity = 0;
}

UserList::UserList(int c)
{
    //paramaterized constructor
	capacity = c;
	arrOfUsers = new User[c]; //hold a memory of the heap with capacity c
	usersCount = 0;
}


void UserList::addUser(User user)
{
    //function to add user at the end of the userlst array
	cout << "Enter the user information in this order\n";
	cout << "Name Age Email Password (Space separated)\n";
	cin >> user; //add the user
	arrOfUsers[usersCount] = user; //the user now is at index zero. First cell of the array
	usersCount++; //increment the index

}

void UserList::Display()
{
	for (int i = 0 ; i < usersCount; i++ )
	{
			arrOfUsers[i].Print(); //display the users
	}
}


void UserList::searchUser(string name)
{
	for (int i = 0; i < usersCount; i++ )
	{
		if (arrOfUsers[i].getName() == name) //if the name entered equal to name of any user will print the user
		{
			 arrOfUsers[i].Print();

		}
		else
            break; //no identical names
	}
}
void UserList::searchUser(int id)
{
    cout << "Enter User id\n";
    cin >> id ;
     for(int i = 0; i<usersCount ;i++ )
     {
          if(arrOfUsers[i].getId() == id) //if the id entered equal to id of any user will print the user
          {
			  arrOfUsers[i].Print();
          }
          else
            break;
     }
}


void UserList::deleteUser(int id)
{
    for (int i= 0 ; i<usersCount ; i++)
    {
        if (arrOfUsers[i].getId() == id)
        {
            arrOfUsers[i] = arrOfUsers[usersCount-1];
            //arrOfUsers[usersCount-1] = NULL;
            usersCount -- ;
        }
    }
}

ostream& operator<<(ostream& output, UserList& userList)
//operator overloading to print the userlist
{
    for (int i =0 ; i <userList.usersCount ; i++)
        output << userList.arrOfUsers[i];
    return output ;
}

UserList :: ~UserList() //destructor to delete the array
{
    delete [] arrOfUsers ;
}

//================================================================================================================

int Book::count = 0; //intialization of the static variable "count" to zero
//and it will increase with every object created
//the static variable must be intialized outside the class
Book::Book()
{   //default constructor
	//used to give default values
	//count++; //incremental the count
	id = count;
	title = " "; //intialize title to empty string
	isbn = " "; //intialize isbn to empty string
	category = " "; //intialize category to empty string
	averageRating =0; //intialize averageRating to zero
}

Book::Book(string tit, string is, string categ, User* au)
{
    count ++ ;
    id = count ;
	//parameterized constructor
	title = tit;
	isbn = is;
	category = categ;
	author = au;

}
Book::Book(const Book& book)
{

	// copy constructor used to copy the data of an object to another object
	count ++ ;
	id = count ;
	title = book.title;
	isbn = book.isbn;
	category = book.category;
}

int Book::getcount()
{  //function to return value of the static variable count
	return count;
}
/*Setter or Mutator is used to store values or modify values which are already founded
in the attributes*/

/*Getter or Accessor is used to restore values from the the attributes*/

void Book::setTitle(string tit)
{
	//Function to set value to title
	title = tit;
}

string Book::getTitle()
{
	//Function to get value of title
	return title;
}

void Book::setISBN(string is)
{
	//Function to set value to ISBN
	isbn = is;
}

string Book::getISBN()
{
	//Function to get value of ISBN
	return isbn;
}
double Book :: getAvRating()
{
    return averageRating ;
}

void Book::setId(int ID)
{
	//Function to set value to id
	id = (ID >= 0) ? ID : 0; //ternary operator
	// if the id'value greater than zero, set the value to id, if it's not set zero as a value to the id
}

int Book::getId()
{
	//Function to get value of id
	return id;
}

void Book::setCategory(string categ)
{
	//Function to set value to category
	category = categ;
}

string Book::getCategory()
{
	//Function to get value of category
	return category;
}

void Book::setAuthor(User* au)
{
	//ASSOCIATION
	//linking class User with class Book by setting the user as an author of the book
	author = au;
}

User Book::getAuthor()
{
	//Function to get the pointer author feom class User
	return *author;
}
void Book :: Print()
{
      averageRating = 0;
     cout << "======= Book " << getId()<< " info ======= \n";
     cout << "Title: " << title << endl;
	cout <<"ISBN: " << isbn << endl;
	cout <<"Id: " << id << endl;
	cout << "Category: " << category << endl;
	cout << "Avg rating: " << averageRating << endl;
     cout << "===================================\n";
}

double sumOfRatings = 0;
void Book::rateBook(int rating)
{	 //function to update the average rating the class Book
	static int numberOfRatings = 0;
	numberOfRatings++;
	sumOfRatings += rating;
	averageRating = sumOfRatings / numberOfRatings;

}


bool Book::operator==(const Book& book)
{
	//Operator overloading using "=="
	//operator to check if the data of the first book is the same as the data of the second book
	if ((title == book.title) && (isbn == book.isbn) && (category == book.category) && (id == book.id) && (author == book.author))
		return true; // if they are same, return true
	else
		return false; //if they're not, return false
}

void Book::printInfo()
{
	//function to print the information of the book and the author
	averageRating = 0 ;
	cout << "====== Book "<<getId() << "info ======\n";
	cout << "Title: " << title << endl;
	cout <<"ISBN: " << isbn << endl;
	cout <<"Id: " << id << endl;
	cout << "Category: " << category << endl;
	cout << "Avg rating: " << averageRating  << endl;
	cout << endl;
	cout << "====== Author info ====== \n";
	cout << "Name: " << author->getName() << endl;
	cout << "Age: " << author->getAge() << endl;
	cout << "Id: " << author->getId() << endl;
	cout << "Email: " << author->getEmail() << endl;
}


ostream& operator<<(ostream& output, const Book& book)
{
	//Operator overloading using "<<"
	//function created from output stream to output objects including the data
	output << "Title: " << book.title << endl;
	output << "ISBN: " << book.isbn << endl;
	output << "Id: " << book.id << endl;
	output << "Category: " << book.category << endl;
	output << "Avg rating: " << book.averageRating << endl;
	return output;
}

istream& operator>>(istream& input, Book& book)
{
	//Operator overloading using ">>"
	//function created from input stream to input objects
	input >> book.title >> book.isbn >> book.category;
	return input;
}
//================================================================================================================


BookList :: BookList(const BookList& anotherList) //copy constructor
{
    capacity = anotherList.capacity;
    arrOfBooks = new Book[capacity]; // Allocate new memory for copy
    copy(anotherList) ;  // Copy anotherlist's elements
}

void BookList :: copy (const BookList & anotherList)
{
    Book * p ; //pointer of data type book
    p = arrOfBooks ; // pointer p is pointing to the same thing the old array is pointing to
    Book* q ; // pointer of data type book
    q = anotherList.arrOfBooks  ; //pointer q is pointing to the same thing the copied array is pointing to

}


BookList::BookList(int c)
{
    //paramterizied constructor
    capacity = c ;
    arrOfBooks = new Book[capacity]; //hold a new memory on the heap of data type book with capacity c
    bookCount = 0;
}

void BookList ::addBook (Book book)
{
    cout << "Enter the book information in this order\n";
    cout << "Title   ISBN   Category(Space separated)\n";
    cin >> book ; //input book using operator overloading
    arrOfBooks[bookCount] = book ; // make the entered book holds index zero at the booklist
    bookCount ++ ; //increment
}



void BookList :: assignAuthor(int id)
{

    cout << "Enter author (user) id\n";
    cin >> id;
    for (int i=0 ; i<bookCount ; i++)
    {
         Book bookObj;
         User userObj;
         UserList userListObj;
        if (userObj.getId() == id )
        {
          // arrOfBooks[i].setAuthor(userListObj.searchUser(id)) ;
        }
        else
            cout << "No Author found with id= " << id << endl ;
    }
}

void BookList :: searchBook(string name)
{
    cout << "Enter name: " << endl;
    cin >> name;
    for(int i =0; i<bookCount ;i++)
    {

        if(arrOfBooks[i].getTitle() == name)
        {  // if the name entered is equal to any title print this book
            arrOfBooks[i].Print() ;
            while (true)
            {
            int answer ;
            if (answer == 6)
            {
                break;
            } //update menu
            cout << "1-Update author\n";
            cout << "2-Update name\n";
            cout << "3-Update category\n";
            cout << "4-Delete book\n";
            cout <<"5-Rate book\n";
            cout <<"6-Get back to the main menu\n";
            cin >> answer ;
            if (answer == 1)
            {
                User userObj;
                arrOfBooks[i].setAuthor(&userObj) ;
            }

            else if (answer == 2)
            {
                string title;
                cout << "Enter the new title: \n";
                cin >> title ;
                arrOfBooks[i].setTitle(title); //new title instead of old title //validation using set function
            }
            else if (answer == 3)
            {
                string category;
                cout << "Enter the new category: \n";
                cin >> category ;
                arrOfBooks[i].setCategory(category) ; //change category ////validation using set function
            }
            else if (answer == 4 )
            {
                arrOfBooks[i] = arrOfBooks[bookCount-1]; //delete this book instead of updating it
                bookCount -- ;
            }
            else if (answer == 5)
            {
                int rating;
                cout << "Enter rating value: \n" ;
                cin >> rating ;
                arrOfBooks[i].rateBook(rating); //rate the book

            }
            else
                break;
            }

        }
        else
            break;
    }

}

void BookList :: searchBook (int id)
{
    cout << "Enter id: " << endl ;
    cin >> id;
    for (int i=0; i <bookCount ;i++ )
    {
        if(arrOfBooks[i].getId() == id)
        { //print the book if the entered id is equal to an existing id
           arrOfBooks[i].Print();

           }
        else
            break;
    }
}

void BookList :: DisplayWithRateBook()
{
    for (int i =0 ; i<bookCount ; i++ )
    {
        //cout << arrOfBooks[i] ;
       arrOfBooks[i].Print();

    }
}


void BookList :: deleteBook(int id)
{
    cout << "Enter id of the book you want to delete: \n";
    cin >> id;
     for (int i = 0 ; i<bookCount ;i++)
     {

         if (arrOfBooks[i].getId()== id)
         {
             //if the entered id is equal to an existing id
             //delete the book
             arrOfBooks[i] = arrOfBooks[bookCount -1] ;
             //arrOfBooks[bookCount-1] = NULL;
             bookCount -- ;
         }
     }

}

Book BookList :: getTheHighestRatedBook()
{
    int h = 0;
    int max;
    max = arrOfBooks[0].getAvRating(); //assign the value of average rating of the first book to variable max
     for (int i = 0 ; i< bookCount ; i++)
     {
         if ((arrOfBooks[i].getAvRating() > arrOfBooks[i+1].getAvRating()) && (arrOfBooks[i].getAvRating() > max ))
          {
              //if average rating of first book is greater than average rating of second book , and greater than the value of max
              //assign this value to max
             max= arrOfBooks[i].getAvRating() ;
             h = i ; //hold the index to another variable because it will be outside the scope
         }

     }
     return arrOfBooks[h] ;  //return the array of data value book

}
Book &BookList :: operator [ ] ( int position)
{
    //operator overloading subscript is used to access element of arrays
     if ((position < 0) || (position >bookCount))

        cout << "Error" << endl ;
     return arrOfBooks[position] ;

}

ostream &operator <<( ostream &output, BookList &booklist )
{
    //operator overloading to output the booklist
    for (int i=0 ; i < booklist.bookCount ; i++)
    {
        output << booklist.arrOfBooks[i] ;
    }

    return output ;

}

BookList :: ~BookList()
{
    //destructor to delete the array after ending the scope of this class
    delete [] arrOfBooks ;
}
