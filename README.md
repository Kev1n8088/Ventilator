Note that this branch is an ongoing development. 

# VENTILATOR
This is the code for an open-source, simple to make, and easy to use ventilator. 

Because of COVID19, the need for ventilators has skyrocketed. Here, you can see the code for a very simple and easy to make ventilator that will hopefully save many.

The device is rather simple, relying on an electric piston to compress the rubberized diaphram in order to force air in and out of the patient's lungs. The core of the device is an aftermarket Arduino (the DFRobot Arduino Romeo), a board based on the Arduino Leonardo but equipped with an H-bridge for motor control. 

This ventilator has 3 modes, manual, timed, and dynamic. In manual mode, the operator adjusts the amount of time the piston pushes in (IE the air volume per breath) and clicks a button to compress the ventilator once. In Timed mode, the operator adjusts the time the piston pushes in and the frequency, and the ventilator will automatically follow these instructions. In Dynamic mode, the operator adjusts the time the piston pushes in, and the ventilator will compress when it senses negative airflow in the airpipe, signifying the patients needs to breathe.

# Hardware:

Board: DFRobot Arduino Romeo

Piston: Bi-directional electric motor-driven piston with a speed of 100mm/s and a max extention range of 250mm

Diaphram: Emergency Medical Resustiation diapram

Sensors: Directional Airflow sensor（optional）


Other parts:

Frame: Laser cut boards and aluminium struts

Jumper wires

External 12V power source


# How to run code:
To run the code, first download the Arduino IDE. Put the Liquid_Crystal folder inside the Arduino Libraries folder. Then, download the VentilatorCode folder, open it, and open it with Arduino IDE. Upload it to the arduino and you are done! You might need to adjust some stats such as the LCD I2C initalization address, or the threshold depending on what sensor you are using for the airflow. 

# Disclaimer:
Note that this ventilator code or design has not been approved by health organizations. We are not responsible for any harm caused to any persons due to this ventilator, however we have tested this system to confidently say that this code and design is safe and should be usable. 

# Project Plan (Link)
https://shimo.im/docs/DgdxrdCHTx8DJGdR/

