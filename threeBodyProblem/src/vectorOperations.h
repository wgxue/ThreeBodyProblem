//
//  vectorOperations.h
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/5/15.
//
//

#ifndef __threeBodyProblem__vectorOperations__
#define __threeBodyProblem__vectorOperations__

#include <stdio.h>
#include <vector>
#include <math.h>

/**
 * Contains simple arithmetic operations on vectors
 */
class vectorOperations {
public:
    /**
     * Adds two vectors
     * The vectors are the same size
     * 
     * @param v1 a vector
     * @param v2 the vector to be added to v1
     * @return the sum of the two vectors
     */
    static std::vector<double> add(std::vector<double> v1, std::vector<double> v2);
    /**
     * Subtracts two vectors
     * The vectors are the same size
     *
     * @param v1 a vector
     * @param v2 the vector to be subtracted from v1
     * @return the sum of the two vectors
     */
    static std::vector<double> subtract(std::vector<double> v1, std::vector<double> v2);
    /**
     * Multiplies a vector by a scalar
     *
     * @param v1 a vector
     * @param v2 the scalar to multiply v1 by
     * @return the input vector multiplied by the input scalar
     */
    static std::vector<double> multiply(std::vector<double> vect, double constant);
    
    /**
     * Computes the norm of a vector
     *
     * @param v1 a vector
     * @return the norm of the input vector
     */
    static double norm(std::vector<double> vect);
};

#endif /* defined(__threeBodyProblem__vectorOperations__) */
