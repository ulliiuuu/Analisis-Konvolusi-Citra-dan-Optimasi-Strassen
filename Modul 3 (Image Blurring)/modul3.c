#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>

void apply_blur(unsigned char* in, unsigned char* out,
                int w, int h, int c, int k_size) {
    int r = k_size / 2;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int ch = 0; ch < c; ch++) {
                float sum = 0;
                int count = 0;
                for (int ky = -r; ky <= r; ky++) {
                    for (int kx = -r; kx <= r; kx++) {
                        int px = x + kx;
                        int py = y + ky;
                        // Boundary check
                        if (px >= 0 && px < w && py >= 0 && py < h) {
                            sum += in[(py * w + px) * c + ch];
                            count++;
                        }
                    }
                }

                out[(y * w + x) * c + ch] =
                    (unsigned char)(sum / count);
            }
        }
    }
}

int main() {
    const char *input_path = "input.png";
    const char *output_path = "output.png";

    int width, height, channels;
    unsigned char *src = stbi_load(input_path, &width, &height, &channels, 0);
    if (!src) {
        fprintf(stderr, "Gagal membaca file %s\n", input_path);
        return 1;
    }

    printf("Gambar sumber: %dx%d (%d channel)\n", width, height, channels);

    unsigned char *out = (unsigned char*)malloc(width * height * channels);
    
    //apply blur harus ganjil, apply blur = 9 untuk hasil blur yang lebih terlihat
    apply_blur(src, out, width, height, channels, 9);

    if (!stbi_write_png(output_path, width, height, channels, out, width * channels)) {
        fprintf(stderr, "Gagal menyimpan file %s\n", output_path);
    } else {
        printf("Gambar hasil disimpan ke: %s\n", output_path);
    }

    stbi_image_free(src);
    free(out);

    return 0;
}