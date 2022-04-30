import cv2 as cv
from cv2 import IMREAD_COLOR

alpha = 0.0
beta = 1.0



while alpha <= 1.0:
    img1 = cv.imread('beach.png', IMREAD_COLOR)
    img2 = cv.imread('cat.png', IMREAD_COLOR)

    dst = cv.addWeighted(img1, alpha, img2, beta, 0)

    print(alpha, ' ', beta)

    cv.imshow('dst', dst)
    cv.waitKey(0)

    #round 파이썬 반올림 함수
    #두번째 인자는 소수 몇번째까지만 나타내겠다
    #두번째 인자 생략시 소수 첫째 자리에서 반올림
    alpha = round(alpha + 0.1, 1)
    beta = round(beta - 0.1, 1)

cv.destroyAllWindows()
