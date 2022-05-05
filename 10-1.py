import cv2 as cv
import numpy as np
from sympy import im

img = cv.imread('test.png')

kernel = np.ones((5,5), np.float32)/25

dst = cv.filter2D(img, -1, kernel)

cv.imshow('Original', img)
cv.imshow('Result', dst)

cv.waitKey(0)
cv.destroyAllWindows()