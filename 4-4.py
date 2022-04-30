import cv2 as cv
import sys

from cv2 import IMREAD_COLOR
from cv2 import COLOR_BGR2GRAY

img_color = cv.imread('ball.jpeg', cv.IMREAD_COLOR);

if img_color is None:
    print('can not read image file')
    sys.exit(1)

img_gray = cv.cvtColor(img_color, COLOR_BGR2GRAY)

img_canny = cv.Canny(img_gray, 90,180)

cv.imshow('GrayScale', img_gray)
cv.imshow('Canny', img_canny)

cv.waitKey(0)
cv.destroyAllWindows()
