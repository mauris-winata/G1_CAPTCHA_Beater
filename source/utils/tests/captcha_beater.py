import tkinter as tk
import sys
import os
from os import path
import PIL
from tkinter import filedialog, Text, PhotoImage
from PIL import ImageTk, Image, ImageGrab, ImageOps
# import numpy as np
import math
# import cv2
import pyscreenshot
# import pyautogui
# from pynput.mouse import Listener
from time import sleep

root = tk.Tk()
root.title('Captcha Beater')
root.config(height=700, width=700)

# Image coords
glob_image = None
glob_temp_image = None
glob_display = None
glob_filename = None
image_x = 0
image_y = 0
image_width = 0
image_height = 0
image_largest_dim = None
image_aspect_ratio = None

# Mouse Pointer Tracking
init_mouse_x = None
init_mouse_y = None
mouse_clicked = 0

# Cropped area 
rect_width = 300


# Open file
def addFile():
    global glob_image
    global glob_display
    global glob_filename
    global image_width
    global image_height
    global image_largest_dim
    global image_aspect_ratio

    #deleting old labels
    for widget in image_frame.winfo_children():
        widget.destroy()

    #opening images
    glob_filename = filedialog.askopenfilename(initialdir="/", title="Select File", filetypes=(("images", "*.png"), ("all files", "*.*")))
    label = tk.Label(image_frame, text=glob_filename)
    label.pack()
    print(glob_filename)
    glob_image = Image.open(glob_filename)
    glob_temp_image = glob_image
    print(glob_image)
    glob_display = ImageTk.PhotoImage(glob_temp_image)
    my_image = canvas.create_image(0,0, image=glob_display)
    dottedRect()
    image_width = glob_image.size[0]
    image_height = glob_image.size[1]
    image_largest_dim = max(image_width, image_height)
    print(image_largest_dim)
    image_aspect_ratio = image_width/image_height

# Print dotted rect
def dottedRect():
    dot_rect_width = rect_width 
    dot_rect_height = dot_rect_width/3
    canvas.update()
    canvas_width = canvas.winfo_width()
    canvas_height = canvas.winfo_height()
    canvas.create_line(canvas_width/2 - dot_rect_width/2 - 1, canvas_height/2 - dot_rect_height/2 - 1, canvas_width/2 + dot_rect_width/2, canvas_height/2 - dot_rect_height/2 - 1, dash=(4, 2))
    canvas.create_line(canvas_width/2 - dot_rect_width/2 - 1, canvas_height/2 + dot_rect_height/2, canvas_width/2 + dot_rect_width/2, canvas_height/2 + dot_rect_height/2, dash=(4, 2))
    canvas.create_line(canvas_width/2 - dot_rect_width/2 - 1, canvas_height/2 - dot_rect_height/2 - 1, canvas_width/2 - dot_rect_width/2 - 1, canvas_height/2 + dot_rect_height/2, dash=(4, 2))
    canvas.create_line(canvas_width/2 + dot_rect_width/2, canvas_height/2 - dot_rect_height/2 - 1, canvas_width/2 + dot_rect_width/2, canvas_height/2 + dot_rect_height/2, dash=(4, 2))

def imageScale(e):
    global image_x
    global image_y
    global glob_image
    global glob_temp_image
    global glob_display
    global image_largest_dim
    global image_aspect_ratio

    scale_factor = image_largest_dim*0.1
    delta = e.delta/120
    # print(delta)
    image_largest_dim = image_largest_dim + delta*scale_factor
    # glob_image.thumbnail(size=(image_largest_dim,image_largest_dim))
    glob_temp_image = glob_image.resize([int(image_largest_dim), int(image_largest_dim/image_aspect_ratio)], PIL.Image.ANTIALIAS)
    glob_display = ImageTk.PhotoImage(glob_temp_image)
    my_image = canvas.create_image(image_x, image_y, image=glob_display)
    dottedRect()

def pictureZoomIn():
    global image_x
    global image_y
    global glob_image
    global glob_temp_image
    global glob_display
    global image_largest_dim
    global image_aspect_ratio
    canvas.delete("all")
    scale_factor = image_largest_dim*0.1
    image_largest_dim = image_largest_dim + scale_factor
    # glob_temp_image = glob_image.thumbnail(size=(image_largest_dim, image_largest_dim))
    glob_temp_image = glob_image.resize([int(image_largest_dim), int(image_largest_dim/image_aspect_ratio)], PIL.Image.ANTIALIAS)
    glob_display = ImageTk.PhotoImage(glob_temp_image)
    my_image = canvas.create_image(image_x, image_y, image=glob_display)
    dottedRect()

def pictureZoomOut():
    global image_x
    global image_y
    global glob_image
    global glob_temp_image
    global glob_display
    global image_largest_dim
    global image_aspect_ratio
    canvas.delete("all")
    scale_factor = image_largest_dim*0.1
    image_largest_dim = image_largest_dim - scale_factor
    # glob_temp_image = glob_image.thumbnail(size=(400, 400))
    glob_temp_image = glob_image.resize([int(image_largest_dim), int(image_largest_dim/image_aspect_ratio)], PIL.Image.ANTIALIAS)
    glob_display = ImageTk.PhotoImage(glob_temp_image)
    my_image = canvas.create_image(image_x, image_y, image=glob_display)
    dottedRect()

def getter():
    #coordinates of canvas
    x=root.winfo_rootx()+canvas.winfo_x()
    y=root.winfo_rooty()+canvas.winfo_y()
    x1=x+canvas.winfo_width()
    y1=y+canvas.winfo_height()

    #coordinates of dotted box
    dot_rect_width = rect_width 
    dot_rect_height = dot_rect_width/3
    canvas.update()
    canvas_width = canvas.winfo_width()
    canvas_height = canvas.winfo_height()
    x_offset = canvas_width/2 - dot_rect_width/2
    y_offset = canvas_height/2 - dot_rect_height/2
    x = x + x_offset
    x1 = x1 - x_offset
    y = y + y_offset
    y1 = y1  - y_offset
    im = ImageGrab.grab().crop((x,y,x1,y1))
    # im.save("test.png")
    # im.show()

    # Save picture to txt file
    savePicture(im)

    # Perform the system call
    os.system('./captchabeater')
    os.system('./captchabeater')
    os.system('./captchabeater')
    os.system('./captchabeater')


    # Check for produced prediction
    while path.exists("prediction.txt") == False:
        sleep(0.25)
    prediction_file = open("prediction.txt")
    prediction_string = prediction_file.read()
    print("Prediction Value is: " + prediction_string)

    # update prediction
    updatePrediction(prediction_string)

    # delete prediction file
    prediction_file.close()
    os.remove("prediction.txt")

def savePicture(image):
    output_file = open('input_image.txt', 'w')
    temp_image = image
    temp_image = temp_image.resize((150, 50), Image.ANTIALIAS)
    grey_im = ImageOps.grayscale(temp_image)
    grey_im = grey_im.load()
    row, column = temp_image.size
    print(row, column)
    for y in range(column):
        for x in range(row):
            pixel = grey_im[x,y]
            output_file.write(str(pixel) + '\n')
    output_file.close()


def initMousePos(e):
    global init_mouse_x
    global init_mouse_y
    init_mouse_x = e.x
    init_mouse_y = e.y
    # print(init_mouse_x)

def movePicture(e):
    global image_x
    global image_y
    global init_mouse_x
    global init_mouse_y
    global glob_display
    global glob_temp_image

    # image_x = image_x + (e.x - init_mouse_x)
    # image_y = image_y + (e.y - init_mouse_y)
    image_x = e.x 
    image_y = e.y
    glob_display = ImageTk.PhotoImage(glob_temp_image)
    my_image = canvas.create_image(image_x, image_y, image=glob_display)
    dottedRect()

    init_mouse_x = e.x
    init_mouse_y = e.y
    # print("x: " + str(image_x) + ", y: " + str(image_y))

def mousePressEvent(event):
    print("here")
    if event.button() == Qt.LeftButton:
        drawing = True
        lastPoint = event.pos() - QPoint(0, self.toolbar.height())

def on_click(x, y, button, pressed):
    global mouse_clicked
    # print(x, y, button, pressed)
    # print(pressed)
    mouse_clicked = pressed

def snipTool():
    global glob_image
    global glob_display
    global image_width
    global image_height
    global image_largest_dim
    global image_aspect_ratio

    # deleting old labels
    for widget in image_frame.winfo_children():
        widget.destroy()

    # obtain screen snip
    listener = Listener(on_click=on_click)
    listener.start()
    while mouse_clicked == 0:
        sleep(0.01)
    while mouse_clicked == 1:
        sleep(0.01)
    x1 = pyautogui.position().x
    y1 = pyautogui.position().y
    while mouse_clicked == 0:
        sleep(0.01)
    while mouse_clicked == 1:
        sleep(0.01)   
    x2 = pyautogui.position().x
    y2 = pyautogui.position().y
    listener.stop()
    listener.join()

    # display screen snip
    im=ImageGrab.grab(bbox=(x1,y1,x2,y2))
    glob_image = im
    glob_temp_image = glob_image
    glob_display = ImageTk.PhotoImage(glob_image)
    my_image = canvas.create_image(0,0, image=glob_display)
    dottedRect()
    image_width = glob_image.size[0]
    image_height = glob_image.size[1]
    image_largest_dim = max(image_width, image_height)
    print(image_largest_dim)
    image_aspect_ratio = image_width/image_height
    root.attributes("-topmost", True)

def updatePrediction(new_string):

    #deleting old labels
    for widget in result_frame.winfo_children():
        widget.destroy()

    disp_string = "Prediction: " + new_string

    label = tk.Label(result_frame, text=disp_string)
    label.place(anchor="c", relx=.5, rely=.5)

# Image canvas
canvas = tk.Canvas(root, bg="white")
canvas.place(relwidth=0.8, relheight=0.5, relx=0.1, rely=0.3)
canvas.bind('<MouseWheel>', imageScale)
canvas.bind('<Button-1>', initMousePos)
canvas.bind('<B1-Motion>', movePicture)

root.bind_all('<Button-1>', initMousePos)

# Frame for project title
title_frame = tk.Frame(root, bg="white")
title_frame.place(relwidth=0.8, relheight=0.1, relx=0.1, rely=0)

# Frame for image
image_frame = tk.Frame(root, bg="white")
image_frame.place(relwidth=0.8, relheight=0.1, relx=0.1, rely=0.2)

# Frame for prediction
result_frame = tk.Frame(root, bg="white")
result_frame.place(relwidth=0.8, relheight=0.1, relx=0.1, rely=0.8)

# Frames for buttons
button_frame_left = tk.Frame(root, bg="white")
button_frame_left.place(relwidth=0.8/3, relheight=0.1, relx=0.1, rely=0.1)
button_frame_mid = tk.Frame(root, bg="white")
button_frame_mid.place(relwidth=0.8/3, relheight=0.1, relx=0.1+0.8/3, rely=0.1)
button_frame_right = tk.Frame(root, bg="white")
button_frame_right.place(relwidth=0.8/3, relheight=0.1, relx=0.1+2*0.8/3, rely=0.1)

# Buttons
openFile = tk.Button(button_frame_left, text="Open File", padx=10, pady=5, fg="White", bg="Blue", command=addFile)
openFile.place(anchor="c", relx=.5, rely=.5)
getSnip = tk.Button(button_frame_mid, text="New Snip", padx=10, pady=5, fg="White", bg="Blue", command=snipTool)
getSnip.place(anchor="c", relx=.5, rely=.5)
cropImage = tk.Button(button_frame_right, text="Predict", padx=10, pady=5, fg="White", bg="Blue", command=getter)
cropImage.place(anchor="c", relx=.5, rely=.5)
zoomIn = tk.Button(canvas, text="+", padx=10, pady=5, fg="White", bg="Grey", command=pictureZoomIn)
zoomIn.grid(column=0, row=0)
zoomOut = tk.Button(canvas, text="-", padx=11, pady=5, fg="White", bg="Grey", command=pictureZoomOut)
zoomOut.grid(column=0, row=1)

# Dotted rectangle
dottedRect()

# Screen info
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()

updatePrediction('-----')

root.mainloop()