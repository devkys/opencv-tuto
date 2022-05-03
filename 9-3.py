from cv2 import IMWRITE_PNG_COMPRESSION
import numpy as np
import cv2 as cv

point_list=[]

def mouse_callback(event, x, y, flags, param):
    if event == cv.EVENT_LBUTTONDOWN:
        point_list.append((x,y))

        cv.circle(img_color, (x,y,),3,(0,0,255), -1)


cv.namedWindow('source')
cv.setMouseCallback('source', mouse_callback)


img_color = cv.imread('test.png')

while True:
    cv.imshow('source', img_color)

    if cv.waitKey(1) == 32:
        break

height, width = img_color.shape[:2]
pts1 = np.float32([point_list[0], point_list[1], point_list[2]])
pts2 = np.float32([point_list[0], point_list[1], point_list[2]])
pts2[2][1] += 100

M = cv.getAffineTransform(pts1, pts2)

img_result = cv.warpAffine(img_color, M, (width, height))

cv.imshow('result', img_result)
cv.waitKey(0)
cv.destroyAllWindows()
