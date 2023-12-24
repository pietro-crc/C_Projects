This project implements image filtering for BMP files using command-line arguments. It allows you to apply four different filters to an input BMP file: blur, grayscale, reflection, and sepia. The filtered image is then written to an output BMP file.

Detailed explanation of the code:

The code starts by defining a set of allowable filters ('bgrs') and then gets the filter flag provided by the user using the getopt function. It checks the validity of the filter flag and ensures that only one filter is provided.

If the usage is not proper (less than 3 or more than 4 command-line arguments), the code prints an error message and terminates.

The code then opens the input and output files using the fopen function. It reads the BITMAPFILEHEADER and BITMAPINFOHEADER from the input file, ensuring that the file format is supported.

The code allocates memory for the image data using the calloc function. It determines the padding required for each scanline and iterates over the input file's scanlines, reading the pixel data and skipping over the padding.

The code then applies the selected filter to the image data:

Blur: blurs the image using a 3x3 Gaussian blur kernel
Grayscale: converts the image to grayscale, averaging the red, green, and blue channels
Reflection: reflects the image horizontally
Sepia: converts the image to sepia tone
Finally, the code writes the filtered image data to the output file, writing the BITMAPFILEHEADER and BITMAPINFOHEADER and then writing each scanline.

Memory management:

The code allocates memory for the image data using calloc and frees the memory when finished using free.

Additional details:

The code uses helper functions for each filter to perform the necessary calculations.
The code handles potential errors gracefully, including invalid filters, insufficient memory, and unsupported file formats.
