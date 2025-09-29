//Assignment 1 - The First phase .
//CS213_A1_Part1_S9, S10 _20240069_20242201_20240606
//             Dr. Mohamed Al-Ramly
// 20240069 -> Filter 1 and Filter 7 /the smallest ID 
// 20242201 -> Filter 3 and Filter 6 /the largest  ID
// 20240606 -> Filter 2 and Filter 5 /the middle   ID
//--------------------------------------------------------------------------------------------------------
// github repo link -> https://github.com/Abdo2000-1/CS213_A1_Part1_S9-S10_20242201_20240069_20240606.git
//--------------------------------------------------------------------------------------------------------

#include "Image_Class.h"
#include<iostream>
#include<string>



using namespace std;

enum enMenu { Filter1, Filter2, Filter3, Filter4, Filter5, Filter6, Filter7, Filter8, Filter9, Filter10, Filter11, Filter12 };

enMenu Printmenu() {
    cout << "  Assignment 1 - 1st Phase - any 6 Filters\n";
    cout << "in 1st Phase filters (1,2,3,5,6,7) are Ready only\n ";
    cout << "=================================================\n";
    cout << "===->             Choose Filter :             ===\n";
    cout << "===Filter 1  -> Grayscale Conversion          ===\n";
    cout << "===Filter 2  -> Black and White               ===\n";
    cout << "===Filter 3  -> Invert Image                  ===\n";
    cout << "===Filter 4  -> Merge Images                  ===\n";
    cout << "===Filter 5  -> Flip Image                    ===\n";
    cout << "===Filter 6  -> Rotate Image                  ===\n";
    cout << "===Filter 7  -> Darken and Lighten Image      ===\n";
    cout << "===Filter 8  -> Crop Images                   ===\n";
    cout << "===Filter 9  -> Adding a Frame to the Picture ===\n";
    cout << "===Filter 10 -> Detect Image Edges            ===\n";
    cout << "===Filter 11 -> Resizing Images               ===\n";
    cout << "===Filter 12 -> Blur Images                   ===\n";
    cout << "=================================================\n";

    int choice;
    cout << "Enter yor choice (1-12)\n";
    cin >> choice;

    while (choice < 1 || choice >12) {

        cout << "Invaliad input (-_-) Enter a number btween (1-12) \n";
        cin >> choice;
    }
    switch (choice) {
    case 1:
        return enMenu::Filter1;
        break;
    case 2:
        return enMenu::Filter2;
        break;
    case 3:
        return enMenu::Filter3;
        break;
    case 4:
        return enMenu::Filter4;
        break;
    case 5:
        return enMenu::Filter5;
        break;
    case 6:
        return enMenu::Filter6;
        break;
    case 7:
        return enMenu::Filter7;
        break;
    case 8:
        return enMenu::Filter8;
        break;
    case 9:
        return enMenu::Filter9;
        break;
    case 10:
        return enMenu::Filter10;
        break;
    case 11:
        return enMenu::Filter11;
        break;
    case 12:
        return enMenu::Filter12;
        break;

    }


}

void GreyscaleFilter(Image& image)
{
    //20240069

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0;

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
void invertFilter(Image& image)
{
    //20242201
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            unsigned char oldRed = image.getPixel(i, j, 0);
            unsigned char oldGreen = image.getPixel(i, j, 1);
            unsigned char oldBlue = image.getPixel(i, j, 2);


            unsigned char newRed = 255 - oldRed;
            unsigned char newGreen = 255 - oldGreen;
            unsigned char newBlue = 255 - oldBlue;

            image.setPixel(i, j, 0, newRed);
            image.setPixel(i, j, 1, newGreen);
            image.setPixel(i, j, 2, newBlue);
        }
    }
}
void rotateFilter(Image& image)
{
    //20242201

    int angle;
    cout << "Enter rotation angle (90, 180, or 270): ";
    cin >> angle;


    if (angle != 90 && angle != 180 && angle != 270) {
        cout << "Invalid angle. Please enter 90, 180, or 270." << endl;
        return;
    }

    if (angle == 180) {
        Image rotatedImage(image.width, image.height);

        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    unsigned char pixel_color = image.getPixel(i, j, k);
                    rotatedImage.setPixel(image.width - 1 - i, image.height - 1 - j, k, pixel_color);
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
                    unsigned char pixel_color = image.getPixel(i, j, k);
                    if (angle == 90) {

                        rotatedImage.setPixel(j, image.width - 1 - i, k, pixel_color);
                    }
                    else {

                        rotatedImage.setPixel(image.height - 1 - j, i, k, pixel_color);
                    }
                }
            }
        }
        image = rotatedImage;
    }


}
void DarkrnAndLightenfilter(Image& image)
{
    //20240069
    short ans = 0;
    cout << "You want to [1] Lighten or [2] Darken 50% ?";
    cin >> ans;
    if (ans == 1)
    {
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
    else
    {
        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width; x++) {
                for (int k = 0; k < 3; k++) {

                    image(x, y, k) = image(x, y, k) * 0.5;
                }
            }
        }

    }
}
void FlipFilter(Image& image)
{
    //20240606
    Image temp_image(image.width, image.height);

    int choice;
    cout << "Enter [1] for horizontal flip : \n";
    cout << "Enter [2] for vertical   flip : \n";

    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    temp_image(image.width - 1 - i, j, k) = image(i, j, k);
                }
            }
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    temp_image(i, image.height - 1 - j, k) = image(i, j, k);
                }
            }
        }
    }
    else {
        cout << "Invalid choice. No flip applied." << endl;
        return;
    }


    image = temp_image;

}
void blackAndWhite(Image& img)
{
    //20240606
    int w = img.width;
    int h = img.height;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int gray = 0;
            for (int k = 0; k < 3; k++) {
                gray += img(x, y, k);
            }
            gray /= 3;

            int bw;
            if (gray < 128) {
                bw = 0;
            }
            else {
                bw = 255;
            }

            for (int k = 0; k < 3; k++) {
                img(x, y, k) = bw;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string filename;
    cout << "                        ----------------------------------------------------------------\n";
    cout << "                        | Please enter the image name and the extension *_*             |\n";
    cout << "                        | -> note that Only .JPG, JPEG, .BMP, .PNG, .TGA are supported  |\n";
    cout << "                        ----------------------------------------------------------------\n";

    cin >> filename;

    Image image(filename);

    if (image.loadNewImage(filename)) {
        cout << "Image loaded Successfully\n";
    }
    else {
        cout << "Error: Could not load image. Please check the filename and path.\n";
        return 1;
    }

    switch ((Printmenu() + 1)) {
    case 1:
        GreyscaleFilter(image);
        cout << "Applying Grayscale Conversion filter ... \n";
        break;
    case 2:
        blackAndWhite(image);
        cout << "Applying Black and White filter  ... \n";
        break;
    case 3:
        invertFilter(image);
        cout << "Applying Invert Image filter ... \n";
        break;
    case 4:
        cout << "Applying Merge Images filter ... \n";
        break;
    case 5:FlipFilter(image);
        cout << "Applying Flip Image filter ... \n";
        break;
    case 6:
        rotateFilter(image);
        cout << "Applying Rotate Image filter ... \n";
        break;
    case 7:
        DarkrnAndLightenfilter(image);
        cout << "Applying Darken and Lighten Image filter  ... \n";
        break;
    case 8:
        cout << "Applying Crop Images filter ... \n";
        break;
    case 9:

        cout << "Applying Adding a Frame to the Picture filter ... \n";
        break;
    case 10:
        cout << "Applying Detect Image Edges filter ... \n";
        break;
    case 11:
        cout << "Applying Resizing Images filter ... \n";
        break;
    case 12:

        cout << "Applying Blur Images filter ... \n";
        break;

    }
    cout << "Filter Added Successfully ! \n";

    cout << "Please enter image name to store new image\n";
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
