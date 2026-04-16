#include "Plotter.h"
#include <sstream>
#include <string>
#include <iostream>
#include <strlib.h>

using namespace std;

void runPlotterScript(istream& input) {
    bool pendown = 0;
    double xPosition = 0, yPosition = 0;
    double dx = 0, dy = 0;
    double x, y;
    string color;
    double width;
    PenStyle style = { 1, "black" }; // Everything is initialized

    /* TODO: Delete this line and the one after it, then implement this function. */
    for(string line; getline(input, line);){
        istringstream iss(line);
        string command;
        iss >> command;
        command = toLowerCase(command);
        if(command == "pendown"){
            pendown = 1;
        }
        else if(command == "penup"){
            pendown = 0;
        }
        else if(command == "moveabs"){
            iss >> x >> y;
            if(pendown == 1){
                drawLine(xPosition, yPosition, x, y, style);
            }
            xPosition = x;
            yPosition = y;
        }
        else if(command == "moverel"){
            iss >> dx >>dy;
            if(pendown == 1){
                drawLine(xPosition, yPosition, xPosition + dx, yPosition + dy, style);
            }
            xPosition += dx;
            yPosition += dy;
        }
        else if(command == "pencolor"){
            iss >> color;
            style.color = color;
        }
        else if(command == "penwidth"){
            iss >> width;
            style.width = width;
        }

    }
}
