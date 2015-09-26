//
//  mathODE.cpp
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/5/15.
//
//

#include "mathODE.h"
#include <iostream>

std::vector<double> mathODE::ImprovedEulerStep(double time, std::vector<double> u, double step_size){
    // Gets the slope of the given positions and velocities
    std::vector<double> slope = threeBody::threebodyproblem(time, u);
    
    // Gets the Euler Point by taking u + s*h (s*h gives change in u for the next time step)
    std::vector<double> uEuler = vectorOperations::add(u, vectorOperations::multiply(slope, step_size));
    
    // Gets the slope at the Euler Point
    std::vector<double> new_slope = threeBody::threebodyproblem(time + step_size, uEuler);
    
    // Averages the slopes and obtains the change in positions and velocities
    // du = ((s+s')/2)*h (change in u using the average slope)
    std::vector<double> du = vectorOperations::multiply(vectorOperations::add(slope, new_slope), step_size/2.0);
    
    return du;
    
}