import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
from matplotlib.widgets import Button

# configuration of data

fig, ax = plt.subplots()

axis_color = 'lightgoldenrodyellow'

path = "images/lena_img.jpg"

def load_image(path):
    img_pil = Image.open(path)
    if img_pil.mode == "L":
        img = np.asarray(img_pil)
        cmap = 'gray'
    else:
        img = np.asarray(img_pil.convert("RGB"))
        cmap = None
    return img, cmap

image, cmap = load_image(path)

nn_counter = 0

current_img = np.asarray(image)
img_display = ax.imshow(current_img, cmap=cmap)

fig.subplots_adjust(bottom=0.25)

# button for proceeding to next image
nextax = fig.add_axes([0.8, 0.025, 0.1, 0.04])
nextbutton = Button(nextax, 'Next', color = axis_color, hovercolor = '0.975')

# registering click on reset button
def button_clicked(mouse_event):
    global current_img, img_display
    new_img = nearest_neighbor(current_img)
    img_display.set_data(new_img)
    current_img = new_img
    plt.draw()

nextbutton.on_clicked(button_clicked)

#change the value of scale to change behaviour of algorithm
def nearest_neighbor(image):
    global nn_counter

    if(nn_counter < 5):

        h, w, c= image.shape
        new_h, new_w = int(h * 1.1), int(w * 1.1)
        new_img = np.zeros((new_h, new_w, c), dtype=image.dtype)

        for y in range(new_h):
            for x in range(new_w):
                src_y = int(y / 1.1)
                src_x = int(x / 1.1)
                src_y = min(src_y, h - 1)
                src_x = min(src_x, w - 1)
                new_img[y, x] = image[src_y, src_x]

        print(f"Scale: {np.pow(1.1,nn_counter):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_enlarged Scale: {np.pow(1.1,nn_counter):.2f}.jpg')
    else:

        h, w, c = image.shape
        new_h, new_w = int(h / 1.1), int(w / 1.1)
        new_img = np.zeros((new_h, new_w, c), dtype=image.dtype)

        for y in range(new_h):
            for x in range(new_w):
                src_y = int(y / 1.1)
                src_x = int(x / 1.1)
                src_y = min(src_y, h - 1)
                src_x = min(src_x, w - 1)
                new_img[y, x] = image[src_y, src_x]

        print(f"Scale: {np.pow(1.1,nn_counter):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_shrinked Scale: {np.pow(1.1,nn_counter):.2f}.jpg')
        
    nn_counter += 1
    return new_img

plt.show()