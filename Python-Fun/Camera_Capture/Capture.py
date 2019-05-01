import cv2
from PIL import Image


#this code is increadibly inefficiant and there is a pretty big bug with the color comparison
#but other than that this was extreamly fun for a small project at 2am

def weave(imA, imB):
	A = Image.open(imA)
	B = Image.open(imB)

	pixA = A.load()
	pixB = B.load()

	for h in range(0,A.height):
		for w in range(0,A.width):
			if w%2 == 0 and  w < B.width and h < B.height: 
				pixA[w,h] = pixB[w,h]
			if h%2 == 0 and w < B.width and h < B.height: 
				pixA[w,h] = pixB[w,h]
	A.save('frame.png',"PNG")

def noBWhite(imA, imB):
	A = Image.open(imA)
	B = Image.open(imB)

	pixA = A.load()
	pixB = B.load()

	for h in range(0,A.height):
		for w in range(0,A.width):
			
			if pixB[w,h] != 36 and w < B.width and h < B.height:
				pixA[w,h] = pixB[w,h]
				print(pixB[w,h])

	A.save('frame.png',"PNG")

cv2.namedWindow("preview")
vc = cv2.VideoCapture(0)

if vc.isOpened():
	rval, frame = vc.read()
else:
	rval = False

while rval:
	cv2.imwrite('frame.png',frame)

	noBWhite('frame.png', 'Circle.png')

	frame = cv2.imread('frame.png')
	cv2.imshow("preview", frame)
	rval, frame = vc.read()
	key = cv2.waitKey(20)
	if key == 27:
		break

cv2.destroyWindow("preview")