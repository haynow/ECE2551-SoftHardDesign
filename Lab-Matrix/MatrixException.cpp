//
//  MatrixException.cpp
//  Matrix-2
//
//

#include <stdio.h>
#include <string>
#include "MatrixException.hpp"

std::string eventTable[] = {
    "No Error",
    "Successfully caught the divide by zero error!",
    "Successfully caught the dimensions' mismatch error!",
    "Successfully caught the matrix not being square error!",
    "Successfully caught the out of bounds error!"
};

MatrixException::MatrixException(unsigned int key, std::string filePath, unsigned int lineNumber){
    // Error Checking:
    // If key > number of error keys then description is Invalid Event Key
    // Otherswise use the key to extract the description from the eventTable array.
    
    // Save the key into errorKey.
    // Save the filePath into the filePath data member.
    // Save the lineNumber into the lineNumber data member.

}

// Implement getKey(), getDescription(), getFilePath(), getLineNumber()
