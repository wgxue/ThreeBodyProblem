//
//  vectorOperations.cpp
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/5/15.
//
//

#include "vectorOperations.h"

std::vector<double> vectorOperations::add(std::vector<double> v1, std::vector<double> v2) {
    std::vector<double> sum;
    // Add the elements of the vectors pairwise
    for (int i=0; i<v1.size(); i++) {
        sum.push_back(v1[i]+v2[i]);
    }
    return sum;
}

std::vector<double> vectorOperations::subtract(std::vector<double> v1, std::vector<double> v2) {
    std::vector<double> difference;
    // Subtract the elements of the vectors pairwise
    for (int i=0; i<v1.size(); i++) {
        difference.push_back(v1[i]-v2[i]);
    }
    return difference;
}

std::vector<double> vectorOperations::multiply(std::vector<double> vect, double constant) {
    std::vector<double> product;
    // Multiply every element of the vector by the scalar
    for (int i=0; i<vect.size(); i++) {
        product.push_back(vect[i] * constant);
    }
    return product;
}

double vectorOperations::norm(std::vector<double> vect) {
    double sum = 0;
    // Calculate the sum of squares of the elements of the vector
    for (int i=0; i<vect.size(); i++) {
        sum += vect[i] * vect[i];
    }
    // Take the square root of this sum of squares to get the norm
    return sqrt(sum);
}
