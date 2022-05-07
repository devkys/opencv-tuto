import cv2 as cv
from cv2 import MORPH_RECT
from cv2 import MORPH_CLOSE

img_gray = cv.imread('test3.png', cv.IMREAD_GRAYSCALE)

kernel = cv.getStructuringElement(MORPH_RECT, (11,11))

img_result = cv.morphologyEx(img_gray, MORPH_CLOSE, kernel) 

cv.imshow('Input', img_gray)
cv.imshow('Result', img_result)

cv.waitKey(0)
cv.destroyAllWindows()