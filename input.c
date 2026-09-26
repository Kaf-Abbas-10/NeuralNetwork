#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define IMAGE_SIZE 28 * 28

uint32_t read_uint32(FILE *file)
{
    uint8_t bytes[4];

    fread(bytes, sizeof(uint8_t), 4, file);

    return ((uint32_t)bytes[0] << 24) |
           ((uint32_t)bytes[1] << 16) |
           ((uint32_t)bytes[2] << 8)  |
           ((uint32_t)bytes[3]);
}

int main()
{
    FILE *images = fopen("dataset/train-images.idx3-ubyte", "rb");
    FILE *labels = fopen("dataset/train-labels.idx1-ubyte", "rb");

    if (images == NULL || labels == NULL)
    {
        printf("Error opening files\n");
        return 1;
    }

    // -------------------------
    // Read image header
    // -------------------------

    uint32_t image_magic = read_uint32(images);
    uint32_t num_images  = read_uint32(images);
    uint32_t rows        = read_uint32(images);
    uint32_t cols        = read_uint32(images);

    // -------------------------
    // Read label header
    // -------------------------

    uint32_t label_magic = read_uint32(labels);
    uint32_t num_labels  = read_uint32(labels);

    printf("Image magic: %u\n", image_magic);
    printf("Number of images: %u\n", num_images);
    printf("Rows: %u\n", rows);
    printf("Columns: %u\n", cols);

    printf("Label magic: %u\n", label_magic);
    printf("Number of labels: %u\n", num_labels);

    // -------------------------
    // Read first image
    // -------------------------
	for(int i = 0; i < 60000; i++){
		unsigned char image[IMAGE_SIZE];
		unsigned char label;

		fread(image, sizeof(unsigned char), IMAGE_SIZE, images);
		fread(&label, sizeof(unsigned char), 1, labels);

		printf("\n%d image label: %d\n", i, label);

		
	}
    fclose(images);
    fclose(labels);

    return 0;
}
