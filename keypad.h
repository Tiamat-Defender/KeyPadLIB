#include "pico/stdlib.h"

#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3

#define COLUMN1 4
#define COLUMN2 5
#define COLUMN3 6
#define COLUMN4 6

char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void Keypad_init()
{
    gpio_init(ROW1);
    gpio_init(ROW2);
    gpio_init(ROW3);
    gpio_init(ROW4);

    gpio_init(COLUMN1);
    gpio_init(COLUMN2);
    gpio_init(COLUMN3);
    gpio_init(COLUMN4);
    gpio_init(COLUMN4);

    gpio_set_dir(ROW1, GPIO_OUT);
    gpio_set_dir(ROW2, GPIO_OUT);
    gpio_set_dir(ROW3, GPIO_OUT);
    gpio_set_dir(ROW4, GPIO_OUT);
    
    gpio_set_dir(COLUMN1, GPIO_IN);
    gpio_set_dir(COLUMN2, GPIO_IN);
    gpio_set_dir(COLUMN3, GPIO_IN);
    gpio_set_dir(COLUMN4, GPIO_IN);

}

char Scan_Input()
{
    for (int row = 0; row < 4; row++) {
        gpio_put(row, 1);

        for (int col = 0; col < 4; col++) {
            if (gpio_get(col + 4)) {
                gpio_put(row, 0);
                return keys[row][col];
            }
        }

        gpio_put(row, 0);
    }

    return '\0'; // Return null character if no key is pressed
}
