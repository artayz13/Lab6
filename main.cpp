/**
 * Laboratory #6 - CSCI2421 - Summer 2021
 * File: main.cpp
 */

#include "iostream" // For cout and cin
#include "memory"   // for smart (managed) pointers
#include "Movie.h"
#include "StreamingService.h"

using namespace std;

/**********************************************************************************************************************/
int displayMenu(){
    int option=0;
    cout<<endl<<endl;
    cout << "------------------------------------------------" << endl;
    cout << "                    MAIN MENU   " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "      1) Display Streaming Service  " << endl;
    cout << "      2) Checking existence of movie" << endl;
    cout << "      3) List Movie titles sorted   " << endl;
    cout << "      4) Search for movie           " << endl;
    cout << "                            99) Quit" << endl;
    cout << "------------------------------------------------" << endl;
    while (option < 1 || option >4){
        cout << "      Select your option [1-4/99]>> ";
        cin >> option;
        if (option == 99)
            return -1;
    }
    return option;

}
/**********************************************************************************************************************/
/**
 * Displays a movie.
 * @param aMovie
 */
void displayMovie(shared_ptr<Movie>& aMovie){
    cout << aMovie->getTitle() << endl;
}

/**********************************************************************************************************************/
/**
 * Loads the database to myService StreamingService
 * @param myService
 */
void loadDatabase(shared_ptr<StreamingService>& myService){
    myService->addActor("Daniel Radcliffe");
    myService->addActor("Emma Watson");
    myService->addActor("Rupert Grint");
    myService->addActor("Sigourney Weaver");
    myService->addActor("Patrick Stewart");
    myService->addActor("Jonathan Frakes");
    myService->addActor("Tom Cruise");

    cout<< "Adding "<< "Harry Potter and the Philosopher's Stone, "<< 2001 <<"Daniel Radcliffe," <<"Emma Watson," <<"Rupert Grint"<< endl;

    myService->addMovie("Harry Potter and the Philosopher's Stone", 2001);
    myService->addActorToMovie("Harry Potter and the Philosopher's Stone", "Daniel Radcliffe");
    myService->addActorToMovie("Harry Potter and the Philosopher's Stone", "Emma Watson");
    myService->addActorToMovie("Harry Potter and the Philosopher's Stone", "Rupert Grint");

    cout<< "Adding "<< "Harry Potter and the Chamber of Secrets, "<< 2002 <<"Daniel Radcliffe," <<"Emma Watson" << endl;
    myService->addMovie("Harry Potter and the Chamber of Secrets",  2002);
    myService->addActorToMovie("Harry Potter and the Chamber of Secrets", "Daniel Radcliffe");
    myService->addActorToMovie("Harry Potter and the Chamber of Secrets", "Emma Watson");

    cout<< "Adding "<< "Star Trek: First Contact, "<< 1996 <<"Patrick Stewart," <<"Jonathan Frakes" << endl;
    myService->addMovie("Star Trek: First Contact",  1996);
    myService->addActorToMovie("Star Trek: First Contact", "Patrick Stewart");
    myService->addActorToMovie("Star Trek: First Contact", "Jonathan Frakes");


    cout<< "Adding "<< "Oblivion, "<< 2013 <<"Tom Cruise"<< endl;
    myService->addMovie("Oblivion",  2013);
    myService->addActorToMovie("Oblivion", "Tom Cruise");

    cout<< "Adding "<< "Alien, "<< 1979 <<"Sigourney Weaver"<< endl;
    myService->addMovie("Alien",  1979);
    myService->addActorToMovie("Alien", "Sigourney Weaver");
}


/**********************************************************************************************************************/
int main(){
    cout << string(120, '=')  << endl;
    cout << string(50, ' ')<< "LABORATORY #6"  << endl;
    cout << string(120, '=')  << endl;

    auto myService = make_shared<StreamingService>();

    cout<<endl<<endl;
    cout << string(120, '*')  << endl;
    cout << "Loading Database...."<<endl;
    loadDatabase(myService);


    int option = 0;
    string searchMovie;
    string pattern;
    while (option>=0){
        option = displayMenu();
        switch (option) {
            case 1: // Display Streaming Service
                cout << string(120,'*');
                cout << *myService;
                break;

            case 2: // Checking existence of movie.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cin.ignore(1, '\n');

                cout<< "Type movie title (case sensitive)>> ";
                getline(cin, searchMovie);

                cout << "Is " << searchMovie << "in the database? "
                     << boolalpha << myService->isMovieAvailable(searchMovie)<<endl;
                break;

            case 3: //List of movies sorted.
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cout << "Movies -- Sorted by Title" << endl;
                cout << "--------------------------------------------------------" << endl;
                myService->visitMoviesSorted(displayMovie);
                cout << "--------------------------------------------------------" << endl;
                break;

            case 4://Search for movie
                cout<<endl<<endl;
                cout << string(120,'*') << endl;
                cin.ignore(1, '\n');

                cout << "Input title search pattern>>";
                getline(cin, pattern);

                vector<shared_ptr<Movie>> searchMovies = myService->searchMoviePattern(pattern);

                if (searchMovies.empty())
                    cout << "NO Matching Movies Found." << endl;
                else {
                    cout << "Matching Movies" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    for (const auto &movie: searchMovies)
                        cout << *movie << endl;
                    cout << "--------------------------------------------------------" << endl;
                }
                break;
        }
    }
    cout << "Program Terminated." << endl;
    return 0;
}
