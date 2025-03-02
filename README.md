# gas-detector
Nowadays, natural gas is used as a fuel in almost every home, but in case of a leak, it can pose a serious threat. Even a small spark can lead to devastating consequences. Today, we will build a sensor that detects excessive gas in the environment, triggers an alarm, flashes a warning light, and displays the message “Gas Danger” on a screen. This way, even if we fail to notice the gas odor, we will still be able to hear and see the danger in time.

For step-by-step detailed information about the setup, check out the [post on my personal blog](https://alirfandogan.com/2025/02/21/gas-sensor-with-warning-system-using-arduino-uno/).

# code-explanation
First, we import the necessary libraries for the LCD screen (Lines 1, 2). Then, we define the pins that will be used (Lines 4 – 7). We write the required code to call the LCD screen using the “lcd” command (Line 9) and then initialize the screen (Line 12). To set the LCD backlight to blue, we add the corresponding command (Line 13). We specify that the defined pins will be used as outputs (Lines 15 – 17) and start serial communication (Line 18).

Next, we store the value received from the analog gas sensor in an integer variable named “value” (Line 22) and print this value to the serial monitor (Line 23). If the value is between 350 and 500, the red LED will blink at 1-second intervals, and the buzzer will sound. Additionally, the LCD screen will display the warning “GAS LEAK! BE CAREFUL!” (Lines 24 – 40). If the value exceeds 500, the red LED will blink at 300-millisecond intervals, the buzzer will sound more frequently, and the LCD screen will show the warning “DANGER! LEAVE THE AREA!” (Lines 41 – 57). If the value is below 350, the green LED will remain on continuously, and no warning message will be displayed on the screen.

# demo

https://github.com/user-attachments/assets/6bde84dc-3c54-4ac2-a959-2b1e31609aa4

