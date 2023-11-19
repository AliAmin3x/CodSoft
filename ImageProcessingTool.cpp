#include <QCoreApplication>
#include <QImage>
#include <QColor>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>
using namespace std;

void displayImage(const QImage& image) {
    cout << "Image Size: " << image.width() << " x " << image.height() << endl;
    cout << "Image Format: " << image.format() << endl;

}

QImage loadImage(const QString& filePath) {
    QImage image(filePath);
    if (image.isNull()) {
        cerr << "Error: Unable to load image from " << filePath.toStdString() << endl;
        return QImage();
    }
    return image;
}

void saveImage(const QImage& image, const QString& filePath) {
    if (image.save(filePath)) {
        cout << "Image saved successfully to " << filePath.toStdString() << endl;
    } else {
        cerr << "Error: Unable to save image to " << filePath.toStdString() << endl;
    }
}

void applyGrayscale(QImage& image) {
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QColor color(image.pixel(x, y));
            int gray = qGray(color.rgb());
            image.setPixel(x, y, QColor(gray, gray, gray).rgb());
        }
    }
}

void applyBlur(QImage& image) {
    // You can implement a blur algorithm based on your requirements
    // This is just a placeholder
}

void applySharpen(QImage& image) {
    // You can implement a sharpening algorithm based on your requirements
    // This is just a placeholder
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString imagePath = "path/to/your/image.jpg";

    QImage originalImage = loadImage(imagePath);
    if (originalImage.isNull()) {
        return 1;
        
    }

    displayImage(originalImage);

    applyGrayscale(originalImage);

    displayImage(originalImage);

    saveImage(originalImage, "path/to/your/output_image.jpg");

    return a.exec();
}
