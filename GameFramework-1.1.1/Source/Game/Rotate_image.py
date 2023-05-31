import cv2
import imutils
#image = cv2.imread('./RES/UI/clock/clock_pointer.bmp')

og_dir = "C:/Users/Kuan/Desktop/classroom-flirting-1/GameFramework-1.1.1/RES/UI/Cpointer/pointer ("
dir = "C:/Users/Kuan/Desktop/classroom-flirting-1/GameFramework-1.1.1/RES/UI/Cpointer/pointer ("

for j in range(1):
    for i in range(180):
        now_dir = og_dir + str(i) + ").bmp"
        img = cv2.imread(now_dir)

        rot = imutils.rotate(img, angle=-(180))
        cv2.imshow("Rotated", rot)
        cv2.waitKey(2)
        num = 180 + i*(j+1)
        cv2.imwrite(dir + str(num) + ").bmp", rot)

        cv2.destroyAllWindows()


# dir = r"C:\Users\Kuan\Desktop\classroom-flirting-1\GameFramework-1.1.1\RES\UI\Cpointer\pointer (44).bmp"
# image = cv2.imread(dir)

# rot = imutils.rotate(image, angle = -1)
# cv2.imwrite(r"C:\Users\Kuan\Desktop\classroom-flirting-1\GameFramework-1.1.1\RES\UI\Cpointer\pointer (45).bmp", rot)