#include "Image_Class.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm> 
#include <random> 

using namespace std;


void addFrameFilter(Image& image)
{
    //20242201

    int chice;
    cout << "Choose frame type:\n";
    cout << "[1] Simple Frame\n";
    cout << "[2]  Fancy Frame\n";
    cout << "Enter your choice: ";
    cin >> chice;

    if (chice != 1 && chice != 2) {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
        return;
    }


    int thickness = image.width / 50;
    unsigned char redFrame = 50, greenFrame = 0, blueFrame = 255;
    unsigned char redPattern = 200, greenPattern = 155, bluePattern = 0;

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {

            if (i < thickness || i >= image.width - thickness || j < thickness || j >= image.height - thickness) {
                if (chice == 1) {
                    image.setPixel(i, j, 0, redFrame);
                    image.setPixel(i, j, 1, greenFrame);
                    image.setPixel(i, j, 2, blueFrame);
                }
                else {

                    if ((i + j) % 20 < 10) {
                        image.setPixel(i, j, 0, redFrame);
                        image.setPixel(i, j, 1, greenFrame);
                        image.setPixel(i, j, 2, blueFrame);
                    }
                    else {
                        image.setPixel(i, j, 0, redPattern);
                        image.setPixel(i, j, 1, greenPattern);
                        image.setPixel(i, j, 2, bluePattern);
                    }
                }
            }
        }
    }

}