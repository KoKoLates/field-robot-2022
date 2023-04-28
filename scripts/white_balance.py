import cv2
import numpy as np

cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

def white_balance(image):
    # Gray World method
    image = image.transpose(2, 0, 1).astype(np.uint32)
    avg_b = np.average(image[0])
    avg_g = np.average(image[1])
    avg_r = np.average(image[2])
    avg = (avg_b + avg_g + avg_r) / 3

    image[0] = np.minimum(image[0] * (avg/avg_b), 255)
    image[1] = np.minimum(image[1] * (avg/avg_g), 255)
    image[2] = np.minimum(image[2] * (avg/avg_r), 255)
    return image.transpose(1, 2, 0).astype(np.uint8)
    

while True:
    ret, frame = cap.read()
    result = white_balance(frame)
    hstack = np.hstack([frame, result])
    cv2.imshow('Image', hstack)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()