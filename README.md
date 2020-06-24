# VENTILATOR
This is the code for a simple to make and easy to use ventilator. 

Because of COVID19, the need for ventilators has skyrocketed. Here, you can see the code for a very simple and easy to make ventilator that will hopefully save many.

Note that this ventilator code or design has not been approved by health organizations. We are not responsible for any harm caused to any persons due to this ventilator, however we have tested this system to confidently say that this code and design is safe and should be usable.

This ventilator has 3 modes, manual, timed, and dynamic. In manual mode, the operator adjusts the amount of time the piston pushes in (IE the air volume per breath) and clicks a button to compress the ventilator once. In Timed mode, the operator adjusts the time the piston pushes in and the frequency, and the ventilator will automatically follow these instructions. In Dynamic mode, the operator adjusts the time the piston pushes in, and the ventilator will compress when it senses negative airflow in the airpipe, signifying the patients needs to breathe.

To run the code, first download the Arduino IDE. Put the Liquid_Crystal folder inside the Arduino Libraries folder. Then, download the VentilatorCode folder, open it, and open it with Arduino IDE. Upload it to the arduino and you are done! You might need to adjust some stats such as the LCD I2C initalization address, or the threshold depending on what sensor you are using for the airflow. 

Project plan: https://shimo.im/docs/DgdxrdCHTx8DJGdR/
