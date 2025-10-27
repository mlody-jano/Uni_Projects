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
bilinear_counter = 0

current_img = np.asarray(image)
img_display = ax.imshow(current_img, cmap=cmap)

fig.subplots_adjust(bottom=0.25)

# button for proceeding to next image
nextax = fig.add_axes([0.8, 0.025, 0.1, 0.04])
nextbutton = Button(nextax, 'Next', color = axis_color, hovercolor = '0.975')

# registering click on reset button, to change interpolation method change func in new_img = func(current_img)
def button_clicked(mouse_event):
    global current_img, img_display
    new_img = nearest_neighbor(current_img)
    img_display.set_data(new_img)
    current_img = new_img
    plt.draw()

def show_summary(scaled_img):
    fig, (ax1, ax2) = plt.subplots(1,2)
    plt.title("Nearest Neighbor Scaling")
    plt.axis('off')
    ax1.imshow(Image.open(path))
    ax1.set_title("Original Image")
    ax1.axis('off')
    ax2.imshow(scaled_img)
    ax2.set_title("Final Scaled Image")
    ax2.axis('off')
    plt.show()


nextbutton.on_clicked(button_clicked)

# nearest neighbor interpolation function
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

        print(f"Scale: {np.pow(1.1,nn_counter + 1):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_nearest_neighbor_enlarged Scale: {np.pow(1.1,nn_counter):.2f}.jpg')
    elif(nn_counter == 5):
        show_summary(current_img)

    elif(nn_counter >= 5 and nn_counter < 10):

        h, w, c = image.shape
        new_h, new_w = int(h / 1.1), int(w / 1.1)
        new_img = np.zeros((new_h, new_w, c), dtype=image.dtype)

        for y in range(new_h):
            for x in range(new_w):
                src_y = int(y * 1.1)
                src_x = int(x * 1.1)
                src_y = min(src_y, h - 1)
                src_x = min(src_x, w - 1)
                new_img[y, x] = image[src_y, src_x]

        print(f"Scale: {np.pow(1.1,10 - nn_counter):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_shrinked Scale: {np.pow(1.1,10 - nn_counter):.2f}.jpg')
    
    elif(nn_counter == 10):
        show_summary(current_img)
        
    nn_counter += 1
    return new_img

# bilinear interpolation function
def bilinear_interpolation(image):
    global bilinear_counter

    if(bilinear_counter < 5):

        h, w, c= image.shape
        new_h, new_w = int(h * 1.1), int(w * 1.1)
        new_img = np.zeros((new_h, new_w, c), dtype=image.dtype)

        for y in range(new_h):
            for x in range(new_w):
                src_x = x / 1.1
                src_y = y / 1.1

                x0 = int(np.floor(src_x))
                x1 = min(x0 + 1, w - 1)
                y0 = int(np.floor(src_y))
                y1 = min(y0 + 1, h - 1)

                dx = src_x - x0
                dy = src_y - y0

                for channel in range(c):
                    top = (1 - dx) * image[y0, x0, channel] + dx * image[y0, x1, channel]
                    bottom = (1 - dx) * image[y1, x0, channel] + dx * image[y1, x1, channel]
                    new_img[y, x, channel] = (1 - dy) * top + dy * bottom

        print(f"Scale: {np.pow(1.1,bilinear_counter + 1):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_bilinear_enlarged Scale: {np.pow(1.1,bilinear_counter + 1):.2f}.jpg')
    elif(bilinear_counter == 5):
        show_summary(current_img)
    elif(bilinear_counter >= 5 and bilinear_counter < 10):

        h, w, c = image.shape
        new_h, new_w = int(h / 1.1), int(w / 1.1)
        new_img = np.zeros((new_h, new_w, c), dtype=image.dtype)

        for y in range(new_h):
            for x in range(new_w):
                src_x = x * 1.1
                src_y = y * 1.1

                x0 = int(np.floor(src_x))
                x1 = min(x0 + 1, w - 1)
                y0 = int(np.floor(src_y))
                y1 = min(y0 + 1, h - 1)

                dx = src_x - x0
                dy = src_y - y0

                for channel in range(c):
                    top = (1 - dx) * image[y0, x0, channel] + dx * image[y0, x1, channel]
                    bottom = (1 - dx) * image[y1, x0, channel] + dx * image[y1, x1, channel]
                    new_img[y, x, channel] = (1 - dy) * top + dy * bottom

        print(f"Scale: {np.pow(1.1,10 - bilinear_counter):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_bilinear_shrinked Scale: {np.pow(1.1,10 - bilinear_counter):.2f}.jpg')
    elif(bilinear_counter == 10):
        show_summary(current_img)
    bilinear_counter += 1
    return new_img

# bicubic interpolation function
def bicubic_interpolation(image):
    global bicubic_counter

    if(bicubic_counter < 5):

        h, w, c= image.shape
        new_h, new_w = int(h * 1.1), int(w * 1.1)
        new_img = np.zeros((new_h, new_w, c), dtype=image.dtype)

        # Bicubic interpolation logic would go here

        print(f"Scale: {np.pow(1.1,bicubic_counter):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_bicubic_enlarged Scale: {np.pow(1.1,bicubic_counter):.2f}.jpg')
    elif(bicubic_counter == 5):
        show_summary(current_img)
    elif(bicubic_counter >= 5 and bicubic_counter < 10):

        h, w, c = image.shape
        new_h, new_w = int(h / 1.1), int(w / 1.1)
        new_img = np.zeros((new_h, new_w, c), dtype=image.dtype)

        # Bicubic interpolation logic would go here

        print(f"Scale: {np.pow(1.1,10 - bicubic_counter):.2f}")
        print(f"Height: {new_h}, Width: {new_w}")

        im = Image.fromarray(current_img)
        im.save(f'images/new_lena_bicubic_shrinked Scale: {np.pow(1.1,10 - bicubic_counter):.2f}.jpg')
    elif(bicubic_counter == 10):
        show_summary(current_img)
    bicubic_counter += 1
    return new_img

plt.show()