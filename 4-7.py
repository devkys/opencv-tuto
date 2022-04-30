import imghdr
import cv2 as cv
import sys

from cv2 import IMREAD_COLOR

def on_trackbar(x):
    pass

img_color = cv.imread('red-ball.jpeg', IMREAD_COLOR)

if img_color is None:
    print('can not read image file')
    sys.exit(1)
cv.imshow('Color', img_color)

img_gray = cv.cvtColor(img_color, cv.COLOR_BGR2GRAY)
cv.imshow('GrayScale', img_gray)

cv.namedWindow('Binary')    
cv.createTrackbar('threshold', 'Binary', 0,255, on_trackbar)
cv.setTrackbarPos('threshold', 'Binary', 127)

while True:
    thresh = cv.getTrackbarPos('threshold', 'Binary')

    retval, img_binary = cv.threshold(img_gray, thresh, 255, cv.THRESH_BINARY_INV)

    cv.imshow('Binary', img_binary)
    if cv.waitKey(1) & 0xFF == 27:
        break