from PIL import Image

def weave(imA, imB):
	A = Image.open(imA)
	B = Image.open(imB)

	pixA = A.load()
	pixB = B.load()

	print("dope")
	for h in range(0,A.height):
		for w in range(0,A.width):
			if w%2 == 0 and w < B.width and h < B.height:
				pixA[w,h] = pixB[w,h]
			if h%2 == 0 and w < B.width and h < B.height:
				pixA[w,h] = pixB[w,h]
	A.save('taco.png',"PNG")


weave('frame.png', 'momo_0.gif')