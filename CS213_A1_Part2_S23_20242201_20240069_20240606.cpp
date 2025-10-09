// Assignment 1 - The Second phase 
// CS213_A1_Part2_ S23 _20240069_20242201_20240606
//             Dr. Mohamed Al-Ramly
// 20240069 -> Filter 1 ,4 ,7 ,10 and Filter 16 as a Bonus /the smallest ID 
// 20242201 -> Filter 3 ,6 ,9 ,12 and Filter 14 as a Bonus /the largest  ID
// 20240606 -> Filter 2 ,5 ,8 ,11 and Filter 13 as a Bonus /the middle   ID
//--------------------------------------------------------------------------------------------------------
// github repo link -> https://github.com/Abdo2000-1/-CS213_A1_Part2_S23_20242201_20240069_20240606.git
//--------------------------------------------------------------------------------------------------------


#include "Image_Class.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm> 
#include <random> 

using namespace std;

enum enMenu { Filter1 = 1, Filter2, Filter3, Filter4, Filter5, Filter6, Filter7, Filter8, Filter9, Filter10, Filter11, Filter12,Filter13, Filter14, Filter15, undo, Exit };

enMenu ans = enMenu::Filter1;
stack<Image> FiltersApplied;

enMenu Printmenu() {
    cout << "\t\t\t  Assignment 1 - 1st Phase - any 6 Filters\n\n\n";
    cout << "\t\t\tin 1st Phase filters (1,2,3,5,6,7) are Ready only\n\n ";
    cout << "\t\t\tChoose 14 if you want to Exit\n\n ";

    cout << "\t\t\tthe Filters Applied is  " << FiltersApplied.size()-1 << " Filter(s)" << endl << endl;


    cout << "\t\t\t=================================================\n";
    cout << "\t\t\t===               Choose Filter :             ===\n";
    cout << "\t\t\t===Filter 1  -> Grayscale Conversion          ===\n";
    cout << "\t\t\t===Filter 2  -> Black and White               ===\n";
    cout << "\t\t\t===Filter 3  -> Invert Image                  ===\n";
    cout << "\t\t\t===Filter 4  -> Merge Images                  ===\n";
    cout << "\t\t\t===Filter 5  -> Flip Image                    ===\n";
    cout << "\t\t\t===Filter 6  -> Rotate Image                  ===\n";
    cout << "\t\t\t===Filter 7  -> Darken and Lighten Image      ===\n";
    cout << "\t\t\t===Filter 8  -> Crop Images                   ===\n";
    cout << "\t\t\t===Filter 9  -> Adding a Frame to the Picture ===\n";
    cout << "\t\t\t===Filter 10 -> Detect Image Edges            ===\n";
    cout << "\t\t\t===Filter 11 -> Resizing Images               ===\n";
    cout << "\t\t\t===Filter 12 -> Blur Images                   ===\n";
    cout << "\t\t\t===Filter 13 -> Purple Filter        (bonus)  ===\n";
    cout << "\t\t\t===Filter 14 -> Sun lihgt Filter     (bonus)  ===\n";
    cout << "\t\t\t===Filter 15 -> Oil Filter           (bonus)  ===\n";
    cout << "\t\t\t===Press  16 -> UNDO                          ===\n";
    cout << "\t\t\t===Press  17 -> Exit                          ===\n";
    cout << "\t\t\t=================================================\n";
                                                      
    int choice;                                       
    cout << "\nEnter your choice (1-17): ";           
    cin >> choice;                                    
                                                      
    while (choice < 1 || choice >17) {
        cout << "Invalid input! Enter a number between (1-17): ";
        cin >> choice;
    }
    ans = (enMenu)choice;
    return ans;
}

void GreyscaleFilter(Image& image) {
    //20240069
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            avg /= 3;

            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}
void invertFilter(Image& image) {
    //20242201
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned char oldRed = image.getPixel(i, j, 0);
            unsigned char oldGreen = image.getPixel(i, j, 1);
            unsigned char oldBlue = image.getPixel(i, j, 2);

            image.setPixel(i, j, 0, 255 - oldRed);
            image.setPixel(i, j, 1, 255 - oldGreen);
            image.setPixel(i, j, 2, 255 - oldBlue);
        }
    }
}
void rotateFilter(Image& image) {
    //20242201
    int angle;
    cout << "Enter rotation angle (90, 180, or 270): ";
    cin >> angle;

    if (angle != 90 && angle != 180 && angle != 270) {
        cout << "Invalid angle. Please enter 90, 180, or 270.\n";
        return;
    }

    if (angle == 180) {
        Image rotatedImage(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    rotatedImage.setPixel(image.width - 1 - i, image.height - 1 - j, k, image.getPixel(i, j, k));
                }
            }
        }
        image = rotatedImage;
    }
    else {
        Image rotatedImage(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (angle == 90)
                        rotatedImage.setPixel(j, image.width - 1 - i, k, image.getPixel(i, j, k));
                    else // 270
                        rotatedImage.setPixel(image.height - 1 - j, i, k, image.getPixel(i, j, k));
                }
            }
        }
        image = rotatedImage;
    }
}
void DarkenAndLightenFilter(Image& image) {
    //20240069
    short choice = 0;
    cout << "You want to [1] Lighten or [2] Darken 50% ? ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
        return;
    }

    if (choice == 1) {
        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width; x++) {
                for (int k = 0; k < 3; k++) {
                    int newVal = image(x, y, k) * 1.5;
                    if (newVal > 255) newVal = 255;
                    image(x, y, k) = newVal;
                }
            }
        }
    }
    else {
        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width; x++) {
                for (int k = 0; k < 3; k++) {
                    image(x, y, k) = image(x, y, k) * 0.5;
                }
            }
        }
    }
}
void FlipFilter(Image& image) {
    //20240606
    Image temp_image(image.width, image.height);
    int choice;
    cout << "Enter [1] for horizontal flip, [2] for vertical flip: ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < image.width; ++i)
            for (int j = 0; j < image.height; ++j)
                for (int k = 0; k < 3; ++k)
                    temp_image(image.width - 1 - i, j, k) = image(i, j, k);
    }
    else if (choice == 2) {
        for (int i = 0; i < image.width; ++i)
            for (int j = 0; j < image.height; ++j)
                for (int k = 0; k < 3; ++k)
                    temp_image(i, image.height - 1 - j, k) = image(i, j, k);
    }
    else {
        cout << "Invalid choice. No flip applied.\n";
        return;
    }
    image = temp_image;
}
void blackAndWhite(Image& img) {
    //20240606
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            int gray = 0;
            for (int k = 0; k < 3; k++) gray += img(x, y, k);
            gray /= 3;

            int bw = (gray < 128) ? 0 : 255;
            for (int k = 0; k < 3; k++) img(x, y, k) = bw;
        }
    }
}
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
void blurFilter(Image& image) {
    int radius;

    cout << " Enter blur level \nFor light blur : Enter 1 or 2 :\n";
    cout << "For medium blur: Enter 4 or 5 :\n";
    cout << "For very strong blur : Try entering 8, 10, or even 15 to see the effect \n \n [ Note : This action may take a while] \n";

    cin >> radius;

    if (radius < 1) {
        cout << "Blur radius must be at least 1 " << endl;
        return;
    }


    Image originalImage = image;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            long long sumR = 0, sumG = 0, sumB = 0;
            int pixel_count = 0;

            for (int ki = -radius; ki <= radius; ++ki) {
                for (int kj = -radius; kj <= radius; ++kj) {
                    int neighbor_x = i + ki;
                    int neighbor_y = j + kj;

                    if (neighbor_x >= 0 && neighbor_x < image.width && neighbor_y >= 0 && neighbor_y < image.height) {
                        sumR += originalImage.getPixel(neighbor_x, neighbor_y, 0);
                        sumG += originalImage.getPixel(neighbor_x, neighbor_y, 1);
                        sumB += originalImage.getPixel(neighbor_x, neighbor_y, 2);
                        pixel_count++;
                    }
                }
            }

            image.setPixel(i, j, 0, sumR / pixel_count);
            image.setPixel(i, j, 1, sumG / pixel_count);
            image.setPixel(i, j, 2, sumB / pixel_count);
        }
    }

    cout << "Blur filter applied successfully." << endl;
}
void purple(Image& image)
{
    
        for (int i = 0; i < image.width; ++i) 
        {
            for (int j = 0; j < image.height; ++j) 
            {

                image(i, j, 1) = min(255, int(image(i, j, 1) * 0.71));


            }
        }
    
    
}
void cropImage(Image& image) {
    int x, y, w, h;
    cout << "Enter top-left corner (x y): ";
    cin >> x >> y;
    cout << "Enter width and height (w h): ";
    cin >> w >> h;

    Image cropped(w, h);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < 3; k++) {
                cropped(i, j, k) = image(x + i, y + j, k);
            }
        }
    }
    image = cropped;
     
}
void DetectEdges(Image& image)
{
   
   
    Image copy = image;

    int w = image.width;
    int h = image.height;

    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
        {
            unsigned char avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            image(i, j, 0) = image(i, j, 1) = image(i, j, 2) = avg;
            copy(i, j, 0) = copy(i, j, 1) = copy(i, j, 2) = avg;
        }

    int Gx[3][3] = { {-1,0,1},{-2,0,2},{-1,0,1} };
    int Gy[3][3] = { {-1,-2,-1},{0,0,0},{1,2,1} };

    for (int i = 1; i < w - 1; ++i)
        for (int j = 1; j < h - 1; ++j)
        {
            int sumX = 0, sumY = 0;
            for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy)
                {

                    sumX += Gx[dx + 1][dy + 1] * copy(i + dx, j + dy, 0);
                    sumY += Gy[dx + 1][dy + 1] * copy(i + dx, j + dy, 0);
                }

            int magnitude = int(sqrt(sumX * sumX + sumY * sumY));
            if (magnitude > 255) magnitude = 255;
            if (magnitude < 0) magnitude = 0;

            magnitude = 255 - magnitude;

            if (magnitude > 128) magnitude = 255;
            else magnitude = 0;

            image(i, j, 0) = image(i, j, 1) = image(i, j, 2) = magnitude;
        }

 

   
}
void resizeImage(Image& image) {
    int newW, newH;
    cout << "Enter new width and height: ";
    cin >> newW >> newH;

    Image resized(newW, newH);

    for (int i = 0; i < newW; i++) {
        for (int j = 0; j < newH; j++) {
            int oldX = i * image.width / newW;
            int oldY = j * image.height / newH;

            for (int k = 0; k < 3; k++) {
                resized(i, j, k) = image(oldX, oldY, k);
            }
        }
    }

    image = resized;
  
}
void Suncode(Image& image) {

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int r = image(i, j, 0);
            int g = image(i, j, 1);
            int b = image(i, j, 2);

            int newR = r + 70;
            if (newR > 255) newR = 255;

            int newG = g + 50;
            if (newG > 255) newG = 255;

            int newB = b - 10;
            if (newB < 0) newB = 0;

            image(i, j, 0) = newR;
            image(i, j, 1) = newG;
            image(i, j, 2) = newB;
        }
    }
}
void Merge(Image& image1) 
{

    string name2;
    cout << "Enter Second image name (image2): ";
    cin >> name2;
   
    

    
    Image image2(name2);

    int newWidth = min(image1.width, image2.width);
    int newHeight = min(image1.height, image2.height);

    Image merged(newWidth, newHeight);

    for (int x = 0; x < newWidth; ++x) {
        for (int y = 0; y < newHeight; ++y) {
            for (int c = 0; c < 3; ++c) {
                merged(x, y, c) = (image1(x, y, c) + image2(x, y, c)) / 2;
            }
        }
    }

    image1 = merged;

}
void oil(Image& image) {

    int radius = 3;
    int intensityLevel = 20;

    Image result(image.width, image.height);

    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {

            vector<int> intensityCount(intensityLevel, 0);
            vector<int> sumR(intensityLevel, 0);
            vector<int> sumG(intensityLevel, 0);
            vector<int> sumB(intensityLevel, 0);


            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {

                    int nx = x + i;
                    int ny = y + j;

                    if (nx >= 0 && nx < image.width && ny >= 0 && ny < image.height) {
                        unsigned char r = image(nx, ny, 0);
                        unsigned char g = image(nx, ny, 1);
                        unsigned char b = image(nx, ny, 2);

                        int intensity = ((r + g + b) / 3 * intensityLevel) / 256;
                        if (intensity >= intensityLevel) intensity = intensityLevel - 1;

                        intensityCount[intensity]++;
                        sumR[intensity] += r;
                        sumG[intensity] += g;
                        sumB[intensity] += b;
                    }
                }
            }


            int maxIndex = 0, maxCount = 0;
            for (int k = 0; k < intensityLevel; k++) {
                if (intensityCount[k] > maxCount) {
                    maxCount = intensityCount[k];
                    maxIndex = k;
                }
            }

            if (maxCount > 0) {
                result(x, y, 0) = sumR[maxIndex] / maxCount;
                result(x, y, 1) = sumG[maxIndex] / maxCount;
                result(x, y, 2) = sumB[maxIndex] / maxCount;
            }
        }
    }

}

int Undo(Image& image) {
    if (!FiltersApplied.empty()) {


        FiltersApplied.pop();
        if (!FiltersApplied.empty())
        {
            image = FiltersApplied.top();

        }
        else
        {
            cout << "There is nothing to Undo\n";
            cout << "Try the Filters \n";
            return 0;
        }
    }
    else 
    {
        cout << "There is nothing to Undo\n";
        cout << "Try the Filters \n";
        return 0;
    }
}

void AddFilter(Image& image) {
    switch (Printmenu())
    {
    case Filter1:
        GreyscaleFilter(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter2:
        blackAndWhite(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter3:
        invertFilter(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter4:
        Merge(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter5:
        FlipFilter(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter6:
        rotateFilter(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter7:
        DarkenAndLightenFilter(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter8:
        cropImage(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter9:
        addFrameFilter(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter10:
        
        DetectEdges(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);
        break;
    case Filter11:
        resizeImage(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);
        break;
    case Filter12:

        blurFilter(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);

        break;
    case Filter13:

        purple(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);
        break;
    case Filter14:
        Suncode(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);
        break;
    case Filter15:

        oil(image);
        cout << "Filter applied successfully!\n";
        FiltersApplied.push(image);
        break;

    case undo:
        
        Undo(image);

        if (FiltersApplied.size() == 0) {

        }
        else {
           
            cout << "Undo applied.\n";
        }
        break;

    case Exit:
        return;
    }
    cout << "\nPress any key to continue. . .";
    system("pause>0");
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string filename;
    cout << "\t\t\t+----------------------------------------------------------------+\n";
    cout << "\t\t\t| Please enter the image name and the extension *_*              |\n";
    cout << "\t\t\t| -> note that Only .JPG, JPEG, .BMP, .PNG, .TGA are supported   |\n";
    cout << "\t\t\t+----------------------------------------------------------------+\n";

    cin >> filename;

    Image image(filename);

    if (image.loadNewImage(filename)) {
        cout << "Image loaded Successfully\n";
    }
    else {
        cout << "Error: Could not load image. Please check the filename and path.\n";
        return 1;
    }

    FiltersApplied.push(image);


    while (ans != enMenu::Exit) {
        system("cls");
        AddFilter(image);
    }

   
    

        cout << "\nPlease enter image name to store new image\n";
        cout << "and choose extension => (Only .JPG, JPEG, .BMP, .PNG, .TGA are supported ): ";
        
        
        
        cin >> filename;
        if (image.saveImage(filename)) {
            cout << "Image saved Successfully ! \n";
        }
        else {
            cout << "Image save fail \n";
        }
    

    return 0;  





}