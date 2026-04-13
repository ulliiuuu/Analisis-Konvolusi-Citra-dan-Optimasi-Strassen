# Analisis-Konvolusi-Citra-dan-Optimasi-Strassen

Image Blurring
Blurring adalah teknik dalam pengolahan citra untuk **menghaluskan gambar** dengan cara meratakan nilai pixel.

Cara kerjanya:
* Setiap pixel diganti dengan **rata-rata pixel di sekitarnya**
* Proses ini disebut **konvolusi (convolution)**

Konsep Kernel
Kernel adalah matriks kecil (misalnya 3x3, 5x5, 7x7) yang digunakan untuk menghitung nilai pixel baru. Kernel harus ganjil supaya ada titik pusat yang jelas untuk menghitung pixel baru secara simetris.

👉 Semakin besar kernel → semakin blur

Compile program : gcc modul3.c -o modul3.exe
Jalankan program : ./modul3.exe

