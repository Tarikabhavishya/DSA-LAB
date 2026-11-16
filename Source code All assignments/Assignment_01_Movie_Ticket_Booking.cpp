#include <iostream>
#include <string>
using namespace std;

const int MAX_MOVIES = 10;

// Structure for storing movie details
struct Movie
{
     int id;
     string name;
     string time;
     int totalSeats;
     int availableSeats;
};
// Function to display all movies
void displayMovies(Movie movies[], int n)
{
    cout << "\n========== MOVIE LIST ==========\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Movie ID         : " << movies[i].id << endl;
        cout << "Movie Name         : " << movies[i].name << endl;
        cout << "Show Time          : " << movies[i].time << endl;
        cout << "Total Seats : " << movies[i].totalSeats << endl;
   cout << "Available Seats: " << movies[i].availableSeats <<
endl;
        cout << "--------------------------------\n";
    }
}

// Function to search for a movie
int searchMovie(Movie movies[], int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (movies[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// Function to book tickets
void bookTicket(Movie movies[], int n)
{
    int id, tickets;

    cout << "\nEnter Movie ID: ";
    cin >> id;

    int index = searchMovie(movies, n, id);

    if (index == -1)
    {
        cout << "Movie not found!\n";
        return;
    }

    cout << "Movie: " << movies[index].name << endl;
 cout << "Available Seats: " << movies[index].availableSeats
<< endl;

 cout << "Enter number of tickets: ";
 cin >> tickets;

 if (tickets <= 0)
 {
     cout << "Invalid number of tickets!\n";
 }
 else if (tickets > movies[index].availableSeats)
 {
     cout << "Sorry! Not enough seats available.\n";
 }
 else
 {
     movies[index].availableSeats -= tickets;

     cout << "\nTickets booked successfully!\n";
     cout << "Movie Name: " << movies[index].name << endl;
     cout << "Tickets Booked: " << tickets << endl;
     cout << "Remaining Seats: "
        << movies[index].availableSeats << endl;
 }
}

// Function to cancel tickets
void cancelTicket(Movie movies[], int n)
{
    int id, tickets;

    cout << "\nEnter Movie ID: ";
    cin >> id;

    int index = searchMovie(movies, n, id);

    if (index == -1)
    {
        cout << "Movie not found!\n";
        return;
    }

    cout << "Movie: " << movies[index].name << endl;
    cout << "Booked Seats: "
   << movies[index].totalSeats -
movies[index].availableSeats
        << endl;
    cout << "Enter number of tickets to cancel: ";
    cin >> tickets;

    int bookedSeats =
        movies[index].totalSeats - movies[index].availableSeats;

    if (tickets <= 0)
    {
        cout << "Invalid number of tickets!\n";
    }
    else if (tickets > bookedSeats)
    {
        cout << "You cannot cancel more tickets than booked.\n";
    }
    else
    {
        movies[index].availableSeats += tickets;

        cout << "\nTickets cancelled successfully!\n";
        cout << "Tickets Cancelled: " << tickets << endl;
        cout << "Available Seats: "
           << movies[index].availableSeats << endl;
    }
}
// Function to add a new movie
void addMovie(Movie movies[], int &n)
{
    if (n >= MAX_MOVIES)
    {
        cout << "\nMovie list is full!\n";
        return;
    }

    int id;

    cout << "\nEnter Movie ID: ";
    cin >> id;

    // Check whether ID already exists
    if (searchMovie(movies, n, id) != -1)
    {
        cout << "Movie ID already exists!\n";
        return;
    }

    movies[n].id = id;
    cin.ignore();

    cout << "Enter Movie Name: ";
    getline(cin, movies[n].name);

    cout << "Enter Show Time: ";
    getline(cin, movies[n].time);

    cout << "Enter Total Seats: ";
    cin >> movies[n].totalSeats;

    if (movies[n].totalSeats <= 0)
    {
        cout << "Invalid number of seats!\n";
        return;
    }

    movies[n].availableSeats = movies[n].totalSeats;

    n++;

    cout << "\nMovie added successfully!\n";
}
// Function to update movie information
void updateMovie(Movie movies[], int n)
{
    int id;

    cout << "\nEnter Movie ID to update: ";
    cin >> id;

    int index = searchMovie(movies, n, id);

    if (index == -1)
    {
        cout << "Movie not found!\n";
        return;
    }

    cin.ignore();

    cout << "Enter new Movie Name: ";
    getline(cin, movies[index].name);

    cout << "Enter new Show Time: ";
    getline(cin, movies[index].time);
    cout << "\nMovie information updated successfully!\n";
}

// Function to delete a movie
void deleteMovie(Movie movies[], int &n)
{
    int id;

    cout << "\nEnter Movie ID to delete: ";
    cin >> id;

    int index = searchMovie(movies, n, id);

    if (index == -1)
    {
        cout << "Movie not found!\n";
        return;
    }

    // Shift all elements to the left
    for (int i = index; i < n - 1; i++)
    {
        movies[i] = movies[i + 1];
    }
    n--;

    cout << "\nMovie deleted successfully!\n";
}

// Function to sort movies by ID
void sortMovies(Movie movies[], int n)
{
    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (movies[j].id > movies[j + 1].id)
            {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }

    cout << "\nMovies sorted by Movie ID successfully!\n";
}

// Main function
int main()
{
    Movie movies[MAX_MOVIES] =
    {
         {101, "Avengers", "10:00 AM", 100, 100},
         {102, "Inception", "01:00 PM", 80, 80},
         {103, "Interstellar", "04:00 PM", 120, 120},
         {104, "Titanic", "07:00 PM", 150, 150},
         {105, "Avatar", "10:00 PM", 200, 200}
    };

    int n = 5;
    int choice;

    do
    {
   cout <<
"\n====================================\n";
         cout << "    MOVIE TICKET BOOKING SYSTEM\n";
   cout <<
"====================================\n";
         cout << "1. Display Movies\n";
  cout << "2. Search Movie\n";
  cout << "3. Book Tickets\n";
  cout << "4. Cancel Tickets\n";
  cout << "5. Add Movie\n";
  cout << "6. Update Movie\n";
  cout << "7. Delete Movie\n";
  cout << "8. Sort Movies\n";
  cout << "9. Exit\n";
   cout <<
"====================================\n";

  cout << "Enter your choice: ";
  cin >> choice;

  switch (choice)
  {
      case 1:
          displayMovies(movies, n);
          break;

      case 2:
      {
          int id;
    cout << "\nEnter Movie ID to search: ";
    cin >> id;

    int index = searchMovie(movies, n, id);

    if (index == -1)
    {
        cout << "Movie not found!\n";
    }
    else
    {
        cout << "\nMovie Found!\n";
        cout << "Movie ID: "
           << movies[index].id << endl;
        cout << "Movie Name: "
           << movies[index].name << endl;
        cout << "Show Time: "
           << movies[index].time << endl;
        cout << "Available Seats: "
           << movies[index].availableSeats << endl;
    }

    break;
}
case 3:
 bookTicket(movies, n);
 break;

case 4:
 cancelTicket(movies, n);
 break;

case 5:
 addMovie(movies, n);
 break;

case 6:
 updateMovie(movies, n);
 break;

case 7:
 deleteMovie(movies, n);
 break;

case 8:
 sortMovies(movies, n);
 break;
       case 9:
        cout << "\nThank you for using the Movie Ticket "
             "Booking System!\n";
        break;

       default:
        cout << "\nInvalid choice! Please try again.\n";
   }

 } while (choice != 9);

 return 0;
}
