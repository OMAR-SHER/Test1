import numpy as np
import cv2
from matplotlib import pyplot as plt

# Image operation using thresholding
img = cv2.imread('coin.jpg')
cv2.imshow('input_image', img)
cv2.waitKey(0)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

ret, thresh = cv2.threshold(gray, 0, 255,
                            cv2.THRESH_BINARY_INV +
                            cv2.THRESH_OTSU)
cv2.imshow('image', thresh)
cv2.waitKey(0)
#cv2.imshow('image', thresh)
#cv2.destroyAllWindows()
kernel = np.ones((8, 8), np.uint8)
closing = cv2.morphologyEx(thresh, cv2.MORPH_CLOSE,
                           kernel, iterations=20)

# Background area using Dialation
bg = cv2.dilate(closing, kernel, iterations=30)

# Finding foreground area
dist_transform = cv2.distanceTransform(closing, cv2.DIST_L2, 0)
ret, fg = cv2.threshold(dist_transform, 0.02
                        * dist_transform.max(), 255, 0)

cv2.imshow('image', fg)
cv2.waitKey(0)
#cv2.imshow('image', thresh)
cv2.destroyAllWindows()