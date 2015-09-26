//
//  planet.cpp
//  threeBodyProblem
//
//  Created by Minami Hamanaka on 8/12/15.
//
//

#include "planet.h"
#include "vectorOperations.h"

planet::planet() {
    // By default, initially a planet starts at the center of the screen
    position.push_back(0);
    position.push_back(0);
}

void planet::updatePosition(double x, double y) {
    // update the position to the specified coordinates
    position[0] = x;
    position[1] = y;
    
    // add the current position to the tail
    addToHistory();
    
    // if our tail is too long, cut off the "oldest element" (that shouldn't be in the tail)
    // we want recent elements to be in the tail
    if (history.size() > TAIL_LENGTH) {
        deleteFromHistory();
    }
}

std::vector<double> planet::getPosition() {
    return position;
}

void planet::draw(vector<vector<double> > positions) {
    // Hollow circle to represent planets
    ofNoFill();
    
    // Draw the tail
    drawTail(positions);
    
    // Draw the planet at this point in time
    ofEllipse(SCALE_FACTOR*position[0] + ofGetWindowWidth()/2.0, SCALE_FACTOR*position[1] + ofGetWindowHeight()/2.0, DIAMETER,DIAMETER);
}

void planet::drawTail(vector<vector<double> > positions) {
    // Draw the tail
    // Go through potential points in the tail
    // Draw each of the points in the history to make up the tail and don't overlap a planet (points have radius 1)
    for (int i = 0; i < history.size(); i++) {
        // The current point is always initially not overlapping any planet
        bool overlapping = false;
        // Check if the current point overlaps any planet
        for (int j = 0; j < positions.size(); j++) {
            vector<double> scaled_current_tail_point = vectorOperations::multiply(history[i], SCALE_FACTOR);
            vector<double> scaled_current_position = vectorOperations::multiply(positions[j], SCALE_FACTOR);
            // A point is overlapping if it is within a radius from the center of the planet
            if (vectorOperations::norm(vectorOperations::subtract(scaled_current_tail_point, scaled_current_position)) < DIAMETER/2.0) {
                overlapping = true;
            }
        }
        
        if (!overlapping) { // Only draw the tail point if it doesn't overlap a planet
            ofEllipse(SCALE_FACTOR*history[i][0] + ofGetWindowWidth()/2.0, SCALE_FACTOR*history[i][1] + ofGetWindowHeight()/2.0, 1,1);
        }
    }
}

void planet::addToHistory() {
    history.push_back(position);
}

void planet::deleteFromHistory() {
    // Erase the first element from the history
    history.erase(history.begin());
}