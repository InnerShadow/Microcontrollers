#include <math.h>
#define PI 3.14159265358979323846
#define N 128 // Количество отсчетов

// Структура для комплексных чисел
typedef struct {
    double real;
    double imag;
} complex;

// Функция для вычисления ДПФ
void fft(complex *X) {
    complex temp, t, u;
    int i, j, k, l, le, le1;
    double arg, c, s;

    // Битовое обращение
    j = 0;
    for (i = 1; i < N - 1; i++) {
        k = N / 2;
        while (k <= j) {
            j = j - k;
            k = k / 2;
        }
        j = j + k;
        if (i < j) {
            temp = X[j];
            X[j] = X[i];
            X[i] = temp;
        }
    }

    // FFT
    for (l = 1; l <= log(N)/log(2); l++) {
        le = pow(2, l);
        le1 = le / 2;
        u.real = 1.0;
        u.imag = 0.0;
        arg = PI / le1;
        c = cos(arg);
        s = -sin(arg);
        for (j = 1; j <= le1; j++) {
            for (i = j - 1; i < N; i += le) {
                k = i + le1;
                t.real = u.real * X[k].real - u.imag * X[k].imag;
                t.imag = u.real * X[k].imag + u.imag * X[k].real;
                X[k].real = X[i].real - t.real;
                X[k].imag = X[i].imag - t.imag;
                X[i].real = X[i].real + t.real; 
                X[i].imag = X[i].imag + t.imag;
            }
            temp = u;
            u.real = c * temp.real - s * temp.imag;
            u.imag = c * temp.imag + s * temp.real;
        }
    }
		while (1) {}
}
