import cv2 as cv

img = cv.imread('median.png')

img_blur = cv.medianBlur(img, 5)

cv.imshow('Original', img)
cv.imshow('Result', img_blur)

cv.waitKey(0)
cv.destroyAllWindows()
