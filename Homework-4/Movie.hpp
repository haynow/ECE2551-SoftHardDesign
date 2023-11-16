//
//  Movie.hpp
//  Netflix_1
//
//

#ifndef Movie_hpp
#define Movie_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Movie {
public:

    // Default constructor
    Movie() : year(0), ranking(0) {}

    // Parameterized constructor
    Movie(std::string name, unsigned short year, std::string rating, unsigned short ranking)
        : name(name), year(year), rating(rating), ranking(ranking) {}

    string getName() const {
        return name;
    }
    string getRating() const {
        return rating;
    }

    unsigned short getYear() const {
        return year;
    }

    unsigned short getRanking() const {
        return ranking;
    }

    Movie& setName(std::string newName) {
        name = move(newName);
        return *this;
    }

    Movie& setYear(unsigned short year) {
        if (year < 1900) {
            throw std::invalid_argument("Invalid year");
        }
        this->year = year;
        return *this;
    }

    Movie& setRating(std::string rating) {
        // Check if the rating is valid (you can customize the valid ratings)
        if (rating != "G" && rating != "PG" && rating != "PG-13" && rating != "R" && rating != "NC-17") {
            throw std::invalid_argument("Invalid rating.");
        }
        this->rating = rating;
        return *this;
    }

    Movie& setRanking(unsigned short ranking) {
        if (ranking <= 0 || ranking > 5) { // Adjust the range based on your requirements
            throw std::invalid_argument("Invalid ranking");
        }
        this->ranking = ranking;
        return *this;
    }

    bool operator== (const Movie& rhs) const {
        return (name == rhs.name && year == rhs.year && rating == rhs.rating && ranking == rhs.ranking);
    }

    bool operator<(const Movie& rhs) const {
        return ranking < rhs.ranking;
    }

    bool operator<=(const Movie& rhs) const {
        return ranking <= rhs.ranking;
    }
    bool operator>(const Movie& rhs) const {
        return ranking > rhs.ranking;
    }

    bool operator>=(const Movie& rhs) const {
        return ranking >= rhs.ranking;
    }

private:
    std::string name;
    unsigned short year;
    std::string rating;
    unsigned short ranking;
};

#endif /* Movie_hpp */
