import cv2 as cv
from cv2 import IMREAD_COLOR
from cv2 import INTER_CUBIC

img_color = cv.imread('cat.jpeg', IMREAD_COLOR)
cv.imshow('original', img_color)

img_result = cv.resize(img_color, None, fx=2, fy=2, interpolation=cv.INTER_CUBIC)
cv.imshow('x2 INTER_CUBIC', img_result)

height, width = img_color.shape[:2]
img_result = cv.resize(img_color, (3*width, 3*height), interpolation=cv.INTER_LINEAR)
cv.imshow('x3 INTER_LINEAR', img_result)

img_result = cv.resize(img_color, None, fx=0.5, fy=0.5, interpolation=cv.INTER_AREA)
cv.imshow('x0.5 INTER_AREA', img_result)

cv.waitKey(0)
cv.destroyAllWindows()
