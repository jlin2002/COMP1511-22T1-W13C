#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 256

#define SUCCESS 0
#define NOT_FOUND 1

// STRUCT DEFINITIONS

struct movie {
    char title[MAX_STR_LENGTH];
    double rating;
    int length;

    struct movie *next;
};

struct genre {
    char name[MAX_STR_LENGTH];

    struct movie *movies;
    struct genre *next;
};

struct cinema {
    struct genre *genres;
};

// FUNCTION PROTOTYPES
struct cinema *create_cinema();
void add_genre(struct cinema *cinema, char *genre_name);
int add_movie(
    struct cinema *cinema,
    char *genre_name,
    char *movie_title,
    double rating,
    int length
);
void print_genre(struct cinema *cinema, char *genre_name);

// This function has been provided for you to test!
int main(void) {
    struct cinema *cinema = create_cinema();
    
    add_genre(cinema, "Action");
    
    // Will only work after finishing this function!
    add_movie(cinema, "Action", "Scooby Doo", 78.5, 90);
    add_movie(cinema, "Action", "Mission Impossible", 87.2, 93);
    add_movie(cinema, "Drama", "Squid Game", 95.7, 600);
    
    // Will only work after finishing this function!
    print_genre(cinema, "Action");
    print_genre(cinema, "Drama");
}

//
// Creates a new `struct cinema` and returns it.
//
// `create_cinema` takes in no parameters.
//
// `create_cinema` will return a pointer to a new `struct cinema`.
//
struct cinema *create_cinema() {
    struct cinema *new = malloc(sizeof(struct cinema));
    new->genres = NULL;

    return new;
}

//
// Adds a genre to the head of the provided cinema of `genre_name`
//
// `add_genre` takes in these parameters:
// - `cinema` a pointer to the `struct cinema` to add the genre to
// - `genre_name` name of the genre to add to the cinema
//
// `add_genre` returns nothing.
//
// ASSUMPTIONS:
// - `cinema` will always be a valid pointer
// - `genre_name` will always be a valid string of `MAX_STR_LENGTH` size
//
void add_genre(struct cinema *cinema, char *genre_name) {
    struct genre *new = malloc(sizeof(struct genre));
    strcpy(new->name, genre_name);
    new->movies = NULL;
    new->next = NULL;

    new->next = cinema->genres;
    cinema->genres = new;
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////// Implement the functions below! ////////////////////////
////////////////////////////////////////////////////////////////////////////////
struct movie *create_movie(char *movie_title, int length, double rating) {
    struct movie *new_movie = malloc(sizeof(struct movie));
    strcpy(new_movie->title, movie_title);
    new_movie->length = length;
    new_movie->rating = rating;
    new_movie->next = NULL;
    return new_movie;
}

struct genre *find_genre(struct cinema *cinema, char *genre_name) {
    struct genre *curr_genre = cinema->genres;
    while (curr_genre != NULL && strcmp(curr_genre->name, genre_name) != 0) {
        curr_genre = curr_genre->next;
    }
    return curr_genre;
}
//
// Adds a movie to the end of the desired genre in the desired cinema.
//
// `add_movie` takes in these parameters:
// - `cinema` - a pointer to the `struct cinema` to add the movie to
// - `genre_name` - name of the desired genre for the movie to add to the cinema
// - `movie_title` - name of the movie to add to the genre
// - `rating` - Rating /100 of the provided movie
// - `length` - Length (in minutes) of the provided movie
//
// `add_movie` returns, in order of precedence:
// `NOT_FOUND` if genre was not found in cinema
// `SUCCESS` if movie is added
//
// ASSUMPTIONS:
// - `cinema` will always be a valid pointer
// - `genre_name` will always be a valid string of `MAX_STR_LENGTH` size
// - `movie_title` will always be a valid string of `MAX_STR_LENGTH` size
// - `rating` will always be a positive integer between [0, 10] inclusive
// - `length` will always be a positive number
//
int add_movie(
    struct cinema *cinema,
    char *genre_name,
    char *movie_title,
    double rating,
    int length
) {
    struct genre *genre = find_genre(cinema, genre_name);
    if (genre == NULL) {
        return NOT_FOUND;
    }
    struct movie *new_movie = create_movie(movie_title, length, rating);
    if (genre->movies == NULL) {
        genre->movies = new_movie;
        return SUCCESS;
    }
    struct movie *curr_movie = genre->movies;
    while (curr_movie->next != NULL) {
        curr_movie = curr_movie->next;
    }
    curr_movie->next = new_movie;
    return SUCCESS;
}

//
// Prints all the movies in the desired genre
//
// Each movie of the genre is printed on a new line in the format:
//
// <movie1-TITLE>, <movie1-RATING>/10 (<movie1-LENGTH> minutes)
// <movie2-TITLE>, <movie2-RATING>/10 (<movie2-LENGTH> minutes)
// <movie3-TITLE>, <movie3-RATING>/10 (<movie3-LENGTH> minutes)
// ...
//
// `print_genre` takes in these parameters:
// - `cinema` a pointer to the `struct cinema` to print the genre
// - `genre_name` name of the desired genre to print in the cinema
//
// `print_genre` returns nothing.
//
// ASSUMPTIONS:
// - `cinema` will always be a valid pointer
// - `genre_name` will always be a valid string of `MAX_STR_LENGTH` size
void print_genre(struct cinema *cinema, char *genre_name) {
    struct genre *genre = find_genre(cinema, genre_name);
    if (genre == NULL) {
        return;
    }

    struct movie *curr_movie = genre->movies;
    while (curr_movie != NULL) {
        printf("%s, %.1lf/10 (%d)\n",
            curr_movie->title, curr_movie->rating, curr_movie->length);
        curr_movie = curr_movie->next;
    }
}
