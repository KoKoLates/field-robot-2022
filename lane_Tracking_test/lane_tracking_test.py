import cv2
import numpy as np

cap = cv2.VideoCapture(0)
hsv_value = [37, 60, 130, 62, 105, 210] # using the color picker to determine

def thresholding(image):
    # Convert into HSV due to easier to find color in color space
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    lower = np.array([hsv_value[0], hsv_value[1], hsv_value[2]])
    upper = np.array([hsv_value[3], hsv_value[4], hsv_value[5]])
    # Mask is the image that only contain the lanes
    mask = cv2.inRange(hsv, lower, upper)
    return mask

# Convert the path into a box and get the center point
def getContours(image, image_threshold):
    # finding the edge in our image
    # based on the edge we could find the lane (or called the bounding box)
    # Use the external method to get the outer region
    # return contour and hierarchy
    contour, hierarcy = cv2.findContours(image_threshold, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    cv2.drawContours(image, contour, -1, (0, 0, 255), 5)
    
    # Assume the biggest region or the region would be the path
    biggest = max(contour, key=cv2.contourArea)

    # convert the biggest contour points into x, y, width and height
    x, y, width, height = cv2.boundingRect(biggest)

    # Due to the parameter, we could find the center points
    center_x = x + (width // 2)
    center_y = y + (height // 2)
    cv2.circle(image, (center_x, center_y), 5, (0, 255, 0), cv2.FILLED)

    # return center x only due to the need to find the center line of the path only
    return center_x

def region_of_interest(image,x,y): 
    hei = image.shape[0]
    wid = image.shape[1]

    triangle = np.array([np.int32((0, hei*y)), 
                        # np.int32((wid / 2, (2 * hei) / 5)), 
                        np.int32((wid, hei*y)),
                        np.int32((wid*x, hei)),
                        np.int32((0, hei))])
    
    mask = np.zeros_like(image)
    mask = cv2.fillPoly(mask, [triangle], (255, 255, 255))
    
    mask_image = cv2.bitwise_and(image, mask)
    return mask_image

while True:
    ret, frame = cap.read()
    # ret is to check whether there is an image
    # frame is the frame image currently
    image = cv2.resize(frame, (480,360))

    # Finding the path and the center of the path 
    image_threshold = thresholding(image)
    image_threshold = region_of_interest(image_threshold, x=1, y=2/3)
    center_x = getContours(image, image_threshold)



    cv2.imshow("Raw frame", image)
    cv2.imshow("Lane", image_threshold)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
