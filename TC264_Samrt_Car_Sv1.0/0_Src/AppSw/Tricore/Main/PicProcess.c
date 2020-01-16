#include "CameraOV7620.h"
#include "PicProcess.h"
/*
extern float _eigen[2][48][53];


// picture: unsigned int pic[121][161]
void Conv() {
    int i, j, ki, kj, ci, cj;
    float temp_avg, temp_conv[2];// 1 for transposed kernal
    int height = 120, width = 160;
    int kernal[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    
    int left = 5, right = 112, up = 6; down = 100;
    // crop by: [5, 6], [100, 112], [row, column]
    // resize: (96, 107), (row, column)
    for (i = 0; i < 96; i++) {
        for (j = 0; j < 107; j++) {
            temp_avg = 0.0f;
            for (ki = 0; ki < 2; ki++) 
                for (kj = 0; kj < 2; kj++) 
                    temp_avg +=
                        (float)pic[i + ki + up][j + kj + left];
            temp_avg /= 4;
            _poolres[i][j] = temp_avg;
        }
    }
    
    for (i = 0, ci = 0; i < 96 - 1; i += 2, ci++) {// 47
        for (j = 0, cj = 0; j < 107 - 1; j += 2, cj++) {// 52
            temp_conv[0] = 0.0f, temp_conv[1] = 0.0f;
            for (ki = 0; ki < 3; ki++) 
                for (kj = 0; kj < 3; kj++) {
                    temp_conv[0] +=
                        (float)pic[i + ki][j + kj] * kernal[ki][kj];
                    temp_conv[1] +=
                        (float)pic[i + ki][j + kj] * kernal[kj][ki];
                        
                }
            _convres[0][ci][cj] = temp_conv[0];
            _convres[1][ci][cj] = temp_conv[1];
        }
    }
}
*/
