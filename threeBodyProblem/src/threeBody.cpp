//
//  threeBody.cpp
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/5/15.
//
//

#include "threeBody.h"

std::vector<double> threeBody::threebodyproblem(double time, std::vector<double> u){
    // The slope of the current position and velocity vector (consists of velocity and acceleration)
    std::vector<double> du;
    
    // The first planet
    std::vector<double> r1;
    r1.push_back(u[0]);
    r1.push_back(u[1]);
    
    // The second planet
    std::vector<double> r2;
    r2.push_back(u[2]);
    r2.push_back(u[3]);
    
    // The third planet
    std::vector<double> r3;
    r3.push_back(u[4]);
    r3.push_back(u[5]);
    
    // Vectors between pairs of planets
    std::vector<double> r12 = vectorOperations::subtract(r1, r2);
    std::vector<double> r13 = vectorOperations::subtract(r1, r3);
    std::vector<double> r23 = vectorOperations::subtract(r2, r3);
    
    // The cubed distance between pairs of planets
    double r12_3 = pow(vectorOperations::norm(r12), 3);
    double r13_3 = pow(vectorOperations::norm(r13), 3);
    double r23_3 = pow(vectorOperations::norm(r23), 3);
    
    du.push_back(u[6]); // The velocity was already recorded in the previous vector (velocity is the slope of position)
    du.push_back(u[7]);
    du.push_back(u[8]);
    du.push_back(u[9]);
    du.push_back(u[10]);
    du.push_back(u[11]);
    du.push_back(-r12[0]/r12_3 - r13[0]/r13_3); // Calculate the acceleration according to the equation
    du.push_back(-r12[1]/r12_3 - r13[1]/r13_3);
    du.push_back(r12[0]/r12_3 - r23[0]/r23_3);
    du.push_back(r12[1]/r12_3 - r23[1]/r23_3);
    du.push_back(r13[0]/r13_3 + r23[0]/r23_3);
    du.push_back(r13[1]/r13_3 + r23[1]/r23_3);
    
    return du;
}
