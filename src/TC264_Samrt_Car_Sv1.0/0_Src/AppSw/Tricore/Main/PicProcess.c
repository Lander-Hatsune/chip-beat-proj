#include "ServeSource.h"
void EvenPooling (int strd, int[121][161]* p_result, int h, int w) {
    for (int i = 0; i < h - strd + 1; i += strd) {
        for (int j = 0; j < w - strd + 1; j += strd) {
            int temp_avg = 0;
            for (int ki = 0; ki < 3; ki++)
                for (int kj = 0; kj < 3; kj++)
                    temp_avg += pic[i + ki][j + kj];
            temp_avg /= (strd * strd);
            (*p_result)[i][j] = temp_avg;
        }
    }
}
void Conv(int strd, int h, int w) {
    int kernal[3][3] = {{1, 0, -1},
                        {2, 0, -2},
                        {1, 0, -1}};
    for (int i = 0; i <= h - strd + 1; i += strd) {
        for (int j = 0; j <= w - strd + 1; j += strd) {
            int temp_sum = 0;
            for (int ki = 0; ki < 3; ki++)
                for (int kj = 0; kj < 3; kj++)
                    temp_sum += kernal[ki][kj] * pic[i + ki][j + kj];
            convout[i][j] = temp_sum;
        }
    }
}
