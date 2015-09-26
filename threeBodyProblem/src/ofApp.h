#pragma once

#include "ofMain.h"

#include <vector>
#include "vectorOperations.h"
#include "mathODE.h"
#include "planet.h"

// ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡
// ♡ I LOVE YOU, MINAMI  ♡
// ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡ ♡
class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    // The three planets
    planet planet_1;
    planet planet_2;
    planet planet_3;
    
    // Keep track of the time (multiples of time steps)
    // To be used in calculating velocities and positions
    double time;
    
    /* Keep track of the current velocities and positions of the planets
     * Elements 0 and 1 are the x and y coordinates of the first planet
     * Elements 2 and 3 are the x and y coordinates of the second planet
     * Elements 4 and 5 are the x and y coordinates of the third planet
     * Elements 6 and 7 are the x and y components of the velocity of the first planet
     * Elements 8 and 9 are the x and y components of the velocity of the second planet
     * Elements 10 and 11 are the x and y components of the velocity of the third planet
     */
    vector<double> current_u;
};
