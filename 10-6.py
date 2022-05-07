import cv2 as cv

img_gray = cv.imread('house.png', cv.IMREAD_GRAYSCALE);
cv.imshow('Original', img_gray);

img_gray = cv.blur(img_gray, (3,3))
img_canny = cv.Canny(img_gray, 50,150)  
cv.imshow('Canny Edge', img_canny)

cv.waitKey(0)
cv.destroyAllWindows()