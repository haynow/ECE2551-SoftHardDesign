//
//  main.cpp
//  Netflix_1
//
//  Created by Xavier Merino on 10/23/16.
//  Copyright © 2016 Xavier Merino. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdexcept>
#include <iostream>
#include "DoublyLinkedList.hpp"
#include "Movie.hpp"

TEST_CASE("Testing Movie Setters and Getters"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    
    REQUIRE(movie1.getName() == "A");
    REQUIRE(movie2.getName() == "B");
    REQUIRE(movie3.getName() == "C");
    
    REQUIRE(movie1.getYear() == 2010);
    REQUIRE(movie2.getYear() == 2011);
    REQUIRE(movie3.getYear() == 2012);
    
    REQUIRE(movie1.getRating() == "PG");
    REQUIRE(movie2.getRating() == "PG-13");
    REQUIRE(movie3.getRating() == "PG");
    
    REQUIRE(movie1.getRanking() == 1);
    REQUIRE(movie2.getRanking() == 5);
    REQUIRE(movie3.getRanking() == 4);
    
    movie1.setName("A2").setYear(2011).setRating("PG").setRanking(2);
    REQUIRE(movie1.getName() == "A2");
    REQUIRE(movie1.getYear() == 2011);
    REQUIRE(movie1.getRating() == "PG");
    REQUIRE(movie1.getRanking() == 2);
}

TEST_CASE("Testing Movie: Year Exception"){
    Movie movie1("A", 2010, "PG", 1);
    REQUIRE_THROWS_AS(movie1.setYear(1800), std::invalid_argument);
    REQUIRE_NOTHROW(movie1.setYear(2011));
    REQUIRE(movie1.getYear() == 2011);
}

TEST_CASE("Testing Movie: Ranking Exception"){
    Movie movie1("A", 2010, "PG", 1);
    REQUIRE_THROWS_AS(movie1.setRanking(0), std::invalid_argument);
    REQUIRE_THROWS_AS(movie1.setRanking(6), std::invalid_argument);
    REQUIRE_THROWS_AS(movie1.setRanking(-1), std::invalid_argument);
    REQUIRE_NOTHROW(movie1.setRanking(1));
    REQUIRE_NOTHROW(movie1.setRanking(2));
    REQUIRE_NOTHROW(movie1.setRanking(3));
    REQUIRE_NOTHROW(movie1.setRanking(4));
    REQUIRE_NOTHROW(movie1.setRanking(5));
    REQUIRE(movie1.getRanking() == 5);
}

TEST_CASE("Testing Movie: Rating Exception"){
    Movie movie1("A", 2010, "PG", 1);
    REQUIRE_THROWS_AS(movie1.setRating("P"), std::invalid_argument);
    REQUIRE_THROWS_AS(movie1.setRating("13"), std::invalid_argument);
    REQUIRE_THROWS_AS(movie1.setRating("Banned"), std::invalid_argument);
    REQUIRE(movie1.getRating() == "PG");
    REQUIRE_NOTHROW(movie1.setRating("NC-17"));
    REQUIRE(movie1.getRating() == "NC-17");
}

TEST_CASE("Testing Movie: Operator =="){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    
    REQUIRE(!(movie1 == movie2));
    
    movie3.setName("A").setYear(2010).setRating("PG").setRanking(2);
    
    REQUIRE(movie1 == movie3);
}

TEST_CASE("Testing Movie: Operator >, <, >=, <="){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    
    REQUIRE((movie1 < movie2) == true);
    REQUIRE((movie1 <= movie2) == true);
    REQUIRE((movie2 > movie3) == true);
    REQUIRE((movie2 >= movie3) == true);
    REQUIRE((movie1 > movie3) == false);
}

TEST_CASE("Testing DoublyLinkedList: insert(), getHead()"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 2);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 3);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list.getHead().getName() == "A");
}

TEST_CASE("Testing DoublyLinkedList: insert(), getTail()"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 2);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 3);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list.getTail().getName() == "J");
}

TEST_CASE("Testing DoublyLinkedList: insert(), size()"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 2);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 3);
    
    DoublyLinkedList<Movie> list;
    
    REQUIRE(list.size() == 0);
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);

    REQUIRE(list.size() == 5);
    
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list.size() == 10);
}

TEST_CASE("Testing DoublyLinkedList: insert() - Edits"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 2);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 3);
    
    Movie movie1b("A", 2010, "PG", 3);
    
    DoublyLinkedList<Movie> list;
    
    REQUIRE(list.size() == 0);
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    
    REQUIRE(list.size() == 5);
    
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list.size() == 10);
    
    list.insert(movie1b);
    REQUIRE(list.size() == 10);
    REQUIRE(list[0].getRanking() == 3);
    
}

TEST_CASE("Testing DoublyLinkedList: isEmpty()"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    
    DoublyLinkedList<Movie> list;
    
    REQUIRE(list.isEmpty() == true);

    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    
    REQUIRE(list.isEmpty() == false);
}

TEST_CASE("Testing DoublyLinkedList: Operator []"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 2);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 3);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list[0].getName() == "A");
    REQUIRE(list[2].getName() == "C");
    REQUIRE(list[4].getName() == "E");
    REQUIRE(list[6].getName() == "G");
    REQUIRE(list[1].getRanking() == 5);
    REQUIRE(list[3].getRanking() == 3);
    REQUIRE(list[5].getRanking() == 1);
    REQUIRE(list[7].getRanking() == 2);
}


TEST_CASE("Testing DoublyLinkedList: Find"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    
    REQUIRE(list.find(movie1) == 0);
    REQUIRE_THROWS_AS(list.find(movie6), std::exception);
    
    list.insert(movie6);
    
    REQUIRE_NOTHROW(list.find(movie6));
}


TEST_CASE("Testing DoublyLinkedList: Erase"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 2);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 3);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list.size() == 10);
    
    for (int i = 0; i < 5; i++){
        list.erase(0);
    }
    
    REQUIRE(list.size() == 5);
    REQUIRE(list[0].getName() == "F");
    REQUIRE(list.getHead().getName() == "F");
    REQUIRE(list.getTail().getName() == "J");
}

TEST_CASE("Testing DoublyLinkedList: Find and Erase"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 2);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 3);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list.size() == 10);
    
    list.erase(list.find(movie3));
    list.erase(list.find(movie4));
    
    REQUIRE(list.size() == 8);
    
    REQUIRE_THROWS_AS(list.find(movie3), std::exception);
    
    REQUIRE(list.size() == 8);
    
    list.erase(list.find(movie1));
    list.erase(list.find(movie2));
    REQUIRE_THROWS_AS(list.find(movie3), std::exception);
    REQUIRE_THROWS_AS(list.find(movie4), std::exception);
    list.erase(list.find(movie5));
    list.erase(list.find(movie6));
    list.erase(list.find(movie7));
    list.erase(list.find(movie8));
    list.erase(list.find(movie9));
    
    REQUIRE(list.size() == 1);
    REQUIRE(list[0].getName() == "J");
    REQUIRE(list.getHead().getName() == "J");
    REQUIRE(list.getTail().getName() == "J");
    
}

TEST_CASE("Testing DoublyLinkedList: sort() - 1"){
    Movie movie6("F", 2012, "PG", 1);
    Movie movie7("G", 2013, "PG", 2);
    Movie movie8("H", 2014, "PG", 4);
    Movie movie9("I", 2015, "R", 3);
    Movie movie10("J", 2016, "R", 5);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie6);
    list.insert(movie7);
    list.insert(movie8);
    list.insert(movie9);
    list.insert(movie10);
    
    REQUIRE(list.size() == 5);
    
    list.sort();
    
    REQUIRE(list[0].getName() == "F");
    REQUIRE(list[1].getName() == "G");
    REQUIRE(list[2].getName() == "I");
    REQUIRE(list[3].getName() == "H");
    REQUIRE(list[4].getName() == "J");
}

TEST_CASE("Testing DoublyLinkedList: sort() - 2"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    
    REQUIRE(list.size() == 5);
    
    list.sort();
    
    REQUIRE(list[0].getName() == "A");
    REQUIRE(list[1].getName() == "E");
    REQUIRE(list[2].getName() == "D");
    REQUIRE(list[3].getName() == "C");
    REQUIRE(list[4].getName() == "B");
}

TEST_CASE("Testing DoublyLinkedList: Exceptions"){
    Movie movie1("A", 2010, "PG", 1);
    Movie movie2("B", 2011, "PG-13", 5);
    Movie movie3("C", 2012, "PG", 4);
    Movie movie4("D", 2013, "R", 3);
    Movie movie5("E", 2014, "R", 2);
    Movie movie6("F", 2012, "PG", 1);
    
    DoublyLinkedList<Movie> list;
    
    list.insert(movie1);
    list.insert(movie2);
    list.insert(movie3);
    list.insert(movie4);
    list.insert(movie5);
    
    REQUIRE(list.size() == 5);
    
    REQUIRE_THROWS_AS(list[5], std::out_of_range);
    
    list.insert(movie6);
    
    REQUIRE_NOTHROW(list[5]);
}


TEST_CASE("Testing DoublyLinkedList: Integers"){
    DoublyLinkedList<int> list;
    
    int a = 3;
    int b = 2;
    int c = 1;
    
    list.insert(a);
    list.insert(b);
    list.insert(c);
    
    REQUIRE(list.size() == 3);
    REQUIRE(list[0] == 3);
}
