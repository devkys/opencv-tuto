import cv2 as cv
import sys




img_color = cv.imread('copy.png', cv.IMREAD_COLOR)

if img_color is None:
    print('can not read image file')
    sys.exit(1)

img_gray = cv.cvtColor(img_color, cv.COLOR_BGR2GRAY)

img_binary = cv.adaptiveThreshold(img_gray, 255, cv.ADAPTIVE_THRESH_MEAN_C,cv.THRESH_BINARY_INV, 5,4)

cv.imshow('GrayScale', img_gray)
cv.imshow('Binary', img_binary)
cv.waitKey(0)

cv.destroyAllWindows()