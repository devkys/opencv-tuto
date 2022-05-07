import cv2 as cv
from cv2 import destroyAllWindows

img = cv.imread('texture.png')
blur = cv.bilateralFilter(img, 9, 75, 75)

cv.imshow('Original', img)
cv.imshow('Result', blur)

cv.waitKey(0)
cv.destroyAllWindows()
