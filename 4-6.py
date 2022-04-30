import cv2 as cv
import sys


img_color = cv.imread('gray.jpeg', cv.IMREAD_COLOR)

if img_color is None:
    print('can not read img_color')
    sys.exit(1)

img_gray = cv.cvtColor(img_color, cv.COLOR_BGR2GRAY)

retval,img_binary = cv.threshold(img_gray, 127 ,255, cv.THRESH_BINARY)
print(retval)
cv.imshow('GrayScale', img_gray)
cv.imshow('Binary', img_binary)
cv.waitKey(0)
cv.destroyAllWindows()
