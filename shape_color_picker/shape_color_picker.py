from tkinter.tix import Tree
import cv2
import numpy as np

def main():
    cap = cv2.VideoCapture(0)
    if not cap:
        print("[ERRPR] Cannot open camera. Exitting...")
        exit()

    while True:
        ret, frame = cap.read()
        if not ret:
            print('cannot receive frame')
            break

        image = frame.copy()
        image_contour = frame.copy()
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        # Using the color picker to decide the mask
        lower = np.array([0, 103, 134])
        upper = np.array([99, 255, 255])
        mask = cv2.inRange(hsv, lower, upper)
        result = cv2.bitwise_and(image, image, mask=mask)

        # Canny sharper
        canny = cv2.Canny(result, 100, 200)

        # Find the Outline of the shape / object
        contours, hierarchy = cv2.findContours(canny, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

        for contour in contours:
            area = cv2.contourArea(contour)
            # TODO

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
