---
title: "Audio meter"
author: "Nomeda"
description: "A sound detector on an ESP32 with adjustable sound sensitivity"
created_at: "2026-07-19"
---

## July 19th
### Session 1
I started by drawing the main components on paper just to visualise the layout. Then I went to Wokwi and started doing the actual simulation. I wired up all the hardware, even the components that I was 
not too familiar with, like the LED ring. Now that I think about it, I was too ambitious wanting to create the final project in one iteration. That proved to be right, when I started writing the 
firmware. I looked at others' work for reference on how they work with mics, LED rings, potentiometers and got really lost with which section belonged to which component. My code was very buggy when I tried to write it.  
Version 1: 
<img width="720" height="552" alt="Screenshot 2026-07-20 at 23 01 23" src="https://github.com/user-attachments/assets/a535f7b0-9eb9-46f0-a203-42405bd7300c" />  
Time lapse:  
https://lapse.hackclub.com/timelapse/sFnXt8INfy8s  

## July 20th
### Session 2
When I started looking at code from yesterday I got very confused so I decided to use the knowledge that I already have about the components to build the final project from the simplest version. 
Version 1 was a way to learn about microphone input. There were 4 components: ESP32 (MCU), a microphone (input), a 220 resistor and an LED (output). I got it done so much faster and it was SO much easier.  
<img width="1250" height="964" alt="image" src="https://github.com/user-attachments/assets/f406e62f-ffb2-4f48-beb3-1fe7e8394da1" />  
In Version 2 I added a more complex output device: an LED ring. This verion's goal was to just properly connect the ESP32 to the LED ring and to ensure that it turns on with sound. It was satisfying
since my project was starting to look more and more like what I imagined.  
<img width="1464" height="950" alt="image" src="https://github.com/user-attachments/assets/837c8d28-4bbd-48a5-b19d-213db291dd92" />  
Version 3 was a bit more difficult since I added a potentiometer to allow control over the sensitivity of the microphone. The logic in the firmware got more complicated and I had to dig through some 
projects to see how it could be implemented. Overall, it was getting more difficult to orientate in my own project as it was getting more nuanced. Annoying.  
<img width="1324" height="1002" alt="image" src="https://github.com/user-attachments/assets/6ee25b6f-ba7d-49f1-be54-24a35a1fa3e4" />  
Version 4 is the final verion, yey!!! The only thing I added here was the code to make the LED ring multicolored when it activates, so the layout of the system is the same as in Version 3. I am very happy with the result!  
Time lapse: https://lapse.hackclub.com/timelapse/C9l4qj-Lb7B_




