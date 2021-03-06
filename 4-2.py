import sys
import cv2 as cv

cap = cv.VideoCapture(0)

if not cap.isOpened():
    print('can not open camera')
    sys.exit(1)

step = 1

while(True):
    ret, img_frame = cap.read() 

    if not ret:
        print('failed capture')
        break;
    
    if step > 1:
        img_frame = cv.cvtColor(img_frame, cv.COLOR_BGR2GRAY)
        
        if step > 2:
            img_frame = cv.Canny(img_frame, 30, 90)
    
    cv.imshow('Result', img_frame)

    key = cv.waitKey(1)
    if key == 27:
        break;
    elif key == ord('1'):
        step = 1
    elif key == ord('2'):
        step = 2
    elif key == ord('3'):
        step = 3
cap.release()
cv.destroyAllWindows()