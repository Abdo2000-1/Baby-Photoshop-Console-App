# 🎨 Baby Photoshop - Console App

A C++ console-based image processing application developed as a project for the **CS213** course under the supervision of **Dr. Mohamed Al-Ramly**. The program allows users to load an image, apply a variety of filters, and save the modified image.

## ✨ Features

The application comes with a wide range of basic and advanced filters:

| Filter # | Filter Name | Description |
| :---: | :--- | :--- |
| 1 | **Grayscale Conversion** | Converts the image to grayscale. |
| 2 | **Black and White** | Converts the image to black and white colors only. |
| 3 | **Invert Image** | Inverts the colors of the image. |
| 4 | **Merge Images** | Merges two images together. |
| 5 | **Flip Image** | Flips the image horizontally or vertically. |
| 6 | **Rotate Image** | Rotates the image by 90, 180, or 270 degrees. |
| 7 | **Darken and Lighten** | Brightens or darkens the image by 50%. |
| 8 | **Crop Image** | Crops a specified portion of the image. |
| 9 | **Add Frame** | Adds a simple or a fancy frame to the image. |
| 10 | **Detect Image Edges** | Detects edges in the image for a sketch-like effect. |
| 11 | **Resize Image** | Changes the dimensions (width and height) of the image. |
| 12 | **Blur Image** | Applies a blur effect to the image. |
| 13 | **Purple Filter (Bonus)** | Applies a cool purple hue filter. |
| 14 | **Sunlight Filter (Bonus)** | Adds a warm, sunlight effect. |
| 15 | **Oil Painting (Bonus)** | Makes the image look like an oil painting. |
| 16 | **Undo** | Reverts the last filter applied. |
| 17 | **Exit** | Saves the image and exits the program. |

---

## 🚀 Getting Started

Follow these steps to get the project running on your local machine.

### Prerequisites

* A C++ compiler (e.g., G++ or MSVC).
* The project files: `main.cpp`, `Image_Class.h`, and any other dependencies.

### Running the Application

1.  **Clone the repository** to your local machine.
2.  **Compile the code.** Open a terminal or Git Bash in the project directory and run the following command (assuming you're using G++ and the image library is compiled from `Image_Class.cpp`):
    ```bash
    g++ main.cpp Image_Class.cpp -o BabyPhotoshop
    ```
3.  **Run the executable.** After successful compilation, run the program:
    ```bash
    ./BabyPhotoshop.exe
    ```
    or on Linux/macOS:
    ```bash
    ./BabyPhotoshop
    ```
4.  **How to Use:**
    * When the program starts, it will prompt you to enter the filename of the image you want to edit (including the extension).
    * A menu with the available filters will be displayed.
    * Choose a filter by entering its number.
    * After you're done, select the exit option to save your work to a new file.

---

## 🖼️ Supported Formats

The program supports loading and saving the following image formats:
* JPG / JPEG
* BMP
* PNG
* TGA

---

## 🧑‍💻 Authors

This project was a collaborative effort by the following students:

* **20240069**
* **20242201**
* **20240606**

Repository Link: [https://github.com/Abdo2000-1/Baby-Photoshop-Console-App](https://github.com/Abdo2000-1/Baby-Photoshop-Console-App)

# 🎨 Baby Photoshop - Console App

تطبيق كونسول لمعالجة الصور بلغة C++، تم تطويره كمشروع لمادة **CS213** تحت إشراف **Dr. Mohamed Al-Ramly**. يتيح البرنامج للمستخدمين تحميل الصور وتطبيق مجموعة متنوعة من الفلاتر عليها، ثم حفظ الصورة المعدلة.

## ✨ الميزات

يحتوي البرنامج على مجموعة واسعة من الفلاتر الأساسية والمتقدمة:

| رقم الفلتر | اسم الفلتر | الوصف |
| :---: | :--- | :--- |
| 1 | **Grayscale Conversion** | تحويل الصورة إلى تدرج الرمادي. |
| 2 | **Black and White** | تحويل الصورة إلى اللونين الأبيض والأسود فقط. |
| 3 | **Invert Image** | عكس ألوان الصورة. |
| 4 | **Merge Images** | دمج صورتين معًا. |
| 5 | **Flip Image** | قلب الصورة أفقيًا أو رأسيًا. |
| 6 | **Rotate Image** | تدوير الصورة بزاوية 90، 180، أو 270 درجة. |
| 7 | **Darken and Lighten** | تفتيح أو تغميق الصورة بنسبة 50%. |
| 8 | **Crop Image** | قص جزء محدد من الصورة. |
| 9 | **Add Frame** | إضافة إطار بسيط أو مزخرف للصورة. |
| 10 | **Detect Image Edges** | كشف الحواف في الصورة لإعطاء مظهر مرسوم. |
| 11 | **Resize Image** | تغيير أبعاد الصورة (الطول والعرض). |
| 12 | **Blur Image** | تطبيق تأثير الضبابية على الصورة. |
| 13 | **Purple Filter (Bonus)** | إضافة فلتر باللون الأرجواني. |
| 14 | **Sunlight Filter (Bonus)** | إضافة تأثير إضاءة الشمس الدافئة. |
| 15 | **Oil Painting (Bonus)** | تحويل الصورة لتبدو كلوحة زيتية. |
| 16 | **Undo** | التراجع عن آخر فلتر تم تطبيقه. |
| 17 | **Exit** | حفظ الصورة والخروج من البرنامج. |

## 🚀 كيفية البدء

اتبع الخطوات التالية لتشغيل المشروع على جهازك.

### المتطلبات الأساسية

- مترجم C++ (مثل G++ أو MSVC).
- ملفات المشروع: `main.cpp` و `Image_Class.h` وأي ملفات أخرى تابعة له.

### التشغيل

1.  **تحميل المشروع:**
    قم بنسخ المستودع إلى جهازك المحلي.

2.  **الترجمة (Compilation):**
    افتح الطرفية (Terminal) أو Git Bash في مجلد المشروع وقم بتنفيذ الأمر التالي لترجمة الكود (بافتراض أنك تستخدم G++ وأن مكتبة الصور مجمعة في ملف `Image_Class.cpp`):

    ```bash
    g++ main.cpp Image_Class.cpp -o BabyPhotoshop
    ```

3.  **تشغيل البرنامج:**
    بعد انتهاء الترجمة بنجاح، قم بتشغيل الملف التنفيذي:

    ```bash
    ./BabyPhotoshop.exe
    ```
    أو
    ```bash
    ./BabyPhotoshop
    ```
    
4.  **الاستخدام:**
    * عند بدء التشغيل، سيطلب منك البرنامج إدخال اسم الصورة التي تريد تعديلها (مع الامتداد).
    * بعد ذلك، ستظهر لك قائمة بالفلاتر المتاحة.
    * اختر رقم الفلتر الذي تريده.
    * بعد تطبيق الفلاتر، اختر خيار الخروج لحفظ الصورة باسم جديد.

## 🖼️ الصيغ المدعومة

البرنامج يدعم تحميل وحفظ الصور بالصيغ التالية:
* JPG / JPEG
* BMP
* PNG
* TGA

## 🧑‍💻 المؤلفون

هذا المشروع هو نتاج عمل جماعي قام به الطلاب:

- **20240069**
- **20242201**
- **20240606**

رابط المستودع: [https://github.com/Abdo2000-1/Baby-Photoshop-Console-App](https://github.com/Abdo2000-1/Baby-Photoshop-Console-App)
