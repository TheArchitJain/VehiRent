#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unistd.h> //for sleep()
#include <stdlib.h> // for system("cls")
#include <utility>  //for vector pair

using namespace std;
void login();
void signup();
void forgot();
void calculatefare();
int book();
int anotherCar();
void rideType();
void rentalCar();

struct Car
{
    string name;
    int count;
};

int main()
{
    cout << "\t\t\t________________________________________________________\n\n";
    cout << "\t\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t\t__________________      MENU      ______________________\n\n";
    cout << "                                                                                \n\n";
    cout << "\t | Press 1 to Login                 | " << endl;
    cout << "\t | Press 2 to Signup                | " << endl;
    cout << "\t | Press 3 if you Forgot Password   | " << endl;
    cout << "\t | Press 4 to Exit                  | " << endl;
    cout << "\t Please Enter Your Choice  : " << endl;
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t\t Thank You!  \n\n"
             << endl;
        break;
    default:
        cout << "Please Enter the choice from given above." << endl;
        sleep(5);
        main();
    }
}
void login()
{
    int count = 0;
    string username, password, id, pass;
    system("cls");
    cout << "\t\t________________________________________________________\n\n";
    cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t__________________      LOGIN      ______________________\n\n";
    cout << "                                                                                \n\n"
         << endl;
    cout << "Please Enter Your Username and Password : " << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    ifstream input("test.txt"); // opening database file
    while (input >> id >> pass)
    {
        if (id == username && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << username << " You have Successfully Logged In" << endl;
        rideType();
    }
    else
    {
        cout << "Login Failed. Please Check your Username and password" << endl;
        main();
    }
}
void signup()
{
    string username, password;
    system("cls");
    cout << "\t\t________________________________________________________\n\n";
    cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t__________________      SIGNUP      ______________________\n\n";
    cout << "                                                                                \n\n"
         << endl;
    cout << "Please Enter the Username and Password to Signup : " << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    ofstream reg("test.txt", ios::app);         // opening database.txt file (write inside file)
    reg << username << ' ' << password << endl; // writing to database.txt (username and password)
    cout << "You have Successfully Signed Up" << endl;
    main();
}
void forgot()
{
    int ch;
    system("cls");
    cout << "\t\t________________________________________________________\n\n";
    cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
    cout << "\t\t__________________      FORGOT PASSWORD      ______________________\n\n";
    cout << "                                                                                \n\n"
         << endl;
    cout << "Press 1 to Reset Password" << endl;
    cout << "Press 2 to go back to Main Menu" << endl;
    cout << "Enter your choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        system("cls");
        int count = 0;
        string username, password, id, pass;
        cout << "\t\t________________________________________________________\n\n";
        cout << "\t\t     Welcome to VehiRent - Your Personal Cab Service     \n\n";
        cout << "\t\t__________________      RESET PASSWORD      ______________________\n\n";
        cout << "                                                                                \n\n"
             << endl;
        cout << "Please Enter the Username You remembered : ";
        cin >> username;
        ifstream input("test.txt"); // opening database.txt file
        while (input >> id >> pass)
        {
            if (id == username)
            {
                count = 1;
            }
        }
        input.close();
        if (count == 1)
        {
            cout << "Your Account is found !" << endl;
            cout << "Your Password is : " << pass << endl;
            main();
        }
        else
        {
            cout << "Username not found" << endl;
            main();
        }
        break;
    }
    case 2:
        main();
    default:
        cout << "Please Enter the choice from given above." << endl;
        forgot();
    }
}

// Round trip or day trip

void rideType()
{
    int choice;
    cout << "Press 1 to Book a Rental Car!" << endl;
    cout << "Press 2 to Book a Single Ride!" << endl;
    cin >> choice;
    if (choice == 1)
    {
        rentalCar();
    }
    else if (choice == 2)
    {
        book();
    }
    else
    {
        cout << "Invalid input. Please select a valid option." << endl;
        rideType();
    }
}
string source, destination;
void car()
{
    cout << "Enter the source : ";
    cin >> source;
    cout << "Enter the destination : ";
    cin >> destination;
}
vector<Car> cars = {
    {"Micro", 5},
    {"Mini", 5},
    {"Sedan", 5},
    {"SUV", 5},
    {"Luxury", 5}};

void display()
{
    cout << "Enter the type of car you want to book : " << endl;
    for (int i = 0; i < cars.size(); i++)
    {
        cout << i + 1 << ". " << cars[i].name << " (" << cars[i].count << " available)" << endl;
    }
}

int anotherCar()
{
    cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;

    int x;
    cout << "Do you want to book another Ride? " << endl;
    cout << "Press 1 to book another Ride" << endl;
    cout << "Press 2 to exit" << endl;
    cin >> x;
    if (x == 2)
    {
        exit(0);
    }
    else if (x == 1)
    {
        rideType();
    }
    else
    {
        cout << "Invalid input. Please select a valid option." << endl;
    }
    return 0;
}

int a;
int book()
{
    car();
    int carChoice;

    while (true)
    {
        cout << endl;
        display();
        cout << endl;
        cout << "Enter your choice: ";
        cin >> carChoice;

        if (carChoice > 0 && carChoice <= cars.size())
        {
            if (cars[carChoice - 1].count > 0)
            {
                cout << "You have selected " << cars[carChoice - 1].name << " car" << endl;
                a = carChoice;
                calculatefare();
                cars[carChoice - 1].count--; // Decrease count of selected car
                anotherCar();
            }
            else
            {
                cout << "No more " << cars[carChoice - 1].name << " cars available. Please choose another type." << endl;
            }
        }
    }
    return 0;
}

// Rental Car
void rentalCar()
{
    int choice;
    int days;
    int charges;
    int n;
    int s;
    cout << endl;
    cout << "____________TERMS AND CONDITIONS:_____________" << endl;
    cout << endl;
    cout << "1. You will be charged 500/-Rs per day + No. of kms car run." << endl;
    cout << "2. Car will run for maximum 16 hours per day." << endl;
    cout << "Enter the number of days you want to book the car for : " << endl;
    cin >> days;
    cout << endl;
    display();
    cout << endl;
    cout << "Enter your choice: ";
    cin >> n;
    if (n > 5 || n < 1)
    {
        cout << "Invalid input. Please select a valid option." << endl;
        rentalCar();
    }
    cout << "You have selected " << cars[n - 1].name << " car" << endl;
    cout << endl;
    cout << "Press 1 to confirm your booking" << endl;
    cout << "Press 2 to cancel your booking" << endl;
    cin >> s;
    if (s == 1)
    {
        cout << endl;
        cout << "Your Booking is confirmed" << endl;
        cout << "Thank You for using VehiRent" << endl;
        cars[n - 1].count--;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << endl;
        cout << "Your Booking is cancelled" << endl;
        cout << "Thank You for using VehiRent" << endl;
        cout << "Press 1 to go back to main menu" << endl;
        cout << "Press 2 to exit" << endl;
        int h;
        cin >> h;
        if (h == 1)
        {
            system("cls");
            rideType();
        }
        else if (h == 2)
        {
            cout << "Thank You for using VehiRent" << endl;
            exit(0);
        }
        else
        {
            cout << "Please enter the choice from given above" << endl;
            rideType();
        }
    }
    cout << "Enter total number of kms: ";
    cin >> choice;
    cout << endl;
    if (cars[n - 1].name == "Micro")
    {

        cout << "You will be charged for " << days << " days." << endl;
        cout << "Your total fare is : " << (days * 500) + (choice * 10) << endl;
    }
    else if (cars[n - 1].name == "Mini")
    {
        cout << "You will be charged for " << days << " days." << endl;
        cout << "Your total fare is : " << (days * 500) + (choice * 15) << endl;
    }
    else if (cars[n - 1].name == "Sedan")
    {
        cout << "You will be charged for " << days << " days." << endl;
        cout << "Your total fare is : " << (days * 500) + (choice * 20) << endl;
    }
    else if (cars[n - 1].name == "SUV")
    {
        cout << "You will be charged for " << days << " days." << endl;
        cout << "Your total fare is : " << (days * 500) + (choice * 25) << endl;
    }
    else if (cars[n - 1].name == "Luxury")
    {
        cout << "You will be charged for" << days << " days." << endl;
        cout << "Your total fare is : " << (days * 500) + (choice * 30) << endl;
    }
    else
    {
        cout << "Invalid input. Please select a valid option." << endl;
        anotherCar();
    }
    cout << "-------------------------Thank You for using VehiRent-----------------------------" << endl;
    cout << "Press 1 to go back to main menu" << endl;
    cout << "Press 2 to exit" << endl;
    int h;
    cin >> h;
    if (h == 1)
    {
        system("cls");
        rideType();
    }
    else if (h == 2)
    {
        cout << "Thank You for using VehiRent" << endl;
        exit(0);
    }
    else
    {
        cout << "Please enter the choice from given above" << endl;
        rideType();
    }
}
void calculatefare()
{

    int km, fare;
    transform(source.begin(), source.end(), source.begin(), ::tolower);
    transform(destination.begin(), destination.end(), destination.begin(), ::tolower);

    cout << "You are booking your ride from " << source << " to " << destination << endl;
    if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1].name == "Micro")
    {
        km = 70;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1].name == "Mini")
    {
        km = 70;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1].name == "Sedan")
    {
        km = 70;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1].name == "SUV")
    {
        km = 70;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "meerut") || (source == "meerut" && destination == "delhi")) && cars[a - 1].name == "Luxury")
    {
        km = 70;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1].name == "Micro")
    {
        km = 30;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1].name == "Mini")
    {
        km = 30;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1].name == "Sedan")
    {
        km = 30;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1].name == "SUV")
    {
        km = 30;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "gurugram") || (source == "gurugram" && destination == "delhi")) && cars[a - 1].name == "Luxury")
    {
        km = 30;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1].name == "Micro")
    {
        km = 50;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1].name == "Mini")
    {
        km = 50;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1].name == "Sedan")
    {
        km = 50;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1].name == "SUV")
    {
        km = 50;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "noida") || (source == "noida" && destination == "delhi")) && cars[a - 1].name == "Luxury")
    {
        km = 50;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1].name == "Micro")
    {
        km = 40;
        fare = km * 10;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1].name == "Mini")
    {
        km = 40;
        fare = km * 15;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1].name == "Sedan")
    {
        km = 40;
        fare = km * 20;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1].name == "SUV")
    {
        km = 40;
        fare = km * 25;
        cout << "Your fare is : " << fare << endl;
    }
    else if (((source == "delhi" && destination == "ghaziabad") || (source == "ghaziabad" && destination == "delhi")) && cars[a - 1].name == "Luxury")
    {
        km = 40;
        fare = km * 30;
        cout << "Your fare is : " << fare << endl;
    }
    else
    {
        cout << "No Rides Available right now Please TRY AGAIN " << endl;
        book();
    }
    cout << endl;
    cout << "Do You Want to confirm your booking ?" << endl;
    cout << "Press 1 to confirm" << endl;
    cout << "Press 2 to cancel" << endl;
    cout << endl;
    int ch;
    cin >> ch;
    if (ch == 1)
    {
        cout << "Your booking is confirmed" << endl;
        cout << "Your ride will arrive in 5 minutes" << endl;
        cout << "Thank You for using VehiRent" << endl;
        cout << endl;
    }
    else
    {
        cout << "Your booking is cancelled" << endl;
        cout << "Thank You for using VehiRent" << endl;
        cout << endl;
        cout << "Press 1 to go back to main menu" << endl;
        cout << "Press 2 to exit" << endl;
        int h;
        cin >> h;
        if (h == 1)
        {
            system("cls");
            rideType();
        }
        else if (h == 2)
        {
            cout << "Thank You for using VehiRent" << endl;
            exit(0);
        }
        else
        {
            cout << "Please enter the choice from given above" << endl;
            book();
        }
    }
}
