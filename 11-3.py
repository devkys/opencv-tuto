import cv2 as cv
from cv2 import MORPH_RECT
from cv2 import MORPH_OPEN

img_gray = cv.imread('test2.png', cv.IMREAD_GRAYSCALE)

kernel = cv.getStructuringElement(MORPH_RECT, (3,3))

img_result = cv.morphologyEx(img_gray, MORPH_OPEN, kernel)  

cv.imshow('Input', img_gray)
cv.imshow('Result', img_result)

cv.waitKey(0)   
cv.destroyAllWindows()
