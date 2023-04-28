import cv2
import glob
import numpy as np

# The number of corners in chessboard both in the width and height
chessboardSize = (24, 17)
frameSize = (1080, 720)

# Termination criteria
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TermCriteria_MAX_ITER, 30, 0.001)

# Prepare object points
objp = np.zeros((chessboardSize[0] * chessboardSize[1], 3), np.float32)
objp[:,:2] = np.mgrid[0:chessboardSize[0], 0:chessboardSize[1].T.reshape(-1,2)]

objPoint = []
imgPoint = []

images = glob.glob('*.png')

for image in images:
    print(image)
    img = cv2.imread(image)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Find the corners of chess board
    ret, corners = cv2.findChessboardCorners(gray, chessboardSize, None)
    if ret == True:
        objPoint.append(objp)
        corners_2 = cv2.cornerSubPix(gray, corners, (11,11), (-1,-1), criteria)
        imgPoint.append(corners)

        cv2.drawChessboardCorners(img, chessboardSize, corners_2, ret)
        cv2.imshow('img', img)
        cv2.waitKey(1000)

cv2.destroyAllWindows()

ret, cameraMatrix, dist, rvecs, tvecs = cv2.calibrateCamera(objPoint, imgPoint, frameSize, None, None)
print("Camera Calibrated: {}".format(ret))
print("Camera Matrix: {}".format(cameraMatrix))
print("Distortion Parameters: {}".format(dist))
print("Rotation Vectors: {}".format(rvecs))
print("Translation Vectors {}".format(tvecs))

