#include <iostream>
#include <cstdlib> 
#include <cstring> 

using namespace std;

class Image {
private:
    int width;
    int height;
    int* imgData;
    int numOfData;

public:

    Image(int w, int h, int n, int* data) : width(w), height(h), numOfData(n) {
        imgData = new int[n];
        for (int i = 0; i < n; i++) {
            imgData[i] = data[i];
        }
    }

    Image(const Image& ogCopy) : width(ogCopy.width), height(ogCopy.height), numOfData(ogCopy.numOfData) {
        imgData = new int[numOfData];
        memcpy(imgData, ogCopy.imgData, numOfData * sizeof(int));
    }

    
    ~Image() {
        delete[] imgData;
    }

    void display() {
        for (int i = 0; i < numOfData; ++i) {
            cout << imgData[i] << " ";
        }
    }

    void updateData(int n, int* upData) {
        delete[] imgData;
        imgData = new int[n];
        numOfData = n;
        memcpy(imgData, upData, n * sizeof(int));
    }
};

int main() {
    
    int sampleD[] = {1, 2, 3, -1, -2, 0};
    int upData[] = {3, 4, 8, 99, 100, 123};
    
    Image originalImage(2, 3, 6, sampleD);
 
    Image copiedImage = originalImage;

   
    cout << "Original Image:\n";
    originalImage.display();
    cout << "\nCopied Image:\n";
    copiedImage.display();

    
    originalImage.updateData(6, upData);
// copied image has to remain the same throughout

   
    cout << "\nOriginal Image After Update:\n";
    originalImage.display();
    cout << "\nCopied Image After Update:\n";
    copiedImage.display();

    return 0;
}
