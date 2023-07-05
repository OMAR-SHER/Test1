#Find contours in image
import cv2
import numpy as np
from matplotlib import pyplot as plt
######################Contours in images###############################
# read the image
image = cv2.imread("smarties.png",cv2.IMREAD_COLOR)
# convert the image to grayscale format
img_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# apply binary thresholding
ret, thresh = cv2.threshold(img_gray, 150, 255, cv2.THRESH_BINARY)
# visualize the binary image
cv2.imshow('Binary image', thresh)
cv2.waitKey(0)
cv2.imshow('image', thresh)
cv2.destroyAllWindows()


# detect the contours on the binary image using cv2.CHAIN_APPROX_NONE
contours, hierarchy = cv2.findContours (image=thresh, mode=cv2. RETR_TREE, method=cv2.CHAIN_APPROX_NONE)
# draw contours on the original image
image_copy = image.copy()
cv2.drawContours(image=image_copy, contours=contours, contourIdx=-1, color=(0, 255, 0), thickness=2, lineType=cv2.LINE_AA)
# see the results
cv2.imshow('None approximation', image_copy)
cv2.waitKey(0)
#cv2.imwrite('contours_none_image1.jpg', image_copy)
cv2.destroyAllWindows()
