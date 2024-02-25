#include "Stenographer.h"

const static std::string CURRENT_DIRECTORY = R"(D:\Programs\Labs\InformationProtecting\Stenography\)";
const static std::string INPUT_FILE = CURRENT_DIRECTORY + "1.bmp";
const static std::string OUTPUT_FILE =  CURRENT_DIRECTORY + "output.txt";

//int main() {
//    FILE *input_file = fopen(INPUT_FILE.c_str(), "rb");
//    if (input_file == nullptr) {
//        perror("Error opening input file");
//        return 1;
//    }
//    FILE *output_file = fopen(OUTPUT_FILE.c_str(), "wb");
//    if (output_file == nullptr) {
//        perror("Error opening output file");
//        fclose(input_file);
//        return 1;
//    }
//    int counter = 1;
//    RGBQUAD pixel;
//    uint8_t extracted_byte;
//    tagRGBQUAD head;
//    fread(&head, sizeof(head), 1, input_file);
//    tagBITMAPFILEHEADER tag;
//    fread(&tag, sizeof(tag), 1, input_file);
//    while (fread(&pixel, sizeof(RGBQUAD), 1, input_file) == 1) {
//        Stenographer::extract_byte_from_pixel(&pixel, &extracted_byte);
//        if (extracted_byte == 0xFF) {
//            break;
//        }
//
//    }
//
//    fclose(input_file);
//    fclose(output_file);
//
//    printf("Data extracted successfully!\n");
//    return 0;
//}

int main() {
    // Extract data
    FILE *input_file = fopen(INPUT_FILE.c_str(), "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen(OUTPUT_FILE.c_str(), "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }
    RGBQUAD pixel;
    uint8_t extracted_byte;
    while (fread(&pixel, sizeof(RGBQUAD), 1, input_file) == 1) {
        Stenographer::extract_byte_from_pixel(&pixel, &extracted_byte);
        if (extracted_byte == 0xFF) {
            break;  // End of file
        }
        if (fwrite(&extracted_byte, sizeof(uint8_t), 1, output_file) != 1) {
            perror("Error writing output file");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data extracted successfully!\n");

    return 0;
}