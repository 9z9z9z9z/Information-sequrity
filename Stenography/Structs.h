typedef struct tagRGBQUAD
{
    char rgbBlue;
    char rgbGreen;
    char rgbRed;
    char rgbReserved;
} RGBQUAD;

typedef unsigned long DWORD; // Двойное слово - 32 бита (разряда)
typedef unsigned int WORD; // Слово - 16 бит (разрядов)
typedef signed long LONG;
typedef unsigned int UINT;
// Заголовок файла
typedef struct tagBITMAPFILEHEADER
{
    WORD bfType; // 'BM' = 4D42h
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits; // Смещение к растру
} BITMAPFILEHEADER;
// Заголовок Bitmap
typedef struct tagBITMAPINFOHEADER
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;