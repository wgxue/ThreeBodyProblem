//
//  planet.h
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/12/15.
//
//

#ifndef __threeBodyProblem__planet__
#define __threeBodyProblem__planet__

#include "ofMain.h"

#include <stdio.h>

#include <vector>
#include "vectorOperations.h"
#include "mathODE.h"

/**
 * Represents a planet
 */
class planet {
public:
    /**
     * Default constructor for a planet
     */
    planet();
    /**
     * Updates the position of this planet to the given coordinates
     *
     * @param x the x coordinate to update this planet to
     * @param y the y coordinate to update this planet to
     */
    void updatePosition(double x, double y);
    /**
     * Gets the current position of this planet
     * @return the position of this planet
     */
    std::vector<double> getPosition();
    /**
     * Draws this planet
     */
    void draw(vector<vector<double> > positions);
    
private:
    /**
     * The position of this planet
     */
    vector<double> position;
    /**
     * A history of positions this planet has taken
     * Primarily used to draw the tail (movement trail) of this planet
     * Should never be longer than the tail length
     */
    vector<vector<double> > history;
    /**
     * The maximum length of the tail (movement trail) of this planet
     */
    static const int TAIL_LENGTH = 150;
    /**
     * The factor by which to scale this planet's location when drawing
     */
    static const int SCALE_FACTOR = 100;
    /**
     * The radius of this planet
     */
    static const int DIAMETER = 20;
    /**
     * Adds the current position of this planet to the history of positions this planet has taken
     */
    void addToHistory();
    /**
     * Removes the first element in the history of positions this planet has taken
     */
    void deleteFromHistory();
    /**
     * Draws the tail (movement trail) of a planet
     * A tail consists of previous locations of a planet drawn in a curve
     * Parts of the tail that overlap another planet are not drawn
     * @param positions the positions of all three planets
     *                  positions[0] -> first planet
     *                      positions[0][0] -> x coordinate of first planet
     *                      positions[0][1] -> y coordinate of first planet
     *                  positions[1] -> second planet
     *                  positions[2] -> third planet
     */
    void drawTail(vector<vector<double> > positions);
    
};

#endif /* defined(__threeBodyProblem__planet__) */
