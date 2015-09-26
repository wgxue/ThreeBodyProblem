//
//  mathODE.h
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/5/15.
//
//

#ifndef __threeBodyProblem__mathODE__
#define __threeBodyProblem__mathODE__

#include <stdio.h>
#include <vector>
#include "vectorOperations.h"
#include "threeBody.h"

/**
 * Contains a method to in general solve ODEs
 * Currently uses the differential equation of the three body problem
 */
class mathODE {
public:
    /**
     * Computes the changes in positions and velocities of given positions and velocities and a given time step size
     * Uses the Improved Euler method, which is computed by averaging the slope at the given point and the slope at the Euler
     * Point (obtained by foward Euler)
     *
     * @param time the current time
     * @param u a vector containing positions (indices 0 through 5) and velocities (indices 6 through 11)
     * @param step_size the amount of time between time steps (step size) to calculate the next time for calculating s'
     * @return the change in positions (0-5) and velocities (6-11) of the given positions and velocities and the positions
     * and velocities in the next time step
     */
    static std::vector<double> ImprovedEulerStep(double time, std::vector<double> u, double step_size);
};

#endif /* defined(__threeBodyProblem__mathODE__) */
