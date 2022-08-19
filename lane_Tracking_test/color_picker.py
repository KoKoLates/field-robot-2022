import cv2
import numpy as np

# Configue the frame of video stream
cap = cv2.VideoCapture(1)
cap.set(3, 640) # Setting the frame width
cap.set(4, 480) # Setting the frame height

# Creating a window for the threshold picker
cv2.namedWindow('Color Picker')
cv2.resizeWindow('Color Picker', 640, 240)

# Create the tracker bar
# Hue has range only on 0 to 179 in OpenCV
# Saturation and Value are range between 0 to 255
cv2.createTrackbar('MIN H', 'Color Picker', 0, 179, lambda x:x)
cv2.createTrackbar('MAX H', 'Color Picker', 169, 179, lambda x:x)
cv2.createTrackbar('MIN S', 'Color Picker', 0, 255, lambda x:x)
cv2.createTrackbar('MAX S', 'Color Picker', 255, 255, lambda x:x)
cv2.createTrackbar('MIN V', 'Color Picker', 0, 255, lambda x:x)
cv2.createTrackbar('MAX V', 'Color Picker', 255, 255, lambda x:x)

while True:
    ret, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Got the tracker bar pose and value
    MIN_H = cv2.getTrackbarPos('MIN H', 'Color Picker')
    MAX_H = cv2.getTrackbarPos('MAX H', 'Color Picker')
    MIN_S = cv2.getTrackbarPos('MIN S', 'Color Picker')
    MAX_S = cv2.getTrackbarPos('MAX S', 'Color Picker')
    MIN_V = cv2.getTrackbarPos('MIN V', 'Color Picker')
    MAX_V = cv2.getTrackbarPos('MAX V', 'Color Picker')

    # The lower and upper range limit for the color space we need
    lower = np.array([MIN_H, MIN_S, MIN_V])
    upper = np.array([MAX_H, MAX_S, MAX_V])
    mask = cv2.inRange(hsv, lower, upper)
    
    result = cv2.bitwise_and(frame, frame, mask=mask)
    mask = cv2.cvtColor(mask, cv2.COLOR_GRAY2BGR)
    HStack = np.hstack([frame, mask, result])

    cv2.imshow('Horizontal Stack', HStack)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()