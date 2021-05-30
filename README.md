# ECE1373 Group 1 Final Project - Captcha Beater
**Members**: 
  Mauris Winata,
  Nikhil Deshpande,
  Randy Ewing Chow,
  Srivatsan Srinivasan
  
A method to solve text-based CAPTCHAs using FPGAs is designed as a term project for ECE1373 dubbed the CAPTCHA Beater. It aims to solve text based CAPTCHAs for bot detection using an FPGA programmed by HLS. 


https://user-images.githubusercontent.com/71918289/120048088-32c2ad80-bfe4-11eb-9f94-d65f9957cb87.mov

*To Build the Project:*
-
### Building Hardware Kernel ###
1. Change directory into source ('cd ./source')
2. The makefile contains commands to build individual IPs of every block within the hardware kernel
3. To build the entire hardware kernel, run 'make generate_captcha_beater'
4. The previous command will build all the individual IPs within the hls_proj folder and 
   then an archived vivado project found within the vivado folder will be opened in gui mode
5. Within the GUI, please go to the Tcl console and execute 'source ../bitstream_generation.tcl'. This will
   generate the bitstream for the project called 'captcha_beater.bit' and the file will be found within
   the vivado folder.

### Building Kernel Driver ###
1. Change directory into the source directory
2. Run 'make xdma'. This will build and install the xdma kernel module
3. To build the software that communicates with the kernel driver, run 'make xdma_tools'
4. Restart the machine and change back into the source directory, then run 'make load_driver' to load the xdma driver.
5. THe driver should be loaded now

### Building Kernel Driver Accompanying Software###
1. Change drirectory into the source directory
2. Please run 'make captcha_beater_software', this will create a program which handles data transfer between the python program
   and the kernel driver communication software

*To Run & Use:*
-
Required Packages:  tkinter, sys, os, PIL, math, pyscreenshot, time
1. Navigate to the source/util/test folder
2. Run the following command: "python3 captcha_beater.py"
3. Import an image by clicking the "Open File" button, several test images are provided in the source/test_captchas folder
4. Center the image appropriately by dragging the image to the center of the dotted rectangle 
5. Size the image appropriately by clicking the "+" or "-" buttons
6. Press the "Predict" button to generate a prediction

**Note: The "New Snip" feature is disabled due to the missing libraries on Agent8**


*Software Dependencies:*
-
- Python 3.7 or newer
- Vivado 2017.2
