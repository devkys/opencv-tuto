import cv2 as cv

img = cv.imread('test.png')

img_blur = cv.blur(img,(5,5))

cv.imshow('Original', img)
cv.imshow('Result', img_blur)

cv.waitKey(0)
cv.destroyAllWindows()