import cv2 as cv
import sys

from cv2 import IMREAD_COLOR
from cv2 import COLOR_HLS2BGR
from cv2 import COLOR_BGR2GRAY

img_color = cv.imread('ball.jpeg', IMREAD_COLOR)

if img_color is None:
    print('can not read image file')
    sys.exit(1)

img_gray = cv.cvtColor(img_color, COLOR_BGR2GRAY)

img_canny = cv.Canny(img_gray, 90, 180)

img_result = cv.hconcat([img_gray, img_canny])

img_result = cv.vconcat([img_gray, img_canny])

cv.imshow('Result', img_result)
cv.waitKey(0)
cv.destroyAllWindows()

