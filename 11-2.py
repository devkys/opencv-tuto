import cv2 as cv

img_gray = cv.imread('test.png', cv.IMREAD_GRAYSCALE)

kernel = cv.getStructuringElement(cv.MORPH_RECT, (3,3))
img_result = cv.dilate(img_gray, kernel, 1)

cv.imshow('Input', img_gray)
cv.imshow('Result', img_result)

cv.waitKey(0)
cv.destroyAllWindows()