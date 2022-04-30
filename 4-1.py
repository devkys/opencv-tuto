import cv2 as cv
from cv2 import IMREAD_GRAYSCALE

def on_trackbar(x):
    pass

cv.namedWindow('Canny')

cv.createTrackbar('low threshold', 'Canny', 0, 1000,on_trackbar)
cv.createTrackbar('high threshold', 'Canny', 0,1000,on_trackbar)

cv.setTrackbarPos('low trheshold', 'Canny', 50)
cv.setTrackbarPos('high threshold', 'Canny', 150)   

img_gray = cv.imread('orange.png', IMREAD_GRAYSCALE)

while(1):
    low = cv.getTrackbarPos('low threshold', 'Canny', 50)
    high = cv.getTrackbarPos('high threshold', 'Canny', 150)

    img_canny = cv.Canny(img_gray, low, high)

    cv.imshow('Canny', img_canny)

    if cv.waitKey(1) & 0xFF == 27:
        break

cv.destroyAllWindows()