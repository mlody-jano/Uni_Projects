import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
from matplotlib.widgets import Button
from scaling import nearest_neighbor, bilinear_interpolation, bicubic_interpolation, load_image, nn_counter, bilinear_counter, bicubic_counter

# declaration of variables

global path
global image
global cmap

# declaration and definition of functions
def rotate_points(x, y, angle, center):
    pass
def rotate_image(image, angle):
    pass
def save_image(image, path):
    pass
def show_image(image):
    pass

path = "images/lena_img.jpg"
image, cmap = load_image(path)