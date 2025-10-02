// Assignment 1 - The First phase 
// CS213_A1_Part1_S9, S10 _20240069_20242201_20240606
//             Dr. Mohamed Al-Ramly
// 20240069 -> Filter 1 and Filter 7 /the smallest ID 
// 20242201 -> Filter 3 and Filter 6 /the largest  ID
// 20240606 -> Filter 2 and Filter 5 /the middle   ID
//--------------------------------------------------------------------------------------------------------
// github repo link -> https://github.com/Abdo2000-1/-CS213_A1_Part1_S9-S10_20242201_20240069_20240606.git
//--------------------------------------------------------------------------------------------------------


#include "Image_Class.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum enMenu { Filter1 = 1, Filter2, Filter3, Filter4, Filter5, Filter6, Filter7, Filter8, Filter9, Filter10, Filter11, Filter12, undo, Exit };

enMenu ans = enMenu::Filter1;
stack<Image> FiltersApplied;

enMenu Printmenu() {
    cout << "\t\t\t  Assignment 1 - 1st Phase - any 6 Filters\n\n\n";
    cout << "\t\t\tin 1st Phase filters (1,2,3,5,6,7) are Ready only\n\n ";
    cout << "\t\t\tChoose 14 if you want to Exit\n\n ";

    cout << "\t\t\tthe Filters Applied is  " << FiltersApplied.size() << " Filter(s)" << endl << endl;


    cout << "\t\t\t=================================================\n";
    cout << "\t\t\t===->             Choose Filter :             ===\n";
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
    cout << "\t\t\t===13 -> UNDO                                 ===\n";
    cout << "\t\t\t===14 -> Exit                                 ===\n";
    cout << "\t\t\t=================================================\n";

    int choice;
    cout << "\nEnter your choice (1-14): ";
    cin >> choice;

    while (choice < 1 || choice >14) {
        cout << "Invalid input! Enter a number between (1-14): ";
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

int Undo(Image& image) {
    if (!FiltersApplied.empty()) {

        image = FiltersApplied.top();
        FiltersApplied.pop();
    }
    else {
        cout << "There is nothing to Undo\n";
        cout << "Try the Filters \n";
        return 0;
    }
}

void AddFilter(Image& image) {
    switch (Printmenu()) {
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
        cout << "Merge Images not implemented yet.\n"; break;
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
        cout << "Crop not implemented yet.\n";
        break;
    case Filter9:
        cout << "Frame not implemented yet.\n";
        break;
    case Filter10:
        cout << "Edge detection not implemented yet.\n";
        break;
    case Filter11:
        cout << "Resize not implemented yet.\n";
        break;
    case Filter12:
        cout << "Blur not implemented yet.\n";
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

int main() {
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