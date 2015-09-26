#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0,0,0); // black background
    
    // Initialize the vector of initial positions and velocities (of planets)
    current_u.push_back(-0.7); // x coordinate of the first planet
    current_u.push_back(0.36); // y coordinate of the first planet
    current_u.push_back(1.1); // second planet
    current_u.push_back(-0.07);
    current_u.push_back(-0.4); // third planet
    current_u.push_back(-0.3);
    current_u.push_back(0.99); // x velocity of the first planet
    current_u.push_back(0.078); // y velocity of the first planet
    current_u.push_back(0.1); // second planet
    current_u.push_back(0.47);
    current_u.push_back(-1.1); // third planet
    current_u.push_back(-0.53);
    
    // Initialize the positions of the planets according to the above specification
    planet_1.updatePosition(current_u[0], current_u[1]);
    planet_2.updatePosition(current_u[2], current_u[3]);
    planet_3.updatePosition(current_u[4], current_u[5]);
    
    // Time starts at 0
    time = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    const double step_size = 0.01; // Use a step size of 0.01
    
    // Compute the new vector of velocities and positions
    // Applies the result of the Improved Euler step (approximating the change in position and velocities)
    // to the previous position and velocities (sums the two)
    vector<double> new_u = vectorOperations::add(current_u, mathODE::ImprovedEulerStep(time, current_u, step_size));
    
    // Updates the variable we use to keep track of the current velocities and positions with the new one we just calculated
    current_u.clear();
    current_u.push_back(new_u[0]); // first planet position
    current_u.push_back(new_u[1]);
    current_u.push_back(new_u[2]); // second planet position
    current_u.push_back(new_u[3]);
    current_u.push_back(new_u[4]); // third planet position
    current_u.push_back(new_u[5]);
    current_u.push_back(new_u[6]); // first planet velocity
    current_u.push_back(new_u[7]);
    current_u.push_back(new_u[8]); // second planet velocity
    current_u.push_back(new_u[9]);
    current_u.push_back(new_u[10]); // third planet velocity
    current_u.push_back(new_u[11]);
    
    // Update the positions of the planets to the newly calculated positions according to the above specifications
    planet_1.updatePosition(current_u[0], current_u[1]);
    planet_2.updatePosition(current_u[2], current_u[3]);
    planet_3.updatePosition(current_u[4], current_u[5]);
    
    // The time has advanced by the step size (one time step)
    time += step_size;
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Get the positions of all three planets (for tail-planet overlap checking)
    vector<vector<double> > positions;
    positions.push_back(planet_1.getPosition());
    positions.push_back(planet_2.getPosition());
    positions.push_back(planet_3.getPosition());
    
    // Draws each individual planet
    planet_1.draw(positions);
    planet_2.draw(positions);
    planet_3.draw(positions);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
