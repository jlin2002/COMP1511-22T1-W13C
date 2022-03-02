// Program that represents time using a struct
// W13C, March 2022

#include <stdio.h>

// Define the 'struct time' type
struct time {
    int hour;
    int minute;
    char meridiem;
};

int main(void) {
    // Declare a variable 'bedtime' of type 'struct time' 
    struct time bedtime;
    // Initialise fields of 'bedtime' to make it represent 10:30 pm
    bedtime.hour = 10;
    bedtime.minute = 30;
    bedtime.meridiem = 'p';
    // Print bedtime in the format HH:MM [ap]m
    printf(
        "Bedtime: %d:%d %cm\n", 
        bedtime.hour, 
        bedtime.minute, 
        bedtime.meridiem
    );
    return 0;
}
