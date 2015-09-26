//
//  threeBody.h
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/5/15.
//
//

#ifndef __threeBodyProblem__threeBody__
#define __threeBodyProblem__threeBody__

#include <stdio.h>
#include <vector>
#include <math.h>
#include "vectorOperations.h"

/**
 * Contains a function representing the differential equation for the three body problem
 */
class threeBody {
public:
    /** 
     * Computes the slope of a vector of positions and velocities
     * More generally computes the derivative of the elements in the given vector of data
     *
     * @param time the current time
     * @param u a vector containing positions (indices 0 through 5) and velocities (indices 6 through 11)
     * @return a vector containing the velocities (0-5) and accelerations (6-11)
     */
    static std::vector<double> threebodyproblem(double time, std::vector<double> u);
};

#endif /* defined(__threeBodyProblem__threeBody__) */
